#include<stdio.h>
#include<string.h>
typedef struct diemtotnghiep {
    int mssv;
    char hoten[30];
    int diem[5];
} diem;
int main() {
    int choice;
    diem d[100];
    do {
        printf("Menu\n1.bo sung sinh vien\n2.danh sach bao ve thanh cong\n3.sap xep\n4.thoat\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1 :
            
            printf("nhap so sinh vien: ");
            int n;
            scanf("%d", &n);
            getchar();
            for( int i=0;i<n;i++) {
                printf("mssv cua sinh vien %d: ", i+1);
                scanf("%d", &d[i].mssv);
            }
            for( int i=0;i<n;i++) {
                printf("ho va ten sv thu %d: ", i+1);
                fflush(stdin);
                gets(d[i].hoten);
            }

            break;
        }
    } while (choice != 0);
    return 0;
}