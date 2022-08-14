#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct SinhVien
{
    int maSV;
    char hoTen[30];
    float diem;
    char xepLoai[15];
}SV;
void nhapMotSV(SV sv)
{
    printf("-->MA SO SV: ");
    scanf("%d", &sv.maSV);
    printf("-->HO TEN SV: ");       
    fflush(stdin);
    gets(sv.hoTen);
    printf("-->DIEM SV: ");
    scanf("%f", &sv.diem);
}
void nhapMangSV(SV sv[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("Nhap thong tin sinh vien thu %d:\n", i+1);
        nhapMotSV(sv[i]);

        if(sv[i].diem >= 8)
            strcpy(sv[i].xepLoai, "GIOI");
        else if(7 <= sv[i].diem && sv[i].diem < 8)
            strcpy(sv[i].xepLoai, "KHA");
        else if(5 <= sv[i].diem && sv[i].diem < 7)
            strcpy(sv[i].xepLoai, "TRUNG BINH");
        else
            strcpy(sv[i].xepLoai, "YEU");

        for(int j=0; j<i; j++)
            while(sv[i].maSV == sv[j].maSV)
            {
                printf("Trung ma sinh vien. Moi nhap lai ma sinh vien: ");
                scanf("%d", &sv[i].maSV);
            }
    }
}

void xuatMotSV(SV sv, int i)
{
    printf("%-5d %-20d %-30s %10.2f %20s\n", i, sv.maSV, sv.hoTen, sv.diem, sv.xepLoai);
}
void XuatMangSV(SV sv[], int n)
{
    printf("%-5s %-20s %-30s %10s %20s\n", "STT", "MSSV", "HO TEN", "DIEM", "XEP LOAI");
    for(int i=0; i<n; i++)
        xuatMotSV(sv[i], i+1);
}

int linearSearch(SV sv[], int n, int x)
{
    int i = 0;
    sv[n].maSV = x;
    while(sv[i].maSV != x)
        i++;
    if(i<n) return i;
    return -1;
}
void HoanVi(SV a, SV b)
{
    SV t = a;  a = b;   b = t;
}
void interChangeSort(SV sv[], int n)
{
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(sv[i].diem < sv[j].diem)
                HoanVi(sv[i], sv[j]);
}
void deleteY(SV sv[], int n, int k)
{
    for(int i=k; i<n-1; i++)
        sv[i] = sv[i+1];
    n--;
}
int main()
{
    int n, chon = 0 , x, kq;
    SV sv[MAX];
    do
    {
        system("cls");
        printf("\t\t\t ============MENU================================\n");
        printf("\t\t\t |1. Tao danh sach sinh vien                    |\n");
        printf("\t\t\t |2. Xuat danh sach sinh vien                   |\n");
        printf("\t\t\t |3. Tim Kiem sinh vien ma X                    |\n");
        printf("\t\t\t |4. Sap xep danh sach theo thu tu giam dan diem|\n");
        printf("\t\t\t |5. Xoa sinh vien co ma Y                      |\n");
        printf("\t\t\t |6. Thoat                                      |\n");
        printf("\t\t\t ================================================\n");
        printf("Ban chon: ");
        scanf("%d", &chon);
        switch(chon)
        {
            case 1:
                printf("Nhap so luong sinh vien: ");
                scanf("%d", &n);
                nhapMangSV(sv,n);
                break;
            case 2:
                XuatMangSV(sv,n);
                break;
            case 3:
                printf("Nhap vao ma sinh vien can tim kiem: ");
                scanf("%d", &x);
                kq = linearSearch(sv,n,x);
                if(kq == -1)
                    printf("Du lieu sai\n");
                else
                {
                    printf("THONG TIN SV TIM THAY:\n");
                    printf("%-5s %-20s %-30s %10s %20s\n", "STT", "MSSV", "HO TEN", "DIEM", "XEP LOAI");
                    xuatMotSV(sv[kq],kq);
                }
                break;
            case 4:
                interChangeSort(sv,n);
                printf("DANH SACH SAU KHI SAP XEP DIEM GIAM DAN:\n");
                XuatMangSV(sv,n);
                break;
            case 5:
                printf("Nhap ma sinh vien can xoa: ");
                scanf("%d", &x);
                deleteY(sv,n,x);
                printf("DANH SACH SAU KHI XOA:\n");
                XuatMangSV(sv,n);
                break;
            case 6:
                break;
            default:
                printf("Ban chon sai. Moi ban chon lai MENU!\n");
                break;
        }
    }while(chon!=6);
    return 0;
}
