#define ll long long
class Solution {
public:
    const int MOD=1e9+7;
    long long sumAndMultiply(int n) 
    {
        ll res=0;
        ll sum=0;

        string s=to_string(n);
        for(ll i=0;i<s.size();i++)
        {
            if(s[i]=='0')continue;
            sum+=s[i]-'0';
            res=res*10;
            res+=s[i]-'0';
        }
        return res*sum;
    }
};

