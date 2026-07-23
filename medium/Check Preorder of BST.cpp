class Solution {
  public:
    
    int in;
    bool helper(int mini,int maxi,vector<int>&a)
    {
        if(in>=a.size())return 1;
        if(maxi<a[in] || a[in]<mini)return 0;
        int val=a[in];
        in++;
        
        bool left=helper(mini,min(val,maxi),a);
        bool right=helper(max(mini,val),maxi,a);
        return left || right;
    }
  
    bool canRepresentBST(vector<int> &arr) 
    {
        in=0;
        return helper(INT_MIN,INT_MAX,arr);
    }
};
