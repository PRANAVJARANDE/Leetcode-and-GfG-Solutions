class Solution {
public:
    bool isTrionic(vector<int>& nums) 
    {
        int n=nums.size();
        for(int i=0;i<n-1;i++)if(nums[i]==nums[i+1])return 0;
        int l=-1;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                l=i;
                break;
            }
        }
        if(l==0 || l==-1)return 0;

        int r=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<nums[i-1])
            {
                r=i;
                break;
            }
        }
        if(r==-1 || r==n-1)return 0;

        for(int j=l+1;j<=r;j++)
        {
            if(nums[j-1]<=nums[j])return 0;
        }
        return 1;
    }
};
