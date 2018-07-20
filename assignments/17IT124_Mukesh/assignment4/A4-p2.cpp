/*
Sample Output

Order of Insretion :
9
3
30
4
1
12
22
14
18
16
Level Traversal :
9
3
30
1
4
12
22
14
18
16
Pre Order Traversal :
9
3
1
4
30
12
22
14
18
16
In Order Traversal :
1
3
4
9
12
14
16
18
22
30
Post Order Traversal :
1
4
3
16
18
14
22
12
30
9
*/




#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class node
{
    public:
    int element;
    node *left;
    node*right;
    node(int data)
    {
        element=data;
        left=right=NULL;
    }
};
node *root=NULL;

void insert(int data)
{
    node *temp1=new node(data);
    if(root==NULL){
        root=temp1;
        return;
    }
    int direction;
    node *t = root, *temp;
    while(t != nullptr) {
        temp = t;
        if(data < t->element) {
            t = t->left;
            direction = 1;
        }
        else {
            t = t->right;
            direction = 2;
        }
    }
    node *new_node = new node(data);
    if(direction == 1)
        temp->left = new_node;
    else
        temp->right = new_node;
}

node *Search(int data)
{
    node *t=root;
    while (t!=NULL)
    {
        if(data > t->element)
            t=t->right;
        else if(t->element > data)
            t=t->left;
        else
            return t;
    }
    return NULL;
}
void level_traversal()
{
    queue<node*> q1;
    q1.push(root);
    node *temp1 = new node(0);
    while(!q1.empty())
    {
        temp1=q1.front();
        cout<<temp1->element<<endl;
        q1.pop();
        if(temp1->left != NULL)
            q1.push(temp1->left);
        if(temp1->right != NULL)
            q1.push(temp1->right);
    }
}
void preorder_traversal(node *t)
{
    if(t == NULL)
        return;
    cout<<t->element<<endl;
    preorder_traversal(t->left);
    preorder_traversal(t->right);
}
void inorder_traversal(node *t)
{
    if(t == NULL)
        return;
    inorder_traversal(t->left);
    cout<<t->element<<endl;
    inorder_traversal(t->right);
}
void postorder_traversal(node *t)
{
    if(t == NULL)
        return;
    postorder_traversal(t->left);
    postorder_traversal(t->right);
    cout<<t->element<<endl;
}
int main()
{
    cout<<"Order of Insretion : "<<endl;
    for(int i=0;i<10;i++)
    {
        int ele=rand()%32;
        insert(ele);

        cout<<ele<<endl;
    }
    cout<<"Level Traversal : "<<endl;
        level_traversal();
    cout<<"Pre Order Traversal : "<<endl;
        preorder_traversal(root);
    cout<<"In Order Traversal : "<<endl;
        inorder_traversal(root);
    cout<<"Post Order Traversal : "<<endl;
        postorder_traversal(root);
}