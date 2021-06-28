struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void flipInternal(TreeNode* root, vector<int>& voyage, vector<int> &res, int &idx) {
    if (root) {
        if (root->val != voyage[idx++]) {
            res.clear();
            res.push_back(-1);
            return;
        }
        if (idx < voyage.size()) {
            if (root->left && root->left->val != voyage[idx]) {
                res.push_back(root->val);
                flipInternal(root->right, voyage, res, idx);
                flipInternal(root->left, voyage, res, idx);
            } else {
                flipInternal(root->left, voyage, res, idx);
                flipInternal(root->right, voyage, res, idx);
            }
        }
    }
}

vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
    vector<int> res;
    int idx = 0;

    flipInternal(root, voyage, res, idx);

    if (!res.empty() && res[0] == -1) {
        res.clear();
        res.push_back(-1);
    }

    return res;
}

int main() {
    auto lrr  = new TreeNode(11);
    auto lrl  = new TreeNode(10);
    auto llr  = new TreeNode(9);
    auto lll  = new TreeNode(8);

    auto rr   = new TreeNode(7);
    auto rl   = new TreeNode(6);

    auto lr   = new TreeNode(5, lrl, lrr);
    auto ll   = new TreeNode(4, lll, llr);

    auto r    = new TreeNode(2, ll, lr);
    auto l    = new TreeNode(3, rl, rr);
    auto root = new TreeNode(1, l, r);

    vector<int> A = {1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 7};
    vector<int> res = flipMatchVoyage(root, A);

    for (int i: res) {
        cout << i << ", ";
    }

    return 0;
}
