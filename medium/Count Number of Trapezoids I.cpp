#define ll long long
class Solution {
public:

    const int MOD=1e9+7;
    int countTrapezoids(vector<vector<int>>& a) 
    {
        map<ll,ll>m;
        for(auto x:a)m[x[1]]++;
        ll ans=0;
        ll ps=0;
        for(auto x:m)
        {
            ll cnt=(x.second*(x.second-1))/2;
            ans=((ans%MOD)+((cnt%MOD)*(ps%MOD))%MOD)%MOD;
            ps=((ps%MOD)+(cnt%MOD))%MOD;
        }
        return ans;
    }
};
