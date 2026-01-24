class Solution {
  public:
    int josephus(int n, int k) 
    {
        int i=1,ans=0;
        while (i<=n) 
        {
            ans=(ans+k)%i;
            i++;
        }
        return ans+1;
    }
};
