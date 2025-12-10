class Solution {
public:

    int help(int n) 
    {
        int ans=0;
        while(n) 
        {
            ans++;
            n>>=1;
        }
        return ans-1;
    }

    int minimumOneBitOperations(int n) 
    {
        if(n==0)return 0;
        int ans=0;
        int sign=1;
        while(n>0) 
        {
            int k=help(n);
            ans+=sign*((1<<(k+1))-1);
            n^=(1<<k);
            sign*=-1;
        }
        return ans;
    }
};
