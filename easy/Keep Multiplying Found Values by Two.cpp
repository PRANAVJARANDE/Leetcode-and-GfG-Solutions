class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        for(auto x:nums)if(x==original)original*=2;
        return original;
    }
};
