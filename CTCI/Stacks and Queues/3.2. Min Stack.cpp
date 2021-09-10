class MinStack : stack<int>{
private:
    stack<int> minStack;
public:
    MinStack() {}

    void push(int value) {
        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }
        stack::push(value);
    }

    void pop() {
        if (top() == minStack.top()) {
            minStack.pop();
        }
        stack::pop();
    }

    int top() {
       return stack::top();
    }

    int min() {
        return minStack.empty() ? INT_MIN : minStack.top();
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
    MinStack stack;

    stack.push(10);
    stack.push(90);
    stack.push(5);
    stack.push(2);
    stack.push(3);

    printTestResult(1, stack.top(), 3);
    printTestResult(2, stack.min(), 2);

    stack.pop();

    printTestResult(3, stack.top(), 2);
    printTestResult(4, stack.min(), 2);

    stack.pop();

    printTestResult(5, stack.min(), 5);

    stack.pop();

    printTestResult(6, stack.min(), 10);

    return 0;
}