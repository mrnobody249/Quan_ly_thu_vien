
#include <iostream>
#include <conio.h>
#include "sach1.h"
#include "menu1.h"

using namespace std;

int main() {
    int chon;
    do {
        Menu();
        cin >> chon;
        cout << "=========================" << endl;
        switch(chon) {
            case 1:
                ThemSach();
                break;
            case 2:
                SuaSach();
                break;
            case 3:
                XoaSach();
                break;
            case 4:
                ThemSinhVien();
                break;
            case 5:
                SuaSinhVien();
                break;
            case 6:
                XoaSinhVien();
                break;
            case 7:
                MuonSach();
                break;
            case 8:
                TraSach();
                break;
            case 9:
                ToanBoSach();
                break;
            case 10:
                ToanBoSach(1);
                break;
            case 11:
                ToanBoSinhVien();
                break;
            case 12:
                SachMotSinhVienMuon();
                break;
            case 13:
                ToanBoSachDuocMuon();
                break;
            case 14:
                SachChuaMuon();
                break;
            case 15:
                CacSachCuaNam();
                break;
            case 16:
                CacSachCuaMotTacGia();
                break;
            case 17:
                TacGiaDuocMuonNhieuSachNhat();
                break;
            case 18:
                TacGiaDuocMuonItSachNhat();
                break;
            case 19:
                SachDuocMuonNhieuNhat();
                break;
            case 20:
                SachDuocMuonItNhat();
                break;
            case 21:
                SachMuonNhieuNhatCuaTacGia();
                break;
            case 22:
                SachMuonItNhatCuaTacGia();
                break;
            case 23:
                SVMuonNhieuSachNhat();
                break;
            case 24:
                SVMuongItSachNhat();
                break;
            case 25:
                LuuDuLieu();
                break;
            case 26:
                TaiDuLieu();
                break;
            case 27:
                ThongKeSachTheoNamXuatBan();
            case 28:
                Thoat();
                break;
        }
        if(chon != 28) {
            cout << endl;
            cout << "========================="<<endl;
            cout << "=> Nhan Enter de tro ve !";
            cin.ignore();
            cin.get();
            system("clear");
        }
    }
    while(chon != 28);
	return 0;
}
