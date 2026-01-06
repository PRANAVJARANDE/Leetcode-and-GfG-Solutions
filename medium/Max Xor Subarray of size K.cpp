class Solution {
  public:
    int maxSubarrayXOR(vector<int>& a, int k) 
    {
        int n=a.size();
        int xs=0;
        for(int i=0;i<k;i++)xs=xs^a[i];
        int ans=xs;
        for(int i=k;i<n;i++)
        {
            xs=xs^a[i]^a[i-k];
            ans=max(ans,xs);
        }
        return ans;
    }
};
