#include<bits/stdc++.h>
using namespace std;





    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };


    bool exist (TreeNode* root , TreeNode* target){
        if(root == nullptr ) return false;

        if(root== target) return true;
        return exist(root->left , target) or exist (root->right , target);
        
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == p or root == q) return root;

        else if(exist(root->left , p) and exist(root->right , q)) return root;
        else if(exist(root->right , p) and exist(root->left , q)) return root;

        //------------------------------------------

        else if(exist(root->left , p) and exist(root->left, q)) {
            return lowestCommonAncestor(root->left , p , q);
        }

        else if(exist(root -> right , p) and exist(root -> right , q) ){
            return lowestCommonAncestor(root->right  , p , q);
        }

        return nullptr;


    }

int main() {

}
        



// here, we first company p,q with root ... if they any of them matches then LCA  will the root because if p,q exist in parent, child connection , then root is the LCA

// if p exist in left sub tree and q exist in right sub tree .. then curr root is the answer

// similarly q in left and p in right

// ----------------

// if both exist in left sub tree -> call next function ie. go to left
// if both exist in right sub tree -> call next function ie. go to right



