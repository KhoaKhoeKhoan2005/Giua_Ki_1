#include <stdio.h>
#include <stdlib.h> //Dung cho atoi
#include <string.h>
#include <ctype.h> //Dung cho isdigit
#define max 10
void nhapmang(char *dt1, char *dt2) {
    printf("Nhap da thuc thu 1:\n");
    fgets(dt1, 100, stdin);
    dt1[strcspn(dt1, "\n")] = 0;  //Loai bo ky tu '\n' o cuoi chuoi
    printf("Nhap da thuc thu 2:\n");
    fgets(dt2, 100, stdin);
    dt2[strcspn(dt2, "\n")] = 0;  //Loai bo ky tu '\n' o cuoi chuoi
}
void nhapvarutgondt(char* dt, int a[]) {
    for (int i = 0; i < max; i++) {
        a[i] = 0; //Dat he so ban dau bang 0
    }

    int len = strlen(dt); //Lay do dai cua chuoi da thuc
    int i = 0, sign = 1, stack[100], top = -1;
    stack[++top] = 1; //Khoi tao dau hieu ban dau la duong

	//Duyet qua tung ki tu trong chuoi
    while (i < len) {//Bo qua khoang trang
        if (dt[i] == ' ') {
            i++; 
            continue;
        }
		//Xu ly dau cong (them he so duong)
        if (dt[i] == '+') {
            sign = stack[top];
            i++;
        }
        //Xu ly dau tru (them he so am)
		 else if (dt[i] == '-') {
            sign = -stack[top];//Dau hien tai la am
            i++;
        }
		//Xu ly dau mo ngoac
		 else if (dt[i] == '(') {
            stack[++top] = sign; //Day dau hien tai vao stack
            i++;
        }
        //Xu ly dau dong ngoac
		 else if (dt[i] == ')') {
            top--;//Pop dau hien tai ra khoi stack khi gap dau ')'
            i++;
        } else {
        	//Xu ly mot hang tu trong da thuc
            int heso = 0, bac = 0;//Khoi tao he so va bac
            char temp[20] = {0};//Mang tam thoi de luu mot hang tu
            int j = 0;
            //Doc ki tu trong chuoi cho den khi gap dau +,-,(,)
            while (i < len && dt[i] != '+' && dt[i] != '-' && dt[i] != '(' && dt[i] != ')') {
                temp[j++] = dt[i++];
            }
            temp[j] = '\0';
			//Kiem tra xem hang tu co chua x khong( de xac dinh la hang tu chua bien)
            char* vitrix = strchr(temp, 'x');
            if (vitrix) {
            	//Neu x co trong hang tu
            	//Neu x o dau chuoi thi he so la 1
                if (vitrix == temp) {
                    heso = 1;
                } else {
                	//Neu khong, lay he so tu truoc x
                    temp[vitrix - temp] = '\0';
                    heso = atoi(temp);//Chuyen chuoi thanh so nguyen
                }
				//Neu co dau ^ sau x thi lay bac
                if (*(vitrix + 1) == '^') {
                    bac = atoi(vitrix + 2);//Lay bac sau ^
                } else {
                    bac = 1;//Neu khong co ^ bac la 1
                }
            } else {//Neu khong co x thi day la so hang
                heso = atoi(temp);
            }
            //Neu bac nho hon max,luu he so vao mang
            if (bac < max) {
                a[bac] += heso * sign;//cong them he so vao vi tri tuong ung trong mang
            }
        }
    }
}

void xuathesodathuc(int a[]) {
    printf("Cac he so cua bieu thuc la:\n");
    for (int i = 0; i < max; i++) {
        printf("%d ", a[i]);//in ra tung he so cua da thuc
    }
    printf("\n");
}

int main() {
    int a[max];
    int b[max];
    char dt1[100];
    char dt2[100];
    nhapmang(dt1, dt2);
    nhapvarutgondt(dt1, a);
    xuathesodathuc(a);
    nhapvarutgondt(dt2, b);
    xuathesodathuc(b);
    return 0;
}
