class Solution {
  public:
    int countSubarray(vector<int>& arr, int l, int r) 
    {
        int n=arr.size();
        int p1=0,p2=0;
        int cs1=0,cs2=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cs1+=arr[i];
            while(cs1>r)
            {
                cs1-=arr[p1];
                p1++;
            }
            
            cs2+=arr[i];
            while(cs2>=l)
            {
                cs2-=arr[p2];
                p2++;
            }
            ans+=max(0,abs(p1-p2));
            
        }
        return ans;
       
    }
};
