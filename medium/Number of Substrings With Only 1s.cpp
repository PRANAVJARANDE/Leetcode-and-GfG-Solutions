class Solution {
public:
    int numSub(string s) 
    {
        const int MOD=1e9+7;
        int cnt=0;
        int ans=0;
        for(auto x:s)
        {
            if(x=='1')cnt++;
            else cnt=0;
            ans=((ans%MOD)+(cnt%MOD))%MOD;
        }
        return ans;
    }
};
