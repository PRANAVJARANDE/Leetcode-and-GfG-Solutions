class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        sort(a.begin(),a.end());
        int ans=INT_MAX;
        m--;
        for(int i=m;i<a.size();i++)ans=min(ans,a[i]-a[i-m]);
        return ans;
    }
};
