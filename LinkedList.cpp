// Author :  PANDIT DEEPESH KUMAR SHARMA (dk30390)
// Topic  :  Append if No duplicates in the Linked List
// Complexity : O(n^2) 
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int id;
    string name;
    string gender;
    node * next;
    node(int _id,string _name,string _gender,node * _next)
    {
        id=_id;
        name = _name;
        gender = _gender;
        next = _next;
    }
};
node * head = NULL;
node * tail = NULL;
node * p = NULL;
node * q = NULL;
void appendifnodup(int id,string name,string gender,node * temp)
{
   node * newnode = new node(id , name , gender , NULL);
   if(head==NULL && tail==NULL)
   {
       head = newnode;
       tail = newnode;
   }
   else
   {
       if(head->id==newnode->id||tail->id==newnode->id)
        return;
       if(head->id>newnode->id)
       {
           newnode->next=head;
           head=newnode;
       }
       else if(tail->id<newnode->id)
       {
           tail->next=newnode;
           tail=newnode;
       }
       else
       {
           p=head->next;
           q=head;
           bool flag=false;
           while(p->id<=newnode->id)
           {
              if(p->id==newnode->id)
              {
                  flag=true;
                  break;
              }
              p=p->next;
              q=q->next;
           }
           if(!flag)
           {
           newnode->next=p;
           q->next=newnode;
           }
       }
   }

}
void display(node * temp)
{
    cout<<"ID Name Gender\n";
    while(temp!=NULL)
    {
        cout<<temp->id<<" "<<temp->name<<" "<<temp->gender<<endl;
        temp=temp->next;
    }
}
int main()
{
    int i,j,id;
    string name,gender,sign="Yes";
    while(sign!="No")
    {
    cout<<"Enter the id\n";
    cin>>id;
    cout<<"Enter the name\n";
    cin>>name;
    cout<<"Enter the gender\n";
    cin>>gender;
    appendifnodup(id,name,gender,head);
    cout<<"Do you want to add details of another student?Type Yes/No\n";
    cin>>sign;
    }
    cout<<"The details of the students are\n";
    display(head);
}
