
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Data {
    int curr_l;
    int curr_r;
    int curr;
    int max;
};

Data longestUnivaluePathInternal(TreeNode* root) {
    Data res = {};

    if (!root) {
        return res;
    }

    Data left  = longestUnivaluePathInternal(root->left);
    Data right = longestUnivaluePathInternal(root->right);

    if (root->left && (root->val == root->left->val)) {
        res.curr_l = max(left.curr_l, left.curr_r) + 1;
        res.curr  += res.curr_l;
    }
    if (root->right && (root->val == root->right->val)) {
        res.curr_r = max(right.curr_l, right.curr_r) + 1;
        res.curr  += res.curr_r;
    }

    res.max = max(res.curr, max(left.max, right.max));

    return res;
}

int longestUnivaluePath(TreeNode* root) {
    Data res = longestUnivaluePathInternal(root);
    return res.max;
}

int main() {
//    auto rr = new TreeNode(5);
//    auto lr = new TreeNode(1);
//    auto ll = new TreeNode(1);
//
//    auto r = new TreeNode(5, nullptr, rr);
//    auto l = new TreeNode(4, ll, lr);
//
//    auto root = new TreeNode(5, l, r);

// --------------------------------------------

//    auto lrllrr = new TreeNode(1, nullptr, nullptr);
//
//    auto lrllr = new TreeNode(1, nullptr, lrllrr);
//
//    auto lrlr = new TreeNode(4, nullptr, nullptr);
//    auto lrll = new TreeNode(1, nullptr, lrllr);
//
//    auto lrr = new TreeNode(3, nullptr, nullptr);
//    auto lrl = new TreeNode(4, lrll, lrlr);
//
//    auto lr = new TreeNode(4, lrl, lrr);
//
//    auto r = new TreeNode(5, nullptr, nullptr);
//    auto l = new TreeNode(4, nullptr, lr);
//
//    auto root = new TreeNode(4, l, r);

// --------------------------------------------

    auto rr = new TreeNode(5);
    auto lr = new TreeNode(5);
    auto ll = new TreeNode(5);

    auto r = new TreeNode(5, nullptr, rr);
    auto l = new TreeNode(5, ll, lr);

    auto root = new TreeNode(4, l, r);

    cout << longestUnivaluePath(root) << endl;

    return 0;
}
