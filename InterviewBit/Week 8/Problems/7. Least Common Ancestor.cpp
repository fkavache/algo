struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int lcaInternal(TreeNode* A, int B, int C) {
    if (!A) return -1;

    if (A->val == B || A->val == C) return A->val;

    int l = lcaInternal(A->left,  B, C);
    int r = lcaInternal(A->right, B, C);

    if (l >= 0 && r >= 0) return A->val;

    return l >= 0 ? l : r;
}

bool find(TreeNode* A, int val) {
    if (!A) return false;
    if (A->val == val) return true;

    return find(A->left, val) || find(A->right, val);
}

int lca(TreeNode* A, int B, int C) {
    if (!find(A, B) || !find(A, C)) return -1;

    return lcaInternal(A, B, C);
}

int main() {
    auto rrl = new TreeNode(9);
    auto rr  = new TreeNode(3, rrl, nullptr);
    auto rl  = new TreeNode(13);

    auto llr = new TreeNode(2);
    auto lll = new TreeNode(7);
    auto ll  = new TreeNode(11, llr, lll);

    auto r = new TreeNode(8, rl, rr);
    auto l = new TreeNode(4, ll, nullptr);

    auto root = new TreeNode(5, l, r);

    cout << lca(root, 3, 8)  << " 8" << endl;
    cout << lca(root, 3, 8)  << " 8" << endl;
    cout << lca(root, 3, 13) << " 8" << endl;
    cout << lca(root, 8, 4)  << " 5" << endl;
    cout << lca(root, 13, 4) << " 5" << endl;
    cout << lca(root, 5, 5)  << " 5" << endl;

    return 0;
}