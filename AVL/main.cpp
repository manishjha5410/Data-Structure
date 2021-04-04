#include <bits/stdc++.h>
using namespace std;

struct AVL
{
    int data,height;
    AVL *left,*right;
}*root=NULL;

struct Queue
{
    int rear,size,front;
    AVL **Q;
};

Queue *create(Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(AVL**)malloc(q->size*sizeof(AVL*));
}

void Enque(Queue *q,AVL *x)
{
    if((q->rear+1)%q->size==q->front)
        cout<<"Queue is FULL";
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

struct AVL* Deque(Queue *q)
{
    AVL *x =NULL;
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

void Preorder(AVL *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        Preorder(p->left);
        Preorder(p->right);
    }

}

void Inorder(AVL *p)
{
    if(p)
    {
        Inorder(p->left);
        cout<<p->data<<" ";
        Inorder(p->right);
    }

}

void Postorder(AVL *p)
{
    if(p)
    {
        Postorder(p->left);
        Postorder(p->right);
        cout<<p->data<<" ";
    }
}

AVL* newNODE(int x)
{
    AVL *node=new AVL();
    node->data=x;
    node->height=1;
    node->left=node->right=NULL;
    return node;
}

int height(AVL *p)
{
    int hl,hr;
    hl=p && p->left?p->left->height:0;
    hr=p && p->right?p->right->height:0;
    return hl>hr?hl+1:hr+1;
}

int balanceFactor(AVL *p)
{
    int a = (p && p->left?p->left->height:0);
    int b = (p && p->right?p->right->height:0);
    int x = a-b;
    return x;
}


AVL *LLRotation(AVL *p)
{
    AVL *pl=p->left;

    p->left=pl->right;
    pl->right=p;

    p->height=height(p);
    pl->height=height(pl);

    if(p==root)
        root=pl;

    return pl;
}

AVL *LRRotation(AVL *p)
{
    AVL *pl=p->left,*plr=pl->right;

    pl->right=plr->left;
    p->left=plr->right;

    plr->left=pl;
    plr->right=p;

    p->height=height(p);
    pl->height=height(p);
    plr->height=height(p);

    if(root==p)
        root=plr;
    return plr;
}

AVL *RRRotation(AVL *p)
{
    AVL *pr=p->right;

    p->right=pr->left;
    pr->left=p;

    p->height=height(p);
    pr->height=height(pr);

    if(p==root)
        root=pr;

    return pr;
}

AVL *RLRotation(AVL *p)
{
    AVL *pr=p->right,*prl=pr->left;

    pr->left=prl->right;
    p->right=prl->left;

    prl->left=p;
    prl->right=pr;

    p->height=height(p);
    pr->height=height(p);
    prl->height=height(p);

    if(root==p)
        root=prl;
    return prl;
}

AVL *Insert(AVL *p,int key)
{
    if(p==NULL)
        return newNODE(key);

    if(key<p->data)
        p->left=Insert(p->left,key);
    else if(key>p->data)
        p->right=Insert(p->right,key);

    p->height=height(p);

    if(balanceFactor(p)==2 && balanceFactor(p->left)==1)
        return LLRotation(p);
    else if(balanceFactor(p)==2 && balanceFactor(p->left)==-1)
        return LRRotation(p);
    else if(balanceFactor(p)==-2 && balanceFactor(p->left)==-1)
        return RRRotation(p);
    else if(balanceFactor(p)==-2 && balanceFactor(p->left)==1)
        return RLRotation(p);
    return p;
}

AVL* inSucc(AVL *p)
{
    if(p && p->left==NULL)
        p=p->left;
    return p;
}

AVL* inPrec(AVL *p)
{
    if(p && p->right==NULL)
        p=p->right;
    return p;
}

struct AVL* create(AVL* q)
{
    cout<<"Enter the value of root"<<endl;
    AVL *p;
    int r;
    cin>>r;
    if(r!=-1)
    {
        root=newNODE(r);
        q=root;
    }
    while(r!=-1)
    {
        cout<<"Enter -1 if no value"<<endl;
        cin>>r;
        if(r!=-1)
            root=Insert(root,r);;
    }
    return root;
};


int search(AVL *p,int value)
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

int searchIterative(AVL *p,int value)
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



void printGivenLevel(AVL* root, int level)
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


void printLevelOrder(AVL* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printGivenLevel(root, i);
}

AVL *genrateAVL(int *in,int start,int last)
{
    if(start>last)
        return NULL;
    int mid = (start+last)/2;
    AVL *root = newNODE(in[mid]);
    root->left=genrateAVL(in,start,mid-1);
    root->right=genrateAVL(in,mid+1,last);
    root->height=height(root);
    return root;
}

AVL *minNode(AVL *p)
{
    if(p==NULL)
        return NULL;
    while(p->left!=NULL)
        p=p->left;
    return p;
}

struct AVL* Delete(struct AVL* p, int x)
{
	if (p==NULL)
        return p;

	if (x<p->data)
		p->left=Delete(p->left, x);

	else if (x>p->data)
		p->right=Delete(p->right, x);
	else
	{
	    if(p->left==NULL || p->right==NULL)
        {
            AVL *temp=p->left?p->left:p->right;
            if(temp==NULL)
            {
                temp=p;
                p=NULL;
            }
            else
                *p=*temp;
            free(temp);
        }
        else
        {
            AVL *temp=minNode(p->right);
            p->data=temp->data;
            p->right=Delete(p->right,temp->data);
        }
	}

	if(p==NULL)
        return p;
    p->height=height(p);
    int b = balanceFactor(p);
    if(b>1 && balanceFactor(p->left)>=0)
        return LLRotation(p);
    else if(b>1 && balanceFactor(p->left)<0)
    {
        p->left=LLRotation(p->left);
        return LRRotation(p);
    }
    else if(b<-1 && balanceFactor(p->right)<=0)
        return RRRotation(p);
    if(b<-1 && balanceFactor(p->right)>0)
    {
        p->right=LLRotation(p->right);
        return RLRotation(p);
    }
	return p;
}

int main()
{
    root=create(root);
    root=Delete(root,3);
    Preorder(root);
    cout<<endl;
    Inorder(root);
    cout<<endl;
    Postorder(root);
    cout<<endl;
    printLevelOrder(root);
    cout<<endl;
}
