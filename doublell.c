#include<stdio.h>
#include<stdlib.h>
 struct Node
 {
   int data;
   struct Node *next;
   struct Node *prev;
 }*start=NULL,*last=NULL,*temp;
 
 void create();
 void insert_beg();
 void insert_loc();
 void insert_end();
 void insert_before();
 void insert_after();
 void delete_beg();
 void delete_loc();
 void delete_end();
 void delete_before();
 void delete_after();
 void display();

 void main()
 { 
  int ch;

   while(1)
   {
    printf("\n1.Create");
    printf("\n2.Insert at beginning");
    printf("\n3.Insert at any location");
    printf("\n4.Insert at end");
    printf("\n5.Insert before an element");
    printf("\n6.Insert after an element");
    printf("\n7.Delete from beginning");
    printf("\n8.Delete from given location");
    printf("\n9.Delete from end");
    printf("\n10.Delete before an element");
    printf("\n11.Delete after an element");
    printf("\n12.Display");
    printf("\n13.Exit");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
 
    switch(ch)
           { int p;
             case 1:do{
                       create();
                       printf("Press 1 to enter and 0 to exit:");
                       scanf("%d",&p);
                      }while(p!=0);
                    break;
             case 2:insert_beg();
                    break;
             case 3:insert_loc();
                    break;       
             case 4:insert_end();
                    break;
             case 5:insert_before();
                    break;
             case 6:insert_after();
                    break;
             case 7:delete_beg();
                    break;
             case 8:delete_loc();
                    break;
             case 9:delete_end();
                    break;
             case 10:delete_before();
                    break;
             case 11:delete_after();
                    break;
             case 12:display();
                    break;
             case 13:exit(0);
             default:printf("\nInvalid choice");
            }
   }
 }
 
 void create()
 {
  struct Node *ptr;
  ptr=(struct Node *)malloc(sizeof(struct Node)); 
  printf("\nEnter data:");
  scanf("%d",&ptr->data);
  ptr->next=NULL;
  ptr->prev=NULL;
  if(start==NULL)
  {
   start=ptr;
   last=ptr;
   ptr->next=NULL;
   ptr->prev=NULL;
  }
  else
  {
   last->next=ptr;
   ptr->next=NULL;
   ptr->prev=last;
   last=ptr;
  }
 }
 
 void insert_beg()
 {
  struct Node *ptr; 
  ptr=(struct Node *)malloc(sizeof(struct Node));
  printf("\nEnter data to be inserted:");
  scanf("%d",&ptr->data);
  ptr->next=NULL;
  ptr->prev=NULL;
  if(start==NULL)
  {
   start=ptr;
   last=ptr;
  }
  else
  {
   ptr->next=start;
   start->prev=ptr;
   start=ptr;
  }
 }
 
  void insert_end()
  {
   struct Node *ptr;
   ptr=(struct Node*)malloc(sizeof(struct Node));
   printf("\nEnter data to be inserted at end:");
   scanf("%d",&ptr->data);
   ptr->next=NULL;
   ptr->prev=NULL;
   if(start=NULL)
   {
    start=ptr;
    last=ptr;
   }
    else
   {
    last->next=ptr;
    ptr->prev=last;
    last=ptr;
   }
  } 

  void insert_loc()
 {
  int loc;
  struct Node *ptr,*t1;
  ptr=(struct Node *)malloc(sizeof(struct Node));
  printf("\nEnter data to be insrted at any location:");
  scanf("%d",&ptr->data);
  printf("\nEnter the location:");
  scanf("%d",&loc);
  if(start==NULL)
  {
   start=ptr;
   last=ptr;
  }
  else if(loc==0)
  {
   ptr->next=start;
   start->prev=ptr;
   start=ptr;
  }
  else
  {
   temp=start;
   for(int i=0;i<loc-1;i++)
   {
    temp=temp->next;
   }
   t1=temp->next;
   ptr->next=t1;
   t1->prev=ptr;
   temp->next=ptr;
   ptr->prev=temp;
  }
 }
 
  void insert_before()
  {
   int x;
   struct Node *ptr,*t1;
   ptr=(struct Node *)malloc(sizeof(struct Node));
   printf("\nEnter element before which data is to be ineserted:");
   scanf("%d",&x);
   printf("\nEnter element to be inserted:");
   scanf("%d",&ptr->data);
   if(start==NULL)
  {
   start=ptr;
   last=ptr;
  }
   else
   {
   temp=start;
   while(temp->data!=x && temp!=NULL)
   {
    t1=temp;
    temp=temp->next;
   }
    if(temp==NULL)
    printf("\nList is empty");
    else
    {
     ptr->next=temp;
     temp->prev=ptr;
     t1->next=ptr;
     ptr->prev=t1;
    }
   } 
  }
  
  void insert_after()
  {
   int x;
   struct Node *ptr,*t1;
   ptr=(struct Node *)malloc(sizeof(struct Node));
   printf("\nEnter element before which data is to be inserted:");
   scanf("%d",&x);
   printf("\nEnter element to be inserted:");
   scanf("%d",&ptr->data);
   if(start==NULL)
  {
   start=ptr;
   last=ptr;
  }
   else
  {
   temp=start;
   while(temp->data!=x && temp!=NULL)
   {
    t1=temp->next;
    temp=temp->next;
   }
    if(temp==NULL)
    printf("\nList is empty");
    else
    {
     ptr->next=temp->next;
     t1->prev=ptr;
     temp->next=ptr;
     ptr->prev=temp;
   }
  }
 }
    
 
  void delete_beg()
 {
  if(start==NULL)
  printf("\nList is empty");
  else if(start->next==NULL)
  {
   temp=start;
   free(temp);
   last=start=NULL;
  }
  else
  {
   temp=start;
   start=start->next;
   free(temp);
   start->prev=NULL;
  }
 }
  
 void delete_end()
 {
  if(start==NULL)
  printf("\nlist is empty");
  else if(start->next==NULL)
  {
   temp=start;
   start=start->next;
   free(temp);
   last=start=NULL;
  }
  else
  {
   temp=last;
   last=last->prev;
   free(temp);
   last->next=NULL;
  }
 }
  
  void delete_loc()
  {
   int loc;
   struct Node *t1,*t2;
   printf("\nEnter location from where element is to be deleted:");
   scanf("%d",&loc);
   if(start==NULL)
   printf("\nlist is empty");
   else if(start->next==NULL)
   {
    temp=start;
    start=start->next;
    free(temp);
    last=start=NULL;
   }
   else
   {
    temp=start;
    for(int i=0;i<loc-1;i++)
    {
     temp=temp->next;
    }
     t1=temp->next;
     t2=temp->next->next;
     temp->next=t1->next;
     t2->prev=temp;
     free(t1);
    }
   }
   
  void delete_before()
  {
   int x;
   struct Node *t1,*t2;
   printf("\nEnter element before which data is to be deleted:");
   scanf("%d",&x);
   temp=start;
   while(temp->data!=x && temp!=NULL)
   {
    t2=t1;
    t1=temp;
    temp=temp->next;
   }
    if(temp==NULL)
    printf("\nList is empty");
    else
    {
     t2->next=temp;//or temp->prev
     temp->prev=t2;//or t2->next
     free(t1);
    }
   }
  void delete_after()
  {
   int x;
   struct Node *t1,*t2;
   printf("\nEnter element after which data is to be deleted:");
   scanf("%d",&x);
   temp=start;
   while(temp->data!=x && temp!=NULL)
   {
    temp=temp->next;
   }
    if(temp==NULL)
    printf("\nList is empty");
    else
    {
     t1=temp->next;
     t2=(temp->next)->next;
     temp->next=t2;
     t2->prev=temp;
     free(t1);
    }
   }
     
    
   
  void display()
 {
  struct Node *temp;
  temp=start;
  while(temp!=NULL)
  {
   printf("%d",temp->data);
   temp=temp->next;
  }
 }
  
   
   
                    
  
