struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void sumNumbersInternal(TreeNode* A, int sofar, int &res) {
    if (!A) return;

    int curr = (sofar * 10 + A->val) % 1003;
    if (!A->left && !A->right) {
        res = (res + curr) % 1003;
        return;
    }

    sumNumbersInternal(A->left,  curr, res);
    sumNumbersInternal(A->right, curr, res);
}

int sumNumbers(TreeNode* A) {
    int res = 0;
    sumNumbersInternal(A, 0, res);
    return res;
}

int main() {
    auto rr   = new TreeNode(7);
    auto rl   = new TreeNode(6);
    auto lr   = new TreeNode(4);
    auto ll   = new TreeNode(3);
    auto r    = new TreeNode(5, rl, rr);
    auto l    = new TreeNode(2, ll, lr);

    auto root = new TreeNode(1, l, r);

    cout << sumNumbers(root) << endl;

    return 0;
}