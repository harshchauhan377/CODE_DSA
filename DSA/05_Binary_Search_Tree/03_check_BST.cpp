#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
     Node (int value){
        data = value;
        left = right = NULL;
    }
};

void inorder(Node* root, vector<int>& ans) {
    if (!root)
        return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

bool isBST(Node* root) {
    vector<int> ans;
    inorder(root, ans);

    for (int i = 1; i < ans.size(); i++) { // Start from 1 to compare with previous element
        if (ans[i] <= ans[i - 1]) {
            return false;
        }
    }
    return true;
}

// Utility function to create a new node
// Node* newNode(int data) {
//     Node* node = new Node(data);
//     return node;
// }

// Function to insert nodes in level order
Node* insertLevelOrder(vector<int>& arr, int i) {
    if (i >= arr.size() || arr[i] == -1) {
        return nullptr;
    }
    
    Node* root = new Node(arr[i]);
    root->left = insertLevelOrder(arr, 2 * i + 1);
    root->right = insertLevelOrder(arr, 2 * i + 2);
    
    return root;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the nodes (use -1 for null nodes): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* root = insertLevelOrder(arr, 0);

    if (isBST(root)) {
        cout << "The tree is a BST" << endl;
    } else {
        cout << "The tree is not a BST" << endl;
    }

    return 0;
}
