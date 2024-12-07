#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int a[20], b[20], tong[20], hieu[20], tich[40], thuong[20], sodu[20];
int so_mu_a, so_mu_b, max_a_b;

int leng(int mang[]);
void nhapdtmang(int mang[], int l, char ten);
void xuatmang(int mang[], int l, char ten);
void congmang(int a[], int b[]);
void trumang(int a[], int b[]);
void nhanmang(int a[], int b[]);
void chiamang(int a[], int b[]);
void inDaThuc(int mang[], int bac);

int main() {
    printf("Gia su ta da rut gon xong bieu thuc, nhap cac he so vao a[] va b[]\n");
    printf("voi bac thap dung truoc, bac cao dung sau.\n");
    printf("VD 2x^2-2x+1 va x^3-2, thi a[] = 1 -2 2 va b[] = -2 0 0 3\n");
    printf("bac cua bieu thuc 1 va bieu thuc 2: ");
    scanf("%d %d", &so_mu_a, &so_mu_b);
    
    if (so_mu_a >= so_mu_b)
        max_a_b = so_mu_a;
    else
        max_a_b = so_mu_b;

    nhapdtmang(a, so_mu_a, 'a');
    nhapdtmang(b, so_mu_b, 'b');
    
    // Xuat cac da thuc
    printf("\nDa thuc a: ");
    xuatmang(a, so_mu_a, 'a');
    
    printf("\nDa thuc b: ");
    xuatmang(b, so_mu_b, 'b');
    
    // Goi lai cac phep toan
    congmang(a, b);  
    trumang(a, b);   
    nhanmang(a, b);  
    chiamang(a, b); 
    
    
    printf("\nTong da thuc: ");
    inDaThuc(tong, max_a_b);

    printf("\nHieu da thuc: ");
    inDaThuc(hieu, max_a_b);

    printf("\nTich da thuc: ");
    inDaThuc(tich, so_mu_a + so_mu_b);

    printf("\nThuong da thuc: ");
    inDaThuc(thuong, leng(thuong));

    printf("\nSo du da thuc: ");
    inDaThuc(sodu, leng(sodu));
}

// xac dinh chieu dai
int leng(int mang[]) {
    int length = 0;
    for (int i = 0; i <= 19; i++) {
        if (mang[i] != 0)
            length = i;
    }
    return length;
}

// Nhap du thuc
void nhapdtmang(int mang[], int l, char ten) {
    for (int i = 0; i <= l; i++) {
        printf("%c[%d]= ", ten, i);
        scanf("%d", &mang[i]);
    }
}

// Xuat da thuc
void xuatmang(int mang[], int l, char ten) {
    for (int i = l; i >= 0; i--) {
        printf("%d", mang[i]);
        if (i > 0) printf("x^%d", i);
        if (i > 0 && mang[i-1] >= 0) printf(" + ");
    }
    printf("\n");
}


void congmang(int a[], int b[]) {
    for (int i = 0; i <= max_a_b; i++) {
        tong[i] = a[i] + b[i];
    }
}

 
void trumang(int a[], int b[]) {
    for (int i = 0; i <= max_a_b; i++) {
        hieu[i] = a[i] - b[i];
    }
}


void nhanmang(int a[], int b[]) {
    for (int i = 0; i <= so_mu_a; i++) {
        for (int j = 0; j <= so_mu_b; j++) {
            tich[i + j] += a[i] * b[j];
        }
    }
}


void chiamang(int a[], int b[]) {
    int temp[20];
    for (int i = 0; i <= so_mu_a; i++) sodu[i] = a[i];
    
    while (leng(sodu) >= so_mu_b) {
        thuong[leng(sodu) - so_mu_b] = sodu[leng(sodu)] / b[so_mu_b];
        
        // Xoá mang tam thoi
        for (int i = 0; i <= 19; i++) temp[i] = 0;
        
    
        for (int i = 0; i <= leng(thuong); i++) {
            for (int j = 0; j <= so_mu_b; j++) {
                temp[i + j] += thuong[i] * b[j];
            }
        }
        
        // Tra ket qua tu phan chia
        for (int i = 0; i <= so_mu_a; i++) {
            sodu[i] = a[i] - temp[i];
        }
    }
}

// In da thuc
void inDaThuc(int mang[], int bac) {
    for (int i = bac; i >= 0; i--) {
        if (mang[i] != 0) {
            if (i != bac && mang[i] > 0) printf("+");
            printf("%d", mang[i]);
            if (i > 0) printf("x^%d ", i);
        }
    }
    printf("\n");
}

