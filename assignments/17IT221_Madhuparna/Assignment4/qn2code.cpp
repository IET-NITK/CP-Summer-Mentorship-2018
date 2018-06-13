Binary Search TREE
CODE:
#include<bits/stdc++.h>
using namespace std;
struct node{
    int key;

    struct node *left;
    struct node *right;
};
  struct node *root=NULL;
struct node *insert(struct node *check,int val)
{
if(check==NULL)
{//cout<<"yes"<<endl;
struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key=val;
    temp->left=NULL;
    temp->right=NULL;
    check=temp;
    return temp;

}
else{
    if(val<check->key)
        check->left= insert(check->left,val);
    else if(val>check->key)
        check->right= insert(check->right,val);
    else
        return check;
}

return check;

}
int searchbst(int val,struct node*ch)
{
     if((ch->key)==val)
        {

            return 1;
        }
        else if(val<ch->key)
        {
            if(ch->left!=NULL)
            return searchbst(val,ch->left);
            else
                return -1;
        }
        else{
            if(ch->right!=NULL)
               return searchbst(val,ch->right);
            else
                return -1;
        }


   return 0;
}
void Preorder(struct node* node)
{
     if (node == NULL)
          return;

     cout<<node->key<<"->";

     Preorder(node->left);

     Preorder(node->right);
}
void Inorder(struct node* node)
{
     if (node == NULL)
          return;

     Inorder(node->left);

     cout<<node->key<<"->";

     Inorder(node->right);
}
void Postorder(struct node* node)
{
     if (node == NULL)
        return;


     Postorder(node->left);


     Postorder(node->right);

    cout<<node->key<<"->";
}
int height(struct node* nd)
{
    if (nd==NULL)
        return 0;
    else
    {

        int lh = height(nd->left);
        int rh = height(nd->right);


        if (lh > rh)
            return(lh+1);
        else
            return(rh+1);
    }
}
void Level(struct node* nd, int l)
{
    if (nd== NULL)
        return;
    if (l == 1)
      cout<<nd->key<<"->";
    else if (l > 1)
    {
        Level(nd->left, l-1);
        Level(nd->right, l-1);
    }
}
void Levelorder(struct node* nd)
{

    int h=height(nd);
    for(int i=1;i<=h;++i)
    {
        Level(nd,i);

    }
}
int main()
{int f=0;
    while(1)
    {int choice;
    cout<<"Enter 1 to add nodes to the tree"<<endl;
    cout<<"Enter 2 to search for a node in the tree"<<endl;
    cout<<"Enter 3 to print the tree"<<endl;
    cout<<"Enter 4 to exit"<<endl;
    cin>>choice;
     int t=0;
     switch(choice)
     {
         case 1:{int val;
                    cout<<"Enter node value"<<endl;
                 cin>>val;
                 if(root==NULL)
                 root=insert(root,val);
                 else
                    insert(root,val);
                 //cout<<root->key<<endl;
                 cout<<"Done"<<endl;

                 break;
         }
         case 2:{
             int element;
             cout<<"Enter search element"<<endl;
             cin>>element;
             if(searchbst(element,root)==1)
                cout<<"Element found!"<<endl;
             else
                cout<<"Not found"<<endl;
            break;
         }
         case 3:{
             cout<<"Preorder traversal:"<<endl;
             Preorder(root);
             cout<<endl;
             cout<<"Postorder traversal:"<<endl;
             Postorder(root);
             cout<<endl;
             cout<<"Inorder Traversal:"<<endl;
             Inorder(root);
             cout<<endl;
             cout<<"Level order Traversal"<<endl;
             Levelorder(root);
             cout<<endl;

             break;

         }
         case 4:{
             f=1;
             break;
         }
     }
     if(f==1)
         break;
    }


}
