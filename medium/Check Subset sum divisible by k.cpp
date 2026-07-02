class Solution {
  public:
    
    int k;
    int dp[1002][1002][2];
    int helper(int in,int cs,bool flag,vector<int>&cnt)
    {
        if(cs==0 && flag==1)return 1;
        if(in>=cnt.size())return 0;
        
        if(dp[in][cs][flag]!=-1)return dp[in][cs][flag];
        
        for(int i=0;i<=cnt[in];i++)
        {
            int res=in*i;
            res+=cs;
            res%=k;
            int nflag=1;
            if(flag==0 && i==0)nflag=0;
            bool nx=helper(in+1,res,nflag,cnt);
            if(nx)return dp[in][cs][flag]=1;
        }
        return dp[in][cs][flag]=0;
    }
  
    bool divisibleByK(vector<int>& arr, int k) 
    {
        this->k=k;
        vector<int>cnt(k,0);
        for(auto x:arr)cnt[x%k]++;
        
        memset(dp,-1,sizeof(dp));
        return helper(0,0,0,cnt);
        
    }
};
