struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* subtreeInternal(TreeNode* root, int curr, int& maxx) {
    int L = 0;
    int R = 0;

    if (!root) {
        maxx = curr - 1;
        return root;
    }

    TreeNode* maxL = subtreeInternal(root->left,  curr + 1, L);
    TreeNode* maxR = subtreeInternal(root->right, curr + 1, R);

    maxx = max(L, R);

    if (L > R) return maxL;
    if (R > L) return maxR;

    return root;
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    int max = 0;
    return subtreeInternal(root, 0, max);
}

int main() {
    auto lrl = new TreeNode(7);
    auto lrr = new TreeNode(4);

    auto rr = new TreeNode(8);
    auto rl = new TreeNode(0);

    auto lr = new TreeNode(2, lrl, lrr);
    auto ll = new TreeNode(6);

    auto r = new TreeNode(1, rl, rr);
    auto l = new TreeNode(5, ll, lr);

    auto root = new TreeNode(3, l, r);

    auto res = subtreeWithAllDeepest(root);

//    auto lr = new TreeNode(2);
//
//    auto r = new TreeNode(3);
//    auto l = new TreeNode(1, nullptr, lr);
//
//    auto root = new TreeNode(0, l, r);
//
//    auto res = subtreeWithAllDeepest(root);

    return 0;
}