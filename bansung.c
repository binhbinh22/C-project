#include<stdio.h>
#include<string.h>
typedef struct ketquathidau {
    char hoten[30];
    int diem[5];
}kqua ;
void swap(char *a, char *b) {
	char t = *a;
	*a = *b;
	*b = t;
}
int main() {
    int choice;
    kqua kq[100];
    do {
        printf("Menu\n1.Dang ky van dang vien\n2.thi dau\n3.xep hang\n4.sieu xa thu\n5.thoat\n mời bạn nhập");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
            	printf("Nhap so van dong vien: ");
            	int n;
            	scanf("%d", &n);
	            getchar();
	for (int num=0; num<n; num++) {
		printf("Van dong vien %d: ", num+1);
		fflush(stdin);
		gets(kq[num].hoten);
	}
	printf("   * Danh sach van dong vien *   \n");
	for (int num=0; num<n; num++) {
		printf("%d. %-30s\n", num+1, kq[num].hoten);
                
            }
            break;
            case 2:
	for (int i=0; i<5; i++) {
		for (int j=0; j<n; j++) {
			printf("Diem cua van dong vien %d o lan ban thu %d: ", j+1, i+1);
			scanf("%d", &kq[j].diem[i]);
		}
	}
	char m[] = "Ho ten";
	printf("%-30s\t1\t2\t3\t4\t5\n", m);
	for (int j=0; j<n; j++) {
		printf("%-30s\t%d\t%d\t%d\t%d\t%d\n", kq[j].hoten, kq[j].diem[0], kq[j].diem[1], kq[j].diem[2], kq[j].diem[3], kq[j].diem[4]);
	}
            break;
            case 3:
            printf("kết quả\n");
            int sum[11];
	int temp, max;
	for ( int i=0; i<n; i++) {
		sum[i] = 0;
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<5; j++) {
			sum[i] += kq[i].diem[j];
		}
	}
	for (int i=0; i<n-1; i++) {
		max = i;
		for (int j=i+1; j<n; j++) {
			if (sum[j] > sum[max]) max = j;
		}
		swap(&kq[i], &kq[max]);
	}
	
	char prize[3][7] = {"Gold", "Silver", "Bronze"};
	for (int i=0; i<3; i++) {
		printf("%-30s\t%-6s\t%d\n", kq[i].hoten, prize+i, sum[i]);
	}
            break;
            case 4:
           printf("sieu xạ thủ\n");
	int d = 0;
	for ( int i=0; i<n; i++) {
		for (int j=0; j<3; j++) {
			if (kq[i].diem[j]==10 && kq[i].diem[j+1]==10 && kq[i].diem[j+2]==10) {
				printf("%s\n", kq[i].hoten);
				d++;
				break;
			}
		}
	}
	if (d==0) printf("Khong co sieu xa thu\n");
            break;
            case 5:
            printf("thoat ");
            return 0;
            default : printf("nhap lai");
        }
    } while(choice != 0);
    return 0;
}
