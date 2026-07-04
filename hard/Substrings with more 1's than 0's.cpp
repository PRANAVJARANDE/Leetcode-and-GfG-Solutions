class Solution {
  public:
    
    /*
       
       psum - 1
       
       substring [l,r]
        
       oc = psum[r]-psum[l-1]
       zc = r-(l-1) - oc
       
       I want :
       
       - oc>zc
       - 2*oc > r-(l-1) 
       - 2psum[r]-2psum[l-1] > r - (l-1)
       - 2psum[r]-r > 2psum[l-1]-(l-1)
       
       
       for i = -1 : 2
       
    */
    
    
    void update(int node,int i,int j,int in,vector<int>&tree)
    {
        if(i==j)
        {
            tree[node]++;
            return;
        }
        
        int mid=i+(j-i)/2;
        if(in<=mid)update(2*node+1,i,mid,in,tree);
        else update(2*node+2,mid+1,j,in,tree);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
    
    int query(int node,int i,int j,vector<int>&tree,int ql,int qr)
    {
        if(qr<i || j<ql)return 0;
        if(ql<=i && j<=qr)return tree[node];
        
        int mid=i+(j-i)/2;
        return query(2*node+1,i,mid,tree,ql,qr)+query(2*node+2,mid+1,j,tree,ql,qr);
    }
 
    int countSubstring(string& s) 
    {
        int n=s.size();
        int sz=2*(n+20);
        int shift=n+4;
        
        vector<int>tree(4*sz,0);
        
        update(0,0,sz-1,1+shift,tree);
        int ans=0;
        int psum=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')psum++;
            
            int cr=2*psum-i;
            ans+=query(0,0,sz-1,tree,0,shift+cr-1);
            update(0,0,sz-1,cr+shift,tree);
        }
        return ans;
        
    }
};
