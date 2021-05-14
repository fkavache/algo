struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (!root) return root;

    if (root->val < low) {
        root = trimBST(root->right,  low, high);
    } else if (root->val > high) {
        root = trimBST(root->left,  low, high);
    } else {
        root->left  = trimBST(root->left,  low, high);
        root->right = trimBST(root->right, low, high);
    }

    return root;
}

int main() {
    auto n19 = new TreeNode(19);
    auto n17 = new TreeNode(17);
    auto n18 = new TreeNode(18, n17, n19);

    auto n6  = new TreeNode(6);
    auto n2  = new TreeNode(2);
    auto n4  = new TreeNode(4, n2, n6);
    auto n10 = new TreeNode(10, n4, n18);

    TreeNode* res = trimBST(n10, 5, 18);

    return 0;
}
