class Solution {
  public:
    
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])
        {
            return a[1]<b[1];
        }
        else 
        {
            return a[0]>b[0];
        }
    }
  
    vector<int> sortBySetBitCount(vector<int>& arr) 
    {
        int n=arr.size();
        vector<vector<int>>v1(n,vector<int>(2,0));
        for(int i=0;i<n;i++)
        {
            v1[i][0]=__builtin_popcount(arr[i]);
            v1[i][1]=i;
        }
        sort(v1.begin(),v1.end(),cmp);
        vector<int>res(n,0);
        for(int i=0;i<n;i++)res[i]=arr[v1[i][1]];
        return res;
    }
};
