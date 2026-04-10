class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) 
    {
        int n=arr.size();
        vector<int>pmin(n);
        vector<int>nmax(n);
        
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            pmin[i]=mini;
            mini=min(mini,arr[i]);
        }
        for(int i=n-1;i>=0;i--)
        {
            nmax[i]=maxi;
            maxi=max(maxi,arr[i]);
        }
        
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(pmin[i]<arr[i] && arr[i]<nmax[i])
            {
                ans={pmin[i],arr[i],nmax[i]};
                return ans;
            }
        }
        return ans;
    }
};
