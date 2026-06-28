class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& a) 
    {
        sort(a.begin(),a.end());
        int in=1;
        for(auto x:a)
        {
            if(in<=x)in++;
        }
        return in-1;
    }
};
