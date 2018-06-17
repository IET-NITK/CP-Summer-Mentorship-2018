#include<stdio.h>
#include<stdlib.h>
struct node
{
    int key;
    struct node *left, *right;
};
struct node* search(struct node* root, int key)
{
    if (root==NULL||root->key == key)
       return root; 
    if (root->key < key)
       return search(root->right, key);
    return search(root->left, key);
}

struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
	printf("%d \n", root->key);        
	preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
	postorder(root->left);
        postorder(root->right);
	printf("%d \n", root->key); 
    }
}
void levell(struct node *root,int level)
{if(root==NULL)
return ;
if(level==1)
printf("%d\n",root->key);
else if(level>1)
{levell(root->left,level-1);
levell(root->right,level-1);}}
void levelorder(struct node *root)
{int h=3;
for(int i=1;i<=h;i++)
levell(root,i);
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL) return newNode(key);
    if (key < node->key)
	node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
    return node;
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
printf("inorder\n");    
inorder(root);
printf("preorder\n");
preorder(root);
printf("postorder\n");
postorder(root);
printf("levelorder\n");
levelorder(root);
    return 0;
}
/*output:
inorder
20
30
40
50
60
70
80
preorder
50
30
20
40
70
60
80
postorder
20
40
30
60
80
70
50
levelorder
50
30
70
20
40
60
80*/

