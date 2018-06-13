// Author :  PANDIT DEEPESH KUMAR SHARMA (dk30390)
// Topic  :  Find the middle Term of the linked list
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
void append(int id , string name , string gender)
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
int count(node * temp)
{
     int ret=0;
     while(temp!=NULL)
     {
        ret++;
        temp=temp->next;
     }
     return ret;
}
node * findmid(int ans,node * temp)
{
    int ret=0;
    while(temp!=NULL)
    {
        ret++;
        if(ret==ans)
            break;
        temp=temp->next;
    }
     return temp;
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
    cout<<"The middle student in the list is\n";
    cout<<"ID Name Gender\n";
    node * show = findmid((count(head)+1)/2,head);
    cout<<show->id<<" "<<show->name<<" "<<show->gender<<endl;
}
