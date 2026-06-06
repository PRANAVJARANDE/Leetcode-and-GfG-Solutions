class Solution {
public:
    vector<int> leftRightDifference(vector<int>&nums) 
    {
        int sum=0;
        for(auto x:nums)sum+=x;
        int cs=0;
        int n=nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            sum-=nums[i];
            ans[i]=abs(cs-sum);
            cs+=nums[i];
        }
        return ans;
    }
};
