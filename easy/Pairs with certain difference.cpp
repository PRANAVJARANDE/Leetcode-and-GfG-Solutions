class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) 
    {
        int ans=0;
        int n=arr.size();
        sort(arr.begin(),arr.end(),greater<int>());
        for(int i=0;i<n-1;)
        {
            if(abs(arr[i]-arr[i+1])<k)
            {
                ans+=arr[i]+arr[i+1];
                i+=2;
            }
            else i++;
        }
        return ans;
    }
};
