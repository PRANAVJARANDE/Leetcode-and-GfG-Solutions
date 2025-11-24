class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int v=0;
        for(auto x:nums) 
        {
            v=(v*2+x)%5;
            ans.push_back(v==0);
        }
        return ans;
    }
};
