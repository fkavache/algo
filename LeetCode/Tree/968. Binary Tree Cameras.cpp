struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// has     -1
// covered  0
// need     1
int minInternal(TreeNode* root, int &res) {
    if (!root) return 0;

    int l = minInternal(root->left,  res);
    int r = minInternal(root->right, res);

    if (l == 1 || r == 1) {
        res++;
        return -1;
    }

    if (l == -1 || r == -1) return 0;
    else return 1;
}

int minCameraCover(TreeNode* root) {
    int res = 0;

    int r = minInternal(root, res);

    return r == 1 ? ++res : res;
}

int main() {
/*
    auto lrlrrr = new TreeNode(6);
    auto lrlrr  = new TreeNode(5, nullptr, lrlrrr);
    auto lrlr   = new TreeNode(4, nullptr, lrlrr);
    auto rrr    = new TreeNode(80);
    auto rr     = new TreeNode(70, nullptr, rrr);
    auto rl     = new TreeNode(40);
    auto lrl    = new TreeNode(3, nullptr, lrlr);
    auto lr     = new TreeNode(55, lrl, nullptr);
    auto ll     = new TreeNode(0);
    auto r      = new TreeNode(50, rl, rr);
    auto l      = new TreeNode(1, ll, lr);

    auto root   = new TreeNode(10, l, r);
*/

    auto lrlrl  = new TreeNode(0, nullptr, nullptr);
    auto lrlr   = new TreeNode(0, lrlrl, nullptr);
    auto lrl    = new TreeNode(0, nullptr, lrlr);
    auto lr     = new TreeNode(0, lrl, nullptr);
    auto l      = new TreeNode(0, nullptr, lr);

    auto root   = new TreeNode(0, l, nullptr);

    cout << minCameraCover(root) << endl;

    return 0;
}
