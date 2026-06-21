#define ll long long
class Solution {
public:

    ll helper(ll in,ll pv,bool flag,string&s,ll k,vector<vector<vector<ll>>>&dp)
    {
        if(in>=s.size())return 1;
        if(dp[in][pv][flag]!=-1)return dp[in][pv][flag];
        int mx=9;
        if(flag)mx=s[in]-'0';
        ll ans=0;
        for(int i=0;i<=mx;i++)
        {
            if(in==0 || pv==10 || abs(i-pv)<=k)
            {
                bool nflag=0;
                if(flag && i==s[in]-'0')nflag=1;
                int npv=10;
                if(i==0 && pv==10)npv=10;
                else npv=i;
                ans+=helper(in+1,npv,nflag,s,k,dp);
            }
        }
        return dp[in][pv][flag]=ans;
    }

    long long goodIntegers(long long l, long long r, int k) 
    {
        l--;
        string s1=to_string(r);
        string s2=to_string(l);
        while(s1.size()!=s2.size())
        {
            s2="0"+s2;
        }
        ll sz=s1.size();
        vector<vector<vector<ll>>>dp1(sz,vector<vector<ll>>(11,vector<ll>(2,-1)));
        vector<vector<vector<ll>>>dp2(sz,vector<vector<ll>>(11,vector<ll>(2,-1)));
        ll ans=helper(0,10,1,s1,k,dp1)-helper(0,10,1,s2,k,dp2);
        return ans;
    }
};
