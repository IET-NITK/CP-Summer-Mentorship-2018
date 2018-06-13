/*Output:
Preorder Traversal:
5 2 1 4 8 6 10 
Inorder Traversal:
1 2 4 5 6 8 10 
Postorder Traversal:
1 4 2 6 10 8 5 
Levelorder Traversal:
5 2 8 1 4 6 10 
*/
#include <iostream>
#include <queue>
using namespace std;
#define LEFT 1
#define RIGHT 2

struct node {
	int data;
	node* left;
	node* right;
	node(int element): data(element), left(nullptr), right(nullptr) {};
};

class bst {
	private:
			node *root = new node(-1);
			bool state = false; //bst is empty
			void preorder_traverse(node* element);
			void inorder_traverse(node* element);
			void postorder_traverse(node* element);
	public:
			void insert(int element);	
			bool find(int element);
			void preorder_traverse();
			void inorder_traverse();
			void postorder_traverse();
			void levelorder_traverse();
};

void bst::insert(int element) {
	if(state == false) {
		root->data = element;
		state = true;
	}
	else {
		int direction;
		node *t = root, *temp;
		while(t != nullptr) {
			temp = t;
			if(element < t->data) {
				t = t->left;
				direction = LEFT;
			}
			else {
				t = t->right;
				direction = RIGHT;
			}
		}
		node *new_node = new node(element);
		if(direction == LEFT)
			temp->left = new_node;
		else 
			temp->right = new_node;
	}
}

bool bst::find(int element) {
	node *t = root;
	while(t != nullptr) {
		if(element < t->data) {
			t = t->left;
		}
		else if (element > t->data){
			t = t->right;
		}
		else {
			return true;
		}
	}
	return false;
}

void bst::preorder_traverse() {
	preorder_traverse(root);
}

void bst::preorder_traverse(node* element) {
	if(element == nullptr)
		return;
	cout<<element->data<<" ";
	preorder_traverse(element->left);
	preorder_traverse(element->right);
}

void bst::inorder_traverse() {
	inorder_traverse(root);
}

void bst::inorder_traverse(node* element) {
	if(element == nullptr) {
		return;
	}
	inorder_traverse(element->left);
	cout<<element->data<<" ";
	inorder_traverse(element->right);
}

void bst::postorder_traverse() {
	postorder_traverse(root);
}

void bst::postorder_traverse(node* element) {
	if(element == nullptr)
		return;
	postorder_traverse(element->left);
	postorder_traverse(element->right);
	cout<<element->data<<" ";
}

void bst::levelorder_traverse() {
	queue<node*> queue;
	queue.push(root);
	while(!queue.empty()) {
		node* element = queue.front();
		cout<<element->data<<" ";
		queue.pop();
		if(element->left != nullptr)
			queue.push(element->left);
		if(element->right != nullptr)
			queue.push(element->right);
	}
}

/*
      5
	   / \
    2   8
   / \ / \
  1  4 6  10
*/


int main() {
	bst tree;
	tree.insert(5);
	tree.insert(2);
	tree.insert(8);
	tree.insert(1);
	tree.insert(4);
	tree.insert(6);
	tree.insert(10);
	cout<<"Preorder Traversal:"<<endl;
	tree.preorder_traverse();
	cout<<endl;
	cout<<"Inorder Traversal:"<<endl;
	tree.inorder_traverse();
	cout<<endl;
	cout<<"Postorder Traversal:"<<endl;
	tree.postorder_traverse();
	cout<<endl;
	cout<<"Levelorder Traversal:"<<endl;
	tree.levelorder_traverse();
	cout<<endl;
	return 0;
}