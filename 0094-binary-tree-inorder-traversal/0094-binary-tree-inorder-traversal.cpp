class Solution {
private:
    void inorderHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        // 1. Traverse left subtree
        inorderHelper(node->left, result);
        // 2. Visit root
        result.push_back(node->val);
        // 3. Traverse right subtree
        inorderHelper(node->right, result);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }
};