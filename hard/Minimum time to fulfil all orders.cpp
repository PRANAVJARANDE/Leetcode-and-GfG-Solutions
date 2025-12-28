#define ll long long
class Solution {
  public:
  
    bool check(ll tm,vector<int>&a,ll n)
    {
        ll cnt=0;
        for(auto x:a)
        {
            ll l=0,r = sqrt((2.0 * tm) / x);;
            ll z=0;
            while(l<=r)
            {
                ll mid=l+(r-l)/2;
                if((((mid*(mid+1))/2)*x)<=tm)
                {
                    z=mid;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            cnt+=z;
        }
        
        return cnt>=n;
    }
  
  
    int minTime(vector<int>& a, int n) 
    {
        ll l=0;
        ll mn=*min_element(a.begin(),a.end());
        ll r = mn*(ll)n*(n+1)/2;
        int ans=r;
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            if(check(mid,a,n))
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
