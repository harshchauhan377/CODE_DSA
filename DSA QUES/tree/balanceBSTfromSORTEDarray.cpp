#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* balanceBST(vector<int>& nums, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = start + (end - start) / 2;
    TreeNode* temp = new TreeNode(nums[mid]);
    temp->left = balanceBST(nums, start, mid - 1);
    temp->right = balanceBST(nums, mid + 1, end);  // Corrected this line
    return temp;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return balanceBST(nums, 0, nums.size() - 1);
}

// Helper function to print the inorder traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = sortedArrayToBST(nums);

    cout << "Inorder Traversal of the constructed BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
