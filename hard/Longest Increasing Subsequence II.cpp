class Solution {
public:

    void update(int node,int i,int j,int in,int val,vector<int>&tree)
    {
        if(i==j)
        {
            tree[node]=max(tree[node],val);
            return;
        }
        int mid=i+(j-i)/2;
        if(in<=mid)update(2*node+1,i,mid,in,val,tree);
        else update(2*node+2,mid+1,j,in,val,tree);
        tree[node]=max(tree[2*node+1],tree[2*node+2]);
    }

    int query(int node,int i,int j,int l,int r,vector<int>&tree)
    {
        if(j<l || r<i)return 0;
        if(l<=i && j<=r)return tree[node];
        int mid=i+(j-i)/2;
        return max(query(2*node+1,i,mid,l,r,tree),query(2*node+2,mid+1,j,l,r,tree));
    }

    int lengthOfLIS(vector<int>& nums, int k) 
    {
        int maxi=0;
        for(auto x:nums)maxi=max(maxi,x);
        maxi+=10;
        vector<int>tree(4*maxi,0);
        int ans=1;
        for(auto x:nums)
        {
            int res=1+query(0,0,maxi-1,max(0,x-k),x-1,tree);
            ans=max(ans,res);
            update(0,0,maxi-1,x,res,tree);
        }        
        return ans;
    }
};
