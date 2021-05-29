#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct
{
    char hoten[20];
    int tuoi;
    float diem;
} sv;

typedef struct node
{
    sv data;
    struct node* next;
} node;

node* first=NULL;
int max=0;

node* taoNode()
{
    node* pnode=(node*) malloc(sizeof(node));

    printf("Nhap ho ten: ");
    fflush(stdin);
    gets(pnode->data.hoten);
    printf("Nhap tuoi: ");
    scanf("%d",&pnode->data.tuoi);
    printf("Nhap diem: ");
    scanf("%f",&pnode->data.diem);

    pnode->next=NULL;
    return pnode;
}

void taoNodeDauTien()
{
    node* pnode;
    if (first==NULL) first=taoNode();
    max++;
}

void taoNodeViTriCuoi()
{
    node* tmp;
    if (first==NULL) taoNodeDauTien();
    else
    {
        for (tmp=first; tmp->next!=NULL ; tmp=tmp->next);
        node* pnode=taoNode();
        tmp->next=pnode;
    }

}

int taoDS(int maxcurrent)
{
    char rep;
    while (1)
    {
        taoNodeViTriCuoi();
        maxcurrent++;
        printf("Nhap tiep(y/n)? ");
        fflush(stdin);
        rep=getchar();
        if (rep=='n') break;
    }
    return maxcurrent;
}

void inDS()
{
    node* tmp;
    printf("\nHoTen\tTuoi\tDiem\n");
    for (tmp=first; tmp!=NULL; tmp=tmp->next)
    {
        printf("\n%s\t%d\t%.2f",tmp->data.hoten,tmp->data.tuoi,tmp->data.diem);

    }
    printf("\nDanh sach co %d sinh vien", max);
}

void timsv()
{
    char t[20];
    int ok=0;
    node* tmp;
    printf("Nhap ten can tim: ");
    fflush(stdin);
    gets(t);
    printf("\nHoTen\tTuoi\tDiem\n");
    for(tmp=first; tmp!=NULL; tmp=tmp->next)
    {
        if (strcmp(tmp->data.hoten,t)==0)
        {
           ok=1;
           printf("\n%s\t%d\t%.2f",tmp->data.hoten,tmp->data.tuoi,tmp->data.diem);
        }
        
    }
    if (ok==0) {
        printf("Khong tim thay, moi them SV nay vao danh sach\n");
        taoNodeViTriCuoi();
    }
}

void sxsv()
{
    node *t1, *t2;
    sv tmp;
    for(t1=first; t1!=NULL; t1=t1->next)
        for(t2=first; t2!=NULL; t2=t2->next)
        {
            if (strcmp(t1->data.hoten,t2->data.hoten)<0)
            {
                tmp=t1->data;
                t1->data=t2->data;
                t2->data=tmp;
            }
        }
    printf("Xong!\nBam phim bat ki de tiep tuc...");
}

void inDSHB(int max)
{
    node* tmp;
    int i=0;
    int limit = max*0.15;
    printf("\nHoTen\tTuoi\tDiem\n");
    for (tmp=first; tmp!=NULL; tmp=tmp->next)
    {
        if ((i<limit) && (tmp->data.diem>=7)){
            printf("\n%s\t%d\t%.2f",tmp->data.hoten,tmp->data.tuoi,tmp->data.diem);
        }
        i++;
        
    }
}


int main()
{
    char rep;
    int chon;
    system("cls");
    while (chon!=6)
    {
        system("cls");
        printf("1.Tao DS SV\n");
        printf("2.Sap xep theo ho ten tang dan\n");
        printf("3.Hien thi danh sach hoc bong\n");
        printf("4.Tim SV\n");
        printf("5.In DS\n");
        printf("6.Thoat\n");
        printf("Lua chon: ");
        scanf("%d",&chon);
        switch (chon)
        {
            case 1 : max=taoDS(max); break;
            case 2 : sxsv(); getch(); break;
            case 3 : inDSHB(max); getch(); break;
            case 4 : timsv(); getch(); break;
            case 5 : inDS(); getch(); break;
            

        }
    }
}
