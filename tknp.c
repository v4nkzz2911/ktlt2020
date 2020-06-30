#include<stdio.h>
#include<string.h>
#define MAX 100
int tknp(int a[], int dau, int cuoi, int x)
{
    if (dau>cuoi)
    {
        return -1;
    }
    int giua=(dau+cuoi)/2;
    if (a[giua]==x) 
    {
        return giua;
    }
    else
    {
        if (a[giua]>x){
            cuoi=giua;
        }
        if (a[giua]<x){
            dau=giua;
        }
        return tknp(a,dau,cuoi,x);
    }
}

int nhap (int a[])
{
    int i,l;
    int n;
    char rep;
    printf("Nhap vao so phan tu: ");
    scanf("%d",&n);
    printf("\n");
    while(1)
    {
        printf("Nhap phan tu thu 0: ");
            scanf("%d",&a[0]);
        for(i=1;i<n;i++)
        {
            printf("Nhap phan tu thu %d: ",i);
            scanf("%d",&a[i]);
            if (a[i]<a[i-1]) 
            {
                printf("Nho hon phan tu truoc!!!\nMoi ban nhap lai...\n");
                scanf("",l);
                break;
            }
        }
        if (i==n) return n;
    }
}

void xuat(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}

int main()
{
    int a[MAX];
    int i,n,x;
    printf("Nhap x: ");
    scanf("%d",&x);

    n=nhap(a);

    printf("%d",tknp(a,0,n-1,x));
    return 0;


}

