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
    float giaTien;
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

struct Node {
    SinhVien data;
    Node* next;
};



