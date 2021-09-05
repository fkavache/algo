struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

// O(1) - time
// O(1) - space
void removeMiddle(Node *middle) {
    if (!middle || !middle->next)
        return;

    middle->val = middle->next->val;
    middle->next = middle->next->next;
}

int main() {
    auto n5 = new Node(5);
    auto n4 = new Node(4, n5);
    auto n3 = new Node(3, n4);
    auto n2 = new Node(2, n3);
    auto n1 = new Node(1, n2);
    auto head = new Node(0, n1);

    removeMiddle(n3);

    return 0;
}