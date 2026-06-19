class Solution {
public:
    int largestAltitude(vector<int>& a) 
    {
        int h=0;
        int ans=0;
        for(auto x:a)
        {
            h+=x;
            ans=max(ans,h);
        }
        return ans;
    }
};
