#include<stdio.h>
#include<math.h>
#include <stdlib.h>
int a[20],b[20],tong[20],hieu[20],tich[40],thuong[20],sodu[20],m,n,max;
int len(int mang[]);
void nhapmang(int mang[], int l,char ten);
void xuatmang(int mang[], int l,char ten);
void congmang(int a[], int b[]);
void trumang(int a[], int b[]);
void nhanmang(int a[], int b[]);
void chiamang(int a[], int b[]);

void main(){
    printf("Gia su ta da rut gon xong bieu thuc, nhap cac he so vao a[] va b[]\nvoi bac thap dung truoc, bac cao dung sau.\n");
    printf("VD 2x^2-2x+1 va x^3-2, thi a[] = 1 -2 2 va b[] = -2 0 0 3\n");
    printf("bac cua bieu thuc 1 va bieu thuc 2: ");
    scanf("%d %d",&m,&n);
    if(m>=n) max=m;
    else max=n;
    nhapmang(a,m,'a');
    nhapmang(b,n,'b');
    xuatmang(a,m,'a');
    xuatmang(b,n,'b');
    congmang(a,b);
    trumang(a,b);
    nhanmang(a,b);
    chiamang(a,b);
    printf("\ntong da thuc: "); for(int i=0;i<=len(tong);i++) printf("%d ",tong[i]);
    printf("\nhieu da thuc: "); for(int i=0;i<=len(hieu);i++) printf("%d ",hieu[i]);
    printf("\ntich da thuc: "); for(int i=0;i<=len(tich);i++) printf("%d ",tich[i]);
    printf("\nthuong da thuc: "); for(int i=0;i<=len(thuong);i++) printf("%d ",thuong[i]);
    printf("\nso du da thuc: "); for(int i=0;i<=len(sodu);i++) printf("%d ",sodu[i]);
}

int len(int mang[20]){
    int length=0;
    for(int i=0;i<=19;i++){
        if(mang[i]!=0) length=i;
    }
    return length;
}

void nhapmang(int mang[],int l,char ten){
    for(int i=0;i<=l;i++){
        printf("%c[%d]= ",ten,i);
        scanf("%d",&mang[i]);
    }
}

void xuatmang(int mang[],int l,char ten){
    printf("\nmang %c: ",ten);
    for(int i=0;i<=l;i++)
        printf("%d ",mang[i]);
}

void congmang(int a[], int b[]){
    for(int i=0;i<=max;i++){
        tong[i]=a[i]+b[i];
    }
}

void trumang(int a[], int b[]){
    for(int i=0;i<=max;i++){
        hieu[i]=a[i]-b[i];
    }
}

void nhanmang(int a[], int b[]){
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            tich[i+j]+=a[i]*b[j];
        }
    }
}

void chiamang(int a[], int b[]){
    int temp[20];
    for(int i=0;i<=m;i++) sodu[i]=a[i];
    while(len(sodu)>=n){
        thuong[len(sodu)-n]=sodu[len(sodu)]/b[n];
        for(int i=0;i<=20;i++) temp[i]=0;
        for(int i=0;i<=len(thuong);i++){
            for(int j=0;j<=n;j++){
                temp[i+j]+=thuong[i]*b[j];
            }
        }
        for(int i=0;i<=m;i++){
        sodu[i]=a[i]-temp[i];
        }
    }
}