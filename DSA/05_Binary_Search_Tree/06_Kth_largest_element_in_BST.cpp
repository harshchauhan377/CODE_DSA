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

// Helper function to perform inorder traversal and calculate the sum of the first k elements
void inorder(TreeNode* root, int& k, int& sum) {
        if (!root || k <= 0) {
            return;
        }
        
        inorder(root->right, k, sum); // Traverse right subtree first
        
        if (k > 0) {
            sum = root->val; // Update sum to current node's data
            k--; // Decrement k
        }
        
        inorder(root->left, k, sum); // Traverse left subtree
}

// Function to find the sum of the k smallest elements in BST
int kthLargest(TreeNode* root, int k) {
        int sum = 0; // To hold the k-th largest element
        inorder(root, k, sum); // Start the reverse in-order traversal
        return sum;
    }

int main() {
    TreeNode* root = NULL;
    int n, val, k;
    
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter the values of nodes: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "Enter the value of k: ";
    cin >> k;

    if (k <= 0) {
        cout << "Value of k must be positive." << endl;
        return 1;
    }

    int result = kthLargest(root, k);
    cout << " largest elements in BST: " << result << endl;

    return 0;
}
