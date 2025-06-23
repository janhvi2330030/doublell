#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *next;
 struct node *prev;
 };
 struct node *head=NULL, *tail= NULL;

 //insertion at beginning
 void insertatbeg()
 {   struct node*  newnode;
     newnode=(struct node*) malloc(sizeof(struct node));
    printf("enter the number u want enter-");
    scanf("%d", &newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;

    head->prev = newnode;
    newnode -> next=head;
    head= newnode;
     
 }
 // insertion at end;
 void insertatend()
 {   struct node*  newnode;
     newnode=(struct node*) malloc(sizeof(struct node));
    printf("enter the number u want insert-");
    scanf("%d", &newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;

    tail->next = newnode;
    newnode -> prev=tail;
    tail= newnode;
 
 }

 // delete  from beginning
    void delfrombeg()
    {
      struct node* temp;
      temp =head;
      head=head->next;
      head ->prev =0;
      temp-> next=0;
      free (temp);
    }
    // delete  from end
    void delfromend()
    {
      struct node* temp;
      temp =tail;
      tail=tail->prev;
      tail->next =0;
      temp-> prev=0;
      free (temp);
    } 
    
   // reverse
   void reverse()
      {
       struct node*current,*nextnode;
       current =head;
       while (current!=0)
       {
         nextnode=current->next;
         current->next=current->prev;
         current->prev=nextnode;
         current=nextnode;
       }
       current=head;
       head=tail;
       tail=current;
       
      }
   
     
 int main()
 {
    int count=0, choice=1;
    struct node *newnode,*temp;
    while(choice==1){
    newnode= (struct node *)malloc(sizeof(struct node));
    printf("enter data-");
    scanf("%d", &newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL)
    {
     head=tail=newnode;
    }
    else
    {
   tail->next=newnode;
   newnode->prev=tail;
   tail=newnode;
    }
    printf("do u want to continue (0/1)-");
    scanf("%d",&choice);
    }
 printf("elements of doubly linked list-\n");
 temp=head;
 count=0;
 while (temp!=NULL)
 {
     printf("%d ",temp->data);
     temp=temp->next;
     count++;
 }
 printf(" \n total node-%d\n",count);

 printf("do u want to insert a elementin beginning (0/1)- ");
 scanf("%d",&choice);
 if(choice==1)
 {
    insertatbeg();
 }

  printf("do u want to insert a element in end(0/1)- ");
 scanf("%d",&choice);
 if(choice==1)
 {
    insertatend();
 }
printf("the elements after insertion are-");
count=0;
temp=head;
while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
    count++;
}
printf(" \n total node-%d\n",count);

printf("do u want to delete a element in beginning (0/1)- ");
 scanf("%d",&choice);
 if(choice==1)
 {
    delfrombeg();
 }
 printf("elements after deletion from begining-");
 temp=head;
 count=0;
  while(temp!=0)
{
   printf("%d ",temp->data);
   temp = temp->next;
   count++;
}
printf(" \n total node-%d\n",count);

printf("do u want to delete a element in end (0/1)- ");
 scanf("%d",&choice);
 if(choice==1)
 {
    delfromend();
 }

 printf("elements after deletion from last-");
 temp=head;
 count=0;
  while(temp!=0)
{
   printf("%d ",temp->data);
   temp = temp->next;
   count++;
}
printf(" \n total node-%d\n",count);


printf("do u want to reverse the dll (0/1)- ");
 scanf("%d",&choice);
 if(choice==1)
 {
    reverse();
 }

 printf("elements after reverse are-");
 temp=head;
 count=0;
  while(temp!=0)
{
   printf("%d ",temp->data);
   temp = temp->next;
   count++;
}
printf(" \n total node-%d\n",count);

 return 0;
 }