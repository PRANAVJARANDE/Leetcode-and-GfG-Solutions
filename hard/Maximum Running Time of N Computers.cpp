#define ll long long
class Solution {
public:

    bool check(ll mid,vector<int>&a,int n)
    {   
        ll cnt=0;
        ll sum=0;
        for(auto x:a)
        {
            ll gt=min(mid,(ll)x);
            sum+=gt;
            if(sum>=mid)
            {
                sum-=mid;
                cnt++;
            }
        }
        return cnt>=n;
    }

    long long maxRunTime(int n, vector<int>& a) 
    {
        sort(a.begin(),a.end());
        ll l=0,r=1e18;
        ll ans=0;
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            if(check(mid,a,n))
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
