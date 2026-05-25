#define ll long long
class Solution {
public:
    const int MOD=1e9+7;
    int countPalindromes(string s) 
    {
        int n=s.size();
        vector<vector<ll>>dp1(n,vector<ll>(100,0));
        vector<ll>cnt1(10,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<100;j++)if(i-1>=0)dp1[i][j]=((dp1[i][j]%MOD) + (dp1[i-1][j]%MOD))%MOD;
            for(int j=0;j<10;j++)
            {
                ll v=cnt1[j];
                ll num=(j*10)+s[i]-'0';
                dp1[i][num]=((dp1[i][num]%MOD) + (v%MOD))%MOD;
            }
            cnt1[s[i]-'0']++;
        }

        vector<vector<ll>>dp2(n,vector<ll>(100,0));
        vector<ll>cnt2(10,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<100;j++)if(i+1<n)dp2[i][j]=((dp2[i][j]%MOD) + (dp2[i+1][j]%MOD))%MOD;
            for(int j=0;j<10;j++)
            {
                ll v=cnt2[j];
                ll num=((s[i]-'0')*10)+j;
                dp2[i][num]=((dp2[i][num]%MOD)+(v%MOD))%MOD;
            }
            cnt2[s[i]-'0']++;
        }

        ll ans=0;
        for(int i=1;i<n-1;i++)
        {
            for(int j=0;j<100;j++)
            {
                int p1=j;
                int p2=(10*(j%10))+(j/10);
                ll res=dp1[i-1][p1]*dp2[i+1][p2];
                ans=((ans%MOD)+(res%MOD))%MOD;
            }
        }
        return ans;
    }
};
