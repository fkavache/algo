
vector<TreeNode*> allFBTInternal(int n, map<int, vector<TreeNode *>> &memo) {
    vector<TreeNode*> result;

    if (n % 2 == 0) {
        return result;
    }

    if (n == 1) {
        result.push_back(new TreeNode(0));
        return result;
    }

    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    for (int i = 1; i < n; i += 2) {
        vector<TreeNode*> l = allFBTInternal(i, memo);
        vector<TreeNode*> r = allFBTInternal(n-i-1, memo);

        for (auto &eachL : l) {
            for (auto &eachR : r) {
                auto root = new TreeNode(0);

                root->left  = eachL;
                root->right = eachR;

                result.push_back(root);
            }
        }
    }

    memo[n] = result;
    return result;
}

vector<TreeNode*> allPossibleFBT(int n) {
    map<int, vector<TreeNode *>> memo;
    return allFBTInternal(n, memo);
}

int main() {
    vector<TreeNode *> res = allPossibleFBT(7);
    return 0;
}