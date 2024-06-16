
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
                ToanBoSinhVien();
                break;
            case 11:
                SachMotSinhVienMuon();
                break;
            case 12:
                ToanBoSachDuocMuon();
                break;
            case 13:
                SachChuaMuon();
                break;
            case 14:
                CacSachCuaNam();
                break;
            case 15:
                CacSachCuaMotTacGia();
                break;
            case 16:
                TacGiaDuocMuonNhieuSachNhat();
                break;
            case 17:
                TacGiaDuocMuonItSachNhat();
                break;
            case 18:
                SachDuocMuonNhieuNhat();
                break;
            case 19:
                SachDuocMuonItNhat();
                break;
            case 20:
                SachMuonNhieuNhatCuaTacGia();
                break;
            case 21:
                SachMuonItNhatCuaTacGia();
                break;
            case 22:
                SVMuonNhieuSachNhat();
                break;
            case 23:
                SVMuongItSachNhat();
                break;
            case 24:
                LuuDuLieu();
                break;
            case 25:
                TaiDuLieu();
                break;
            case 26:
                ThongKeSachTheoNamXuatBan();
		break;
	    case 27:
		ThongKeSachMuon();
		break;
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
            system("cls");
        }
    }
    while(chon != 28);
	return 0;
}
