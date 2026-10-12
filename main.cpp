#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert a value into BST
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }
    
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    
    return root;
}

// Function to perform reverse in-order traversal to get values in descending order
void reverseInorder(TreeNode* root, vector<int>& result) {
    if (!root) return;
    
    reverseInorder(root->right, result);  // Visit right subtree first (larger values)
    result.push_back(root->val);           // Visit root
    reverseInorder(root->left, result);    // Visit left subtree last (smaller values)
}

// Function to find the cnt-th largest element in BST
int findKthLargest(TreeNode* root, int cnt) {
    vector<int> values;
    reverseInorder(root, values);
    
    // Return the cnt-th largest element (1-indexed)
    return values[cnt - 1];
}

int main() {
    vector<int> values(7);
    int cnt;
    
    // Read 7 node values
    for (int i = 0; i < 7; i++) {
        cin >> values[i];
    }
    
    // Read cnt
    cin >> cnt;
    
    // Build BST from the input values
    TreeNode* root = nullptr;
    for (int val : values) {
        root = insertIntoBST(root, val);
    }
    
    // Find and output the cnt-th largest element
    cout << findKthLargest(root, cnt) << endl;
    
    // Clean up memory (optional for this problem)
    // In a real application, you'd want to properly delete the tree
    // For this problem, it's not strictly necessary as the program ends
    
    return 0;
}