//Assignment4 , q2
//code:
#include<bits/stdc++.h>
using namespace std;
struct node* newnode(int data);
void printlevel(struct node* root,int level);
int l=0;
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
void levelorder(struct node* root,int level)
{
	if(root==NULL)
		return;
	printlevel(root,level);
	if(level==l)
		{
			l++;
			levelorder(root->left,++level);
			levelorder(root->right,level);
			return;
		}
	else
		return;


}
void printlevel(struct node* root,int level)
{
	if(level==0)
		cout<<root->data<<" ";
	if(root->left!=NULL)
	cout<<root->left->data<<" ";
	if(root->right!=NULL)
	cout<<root->right->data<<" ";
}
void inorder(struct node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void preorder(struct node* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(struct node* root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
struct node* insert(struct node *root,int key)
{
	if(root==NULL)
		{
			root=newnode(key);
			return root;
		}	
	if(key>root->data)
		root->right=insert(root->right,key);
	else 
		root->left=insert(root->left,key);
}
struct  node* search(struct node* root,int key)
{
	if(root==NULL||root->data==key)
		return root;
	else if(root->data<key)
		return search(root->right,key);
	else 
		return search(root->left,key);	
}
struct node* newnode(int data)
{
	struct node* temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
int main()
{
	struct node* root=newnode(15);
	root->left=newnode(4);
	root->right=newnode(21);
	root->left->right=newnode(8);
	root->left->left=newnode(3);
	root->right->left=newnode(20);
	root->right->right=newnode(30);
	insert(root,1000);
	if(search(root,1000)!=NULL)
		cout<<"search sucessful , 1000 found"<<endl;
	inorder(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	levelorder(root,0);
}
//Output:search sucessful , 1000 found
//3 4 8 15 20 21 30 1000 
//15 4 3 8 21 20 30 1000 
//3 8 4 20 1000 30 21 15 
//15 4 21 3 8 20 30 
