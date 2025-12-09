#define ll long long
class Solution {
public:
    int smallestRepunitDivByK(int k) 
    {
        if(k%2==0 || k%5==0)return -1;
        ll i=1;
        int ans=1;
        while(i%k)
        {
            i=i%k;
            ans++;
            i*=10;
            i++;
        }
        return ans;
    }
};
