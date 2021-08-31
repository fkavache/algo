// O(n) - time
// O(1) - space
void rotateImage(vector<vector<int>> &image) {
    int n = image.size();

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(image[i][j], image[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        reverse(image[i].begin(), image[i].end());
    }
}

void print(vector<vector<int>> &matrix) {
    for (auto m: matrix) {
        for (auto i: m) {
            cout << i << ", ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> grid1 = {
            {1,  2,  3,  4,  5},
            {6,  7,  8,  9,  10},
            {11, 12, 13, 14, 15},
            {16, 17, 18, 19, 20},
            {21, 22, 23, 24, 25}
    };

    vector<vector<int>> grid2 = {
            {1,  2,  3},
            {4,  5,  6},
            {7,  8,  9},
    };

    vector<vector<int>> grid3 = {
            {1, 2},
            {3, 4}
    };

    rotateImage(grid1);
    print(grid1);

    rotateImage(grid2);
    print(grid2);

    rotateImage(grid3);
    print(grid3);

    return 0;
}
