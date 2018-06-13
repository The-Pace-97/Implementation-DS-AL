// Author :  PANDIT DEEPESH KUMAR SHARMA (dk30390)
// Topic  :  Reverse the Linked list
// Complexity : O(n) 
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
void append(int id,string name , string gender)
{
    node * newnode = new node(id , name , gender , NULL);
    if(head==NULL && tail==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {   tail->next=newnode;
        tail=newnode;
    }
}
node * head1 = NULL;
node * tail1 = NULL;
void reverse(node * temp)
{
    while(temp!=NULL)
    {
        node * newnode = new node(temp->id,temp->name,temp->gender,NULL);
        if(tail1==NULL && head1==NULL)
        {
            tail1=newnode;
            tail->next=NULL;
            head1=tail1;
        }
        else
        {
            newnode->next=head1;
            head1=newnode;
        }
        temp=temp->next;
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
    append(id,name,gender);
    cout<<"Do you want to add details of another student?Type Yes/No\n";
    cin>>sign;
    }

    cout<<"The details of the students are\n";
    display(head);
    reverse(head);
    cout<<"The details of the students after reversing are\n";
    display(head1);

}
