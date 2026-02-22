class Solution {
  public:
    long subarrayXor(vector<int> &a, int k) {
        map<int,int>m;
        m[0]++;
        int xs=0,ans=0;
        for(auto x:a)
        {
            xs=xs^x;
            ans+=m[xs^k];
            m[xs]++;
        }
        return ans;
    }
};
