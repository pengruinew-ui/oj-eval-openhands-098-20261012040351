#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to reconstruct BST from level order traversal
TreeNode* buildBSTFromLevelOrder(const vector<int>& levelOrder) {
    if (levelOrder.empty()) return nullptr;
    
    // Create root from first element
    TreeNode* root = new TreeNode(levelOrder[0]);
    
    // Use queue to process nodes in level order
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1; // Index for levelOrder array
    while (!q.empty() && i < levelOrder.size()) {
        TreeNode* current = q.front();
        q.pop();
        
        // Process left child
        if (i < levelOrder.size()) {
            // In a BST, left child should be less than parent
            if (levelOrder[i] < current->val) {
                current->left = new TreeNode(levelOrder[i]);
                q.push(current->left);
            }
            i++;
        }
        
        // Process right child
        if (i < levelOrder.size()) {
            // In a BST, right child should be greater than parent
            if (levelOrder[i] > current->val) {
                current->right = new TreeNode(levelOrder[i]);
                q.push(current->right);
            }
            i++;
        }
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