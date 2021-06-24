struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:

    string serialize(TreeNode* root) {
        if (!root) return "10001,";

        string res = to_string(root->val) + ",";
        res.append(serialize(root->left));
        res.append(serialize(root->right));

        return res;
    }


    TreeNode* deserializeInternal(vector<int> &pre, int &idx) {
        if (pre[idx] == 10001) {
            idx++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(pre[idx++]);

        node->left  = deserializeInternal(pre, idx);
        node->right = deserializeInternal(pre, idx);

        return node;
    }

    TreeNode* deserialize(string data) {
        stringstream tok(data);
        vector<int>  resv;
        string       str;
        int          idx = 0;

        while(getline(tok, str, ',')) {
            resv.push_back(stoi(str));
        }

        return deserializeInternal(resv, idx);
    }
};

int main() {
    auto lrlrrr = new TreeNode(6);
    auto lrlrr  = new TreeNode(5, nullptr, lrlrrr);
    auto lrlr   = new TreeNode(4, nullptr, lrlrr);
    auto rrr    = new TreeNode(80);
    auto rr     = new TreeNode(70, nullptr, rrr);
    auto rl     = new TreeNode(40);
    auto lrl    = new TreeNode(3, nullptr, lrlr);
    auto lr     = new TreeNode(55, lrl, nullptr);
    auto ll     = new TreeNode(0);
    auto r      = new TreeNode(50, rl, rr);
    auto l      = new TreeNode(1, ll, lr);
    auto root   = new TreeNode(10, l, r);

    auto ser   = new Codec();
    auto deser = new Codec();

    auto tree = ser->serialize(root);
    auto ans  = deser->deserialize(tree);

    return 0;
}

