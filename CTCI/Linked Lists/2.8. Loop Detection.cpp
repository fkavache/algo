struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

Node *LoopDetection(Node *head) {
    auto slow = head;
    auto fast = head;

    do {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main() {
    auto h3 = new Node(3);

    auto h8 = new Node(7, h3);
    auto h7 = new Node(7, h8);
    auto h6 = new Node(6, h7);
    auto h5 = new Node(5, h6);
    auto h4 = new Node(4, h5);

    h3->next = h4;

    auto h2 = new Node(2, h3);
    auto h1 = new Node(1, h2);
    auto head = new Node(0, h1);

    auto res = LoopDetection(head);

    return 0;
}
