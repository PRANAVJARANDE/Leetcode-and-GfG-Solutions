class Solution {
  public:
    int findPosition(int n) 
    {
        if(n==0)return -1;
        if((n & (n-1)))return -1;
        
        int cnt=0;
        while(n)
        {
            cnt++;
            n/=2;
        }
        return cnt;
        
    }
};
