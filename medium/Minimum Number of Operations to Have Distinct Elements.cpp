#define ll long long
class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        map<ll,ll>m;
        for(auto x:nums)m[x]++;
        ll n=nums.size();
        ll ans=0;
        for(ll i=0;i<n;i+=3)
        {   
            if(m.size()==(n-i))break;
            for(ll j=i;j<min(i+3,n);j++)
            {
                m[nums[j]]--;
                if(m[nums[j]]==0)m.erase(nums[j]);
            }
            ans++;
        }
        return ans;
            
    }

};
