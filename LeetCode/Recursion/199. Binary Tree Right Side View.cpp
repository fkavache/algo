
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void clear(queue<TreeNode*> &q) {
    queue<TreeNode*> empty;
    swap(q, empty);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    queue<TreeNode*> q;
    queue<TreeNode*> nq;

    if (root) q.push(root);
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (curr->left)  nq.push(curr->left);
        if (curr->right) nq.push(curr->right);

        if (q.empty()) {
            res.push_back(curr->val);
            q = nq;
            clear(nq);
        }
    }

    return res;
}

vector<int> rightSideView2Internal(TreeNode* root, int currD, int& maxD) {
    vector<int> res;

    if (!root) return res;
    if (currD > maxD) res.push_back(root->val);

    vector<int> R = rightSideView2Internal(root->right, currD + 1, maxD);
    vector<int> L = rightSideView2Internal(root->left,  currD + 1, maxD);

    maxD = max(currD, maxD);
    res.insert(res.end(), R.begin(), R.end());
    res.insert(res.end(), L.begin(), L.end());

    return res;
}

vector<int> rightSideView2(TreeNode* root) {
    int D = 0;
    return rightSideView2Internal(root, 1, D);
}

int main() {
    auto lrlrrr = new TreeNode(6);
    auto lrlrr = new TreeNode(5, nullptr, lrlrrr);
    auto lrlr = new TreeNode(4, nullptr, lrlrr);

    auto rrr = new TreeNode(80);

    auto rr = new TreeNode(70, nullptr, rrr);
    auto rl = new TreeNode(40);

    auto lrl = new TreeNode(3, nullptr, lrlr);

    auto lr = new TreeNode(5, lrl, nullptr);
    auto ll = new TreeNode(0);

    auto r = new TreeNode(50, rl, rr);
    auto l = new TreeNode(1, ll, lr);

    auto root = new TreeNode(10, l, r);

    vector<int> res = rightSideView2(root);

    for (int e: res) {
        cout << e << ", ";
    }

    return 0;
}