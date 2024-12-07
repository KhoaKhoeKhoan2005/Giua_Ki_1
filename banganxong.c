#include <stdio.h>
#include <stdlib.h> //Dung cho atoi
#include <string.h>
#include <ctype.h> //Dung cho isdigit
#define max 20
int a[max],b[max],tong[max],hieu[max],tich[max*2],thuong[max],sodu[max],so_mu_a,so_mu_b,max_a_b;

void nhapmang(char *dt1, char *dt2) {
    printf("Nhap da thuc thu 1:\n");
    fgets(dt1, 100, stdin);
    dt1[strcspn(dt1, "\n")] = 0;  //Loai bo ky tu '\n' o cuoi chuoi
    printf("Nhap da thuc thu 2:\n");
    fgets(dt2, 100, stdin);
    dt2[strcspn(dt2, "\n")] = 0;  //Loai bo ky tu '\n' o cuoi chuoi
}
void nhapvarutgondt(char* dt, int c[]) {
    for (int i = 0; i < max; i++) {
        c[i] = 0; //Dat he so ban dau bang 0
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
        else if (dt[i] == '+') {
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
                c[bac] += heso * sign;//cong them he so vao vi tri tuong ung trong mang
            }
        }
    }
}
void xuathesodathuc(int a[]) {
    printf("Cac he so cua bieu thuc la:\n");
    for (int i = 0; i < max; i++) {
        printf("%d ", a[i]); // In ra tung he so cua da thuc
    }
    printf("\n");
}

int leng(int mang[]) {
    for (int i = max - 1; i >= 0; i--) {      // Duyet tu bac cao nhat
        if (mang[i] != 0) return i;           // Tra ve bac dau tien khac 0
    }
    return 0;                                 // Neu tat ca bang 0, tra ve 0
}
void congmang(int a[], int b[]){
    for(int i=0;i<=max_a_b;i++){
        tong[i]=a[i]+b[i];
    }
}
void trumang(int a[], int b[]){
    for(int i=0;i<=max_a_b;i++){
        hieu[i]=a[i]-b[i];
    }
}
void nhanmang(int a[], int b[]){
    for(int i=0;i<=so_mu_a;i++){
        for(int j=0;j<=so_mu_b;j++){
            tich[i+j]+=a[i]*b[j];
        }
    }
}

void chiamang(int a[], int b[]) {
    int temp[20];
    for (int i = 0; i <= so_mu_a; i++) sodu[i] = a[i];
      // Chia da thuc
    for (int i = so_mu_a; i >= so_mu_b; i--) {
        if (b[so_mu_b] != 0) {
            thuong[i - so_mu_b] = sodu[i] / b[so_mu_b];
            for (int j = 0; j <= so_mu_b; j++) {
                temp[j] = thuong[i - so_mu_b] * b[j];
            }
            for (int j = i; j >= i - so_mu_b; j--) {
                sodu[j] -= temp[i - j];
            }
        }
    }
}

void xuatdathuc(int a[]) {
    int first = 1;                           // De kiem tra phan tu dau tien
    for (int i = max - 1; i >= 0; i--) {     // Duyet tu bac cao nhat
        if (a[i] != 0) {
            if (!first && a[i] > 0) printf(" + "); // In dau cong neu khong phai phan tu dau
            if (a[i] < 0) printf(" - ");           // In dau tru neu he so am
            if (abs(a[i]) != 1 || i == 0) printf("%d", abs(a[i])); // In he so tru 1 neu can
            if (i > 0) printf("x");                // In bien x
            if (i > 1) printf("^%d", i);           // In bac neu lon hon 1
            first = 0;
        }
    }
    if (first) printf("0");                   // Neu da thuc rong, in 0
    printf("\n");
}
int main(){
    char dt1[100];
    char dt2[100];
    nhapmang(dt1, dt2);
    nhapvarutgondt(dt1, a);
    xuathesodathuc(a);
    nhapvarutgondt(dt2, b);
    xuathesodathuc(b);
    so_mu_a=leng(a); so_mu_b=leng(b);
      so_mu_a = leng(a);  // Bac cao nhat cua da thuc 1
    so_mu_b = leng(b);  // Bac cao nhat cua da thuc 2
    max_a_b = (so_mu_a >= so_mu_b) ? so_mu_a : so_mu_b;  // Xac dinh bac cao nhat cua 2 da thuc
    // Cong hai da thuc
    congmang(a, b);
    printf("\nTong da thuc: ");
    xuatdathuc(tong);  // Xuat ket qua tong
    // Tru hai da thuc
    trumang(a, b);
    printf("\nHieu da thuc: ");
    xuatdathuc(hieu);  // Xuat ket qua hieu
    // Nhan hai da thuc
    nhanmang(a, b);
    printf("\nTich da thuc: ");
    xuatdathuc(tich);  // Xuat ket qua tich
    chiamang(a,b);
    printf("\nThuong da thuc: ");
    xuatdathuc(thuong);
     printf("\nSo du da thuc: ");
    xuatdathuc(sodu);
    return 0;  // Ket thuc chuong trinh
}
