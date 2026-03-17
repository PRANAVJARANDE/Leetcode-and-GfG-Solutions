class Solution {
public:
    int bitwiseComplement(int n) 
    {
        if(n==0)return 1;
        int ans=0;
        int in=0;
        while(n)
        {
            if(n%2==0)ans=ans | (1<<in);
            in++;
            n/=2;
        }
        return ans;
    }
};
