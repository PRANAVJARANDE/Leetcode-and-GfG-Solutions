class Solution {
public:
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    vector<int> exitPoint(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        int i = 0, j = 0;
        int dir = 0; 
        
        while (i >= 0 && i < n && j >= 0 && j < m) 
        {
            if (mat[i][j] == 1) {
                dir = (dir + 1) % 4;
                mat[i][j] = 0;
            }

            i += dx[dir];
            j += dy[dir];
        }

        i -= dx[dir];
        j -= dy[dir];

        return {i, j};
    }
};
