struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* delInternal(TreeNode* root, vector<TreeNode*> &res, vector<bool>& to_delete) {
    if (root) {
        root->left  = delInternal(root->left,  res, to_delete);
        root->right = delInternal(root->right, res, to_delete);

        if (to_delete[root->val]) {
            if (root->left)  res.push_back(root->left);
            if (root->right) res.push_back(root->right);
            return nullptr;
        }
    }
    return root;
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<bool> to (1001);
    vector<TreeNode*> res;

    for (int i: to_delete) {
        to[i] = true;
    }

    auto r = delInternal(root, res, to);
    if (r) res.push_back(r); 

    return res;
}

int main() {
    return 0;
}

