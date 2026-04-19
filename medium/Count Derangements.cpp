class Solution {
  public:
  
    int derangeCount(int n) 
    {
        if(n==1)return 0;
        if(n==2)return 1;
        int p1=0,p2=1;
        for(int i=3;i<=n;i++)
        {
            int res=(i-1)*(p1+p2);
            p1=p2;
            p2=res;
        }
        return p2;
    }
};
