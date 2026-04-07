#define ll long long
class Solution {
public:
    int n;
    bool check(ll mid,vector<int>&c,vector<int>&r,ll b)
    {
        multiset<ll>s1;
        ll sum=0;
        for(int i=0;i<mid;i++)
        {
            sum+=r[i];
            s1.insert(c[i]);
        }
        if((*s1.rbegin())+(mid*sum)<=b)return 1;
        for(int i=mid;i<n;i++)
        {
            sum+=r[i]-r[i-mid];
            s1.insert(c[i]);
            s1.erase(s1.find(c[i-mid]));
            if((*s1.rbegin())+(mid*sum)<=b)return 1;
        }
        return 0;
    }

    int maximumRobots(vector<int>&c, vector<int>&rc,long long b) 
    {
        n=c.size();
        int ans=0;
        int l=1,r=n;

        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,c,rc,b))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};
