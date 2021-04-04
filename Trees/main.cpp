#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    int data;
    Tree *left,*right;
};

struct Stack
{
    int Size,top;
    struct Tree **S;
};

struct Stack *createStack(struct Stack *st,int Size)
{
    st->Size=Size;
    st->top=-1;
    st->S=(struct Tree**)malloc(st->Size*sizeof(struct Tree*));
    return st;
};

void Push(struct Stack *st,struct Tree *x)
{
    if(st->top==st->Size-1)
        printf("Stack overflow\n");
    else
        st->S[++st->top]=x;
}

struct Tree *pop(struct Stack *st)
{
    if(st->top==-1)
        printf("Stack Underflow\n");
    else
    {
        Tree *x=st->S[st->top];
        st->top--;
        return x;
    }
};

bool isEmptyStack(struct Stack *st)
{
    return st->top==-1;
}


struct Queue
{
    int rear,size,front;
    Tree **Q;
};

Queue *create(Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(Tree**)malloc(q->size*sizeof(Tree*));
}

void Enque(Queue *q,Tree *x)
{
    if((q->rear+1)%q->size==q->front)
        cout<<"Queue is FULL";
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

struct Tree* Deque(Queue *q)
{
    Tree *x =NULL;
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

struct Tree* create(Tree* root)
{
    Queue q;
    create(&q,100);
    cout<<"Enter the value of root"<<endl;
    Tree *p,*r;
    cin>>root->data;
    root->left=root->right=NULL;
    Enque(&q,root);
    int x;
    while(!isEmpty(&q))
    {
        p=Deque(&q);
        printf("Enter -1 if no left node is there for node %d\n",p->data);
        cin>>x;
        if(x!=-1)
        {
            r = new Tree();
            r->data=x;
            r->left=r->right=NULL;
            p->left=r;
            Enque(&q,r);
        }
        printf("Enter -1 if no right node is there for node %d\n",p->data);
        cin>>x;
        if(x!=-1)
        {
            r = new Tree();
            r->data=x;
            r->left=r->right=NULL;
            p->right=r;
            Enque(&q,r);
        }
    }

    return root;
};

void LevelOrderIterative(Tree *p)
{
    Queue q;
    cout<<p->data<<" ";
    create(&q,100);
    Enque(&q,p);
    while(!isEmpty(&q))
    {
        p=Deque(&q);
        if(p->left)
        {
            cout<<p->left->data<<" ";
            Enque(&q,p->left);
        }
        if(p->right)
        {
            cout<<p->right->data<<" ";
            Enque(&q,p->right);
        }
    }
    //printf("\n");
}

int height(Tree *p)
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

void PreorderIterative(struct Tree* p)
{
    struct Stack st;
    createStack(&st,100);
    while(p || !isEmptyStack(&st))
    {
        if(p!=NULL)
        {
            cout<<p->data<<" ";
            Push(&st,p);
            p=p->left;
        }
        else
        {
            p=pop(&st);
            p=p->right;
        }
    }
}

void InorderIterative(struct Tree* p)
{
    struct Stack st;
    createStack(&st,100);
    while(p || !isEmptyStack(&st))
    {
        if(p!=NULL)
        {
            Push(&st,p);
            p=p->left;
        }
        else
        {
            p=pop(&st);
            cout<<p->data<<" ";
            p=p->right;
        }
    }
}

void PostorderIterative(struct Tree* p)
{
    struct Stack st1,st2;
    createStack(&st1,100);
    createStack(&st2,100);
    Push(&st1,p);
    Tree* temp;
    while(!isEmptyStack(&st1))
    {
        temp=pop(&st1);
        Push(&st2,temp);
        if(temp->left)
            Push(&st1,temp->left);
        if(temp->right)
            Push(&st1,temp->right);
    }
    while(!isEmptyStack(&st2))
        cout<<pop(&st2)->data<<" ";
}

void Preorder(Tree *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        Preorder(p->left);
        Preorder(p->right);
    }

}

/* void LevelOrder(Tree *p)
{
    if(p->left || p->right)
    {
        cout<<p->data<<" ";
        LevelOrder(p->left);
        LevelOrder(p->right);
    }
} */

void Inorder(Tree *p)
{
    if(p)
    {
        Inorder(p->left);
        cout<<p->data<<" ";
        Inorder(p->right);
    }

}

void Postorder(Tree *p)
{
    if(p)
    {
        Postorder(p->left);
        Postorder(p->right);
        cout<<p->data<<" ";
    }
}

int countNode(Tree *p)
{
    if(p)
        return countNode(p->left)+countNode(p->right)+1;
    return 0;
}

int c=0;
int countLeafNode(Tree *p)
{
    if(!p)
        return 0;
    if(p->left==NULL && p->right==NULL)
        return countLeafNode(p->left)+countLeafNode(p->right)+1;
    return countLeafNode(p->left)+countLeafNode(p->right);
}

int count2deg(Tree *p)
{
    if(!p)
        return 0;
    if(p->left==NULL || p->right==NULL)
        return count2deg(p->left)+count2deg(p->right)+1;
    return count2deg(p->left)+count2deg(p->right);
}

int count1deg(Tree *p)
{
    if(!p)
        return 0;
    if(p->left==NULL^p->right==NULL)
        return count1deg(p->left)+count1deg(p->right)+1;
    return count1deg(p->left)+count1deg(p->right);
}


Tree* genrateTree(int *inorder,int *preorder,int start,int end,unordered_map<int,int>&a)
{
    static int pre = 0;
    if(start>end)
        return NULL;
    Tree *node=new Tree();
    node->data=preorder[pre++];
    node->left=node->right=NULL;
    if(start==end)
        return node;
    int index = a[node->data];
    node->left=genrateTree(inorder,preorder,start,index-1,a);
    node->right=genrateTree(inorder,preorder,index+1,end,a);

    return node;
}

Tree* Find(int *p,int *in,int len,int start)
{
    unordered_map<int,int>a;
    for(int i=0;i<=len;i++)
        a[in[i]]=i;
    return genrateTree(in,p,start,len,a);
}
int main()
{
    int inorder[]={4,2,5,1,6,3};
    int preorder[]={1,2,4,5,3,6};
    int len = sizeof(inorder)/sizeof(inorder[0])-1;
    Tree *root=Find(preorder,inorder,len,0);
    Preorder(root);
    cout<<endl;
    Inorder(root);
    cout<<endl;
    Postorder(root);
    cout<<endl;
}
