struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode *left, TreeNode *right): val(val), left(left), right(right){}
};

bool checkBalancedInternal(TreeNode *root, int &depth) {
    if (!root) return true;

    bool res;
    int  depthL = 0;
    int  depthR = 0;

    res = checkBalancedInternal(root->left, depthL);
    if (res) {
        res = checkBalancedInternal(root->right, depthR);
    }

    depth = max(depthL, depthR) + 1;

    return res && abs(depthL - depthR) <= 1;
}

bool checkBalanced(TreeNode *root) {
    int depth = 0;

    return checkBalancedInternal(root, depth);
}

int main() {
    auto rrr  = new TreeNode(7);
    auto rr   = new TreeNode(6, nullptr, rrr);
    auto rl   = new TreeNode(5);
    auto lr   = new TreeNode(4);
    auto ll   = new TreeNode(3);
    auto r    = new TreeNode(2, rl, rr);
    auto l    = new TreeNode(1, ll, lr);
    auto root = new TreeNode(0, l, r);

    cout << checkBalanced(root) << endl;

    return 0;
}