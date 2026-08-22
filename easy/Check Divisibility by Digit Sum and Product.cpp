class Solution {
public:
    bool checkDivisibility(int n) 
    {
        int pn=n;
        int s1=0;
        int s2=1;
        while(n)
        {
            int rem=n%10;
            s1+=rem;
            s2*=rem;
            n/=10;
        }

        if(pn%(s1+s2)==0)return 1;
        return 0;
        
    }
};
