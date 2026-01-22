#define ll long long
class Solution {
public:
    int minimumPairRemoval(vector<int>& a) 
    {
        ll n=a.size();
        vector<ll>nxt(n,0),prev(n,0);
        vector<ll>nums(n);
        for(int i=0;i<n;i++)nums[i]=a[i];

        set<pair<ll,ll>>s1;
        map<ll,ll>m;
        set<ll>to_repair;

        for(ll i=0;i<n;i++)
        {
            if(i+1<n)
            {
                m[i]=nums[i]+nums[i+1];
                s1.insert({nums[i]+nums[i+1],i});
                if(nums[i]>nums[i+1])to_repair.insert(i);
            }
            nxt[i]=i+1;
            prev[i]=i-1;
        }

        ll ans=0;
        while(!to_repair.empty())
        {
            auto pr=*s1.begin();
            ll in=pr.second;
            ans++;

            s1.erase({m[in],in});
            to_repair.erase(in);

            s1.erase({m[nxt[in]], nxt[in]});
            to_repair.erase(nxt[in]);

            if(prev[in]!=-1)
            {
                s1.erase({m[prev[in]], prev[in]});
                to_repair.erase(prev[in]);
            }

            nums[in]+=nums[nxt[in]];
            nxt[in]=nxt[nxt[in]];
            if(nxt[in]<n)prev[nxt[in]]=in;
            
            if(prev[in]!=-1)
            {
                m[prev[in]]=(ll)nums[prev[in]] + nums[in];
                s1.insert({m[prev[in]], prev[in]});
                if(nums[prev[in]]>nums[in])to_repair.insert(prev[in]);
            }

            if(nxt[in]<n)
            {
                m[in]=(ll)nums[in]+nums[nxt[in]];
                s1.insert({m[in],in});
                if(nums[in]>nums[nxt[in]])to_repair.insert(in);
            }
        }
        return ans;
        
    }
};
