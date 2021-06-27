struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int pruneSum(TreeNode* root) {
    if (!root) return 0;

    return root->val + pruneSum(root->left) + pruneSum(root->right);
}

TreeNode* pruneTree(TreeNode* root) {
    if (!root || pruneSum(root) == 0){
        return nullptr;
    }

    root->left  = pruneTree(root->left);
    root->right = pruneTree(root->right);

    return root;
}

int main() {
    return 0;
}

