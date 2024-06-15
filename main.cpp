
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
                SortLSVienMSV(sv);
                ToanBoSinhVien();
            case 15:
                SortLSachAlph(s);
                ToanBoSach();
            case 16:
                //to be implemented
            case 17:
                Thoat();
                break;
        }
        if(chon != 14) {
            cout << endl;
            cout << "========================="<<endl;
            cout << "=> Nhan Enter de tro ve !";
            cin.ignore();
            cin.get();
            system("clear");
        }
    }
    while(chon != 14);
	return 0;
}
