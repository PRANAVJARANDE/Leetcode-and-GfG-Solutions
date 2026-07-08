#define ll long long
class Solution {
public:

    const int MOD=1e9+7;

    ll mod_pow(ll a,ll b)
    {
        ll res=1;
        while(b)
        {
            if(b&1)res=(res*a)%MOD;
            a=(a*a)%MOD;
            b>>=1;
        }
        return res;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) 
    {
        int n=s.size();
        vector<ll>ssum(n,0);
        vector<int>cnt(n,0);

        int rem=0;
        for(int i=n-1;i>=0;i--)
        {
            ssum[i]=(mod_pow(10,rem)*(s[i]-'0'))%MOD;
            if(s[i]!='0')rem++;
            if(i+1<n)ssum[i]=(ssum[i]+ssum[i+1])%MOD;
            cnt[i]=rem;
        }

        vector<int>psum(n,0);
        psum[0]=s[0]-'0';
        for(int i=1;i<n;i++)
            psum[i]=(psum[i-1]+(s[i]-'0'))%MOD;

        vector<int>ans;
        for(auto x:queries)
        {
            int l=x[0];
            int r=x[1];

            ll res=ssum[l];
            if(r+1<n)
            {
                res=(res-ssum[r+1]+MOD)%MOD;
                res=(res*mod_pow(mod_pow(10,cnt[r+1]),MOD-2))%MOD;
            }
            int cs=psum[r];
            if(l-1>=0)cs-=psum[l-1];
            res=((res%MOD)*(cs%MOD))%MOD;
            ans.push_back(res);
        }
        return ans;
    }
};
