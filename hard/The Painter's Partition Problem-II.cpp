class Solution {
  public:
    
    bool check(int mid,vector<int>&arr,int k)
    {
        int cnt=1;
        int cs=0;
        for(auto x:arr)
        {
            cs+=x;
            if(cs>mid)
            {
                cnt++;
                cs=x;
            }
        }
        return cnt<=k;
    }
  
    int minTime(vector<int>& arr, int k) 
    {
        int l=0,r=0;
        for(auto x:arr)
        {
            r+=x;
            l=max(l,x);
        }
        int ans=r;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,arr,k))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
