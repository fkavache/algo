struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxPathSumInternal(TreeNode* root, int &res) {
    if (!root) return 0;

    int r = max(0, maxPathSumInternal(root->right, res));
    int l = max(0, maxPathSumInternal(root->left,  res));

    res = max(res, l + root->val + r);

    return max(r, l) + root->val;
}

int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    maxPathSumInternal(root, res);
    return res;
}

int main() {
    auto rr = new TreeNode(7);
    auto rl = new TreeNode(15);

    auto r = new TreeNode(20, rl, rr);
    auto l = new TreeNode(9);

    auto root = new TreeNode(-10, l, r);

    cout << maxPathSum(root);

    return 0;
}