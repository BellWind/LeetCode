class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool vis[9];
        for(int k = 0; k < 9; k++) {
            for(int i = 0; i < 9; i++)
                vis[i] = 0;
            for(int i = 0; i < 9; i++) {
                if(board[k][i] == '.')
                    continue;
                if(vis[board[k][i] - '1'])
                    return false;
                vis[board[k][i] - '1'] = 1;
            }
        }
        for(int k = 0; k < 9; k++) {
            for(int i = 0; i < 9; i++)
                vis[i] = 0;
            for(int i = 0; i < 9; i++) {
                if(board[i][k] == '.')
                    continue;
                if(vis[board[i][k] - '1'])
                    return false;
                vis[board[i][k] - '1'] = 1;
            }
        }
        for(int rs = 0; rs < 9; rs += 3) {
            for(int cs = 0; cs < 9; cs += 3) {
                for(int i = 0; i < 9; i++)
                    vis[i] = 0;
                for(int i = rs; i < rs + 3; i++)
                    for(int j = cs; j < cs + 3; j++) {
                        if(board[i][j] == '.')
                            continue;
                        if(vis[board[i][j] - '1'])
                            return false;
                        vis[board[i][j] - '1'] = 1;
                    }
            }
        }
        return true;
    }
};
