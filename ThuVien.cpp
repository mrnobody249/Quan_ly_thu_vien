#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <conio.h>
#define MAX 100

using namespace std;

struct Sach {
    char tenSach[50];
    char tacGia[50];
    int namXuatBan;
    char theLoai[50];
};

struct NodeSach {
    Sach data;
    NodeSach* next;
};

struct SinhVien {
    long mssv;
    char hoTen[50]; 
    char nganhHoc[50];
    Sach* sachMuon;
};

struct NodeSV {
    SinhVien data;
    NodeSV* next;
};

void addSVDau(NodeSV** pHead, SinhVien sv) {
    NodeSV* pNew = new NodeSV;
    pNew->data = sv;
    pNew->next = *pHead;
    *pHead = pNew;
}

void addSVCuoi(NodeSV** p, SinhVien sv) {
    NodeSV* pNew = new NodeSV;
    pNew->data = sv;
    pNew->next = (*p)->next;
    (*p)->next = pNew;
}

NodeSV* findSVMSSV(NodeSV* pHead, long mssv) {
    while (pHead != NULL && pHead->data.mssv != mssv) {
        pHead = pHead->next;
    }
    return pHead;
}

void displayList(NodeSV* pHead) {
    while (pHead != NULL) {
        cout << "MSSV: " << pHead->data.mssv << endl;
        cout << "Ho ten: " << pHead->data.hoTen << endl;
        cout << "Nganh hoc: " << pHead->data.nganhHoc << endl;
        cout << "Sach muon: " << "\n\n";
        Sach* p = pHead->data.sachMuon;
        while (p != NULL) {
            cout << "Ten sach: " << p->tenSach << endl;
            cout << "Tac gia: " << p->tacGia << endl;
            cout << "Nam xuat ban: " << p->namXuatBan << endl;
            cout << "The loai: " << p->theLoai << endl;
            p = p->next;
        }
        pHead = pHead->next;
    }
}
