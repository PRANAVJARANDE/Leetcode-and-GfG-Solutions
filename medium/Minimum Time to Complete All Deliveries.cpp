#define ll long long
class Solution {
public:

    bool check(ll tmid,vector<int>d,vector<int>r)
    {
        ll lcm=(r[0]*r[1])/(__gcd(r[0],r[1]));
        ll cnt=tmid/lcm;
        ll cnt1=(tmid/r[0])-cnt;
        ll cnt2=(tmid/r[1])-cnt;
        ll cnt3=tmid-cnt-cnt1-cnt2;
        d[0]=max(0ll,(ll)d[0]-cnt2);
        d[1]=max(0ll,(ll)d[1]-cnt1);
        if(cnt3>=d[0]+d[1])return 1;
        return 0;
    }

    long long minimumTime(vector<int>& dd, vector<int>& rr) 
    {
        ll l=0,r=1e15;
        ll ans=r;
        cout<<check(5,dd,rr)<<endl;
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            if(check(mid,dd,rr))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
