struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int findFrequentTreeSum(TreeNode* root, unordered_map<int, int> &freq, int &m) {
    if (!root) return 0;

    int l = findFrequentTreeSum(root->left, freq, m);
    int r = findFrequentTreeSum(root->right, freq, m);

    int res = l + r + root->val;

    freq[res]++;
    m = max(m, freq[res]);

    return res;
}

vector<int> findFrequentTreeSum(TreeNode* root) {
    unordered_map<int, int> freq;
    vector<int> res;
    int m = INT_MIN;

    findFrequentTreeSum(root, freq, m);

    for (auto const& p : freq) {
        if (p.second == m) res.push_back(p.first);
    }

    return res;
}

int main() {
    return 0;
}