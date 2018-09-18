#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * left ;
    struct node * right ;
};
struct node * get(int _data)
{
    struct node * newnode =  (struct node *)malloc(sizeof(struct node));
    newnode->data = _data ;
    newnode->left = NULL ;
    newnode->right = NULL ;
    return newnode ;
};
struct node * search(struct node * node ,int key)
{

    if(node==NULL) return NULL ;

    if(node->data == key)
        return node ;

    if(key<node->data) return search(node->left ,key);
    else return search(node->right,key);
};
struct node * insert(struct node * node , int key)
{
    if(node==NULL) return get(key);
    if(key<=node->data) node->left = insert(node->left , key);
    else node->right = insert(node->right , key );
    return node ;
};
struct node * findmin(struct node * node)
{   if(node==NULL) return NULL;
    if(node->left==NULL) return node ;
    return findmin(node->left);
};
struct node * del(struct node * node , int key)
{
    if(node==NULL) return NULL ;
    struct node * temp  = NULL ;

    if(key<node->data) node->left=del(node->left,key);
    else if(key>node->data) node->right=del(node->right,key);
    else if(node->left && node->right)          // case : 3
    {
        temp = findmin(node->right) ;
        node->data = temp->data ;
        node->right=del(node->right,node->data);
    }
    else
    {
        temp=node;
        if(node->left==NULL)                    // case : 1 , 2
         node=node->right ;
        else if(node->right==NULL)
        node=node->left;
        free(temp);
    }

    return node ;

};
void inorder(struct node * node)
{   if(node==NULL) return;
    inorder(node->left);
    printf("%d ",node->data);
    inorder(node->right);
};
int main()
{
    int i,j,k,l,n,m,t,q,ch;
    printf("Enter Testcase : \n");
    scanf("%d",&t);
    while(t--)
    {   printf("Enter the number of nodes in BST : \n");
        scanf("%d",&n);
        struct node * root = NULL ;
        printf("Enter details of each node : \n");
        for(i=1;i<=n;i++)
        {
            scanf("%d",&k);
            root = insert(root,k);
        }
        inorder(root);printf("\n");
        printf("Enter number of queries : \n");
        scanf("%d",&q);
        while(q--)
        {
            printf("Press search/insert/delete ? 0/1/2 :\n");

            scanf("%d",&ch);

            printf("Enter Data:\n");

            scanf("%d",&l);
            if(ch==0)
            {
                  struct node * temp = search(root,l);
                  if(temp==NULL) printf("Not Found\n");
                  else printf("found\n");
            }
            else if(ch==1)
            {
               root = insert(root,l);
               inorder(root);printf("\n");
            }
            else if(ch==2)
            {
                root = del(root,l);
                inorder(root);printf("\n");
            }
        }
    }
}
