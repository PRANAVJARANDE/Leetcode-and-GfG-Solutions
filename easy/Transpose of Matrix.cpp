class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& a) {
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(a[i][j],a[j][i]);
            }
        }
        return a;
        
    }
};
