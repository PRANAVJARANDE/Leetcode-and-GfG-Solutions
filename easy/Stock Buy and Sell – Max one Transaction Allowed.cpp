class Solution {
  public:
    int maxProfit(vector<int> &prices) 
    {
        int pmin=INT_MAX;
        int ans=0;
        for(auto x:prices)
        {
            if(pmin!=INT_MAX)
            {
                ans=max(ans,x-pmin);
            }
            pmin=min(pmin,x);
        }
        return ans;
    }
};
