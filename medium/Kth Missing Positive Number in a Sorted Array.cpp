class Solution {
  public:
    int kthMissing(vector<int> &a, int k) 
    {
        int in=1;
        for(auto x:a)
        {
            int missing=(x-in);
            if(k>missing)
            {
                k-=missing;
                in=x+1;
            }
            else
            {
                return in+k-1;
            }
        }
        return in+k-1;
    }
};
