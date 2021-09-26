bool isValidStep(vector<vector<int>> &board, int i, int j) {
    return i < board.size() && j < board[0].size() && board[i][j] == 0;
}

bool reached(vector<vector<int>> &board, int i, int j) {
    return (i == (board.size() - 1)) && (j == (board[0].size() - 1));
}

vector<pair<int, int>> robotInternal(vector<vector<int>> &board
        , vector<pair<int, int>> &sofar
        , unordered_map<int, vector<pair<int, int>>> &memo
        , int i, int j) {
    if (!isValidStep(board, i, j)) {
        return {};
    }

    sofar.push_back(make_pair(i, j));

    if (reached(board, i, j)) {
        return sofar;
    }

    if (memo.find(i * board[0].size() + j) != memo.end()) {
        return memo[i * board[0].size() + j];
    }

    vector<pair<int, int>> res;

    res = robotInternal(board, sofar, memo, i + 1, j);
    if (res.empty()) {
        res = robotInternal(board, sofar, memo, i, j + 1);
    }

    sofar.pop_back();

    memo[i * board[0].size() + j] = res;

    return res;
}

// o(n * m) - time
// o(n * m) - space
vector<pair<int, int>> robot(vector<vector<int>> &board) {
    unordered_map<int, vector<pair<int, int>>> memo;
    vector<pair<int, int>> sofar;

    return robotInternal(board, sofar, memo, 0, 0);
}

int main() {
    vector<vector<int>> board = {
            {0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0},
            {0, 1, 0, 0, 0},
            {0, 1, 0, 0, 0},
            {0, 0, 0, 1, 0},
    };

    auto res = robot(board);

    for (auto e: res) {
        cout << "{" << e.first << ", " << e.second << "}, ";
    }

    return 0;
}
