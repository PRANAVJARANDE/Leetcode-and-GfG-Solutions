class Solution {
  public:
    
    bool check(int mid,vector<int>&a)
    {
        int cnt=0;
        for(auto x:a)
        {
            if(x>=mid)cnt++;
        }
        return cnt>=mid;
    }
  
    int hIndex(vector<int>& a) 
    {
        int n=a.size();
        int l=0,r=n;
        int ans=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,a))
            {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};
