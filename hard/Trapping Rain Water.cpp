class Solution {
  public:
    int maxWater(vector<int> &arr) 
    {
        int ans=0;
        int n=arr.size();
        
        vector<int>pmax(n,0);
        int pmini=INT_MIN;
        for(int i=0;i<n;i++)
        {
            pmax[i]=pmini;
            pmini=max(pmini,arr[i]);
        }
        
        int nmini=INT_MIN;
        vector<int>nmax(n,0);
        for(int i=n-1;i>=0;i--)
        {
            nmax[i]=nmini;
            nmini=max(nmini,arr[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            int w=min(pmax[i],nmax[i]);
            if(w==INT_MIN)continue;
            ans+=max(0,w-arr[i]);
        }
        return ans;
    }
};
