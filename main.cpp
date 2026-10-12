#include <iostream>
#include <vector>
#include <stack>

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

// Function to find the cnt-th largest element in BST using iterative reverse in-order traversal
int findKthLargest(TreeNode* root, int cnt) {
    stack<TreeNode*> st;
    TreeNode* current = root;
    int count = 0;
    
    while (current != nullptr || !st.empty()) {
        // Go to the rightmost node
        while (current != nullptr) {
            st.push(current);
            current = current->right;
        }
        
        // Current is now nullptr, so pop from stack
        current = st.top();
        st.pop();
        
        // Process current node
        count++;
        if (count == cnt) {
            return current->val;
        }
        
        // Visit left subtree
        current = current->left;
    }
    
    return -1; // Should not reach here if cnt is valid
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
    
    // Build BST by inserting values in the order they appear
    TreeNode* root = nullptr;
    for (int val : values) {
        root = insertIntoBST(root, val);
    }
    
    // Find and output the cnt-th largest element
    cout << findKthLargest(root, cnt) << endl;
    
    return 0;
}