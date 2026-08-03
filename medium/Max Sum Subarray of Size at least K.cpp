class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) 
    {
        int n=arr.size();
        int ans=INT_MIN;
        int mini=INT_MAX;
        
        int sum=0;
        vector<int>psum(n,0);
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            psum[i]=sum;
            if(i-k>=-1)
            {
                if(i-k==-1)mini=0;
                else mini=min(mini,psum[i-k]);
                ans=max(ans,sum-mini);
            }
        }
        return ans;
        
    }
};
