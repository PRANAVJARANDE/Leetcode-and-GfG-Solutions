class Solution {
public:
    int longestSubsequence(vector<int>& nums) 
    {
        int ans=0;
        for(int b=0;b<32;b++)
        {
            int res=0;
            int od=0;
            for(auto x:nums)
            {
                if(x & (1<<b))od++;
                else res++;
            }
            if(od!=0 && od%2==0)od--;
            res+=od;
            if(od!=0)ans=max(ans,res);
        }
        return ans;
    }
};
