class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        vector<int>ans;
        int xs=0;
        reverse(queries.begin(),queries.end());
        for(auto x:queries)
        {
            if(x[0]==0)
            {
                ans.push_back(x[1]^xs);
            }
            else
            {
                xs=xs^x[1];
            }
        }
        ans.push_back(xs);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
