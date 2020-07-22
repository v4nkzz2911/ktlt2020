#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>

#define nmax 1000

typedef struct SV
{
    char MaSV[10];
    char HoTen[30];
    float toan;
    float ly;
    float hoa;
} SV;

SV a[nmax];
float dtb[nmax];
int count=0;
int* toCount=&count;

void initList(SV a[])
{
    printf("Danh sach da duoc khoi tao!!");
    *toCount=0;
    getch();
}

void inputEntry(SV a[], int current)
{
    printf("Nhap thong tin cho sinh vien thu %d \n",current);
    printf("Nhap ma SV: ");
    fflush(stdin);
    gets(a[current].MaSV);
    printf("Nhap ho ten: ");
    fflush(stdin);
    gets(a[current].HoTen);
    printf("Nhap diem toan: ");
    scanf("%f",&a[current].toan);
    printf("Nhap diem ly: ");
    scanf("%f",&a[current].ly);
    printf("Nhap diem hoa: ");
    scanf("%f",&a[current].hoa);
    dtb[current]=(a[current].toan+a[current].ly+a[current].hoa)/3;
}



int inputKEntry(SV a[], int current)
{
    int k,i;
    printf("Nhap so luong SV muon nhap: ");
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        inputEntry(a,current+i);
    }
    return k;
}

void printAllEntry(SV a[],int count)
{
    int i;
    if (count==0) printf("Danh sach rong!!");
        else
        {    
            printf("Danh sach sinh vien\n");
            printf("------------------------------------------------------------------\n");
            printf("%10s|%30s|%5s|%5s|%5s|%5s\n","MSV","Ho ten","Toan","Ly","Hoa","DTB");
            for(i=0;i<count;i++)
            {
                printf("%10s|%30s|%3.2f|%3.2f|%3.2f|%3.2f\n",a[i].MaSV,a[i].HoTen,a[i].toan,a[i].ly,a[i].hoa,dtb[i]);
            }
        }
    getch();
}

void sortToanEntry(SV a[], int count)
{
    SV t3mp;
    int i,j;
    for(i=0;i<count;i++)
        for(j=0;j<count;j++)
        {
            if (a[i].toan<a[j].toan)
            {
                t3mp=a[i];
                a[i]=a[j];
                a[j]=t3mp;
            }
        }
}

void sortLyEntry(SV a[], int count)
{
    SV t3mp;
    int i,j;
    for(i=0;i<count;i++)
        for(j=0;j<count;j++)
        {
            if (a[i].ly<a[j].ly)
            {
                t3mp=a[i];
                a[i]=a[j];
                a[j]=t3mp;
            }
        }
}

void sortHoaEntry(SV a[], int count)
{
    SV t3mp;
    int i,j;
    for(i=0;i<count;i++)
        for(j=0;j<count;j++)
        {
            if (a[i].hoa<a[j].hoa)
            {
                t3mp=a[i];
                a[i]=a[j];
                a[j]=t3mp;
            }
        }
}

void sortDTBEntry(float dtb[],int count, SV a[])
{
    SV t3mp;
    float t;
    int i,j;
    for(i=0;i<count;i++)
        for(j=0;j<count;j++)
        {
            if (dtb[i]<dtb[j])
            {
                t3mp=a[i]; t=dtb[i];
                a[i]=a[j]; dtb[i]=dtb[j];
                a[j]=t3mp; dtb[j]=t;
            }
        }
}

void sortAllEntry(SV a[], int count, int type,float dtb[])
{
    switch (type)
    {
    case 1:
        sortToanEntry(a,count);
        break;
    case 2:
        sortLyEntry(a,count);
        break;
    case 3:
        sortHoaEntry(a,count);
        break;
    case 4:
        sortDTBEntry(dtb,count,a);
        break;
    }
    
}

int checkToanEntry(SV a[],int count)
{
    int i,j;
    for ( i = 0; i < count-1; i++)
    {
        for(j=1;j< count;j++)
        {
            if (a[i].toan>a[j].toan) return 0;
        }
    }
    return 1;
    
}

int checkLyEntry(SV a[],int count)
{
    int i,j;
    for ( i = 0; i < count-1; i++)
    {
        for(j=1;j< count;j++)
        {
            if (a[i].ly>a[j].ly) return 0;
        }
    }
    return 1;
    
}

int checkHoaEntry(SV a[],int count)
{
    int i,j;
    for ( i = 0; i < count-1; i++)
    {
        for(j=1;j< count;j++)
        {
            if (a[i].hoa>a[j].hoa) return 0;
        }
    }
    return 1;
    
}

int checkDTBEntry(float dtb[],int count)
{
    int i,j;
    for ( i = 0; i < count-1; i++)
    {
        for(j=1;j< count;j++)
        {
            if (dtb[i]>dtb[j]) return 0;
        }
    }
    return 1;
    
}

void checkAllEntry(SV a[], int count, int type,float dtb[])
{
    switch (type)
    {
    case 1:
        checkToanEntry(a,count);
        break;
    case 2:
        checkLyEntry(a,count);
        break;
    case 3:
        checkHoaEntry(a,count);
        break;
    case 4:
        checkDTBEntry(dtb,count);
        break;
    }
    
}

void findHoTenEntry(SV a[], int count)
{
    char t3mp[30];
    int i,kq[nmax];
    int check=0;
    printf("Nhap ten can tim: ");
    fflush(stdin);
    gets(t3mp);
    for(i=0;i<count;i++)
    {
        if (strcmp(a[i].HoTen,t3mp)==0) kq[i]++;
    }
    for (i=0;i<nmax;i++){
        if (kq[i]!=0) check=1; 
    }
    if (check==0) 
    {    
        printf("Khong tim thay!!");
        return;
    }
    else
    {
        printf("Danh sach sinh vien tim thay");
        printf("----------------------------");
        printf("%10s|%30s|%5s|%5s|%5s|%5s","MSV","Ho ten","Toan","Ly","Hoa","DTB");
        for (i = 0; i < count; i++)
        {
            if(kq[i]!=0)
                printf("%10s|%30s|%5f|%5f|%5f|%5f\n",a[i].MaSV,a[i].HoTen,a[i].toan,a[i].ly,a[i].hoa,dtb[i]);
        }
        
    }
    
}

int binarySearchDTBEntry(float dtb[], int dau, int cuoi, int x)
{
    if (dau>cuoi)
    {
        return -1;
    }
    int giua=(dau+cuoi)/2;
    if (dtb[giua]==x) 
    {
        return giua;
    }
    else
    {
        if (dtb[giua]>x){
            cuoi=giua;
        }
        if (dtb[giua]<x){
            dau=giua;
        }
        return binarySearchDTBEntry(dtb,dau,cuoi,x);
    }
}

void deleteEntry(SV a[],int count)
{
    int i;
    char t3mp[10];
    printf("Nhap MSV can xoa: ");
    fflush(stdin);
    gets(t3mp);

}

void menu()
{
    system("cls");
    printf("1.Khoi tao danh sach\n");
    printf("2.Nhap k sinh vien\n");
    printf("3.Xem danh sach\n");
    printf("4.Sap xep danh sach theo thu tu tang dan\n");
    printf("5.Kiem tra danh sach da sap xem chua\n");
    printf("6.Tim kiem tuyen tinh theo Hoten\n");
    printf("7.Tim kiem nhi phan theo dtb\n");
    printf("8.Xoa sinh vien co masv=xMasv(tu ban phim)\n");
    printf("9.Chen sinh vien k lam mat tinh sap xep\n");
    printf("S.Chon S de luu danh sach sinh vien vao DSSV.dat\n");
    printf("L.Chon L de load danh sach sinh vien va hien thi\n");
    printf("Z.Thoat\n");
    printf("Lua chon: ");
}

void subMenuSort()
{
    system("cls");
    printf("1.Sap xep theo diem Toan\n");
    printf("2.Sap xep theo diem Ly\n");
    printf("3.Sap xep thep diem Hoa\n");
    printf("4.Sap xep theo diem Trung Binh\n");
    printf("Lua chon: ");
}

void subMenuCheck()
{
    system("cls");
    printf("1.Kiem tra theo diem Toan\n");
    printf("2.Kiem tra theo diem Ly\n");
    printf("3.Kiem tra thep diem Hoa\n");
    printf("4.Kiem tra theo diem Trung Binh\n");
    printf("Lua chon: ");
}

void main()
{
    char rep='1';
    int subRep=0;
    while (rep!='Z')
    {
        menu();
        fflush(stdin);
        scanf("%c",&rep);
        switch (rep)
        {
            case '1': 
                initList(a);
                break;
            case '2':
                count=count+inputKEntry(a,count);
                break;
            case '3':
                printAllEntry(a,count);
                break;
            case '4':
                subMenuSort();
                scanf("%d",&subRep);
                sortAllEntry(a,count,subRep,dtb);
                break;
            case '5':
                subMenuCheck();
                scanf("%d",&subRep);
                checkAllEntry(a,count,subRep,dtb);
                break;



        }

    }

}