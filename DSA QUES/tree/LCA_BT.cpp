#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Base case: if root is null, return null
    if (root == NULL) {
        return NULL;
    }
    
    // If either p or q is the root, then root is the LCA
    if (root == p || root == q) {
        return root;
    }

    // Recur for left and right subtrees
    TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

    // If both left and right subtrees return non-null, it means p and q are found in different subtrees
    // so root is their LCA
    if (leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    // Otherwise, return the non-null subtree (either left or right)
    if (leftLCA != NULL) {
        return leftLCA;
    } else {
        return rightLCA;
    }
}

// Driver code to test the above function
int main() {
    // Construct the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Test the lowestCommonAncestor function
    TreeNode* p = root->left->left; // Node 4
    TreeNode* q = root->left->right; // Node 5
    TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca != NULL)
        cout << "LCA of " << p->data << " and " << q->data << " is " << lca->data << endl;
    else
        cout << "LCA does not exist." << endl;

    p = root->left->left; // Node 4
    q = root->right->left; // Node 6
    lca = lowestCommonAncestor(root, p, q);
    if (lca != NULL)
        cout << "LCA of " << p->data << " and " << q->data << " is " << lca->data << endl;
    else
        cout << "LCA does not exist." << endl;

    return 0;
}
