class Solution {
public:
    bool isGood(vector<int>& nums) 
    {
        int n=nums.size();
        int in=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==in)in++;
            else return 0;
        }
        return nums[n-1]==n-1;
    }
};
