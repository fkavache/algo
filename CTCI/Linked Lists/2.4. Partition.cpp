struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

// O(n) - time
// O(1) - space
void partition1(Node *head, int k) {
    Node *left  = head;
    Node *right = nullptr;
    while (left->next) {
        if (left->val >= k) {
            auto tmp = left->next;

            swap(left->val, left->next->val);
            left->next = left->next->next;

            tmp->next = right;
            right = tmp;
        } else {
            left = left->next;
        }
    }

    left->next = right;
}

// O(n) - time
// O(1) - space
Node *partition2(Node *head, int k) {
    Node *left  = head;
    Node *right = head;
    while (head) {
        auto tmp = head->next;
        if (head->val < k) {
            head->next = left;
            left = head;
        } else {
            right->next = head;
            right = head;
        }
        head = tmp;
    }
    right->next = nullptr;

    return left;
}

int main() {
    auto head = new Node(10, new Node(2, new Node(30, new Node(40, new Node(5, new Node(6, new Node(7)))))));

    partition1(head, 10);

    return 0;
}