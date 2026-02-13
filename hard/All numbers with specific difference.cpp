#define ll long long
class Solution {
  public:
  
    ll getSum(ll x) 
    {
        ll sum=0;
        while(x>0) 
        {
            sum+=x%10;
            x/=10;
        }
        return sum;
    }

    ll getCount(ll n,ll d) 
    {
        ll l=1,r=n;
        ll ans=-1;

        while(l<=r) 
        {
            ll mid=l+(r-l)/2;
            if(mid-getSum(mid)>=d) 
            {
                ans=mid;
                r=mid-1; 
            } 
            else 
            {
                l=mid+1;
            }
        }
        if(ans==-1)return 0;
        return (n-ans+1);
    }
};
