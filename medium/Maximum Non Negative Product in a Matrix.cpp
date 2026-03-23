#define ll long long
class Solution {
public:

    ll n,m;
    const int MOD=1e9+7;
    const ll INF=1e18;

    int maxProductPath(vector<vector<int>>&a) 
    {
        n=a.size();
        m=a[0].size();
        vector<vector<ll>>pos(n,vector<ll>(m,-INF));
        vector<vector<ll>>neg(n,vector<ll>(m,INF));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)
                {
                    if(a[i][j]>=0)pos[i][j]=a[i][j];
                    if(a[i][j]<=0)neg[i][j]=a[i][j];
                    continue;
                }
                if(a[i][j]>=0)
                {
                    if(i-1>=0)
                    {
                        if(pos[i-1][j]!=-INF)pos[i][j]=max(pos[i-1][j]*a[i][j],pos[i][j]);
                        if(neg[i-1][j]!=INF)neg[i][j]=min(neg[i][j],neg[i-1][j]*a[i][j]);
                    }
                    if(j-1>=0)
                    {
                        if(pos[i][j-1]!=INT_MIN)pos[i][j]=max(pos[i][j-1]*a[i][j],pos[i][j]);
                        if(neg[i][j-1]!=INT_MAX)neg[i][j]=min(neg[i][j],neg[i][j-1]*a[i][j]);
                    }
                }
                else
                {
                    if(i-1>=0)
                    {
                        if(pos[i-1][j]!=-INF)neg[i][j]=min(pos[i-1][j]*a[i][j],neg[i][j]);
                        if(neg[i-1][j]!=INF)pos[i][j]=max(pos[i][j],neg[i-1][j]*a[i][j]);
                    }
                    if(j-1>=0)
                    {
                        if(pos[i][j-1]!=-INF)neg[i][j]=min(pos[i][j-1]*a[i][j],neg[i][j]);
                        if(neg[i][j-1]!=INF)pos[i][j]=max(pos[i][j],neg[i][j-1]*a[i][j]);
                    }
                }
                if(a[i][j] == 0)
                {
                    pos[i][j]=max(pos[i][j],0LL);
                    neg[i][j]=min(neg[i][j],0LL);
                }
            }
        }

        ll ans=pos[n-1][m-1];
        if(ans<0)ans=-1;
        return ans%MOD;
    }
};
