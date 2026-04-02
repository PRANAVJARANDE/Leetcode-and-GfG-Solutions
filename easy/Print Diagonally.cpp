class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) 
    {
        int n=mat.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int r=0,c=i;
            while(r<n && c>=0)
            {
                ans.push_back(mat[r][c]);
                r++;
                c--;
            }
        }
        for(int i=1;i<n;i++)
        {
            int r=i,c=n-1;
            while(r<n && c>=0)
            {
                ans.push_back(mat[r][c]);
                r++;
                c--;
            }
        }
        return ans;
    }
};
