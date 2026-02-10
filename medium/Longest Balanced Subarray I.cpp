class Solution {
public:
    int longestBalanced(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            map<int,int>od,ev;
            for(int j=i;j<n;j++)
            {
                if(nums[j]%2)od[nums[j]]++;
                else ev[nums[j]]++;
                if(od.size()==ev.size())ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};
