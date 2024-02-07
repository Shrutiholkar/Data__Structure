//levelorder tree

#include<stdio.h>
#include<stdlib.h>
#define max 50
struct node 
{
int data;
struct node *left,*right;
};
struct que
{
struct node *data1[max];
int front,rear;
};
struct que q;

void init()
{
q.front=q.rear=-1;
}

int isempty()
{
return(q.front==q.rear);

}

int isfull()
{
return(q.rear==max-1);
}

void add(struct node *temp)
{
q.data1[++q.rear]=temp;

}

struct node *delete()
{
return q.data1[++q.front];
}

struct node *create(struct node *root)
{
int i,n,num;
struct node *temp,*newnode,*parent;
printf("enter limit ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
newnode=(struct node *)malloc(sizeof(struct node ));
printf("enter value");
scanf("%d",&newnode->data);
newnode->left=newnode->right=NULL;
if(root==NULL)
{
root=newnode;
continue;
}
temp=root;
while(temp!=NULL)
{
parent=temp;
if(newnode->data<temp->data)
 temp=temp->left;
else
  temp=temp->right; 
}
if(newnode->data<parent->data)
 parent->left=newnode;
else
 parent->right=newnode; 
}
return root;
}

void levelorder(struct node *root)
{
struct node *m=NULL,*temp;
int level=0;
init();
add(root);
add(m);
printf("\nlevel-%d-->",level);
while(!isempty())
{
temp=delete();
if(temp==m)
{
level++;
if(!isempty())
add(m);
printf("level-%d-->",level);
}
else
{
printf("\n%d",temp->data);
if(temp->left)
add(temp->left);
if(temp->right)
add(temp->right);
}
}
}

void main()
{
struct node *root=NULL;
root=create(root);
levelorder(root);

}


