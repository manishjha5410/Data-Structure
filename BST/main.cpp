#include <bits/stdc++.h>
using namespace std;

struct BST
{
    int data;
    BST *left,*right;
};

struct Queue
{
    int rear,size,front;
    BST **Q;
};

Queue *create(Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(BST**)malloc(q->size*sizeof(BST*));
}

void Enque(Queue *q,BST *x)
{
    if((q->rear+1)%q->size==q->front)
        cout<<"Queue is FULL";
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

struct BST* Deque(Queue *q)
{
    BST *x =NULL;
    if(q->front==q->rear)
        cout<<"Queue is Empty";
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
};

bool isEmpty(Queue *q)
{
    return q->front==q->rear;
}



void Preorder(BST *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        Preorder(p->left);
        Preorder(p->right);
    }

}

void Inorder(BST *p)
{
    if(p)
    {
        Inorder(p->left);
        cout<<p->data<<" ";
        Inorder(p->right);
    }

}

void Postorder(BST *p)
{
    if(p)
    {
        Postorder(p->left);
        Postorder(p->right);
        cout<<p->data<<" ";
    }
}

BST* newNODE(int x)
{
    BST *node=new BST();
    node->data=x;
    node->left=node->right=NULL;
    return node;
}

struct BST* create(BST* root)
{
    cout<<"Enter the value of root"<<endl;
    BST *p,*t;
    cin>>root->data;
    root->left=root->right=NULL;
    int x,r;
    cout<<"Enter -1 if no value"<<endl;
    cin>>r;
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
        cout<<"Enter -1 if no value"<<endl;
        cin>>r;
    }
    return root;
};

BST* Insert(BST* root,int r)
{
    BST *p,*t;
    t=root;
    while(t!=NULL)
    {
        p=t;
        if(r>t->data)
            t=t->right;
        else
            t=t->left;
    }
    if(r>p->data)
        p->right=newNODE(r);
    else
        p->left=newNODE(r);
    return root;
};

BST* InserReccur(BST *node,int x)
{
    BST *t;
    if(node==NULL)
        return newNODE(x);
    if(x>node->data)
        node->right=InserReccur(node->right,x);
    else
        node->left=InserReccur(node->left,x);
    return node;
}

int search(BST *p,int value)
{
    if(!p)
        return NULL;
    else if(p->data==value)
        return value;
    else if(value>p->data)
        search(p->right,value);
    else
        search(p->left,value);
}

int searchIterative(BST *p,int value)
{
    while(p!=NULL)
    {
        if(p->data==value)
            return value;
        else if(value>p->data)
            p=p->right;
        else
            p=p->left;
    }
    return NULL;
}

int height(BST *p)
{
    if(p==NULL)
        return 0;
    int x=0,y=0;
    x=height(p->left);
    y=height(p->right);
    if(x>y)
        return x+1;
    else
        return y+1;
}

BST* inSucc(BST *p)
{
    if(p && p->left==NULL)
        p=p->left;
    return p;
}

BST* inPrec(BST *p)
{
    if(p && p->right==NULL)
        p=p->right;
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

bool isBst(BST *p,int Min,int Max)
{
    if(p==NULL)
        return true;
    else if(Min>p->data || p->data>Max)
        return false;
    return isBst(p->left,Min,p->data-1) && isBst(p->right,p->data+1,Max);
}

BST *generateBST(int *pre,int p,int data,int Min,int Max,int len)
{
    if(p>=len)
        return NULL;
    BST *node=NULL;
    if(data>Min && data<Max)
    {
        node=newNODE(data);
        p++;
        if(p<len)
        {
            node->left=generateBST(pre,p,pre[p],Min,data,len);
            node->right=generateBST(pre,p,pre[p],data,Max,len);
        }
    }

    return node;
}


void printGivenLevel(BST* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level>1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}


void printLevelOrder(BST* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printGivenLevel(root, i);
}

int main()
{
    BST *root=new BST();
    /*root=create(root);
    Inorder(root);
    cout<<endl;
    Delete(root,23);
    Preorder(root);
    cout<<endl;
    printLevelOrder(root);
    cout<<endl;
    if(isBst(root,INT_MIN,INT_MAX)==true)
        cout<<"BST"<<endl;
    else
        cout<<"NOT A BST"<<endl;*/

    int pre[]={20,8,15,13,14};
    root=generateBST(pre,0,pre[0],INT_MIN,INT_MAX,sizeof(pre)/sizeof(pre[0]));
    Inorder(root);

}
