#define ll long long
class Solution {
public:

    static vector<int>v1;

    static vector<int> precompute()
    {
        map<ll,ll>m;
        for(ll i=0;i<=1000;i++)
        {
            for(ll j=i+1;j<=1000;j++)
            {
                ll res=(i*i*i)+(j*j*j);
                if(res>1e9)break;
                m[res]++;
            }
        }
        vector<int>temp;
        for(auto x:m)if(x.second>=2)temp.push_back(x.first);
        return temp;
    } 

    vector<int> findGoodIntegers(int n) 
    {
        vector<int>ans;
        for(auto x:v1)
        {
            if(x<=n)ans.push_back(x);
            else break;
        }
        return ans;
    }
};

vector<int> Solution::v1 = Solution::precompute();
