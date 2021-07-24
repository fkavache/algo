bool isValid(vector<vector<int>>& grid, int i, int j) {
    int n = grid.size();
    return i >= 0 && i < n && j >= 0 && j < n
        && grid[i][j] != -1;
}

int swimInWater(vector<vector<int>>& grid) {
    int s  = grid.size();
    int ss = s * s - 1;

    priority_queue<pair<int, int>> pq;

    pq.push(make_pair(ss - grid[0][0], 0));

    int res = INT_MIN;

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        int i = curr.second / s;
        int j = curr.second % s;

        res = max(res, ss - curr.first);

        grid[i][j] = -1;

        if (i == s - 1 && j == s - 1) {
            break;
        }

        for (int m = -1; m <= 1 ; ++m) {
            for (int n = -1; n <= 1 ; ++n) {
                if (m * n == 0 && (m + n) != 0) {
                    if (isValid(grid, i + m, j + n)) {
                        pq.push(make_pair(ss - grid[i + m][j + n]
                                , (i + m) * s + (j + n)));
                    }
                }
            }
        }

    }

    return res;
}

int main() {
    vector<vector<int>> grid1 = {
        {0,  1,  2,  3,  4},
        {24, 23, 22, 21, 5},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10, 9,  8,  7,  6}
    };

    vector<vector<int>> grid2 = {
        {3, 2},
        {0, 1}
    };

    vector<vector<int>> grid3 = {
        {0,  1,  2,  3,  4},
        {5,  23, 22, 21, 24},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10, 9,  8,  7,  6}
    };

    cout << swimInWater(grid1) << endl;
    cout << swimInWater(grid2) << endl;
    cout << swimInWater(grid3) << endl;

    return 0;
}