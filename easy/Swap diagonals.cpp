class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &a) 
    {
        int n=a.size();
        for(int r=0;r<n;r++)swap(a[r][r],a[r][n-r-1]);
    }
};
