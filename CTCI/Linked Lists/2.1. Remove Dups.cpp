struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

// O(n^2) - time
// O(1)   - space
void removeDups1(Node *head) {
    auto i = head;
    while (i) {
        auto j = i;
        while (j->next) {
            if (j->next->val == i->val) {
                j->next = j->next->next;
            } else {
                j = j->next;
            }
        }
        i = i->next;
    }
}

// O(n) - time
// O(n) - space
void removeDups2(Node *head) {
    unordered_set<int> set;

    auto i = head;
    while (i->next) {
        set.insert(i->val);
        if (set.find(i->next->val) != set.end()) {
            i->next = i->next->next;
        } else {
            i = i->next;
        }
    }
}

int main() {
    auto head = new Node(2, new Node(2, new Node(3, new Node(3, new Node(3, new Node(1))))));

    removeDups2(head);

    return 0;
}