struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeKLists(vector<ListNode*> &A) {
    priority_queue<int> q;
    ListNode* res = nullptr;

    for (auto i: A) {
        while (i) {
            q.push(i->val);
            i = i->next;
        }
    }

    while (!q.empty()) {
        auto node = new ListNode(q.top());
        q.pop();
        node->next = res;
        res = node;
    }

    return res;
}


int main() {
    return 0;
}