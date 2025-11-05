#define ll long long
class Solution {
public:

    ll ans;
    map<ll,ll>m;
    set<pair<ll,ll>>s1;
    set<pair<ll,ll>>s2;
    int x;
    void insert(ll val)
    {
        if(m[val]>0)
        {
            if(s1.find({m[val],val})!=s1.end())
            {
                s1.erase({m[val],val});
                ans-=(m[val]*val);
            }
            else s2.erase({m[val],val});
        }
        m[val]++;
        s1.insert({m[val],val});
        ans+=(m[val]*val);
        while(s1.size()>x)
        {
            auto pr=*s1.begin();
            ans-=((pr.first)*(pr.second));
            s1.erase(pr);
            s2.insert(pr);
        }
    }

    void erase(ll val)
    {
        if(m[val]==0)return;
        if(s1.find({m[val],val})!=s1.end())
        {
            s1.erase({m[val],val});
            ans-=(m[val]*val);
        }
        else s2.erase({m[val],val});
        m[val]--;
        if(m[val]==0)m.erase(val);
        else s2.insert({m[val],val});
        if(s1.size()<x && !s2.empty())
        {
            auto pr=*s2.rbegin();
            s1.insert(pr);
            ans+=(pr.first*pr.second);
            s2.erase(pr);
        }
    }

    vector<long long> findXSum(vector<int>& nums, int k, int xx) 
    {
        int n=nums.size();
        x=xx;
        ans=0;
        for(int i=0;i<k;i++)insert(nums[i]);
        vector<ll>res;
        res.push_back(ans);


        for(int i=k;i<n;i++)
        {
            erase(nums[i-k]);
            insert(nums[i]);
            res.push_back(ans);
        }
        return res;
    }
};
