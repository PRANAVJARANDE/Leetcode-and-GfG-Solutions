class Solution {
public:
    int minElement(vector<int>& nums) 
    {
        int mini=INT_MAX;
        for(auto x:nums)
        {
            int res=0;
            while(x)
            {
                res+=(x%10);
                x/=10;
            }
            mini=min(mini,res);
        }
        return mini;
    }
};
