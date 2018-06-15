#include<bits/stdc++.h>
using namespace std;

 typedef long long ll;
 #define pb push_back
 #define f(i,a,n) for(ll i=0;i<n;i++)
 #define mod 1000000007
 #define mp make_pair

struct node
{
  int key;
  struct node *left,*right;
};

//newnode value initialization
struct node *newNode(int element)
{
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->key=element;
  temp->left=temp->right=NULL;
  return temp;
};

//insertion
struct node* insert(struct node* temp,int element)
{
  if(temp==NULL) return newNode(element);
  if(element < temp->key)
  temp->left = insert(temp->left , element);

  else if(element>temp->key)
  temp->right=insert(temp->right , element);

  return temp;

}

//search
struct node* search( node *temp , int element)
{

  while(temp!=NULL)
  {
  if(temp->key==element) return temp;
  if(temp->right==NULL && temp->left==NULL) return NULL;
  else if(temp->key > element )  {temp=temp->left; continue;}
  else {temp=temp->right; }
  }

}

//preorder
void preorder(node *temp)
{

  stack< node* > s;
  s.push(temp);
  while(s.empty()!=1)
  {
    temp=s.top();
    s.pop();
    while(temp!=NULL)
    {
      cout<<temp->key<<"\t";
      s.push(temp->right);
      temp=temp->left;
    }
  }
}

//Inorder
void inorder( node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \t", root->key);
        inorder(root->right);
    }
}

//postorder
void postorder(node *temp)
{
  if(temp==NULL) return ;
  postorder(temp->left);
  postorder(temp->right);
  cout<<temp->key<<"\t";
}

void levelorder(node *temp)
{
  queue< node* > q;
  q.push(temp);
  while(!q.empty())
  {
    temp=q.front();
    q.pop();
    cout<<temp->key<<"\t";
       if(temp->left)
    q.push(temp->left);
    if(temp->right)
    q.push(temp->right);
  }
}





 int main()
 {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  struct node* root=NULL;
  root=insert(root,50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    int element;

    //searching
    cin>>element;
    node* temp=search(root , element);
    if(temp) cout<<"found "<<element<<endl;
    else cout<<"not found"<<endl;

    //transversal

    //preorder
    cout<<"preorder transversal:";
    preorder(root);
    cout<<endl;


    //postorder
    cout<<"postorder transversal:";
    postorder(root);
    cout<<endl;

    //level order
    cout<<"level order transversal:";
    levelorder(root);
    cout<<endl;

     //Inorder
    cout<<"Inorder transversal:";
    inorder(root);



 }
