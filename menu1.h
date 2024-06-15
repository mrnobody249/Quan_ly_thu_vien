#ifndef MENU_H
#define MENU_H

#include "sach1.h"

void Menu() {
    cout << "\tChuong Trinh Quan Ly Thu Vien" << endl;
    cout << "\t\t\tNhom 18" << endl;
    cout << endl;
    cout << "1. Nhap them mot cuon sach" << endl;
    cout << "2. Sua thong tin sach" << endl;
    cout << "3. Xoa mot cuon sach" << endl;
    cout << "4. Nhap thong tin sinh vien" << endl;
    cout << "5. Sua thong tin sinh vien" << endl;
    cout << "6. Xoa thong tin sinh vien" << endl;
    cout << "7. Muon sach" << endl;
    cout << "8. Tra sach" << endl;
    cout << "9. Liet ke toan bo sach trong thu vien" << endl;
    cout << "10. Liet ke toan bo sinh vien" << endl;
    cout << "11. Liet ke nhung sach duoc muon cua mot sinh vien" << endl;
    cout << "12. Liet ke toan bo sach duoc muon trong thu vien" << endl;
    cout << "13. Liet ke toan bo sach cua mot tac gia" << endl;
    cout << "14. Sap xep toan bo sinh vien theo msv" << endl;
    cout << "15. Sap xep toan bo sach theo ten" << endl;
    cout << "16. Sap xep toan bo sach duoc muon cua mot sinh vien theo ten" << endl;
    cout << "17. Thoat khoi he thong" << endl;
    cout << "=> Moi chon chuc nang: ";
}
void ThemSach() {
    cout << "\t\tNhap them mot cuon sach" << endl;
    cout << endl;
    char MS[10], Ten[100], Loai[100], TG[100];
    int NXB;;
    cin.ignore();
    cout << "- Nhap ma sach: ";
    cin.getline(MS, 10);
    cout << "- Nhap ten sach: ";
    cin.getline(Ten, 100);
    cout << "- Nhap the loai: ";
    cin.getline(Loai, 100);
    cout << "- Nhap tac gia: ";
    cin.getline(TG, 100);
    cout << "- Nhap nam xuat ban: ";
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
    cout << "- Nhap ten sach moi: ";
    cin.getline(newTen, 100);
    cout << "- Nhap the loai moi: ";
    cin.getline(newLoai, 100);
    cout << "- Nhap tac gia moi: ";
    cin.getline(newTG, 100);
    cout << "- Nhap nam xuat ban moi: ";
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
    cout << "- Nhap ma sinh vien: ";
    cin.getline(msv, 10);
    cout << "- Nhap ho va ten: ";
    cin.getline(hoten, 100);
    ThemSinhVien(sv, msv, hoten);
    cout << endl;
    cout << "\t\tThem sinh vien thanh cong ^^" << endl;
}
void SuaSinhVien() {
    cout << "\t\tSua thong tin sinh vien" << endl;
    cout << endl;
    char newMSV[10], newHoTen[100];
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
    //strcpy(temp->SV.MSV, newMSV);
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
void ToanBoSach() {
    cout << endl;
    SapXepSachTheoMa(s);
    PSach temp = s;
    while (temp != nullptr) {
        cout << temp->S.MaSach << "\t" << temp->S.TenSach << "\t" << temp->S.TheLoai << "\t"
            << temp->S.TacGia << "\t" << temp->S.NamXuatBan << "\t" << temp->S.svm << endl;
        temp = temp->next;
    }
}

void ToanBoSinhVien(){
    cout << endl;
    //SapXepSachTheoMa(s);
    PSV temp = sv;
    while (temp != nullptr) {
        cout << "MSV: " << temp->SV.MSV << ", HoTen: " << temp->SV.HoTen << endl;
        temp = temp->next;
    }
}

void SachMotSinhVienMuon() {
    cin.ignore();
    cout << "\t\tLiet ke nhung sach duoc muon cua mot sinh vien" << endl;
    cout << endl;
    char Finding[10];
    int stt = 0;
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
    if (temp == nullptr) {
        cout << endl;
        cout << "\t\tSinh vien khong muon sach nao" << endl;
        return;
    }
    while (sm != nullptr) {
        cout << "MaSach: " << sm->P->S.MaSach << ", TenSach: " << sm->P->S.TenSach << ", TheLoai: " << sm->P->S.TheLoai << ", TacGia: "
            << sm->P->S.TacGia << "\t\t" << sm->P->S.NamXuatBan << endl;
        sm = sm->next;
    }
}
void ToanBoSachDuocMuon(){
    cout << endl;
    SapXepSachTheoMa(s);
    PSach temp = s;
    while (temp != nullptr) {
        if((temp->S.svm[0] != '\0'))
            cout << temp->S.MaSach << "\t" << temp->S.TenSach << "\t" << temp->S.TheLoai << "\t"
                << temp->S.TacGia << "\t" << temp->S.NamXuatBan << "\t" << temp->S.svm << endl;
        temp = temp->next;
    }
}

void Thoat() {
    cout << endl;
    cout << "\t\tXin chao va hen gap lai!" << endl;
    cout << endl;
}

#endif
