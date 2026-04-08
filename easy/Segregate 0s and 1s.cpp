class Solution {
  public:
    void segregate0and1(vector<int> &arr) 
    {
        int n=arr.size();
        int r=n-1;
        for(int i=0;i<n;i++)
        {
            if(arr[i])
            {
                while(r>=0 && arr[r]==1)r--;
                if(r>=0 && i<=r)swap(arr[i],arr[r]);
            }
        }
    }
};
