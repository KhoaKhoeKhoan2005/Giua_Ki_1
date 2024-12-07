#include<stdio.h>
#include<math.h>
#include <stdlib.h>
int a[20],b[20],tong[20],hieu[20],tich[40],thuong[20],sodu[20],so_mu_a,so_mu_b,max_a_b;
int leng(int mang[]);
void nhapdtmang(int mang[], int l,char ten);
void xuatmang(int mang[], int l,char ten);
void congmang(int a[], int b[]);
void trumang(int a[], int b[]);
void nhanmang(int a[], int b[]);
void chiamang(int a[], int b[]);

void main(){
    printf("Gia su ta da rut gon xong bieu thuc, nhap cac he so vao a[] va b[]\nvoi bac thap dung truoc, bac cao dung sau.\n");
    printf("VD 2x^2-2x+1 va x^3-2, thi a[] = 1 -2 2 va b[] = -2 0 0 3\n");
    printf("bac cua bieu thuc 1 va bieu thuc 2: ");
    scanf("%d %d",&so_mu_a,&so_mu_b);
    if(so_mu_a>=so_mu_b) max_a_b=so_mu_a;
    else max_a_b=so_mu_b;
    nhapdtmang(a,so_mu_a,'a');
    nhapdtmang(b,so_mu_b,'b');
    xuatmang(a,so_mu_a,'a');
    xuatmang(b,so_mu_b,'b');
    congmang(a,b);
    trumang(a,b);
    nhanmang(a,b);
    chiamang(a,b);
    printf("\ntong da thuc: "); for(int i=0;i<=leng(tong);i++) printf("%d ",tong[i]);
    printf("\nhieu da thuc: "); for(int i=0;i<=leng(hieu);i++) printf("%d ",hieu[i]);
    printf("\ntich da thuc: "); for(int i=0;i<=leng(tich);i++) printf("%d ",tich[i]);
    printf("\nthuong da thuc: "); for(int i=0;i<=leng(thuong);i++) printf("%d ",thuong[i]);
    printf("\nso du da thuc: "); for(int i=0;i<=leng(sodu);i++) printf("%d ",sodu[i]);
}

int leng(int mang[20]){
    int length=0;
    for(int i=0;i<=19;i++){
        if(mang[i]!=0) length=i;
    }
    return length;
}

void nhapdtmang(int mang[],int l,char ten){
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

void chiamang(int a[], int b[]){
    int temp[20];
    for(int i=0;i<=so_mu_a;i++) sodu[i]=a[i];
    while(leng(sodu)>=so_mu_b){
        thuong[leng(sodu)-so_mu_b]=sodu[leng(sodu)]/b[so_mu_b];
        for(int i=0;i<=20;i++) temp[i]=0;
        for(int i=0;i<=leng(thuong);i++){
            for(int j=0;j<=so_mu_b;j++){
                temp[i+j]+=thuong[i]*b[j];
            }
        }
        for(int i=0;i<=so_mu_a;i++){
        sodu[i]=a[i]-temp[i];
        }
    }
}