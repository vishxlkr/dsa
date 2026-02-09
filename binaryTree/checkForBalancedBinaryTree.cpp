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



int checkHeight(Node* root){
    if(root == NULL) return 0;

    int leftHeight = checkHeight(root->left);
    if(leftHeight==-1) return -1;

    int rightHeight = checkHeight(root->right);
    if(rightHeight ==-1) return -1;

    if(abs(leftHeight-rightHeight)>1) return -1;

    return max(leftHeight,rightHeight)+1;
}


// balanced trees => diff(left subtree and right sub tree ) <= 1;


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
    d->left=f;
    d->right=g;



    if(checkHeight(a) !=-1) cout<<"tree is balanced"<<"\n";
    else cout<<"tree is not balancned"<<"\n";




    

    return 0;
}