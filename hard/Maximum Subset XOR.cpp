class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) 
    {
        int n=arr.size();
        int in=0;
        for(int b=20;b>=0 && in<n;b--)
        {
            int mx=in;
            for(int i=in;i<n;i++)
            {
                if(arr[i] & (1<<b) && arr[i]>arr[mx])
                {
                    mx=i;
                }
            }
            
            if(!(arr[mx] & (1<<b)))continue;
            
            swap(arr[in],arr[mx]);
            
            for(int i=0;i<n;i++)
            {
                if(i!=in && (arr[i] & (1<<b)))
                {
                    arr[i]^=arr[in];
                }
            }
            in++;
            
        }
        
        int ans=0;
        for(auto x:arr)ans^=x;
        return ans;
        
    }
};
