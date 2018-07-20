#include<bits/stdc++.h>
using namespace std;

struct Node{
			int data;
			struct Node*left;
			struct Node*right;
}*root;

struct Node * newnode(int element)
    {
        struct Node * temp=(Node * )malloc(sizeof(Node));
        temp->data=element;
        temp->left=temp->right=NULL;
        return temp;
    }
    
struct Node* insert(struct Node* Node, int data)
{
    if (Node == NULL) return newnode(data);
 
    if (data < Node->data)
        Node->left  = insert(Node->left, data);
    else if (data > Node->data)
        Node->right = insert(Node->right, data);   
 	return Node;
}

struct Node* search(struct Node* root, int data)
{
    if (root == NULL || root->data == data)
       return root;
    
     if (root->data < data)
       return search(root->right, data);
 
     return search(root->left, data);
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
    
void preorder(struct Node *root)
{
    if (root != NULL)
    {
		printf("%d ", root->data);
		preorder(root->left);
        preorder(root->right);
    }
}    

void postorder(struct Node *root)
{
    if (root != NULL)
    {
		postorder(root->left);
        postorder(root->right);
		printf("%d ", root->data);
		
    }
}    
void levelorder(struct Node *n)
{
		 // Create a queue
   queue<Node*> q;

   // Push the root
   q.push(n);

   while ( ! q.empty() )
   {
       // Dequeue a node from front
       Node* v = q.front();
       cout << v->data << " ";

       // Enqueue the left children
       if ( v->left != NULL )
            q.push(v->left);

       // Enqueue the right children
       if ( v->right != NULL )
            q.push(v->right);

       // Pop the visited node
       q.pop();
   }
}    
    
int main()
{
	struct Node *root = NULL;
    root = insert(root, 40);
    insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 60);
    insert(root, 50);
    insert(root, 70);
	int c,x=1;
	int val,val2;
while(x)
{
cout<<"enter choice";
cout<<"\n 1.insertion \n 2.search \n 3.traversal output\n";
cin>>c;
switch(c)
{
	case 1: cout<<"Enter the element to be inserted:";
			cin>>val;
			insert(root,val);
			 break;
	
	case 2: cout<<"enter data to be searched:";
			cin>>val2;
			search(root,val2); 
			break;
	
	case 3: 
			{ cout<<"Preorder:";
			preorder(root); 
			cout<<"\n";
			cout<<"Postorder:";
			postorder(root);
			cout<<"\n";
			cout<<"Inorder:";
			 inorder(root);
				cout<<"\n";
				cout<<"levelorder:";
			levelorder(root); 
			cout<<"\n";
			
				break;}
			

}

cout<<"one more time?(1/0)";
cin>>x;
}
}

