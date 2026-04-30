class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) 
    {
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            int lc=INT_MIN,rc=INT_MIN;
            if(2*i+1<n)lc=arr[2*i+1];
            if(2*i+2<n)rc=arr[2*i+2];
            
            if(arr[i]<lc || arr[i]<rc)return 0;
            
        }
        return 1;
        
    }
};
