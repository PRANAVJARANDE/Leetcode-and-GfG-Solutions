class Solution {
  public:
    
    int dp[11][2][2];
    int d;
    int helper(int in,int th,int pr,string&s)
    {
        if(in>=s.size())
        {
            if(pr==0)return 0;
            return 1;
        }
        
        if(dp[in][th][pr]!=-1)return dp[in][th][pr];
        
        int op1=0,op2=0;
        if(pr==0)
        {
            op1=helper(in+1,0,0,s);
            int nx=9;
            if(th)nx=s[in]-'0';
            for(int i=1;i<=nx;i++)
            {
                if(i==d)continue;
                int nth=0;
                if(th && i==nx)nth=1;
                op2+=helper(in+1,nth,1,s);
            }
        }
        else
        {
            int nx=9;
            if(th)nx=s[in]-'0';
            for(int i=0;i<=nx;i++)
            {
                if(i==d)continue;
                int nth=0;
                if(i==nx && th==1)nth=1;
                op1+=helper(in+1,nth,1,s);
            }
        }
        return dp[in][th][pr]=op1+op2;
    }
    
    int countWithout(int n, int d) 
    {
        memset(dp,-1,sizeof(dp));
        this->d=d;
        string s=to_string(n);
        return max(0,helper(0,1,0,s));
    }
};
