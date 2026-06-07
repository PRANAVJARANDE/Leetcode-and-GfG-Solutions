#define ll long long
class Solution {
public:
    
    const ll NEG = -(1LL<<60);
    ll query(int node,int i,int j,int l,int r,vector<ll>& tree)
    {
        if(r<i || j<l) return NEG;
        if(l<=i && j<=r)return tree[node];
        int mid=i+(j-i)/2;
        return max(query(2*node+1,i,mid,l,r,tree),query(2*node+2,mid+1,j,l,r,tree));
    }

    void update(int node,int i,int j,int in,ll val,vector<ll>&tree)
    {
        if(i==j)
        {
            tree[node]=val;
            return;
        }
        int mid=i+(j-i)/2;
        if(in<=mid)update(2*node+1,i,mid,in,val,tree);
        else update(2*node+2,mid+1,j,in,val,tree);
        tree[node]=max(tree[2*node+1],tree[2*node+2]);
    }
    
    long long maximumSum(vector<int>& nums, int m, int l, int r)
    {
        int n=nums.size();
        vector<ll>psum(n,0);
        psum[0]=nums[0];
        for(int i=1;i<n;i++)psum[i]=psum[i-1]+nums[i];

        vector<vector<ll>>dp(n+1,vector<ll>(m+1,NEG));
        for(int i=0;i<=n;i++)dp[i][0]=0;

        vector<vector<ll>>tree(m+1,vector<ll>(4*(n+1),NEG));

        for(int i=0;i<=n;i++)
        {
            ll val=NEG;
            if(dp[i][0]<=NEG/2)val=NEG;
            else
            {
                if(i==0)val=0;
                else val=psum[i-1];
            }
            update(0,0,n,i,val,tree[0]);
        }

        for(int k=1;k<=m;k++)
        {
            dp[n][k]=NEG;

            for(int i=n;i>=0;i--)
            {
                if(i<n)
                {
                    ll take=NEG;
                    int a=i+l,b=min(n,i+r);
                    if(a<=b)
                    {
                        take=query(0,0,n,a,b,tree[k-1]);
                        if(i>0)take-=psum[i-1];
                    }
                    ll skip=dp[i+1][k];
                    dp[i][k]=max(skip,take);
                }

                ll val;
                if(dp[i][k]<=NEG/2)val=NEG;
                else
                {
                    if(i==0)val=0;
                    else val=psum[i-1];
                    val+=dp[i][k];
                }
                update(0,0,n,i,val,tree[k]);
            }
        }

        ll ans=NEG;
        for(int k=1;k<=m;k++)ans=max(ans,dp[0][k]);
        return ans;
    }
};
