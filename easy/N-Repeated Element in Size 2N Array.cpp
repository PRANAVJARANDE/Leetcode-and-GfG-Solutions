class Solution {
public:
    int repeatedNTimes(vector<int>& nums) 
    {
        int n=nums.size();
        for(int i=0;i<n;i++)if(nums[i]==nums[(i+1)%n])return nums[i];
        for(int i=0;i<n;i++)if(nums[(i+1)%n]==nums[(i-1+n)%n])return nums[(i+1)%n];
        return -1;
    }
};
