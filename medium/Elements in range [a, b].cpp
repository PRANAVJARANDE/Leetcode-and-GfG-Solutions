class Solution {
  public:
    vector<int> cntInRange(vector<int> &a, vector<vector<int>> &q) {
        sort(a.begin(),a.end());
        int sz=q.size();
        vector<int>ans(sz);
        for(int i=0;i<sz;i++)
        {
            int l=q[i][0],r=q[i][1];
            ans[i]=upper_bound(a.begin(),a.end(),r)-lower_bound(a.begin(),a.end(),l);
        }
        return ans;
    }
};
