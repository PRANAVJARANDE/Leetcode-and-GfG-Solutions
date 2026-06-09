class Solution {
  public:
    

    int helper(int l,int r,int mini,int maxi,vector<int>&nums)
    {
        if(l>r)return 0;
        int mid=l+(r-l)/2;
        int ans=0;
        if(mini<nums[mid] && nums[mid]<maxi)ans++;
        ans+=helper(l,mid-1,mini,min(maxi,nums[mid]),nums);
        ans+=helper(mid+1,r,max(mini,nums[mid]),maxi,nums);
        return ans;
    }
  
    int binarySearchable(vector<int>& arr) 
    {
        return helper(0,arr.size()-1,INT_MIN,INT_MAX,arr);  
    }
};
