#include<stdio.h>
#include<string.h>
#include<math.h>

typedef struct ketquathidau  {
    int ID ;
    char nation[3];
    char name[30];
    double R[3];
    double FR;

}ketqua;
int main()
{
    int choice;
    ketqua kq[100];
    do {
        printf("Menu\n1.Nhap thong tin truoc thi dau\n2.In thông tin\n3.thi đấu\n4.tìm kiếm\n5.in kết quả\n6.kết thúc\n moi ban chon chuc nang");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
            printf("Nhap so van dong vien: ");
            	int n;
            	scanf("%d", &n);
                if (n <0 || n >20)
                { printf("Nhap lai");}
	            else {
	
    for (int i=0;i<n;i++){
        printf("nhap quoc gia nguoi %d: ",i+1 );
        scanf("%s", kq[i].nation);
    }
        getchar();
       
         for (int i=0;i<n;i++){
        printf("ho va ten nguoi %d: ", i+1);
       fflush(stdin);
        gets(kq[i].name);
    }}
            break;
            case 2:
            printf("   * Danh sach van dong vien *   \n");

        printf("ID\tNATION\tNAME\tN1\tN2\tN3\tFR\n");
       for (int i=0; i<n; i++) {
		printf("%d\t%c\t  -%s  \t\n", i+1,kq[i].nation,kq[i].name);
                
            }
            break;
            case 3:
            printf("nhap ket qua:");
        
            for(int i=0;i<n;i++){
             printf("ket qua thi dau lan %d:", i+1);
             }
            
            break;
            case 4:
            printf("chon: \n");
            int c;
            do {
                printf("1.theo quoc gia\n2.theo ten\n");
                scanf("%d", &c);
                switch (c){
                    case 1 :
                    printf("Nhap can tim: ");
                    char a[3];
                    scanf("%s", a);
                    for (int i=0;i<n;i++) {
                    char coppy[3];
                    strcpy(coppy,kq[i].nation);
                    if(strcmp(strdup(a),strdup(coppy))==0) { printf("%d\t%s\t%s\t\t\t\t", i+1,kq[i].nation,kq[i].name);}}
                    break;
                    case 2:
                    break;
                    default : printf("Nhap lai:\n");
                }} while(c != 0);

            break;
            case 5:
            for(int i=0;i<n-1;i++) {
                for(int j=i;j<n;j++) {
                    if(kq[j].FR > kq[i].FR ) {
                        int temp = kq[i].FR;
                        kq[i].FR = kq[j].FR;
                        kq[j].FR = temp;
                    }
                }
            
            }
            for (int i=0;i<n;i++) {
                printf("%d\t%s\t%-30s\n", i+1,kq[i].nation,kq[i].name);
            }
            break;
            case 6:
            printf("thoat chuong trinh");
            return 0;
            defaut : printf("moi ban nhap lai chuc nang: ");
    
        
    } } while (choice != 0);
    return 0;
}