class Solution {
  public:
    const int MOD=1e9+7;
    int distinctSubseq(string &s) 
    {
        int n=s.size();
        vector<int>dp(n+1,0),pv(26,-1);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i]=(2*(dp[i-1]%MOD))%MOD;
            if(pv[s[i-1]-'a']!=-1)dp[i]=((dp[i]%MOD)-(dp[pv[s[i-1]-'a']]%MOD) + MOD)%MOD;
            pv[s[i-1]-'a']=i-1;
        }
        return dp[n];
    }
};
