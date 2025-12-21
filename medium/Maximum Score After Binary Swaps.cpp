#define ll long long
class Solution {
public:
    
    int maximumSum(vector<int>& nums) 
    {
        map<ll,vector<ll>>m;
        for(auto x:nums)m[x%3].push_back(x);
        
        for(auto &x:m)sort(x.second.rbegin(),x.second.rend());
    
        ll ans=0;
        if(m[0].size()>=3)ans=max(ans,m[0][0]+m[0][1]+m[0][2]);
        if(m[1].size()>=3)ans=max(ans,m[1][0]+m[1][1]+m[1][2]);
        if(m[2].size()>=3)ans=max(ans,m[2][0]+m[2][1]+m[2][2]);
        if(m[0].size()>=1 && m[1].size()>=1 && m[2].size()>=1)ans=max(ans,m[0][0]+m[1][0]+m[2][0]);
        return ans;
    }
};
