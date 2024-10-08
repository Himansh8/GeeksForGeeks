/*Given a linked list. Print all the elements of the linked list.

Note :- End of Line is handled by driver code itself. You just have to end with a single space.*/


//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    
}*start;

void insert();
void display(struct Node *head);
//struct Node *start;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
      start=NULL;
      insert();
      display(start);
      printf("\n");
    }
    return 0;

}


 void insert()
 {
     int n,value,i;
     scanf("%d",&n);
     struct Node *temp;
     for(i=0;i<n;i++)
     {
         scanf("%d",&value);
         if(i==0)
         {
              start=(struct Node *) malloc( sizeof(struct Node) );
              start->data=value;
              start->next=NULL;
              temp=start;
              continue;
         }
         else
         {
             temp->next= (struct Node *) malloc( sizeof(struct Node) );
             temp=temp->next;
             temp->data=value;
             temp->next=NULL;
         }
     }
 }

// } Driver Code Ends




/*
  Print elements of a linked list on console 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
     Node(int x){
         data = x;
         next  NULL;
     }
  }*/

void display(struct Node *head)
{
   //add code here
   if(start==NULL){
       printf("Node is empty");
   }
   else{
   while(head!=NULL){
       printf("%d ",head->data);
       head=head->next;
   }
       
   }
}