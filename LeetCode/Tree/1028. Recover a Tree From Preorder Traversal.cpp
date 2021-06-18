struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* recoverFromPreorder(string traversal) {
    int n = traversal.length();

    TreeNode *res = nullptr;
    stack<pair<TreeNode *, int>> s;

    int l  = 0;
    int c  = 0;
    for (int i = 0; i < n; i++) {
        if (traversal[i] == '-') {
            int j = i;
            while (traversal[j] == '-') j++;
            l = j-i;
            i = j - 1;
        } else {
            int j = i;
            while (traversal[j] != '-' && j < n) j++;
            c = stoi(traversal.substr(i, j-i));
            i = j - 1;

            while (!s.empty() && l <= s.top().second) {
                s.pop();
            }

            auto nn = new TreeNode(c);

            if (!s.empty()) {
                if (s.top().first->left) s.top().first->right = nn;
                else s.top().first->left = nn;
            } else {
                res = nn;
            }

            s.push(make_pair(nn, l));
        }
    }

    return res;
}

int main() {
    auto res = recoverFromPreorder("1-401--349---90--88-999");

    return 0;
}

