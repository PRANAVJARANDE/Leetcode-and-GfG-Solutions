class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        int ans=0;
        int cnt=1;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i-1]<arr[i])cnt++;
            else cnt=1;
            ans+=cnt-1;
        }
        return ans;
    }
};
