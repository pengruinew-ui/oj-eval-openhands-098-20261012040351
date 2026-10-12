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
    
    // Use queue to store nodes at current level
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1; // Index for levelOrder array
    while (!q.empty() && i < levelOrder.size()) {
        int size = q.size();
        
        // Process all nodes at current level
        for (int j = 0; j < size && i < levelOrder.size(); j++) {
            TreeNode* current = q.front();
            q.pop();
            
            // Add left child if it exists and is less than parent
            if (i < levelOrder.size()) {
                int leftVal = levelOrder[i];
                // In BST, left child must be less than parent
                if (leftVal < current->val) {
                    current->left = new TreeNode(leftVal);
                    q.push(current->left);
                }
                i++;
            }
            
            // Add right child if it exists and is greater than parent
            if (i < levelOrder.size()) {
                int rightVal = levelOrder[i];
                // In BST, right child must be greater than parent
                if (rightVal > current->val) {
                    current->right = new TreeNode(rightVal);
                    q.push(current->right);
                }
                i++;
            }
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