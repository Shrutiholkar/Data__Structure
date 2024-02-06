//menu driven program 
//(create,preorder,inorder,postorder,insert,search)


#include<stdio.h>
#include<stdlib.h>
#define memory (node *)malloc(sizeof(node));
   
typedef struct node 
{
int data;
struct node *left,*right;
}node;

node *create(node *root)
{
int i,n;
node *temp,*newnode,*parent;
printf("enter limit ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
newnode=memory;
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

void inorder(node *root )
{
node *temp=root;
if(temp!=NULL)
{
inorder(temp->left);
printf("%d\t",temp->data);
inorder(temp->right);

}

}

void preorder(node *root)
{
node *temp=root;
if(temp!=NULL)
{
printf("%d\t",temp->data);
preorder(temp->left);
preorder(temp->right);
}
}

void postorder(node *root)
{
node *temp=root;
if(temp!=NULL)
{
postorder(temp->left);
postorder(temp->right);
printf("%d\t",temp->data);
}
}

node *insert(node *root)
{
int i,n;
node *newnode,*temp,*parent;
newnode=memory;
printf("enter value");
scanf("%d",&newnode->data);
newnode->left=NULL;
newnode->right=NULL;

if(root==NULL)
{
root=newnode;
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

return root;
}

int search(node *root)
{
int num;
printf("enter number");
scanf("%d",&num);
node *temp=root;
while(temp!=NULL)
{
if(num==temp->data)
{
return num;
}
else if(num<temp->data)
  temp=temp->left;
else 
  temp=temp->right;  
}
return -1;
}

void main()
{
int ch,ans;
node *root=NULL;
do
{
printf("\n1-create\n2-preorder\n3-inorder\n4-postorder\n5-insert\n6-search\n enter choice");
scanf("%d",&ch);
switch(ch)
{
case 1:root=create(root);break;
case 2:preorder(root);break;
case 3:inorder(root);break;
case 4:postorder(root);break;
case 5:root=insert(root);break;
case 6:ans=search(root);
       if(ans==-1)
       printf("not found");
       else
       printf("found");
       break;



}


}while(ch<7);


}















