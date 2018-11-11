#include <stdio.h>
#include <stdlib.h>

typedef struct ph *pp;

struct ph{
int am;
float grade;
pp next;
};

pp h, t;

void insert(pp *h,pp *t);
void print1(pp h);
void print2(pp h);
void d_elete(pp *h,pp *t);

int main()
{

    h = NULL;
    t = NULL;
    char marg;
    marg = 'a';

    while(marg!='q')
    {
        printf("Enter your selection:\n"
               "i:insert new student\n"
               "d:delete\n"
               "p:print list\n");

        scanf("\n%c",&marg);
        if(marg == 'q') printf("\n QUIT \n");
        if(marg == 'i')
        {
            printf("\n INSERT \n");
            insert(&h,&t);
        }
        if(marg == 'd')
        {
            printf("\n DELETE \n");
            d_elete(&h,&t);
        }
        if(marg == 'p')
        {
            printf("\n LIST PRINT \n");
            print1(h);
        }
    }






    return 0;
}

void insert(pp *h,pp *t)
{
    pp temp,aux;
    int data;

    printf("Please insert new AM\n");
    scanf("\n%d",&data);

    temp = (pp)malloc(sizeof(struct ph));
    temp->am = data;
    temp->next = NULL;
    printf("the AM of the new student is: %d \n",temp->am);
    if ((*h)!=NULL && (*h)->am>temp->am)
    {
        temp->next = *h;
        *h = temp;
    }

    if ((*h)!=NULL && (*h)->am<temp->am /*&& (*h)->next != NULL*/)
    {
        aux = *h;
        while(aux->next!=NULL && aux->next->am<temp->am) aux = aux->next;
        if(aux->next!= NULL)
        {
            temp->next = aux->next;
            aux->next = temp;
        }
        if(aux->next == NULL)
        {
            aux->next=temp;
            *t=temp;
        }

    }
    /*if ((*h)!=NULL && (*h)->am<temp->am && (*h)->next == NULL)
    {

        (*h)->next = temp;

        *t = temp;

    }*/
    if((*h)==NULL)
    {
        *h= temp;
        *t= temp;
    }

}

void d_elete(pp *h,pp *t)
{
    pp temp,aux;
    int data;
    printf("Please insert AM to delete\n"); printf("e115");
    fflush(stdin); printf("e116");
    scanf("%d",&data); printf("e117%d",data);
    getchar();
    sleep(1);
    if((*h)!=NULL && (*h)->am < data)
    {
        aux = *h; printf("e120");

        while(aux->next!=NULL && aux->next->am != data)
        {
        aux = aux->next; printf("e124");
        }
        if(aux->next->am != data) printf("There is no student with this AM");
        if(aux->next->am == data)
        {
            temp = aux->next;
            aux->next = temp->next;
            free(temp);
        }
    }
    if(h!=NULL && (*h)->am == data)
    {
        if((*h)->next==NULL)
        {
            free(*h);
            *h = NULL; printf("e140");
            *t = NULL; printf("e141");

        return;
        }
        if((*h)->next!=NULL)
        {
            temp = *h; printf("e148 %p",*h);
            *h = (*h)->next; printf("e149 %p",*h);
            free(temp);
        }
    }
}

void print1(pp h)
{

    pp aux;
    aux = h; //printf("e157 %p",h);
    int i = 1;
    if(aux == NULL) printf("There is no student in the list\n\n");
    if(aux!=NULL&&aux->next == NULL) printf("%d student AM:%d \n",i,aux->am);
    while(aux!=NULL&&aux->next!=NULL)
    {
        printf("%d student AM:%d \n",i,aux->am/*,aux->next*/);
        i++;
        if(aux->next->next == NULL) printf("%d student AM:%d \n",i++,aux->next->am);
        aux=aux->next;

    }
}
