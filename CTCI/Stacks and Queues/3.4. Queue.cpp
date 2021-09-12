class Queue {
private:
    stack<int> push;
    stack<int> pop;
public:
    Queue() {}

    void enqueue(int value) {
        while (!pop.empty()) {
            push.push(pop.top());
            pop.pop();
        }
        push.push(value);
    }

    void dequeue() {
        while (!push.empty()) {
            pop.push(push.top());
            push.pop();
        }
        pop.pop();
    }

    int peek() {
        while (!push.empty()) {
            pop.push(push.top());
            push.pop();
        }
        return pop.top();
    }
};

void printTestResult(int testNum, int actual, int expected) {
    if (actual == expected) {
        cout << "Test #" << testNum << " " << "Passed" << endl;
    } else {
        cout << "Test #" << testNum << " " << "Failed, Expected: " << expected << ", But was: " << actual << endl;
    }
}

int main() {
    Queue queue;

    for (int i = 1; i <= 10; i++) queue.enqueue(i);
    printTestResult(1, queue.peek(), 1);

    for (int i = 1; i <= 5; i++) queue.dequeue();
    printTestResult(2, queue.peek(), 6);

    for (int i = 11; i <= 20; i++) queue.enqueue(i);
    printTestResult(3, queue.peek(), 6);

    for (int i = 1; i <= 5; i++) queue.dequeue();
    printTestResult(4, queue.peek(), 11);

    return 0;
}