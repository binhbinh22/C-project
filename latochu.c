#include<stdio.h>
#include<string.h>
typedef struct latochu {
char Name[25];
int Old;
int Score[5];
} Game;
int main() {
    int choice;
    Game ga[100];
    do {
        printf("Menu\n1.khoi dong\n2.choi doan\n3.tong hop\n4.thoat\n ");
        scanf("%d", &choice);
        switch(choice) {
        case 1 :
        printf("Nhap xau tu ban phim: ");
        char S[40];
        scanf("%s", S);
        if( strlen(S) < 20 || strlen(S) > 40) {
            printf("yeu cau nhap lai: ");
        }
        else {
        printf("nhap so nguoi choi: ");
        int n;
        scanf("%d", &n);
        getchar();
        for(int i =0;i<n;i++) {
            printf("ho ten nguoi %d: ", i+1);
            fflush(stdin);
            gets(ga[i].Name);}
           for(int i=0;i<n;i++) {
            printf("tuoi nguoi %d: ", i+1);
         scanf("%d", &ga[i].Old);}
        printf("ho va ten  \t tuoi\n");
        for(int i=0;i<n;i++)
        {
            printf("%s\t   %d\n", ga[i].Name,ga[i].Old);
        }}
        break;
        case 2:
        printf("Bat dau choi, hien thi: ***************************\n");
        char s;
        char xau[40];
        
        for(int i=0;i<2;i++) {
            printf("Moi người thứ %d nhap: \n", i+1);
            scanf("%c", &s);
            if (s == 'A') { printf("**a***a*******a*a**a*****a*\n");}
            if( s== 'N') {printf("**an**a****n**a*a**a****na*\n");}
            if( s== 'K') { printf("**an**a****n**a*a**a****na*\n");}
            if(s =='n') {printf("**an**a****n**a*a**a****na*\n");}}
            for(int i=0;i<2;i++) {
            printf("nhap xau: \n");
            scanf("%s", xau);
            if(xau == S) {printf("đúng\n");}
            else { printf("sai\n");}
        }
        break;
        default : 
        printf("Nhap lai: ");}}
     while (choice != 0);
    return 0;
}