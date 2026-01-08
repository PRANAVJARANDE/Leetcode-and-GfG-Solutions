class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        map<int,int>m;
        m[0]=1;
        int sum=0;
        int ans=0;
        for(auto x:arr)
        {
            if(x%2)sum++;
            ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};
