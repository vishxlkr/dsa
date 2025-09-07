#include <iostream>
#include <vector>
#include <algorithm>

// Assuming TreeNode structure is defined elsewhere, like this:
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to recursively build the tree
TreeNode* build(std::vector<int>& preorder, int prelo, int prehi, std::vector<int>& inorder, int inlo, int inhi) {
    if (prelo > prehi) {
        return nullptr;
    }

    if (prelo == prehi) {
        return new TreeNode(preorder[prelo]);
    }

    TreeNode* root = new TreeNode(preorder[prelo]);

    int i = inlo;
    while (i <= inhi) {
        if (inorder[i] == preorder[prelo]) {
            break;
        }
        i++;
    }

    int left_count = i - inlo;
    int right_count = inhi - i;

    root->left = build(preorder, prelo + 1, prelo + left_count, inorder, inlo, inlo + left_count - 1);
    root->right = build(preorder, prehi - right_count + 1, prehi, inorder, inhi - right_count + 1, inhi);

    return root;
}

// Main function to initiate the tree building
TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    int n = preorder.size();
    if (n == 0) {
        return nullptr;
    }
    return build(preorder, 0, n - 1, inorder, 0, n - 1);
}

int main() {
    // Example usage:
    // Preorder traversal: {3, 9, 20, 15, 7}
    // Inorder traversal: {9, 3, 15, 20, 7}
    std::vector<int> preorder = {3, 9, 20, 15, 7};
    std::vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = buildTree(preorder, inorder);

    // You can add code here to verify the constructed tree,
    // for example, by performing a traversal and printing the values.

    std::cout << "Tree built successfully!" << std::endl;
    // Clean up memory (optional, for this example)
    // deleteTree(root);
    
    return 0;
}