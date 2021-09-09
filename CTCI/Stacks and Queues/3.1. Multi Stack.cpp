class MultiStack {
private:
    int  numStacks;
    int  capacity;
    int *data;
    int *indices;
    
public:
    MultiStack(int numStacks, int capacity) {
        this->numStacks = numStacks;
        this->capacity  = capacity;

        data    = new int[capacity];
        indices = new int[numStacks + 1];

        for (int i = 1; i <= numStacks; i++) {
            indices[i] = i;
        }
    }

    MultiStack(int numStacks) {
        MultiStack(numStacks, numStacks);
    }

    void push(int stackNum, int value) {
        int idx = indices[stackNum];

        if (idx >= capacity) {
            resize();
        }

        data[idx] = value;
        indices[stackNum] += numStacks;
    }

    void pop(int stackNum) {
        if (indices[stackNum] != stackNum) {
            indices[stackNum] -= numStacks;
        }
    }

    int top(int stackNum) {
        int idx = indices[stackNum];

        if (idx != stackNum) {
            return data[idx - numStacks];
        }

        return -1;
    }

    bool empty(int stackNum) {
        return indices[stackNum] == stackNum;
    }

    void resize() {
        capacity *= 2;
        int *newData = new int[capacity];

        for (int i = 0; i <= capacity / 2; i++) {
            newData[i] = data[i];
        }

        delete[] data;

        data = newData;
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
    MultiStack stack(3, 5);

    stack.push(1, 101);
    stack.push(1, 201);
    stack.push(1, 301);
    stack.push(2, 102);
    stack.push(2, 202);
    stack.push(3, 103);
    stack.push(1, 401);
    stack.push(1, 501);
    stack.push(1, 601);

    printTestResult(1, stack.top(1), 601);
    printTestResult(2, stack.top(2), 202);
    printTestResult(3, stack.top(3), 103);

    stack.pop(1);
    stack.pop(1);

    printTestResult(4, stack.top(1), 401);
    printTestResult(5, stack.top(2), 202);

    stack.pop(2);
    stack.pop(1);

    printTestResult(6, stack.top(2), 102);
    printTestResult(7, stack.top(1), 301);

    stack.pop(2);
    stack.pop(3);

    printTestResult(8,  stack.top(2),  -1);
    printTestResult(9,  stack.empty(2), 1);
    printTestResult(10, stack.empty(3), 1);

    return 0;
}