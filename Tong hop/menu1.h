#ifndef MENU_H
#define MENU_H

#include "sach1.h"

void Menu() {
    cout << "\tChuong Trinh Quan Ly Thu Vien" << endl;
    cout << "\t\t\tNhom 16" << endl;
    cout << endl;
    cout << "1. Nhap them mot cuon sach" << endl;
    cout << "2. Sua thong tin sach" << endl;
    cout << "3. Xoa mot cuon sach" << endl;
    cout << "4. Nhap thong tin sinh vien" << endl;
    cout << "5. Sua thong tin sinh vien" << endl;
    cout << "6. Xoa thong tin sinh vien" << endl;
    cout << "7. Muon sach" << endl;
    cout << "8. Tra sach" << endl;
    cout << "9. Liet ke toan bo sach trong thu vien theo thu tu ma tang dan" << endl;
    cout << "10. Liet ke toan bo sach trong thu vien theo thu tu ten tang dan" << endl;
    cout << "11. Liet ke toan bo sinh vien" << endl;
    cout << "12. Liet ke nhung sach duoc muon cua mot sinh vien" << endl;
    cout << "13. Liet ke toan bo sach duoc muon trong thu vien" << endl;
    cout << "14. Liet ke nhung sach chua duoc muon" << endl;
    cout << "15. Liet ke toan bo sach trong nam" << endl;
    cout << "16. Liet ke sach cua mot tac gia" << endl;
    cout << "17. Tac gia duoc muon nhieu sach nhat" << endl;
    cout << "18. Tac gia duoc muon it sach nhat" << endl;
    cout << "19. Sach duoc muon nhieu nhat" << endl;
    cout << "20. Sach duoc muon it nhat" << endl;
    cout << "21. Sach duoc muon nhieu nhat cua mot tac gia" << endl;
    cout << "22. Sach duoc muon it nhat cua mot tac gia" << endl;
    cout << "23. Sinh vien muon nhieu sach nhat" << endl;
    cout << "24. Sinh vien muon it sach nhat" << endl;
    cout << "25. Thoat khoi he thong" << endl;
    cout << "=> Moi chon chuc nang: ";
}
void ThemSach() {
    cout << "\t\tNhap them mot cuon sach" << endl;
    cout << endl;
    char MS[10], Ten[100], Loai[100], TG[100];
    int NXB;;
    cin.ignore();
    cout << "Nhap ma sach: ";
    cin.getline(MS, 10);
    if(TimSachTheoMa(s, MS) != nullptr){ //Tung: Bo sung truong hop ma sach da ton tai
        cout << endl;
        cout << "Ma sach da ton tai. Vui long thu lai." << endl;
        return;
    }
    cout << "Nhap ten sach: ";
    cin.getline(Ten, 100);
    cout << "Nhap the loai: ";
    cin.getline(Loai, 100);
    cout << "Nhap tac gia: ";
    cin.getline(TG, 100);
    cout << "Nhap nam xuat ban: ";
    cin >> NXB;
    ThemSach(s, MS, Ten, Loai, TG, NXB);
    cout << endl;
    cout << "\t\tThem sach thanh cong." << endl;
}

void SuaSach() {
    cout << "\t\tSua thong tin sach" << endl;
    cout << endl;
    char Finding[10];
    char newTen[100], newLoai[100], newTG[100];
    int newNXB;
    cin.ignore();
    cout << "Nhap ma sach can sua: ";
    cin.getline(Finding, 10);
    PSach temp = TimSachTheoMa(s, Finding);
    if (temp == nullptr) {
        cout << endl;
        cout << "\t\tMa sach vua nhap khong ton tai. Vui long thu lai !" << endl;
        return;
    }
    cout << "Nhap ten sach moi: ";
    cin.getline(newTen, 100);
    cout << "Nhap the loai moi: ";
    cin.getline(newLoai, 100);
    cout << "Nhap tac gia moi: ";
    cin.getline(newTG, 100);
    cout << "Nhap nam xuat ban moi: ";
    cin >> newNXB;
    strcpy(temp->S.TenSach, newTen);
    strcpy(temp->S.TheLoai, newLoai);
    strcpy(temp->S.TacGia, newTG);
    temp->S.NamXuatBan = newNXB;
    cout << endl;
    cout << "\t\tSua thong tin sach thanh cong." << endl;
    return;
}
void XoaSach() {
    cout << "\t\tXoa mot cuon sach" << endl;
    cout << endl;
    char Finding[10];
    cout << "Nhap ma sach can xoa: ";
    cin.ignore();
    cin.getline(Finding, 10);
    PSach temp = TimSachTheoMa(s, Finding);
    if (temp == nullptr) {
        cout << endl;
        cout << "\t\tMa sach vua nhap khong ton tai. Vui long thu lai !" << endl;
        return;
    }
    if (TimSinhVien(sv, temp->S.svm) != nullptr) {
        cout << endl;
        cout << "\t\tSach nay dang duoc muon. Khong the xoa, vui long thu lai!" << endl;
        return;
    }
    XoaSach(s, Finding);
    cout << endl;
    cout << "\tXoa sach thanh cong" << endl;
    return;
}
void ThemSinhVien() {
    cout << "\t\tNhap thong tin sinh vien" << endl;
    cout << endl;
    char msv[10], hoten[100];
    cin.ignore();
    cout << "Nhap ma sinh vien: ";
    cin.getline(msv, 10);
    if(TimSinhVien(sv, msv) != nullptr){ //Tung: Bo sung truong hop nhap ma sinh vien da ton tai
        cout << endl;
        cout << "\t\tMa sinh vien vua nhap da ton tai. Vui long thu lai !" << endl;
        return;
    }
    cout << "Nhap ho va ten: ";
    cin.getline(hoten, 100);
    ThemSinhVien(sv, msv, hoten);
    cout << endl;
    cout << "\t\tThem sinh vien thanh cong ^^" << endl;
}
void SuaSinhVien() {
    cout << "\t\tSua thong tin sinh vien" << endl;
    cout << endl;
    char newHoTen[100];
    char Finding[10];
    cin.ignore();
    cout << "Nhap ma sinh vien can sua: ";
    cin.getline(Finding, 10);
    PSV temp = TimSinhVien(sv, Finding);
    if (temp == nullptr) {
        cout << endl;
        cout << "\t\tMa sinh vien vua nhap khong ton tai. Vui long thu lai !" << endl;
        return;
    }
    cout << "- Nhap ho va ten moi: ";
    cin.getline(newHoTen, 100);
    strcpy(temp->SV.HoTen, newHoTen);
    cout << endl;
    cout << "\t\tSua thong tin sinh vien thanh cong." << endl;
    return;
}
void XoaSinhVien() {
    cout << "\t\tXoa thong tin sinh vien" << endl;
    cout << endl;
    char Finding[10];
    cin.ignore();
    cout << "- Nhap ma sinh vien can xoa: ";
    cin.getline(Finding, 10);
    PSV temp = TimSinhVien(sv, Finding);
    if (temp == nullptr) {
        cout << endl;
        cout << "\t\tMa sinh vien vua nhap khong ton tai. Vui long thu lai !" << endl;
        return;
    }
    if (temp->SV.SachMuon != nullptr) {
        cout << endl;
        cout << "\t\tSinh vien can xoa dang no sach. Vui long thu lai !" << endl;
        return;
    }
    XoaSinhVien(sv, Finding);
    cout << endl;
    cout << "\tXoa sinh vien thanh cong" << endl;
    return;
}
void MuonSach() {
    cout << "\t\tMuon sach" << endl;
    cout << endl;
    char msv[10], ms[10];
    cin.ignore();
    cout << "- Nhap ma sinh vien: ";
    cin.getline(msv, 10);
    cout << "- Nhap ma sach: ";
    cin.getline(ms, 10);
    PSach temp1 = TimSachTheoMa(s, ms);
    if (temp1 == nullptr) {
        cout << endl;
        cout << "\t\tMa sach vua nhap khong ton tai. Vui long thu lai !" << endl;
        return;
    }
    if (TimSinhVien(sv, temp1->S.svm) != nullptr) {
        cout << endl;
        cout << "\t\tSach nay dang duoc muon. Vui long thu lai!" << endl;
        return;
    }
    PSV temp2 = TimSinhVien(sv, msv);
    if (temp2 == nullptr) {
        cout << endl;
        cout << "\t\tMa sinh vien vua nhap khong ton tai. Vui long thu lai !" << endl;
        return;
    }
    MuonSach(temp2, temp1);
    cout << endl;
    cout << "Muon sach thanh cong" << endl;
}
void TraSach() {
    cout << "\t\tTra sach" << endl;
    cout << endl;
    char ms[10];
    cin.ignore();
    cout << "- Nhap ma sach: ";
    cin.getline(ms, 10);
    PSach ps = TimSachTheoMa(s, ms);
    if(ps == nullptr){
        cout << endl;
        cout << "\tMa sach khong ton tai. Vui long thu lai!" << endl;
        return;
    }
    PSV psv = TimSinhVien(sv, ps->S.svm);
    if(psv == nullptr){
        cout << endl;
        cout << "\tSach khong nguoi muon. Vui long thu lai!" << endl;
        return;
    }
    TraSach(ps, psv);
    cout << endl;
    cout << "\tTra sach thanh cong" << endl;
    return;
}
void ToanBoSach(bool ASorted = false) { //Liet ke toan bo sach
    cout << endl;
    if(s == nullptr){ //Tung: Bo sung truong hop khong co sach
        cout << "Khong co quyen sach nao" << endl;
        return;
    }
    if (ASorted){
        BubbleSortSach(s); // Liet ke theo thu tu ten sach tang dan
    }
    else SapXepSachTheoMa(s); //Mac dinh sap xep theo ma, ASorted true => sx theo Ten
    PSach temp = s;
    while (temp != nullptr) {
        cout << temp->S.MaSach << "\t" << temp->S.TenSach << "\t" << temp->S.TheLoai << "\t"
            << temp->S.TacGia << "\t" << temp->S.NamXuatBan << "\t" << temp->S.svm << endl;
        temp = temp->next;
    }
}

void ToanBoSinhVien(){ // Liet ke toan bo sinh vien theo thu tu ma sinh vien tang dan
                        //Tung: bo Asorted ma cho sap xep luon
    cout << endl;
    if(sv == nullptr){ //Tung: Bo sung truong hop khong co sinh vien
        cout << "Khong co sinh vien nao" << endl;
        return;
    }
    PSV temp = sv;
    BubbleSortSinhVien(sv);
    while (temp != nullptr) {
        cout << "MSV: " << temp->SV.MSV << ", HoTen: " << temp->SV.HoTen << endl;
        temp = temp->next;
    }
}

void SachMotSinhVienMuon() {// Liet ke toan bo sach sinh vien muon theo thu tu ten sach tang dan
                                                //Tung: bo Asorted ma cho sap xep luon
    cin.ignore();
    cout << "\t\tLiet ke nhung sach duoc muon cua mot sinh vien" << endl;
    cout << endl;
    char Finding[10];
    cout << "Nhap ma sinh vien: ";
    cin.getline(Finding, 10);
    cout << endl;
    PSV temp = TimSinhVien(sv, Finding);
    if (temp == nullptr) {
        cout << endl;
        cout << "\t\tMa sinh vien vua nhap khong ton tai. Vui long thu lai !" << endl;
        return;
    }
    cout << "Ma sach\t\tTen sach\t\tThe loai\t\tTac gia\t\tNam xuat ban" << endl;
    cout << endl;
    PSM sm = temp->SV.SachMuon;
    if (sm == nullptr) {
        cout << endl;
        cout << "\t\tSinh vien khong muon sach nao" << endl;
        return;
    }
    BubbleSortSachMuon(sm);
    while (sm != nullptr) {
        cout << "MaSach: " << sm->P->S.MaSach << ", TenSach: " << sm->P->S.TenSach << ", TheLoai: " << sm->P->S.TheLoai << ", TacGia: "
            << sm->P->S.TacGia << ", NamXuatBan: " << sm->P->S.NamXuatBan << endl;
        sm = sm->next;
    }
}
void ToanBoSachDuocMuon(){
    cout << endl;
    SapXepSachTheoMa(s);
    PSach temp = s;
    bool found = false; //Bo sung truong hop khong co sach nao duoc muon
    while (temp != nullptr) {
        if((temp->S.svm[0] != '\0')){
            found = true;
            cout << temp->S.MaSach << "\t" << temp->S.TenSach << "\t" << temp->S.TheLoai << "\t"
                << temp->S.TacGia << "\t" << temp->S.NamXuatBan << "\t" << temp->S.svm << endl;
        }
        temp = temp->next;
    }
    if(!found)
        cout << "Khong co sach nao duoc muon" << endl;
    return;
}




//Do Chi Cong - 20223888




void SachChuaMuon() {
    cout << endl;
    SapXepSachTheoMa(s);
    PSach temp = s;
    while (temp != nullptr) {
        if((temp->S.svm[0] == '\0'))
            cout << temp->S.MaSach << "\t" << temp->S.TenSach << "\t" << temp->S.TheLoai << "\t"
                << temp->S.TacGia << "\t" << temp->S.NamXuatBan << "\t" << temp->S.svm << endl;
        temp = temp->next;
    }
}

void CacSachCuaNam() {
    cout << endl;
    int nam;
    cout << "Nhap nam xuat ban: ";
    cin >> nam;
    PSach temp = s;
    bool found = false;
    while (temp != nullptr) {
        if (temp->S.NamXuatBan == nam) {
            found = true;
            cout << temp->S.MaSach << "\t" << temp->S.TenSach << "\t" << temp->S.TheLoai << "\t"
                << temp->S.TacGia << "\t" << temp->S.NamXuatBan << "\t" << temp->S.svm << endl;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Khong co sach nao duoc xuat ban nam " << nam << endl;
    }
}

void CacSachCuaMotTacGia() {
    cout << endl;
    char TacGia[100];
    cin.ignore();
    cout << "Nhap ten tac gia: ";
    cin.getline(TacGia, 100);
    PSach temp = s; //Tung bo sung truong hop ko co sach cua tac gia
    bool found = false;
    while (temp != nullptr) {
        if (!strcmp(temp->S.TacGia, TacGia))
            cout << temp->S.MaSach << "\t" << temp->S.TenSach << "\t" << temp->S.TheLoai << "\t"
                << temp->S.TacGia << "\t" << temp->S.NamXuatBan << "\t" << temp->S.svm << endl;
        temp = temp->next;
    }
    if (!found) { //Tung bo sung truong hop ko co sach cua tac gia
        cout << "Khong co sach nao cua tac gia " << TacGia << endl;
    }
}

void TacGiaDuocMuonNhieuSachNhat() {
    cout << endl;
    PSach temp = s;
    int max = 0;
    char tenTacGia[100];
    while(temp != nullptr){
        int count = 0;
        PSach p = s;
        while(p != nullptr){
            if(strcmp(p->S.TacGia, temp->S.TacGia) == 0){
                count++;
            }
            p = p->next;
        }
        if(count > max){
            max = count;
            strcpy(tenTacGia, temp->S.TacGia);
        }
        temp = temp->next;
    }
    cout << "Tac gia duoc muon nhieu sach nhat la: " << tenTacGia << endl;
    cout << "So sach duoc muon: " << max << endl;
}

void TacGiaDuocMuonItSachNhat() {
    cout << endl;
    PSach temp = s;
    int min = 100000;
    char tenTacGia[100];
    while(temp != nullptr){
        int count = 0;
        PSach p = s;
        while(p != nullptr){
            if(strcmp(p->S.TacGia, temp->S.TacGia) == 0){
                count++;
            }
            p = p->next;
        }
        if(count < min){
            min = count;
            strcpy(tenTacGia, temp->S.TacGia);
        }
        temp = temp->next;
    }
    cout << "Tac gia duoc muon it sach nhat la: " << tenTacGia << endl;
    cout << "So sach duoc muon: " << min << endl;
}

void SachDuocMuonNhieuNhat() {
    cout << endl;
    PSach temp = s;
    int max = 0;
    char tenSach[100];
    while(temp != nullptr){
        int count = 0;
        PSV psv = sv;
        while(psv != nullptr){
            PSM sm = psv->SV.SachMuon;
            while(sm != nullptr){
                if(strcmp(sm->P->S.TenSach, temp->S.TenSach) == 0){
                    count++;
                }
                sm = sm->next;
            }
            psv = psv->next;
        }
        if(count > max){
            max = count;
            strcpy(tenSach, temp->S.TenSach);
        }
        temp = temp->next;
    }
    cout << "Sach duoc muon nhieu nhat la: " << tenSach << endl;
    cout << "So lan muon: " << max << endl;
}

void SachDuocMuonItNhat() {
    cout << endl;
    PSach temp = s;
    int min = 100000;
    char tenSach[100];
    while(temp != nullptr){
        int count = 0;
        PSV psv = sv;
        while(psv != nullptr){
            PSM sm = psv->SV.SachMuon;
            while(sm != nullptr){
                if(strcmp(sm->P->S.TenSach, temp->S.TenSach) == 0){
                    count++;
                }
                sm = sm->next;
            }
            psv = psv->next;
        }
        if(count < min){
            min = count;
            strcpy(tenSach, temp->S.TenSach);
        }
        temp = temp->next;
    }
    cout << "Sach duoc muon it nhat la: " << tenSach << endl;
    cout << "So lan muon: " << min << endl;
}

void SachMuonNhieuNhatCuaTacGia() {
    cout << endl;
    char TacGia[100];
    cin.ignore();
    cout << "Nhap ten tac gia: ";
    cin.getline(TacGia, 100);
    PSach temp = s;
    int maxCount = 0;
    PSach maxSach = nullptr;
    while (temp != nullptr) {
        if (strcmp(temp->S.TacGia, TacGia) == 0) {
            int count = 0;
            PSV psv = sv;
            while (psv != nullptr) {
                PSM sm = psv->SV.SachMuon;
                while (sm != nullptr) {
                    if (strcmp(sm->P->S.TenSach, temp->S.TenSach) == 0) {
                        count++;
                    }
                    sm = sm->next;
                }
                psv = psv->next;
            }
            if (count > maxCount) {
                maxCount = count;
                maxSach = temp;
            }
        }
        temp = temp->next;
    }
    if (maxSach != nullptr) {
        cout << "Sach cua tac gia " << TacGia << " duoc muon nhieu nhat la: " << maxSach->S.TenSach << endl;
        cout << "So lan muon: " << maxCount << endl;
    } else {
        cout << "Tac gia " << TacGia << " khong co sach duoc muon" << endl;
    }
}

void SachMuonItNhatCuaTacGia() {
    cout << endl;
    char TacGia[100];
    cin.ignore();
    cout << "Nhap ten tac gia: ";
    cin.getline(TacGia, 100);
    PSach temp = s;
    int minCount = 100000;
    PSach minSach = nullptr;
    while (temp != nullptr) {
        if (strcmp(temp->S.TacGia, TacGia) == 0) {
            int count = 0;
            PSV psv = sv;
            while (psv != nullptr) {
                PSM sm = psv->SV.SachMuon;
                while (sm != nullptr) {
                    if (strcmp(sm->P->S.TenSach, temp->S.TenSach) == 0) {
                        count++;
                    }
                    sm = sm->next;
                }
                psv = psv->next;
            }
            if (count < minCount) {
                minCount = count;
                minSach = temp;
            }
        }
        temp = temp->next;
    }
    if (minSach != nullptr) {
        cout << "Sach cua tac gia " << TacGia << " duoc muon it nhat la: " << minSach->S.TenSach << endl;
        cout << "So lan muon: " << minCount << endl;
    } else {
        cout << "Tac gia " << TacGia << " khong co sach duoc muon" << endl;
    }
}

void SVMuonNhieuSachNhat() {
    cout << endl;
    PSV temp = sv;
    int max = 0;
    char msv[10];
    while(temp != nullptr){
        int count = 0;
        PSM sm = temp->SV.SachMuon;
        while(sm != nullptr){
            count++;
            sm = sm->next;
        }
        if(count > max){
            max = count;
            strcpy(msv, temp->SV.MSV);
        }
        temp = temp->next;
    }
    cout << "Sinh vien muon nhieu sach nhat la: " << msv << endl;
    cout << "So sach muon: " << max << endl;
}

void SVMuongItSachNhat() {
    cout << endl;
    PSV temp = sv;
    int min = 100000;
    char msv[10];
    while(temp != nullptr){
        int count = 0;
        PSM sm = temp->SV.SachMuon;
        while(sm != nullptr){
            count++;
            sm = sm->next;
        }
        if(count < min){
            min = count;
            strcpy(msv, temp->SV.MSV);
        }
        temp = temp->next;
    }
    cout << "Sinh vien muon it sach nhat la: " << msv << endl;
    cout << "So sach muon: " << min << endl;
}




//Do Chi Cong - 20223888




void Thoat() {
    cout << endl;
    cout << "\t\tXin chao va hen gap lai!" << endl;
    cout << endl;
}

#endif

