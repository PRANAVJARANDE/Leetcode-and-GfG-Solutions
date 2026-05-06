class Solution {
public:
    int maxRotateFunction(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=0;
        int sum=0;
        vector<int>nsum(n,0);
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            ans+=(nums[i]*i);
        }
        int res=ans;
        for(int i=1;i<n;i++)
        {
            ans-=sum;
            ans+=(n*nums[i-1]);
            res=max(res,ans);
        }
        return res;
    }
};
