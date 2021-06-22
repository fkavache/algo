struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define mod 1000000007
#define ll long long

ll maxSum(TreeNode* root) {
    if (!root) return 0;

    ll s = maxSum(root->left) + maxSum(root->right);
    root->val = root->val + s;

    return root->val;
}

void maxInternal(TreeNode* root, ll sum, ll &mx) {
    if (!root) return;

    maxInternal(root->left,  sum, mx);
    maxInternal(root->right, sum, mx);

    mx = max(mx, (sum - root->val) * root->val);
}

int maxProduct(TreeNode* root) {
    ll sum = maxSum(root);
    ll res = 0;

    maxInternal(root, sum, res);

    return res % mod;
}

int main() {
    return 0;
}