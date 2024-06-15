#ifndef SACH_H
#define SACH_H

#include <cstring>
#include <vector>

using namespace std;

typedef struct Sach {
    char MaSach[10];
    char TenSach[100];
    char TheLoai[100];
    char TacGia[100];
    int NamXuatBan;
    char svm[10] = "\0"; //dung MSSV
} Sach;

typedef struct SachNode {
    Sach S;
    SachNode* next = nullptr;
}SachNode;

typedef SachNode* PSach;
typedef SachNode* LSach;

LSach s = nullptr; //danh sach cac sach

typedef struct SachMuon {
    PSach P = nullptr;
    SachMuon* next = nullptr;
}SachMuon, FindingBook;

typedef SachMuon* PSM; //cac node cua danh sach sach muon
typedef SachMuon* LSM; //sach muon

typedef FindingBook* PFB;
typedef FindingBook* LFB; //list finding book

typedef struct SinhVien {
    char MSV[10];
    char HoTen[100];
    LSM SachMuon = nullptr;
} SinhVien;

typedef struct SinhVienNode {
    SinhVien SV;
    SinhVienNode* next = nullptr;
}SinhVienNode;

typedef SinhVienNode* PSV;
typedef SinhVienNode* LSV;

LSV sv = nullptr; //danh sach sinh vien

void ThemSach(LSach& LS, char Ma[], char Ten[], char Loai[], char TG[], int NXB) {
    PSach temp = new SachNode;
    strcpy(temp->S.MaSach, Ma);
    strcpy(temp->S.TenSach, Ten);
    strcpy(temp->S.TheLoai, Loai);
    strcpy(temp->S.TacGia, TG);
    temp->S.NamXuatBan = NXB;
    temp->next = LS;
    LS = temp;
}

void XoaSach(LSach& LS, char* info) { //xoa sach theo ma sach
    PSach A = LS;
    if (!strcmp(LS->S.MaSach, info)) {
        LS = LS->next;
        delete A;
    }
    while (A->next != nullptr) {
        if (!strcmp(A->next->S.MaSach, info)) {
            PSach B = A->next;
            A->next = B->next;
            delete B;
        }
        A = A->next;
    }
}

void DeleteFindingBook(LFB& lfb) { //xoa toan bo list sach
    while (lfb != nullptr) {
        LFB A = lfb;
        lfb = lfb->next;
        delete A;
    }
}

PSach TimSachTheoMa(LSach LS, char* masach) { //tim sach theo ma sach
    while (LS != nullptr) {

        if (!strcmp(LS->S.MaSach, masach))
            return LS;
        LS = LS->next;

    }
    return LS;
}

LFB TimSachTheoTen(LSach LS, char* tensach) {
    LFB lfb = nullptr;
    while (LS != nullptr) {
        if (!strcmp(LS->S.TenSach, tensach)) {
            PFB A = new FindingBook;
            A->P = LS;
            A->next = lfb;
            lfb = A;
            LS = LS->next;
        }
    }
    return lfb;
}


int DemSach(LSach LS) { //dem so sach
    int Count = 0;
    while (LS != nullptr) {
        Count++;
        LS = LS->next;
    }
    return Count;
}

//Sap xep sach theo ma sach
typedef struct HashMaSach { //cau truc luu tru de bam ma sach
    char MaSach[100];
    PSach P;
}HashMaSach;


void HashTableMaSach(HashMaSach* H, LSach LS) { //bam ma sach
    int N = DemSach(LS);
    while (LS != nullptr) {
        H->P = LS;
        strcpy(H->MaSach, LS->S.MaSach);
        H++;
        LS = LS->next;
    }
}

int PartitionHashTableMaSach(HashMaSach* H, int first, int last) { //Partition trong quicksort
    if(first >= last) return last;
    char c[100];
    strcpy(c, H[first].MaSach);
    int i = first + 1;
    int j = last;
    while (i <= j) {
        while (strcmp(H[i].MaSach, c) <= 0 && i <= j) i++;
        while (strcmp(H[j].MaSach, c) > 0 && i <= j) j--;
        if (i <= j) {
            swap(H[i], H[j]);
        }
    }
    swap(H[first], H[j]);
    return j;
}

void SapXepHashTableMaSach(HashMaSach* H, int first, int last) { //sap xep ma sach tren hashtable
    int j;
    if (first < last) {
        j = PartitionHashTableMaSach(H, first, last);
        SapXepHashTableMaSach(H, first, j - 1);
        SapXepHashTableMaSach(H, j+1, last);
    }
}

void SapXepSachTheoMa(LSach& LS) { //sap xep sach theo ma
    int N = DemSach(LS);
    HashMaSach* H = new HashMaSach[N];
    HashTableMaSach(H, LS);
    SapXepHashTableMaSach(H, 0, N - 1);
    LS = H[0].P;
    PSach A = LS;
    for (int i = 1; i < N; i++) {
        A->next = H[i].P;
        A = A->next;
    }
    A->next = nullptr;
    delete[] H;
}

void ThemSinhVien(LSV& lsv, char* msv, char* hoten) {
    PSV temp = new SinhVienNode;
    strcpy(temp->SV.MSV, msv);
    strcpy(temp->SV.HoTen, hoten);
    temp->next = lsv;
    lsv = temp;
}

void XoaSinhVien(LSV& lsv, char* msv) {
    PSV A = lsv;
    if (!strcmp(lsv->SV.MSV, msv)) {
        lsv = lsv->next;
        delete A;
    }
    while (A->next != nullptr) {
        if (!strcmp(A->next->SV.MSV, msv)) {
            PSV B = A->next;
            A->next = B->next;
            delete B;
        }
        A = A->next;
    }
}

PSV TimSinhVien(LSV lsv, char* msv) { //tim sinh vien theo msv
    while (lsv != nullptr) {
        if (!strcmp(lsv->SV.MSV, msv))
            return lsv;
        lsv = lsv->next;
    }
    return lsv;
}

int DemSinhVien(LSV lsv) { //dem so sinh vien
    int Count = 0;
    while (lsv != nullptr) {
        Count++;
        lsv = lsv->next;
    }
    return Count;
}


void MuonSach(PSV psv, PSach ps) {
    strcpy(ps->S.svm, psv->SV.MSV);
    PSM psm = new SachMuon;
    psm->P = ps;
    psm->next = psv->SV.SachMuon;
    psv->SV.SachMuon = psm;
}

void TraSach(PSach ps, PSV psv) {
    char masach[10];
    strcpy(masach, ps->S.MaSach);
    ps->S.svm[0] = '\0';
    PSM A = psv->SV.SachMuon;
    if (!strcmp(A->P->S.MaSach, masach)) {
        psv->SV.SachMuon = psv->SV.SachMuon->next;
        delete A;
        return;
    }
    while (A->next != nullptr) {
        if (!strcmp(A->next->P->S.MaSach, masach)) {
            PSM B = A->next;
            A->next = B->next;
            delete B;
            return;
        }
        A = A->next;
    }
}

vector<Sach> ConvertSachVector(LSach LS){
    vector<Sach> SachV;
    while(LS != nullptr) {
        SachV.push_back(LS->S);
        LS = LS->next;
    }
    return SachV;
}

vector<SinhVien> ConvertSVienVector(LSV LSVien){
    vector<SinhVien> SVienV;
    while(LSVien != nullptr) {
        SVienV.push_back(LSVien->SV);
        LSVien = LSVien->next;
    }
    return SVienV;
}

void SortLSachAlph(LSach& LS){
    vector<Sach> SachV = ConvertSachVector(LS);
    sort(SachV.begin(), SachV.end(), [](Sach a, Sach b) {
        return strcmp(a.TenSach, b.TenSach) > 0;
    });
    LSach temp = nullptr;
    for(Sach& a : SachV){
        ThemSach(temp, a.MaSach, a.TenSach, a.TheLoai, a.TacGia, a.NamXuatBan);
    }
    LS = temp;
}

void SortLSVienMSV(LSV& LSVien){
    vector<SinhVien> SVienV = ConvertSVienVector(LSVien);
    sort(SVienV.begin(), SVienV.end(), [](SinhVien a, SinhVien b) {
        return strcmp(a.MSV, b.MSV) > 0;
    });
    LSV temp = nullptr;
    for (SinhVien& a : SVienV) {
        ThemSinhVien(temp, a.MSV, a.HoTen);
    }
    LSVien = temp;
}


#endif
