class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int s=0;
        for(auto x:nums)s+=x;
        s%=k;
        return s;
    }
};
