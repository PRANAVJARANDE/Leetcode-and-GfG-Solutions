class Solution {
public:
    int maximumAmount(vector<vector<int>>& a) 
    {
        int n=a.size();
        int m=a[0].size();

        vector<vector<vector<int>>>dis(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));
        dis[0][0][0]=a[0][0];
        dis[0][0][1]=0;
        dis[0][0][2]=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)continue;
                for(int k=0;k<3;k++)
                {
                    int ans=INT_MIN;
                    if(i-1>=0)
                    {
                        ans=max(ans,dis[i-1][j][k]+a[i][j]);
                        if(k!=0)ans=max(ans,dis[i-1][j][k-1]);
                    }
                    if(j-1>=0)
                    {
                        ans=max(ans,dis[i][j-1][k]+a[i][j]);
                        if(k!=0)ans=max(ans,dis[i][j-1][k-1]);
                    }
                    dis[i][j][k]=ans;
                }
            }
        }

        int res=INT_MIN;
        for(int k=0;k<3;k++)
        {
            res=max(res,dis[n-1][m-1][k]);
        }
        return res;
    }
};
