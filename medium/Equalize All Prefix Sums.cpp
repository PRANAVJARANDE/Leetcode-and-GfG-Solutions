class Solution {
  public:
    vector<int> optimalArray(vector<int> &a) 
    {
        int n=a.size();
        vector<int>ans(n,0);
        vector<int>psum(n,0);
        psum[0]=a[0];
        for(int i=1;i<n;i++)psum[i]=a[i]+psum[i-1];
        
        for(int i=0;i<n;i++)
        {
            int hf=i/2;
            int res=((hf+1)*a[hf])-psum[hf];
            res+=(psum[i]-psum[hf])-((i-hf)*a[hf]);
            ans[i]=res;
        }
        return ans;
    }
};
