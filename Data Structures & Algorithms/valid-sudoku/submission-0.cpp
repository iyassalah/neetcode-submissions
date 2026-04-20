class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, vector<bool>> rowHave;
        map<int, vector<bool>> colHave;
        map<pair<int, int>, vector<bool>> blockHave;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;

                int val = board[i][j] - '0';
                pair<int, int> blockKey = {i / 3, j / 3};

                if (rowHave[i].empty()) rowHave[i].resize(10, false);
                if (colHave[j].empty()) colHave[j].resize(10, false);
                if (blockHave[blockKey].empty()) blockHave[blockKey].resize(10, false);

                if (rowHave[i][val] || colHave[j][val] || blockHave[blockKey][val]) {
                    return false;
                }

                rowHave[i][val] = colHave[j][val] = blockHave[blockKey][val] = true;
            }
        }
        return true;
    }
};
