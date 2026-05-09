#define ll long long
class Solution {
public:
    long long appealSum(string s) 
    {
        ll n=s.size();
        ll ans=0;
        for(char c='a';c<='z';c++)
        {
            ll sum=(n*(n+1))/2;
            ll cnt=0;
            for(int i=0;i<n;i++)
            {
                if(s[i]==c)cnt=0;
                else cnt++;
                sum-=cnt;
            }
            ans+=sum;
        }
        return ans;        
    }
};
