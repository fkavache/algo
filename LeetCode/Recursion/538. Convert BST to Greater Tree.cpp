struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* convertBSTInternal(TreeNode* root, int &start) {
    if (!root) {
        return root;
    }

    root->right = convertBSTInternal(root->right, start);

    start += root->val;
    root->val = start;

    root->left  = convertBSTInternal(root->left, start);

    return root;
}

TreeNode* convertBST(TreeNode* root) {
    int start = 0;
    return convertBSTInternal(root, start);
}

int main() {
    auto rrr = new TreeNode(8);

    auto rr = new TreeNode(7, nullptr, rrr);
    auto rl = new TreeNode(5);

    auto lrr = new TreeNode(3);

    auto lr = new TreeNode(2, nullptr, lrr);
    auto ll = new TreeNode(0);

    auto r = new TreeNode(6, rl, rr);
    auto l = new TreeNode(1, ll, lr);

    auto root = new TreeNode(4, l, r);

//-----------------------------------------

    auto r1 = new TreeNode(1);
    auto root1 = new TreeNode(0, nullptr, r1);

//-----------------------------------------

    auto r2 = new TreeNode(2);
    auto l2 = new TreeNode(0);
    auto root2 = new TreeNode(1, l2, r2);


//-----------------------------------------
    auto ll3 = new TreeNode(1);

    auto r3 = new TreeNode(4);
    auto l3 = new TreeNode(2, ll3, nullptr);
    auto root3 = new TreeNode(3, l3, r3);

    auto res = convertBST(root);

    return 0;
}