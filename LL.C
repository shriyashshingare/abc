#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *next;
};

int n=0;

int create_ll(struct node *h)
{

 char ch;
 struct node *ptr,*last;
 last=h;
 n=0;
 do
 {
 ptr=(struct node *)malloc(sizeof(struct node*));
 ptr->next=NULL;
 printf("\nEnter data in the node:");
 scanf("%d",&ptr->data);
 last->next=ptr;
 last=ptr;
 printf("Do you want to add more nodes(n/y):");
 scanf(" %c",&ch);
 n++;
 }while(ch=='y');
 return n;
}

void display_ll(struct node *h)
{
 printf("\nData in the Link List is:\n");
 struct node *ptr;
 if(h->next==NULL)
   printf("\nLink list is empty");
 else
 {
  ptr=h->next;
  while(ptr!=NULL)
  {
   printf("%d-->",ptr->data);
   ptr=ptr->next;
  }
 }
 printf("\n");
}

void add_node(struct node *h)
{
 int cnt=1,pos,f=1;
 struct node *ptr,*temp;
 ptr=(struct node *)malloc(sizeof(struct node*));
  printf("\nEnter Position to add node in between linklist:");
 scanf("%d",&pos);
 printf("\nEnter data in the node:");
 scanf("%d",&ptr->data);

 while(ptr!=NULL)
 {
  if(cnt==pos)
  {
   f=0;
   ptr->next=temp->next;
   temp->next=ptr;
   break;
  }
  else
  {
   temp=temp->next;
   cnt++;
  }
 }
 if(f==1)
 {printf("\nNo Node found\n");}
}

void rev_ll(struct node *h)
{
  struct node *p,*q,*r,*temp;
  p=NULL;
  q=h->next;
  while(q!=NULL)
  {
   r=q->next;
   q->next=p;
   p=q;
   q=r;
  }
  h->next=p;
}

void del_node(struct node *h)
{
 int cnt=1,f=1,pos;
 struct node *prev,*temp;
 printf("\nEnter Position to delete from linklist:");
 scanf("%d",&pos);
 temp=h->next;
 while(temp!=NULL)
 {
  if(cnt==pos)
  {
  f=0;
  prev->next=temp->next;
  temp->next=NULL;
  free(temp);
  break;
  }
  else
  {
   prev=temp;
   temp=temp->next;
   cnt++;
  }
 }
  if(f==1)
 {printf("\nNo Node found to delete\n");}
}

void sort_ll(struct node *h,int a)
{
 int i,j;
 n=a;
 struct node *prev,*curr,*temp;
 for(i=0;i<n;i++)
 {
  prev=h;
  curr=h->next;
  for(j=0;j<n-i-1;j++)
  {
   temp=curr->next;
   if(curr->data>temp->data)
   {
    prev->next=temp;
    curr->next=temp->next;
    temp->next=curr;
    prev=temp;
   }
   else
   {
    prev=curr;
    curr=curr->next;
   }
  }
 }
}

void merge_LL(struct node *h1,struct node *h2)
{
printf("Inside merge");
 struct node *h3,*t1,*t2,*t3;
 h3=(struct node *)malloc(sizeof(struct node*));
 h3->next=NULL;
 t1=h1->next;
 t2=h2->next;
 t3=h3;
 while(t1!=NULL&&t2!=NULL)
 {
   if(t1->data<t2->data)
   {
    t3->next=t1;
    t1=t1->next;
    t3=t3->next;
   }
   else
   {
    t3->next=t2;
    t2=t2->next;
    t3=t3->next;
   }
 }
 if(t1!=NULL)
   t3->next=t1;
 if(t2!=NULL)
   t3->next=t2;

 printf("\n1st linklist:\n");
 display_ll(h1);
 printf("\n2ed linklist:\n");
 display_ll(h2);
 printf("\nMerged linklist:\n");
 display_ll(h3);
}
