class Solution {
public:

    int n,m;
    vector<int>dx{0,1};
    vector<int>dy{1,0};
    bool issafe(int i,int j)
    {
        return i>=0 && j>=0 && i<n && j<m;
    }
    
    int helper(int r1,int c1,int c2,vector<vector<int>>&a,vector<vector<vector<int>>>&dp)
    {
        int r2=r1+c1-c2;
        if(!issafe(r1,c1) || !issafe(r2,c2) || a[r1][c1]==-1 || a[r2][c2]==-1)return INT_MIN;
        if(dp[r1][c1][c2]!=-1)return dp[r1][c1][c2];
        
        if(r1==n-1 && c1==m-1 && r2==n-1 && c2==m-1)return dp[r1][c1][c2] = a[r1][c1];
        
        int ans=INT_MIN;
        for(int z=0;z<2;z++)
        {
            int nr1=r1+dx[z];
            int nc1=c1+dy[z];
            for(int w=0;w<2;w++)
            {
                int nr2=r2+dx[w];
                int nc2=c2+dy[w];
                ans=max(ans,helper(nr1,nc1,nc2,a,dp));
            }
        }
        
        if(ans!=INT_MIN)
        {
            ans+=a[r1][c1];
            if(r1!=r2)ans+=a[r2][c2];
        }
        return dp[r1][c1][c2]=ans;
    }

    int cherryPickup(vector<vector<int>>& a) {
        n=a.size();
        m=a[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        if(a[0][0]==-1 || a[n-1][m-1]==-1)return 0;
        int ans=helper(0,0,0,a,dp);
        return max(0,ans);
    }
};
