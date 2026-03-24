#define ll long long
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& a) 
    {
        ll ans=0;
        ll loss=0;
        for(auto x:a)
        {
            ans=max(ans,(ll)x[0]);
            if(x[0]>=x[1])loss+=x[0]-x[1];
        }
        for(auto x:a)
        {
            if(x[0]>x[1])ans=max(ans,loss+x[1]);
            else ans=max(ans,loss+x[0]);
        }
        return ans;
    }
};
