#define ll long long
class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<ll>>pv(n,vector<ll>(32,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<32;j++)
            {
                if(nums[i] & (1<<j))pv[i][j]=i;
                else if(i-1>=0)pv[i][j]=pv[i-1][j];
            }
        }

        vector<vector<ll>>nx(n,vector<ll>(32,n));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<32;j++)
            {
                if(nums[i] & (1<<j))nx[i][j]=i;
                else if(i+1<n)nx[i][j]=nx[i+1][j];
            }
        }
        
        map<ll,ll>m;
        for(int i=0;i<n;i++)
        {
            if(m.find(nums[i])!=m.end())
            {
                for(int j=0;j<32;j++)
                {
                    pv[i][j]=max(pv[i][j],m[nums[i]]);
                }
            }
            m[nums[i]]=i;
        }

        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            ll r=n,l=-1;
            for(int j=0;j<32;j++)
            {
                if(!(nums[i] & (1<<j)))
                {
                    r=min(r,nx[i][j]);
                    l=max(l,pv[i][j]);
                }
            }
            ll ta=(r-i)*(i-l);
            //cout<<ta<<" ";
            ans+=(r-i)*(i-l);
        }
        return ans;
    }
};
