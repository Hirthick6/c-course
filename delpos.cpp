#include<iostream>
using namespace std;

class node
{
  public:
  int data;
  node* next;
  node*prev;
};
node*delpos(node*h,int pos)
{
    int count=0;
    node*curr=h;


    node*t=curr->next;


if(pos==1)
{
h=curr->next;
delete(curr);
return h;

}
while(curr!=NULL && curr->data!=pos)
{
    count++;
    if(count==pos-1)
    {
        curr->next=t->next->prev;
        t->next->prev=curr;
        delete(t);
        return h;
    }
    t=t->next;
    curr=curr->next;
   if(t->next==NULL)
    {
        curr->next=NULL;
        delete(t);

        return h;
    }
}
}
void display(node*h)
{
    while(h!=NULL)
    {
        cout<<h->data<<"->";
         h=h->next;

    }
    cout<<"NULL";
}


int main()
{
    node*head=NULL;
    node*second=NULL;
    node*third=NULL;
    node*fourth=NULL;
    head=new node();
    second=new node();
    third=new node();
    fourth=new node();
    head->data=1;
    head->next=second;
    head->prev=NULL;
    second->data=2;
    second->next=third;
    second->prev=head;
    third->data=3;
    third->next=fourth;
    third->prev=second;
    fourth->data=4;
    fourth->next=NULL;
    fourth->prev=third;
    display(head);
    cout<<"\nafter deleting\n";
    head=delpos(head,4);
    display(head);
}


