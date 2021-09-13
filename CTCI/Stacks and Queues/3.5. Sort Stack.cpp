void sortStack(stack<int> &s) {
    stack<int> tmp;
    while (!s.empty()) {
        int curr = s.top();
        s.pop();

        while (!tmp.empty() && tmp.top() > curr) {
            s.push(tmp.top());
            tmp.pop();
        }

        tmp.push(curr);
    }

    while (!tmp.empty()) {
        s.push(tmp.top());
        tmp.pop();
    }
}

void printTestResult(int testNum, int actual, int expected) {
    if (actual == expected) {
        cout << "Test #" << testNum << " " << "Passed" << endl;
    } else {
        cout << "Test #" << testNum << " " << "Failed, Expected: " << expected << ", But was: " << actual << endl;
    }
}

bool sorted(stack<int> &s) {
    int prev = INT_MIN;
    while (!s.empty()) {
        if (s.top() < prev) {
            return false;
        }
        prev = s.top();
        s.pop();
    }

    return true;
}

int main() {
    stack<int> s;

    for (int i = 0; i < 10; i++) {
        s.push(rand());
    }

    sortStack(s);

    printTestResult(1, sorted(s), true);

    return 0;
}
