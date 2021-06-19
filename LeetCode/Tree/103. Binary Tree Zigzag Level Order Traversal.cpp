struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;

    if (!root) return res;

    vector<int> curr;
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;

    s2.push(root);

    bool flag = false;
    while (!s1.empty() || !s2.empty()) {
        TreeNode *c = nullptr;
        if (flag) {
            c = s1.top();
            s1.pop();

            if (c->right) s2.push(c->right);
            if (c->left)  s2.push(c->left);
        } else {
            c = s2.top();
            s2.pop();

            if (c->left)  s1.push(c->left);
            if (c->right) s1.push(c->right);
        }

        curr.push_back(c->val);

        if ((flag && s1.empty()) || (!flag && s2.empty())) {
            flag = !flag;
            res.push_back(curr);
            curr.clear();
        }
    }

    return res;
}

int main() {
    auto rr = new TreeNode(5);
    auto ll = new TreeNode(4);

    auto r = new TreeNode(3, nullptr, rr);
    auto l = new TreeNode(2, ll, nullptr);

    auto root = new TreeNode(1, l, r);

    vector<vector<int>> res = zigzagLevelOrder(root);

    return 0;
}
