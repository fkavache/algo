struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode *left, TreeNode *right): val(val), left(left), right(right){}
};

void pathsInternal(TreeNode *root, unordered_map<int, int> &sums, int sofar, int target, int &result) {
    if (!root) return;

    sofar += root->val;
    if (sums.find(sofar - target) != sums.end()) {
        result += sums[sofar - target];
    }

    sums[sofar]++;
    pathsInternal(root->left, sums, sofar, target, result);
    pathsInternal(root->right, sums, sofar, target, result);
    sums[sofar]--;
}

// o(n) - time
// o(d) - space
int pathsWithSum(TreeNode *root, int target) {
    unordered_map<int, int> sums;
    int result = 0;
    sums[result]++;

    pathsInternal(root, sums, 0, target, result);

    return result;
}

int main() {
    auto llrrr = new TreeNode(0);
    auto llrrl = new TreeNode(10);
    auto llrr  = new TreeNode(30, llrrl, llrrr);
    auto llrl  = new TreeNode(-5);
    auto llr   = new TreeNode(5, llrl, llrr);
    auto ll    = new TreeNode(5, nullptr, llr);
    auto rrr   = new TreeNode(15);
    auto rrl   = new TreeNode(5);
    auto rr    = new TreeNode(20, rrl, rrr);
    auto rl    = new TreeNode(5);
    auto r     = new TreeNode(10, rl, rr);
    auto l     = new TreeNode(10, ll, nullptr);

    auto root = new TreeNode(5, l, r);

    cout << pathsWithSum(root, 50) << endl;

    return 0;
}