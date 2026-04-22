class Solution {
  public:
    vector<int> findMean(vector<int> &a, vector<vector<int>> &queries) 
    {
       for(int i=1;i<a.size();i++)a[i]+=a[i-1];
       vector<int>res;
       for(auto x:queries)
       {
           int sum=a[x[1]];
           if(x[0]-1>=0)sum-=a[x[0]-1];
           int avg=sum/(x[1]-x[0]+1);
           res.push_back(avg);
       }
       return res;
    }
};
