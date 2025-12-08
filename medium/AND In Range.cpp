#define ll long long
class Solution {
  public:
    int andInRange(int l, int r) 
    {
        ll ans=0;
        for(ll i=0;i<31;i++)
        {
            ll tl1=l%(1ll<<(i+1));
            ll hf=(1ll<<i);
            if(tl1<hf)continue;
            
            ll tl2=tl1%hf;
            
            ll nx=l+(hf-tl2);
            if(nx>r)
            {
                ans = ans | (1ll<<i);   
            }
        }
        return ans;
    }
};
