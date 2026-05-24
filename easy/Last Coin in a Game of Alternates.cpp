class Solution {
  public:
    int coin(vector<int>& arr) {
        int n=arr.size();
        int l=0,r=n-1;
        
        while(l<r)
        {
            if(arr[l]<arr[r])r--;
            else l++;
        }
        return arr[l];
    }
};
