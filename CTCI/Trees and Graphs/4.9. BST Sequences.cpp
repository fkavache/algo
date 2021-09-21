struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode *left, TreeNode *right): val(val), left(left), right(right){}
};

void prepend(int elem, vector<vector<int>> &A, vector<vector<int>> &res) {
    for (auto arr: A) {
        arr.insert(arr.begin(), elem);
        res.push_back(arr);
    }
}

void addRest(int idx, vector<int> &A, vector<vector<int>> &res) {
    vector<int> rest;

    for (int i = idx; i < A.size(); i++) {
        rest.push_back(A[i]);
    }

    res.push_back(rest);
}

vector<vector<int>> mergingInternal(vector<int> &A, vector<int> &B, int i, int j) {
    vector<vector<int>> res;

    if (i == A.size()) {
        addRest(j, B, res);
        return res;
    } else if (j == B.size()) {
        addRest(i, A, res);
        return res;
    }

    vector<vector<int>> arec = mergingInternal(A, B, i + 1, j);
    vector<vector<int>> brec = mergingInternal(A, B, i, j + 1);

    prepend(A[i], arec, res);
    prepend(B[j], brec, res);

    return res;
}

vector<vector<int>> merging(vector<int> &A, vector<int> &B) {
    return mergingInternal(A, B, 0, 0);
}

vector<vector<int>> prependMerging(int elem, vector<int> &A, vector<int> &B) {
    vector<vector<int>> merge = merging(A, B);

    for (auto &arr: merge) {
        arr.insert(arr.begin(), elem);
    }

    return merge;
}

vector<vector<int>> BSTSequences(TreeNode *root) {
    vector<vector<int>> result;

    if (!root) {
        result.push_back(vector<int>());

        return result;
    }

    vector<vector<int>> left  = BSTSequences(root->left);
    vector<vector<int>> right = BSTSequences(root->right);

    for (auto l: left) {
        for (auto r: right) {
            vector<vector<int>> merge = prependMerging(root->val, l, r);

            result.insert(result.end(), merge.begin(), merge.end());
        }
    }

    return result;
}

int main() {
    auto rl   = new TreeNode(7);
    auto lr   = new TreeNode(4);
    auto r    = new TreeNode(3, rl, nullptr);
    auto l    = new TreeNode(1, nullptr, lr);
    auto root = new TreeNode(2, l, r);

    vector<vector<int>> res = BSTSequences(root);

    for (auto arr: res) {
        for (auto i: arr) {
            cout << i << ", ";
        }
        cout << endl;
    }

    return 0;
}