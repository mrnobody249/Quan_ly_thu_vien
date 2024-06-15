/**/




/* Để vào file menu */

//Thêm cout các option vào menu
    /*
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
    */

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
    PSach temp = s;
    while (temp != nullptr) {
        if (!strcmp(temp->S.TacGia, TacGia))
            cout << temp->S.MaSach << "\t" << temp->S.TenSach << "\t" << temp->S.TheLoai << "\t"
                << temp->S.TacGia << "\t" << temp->S.NamXuatBan << "\t" << temp->S.svm << endl;
        temp = temp->next;
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


//Thêm vào switch case ở file main, đổi biến chon
/*
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
*/