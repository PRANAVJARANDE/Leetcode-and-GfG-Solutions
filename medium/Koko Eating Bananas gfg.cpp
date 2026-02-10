class Solution {
  public:
    
    bool check(int mid,vector<int>&a,int k)
    {
        for(auto x:a)
        {
            int tm=x/mid;
            if(x%mid)tm++;
            k-=tm;
        }
        return k>=0;
    }
  
    int kokoEat(vector<int>& a, int k) 
    {
        int n=a.size();
        int l=1,r=1e9;
        int ans=r;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,a,k))
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
