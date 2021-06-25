struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if (!root) return nullptr;
    if (depth == 1) {
        return new TreeNode(val, root, nullptr);;
    }
    if (depth == 2) {
        root->left  = new TreeNode(val, root->left, nullptr);;
        root->right = new TreeNode(val, nullptr, root->right);
        return root;
    }

    addOneRow(root->left,  val, depth - 1);
    addOneRow(root->right, val, depth - 1);

    return root;
}

int main() {
    auto rrr = new TreeNode(1);
    auto rrl = new TreeNode(5);
    auto rr = new TreeNode(4, rrl, rrr);
    auto rl = new TreeNode(13);

    auto llr = new TreeNode(2);
    auto lll = new TreeNode(7);
    auto ll = new TreeNode(11, llr, lll);

    auto r = new TreeNode(8, rl, rr);
    auto l = new TreeNode(4, ll, nullptr);

    auto root = new TreeNode(5, l, r);

    auto nroot = addOneRow(root, 99, 5);

    return 0;
}