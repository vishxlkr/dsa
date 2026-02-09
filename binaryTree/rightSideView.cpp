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
    if(root == nullptr)return 0;
    return 1 + max(level(root->left), level(root->right));
}

void view(Node*root , vector<int> &ans, int level){
    if(root == nullptr) return ;

    ans[level] = root->val;
    view(root -> right, ans , level+1);
    view (root->left, ans , level+1);


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
    Node* i = new Node(9);
    

    // a->left=b;
    // a->right=c;
    // b->left=d;
    // b->right=e;
    // c->left=f;
    // c->right=g;

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    d->left=h;
    h->right=i;

    int n  = level(a);
    vector<int> ans (n+1);

   
    
    view(a,ans,0);

    for(int i = 0; i <n ; i++){
        cout<<ans[i]<<" ";
    }



    

    return 0;
}