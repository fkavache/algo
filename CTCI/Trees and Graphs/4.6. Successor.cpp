struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode *left, TreeNode *right): val(val), left(left), right(right){}
};

TreeNode *getLeftMost(TreeNode *node) {
    if (!node) return nullptr;
    if (!node->left) return node;

    return getLeftMost(node->left);
}

TreeNode *getLeftParent(TreeNode *node) {
    if (!node->parent) return nullptr;

    if (node->parent->left == node) {
        return node->parent;
    }

    return getLeftParent(node->parent);
}

// o(log(n)) - time
// o(log(n)) - space
TreeNode *successor(TreeNode *node) {
    auto next = getLeftMost(node->right);
    if (!next) {
        next = getLeftParent(node);
    }

    return next;
}

int main() {
    auto rr   = new TreeNode(15);
    auto rl   = new TreeNode(7);
    auto lr   = new TreeNode(4);
    auto ll   = new TreeNode(1);
    auto r    = new TreeNode(10, rl, rr);
    auto l    = new TreeNode(3, ll, lr);
    auto root = new TreeNode(5, l, r);

    ll->parent = l;
    lr->parent = l;

    rl->parent = r;
    rr->parent = r;

    l->parent = root;
    r->parent = root;

    auto next1 = successor(rr); // null
    auto next2 = successor(r);  // 15
    auto next3 = successor(lr); // 5
    auto next4 = successor(ll); // 3

    cout << (next1 == nullptr) << endl;
    cout << (next2->val == 15) << endl;
    cout << (next3->val == 5)  << endl;
    cout << (next4->val == 3)  << endl;

    return 0;
}