#define ll long long
class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) 
    {
        map<ll,ll>m;
        if(target==0)
        {
            for(auto x:arr)if(x==0)return 1;
            return 0;
        }
        for(auto x:arr)
        {
            if(x==0)continue;
            if(target%x==0)
            {
                ll req=target/x;
                if(m[req])return 1;
            }
            m[x]++;
        }
        return 0;
    }
};
