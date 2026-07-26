class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) 
    {
        int n=arr.size();
        int cnt=1;
        vector<vector<int>>ans;
        for(int i=0;i<n;)
        {
            vector<int>res;
            int tk=cnt;
            while(i<n && tk--)
            {
                res.push_back(arr[i]);
                i++;
            }
            cnt*=2;
            sort(res.begin(),res.end());
            ans.push_back(res);
        }
        return ans;
    }
};
