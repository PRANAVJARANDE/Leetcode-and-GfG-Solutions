class Solution {
  public:
    int maxSubarraySum(vector<int>& a, int k) {
        int sum=0;
        for(int i=0;i<k;i++)sum+=a[i];
        int ans=sum;
        for(int i=k;i<a.size();i++)
        {
            sum+=a[i]-a[i-k];
            ans=max(ans,sum);
        }
        return ans;
    }
};
