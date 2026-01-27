class Solution {
  public:
    
    long long helper(int open,int n)
    {
        if(n==0)
        {
            if(open==0)return 1;
            return 0;
        }
        long long ans=0;
        if(open>0)ans+=helper(open-1,n-1);
        ans+=helper(open+1,n-1);
        return ans;
    }
  
    int findWays(int n) 
    {
        return helper(0,n);
    }
};
