class Solution {
public:

    int n,m;
    int helper(int in,int pmask,vector<vector<char>>&a,vector<vector<int>>&dp)
    {
        if(in<0)return 0;
        if(dp[in][pmask]!=-1)return dp[in][pmask];
        int ans=0;
        for(int mask=0;mask<(1<<m);mask++)
        {
            bool flag=1;
            int cnt=0;
            for(int j=0;j<m;j++)
            {
                if(mask & (1<<j))
                {
                    if(a[in][j]=='#')flag=0;
                    if(j>0)
                    {
                        if(mask & (1<<(j-1)))flag=0;
                        if(pmask & (1<<(j-1)))flag=0;
                    }
                    if(j<m-1)
                    {
                        if(mask & (1<<(j+1)))flag=0;
                        if(pmask & (1<<(j+1)))flag=0;
                    }
                    if(flag==0)break;
                    cnt++; 
                }
            }
            if(flag)ans=max(ans,cnt+helper(in-1,mask,a,dp));
        }   
        return dp[in][pmask]=ans;
    }

    int maxStudents(vector<vector<char>>& a) 
    {
        n=a.size();
        m=a[0].size();
        vector<vector<int>>dp(n,vector<int>((1<<m)+10,-1));
        int ans=helper(n-1,0,a,dp);
        return ans;
    }
};
