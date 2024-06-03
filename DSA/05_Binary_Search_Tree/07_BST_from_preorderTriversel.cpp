#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Structure for a tree node
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to initiate BST construction from preorder traversal
    TreeNode* constructBSTFromPreorder(vector<int>& preorder) {
        int index = 0;
        return construct(preorder, index, INT_MIN, INT_MAX);
    }

private:
    // Helper function to construct the BST
    TreeNode* construct(vector<int>& preorder, int& index, int min, int max) {
        // Base case: if index is out of bounds or value is not in the range [min, max]
        if (index >= preorder.size() || preorder[index] < min || preorder[index] > max) {
            return NULL;
        }

        // Create a new node with the current value and increment index
        TreeNode* root = new TreeNode(preorder[index++]);

        // Recursively construct the left and right subtrees
        root->left = construct(preorder, index, min, root->val);
        root->right = construct(preorder, index, root->val, max);

        return root;
    }
};

// Utility function to print the inorder traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Solution sol;
    TreeNode* root = sol.constructBSTFromPreorder(preorder);

    // Print the inorder traversal of the constructed BST
    inorderTraversal(root);
    cout << endl;

    // Free allocated memory (optional for this example)
    // Freeing the entire tree is left as an exercise to the reader.
    return 0;
}
