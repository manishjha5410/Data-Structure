#include <bits/stdc++.h>
using namespace std;

struct Element
{
    int x,y,z;
};

struct Sparsed
{
    int m,n,num;
    struct Element *e;
};

int Create(struct Sparsed* s)
{
    printf("Enter number of rows and columns\n");
    scanf("%d%d",&s->m,&s->n);
    printf("Enter number of non zero element\n");
    scanf("%d",&s->num);
    s->e=(struct Element*)malloc(s->num*sizeof(struct Element));
    printf("Enter row,column,element\n");
    for(int i=0;i<s->num;i++)
        scanf("%d%d%d",&s->e[i].x,&s->e[i].y,&s->e[i].z);
}

int display(struct Sparsed* s)
{
    int i,j,k=0;
    for(i=0;i<s->m;i++)
    {
        for(int j=0;j<s->n;j++)
        {
            if(j==s->e[k].y && s->e[k].x)
                printf("%d ",s->e[++k].z);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    Sparsed s;
    Create(&s);
    display(&s);
}
