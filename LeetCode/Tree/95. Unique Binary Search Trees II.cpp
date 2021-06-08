vector<TreeNode*> generateInternal(int s, int n) {
    vector<TreeNode*> res;
    if (s == n) {
        res.push_back(new TreeNode(n));
        return res;
    }

    if (s  == 0 || s > n) {
        res.push_back(nullptr);
        return res;
    }

    for (int i = s; i <= n; i++) {
        vector<TreeNode*> l = generateInternal(s, i-1);
        vector<TreeNode*> r = generateInternal(i+1, n);

        for (auto &eachL: l) {
            for (auto &eachR: r) {
                auto root = new TreeNode(i);
                root->left  = eachL;
                root->right = eachR;
                res.push_back(root);
            }
        }
    }

    return res;
}

vector<TreeNode*> generateTrees(int n) {
    return generateInternal(1, n);
}
