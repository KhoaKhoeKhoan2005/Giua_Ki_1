#include<stdio.h>
#include<math.h>
#include <stdlib.h>
int a[20],b[20],c[20],t[20],x[40],h[20],d[20],m,n,max;
int len(int mang[]);
void nhap(int mang[], int l, char ten);
void xuat(int mang[], int l, char ten);
void cong(int a[], int b[]);
void tru(int a[], int b[]);
void nhan(int a[], int b[]);
void chia(int a[], int b[]);
void main(){
    printf("Gia su ta da rut gon xong bieu thuc, nhap cac he so vao a[] va b[]\nvoi bac thap dung truoc, bac cao dung sau.\n");
    printf("VD 2x^2-2x+1 va x^3-2, thi a[] = 1 -2 2 va b[] = -2 0 0 3\n");
    printf("bac cua bieu thuc 1 va bieu thuc 2: ");
    scanf("%d %d",&m,&n);
    if(m>=n) max=m;
    else max=n;
    nhap(a,m,'a');
    nhap(b,n,'b');
    xuat(a,m,'a');
    xuat(b,n,'b');
    cong(a,b);
    tru(a,b);
    nhan(a,b);
    chia(a,b);
}

int len(int mang[20]){
    int length=0;
    for(int i=0;i<=19;i++){
        if(mang[i]!=0) length=i;
    }
    return length;
}

void nhap(int mang[],int l,char ten){
    for(int i=0;i<=l;i++){
        printf("%c[%d]= ",ten,i);
        scanf("%d",&mang[i]);
    }
}

void xuat(int mang[],int l,char ten){
    printf("\nmang %c: ",ten);
    for(int i=0;i<=l;i++)
        printf("%d ",mang[i]);
}

void cong(int a[], int b[]){
    for(int i=0;i<=max;i++){
        c[i]=a[i]+b[i];
    }
    xuat(c,max,'c');
}

void tru(int a[], int b[]){
    for(int i=0;i<=max;i++){
        t[i]=a[i]-b[i];
    }
    xuat(t,max,'t');
}

void nhan(int a[], int b[]){
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            x[i+j]+=a[i]*b[j];
        }
    }
    xuat(x,m+n,'x');
}

void chia(int a[], int b[]){
    int temp[20];
    for(int i=0;i<=m;i++) d[i]=a[i];
    while(len(d)>=n){
        h[len(d)-n]=d[len(d)]/b[n];
        for(int i=0;i<=20;i++) temp[i]=0;
        for(int i=0;i<=len(h);i++){
            for(int j=0;j<=n;j++){
                temp[i+j]+=h[i]*b[j];
            }
        }
        for(int i=0;i<=m;i++){
        d[i]=a[i]-temp[i];
        }
    }
    xuat(h,len(h),'h');
    xuat(d,len(d),'d');
}