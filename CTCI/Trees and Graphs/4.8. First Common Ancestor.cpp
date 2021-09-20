struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode *left, TreeNode *right): val(val), left(left), right(right){}
};

// o(n)      - time
// o(log(n)) - space
TreeNode *firstAncestor(TreeNode *root, TreeNode *n1, TreeNode *n2) {
    if (!root || root == n1 || root == n2) {
        return root;
    }

    auto left  = firstAncestor(root->left,  n1, n2);
    auto right = firstAncestor(root->right, n1, n2);

    if (left && right) return root;
    if (left) return left;
    return right;
}

int main() {
    auto rr   = new TreeNode(15);
    auto rl   = new TreeNode(7);
    auto lr   = new TreeNode(4);
    auto ll   = new TreeNode(1);
    auto r    = new TreeNode(10, rl, rr);
    auto l    = new TreeNode(3, ll, lr);
    auto root = new TreeNode(5, l, r);

    auto res = firstAncestor(root, ll, l);

    return 0;
}