#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
    int val;
    Node*left;
    Node*right;

    Node(int val){
        this->val = val;
        this->left= NULL;
        this->right=NULL;
    }
};

Node* contructBinaryTree(vector<int>&arr){
    queue<Node*> qu;
    Node* root = new Node(arr[0]);

    qu.push(root);
    int i = 1; 
    int j = 2;
    while(not qu.empty()){
        Node*curr = qu.front();
        qu.pop();

        Node*l = new Node(arr[i]);
        Node*r = new Node(arr[j]);

        curr->left = l;
        curr->right = r;

        i +=2;
        j+=2;

    }

    return root;
}




int main(){

    vector<int> arr = {1,2 ,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9,INT_MIN};



    return 0;
}