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

void taoDS()
{
    char rep;
    while (1)
    {
        taoNodeViTriCuoi();
        printf("Nhap tiep(y/n)? ");
        fflush(stdin);
        rep=getchar();
        if (rep=='n') break;
    }
}

void inDS()
{
    node* tmp;
    printf("\nHoTen\tTuoi\tDiem\n");
    for (tmp=first; tmp!=NULL; tmp=tmp->next)
    {
        printf("\n%s\t%d\t%.2f",tmp->data.hoten,tmp->data.tuoi,tmp->data.diem);

    }
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
    if (ok==0) printf("Khong tim thay");
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

void xoasv()
{
    char t[20];
    node* tmp;
    node* t2;
    node* pre;
    printf("Nhap ten can tim: ");
    fflush(stdin);
    gets(t);
    if (strcmp(first->data.hoten,t)==0)
    {
        node* del=first;
        first=first->next;
        free(del);
    }
    else
    {
        pre=first;
        for(tmp=first->next; tmp!=NULL; tmp=tmp->next)
        {
            if (strcmp(tmp->data.hoten,t)==0)
            {

                node* del;
                del=pre->next;
                pre->next=del->next;
            free(del);
            }
            pre=tmp;
        }
    }
    printf("Xong!/nBam phim bat ki de tiep tuc...");
}

void xoacuoi()
{
    node* tmp;
    node* del;
    node* tmp2;
    for (tmp=first; tmp->next!=NULL; tmp=tmp->next);
    for (tmp2=first; tmp2->next!=tmp; tmp2=tmp2->next);
    tmp2->next=NULL;
    free(tmp);


}

int main()
{
    char rep;
    int chon;
    system("cls");
    while (chon!=7)
    {
        system("cls");
        printf("1.Nhap\n");
        printf("2.In\n");
        printf("3.Tim\n");
        printf("4.Sap xep\n");
        printf("5.Xoa\n");
        printf("6.Xoa cuoi\n");
        printf("7.Thoat\n");
        printf("Lua chon: ");
        scanf("%d",&chon);
        switch (chon)
        {
            case 1 : taoDS(); break;
            case 2 : inDS(); getch(); break;
            case 3 : timsv(); getch(); break;
            case 4 : sxsv(); getch(); break;
            case 5 : xoasv(); getch(); break;
            case 6 : xoacuoi(); getch(); break;

        }
    }
}
