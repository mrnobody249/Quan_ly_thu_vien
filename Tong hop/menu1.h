#ifndef MENU_H
#define MENU_H

#include "sach1.h"
#include <map>
#include <ostream>
#include <fstream>

void Menu() {    //Ham in ra menu
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
    cout << "10. Liet ke toan bo sinh vien" << endl;
    cout << "11. Liet ke nhung sach duoc muon cua mot sinh vien" << endl;
    cout << "12. Liet ke toan bo sach duoc muon trong thu vien" << endl;
    cout << "13. Liet ke nhung sach chua duoc muon" << endl;
    cout << "14. Liet ke toan bo sach trong nam" << endl;
    cout << "15. Liet ke sach cua mot tac gia" << endl;
    cout << "16. Tac gia duoc muon nhieu sach nhat" << endl;
    cout << "17. Tac gia duoc muon it sach nhat" << endl;
    cout << "18. Sach duoc muon nhieu nhat" << endl;
    cout << "19. Sach duoc muon it nhat" << endl;
    cout << "20. Sach duoc muon nhieu nhat cua mot tac gia" << endl;
    cout << "21. Sach duoc muon it nhat cua mot tac gia" << endl;
    cout << "22. Sinh vien muon nhieu sach nhat" << endl;
    cout << "23. Sinh vien muon it sach nhat" << endl;
    cout << "24. Xuat toan bo du lieu ra file" << endl;
    cout << "25. Tai du lieu tu file vao he thong" << endl;
    cout << "26. Thong ke sach theo nam xuat ban" << endl;
    cout << "27. Thong ke sach muon" << endl;
    cout << "28. Thoat khoi he thong" << endl;
    cout << "=> Moi chon chuc nang: ";
}
void ThemSach() {    //Thu thu them sach
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

void SuaSach() {    //Thu thu sua thong tin sach
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
void XoaSach() {    //Thu thu xoa sach
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
void ThemSinhVien() {    //Thu thu them sinh vien
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
void SuaSinhVien() {    //Thu thu sua thong tin sinh vien
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
void XoaSinhVien() {    //Thu thu xoa sinh vien
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
void MuonSach() {    //Thu thu cho muon sach
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
void TraSach() {    //Thu thu thong bao tra sach
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
void ToanBoSach() { //Liet ke toan bo sach
    cout << endl;
    if(s == nullptr){
        cout << "Khong co quyen sach nao" << endl;
        return;
    }
    SapXepSachTheoMa(s);
    PSach temp = s;
    while (temp != nullptr) {
        cout << temp->S.MaSach << "\t" << temp->S.TenSach << "\t" << temp->S.TheLoai << "\t"
            << temp->S.TacGia << "\t" << temp->S.NamXuatBan << "\t" << temp->S.svm << endl;
        temp = temp->next;
    }
}

void ToanBoSinhVien(){ // Liet ke toan bo sinh vien theo thu tu ma sinh vien tang dan
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
void ToanBoSachDuocMuon(){    //Liet ke toan bo sach duoc muon
    cout << endl;
    SapXepSachTheoMa(s);
    PSach temp = s;
    bool found = false;
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




void SachChuaMuon() {    //Liet ke nhung sach khong duoc muon
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

void CacSachCuaNam() {    //Liet ke nhung sach trong nam
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

void CacSachCuaMotTacGia() {    //Liet ke nhung sach cua tac gia
    cout << endl;
    char TacGia[100];
    cin.ignore();
    cout << "Nhap ten tac gia: ";
    cin.getline(TacGia, 100);
    PSach temp = s; //Tung bo sung truong hop ko co sach cua tac gia
    bool found = false;
    while (temp != nullptr) {
        if (!strcmp(temp->S.TacGia, TacGia)){
            found = true;
            cout << temp->S.MaSach << "\t" << temp->S.TenSach << "\t" << temp->S.TheLoai << "\t"
                << temp->S.TacGia << "\t" << temp->S.NamXuatBan << "\t" << temp->S.svm << endl;
        }
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
        if(temp->S.svm[0] != '\0'){
            int count = 0;
            PSach p = s;
            while(p != nullptr){
                if(strcmp(p->S.TacGia, temp->S.TacGia) == 0 && p->S.svm[0] != '\0'){
                    count++;
                }
                p = p->next;
            }
            if(count > max){
                max = count;
                strcpy(tenTacGia, temp->S.TacGia);
            }
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
            if(strcmp(p->S.TacGia, temp->S.TacGia) == 0 && p->S.svm[0] != '\0'){
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

void SachDuocMuonNhieuNhat() {    //Dau sach duoc muon nhieu nhat
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

void SachDuocMuonItNhat() {    //Dau sach duoc muon it nhat
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

void SVMuonNhieuSachNhat() {    //Sinh vien muon nhieu sach nhat
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

void SVMuongItSachNhat() {    //Sinh vien muon it sach nhat
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




// Nguyen Duc Tu
void LuuDuLieu() {    //Ghi du lieu vao file txt
    ofstream file("library_data.txt");
    if (!file.is_open()) {
        cout << "Khong the mo tep de luu du lieu." << endl;
        return;
    }

    // Tu: Luu sach
    PSach tempSach = s;
    while (tempSach != nullptr) {
        file << "SACH" << endl;
        file << tempSach->S.MaSach << endl;
        file << tempSach->S.TenSach << endl;
        file << tempSach->S.TheLoai << endl;
        file << tempSach->S.TacGia << endl;
        file << tempSach->S.NamXuatBan << endl;
        file << tempSach->S.svm << endl;
        tempSach = tempSach->next;
    }

    // Tu: Luu sinh vien
    PSV tempSV = sv;
    while (tempSV != nullptr) {
        file << "SINHVIEN" << endl;
        file << tempSV->SV.MSV << endl;
        file << tempSV->SV.HoTen << endl;
        PSM sm = tempSV->SV.SachMuon;
        while (sm != nullptr) {
            file << "SACHMUON" << endl;
            file << sm->P->S.MaSach << endl;
            sm = sm->next;
        }
        tempSV = tempSV->next;
    }

    file.close();
    cout << "Luu du lieu thanh cong!" << endl;
}

void TaiDuLieu() {    //Doc du lieu tu file txt
    ifstream file("library_data.txt");
    if (!file.is_open()) {
        cout << "Khong the mo tep de tai du lieu." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line == "SACH") {
            Sach sach;
            string MaSach, TenSach, TheLoai, TacGia, NamXuatBan;
            getline(file, MaSach);
            getline(file, TenSach);
            getline(file, TheLoai);
            getline(file, TacGia);
            sach.NamXuatBan = stoi(NamXuatBan);
            strcpy(sach.MaSach, MaSach.c_str());
            strcpy(sach.TenSach, TenSach.c_str());
            strcpy(sach.TheLoai, TheLoai.c_str());
            strcpy(sach.TacGia, TacGia.c_str());

            ThemSach(s, sach.MaSach, sach.TenSach, sach.TheLoai, sach.TacGia, sach.NamXuatBan);
        } else if (line == "SINHVIEN") {
            SinhVien svien;
            string MSV, HoTen;
            getline(file, MSV);
            getline(file, HoTen);

            strcpy(svien.MSV, MSV.c_str());
            strcpy(svien.HoTen, HoTen.c_str());

            ThemSinhVien(sv, svien.MSV, svien.HoTen);
        }
    }

    file.close();
    cout << "Tai du lieu thanh cong!" << endl;
}

// Tu: Thống kê số lượng sách theo năm xuất bản
void ThongKeSachTheoNamXuatBan() {
    map<int, int> thongKe;
    PSach temp = s;
    while (temp != nullptr) {
        thongKe[temp->S.NamXuatBan]++;
        temp = temp->next;
    }

    cout << "Thong ke sach theo nam xuat ban:" << endl;
    for (const auto& entry : thongKe) {
        cout << entry.first << ": " << entry.second << " quyen" << endl;
    }
}

// Tu: Thống kê số lượng sách đang được mượn và chưa được mượn
void ThongKeSachMuon() {
    int sachMuon = 0;
    int sachChuaMuon = 0;
    PSach temp = s;
    while (temp != nullptr) {
        if (temp->S.svm[0] == '\0') {
            sachChuaMuon++;
        } else {
            sachMuon++;
        }
        temp = temp->next;
    }

    cout << "Thong ke sach muon va chua muon:" << endl;
    cout << "Sach muon: " << sachMuon << " quyen" << endl;
    cout << "Sach chua muon: " << sachChuaMuon << " quyen" << endl;
}
void Thoat() {
    cout << endl;
    cout << "\t\tXin chao va hen gap lai!" << endl;
    cout << endl;
}

#endif

