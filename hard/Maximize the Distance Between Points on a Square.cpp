#define ll long long
class Solution {
public:

    ll n;
    bool check(ll mid,vector<ll>&v1,ll k,ll side)
    {
        for(ll i=0;i<n;i++)
        {
            ll cnt=1;
            ll j=lower_bound(v1.begin(),v1.end(),v1[i]+mid)-v1.begin();
            while(j<i+n)
            {
                cnt++;
                if(cnt>=k)
                {
                    ll gap=4*side-(v1[j]-v1[i]);
                    if(gap>=mid)return 1;
                    else break;
                }
                j=lower_bound(v1.begin(),v1.end(),v1[j]+mid)-v1.begin();
            }
        }
        return 0;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) 
    {
        ll ans=0;
        ll l=0,r=4ll*side;
        vector<ll>v1;
        for(auto pt:points)
        {
            if(pt[1]==0)v1.push_back(pt[0]);
            else if(pt[0]==side)v1.push_back(1ll*side+pt[1]);
            else if(pt[1]==side)v1.push_back(3ll*side-pt[0]);
            else v1.push_back(4ll*side-pt[1]);
        }
        sort(v1.begin(),v1.end());
        n=v1.size();
        for(int i=0;i<n;i++)v1.push_back(4ll*side+v1[i]);
        
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            if(check(mid,v1,k,side))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};
