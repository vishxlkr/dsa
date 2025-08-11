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

Node* searchBST(Node* root, int val){
    if(root == nullptr) return NULL;

    if(root->val == val) return root;
      else if(root->val > val){           // go left
        return searchBST(root->left,val);
    } else if (root->val<val) {
        return searchBST(root->right,val);
    }

}

// here we are returning 



int main(){


    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);
    

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;

    

    

    return 0;
}