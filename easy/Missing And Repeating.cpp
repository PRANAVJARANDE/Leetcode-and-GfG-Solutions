class Solution {
  public:
    vector<int> findTwoElement(vector<int>& a) {
        int n=a.size();
        vector<int>dp(n+1,0);
        for(auto x:a)dp[x]++;
        int a1=-1,a2=-1;
        for(int i=1;i<=n;i++)
        {
            if(dp[i]==2)a1=i;
            if(dp[i]==0)a2=i;
        }
        return {a1,a2};
    }
};
