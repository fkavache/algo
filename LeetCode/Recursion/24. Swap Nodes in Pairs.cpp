struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    auto tmp = head->next;

    head->next = swapPairs(tmp->next);
    tmp->next  = head;

    return tmp;
}

int main() {
    auto nnn = new ListNode(4);
    auto nn  = new ListNode(3, nnn);
    auto n   = new ListNode(2, nn);
    auto h   = new ListNode(1, n);

    auto res = swapPairs(nullptr);

    return 0;
}