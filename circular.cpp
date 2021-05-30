#include<iostream>
#include<stdlib.h>
using namespace std;
struct CCLNode{
  int data;
  struct CCLNode *next;
}*head;
void insertNode(int n)
{
    int data,i;
    struct CCLNode *newnode,*temp;
    if(n<0)
    {
        cout<<"Choice should be greater than 0"<<endl;
    }

        else
        {
            head=(struct CCLNode*)malloc(sizeof(struct CCLNode));
            if(head==NULL)
        {
            cout<<"Unable to allocate memory"<<endl;
        }
        else{
            cout<<"Enter the data of 1st node"<<endl;
            cin>>data;
            head->data=data;
            head->next=head;
            temp=head;
            for(i=2;i<=n;i++)
            {
                newnode=(struct CCLNode*)malloc(sizeof(struct CCLNode));
                cout<<"Enter the data of "<<i<<"node :";
                cin>>data;
                newnode->data=data;
                newnode->next=newnode;
                temp->next=newnode;
                newnode->next=head;
                temp=newnode;
            }
        }
        }

}
void insertAtBeginning(CCLNode **head)
{
    struct CCLNode *newnode,*temp;
    temp=*head;
    int data;
    newnode=(struct CCLNode*)malloc(sizeof(struct CCLNode));
    cout<<"Enter the data to be inserted at the beginning of the node"<<endl;
    cin>>data;
    newnode->data=data;
    newnode->next=newnode;
   while(temp->next!=(*head))
   {
       temp=temp->next;
   }
    temp->next=newnode;
    newnode->next=*head;
    *head=newnode;
}
void insertAtPosition(CCLNode **head)
 {
     int pos,k=1;
     int data;
     cout<<"Enter the position you want to insert"<<endl;
     cin>>pos;
     struct CCLNode *newnode,*p,*q;
     p=*head;
     while(p!=NULL && k<pos)
     {
         k++;
         q=p;
         p=p->next;
     }
     newnode=(struct CCLNode*)malloc(sizeof(struct CCLNode));
     cout<<"Enter the data of inserted node"<<endl;
     cin>>data;
     newnode->data=data;
    newnode->next=q->next;
    q->next=newnode;

 }
 void insertAtLast(CCLNode **head){
     CCLNode *newnode,*temp;
     temp=*head;
     int data;
     newnode=(struct CCLNode*)malloc(sizeof(struct CCLNode));
     cout<<"Enter the data of last node"<<endl;
     cin>>data;
     newnode->data=data;
     newnode->next=newnode;
  do{
        temp=temp->next;
     }while(temp->next!=*head);
     temp->next=newnode;
     newnode->next=*head;

 }
 void  deleteAtBeginning(CCLNode **head)
 {
     CCLNode *p,*temp;
     temp=*head;
     p=*head;
     do{
        p=p->next;
     }while(p->next!=*head);
     p->next=temp->next;
     *head=temp->next;
     cout<<"The deleted data is"<<temp->data<<endl;
     free(temp);

 }
 void deleteAtPosition(CCLNode **head)
 {
     struct CCLNode *p,*q;
     p=*head;
     q=NULL;
     int k=1;int pos;
     cout<<"Enter the position to be deleted:"<<endl;
     cin>>pos;
     while(p!=NULL && k<pos){
        k++;
        q=p;
        p=p->next;
     }
     q->next=p->next;
     free(p);

 }
 void  deleteAtLast( CCLNode **head)
 {
     struct  CCLNode *temp;
     temp=*head;
     do{
        temp=temp->next;
     }while(temp->next->next!=(*head));
     temp->next=*head;
     free(temp);
 }
 int countNode(CCLNode **head){
      struct CCLNode *current;
      int count=0;
    current=*head;
    if(*head==NULL)
        return 0;
    do{
        current=current->next;
        count++;
    }while(current!=(*head));
 cout<<"The count of node is "<<count<<endl;
 }
int display()
{
    struct CCLNode *current;
    current=head;
    if(head==NULL)
        return 0;
    do{
        cout<<current->data<<"->";
        current=current->next;
    }while(current!=head);
 cout<<head->data<<endl;
}
int main()
{
    int n;

    cout<<"Enter the value of n:"<<endl;
    cin>>n;
    insertNode(n);

    while(1){
            cout<<"1.Display"<<endl;
            cout<<"2.Insert at beginning"<<endl;
            cout<<"3.Insert at position"<<endl;
            cout<<"4.Insert at Last"<<endl;
            cout<<"5.Delete at Beginning"<<endl;
            cout<<"6.Delete at a position"<<endl;
            cout<<"7.Delete at Last"<<endl;
            cout<<"8.Count node"<<endl;

           int choice;
           cout<<"Enter choice"<<endl;
           cin>>choice;
    switch(choice){
    case 1:
        display();
        break;

    case 2 :
        insertAtBeginning(&head);
        break;
    case 3:
         insertAtPosition(&head);
         break;
    case 4:
        insertAtLast(&head);
        break;
    case 5:
        deleteAtBeginning(&head);
        break;
    case 6:
        deleteAtPosition(&head);
        break;
    case 7:
        deleteAtLast(&head);
        break;
    case 8:
        countNode(&head);
        break;


    }

    }
}
