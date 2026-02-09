class Solution {
  public:
    int maxSum(vector<int> &a) 
    {
        int cs=0,sum=a[0];
        int n=a.size();
        for(int i=1;i<n;i++)
        {
            cs+=i*a[i];
            sum+=a[i];
        }
        int ans=cs;
        for(int i=n-1;i>=0;i--)
        {
            cs-=((n-1)*a[i]);
            cs+=sum-a[i];
            ans=max(ans,cs);
        }
        return ans;
    }
};
