class Solution {
public:
    int mirrorDistance(int n) {
        int r=0;
        int tp=n;
        while(tp)
        {
            r*=10;
            r+=tp%10;
            tp/=10;
        }
        return abs(n-r);
    }
};
