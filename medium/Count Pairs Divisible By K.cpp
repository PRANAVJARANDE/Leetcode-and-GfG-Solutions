class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        int ans=0;
        map<int,int>m;
        for(auto x:arr)
        {
            x=x%k;
            int req=(k-x)%k;
            ans+=m[req];
            m[x]++;
        }
        return ans;
    }
};
