struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* A) {
    vector<vector<int>> res;
    queue<TreeNode *> q;
    q.push(A);

    int left = 1;
    res.push_back(vector<int>());
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        res[res.size() - 1].push_back(curr->val);

        if (curr->left)  q.push(curr->left);
        if (curr->right) q.push(curr->right);

        left--;
        if (left == 0) {
            left = q.size();
            if (left > 0) res.push_back(vector<int>());
        }
    }

    return res;
}

int main() {
    auto rr = new TreeNode(7);
    auto ll = new TreeNode(4);

    auto rl = new TreeNode(6);
    auto lr = new TreeNode(5);

    auto r = new TreeNode(3, rl, rr);
    auto l = new TreeNode(2, ll, lr);

    auto root = new TreeNode(1, l, r);

    vector<vector<int>> res = levelOrder(root);

    return 0;
}