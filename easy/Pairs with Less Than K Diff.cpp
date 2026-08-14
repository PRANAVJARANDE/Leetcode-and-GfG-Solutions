class Solution {
  public:
    int countPairs(vector<int>& a, int k) {
        sort(a.begin(),a.end());
        int ans=0;
        int l=0;
        for(int i=0;i<a.size();i++)
        {
            while(abs(a[l]-a[i])>=k)l++;
            ans+=max(0,i-l);
        }
        return ans;
    }
};
