
#include <iostream>
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
                break;
            case 14:
                ToanBoSinhVien(1);
                break;
            case 15:
                ToanBoSach(1);
                break;
            case 16:
                SachMotSinhVienMuon(1);
                break;
            case 17:
                Thoat();
                break;
        }
        if(chon != 17) {
            cout << endl;
            cout << "========================="<<endl;
            cout << "=> Nhan Enter de tro ve !";
            cin.ignore();
            cin.get();
            system("clear");
        }
    }
    while(chon != 17);
	return 0;
}
