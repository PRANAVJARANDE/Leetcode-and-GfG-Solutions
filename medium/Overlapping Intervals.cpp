class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& a) 
    {
        sort(a.begin(),a.end());
        vector<vector<int>>ans;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            int st=a[i][0];
            int maxi=a[i][1];
            while(i<n && a[i][0]<=maxi)
            {
                maxi=max(maxi,a[i][1]);
                i++;
            }
            i--;
            ans.push_back({st,maxi});
        }
        return ans;
    }
};
