class Solution {
  public:
    int minToggle(vector<int>& arr) {
        int zc=0;
        for(auto x:arr)zc+=1-x;
        int ans=min(zc,(int)arr.size()-zc);
        int oc=0;
        for(auto x:arr)
        {
            if(x==0)zc--;
            else oc++;
            ans=min(ans,zc+oc);
        }
        return ans;
    }
};
