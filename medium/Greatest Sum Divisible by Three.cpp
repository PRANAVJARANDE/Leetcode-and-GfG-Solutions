class Solution {
public:
    int maxSumDivThree(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<int>v1,v2;
        int s=0;
        for(auto x:nums)
        {
            s+=x;
            if(x%3==1)v1.push_back(x);
            else if(x%3==2)v2.push_back(x);
        }
        if(s%3==0)return s;
        if(s%3==1)
        {
            int ans=0;
            if(v2.size()>=2)ans=max(ans,s-v2[0]-v2[1]);
            if(v1.size()>=1)ans=max(ans,s-v1[0]);
            return ans;
        }
        int ans=0;
        if(v1.size()>=2)ans=max(ans,s-v1[0]-v1[1]);
        if(v2.size()>=1)ans=max(ans,s-v2[0]);
        return ans;
    }
};
