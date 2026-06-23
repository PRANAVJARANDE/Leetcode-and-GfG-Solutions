class Solution {
public:
    int sz;
    const int MOD=1e9+7;
    int dp[2001][2001][2];
    long long helper(int in,int prev,bool flag,int n) 
    {
        if(in>=n)return 1;
        if(dp[in][prev][flag]!=-1)return dp[in][prev][flag];
        long long op1=0,op2=0;
        if(flag==0)
        {
            if(prev-1>=0)
            {
                op1=helper(in+1,prev-1,!flag,n);
                op2=helper(in,prev-1,flag,n);
            }
        }
        if(flag==1)
        {
            if(prev+1<=sz) 
            {
                op1=helper(in+1,prev+1,!flag,n);
                op2=helper(in,prev+1,flag,n);
            }
        }
        return dp[in][prev][flag]=(op1+op2)%MOD ;
    }

    int zigZagArrays(int n, int l, int r) 
    {
        sz=r-l;
        memset(dp,-1,sizeof(dp));
        return (2*1LL*helper(0,0,1,n))%MOD;
    }
};
