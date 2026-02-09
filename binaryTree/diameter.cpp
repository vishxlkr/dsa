#include<bits/stdc++.h>

using namespace std;


class Node {
    public: 
    int val ;
    Node * left ;
    Node * right;

    Node(int val ){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void display (Node * root){
    if(root == NULL) return;

    display(root->left);
    display(root->right);
    cout<<root->val<<" ";
}

int level(Node*root){
    if(root == NULL) return 0;
    return 1 + max(level(root->left), level(root->right));
}

int diameter(Node * root){
    if(root == nullptr) return 0;

    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    return max (level(root->left)+level(root->right), max(leftDiameter, rightDiameter));
}

int main(){


    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);
    Node* h = new Node(8);

    

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    d->left=h;

    cout<<diameter(a);

    

    return 0;
}