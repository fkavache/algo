
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int isBalancedInternal(TreeNode* A, int &d) {
    if (!A) {
        d = 0;
        return true;
    }

    int ld, rd = 0;
    int l = isBalancedInternal(A->left, ld);
    int r = isBalancedInternal(A->right, rd);

    if (!l || !r || abs(ld - rd) > 1) {
        return false;
    }

    d = max(ld, rd) + 1;
    return true;
}

int isBalanced(TreeNode* A) {
    int d = 0;
    return isBalancedInternal(A, d);
}

int main() {
    auto rr   = new TreeNode(7);
    auto rl   = new TreeNode(6);
    auto lr   = new TreeNode(5);
    auto ll   = new TreeNode(4);
    auto r    = new TreeNode(3, rl, rr);
    auto l    = new TreeNode(2, ll, lr);
    auto root = new TreeNode(1, l, r);

    cout << isBalanced(root) << endl;

    return 0;
}