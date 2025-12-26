class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& a) 
    {
        int n=a.size();
        int m=a[0].size();
        
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int maxi=INT_MIN;
            int ind=-1;
            for(int j=0;j<m;j++)
            {
                if(a[mid][j]>maxi)
                {
                    maxi=a[mid][j];
                    ind=j;
                }
            }
            
            int up=INT_MIN,down=INT_MIN;
            if(mid-1>=0)up=a[mid-1][ind];
            if(mid+1<n)down=a[mid+1][ind];
            
            if(a[mid][ind]>=up && a[mid][ind]>=down)return {mid,ind};
            if(down>a[mid][ind])l=mid+1;
            else r=mid-1;
        }
        return {-1,-1};
        
    }
};
