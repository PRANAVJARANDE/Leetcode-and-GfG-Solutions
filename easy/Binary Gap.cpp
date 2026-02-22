class Solution {
public:
    int binaryGap(int n) 
    {
        int in=0;
        int pv=-1;
        int ans=0;
        while(n)
        {
            if(n%2)
            {
                if(pv==-1)pv=in;
                else 
                {
                    ans=max(ans,in-pv);
                    pv=in;
                }
            }
            n/=2;
            in++;
        }
        return ans;
    }
};
