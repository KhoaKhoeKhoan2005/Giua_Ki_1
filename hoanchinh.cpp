#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define max 20
int a[max],b[max],tong[max],hieu[max],tich[max*2],so_mu_a,so_mu_b,max_a_b;
float fa[max], fb[max], thuong[max], sodu[max];
void nhapmang(char *dt1, char *dt2) {
    printf("Nhap da thuc thu 1:\n");
    fgets(dt1, 100, stdin);
    dt1[strcspn(dt1, "\n")] = 0; 	//Loai bo ky tu '\n' o cuoi chuoi
    printf("Nhap da thuc thu 2:\n");
    fgets(dt2, 100, stdin);		//Loai bo ky tu '\n' o cuoi chuoi
    dt2[strcspn(dt2, "\n")] = 0;
}
void nhapvarutgondt(char* dt, int c[]) {
    for (int i = 0; i < max; i++) 
	{	c[i] = 0;	}		//Dat he so ban dau bang 0

    int len = strlen(dt);		//Lay do dai cua chuoi da thuc
    int i = 0, sign = 1, stack[100], top = -1;
    stack[++top] = 1;		//Khoi tao dau hieu ban dau la duong
		
		//Duyet qua tung ki tu trong chuoi
    while (i < len) 		//Bo qua khoang trang
	{
        if (dt[i] == ' ') 
		{    i++; 
            continue; 	}	// Bo qua lenh lap hien tai
        	//Xu ly dau cong (them he so duong)
        if (dt[i] == '+') 
		{    sign = stack[top];
            i++;    }
        	//Xu ly dau tru (them he so am)
		else if (dt[i] == '-') 
		{   sign = -stack[top];		//Dau hien tai la am
            i++;    }
        	//Xu ly dau mo ngoac
		else if (dt[i] == '(') 
		{    stack[++top] = sign;	//Day dau hien tai vao stack
            i++;    }
        	//Xu ly dau dong ngoac
		else if (dt[i] == ')') 
		{    top--;		//Pop dau hien tai ra khoi stack khi gap dau ')'
            i++;    } 
		else 
		{		//Xu ly mot hang tu trong da thuc
            int heso = 0, bac = 0;		//Khoi tao he so va bac
            char temp[20] = {0};		//Mang tam thoi de luu mot hang tu
            int j = 0;
            	//Doc ki tu trong chuoi cho den khi gap dau +,-,(,)
            while (i < len && dt[i] != '+' && dt[i] != '-' && dt[i] != '(' && dt[i] != ')') 
			{    temp[j++] = dt[i++];    }
            temp[j] = '\0';
            	//Kiem tra xem hang tu co chua x khong( de xac dinh la hang tu chua bien)
            char* vitrix = strchr(temp, 'x');
            if (vitrix) 
			{
					//Neu x co trong hang tu
            		//Neu x o dau chuoi thi he so la 1
                if (vitrix == temp) 
				{    heso = 1;    } 
				else 
				{		//Neu khong, lay he so tu truoc x
                    temp[vitrix - temp] = '\0';
                    heso = atoi(temp);		//Chuyen chuoi thanh so nguyen
                }
                	//Neu co dau ^ sau x thi lay bac
                if (*(vitrix + 1) == '^') 
				{    bac = atoi(vitrix + 2);	}	//Lay bac sau ^    
				else 
				{    bac = 1;	}	//Neu khong co ^ bac la 1
            } 
			else 
			{	heso = atoi(temp);	}	//Neu khong co x thi day la so hang 
            	//Neu bac nho hon max,luu he so vao mang
            if (bac < max) 
			{    c[bac] += heso * sign;		}	//cong them he so vao vi tri tuong ung trong mang    
        }
    }
}
int leng(int mang[]) 	{
    for (int i = max - 1; i >= 0; i--) 	// Duyet tu bac cao nhat
	{    if (mang[i] != 0) return i;	}	// Tra ve bac dau tien khac 0
    return 0;		// Neu tat ca bang 0, tra ve 0
}
int fleng(float mang[]) {	//ham leng cho mang float
    for (int i = max - 1; i >= 0; i--) 
	{    if (mang[i] != 0) return i;    }
    return 0;
}
void congmang(int a[], int b[])	{	//phep cong mang
    for(int i=0;i<=max_a_b;i++)
	{    tong[i]=a[i]+b[i];    }
}
void trumang(int a[], int b[])	{	//phep tru mang
    for(int i=0;i<=max_a_b;i++)
	{    hieu[i]=a[i]-b[i];    }
}
void nhanmang(int a[], int b[])	{	//phep nhan mang
    for(int i=0;i<=so_mu_a;i++)
	{
        for(int j=0;j<=so_mu_b;j++)	//thuc hien nhan tung phan tu cua mang roi cong lai
		{    tich[i+j]+=a[i]*b[j];    }
    }
}
void chiamang(int a[], int b[])	{
    for (int i=0;i<=so_mu_a;i++) fa[i]=a[i]*1.0;	//tao 2 mang float
    for (int i=0;i<=so_mu_b;i++) fb[i]=b[i]*1.0;
    float temp[20];	//ham temp de luu tich cua thuong va fb
    for(int i=0;i<=so_mu_a;i++) sodu[i]=fa[i];
    while(fleng(sodu)>=so_mu_b)
	{
        thuong[fleng(sodu)-so_mu_b]=sodu[fleng(sodu)]/fb[so_mu_b]; //chia cho bac cao nhat
        for(int i=0;i<=20;i++) temp[i]=0; //reset lai temp de khoi cong don
        for(int i=0;i<=fleng(thuong);i++)
		{
            for(int j=0;j<=so_mu_b;j++)
			{    temp[i+j]+=thuong[i]*fb[j];    } //temp bang tich cua thuong va fb
        }
        for(int i=0;i<=so_mu_a;i++)
		{    sodu[i]=fa[i]-temp[i];    } //tinh lai so du
	if(so_mu_b==0) break;
    }
}
void xuatdathuc(int a[]) 	{
    int first = 1;		// De kiem tra phan tu dau tien
    for (int i = max - 1; i >= 0; i--) 
	{		// Duyet tu bac cao nhat
        if (a[i] != 0) 
		{
            if (!first && a[i] > 0) printf(" + ");		// In dau cong neu khong phai phan tu dau
            if (a[i] < 0) printf(" - ");		 // In dau tru neu he so am
            if (abs(a[i]) != 1 || i == 0) printf("%d", abs(a[i]));		// In he so tru 1 neu can
            if (i > 0) printf("x");		// In bien x
            if (i > 1) printf("^%d", i);		// In bac neu lon hon 1
            first = 0;
        }
    }
    if (first) printf("0");		// Neu da thuc rong, in 0
    printf("\n");
}
void xuatdathuc_float(float a[]) 	{	// Ham xuat da thuc cho mang float
    int first = 1;
    for (int i = max - 1; i >= 0; i--) 
	{
        if (a[i] != 0) {
            if (!first && a[i] > 0) printf(" + ");
            if (a[i] < 0) printf(" - ");
            if (fabs(a[i]) != 1 || i == 0) printf("%.2f", fabs(a[i]));
            if (i > 0) printf("x");
            if (i > 1) printf("^%d", i);
            first = 0;
        }
    }
    if (first) printf("0");
    printf("\n");
}
int main()	{
    char dt1[100];
    char dt2[100];
    nhapmang(dt1, dt2);
    nhapvarutgondt(dt1, a);
    nhapvarutgondt(dt2, b);
    so_mu_a=leng(a); so_mu_b=leng(b);
      so_mu_a = leng(a);		// Bac cao nhat cua da thuc 1
    so_mu_b = leng(b);			// Bac cao nhat cua da thuc 2
    max_a_b = (so_mu_a >= so_mu_b) ? so_mu_a : so_mu_b;		// Xac dinh bac cao nhat cua 2 da thuc
	congmang(a, b);		// Cong hai da thuc
    printf("\nTong da thuc: ");
    xuatdathuc(tong);		// Xuat ket qua tong
    trumang(a, b);		// Tru hai da thuc
    printf("\nHieu da thuc: ");
    xuatdathuc(hieu);		// Xuat ket qua hieu
    nhanmang(a, b);		// Nhan hai da thuc
    printf("\nTich da thuc: ");
    xuatdathuc(tich);		// Xuat ket qua tich
    if(so_mu_b==0 && b[0]==0)
	{	printf("\nKhong the chia da thuc");		}
    else
	{
    chiamang(a,b);		// Chia hai da thuc
    printf("\nThuong da thuc: ");		// Xuat ket qua thuong
    xuatdathuc_float(thuong);
     printf("\nSo du da thuc: ");
    xuatdathuc_float(sodu);				// Xuat phan du cua thuong
    }
    return 0;		// Xuat ket qua tich
}
