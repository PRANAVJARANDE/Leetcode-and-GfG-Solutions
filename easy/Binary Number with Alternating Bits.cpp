class Solution {
public:
    bool hasAlternatingBits(int n)
    {
        int rem=n%2;
        n/=2;
        while(n)
        {
            int r=n%2;
            if(rem==r)return 0;
            rem=r;
            n/=2;
        }
        return 1;
    }
};
