
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void pathSumInternal(TreeNode* root, int targetSum, vector<int> &sofar, vector<vector<int>> &res) {
    if (!root) return;

    sofar.push_back(root->val);
    targetSum -= root->val;

    if (!root->left && !root->right && targetSum == 0) {
        res.push_back(sofar);
    }

    pathSumInternal(root->left,  targetSum, sofar, res);
    pathSumInternal(root->right, targetSum, sofar, res);

    sofar.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> res;
    vector<int> sofar;

    pathSumInternal(root, targetSum, sofar, res);

    return res;
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

    vector<vector<int>> res = pathSum(root, 22);

    for (auto &v: res) {
        for (auto i: v) {
            cout << i << ",";
        }
        cout << endl;
    }

    return 0;
}
