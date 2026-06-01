class Solution {
  public:
  
    const int MOD=1e9+7;
    int findMaxProduct(vector<int>& arr) {
        vector<int>neg,pos;
        int maxi=INT_MIN;
        for(auto x:arr)
        {
            if(x>0)pos.push_back(x);
            else if(x<0) neg.push_back(x);
            maxi=max(maxi,x);
        }
        sort(neg.begin(),neg.end());
        if(neg.size()%2)neg.pop_back();
        int ans=maxi;
        long long p=1;
        for(auto x:pos)p=((p%MOD)*(x%MOD))%MOD;
        for(auto x:neg)p=(p*((x%MOD+MOD)%MOD))%MOD;
        if(pos.size()==0 && neg.size()==0)return maxi;
        return p;
    }
};
