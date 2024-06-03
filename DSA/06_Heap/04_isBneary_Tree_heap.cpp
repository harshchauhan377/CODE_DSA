#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to count the number of nodes in the tree
    int CountNode(Node* tree) {
        if (!tree) return 0; // Corrected to return 0 instead of NULL
        
        int ans = 1 + CountNode(tree->left) + CountNode(tree->right);
        return ans;
    }
    
    // Function to check if the tree is a Complete Binary Tree
    bool CBT(Node* tree, int index, int totalCount) {
        if (!tree) return true;
        
        if (index >= totalCount) {
            return false;
        }
        
        bool left = CBT(tree->left, 2 * index + 1, totalCount);
        bool right = CBT(tree->right, 2 * index + 2, totalCount);
        return left && right;
    }
    
    // Function to check the max-heap property
    bool maxOrder(Node* tree) {
        if (!tree->left && !tree->right) {
            return true;
        }
        
        if (!tree->right) {
            return (tree->data > tree->left->data);
        }
        
        bool left = maxOrder(tree->left);
        bool right = maxOrder(tree->right);
        
        return left && right && (tree->data > tree->left->data && tree->data > tree->right->data);
    }
  
    // Main function to check if the binary tree is a max-heap
    bool isHeap(Node* tree) {
        int index = 0; 
        int totalCount = CountNode(tree);
        if (CBT(tree, index, totalCount) && maxOrder(tree)) {
            return true;
        }
        return false;
    }
};

// Helper function to create a new node
Node* newNode(int data) {
    Node* temp = new Node(data);
    return temp;
}

// Function to construct a binary tree from a vector using recursion.
Node* constructTreeRecursively(const vector<int>& values, int index) {
    if (index >= values.size()) return nullptr;

    Node* root = new Node(values[index]);
    root->left = constructTreeRecursively(values, 2 * index + 1);
    root->right = constructTreeRecursively(values, 2 * index + 2);
    
    return root;
}

// Function to take input from the user and create a binary tree
Node* createBinaryTree() {
    int n;
    cout << "Enter the number of nodes in the binary tree: ";
    cin >> n;

    vector<int> values(n);
    cout << "Enter the values of the nodes in level order: ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    return constructTreeRecursively(values, 0);
}

// Main function for testing
int main() {
    Node* root = createBinaryTree();

    Solution sol;
    if (sol.isHeap(root)) {
        cout << "The binary tree is a max heap." << endl;
    } else {
        cout << "The binary tree is not a max heap." << endl;
    }

    return 0;
}
