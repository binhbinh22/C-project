#include<stdio.h>
#include<string.h>
typedef struct nhahang{
    char name[30];
    char description[500];
    float rating;
    char address[100];
}nh;
int main(){
    int x,n=0,bonus;
    nh st[100];
    TIEP:
    printf("Chuong trinh kiem tra nha hang:\n");
    printf("1. Nhap thong tin nha hang\n");
    printf("2. In thong tin cac nha hang\n");
    printf("3. Tim kiem theo ten\n");
    printf("4. Tim kiem theo mo ta\n");
    printf("5. Sap xep\n");
    printf("6. Thoat\n");
    printf("Press to choose(1 to 6) : ");
    scanf("%d",&x);
    switch (x)
    {
    case 1:{
        if(n==0){
            tiep1:
            printf("Nhap so luong nha hang:");
            scanf("%d",&n);
            if(n<=0)goto tiep1;
            for(int i=0;i<n;i++){
                printf("Nhap ten nha hang %d: ",i+1);
      
                gets(st[i].name);
                while (getchar () != '\n');
                printf("Nhap cac mon an cua nha hang: ");
                fflush(stdin);
                gets(st[i].description);
                printf("Nhap rating: ");
                scanf("%f",&st[i].rating);
                printf("Nhap dia chi: ");
                fflush(stdin);
                gets(st[i].address);   
                while(getchar() != '\n');
            }
        }else{
            tiep2:
            printf("Nhap so luong quan can them :");
            scanf("%d",&bonus);
            if(bonus<=0)goto tiep2;
            for(int i=n;i<n+bonus;i++){
                printf("Nhap ten nha hang %d: ",i+1);
                fflush(stdin);
                gets(st[i].name);
                printf("Nhap cac mon an cua nha hang: ");
                fflush(stdin);
                gets(st[i].description);
                printf("Nhap rating: ");
                scanf("%f",&st[i].rating);
                printf("Nhap dia chi: ");
                fflush(stdin);
                gets(st[i].address);   
            }
            n+=bonus;
        }
        goto TIEP;
        break;
    }
    case 2:{
        for(int i=0;i<n;i++){
            printf("\nNha hang %d\n",i+1);
            printf("Name: %s\n",st[i].name);
            printf("Description: %s\n",st[i].description);
            printf("Rating: %.2f\n",st[i].rating);
            printf("Address: %s\n",st[i].address);
        }
        goto TIEP;
        break;
    }
    case 3:{
        char a[30];
        printf("Nhap ten nha hang can tim kiem:");
        
        gets(a);
        for(int i=0;i<n;i++){
            char copy[30];
            strcpy(copy,st[i].name);
            if(strcmp(strdup(a),strdup(copy))==0){
                printf("\nNha hang %d\n",i+1);
                printf("Name: %s\n",st[i].name);
                printf("Description: %s\n",st[i].description);
                printf("Rating: %.2f\n",st[i].rating);
                printf("Address: %s\n",st[i].address);
            }
        }
        goto TIEP;
        break;
    }
    case 4:{
        char b[100];
        printf("Nhap ten mon an: ");
        fflush(stdin);
        gets(b);
        for(int i=0;i<n;i++){
            char copy[100];
            strcpy(copy,st[i].description);
            char *saochep=strstr(strdup(copy),strdup(b));
            if(saochep!=NULL){
                printf("\nNha hang %d\n",i+1);
                printf("Name: %s\n",st[i].name);
                printf("Description: %s\n",st[i].description);
                printf("Rating: %.2f\n",st[i].rating);
                printf("Address: %s\n",st[i].address);
            }
        }
        goto TIEP;
        break;
    }
    case 5:{
        for(int i=0;i<n-1;i++){
           for(int j=i;j<n;j++){
               if(st[j].rating>st[i].rating){
                   nh stcpy = st[i];
                   st[i]=st[j];
                   st[j]=stcpy;
               }
           }
        }
        for(int i=0;i<n;i++){
            printf("\nNha hang %d\n",i+1);
            printf("Name: %s\n",st[i].name);
            printf("Description: %s\n",st[i].description);
            printf("Rating: %.2f\n",st[i].rating);
            printf("Address: %s\n",st[i].address);
        }
        goto TIEP;
        break;
    }
    case 6:{
        return 0;
        break;
    }
}
}