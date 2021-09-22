struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode *left, TreeNode *right): val(val), left(left), right(right){}
};

string getPreOrder(TreeNode *root) {
    if (!root) return "";

    return to_string(root->val) + "," + getPreOrder(root->left) + "," + getPreOrder(root->right);
}

// o(n + m) - time
// o(n + m) - space
bool checkSubtree1(TreeNode *T1, TreeNode *T2) {
    string t1str = getPreOrder(T1);
    string t2str = getPreOrder(T2);

    return t1str.find(t2str) != -1;
}

// -------------------------------------------

// o(n * m)           - time
// o(log(n) + log(m)) - space
bool checkMatch(TreeNode *T1, TreeNode *T2) {
    if (!T1 && !T2) return true;
    if (!T1 || !T2) return false;

    if (T1->val != T2->val) return false;

    return checkMatch(T1->left, T2->left) && checkMatch(T1->right, T2->right);
}

bool checkSubtree2(TreeNode *T1, TreeNode *T2) {
    if (!T1) return false;

    if (T1->val == T2->val) {
        if(checkMatch(T1, T2)) {
            return true;
        }
    }

    return checkSubtree2(T1->left, T2) || checkSubtree2(T1->right, T2);
}

int main() {
    // -------------------------------------------

    auto lrr  = new TreeNode(5);
    auto rrl  = new TreeNode(14);
    auto rr   = new TreeNode(15, rrl, nullptr);
    auto rl   = new TreeNode(7);
    auto lr   = new TreeNode(4, nullptr, lrr);
    auto ll   = new TreeNode(1);
    auto r    = new TreeNode(10, rl, rr);
    auto l    = new TreeNode(3, ll, lr);
    auto root = new TreeNode(6, l, r);

    // -------------------------------------------

    cout << checkSubtree2(root, root) << endl; // 1
    cout << checkSubtree2(root, r)    << endl; // 1
    cout << checkSubtree2(root, l)    << endl; // 1
    cout << checkSubtree2(root, ll)   << endl; // 1
    cout << checkSubtree2(root, lr)   << endl; // 1
    cout << checkSubtree2(root, rl)   << endl; // 1
    cout << checkSubtree2(root, rr)   << endl; // 1
    cout << checkSubtree2(root, rrl)  << endl; // 1
    cout << checkSubtree2(root, lrr)  << endl; // 1

    // -------------------------------------------

    auto rr1 = new TreeNode(15);
    auto rl1 = new TreeNode(7);
    auto r1  = new TreeNode(10, rl1, rr1);

    // -------------------------------------------

    cout << checkSubtree2(root, r1)  << endl; // 0
    cout << checkSubtree2(root, rl1) << endl; // 1
    cout << checkSubtree2(root, rr1) << endl; // 0

    // -------------------------------------------

    return 0;
}