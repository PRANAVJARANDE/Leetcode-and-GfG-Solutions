class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) 
    {
        long long maxi=INT_MIN,mini=INT_MAX;
        for(auto x:nums)
        {
            maxi=max(maxi,(long long)x);
            mini=min(mini,(long long)x);
        }
        long long ans=(maxi-mini)*k;
        return ans;
    }
};
