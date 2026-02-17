class Solution {
  public:
    
    void add(int node,int i,int j,vector<int>&tree,int in)
    {
        if(i==j)
        {
            tree[node]++;
            return;
        }
        int mid=i+(j-i)/2;
        if(in<=mid)add(2*node+1,i,mid,tree,in);
        else add(2*node+2,mid+1,j,tree,in);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
    
    int query(int node,int i,int j,vector<int>&tree,int l,int r)
    {
        if(l<=i && j<=r)return tree[node];
        if(r<i || j<l)return 0;
        int mid=i+(j-i)/2;
        return query(2*node+1,i,mid,tree,l,r)+query(2*node+2,mid+1,j,tree,l,r);
    }
  
    int inversionCount(vector<int> &arr) 
    {
        int sz=0;
        for(auto x:arr)sz=max(sz,x);
        sz+=10;
        vector<int>tree(4*sz,0);
        int ans=0;
        for(auto x:arr)
        {
            ans+=query(0,0,sz-1,tree,x+1,sz+3);
            add(0,0,sz-1,tree,x);
        }
        return ans;
    }
};
