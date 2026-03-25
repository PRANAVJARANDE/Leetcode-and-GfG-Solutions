#define ll long long
class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& a, vector<int>& q) 
    {
        ll n=a.size();
        set<ll>s1;
        s1.insert(-1);
        s1.insert(n);
        vector<ll>nums(n,0);
        nums[0]=a[0];
        for(int i=1;i<n;i++)nums[i]=nums[i-1]+a[i];
        multiset<ll>sums;
        sums.insert(nums[n-1]);
        vector<ll>ans;

        for(auto x:q)
        {
            auto itr=s1.upper_bound(x);
            ll r=(*itr)-1;
            itr--;
            ll l=(*itr)+1;
            ll cs=nums[r];
            if(l-1>=0)cs-=nums[l-1];

            sums.erase(sums.find(cs));
            s1.insert(x);

            if(l<=x-1)
            {
                ll sum1=nums[x-1];
                if(l-1>=0)sum1-=nums[l-1];
                sums.insert(sum1);
            }

            if(x+1<=r)
            {
                ll sum2=nums[r]-nums[x];
                sums.insert(sum2);
            }

            ans.push_back(sums.empty() ? 0 : *sums.rbegin());         
        }
        return ans;
    }
};
