//heap sort program

#include<stdio.h>
#include<stdlib.h>
void accept(int a[],int n)
{
int i;
printf("enter value");
for(i=0;i<n;i++)
{
scanf("%d\t",&a[i]);
}
}
void disp(int a[],int n)
{
int i;
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
}

void heapify(int a[],int top,int last)
{
int large=a[top];
int j; 
   j=(2*top)+1;

if(j<=last && a[j]<a[j+1])
   j=j+1;
if(j<=last && large<a[j])
{
   int temp=a[top];
  a[top]=a[j];
  a[j]=temp;
  heapify(a,j,last); 
}
}

void buildheap(int a[],int n)
{
for(int i=(n/2)-1;i>=0;i--)
{
  heapify(a,i,n-1);
}

}

void heapsort(int a[],int n)
{
int last;
int top=0;
buildheap(a,n);
printf("\ninitial heap= ");
disp(a,n);
for(last=n-1;last>1;last--)
{
int temp=a[top];
a[top]=a[last];
a[last]=temp;


printf("\niteration %d=\n\n ",n-last );
disp(a,n);
heapify(a,top,last-1);
}
}

void main()
{
int n,a[20];
printf("enter limit ");
scanf("%d",&n);
accept(a,n);
heapsort(a,n);

}


