class Solution {
  public:
    
    int getcost(int k,vector<int>&h,vector<int>&c)
    {
        int ans=0;
        for(int i=0;i<c.size();i++)
        {
            ans+=(abs(k-h[i]))*c[i];
        }
        return ans;
    }
  
    int minCost(vector<int>& h, vector<int>& c) 
    {
        int n=c.size();
        int l=INT_MAX,r=INT_MIN;
        for(int i=0;i<n;i++)
        {
            l=min(l,h[i]);
            r=max(r,h[i]);
        }
        int ans=INT_MAX;
        while(l<=r)
        {
            int mid1=l+((r-l)/3);
            int mid2=r-((r-l)/3);
            int c1=getcost(mid1,h,c);
            int c2=getcost(mid2,h,c);
            ans=min(ans,min(c1,c2));
            if(c1<c2)
            {
                r=mid2-1;
            }
            else
            {
                l=mid1+1;
            }
        }
        return ans;
    }
};
