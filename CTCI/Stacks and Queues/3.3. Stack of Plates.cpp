class Plates {
private:
    vector<stack<int>> data;
    int capacity;
public:
    Plates(int capacity) {
        this->capacity = capacity;
        data.push_back(stack<int>());
    }

    void push(int value) {
        if (data[data.size() - 1].size() == capacity) {
            data.push_back(stack<int>());
        }

        data[data.size() - 1].push(value);
    }

    void pop() {
        if (!data.empty()) {
            data[data.size() - 1].pop();
            if (data[data.size() - 1].empty()) {
                data.pop_back();
            }
        }
    }

    void popAt(int index) {
        if (index >= 0 && index < data.size()) {
            data[index].pop();
            if (data[index].empty()) {
                data.erase(data.begin() + index);
            }
        }
    }

    int top() {
        if (!data.empty()) {
            return data[data.size() - 1].top();
        }

        return -1;
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
    Plates stack1(8);
    Plates stack2(10);

    for (int i = 1; i <= 100; i++) stack1.push(i);
    printTestResult(1, stack1.top(), 100);

    for (int i = 1; i <= 20; i++) stack1.pop();
    printTestResult(2, stack1.top(), 80);

    for (int i = 1; i <= 60; i++) stack1.pop();
    printTestResult(3, stack1.top(), 20);

    for (int i = 1; i < 20; i++) stack1.pop();
    printTestResult(4, stack1.top(), 1);

    // --------------------------------------------

    for (int i = 1; i <= 30; i++) stack2.push(i);
    printTestResult(5, stack2.top(), 30);

    for (int i = 1; i <= 10; i++) stack2.popAt(1);
    printTestResult(6, stack2.top(), 30);

    for (int i = 1; i <= 10; i++) stack2.popAt(0);
    printTestResult(7, stack2.top(), 30);

    return 0;
}