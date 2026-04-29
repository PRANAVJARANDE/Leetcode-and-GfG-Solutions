class Solution {
  public:
    int minSwaps(vector<int>& arr) 
    {
        int n=arr.size();
        int s=0;
        for(auto x:arr)s+=x;
        
        int cs=0;
        for(int i=0;i<s;i++)
        {
            cs+=arr[i];
        }
        if(s==0)return -1;
        int ans=s-cs;
        
        for(int i=s;i<arr.size();i++)
        {
            cs+=arr[i]-arr[i-s];
            ans=min(ans,s-cs);
        }
        return ans;
    }
};
