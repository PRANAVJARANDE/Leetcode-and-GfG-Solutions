class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) 
    {
        vector<int>od,ev,tod,tev;
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());
        for(auto x:nums)
        {
            if(x%2)od.push_back(x);
            else ev.push_back(x);
        }
        for(auto x:target)
        {
            if(x%2)tod.push_back(x);
            else tev.push_back(x);
        }
        
        long long ans=0;
        for(int i=0;i<ev.size();i++)ans+=max(0,ev[i]-tev[i]);
        for(int i=0;i<od.size();i++)ans+=max(0,od[i]-tod[i]);
        ans/=2;
        return ans;
    }
};
