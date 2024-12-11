#include <stdio.h>	//Su dung cho cac ham nhap xuat trong C, neu khong co thu vien nay se khong the dung scanf, printf
#include <stdlib.h> //dung cho  atoi (chuyen doi chuoi thanh so nguyen)
#include <string.h> // dung cho cac thao tac trong chuoi
#include <math.h> //dung cho cac ham toan hoc fabs abs
#define max 20
int a[max],b[max],tong[max],hieu[max],tich[max*2],so_mu_a,so_mu_b,max_a_b;
float fa[max], fb[max], thuong[max], sodu[max];
void nhapmang(char *dt1, char *dt2) {
    printf("Nhap da thuc thu 1:\n");
    fgets(dt1, 100, stdin);             // Doc du lieu tu ban phim va luu vao mang dt1
    dt1[strcspn(dt1, "\n")] = 0; 	//Loai bo ky tu '\n' o cuoi chuoi
    printf("Nhap da thuc thu 2:\n");
    fgets(dt2, 100, stdin);		// Doc du lieu tu ban phim va luu vao mang dt2
    dt2[strcspn(dt2, "\n")] = 0;	//Loai bo ky tu '\n' o cuoi chuoi
}
void nhapvarutgondt(char* dt, int c[]) {
    for (int i = 0; i < max; i++) 
	{	c[i] = 0;	}       //khoi tao he so da thuc la 0
	
    int len = strlen(dt);		//Lay do dai cua chuoi da thuc khong bao gom ky tu '\0'
    int i = 0, sign = 1, stack[100], top = -1;
//sign luu tru dau hien tai (duong hoac am), vd nhap -5 may se luu là -5.
//stack[] là mang giup xu li dau cua các hang tu trong da thuc khi có dau ngoac
//top=-1 nghia la ngan xep hien tai dang rong, de luu tru chi so cua phan tu 
    stack[++top] = 1;		
//Khoi tao dau ban dau la duong, ++top tang top tu -1 len 0,sau do stack[0] = 1, se gan gtri 1 vao ptu dau tien cua mang stack	
	//Duyet qua tung ki tu trong chuoi
    while (i < len) 	
	{
        if (dt[i] == ' ') 
		{    i++; 
            continue; 	}	// Bo qua lenh lap hien tai
        if (dt[i] == '+') 	//Xu ly dau cong (them he so duong)
		{    sign = stack[top]; //gan gia tri dau vao stack, tang i
            i++;    }
        	//Xu ly dau tru (them he so am)
		else if (dt[i] == '-') 
		{   sign = -stack[top];		//Dau hien tai la am, gan gia tri dau am vao stack, tang i
            i++;    }				
        	//Xu ly dau mo ngoac
		else if (dt[i] == '(') 
		{    stack[++top] = sign;	//luu dau cua bieu thuc trong ngoac vao stack
            i++;    }
        	//Xu ly dau dong ngoac
		else if (dt[i] == ')') 
		{    top--;	//pop dau hien tai ra khoi stack khi gap dau ')', giam gia tri top
            i++;    } 
		else 
		{		//Xu ly mot hang tu trong da thuc
            int heso = 0, bac = 0;		//Khoi tao he so va bac
            char temp[20] = {0};		//Chuoi tam thoi de luu mot hang tu duoi dang chuoi ky tu
            int j = 0;
            	//Doc ki tu trong chuoi cho den khi gap dau +,-,(,)
            while (i < len && dt[i] != '+' && dt[i] != '-' && dt[i] != '(' && dt[i] != ')')
			{    temp[j++] = dt[i++]; // Doc tung ki tu trong da thuc
			   }
		temp[j] = '\0';//gan ki tu ket thuc chuoi '\0' vào vi tri j trong mang temp de dam bao chuoi hop le
//Kiem tra xem hang tu co chua x khong (de xac dinh la hang tu chua bien), neu co x thi vitrix se tro den vi tri cua x
            char* vitrix = strchr(temp, 'x');// Day la mot con tro kieu char,de luu tru vitri cua 'x' trong chuoi temp
            if (vitrix) // neu co x, tuc la da thuc co bac cao hon bac 0
			{ 
		//Neu x co trong hang tu
                if (vitrix == temp) 	//Neu x o dau chuoi thi he so la 1
				{    heso = 1;    } 
				else 
				{		//Neu khong, lay he so tu truoc x
                    temp[vitrix - temp] = '\0';//khoang cach vitri x va con tro temp(dau chuoi)
                    heso = atoi(temp);		//Chuyen chuoi thanh so nguyen va gan do heso
                }
		//Neu co dau ^ sau x thi lay bac
                if (*(vitrix + 1) == '^') 
				{    bac = atoi(vitrix + 2);	}	//Lay bac sau ^, chuyen chuoi sau ^ thanh so nguyen   
				else 
				{    bac = 1;	}	//Neu khong co ^ bac la 1
            } 
			else 
			{	heso = atoi(temp); 	}	//Neu khong co x thi day la hang so, khong co bien, chuyen thanh so nguyen
    //Neu bac nho hon max,luu he so vao mang
            if (bac < max) 
			{    c[bac] += heso * sign;		}
//Luu he so vao mang c[] tai vi tri bac, neu co dau (+ hoac -) thi heso se duoc nhan voi sign de dam bao dung dau
//vidu: hang tu 2x^3, chung ta luu he so 2 vao c[3] (vi bac la 3).
        }
    }
}
//Tinh bac cua da thuc
int leng(int mang[]) 	{//su dung de tinh bac cao nhat cua mot da thuc co he so kieu nguyen.
    for (int i = max - 1; i >= 0; i--) 	// Duyet tu bac cao nhat
	{    if (mang[i] != 0) return i;	}//Khi gap mot ptu co gtri khac 0, ham se tra ve i, tuc la bac cao nhat cua da thuc.
    return 0;		// Neu tat ca bang 0, tra ve 0
}
int fleng(float mang[]) {//su dung de tinh bac cao nhat cua mot da thuc co he so kieu so thuc (float).
    for (int i = max - 1; i >= 0; i--) //Duyet tu bac cao nhat
	{    if (mang[i] != 0) return i;    }//Khi gap mot ptu co gtri khác 0, hàm se tra ve i, tuc la bac cao nhat cua da thuc.
    return 0;     // Neu tat ca bang 0, tra ve 0
}
void congmang(int a[], int b[])	{	//phep cong mang
    for(int i=0;i<=max_a_b;i++) //Bien max_a_b duoc xac dinh la bac cao nhat cua hai da thuc ma ta dang cong
	{    tong[i]=a[i]+b[i];    }//O moi vong lap, gtri cua i cua mang a[] va b[] duoc cong lai, luu vao mang tong[].
}
void trumang(int a[], int b[])	{	//phep tru mang
    for(int i=0;i<=max_a_b;i++)//Bien max_a_b duoc xac dinh la bac cao nhat cua hai da thuc ma ta dang tru
	{    hieu[i]=a[i]-b[i];    }//O moi vong lap, gtri cua i cua mang a[] va b[] duoc tru lai, luu vao mang hieu[].
}
void nhanmang(int a[], int b[])	{	//phep nhan mang
//Moi lan vong lap 1,2 chay, se lay duoc he so tai vitri i cua a, j cua b, sau do nhan chung lai: a[i] * b[j].
//Ket qua nay se duoc cong vao vi tri i + j trong tich[]. do khi nhan hai x^i va y^j, ket qua se co bac la i + j.
    for(int i=0;i<=so_mu_a;i++)
	{
for(int j=0;j<=so_mu_b;j++)	//thuc hien nhan tung phan tu cua mang roi cong lai
		{    tich[i+j]+=a[i]*b[j];    }
    }
}
void chiamang(int a[], int b[])	{
    for (int i=0;i<=so_mu_a;i++) fa[i]=a[i]*1.0; //chuyen he so cua 2 mang a[] va b[] sang so thuc va luu ru vao float
    for (int i=0;i<=so_mu_b;i++) fb[i]=b[i]*1.0;
    float temp[20];	// dung de luu kq trung gian cua phep nhan trong qua trinh chia
    for(int i=0;i<=so_mu_a;i++) sodu[i]=fa[i];//// Sao chep phan d ban dauu tu fa sang sodu
    while(fleng(sodu)>=so_mu_b)
    // fleng(sodu) tra ve bac cao nhat cua phan du
	{
        thuong[fleng(sodu)-so_mu_b]=sodu[fleng(sodu)]/fb[so_mu_b];
        //Chia heso so bac cao nhat trong phdu sodu[fleng(sodu)] cho he so cua bac cao nhat trong da thuc chia fb[so_mu_b].
	    for(int i=0;i<=20;i++) temp[i]=0; //mang temp[] se duoc reset ve gia tri 0 de luu tru tam thoi ket qua cua phep nhan trong buoc tiep theo.
        for(int i=0;i<=fleng(thuong);i++)
		{
            for(int j=0;j<=so_mu_b;j++)
			{    temp[i+j]+=thuong[i]*fb[j];    }//Moi phan tu cua thuong(tu mang thuong[]) duoc nhan voi tung he so cua da thuc chia (tu mang fb[]).
			//va luu vao mang temp
        }
	//cap nhat phan du moi
        for(int i=0;i<=so_mu_a;i++)
		{    sodu[i]=fa[i]-temp[i];    } //Phan du moi se là hieu giua phan du cu và tich vua tính duoc (temp[]).
	if(so_mu_b==0) break;
        if (fleng(sodu) < so_mu_b) break;// neu bac cao nhat cua phan du thap hon bac cao nhat cua da thuc 2
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
            if (abs(a[i]) != 1 || i == 0) printf("%d", abs(a[i]));// la hang so		
            if (i > 0) printf("x");		// bac bang 1 do bi chan o if duoi
            if (i > 1) printf("^%d", i);		// In bac neu lon hon 1
            first = 0;			//tra ve gia tri first bang 0
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
    so_mu_a = leng(a);		        // Bac cao nhat cua da thuc 1
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
    return 0;
}
