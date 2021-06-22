struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return root;

    if (root->val == p->val || root->val == q->val) return root;

    auto l = lowestCommonAncestor(root->left,  p, q);
    auto r = lowestCommonAncestor(root->right, p, q);

    if (l && r) return root;

    return l ? l : r;
}

int main() {
    return 0;
}
