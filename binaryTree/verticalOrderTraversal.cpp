
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


vector<vector<int>> verticalOrderTraversal(Node* root){
    if(root == nullptr)return {};

    map<int, vector<int>> mp;   // vertical level , node list of vertical level
    queue<pair<Node*,int>> qu;  //  node adress, vertical level

    qu.push({root,0});

    while (not qu.empty()){
        auto curr= qu.front();
        qu.pop();

        Node* node = curr.first;
        int verticalLevel = curr.second;

        mp[verticalLevel].push_back(node->val);

        if(node->left) qu.push({node->left, verticalLevel-1});
        if(node->right) qu.push({node->right, verticalLevel+1});

        

        
    
    }

    vector<vector<int>> result;
    for (auto ele : mp) {
        result.push_back(ele.second);
    }
    return result;
   

}

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

    vector<vector<int>> ans = verticalOrderTraversal(a);

    for(int i = 0 ; i < ans.size();i++){
        for(int j= 0 ; j<ans[i].size();j++){
            cout << ans[i][j]<<" ";
        } cout<<endl;
    }


    // here we can get the top view or bottom view accordingly


    

    return 0;
}