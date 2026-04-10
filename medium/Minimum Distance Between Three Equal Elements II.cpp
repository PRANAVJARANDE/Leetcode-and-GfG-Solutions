class Solution {
public:
    int minimumDistance(vector<int>& nums) 
    {
        map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++)m[nums[i]].push_back(i);
        int ans=INT_MAX;
        for(auto x:m)
        {
            for(int i=1;i<((x.second).size())-1;i++)
            {
                int d1=abs((x.second)[i]-(x.second)[i-1]);
                int d2=abs((x.second)[i+1]-(x.second)[i]);
                int d3=abs((x.second)[i+1]-(x.second)[i-1]);
                ans=min(ans,d1+d2+d3);
            }
        }
        if(ans==INT_MAX)ans=-1;
        return ans;
    }
};
