#include <iostream>
#include <vector>
#include <functional>

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

// Function to find the cnt-th largest element in BST using reverse in-order traversal with counter
int findKthLargest(TreeNode* root, int cnt) {
    int count = 0;
    int result = -1;
    
    // Helper function for reverse in-order traversal
    function<void(TreeNode*)> reverseInorder = [&](TreeNode* node) {
        if (!node || count >= cnt) return;
        
        // Visit right subtree first (larger values)
        reverseInorder(node->right);
        
        // Visit root
        count++;
        if (count == cnt) {
            result = node->val;
            return;
        }
        
        // Visit left subtree last (smaller values)
        reverseInorder(node->left);
    };
    
    reverseInorder(root);
    return result;
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