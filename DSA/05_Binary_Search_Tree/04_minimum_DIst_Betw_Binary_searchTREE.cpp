#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to insert a new node in the BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Inorder traversal to get the nodes in sorted order
void inorder(TreeNode* root, vector<int>& nodes) {
    if (root == NULL) return;
    inorder(root->left, nodes);
    nodes.push_back(root->val);
    inorder(root->right, nodes);
}

// Function to find the minimum difference between nodes
int minDiffInBST(TreeNode* root) {
    vector<int> nodes;
    inorder(root, nodes);

    int minDiff = INT_MAX;
    for (size_t i = 1; i < nodes.size(); ++i) {
        minDiff = min(minDiff, nodes[i] - nodes[i - 1]);
    }
    return minDiff;
}

int main() {
    TreeNode* root = NULL;
    int n, val;
    
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter the values of nodes: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        root = insert(root, val);
    }
    
    int result = minDiffInBST(root);
    cout << "Minimum distance between BST nodes: " << result << endl;
    
    return 0;
}
