class Solution {
  public:
    int maxSum(int n) 
    {
        if(n==0)return 0;
        int ans=n;
        int b1=n/2;
        int b2=n/3;
        int b3=n/4;
        
        int op1=maxSum(b1);
        int op2=maxSum(b2);
        int op3=maxSum(b3);
        
        b1=max(b1,op1);
        b2=max(b2,op2);
        b3=max(b3,op3);
        
        ans=max(ans,b1+b2+b3);
        return ans;
    }
};
