class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) 
    {
        vector<int>ans;
        for(int i=nums.size()-1;i>=0;i--)
        {
            int x=nums[i];
            while(x)
            {
                int rem=x%10;
                ans.push_back(rem);
                x/=10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
