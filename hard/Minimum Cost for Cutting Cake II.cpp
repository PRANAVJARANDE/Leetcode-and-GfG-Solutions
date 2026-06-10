#define ll long long
class Solution {
public:

    long long minimumCost(int m, int n, vector<int>& v1, vector<int>& v2) 
    {
        vector<vector<ll>>cuts;
        for(auto x:v1)cuts.push_back({x,0});
        for(auto x:v2)cuts.push_back({x,1});
        sort(cuts.begin(),cuts.end(),greater<vector<ll>>());

        ll ans=0;
        ll p0=0,p1=0;
        for(auto x:cuts)
        {
            //cout<<x[0]<<" "<<x[1]<<endl;
            ll ct=p0+1;
            if(x[1]==0)ct=p1+1;
            ans+=x[0]*ct;
            if(x[1]==0)p0++;
            else p1++;
        }
        return ans;
    }
};
