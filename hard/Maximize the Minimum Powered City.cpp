#define ll long long
class Solution {
public:

    ll n;
    bool check(ll mid,vector<int>a,ll r,ll k)
    {
        ll cs=0;
        for(int i=0;i<min(n,r);i++)cs+=a[i];
        for(ll i=0;i<n;i++)
        {
            if(i+r<n)cs+=a[i+r];
            ll diff=max(0ll,mid-cs);
            k-=diff;
            a[min(n-1,i+r)]+=diff;
            cs+=diff;
            if(i-r>=0)cs-=a[i-r];
        }
        return k>=0;
    }

    long long maxPower(vector<int>& a, int rr, int k) 
    {
        n=a.size();
        ll l=0,r=1e18;
        ll ans=0;
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            if(check(mid,a,rr,k))
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
