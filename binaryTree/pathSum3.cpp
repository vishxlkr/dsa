#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode* root, long long sum, int& count) {
    if (root == nullptr) return;

    if ((long long)(root->val) == sum) {
        count++;
    }

    helper(root->left, sum - (long long)(root->val), count);
    helper(root->right, sum - (long long)(root->val), count);
}

int pathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return 0;

    int count = 0;
    helper(root, (long long)(targetSum), count);            // this will find if pathsum is possible for a particular node or not

    // recursively check paths starting from left and right children too
    count += pathSum(root->left, targetSum);
    count += pathSum(root->right, targetSum);

    return count;
}

int main() {
    /*
         Example Tree:
               10
              /  \
             5   -3
            / \     \
           3   2     11
          / \    \
         3  -2    1
    Target = 8
    Expected answer = 3
    Paths: [5,3], [5,2,1], [-3,11]
    */

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    int targetSum = 8;
    cout << "Number of paths with sum " << targetSum << " = " 
         << pathSum(root, targetSum) << endl;

    return 0;
}
