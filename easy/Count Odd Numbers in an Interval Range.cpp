class Solution {
public:
    int countOdds(int l, int h) 
    {
        if(l%2==0)l++;
        int diff=h-l+1;
        int ans=diff/2;
        if(diff%2)ans++;
        return ans;
    }
};
