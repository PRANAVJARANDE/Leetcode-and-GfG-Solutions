class Solution {
  public:
  
    int bitonic(vector<int> &arr) 
    {
        int n=arr.size();
        vector<int>v1(n,0);
        vector<int>v2(n,n-1);
        
        for(int i=1;i<n;i++)
        {
            v1[i]=v1[i-1];
            if(arr[i-1]>arr[i])v1[i]=i;
        }
        
        for(int i=n-2;i>=0;i--)
        {
            v2[i]=v2[i+1];
            if(arr[i]<arr[i+1])v2[i]=i;
        }
        
        
        int ans=1;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,v2[i]-v1[i]+1);
        }
        return ans;
        
    }
};
