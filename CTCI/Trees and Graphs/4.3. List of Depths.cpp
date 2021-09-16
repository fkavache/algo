struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val): val(val), next(nullptr){}
    ListNode(int val, ListNode *next): val(val), next(next){}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode *left, TreeNode *right): val(val), left(left), right(right){}
};

// O(n) - time
// O(n) - space
vector<ListNode *> listOfDepths(TreeNode *root) {
    queue<TreeNode *> q;
    vector<ListNode *> res;

    ListNode *curr = nullptr;
    ListNode *currHead = curr;

    q.push(root);
    int left = 1;

    while (!q.empty()) {
        auto currNode = q.front();
        q.pop();

        auto nn = new ListNode(currNode->val);

        if (!curr) {
            curr = nn;
            currHead = curr;
        } else {
            curr->next = nn;
            curr = nn;
        }

        if (currNode->left)  q.push(currNode->left);
        if (currNode->right) q.push(currNode->right);

        left--;
        if (left == 0) {
            res.push_back(currHead);
            curr = nullptr;
            currHead = curr;
            left = q.size();
        }
    }

    return res;
}

void listOfDepthsInternal(TreeNode *root, unordered_map<int, ListNode *> &sofar, vector<ListNode *> &res, int depth) {
    if (root) {
        auto nn = new ListNode(root->val);

        if (!sofar[depth]) {
            sofar[depth] = nn;
            res.push_back(nn);
        } else {
            sofar[depth]->next = nn;
            sofar[depth] = nn;
        }

        listOfDepthsInternal(root->left,  sofar, res, depth + 1);
        listOfDepthsInternal(root->right, sofar, res, depth + 1);
    }
}

// O(n) - time
// O(n) - space
vector<ListNode *> listOfDepths2(TreeNode *root) {
    unordered_map<int, ListNode *> sofar;
    vector<ListNode *> res;

    listOfDepthsInternal(root, sofar, res, 0);

    return res;
}

int main() {
    auto rrr  = new TreeNode(7);
    auto rr   = new TreeNode(6, nullptr, rrr);
    auto rl   = new TreeNode(5);
    auto lr   = new TreeNode(4);
    auto ll   = new TreeNode(3);
    auto r    = new TreeNode(2, rl, rr);
    auto l    = new TreeNode(1, ll, lr);
    auto root = new TreeNode(0, l, r);

    auto res = listOfDepths2(root);

    return 0;
}