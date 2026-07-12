#define ll long long
class Solution {
  public:
    const int MOD=1e9+7;
    int maxAmount(vector<int>& arr, int k) 
    {
        ll n=arr.size();
        sort(arr.begin(),arr.end());
        ll ans=0;
        ll maxi=arr.back();
        
        for(int j=maxi;j>0 && k>0;j--)
        {
            auto in=lower_bound(arr.begin(),arr.end(),j)-arr.begin();
            ll tm=min(n-in,(ll)k);
            ans=((ans%MOD)+((j%MOD)*(tm%MOD))%MOD)%MOD;
            k-=tm;
        }
        return ans;
    }
};
