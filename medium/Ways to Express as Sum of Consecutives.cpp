#define ll long long
class Solution {
  public:
    int getCount(int n) 
    {
        int ans=0;
        ll k=2;
        while(((k*(k-1))/2)<n)
        {
            ll temp=(k*(k-1))/2;
            if((n-temp)%k==0)ans++;
            k++;
        }
        return ans;
    }
};
