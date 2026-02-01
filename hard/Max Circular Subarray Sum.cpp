class Solution {
  public:
    int maxCircularSum(vector<int> &a) 
    {
        int n=a.size();
        for(int i=0;i<n;i++)a.push_back(a[i]);
        vector<int>psum(2*n+1,0);
        for(int i=0;i<2*n;i++)psum[i+1]=a[i]+psum[i];
        int ans=INT_MIN;
        multiset<int>s1;
        s1.insert(0);
        for(int i=1;i<=2*n;i++)
        {
            if(i-n-1>=0)s1.erase(s1.find(psum[i-n-1]));
            int res=psum[i]-*s1.begin();
            ans=max(ans,res);
            s1.insert(psum[i]);
        }
        return ans;
    }
};
