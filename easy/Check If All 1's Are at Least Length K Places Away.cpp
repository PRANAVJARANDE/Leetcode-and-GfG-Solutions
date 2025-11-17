class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) 
    {
        int pv=k+1;
        for(auto x:nums)
        {
            if(x==0)pv++;
            else 
            {
                if(pv>=k)pv=0;
                else return 0;
            }
        }
        return 1;
    }
};
