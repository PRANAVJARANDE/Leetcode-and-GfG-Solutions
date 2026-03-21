class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& a, int x, int y, int k) 
    {
        for(int i=0;i<k/2;i++)
        {
            for(int j=0;j<k;j++)
            {
                swap(a[x+i][y+j],a[x+k-i-1][y+j]);
            }
        }
        return a;
    }
};
