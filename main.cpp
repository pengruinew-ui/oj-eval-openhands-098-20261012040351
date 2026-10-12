#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to reconstruct BST from level order traversal
// Assuming the input is a complete binary tree with 7 nodes
TreeNode* buildBSTFromLevelOrder(const vector<int>& levelOrder) {
    if (levelOrder.empty()) return nullptr;
    
    // Create nodes for all values
    vector<TreeNode*> nodes;
    for (int val : levelOrder) {
        nodes.push_back(new TreeNode(val));
    }
    
    // Connect nodes based on complete binary tree structure
    // For a node at index i:
    // - Left child is at index 2*i + 1
    // - Right child is at index 2*i + 2
    for (int i = 0; i < 7; i++) {
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;
        
        if (leftIndex < 7) {
            nodes[i]->left = nodes[leftIndex];
        }
        
        if (rightIndex < 7) {
            nodes[i]->right = nodes[rightIndex];
        }
    }
    
    return nodes[0]; // Root is at index 0
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
    
    // Read 7 node values (level order traversal of BST)
    for (int i = 0; i < 7; i++) {
        cin >> values[i];
    }
    
    // Read cnt
    cin >> cnt;
    
    // Reconstruct BST from level order traversal
    TreeNode* root = buildBSTFromLevelOrder(values);
    
    // Find and output the cnt-th largest element
    cout << findKthLargest(root, cnt) << endl;
    
    return 0;
}