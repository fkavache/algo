
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* insertionSortList(ListNode* A) {
    auto h = A;

    int i = 0;
    while (h) {
        auto c = A;
        int j = 0;
        while (j < i) {
            if (c->val > h->val) swap(c->val, h->val);
            c = c->next;
            j++;
        }

        h = h->next;
        i++;
    }

    return A;
}


int main() {
    auto hn5 = new ListNode(15);
    auto hn4 = new ListNode(20, hn5);
    auto hn3 = new ListNode(3, hn4);
    auto hn2 = new ListNode(5, hn3);
    auto hn1 = new ListNode(1, hn2);

    auto h = new ListNode(10, hn1);

    auto res = insertionSortList(h);

    return 0;
}