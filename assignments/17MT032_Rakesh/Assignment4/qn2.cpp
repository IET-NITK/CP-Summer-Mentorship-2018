/*     OUTPUT :-
Preorder Traversal:
54 22 12 10 43 81 61 
Inorder Traversal:
10 12 22 43 54 61 81 
Postorder Traversal:
10 12 43 22 61 81 54 
Levelorder Traversal:
54 22 81 12 43 61 10    */

// SOURCE CODE:- 

#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int element): data(element), left(NULL), right(NULL) {};
};

class bin_search_tree {
    private:
            node *root = new node(-1);
            bool state = false; //bin_search_tree is empty
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

void bin_search_tree::insert(int element) {
    if(state == false) {
        root->data = element;
        state = true;
    }
    else {
        int direction;
        node *t = root, *temp;
        while(t != NULL) {
            temp = t;
            if(element < t->data) {
                t = t->left;
                direction = 1;
            }
            else {
                t = t->right;
                direction = 2;
            }
        }
        node *new_node = new node(element);
        if(direction == 1)
            temp->left = new_node;
        else 
            temp->right = new_node;
    }
}

bool bin_search_tree::find(int element) {
    node *t = root;
    while(t != NULL) {
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

void bin_search_tree::preorder_traverse() {
    preorder_traverse(root);
}

void bin_search_tree::preorder_traverse(node* element) {
    if(element == NULL)
        return;
    cout<<element->data<<" ";
    preorder_traverse(element->left);
    preorder_traverse(element->right);
}

void bin_search_tree::inorder_traverse() {
    inorder_traverse(root);
}

void bin_search_tree::inorder_traverse(node* element) {
    if(element == NULL) {
        return;
    }
    inorder_traverse(element->left);
    cout<<element->data<<" ";
    inorder_traverse(element->right);
}

void bin_search_tree::postorder_traverse() {
    postorder_traverse(root);
}

void bin_search_tree::postorder_traverse(node* element) {
    if(element == NULL)
        return;
    postorder_traverse(element->left);
    postorder_traverse(element->right);
    cout<<element->data<<" ";
}

void bin_search_tree::levelorder_traverse() {
    queue<node*> queue;
    queue.push(root);
    while(!queue.empty()) {
        node* element = queue.front();
        cout<<element->data<<" ";
        queue.pop();
        if(element->left != NULL)
            queue.push(element->left);
        if(element->right != NULL)
            queue.push(element->right);
    }
}

int main() {
    bin_search_tree t;
    t.insert(54);
    t.insert(22);
    t.insert(81);
    t.insert(12);
    t.insert(43);
    t.insert(61);
    t.insert(10);
    cout<<"Preorder Traversal:\n";
    t.preorder_traverse();
    cout<<endl;
    cout<<"Inorder Traversal:\n";
    t.inorder_traverse();
    cout<<endl;
    cout<<"Postorder Traversal:\n";
    t.postorder_traverse();
    cout<<endl;
    cout<<"Levelorder Traversal:\n";
    t.levelorder_traverse();
    cout<<"\n";
    return 0;
}
