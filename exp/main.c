#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};

struct BST* newNODE(int x)
{
    struct BST *node=(struct BST*)malloc(sizeof(struct BST));
    node->data=x;
    node->left=node->right=NULL;
    return node;
}

void Preorder(struct BST *p)
{
    if(p)
    {
        printf("%d ",p->data);
        Preorder(p->left);
        Preorder(p->right);
    }

}

void Inorder(struct BST *p)
{
    if(p)
    {
        Inorder(p->left);
        printf("%d ",p->data);
        Inorder(p->right);
    }

}

void Postorder(struct BST *p)
{
    if(p)
    {
        Postorder(p->left);
        Postorder(p->right);
        printf("%d ",p->data);
    }
}

struct BST* create(struct BST* root)
{
    printf("Enter the value of root\n");
    struct BST *p,*t;
    int f;
    scanf("%d",&f);
    root=newNODE(f);
    int x,r;
    printf("Enter -1 if no value\n");
    scanf("%d",&r);
    while(r!=-1)
    {
        t=root;
        while(t!=NULL)
        {
            p=t;
            if(r>t->data)
                t=t->right;
            else
                t=t->left;
        }
        if(r>p->data && r!=-1)
            p->right=newNODE(r);
        else if(r!=-1)
            p->left=newNODE(r);
        printf("Enter -1 if no value\n");
        scanf("%d",&r);
    }
    return root;
};

struct BST* Insert(struct BST *node,int x)
{
    struct BST *t;
    if(node==NULL)
        return newNODE(x);
    if(x>node->data)
        node->right=Insert(node->right,x);
    else
        node->left=Insert(node->left,x);
    return node;
}

struct BST* inSucc(struct BST *p)
{
    if(p && p->left==NULL)
        p=p->left;
    return p;
}


struct BST* Delete(struct BST* p, int x)
{
	if (p==NULL)
        return p;

	if (x<p->data)
		p->left=Delete(p->left, x);

	else if (x>p->data)
		p->right=Delete(p->right, x);
	else if(x==p->data)
	{
		if(p->left==NULL)
		{
			struct BST *temp=p->right;
			free(p);
			return temp;
		}
		else if(p->right==NULL)
		{
			struct BST *temp=p->left;
			free(p);
			return temp;
		}
		struct BST* temp = inSucc(p->right);
		p->data = temp->data;
		p->right = Delete(p->right,temp->data);
	}
	else
    {
        printf("Not found\n");
        return NULL;
    }
	return p;
}


int main()
{
    int s=1;
    struct BST *root=NULL;
    while(s==1)
    {
        go2: printf("Here for a BST you can do following things: 1.Create 2.Insert 3.Delete 4.Display\n\tEnter your choice\n");
        int f;
        scanf("%d",&f);
        if(f==1)
        {
            root=create(root);
            printf("\n");
        }
        else if(f==2)
        {
            printf("Enter value to be inserted : ");
            int r;
            scanf("%d",&r);
            root=Insert(root,r);
            printf("\n");
        }
        else if(f==3)
        {
            printf("Enter value to be deleted\n");
            int h;
            scanf("%d",&h);
            root=Delete(root,h);
        }
        else if(f==4)
        {
            go1: printf("Enter which traversal do you want: 1.Preorder 2.Inorder 3.Postorder\n");
            int d;
            scanf("%d",&d);
            if(d==1)
            {
                Preorder(root);
                printf("\n");
            }
            else if(d==2)
            {
                Inorder(root);
                printf("\n");
            }
            else if(d==3)
            {
                Postorder(root);
                printf("\n");
            }
            else
            {
                printf("Wrong choice Entered\nEnter once again\n");
                goto go1;
            }
        }
        else
        {
            printf("Wrong choice Entered\nEnter once again\n");
            goto go2;
        }
        printf("Enter 1 to continue else for exit\n");
        scanf("%d",&s);
    }
}
