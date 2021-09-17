struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode *left, TreeNode *right): val(val), left(left), right(right){}
};

bool validateInternal(TreeNode *root, int lo, int hi) {
    if (!root) return true;

    if (root->val < lo || root->val > hi) {
        return false;
    }

    return validateInternal(root->left,  lo, root->val)
        && validateInternal(root->right, root->val, hi);
}

bool validateBST(TreeNode *root) {
    return validateInternal(root, INT_MIN, INT_MAX);
}

int main() {
    auto rr   = new TreeNode(15);
    auto rl   = new TreeNode(7);
    auto lr   = new TreeNode(4);
    auto ll   = new TreeNode(1);
    auto r    = new TreeNode(10, rl, rr);
    auto l    = new TreeNode(3, ll, lr);
    auto root = new TreeNode(5, l, r);

    cout << validateBST(root) << endl;

    return 0;
}