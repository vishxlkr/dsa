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




 class Solution {
public:

    void helper(TreeNode* root , string s , vector<string> & ans){
        if(root == nullptr) return;

         string a = to_string(root->val);

         s  = s + a;

        if(root->left == nullptr and root->right == nullptr) {
            ans.push_back(s);
            return;
        }

        helper(root->left , s + "->" , ans);
        helper(root->right , s + "->" , ans);

        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string > ans ;

        string s = "";

        helper(root, s , ans);

        return ans;
    }
};



// what we are doing here
// here we are going to each node and then adding it the string  .... and then if we found ourself that we are present on the last node then we are saving that answer in the vector