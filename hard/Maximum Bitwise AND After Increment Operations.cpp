#define ll long long
class Solution {
public:

    ll convert(ll a, ll mask) {
        ll x=a;
        for(int b=31;b>=0;b--) 
        {
            if(mask & (1LL<<b)) 
            {
                if((x&(1LL<<b))==0) 
                {
                    x=((x>>b)+1)<<b;
                }
            }
        }
        return x-a;
    }

    int maximumAND(vector<int>& a, int k, int m) 
    {
        ll n=a.size();
        ll ans=0;
        for(int b=31;b>=0;b--)
        {
            ll res=ans | (1<<b);
            vector<int>ops;
            for(auto x:a)ops.push_back(convert(x,res));
            sort(ops.begin(),ops.end());
            ll sum=0;
            for(int i=0;i<m;i++)sum+=ops[i];
            if(sum<=k)ans=res;
        }
        return ans;
    }
};
