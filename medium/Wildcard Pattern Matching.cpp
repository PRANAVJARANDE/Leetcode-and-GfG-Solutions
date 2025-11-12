class Solution {
  public:
    
    int helper(int i,int j,string&a,string&b,vector<vector<int>>&dp)
    {
        int n=a.size();
        int m=b.size();
        if(i==n && j==m)return 1;
        if(j==m)return 0;
        if(i==n)
        {
            for(int k=j;k<m;k++)
            {
                if(b[k]!='*')return 0;
            }
            return 1;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        
        if(a[i]==b[j] || b[j]=='?')
        {
            int op=helper(i+1,j+1,a,b,dp);
            if(op)return dp[i][j]=1;
        }
        else if(b[j]=='*') 
        {
            for(int ni=i;ni<=n;ni++)
            {
                int op=helper(ni,j+1,a,b,dp);
                if(op)return dp[i][j]=1;
            }
        }
        return dp[i][j]=0;
    }
  
    bool wildCard(string &txt, string &pat) 
    {
        int n=txt.size();
        int m=pat.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,txt,pat,dp);
    }
};
