class Solution {
  public:
    int countSetBits(int n) 
    {
        int ans=0;
        for(int i=1;i<=30;i++)
        {
            int hf=(1<<i);
            ans+=(((n+1)/hf))*(hf/2);
            int rem=(n+1)%hf;
            ans+=max(0,rem-(hf/2));
        }
        return ans;
    }
};
