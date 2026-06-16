class Solution {
public:

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

    int query(int node,int i,int j,int l,int r,vector<int>&tree)
    {
        if(j<l || r<i)return 0;
        if(l<=i && j<=r)return tree[node];
        int mid=i+(j-i)/2;
        return query(2*node+1,i,mid,l,r,tree)+query(2*node+2,mid+1,j,l,r,tree);
    }

    string minInteger(string num, int k) 
    {
        int n=num.size();
        vector<deque<int>>v1(10);
        for(int i=0;i<n;i++)v1[num[i]-'0'].push_back(i);
        vector<int>tree(4*n,0);
        string ans;
        while(k>0 && ans.size()<n)
        {
            bool found=1;
            for(int z=0;z<10;z++)
            {
                if(v1[z].empty())continue;
                int index=v1[z].front();
                int in=index-query(0,0,n-1,0,index-1,tree);
                if(in<=k)
                {
                    v1[z].pop_front();
                    ans.push_back(z+'0');
                    k-=in;
                    update(0,0,n-1,index,tree);
                    break;
                }
            }
            if(!found)break;
        }

        vector<pair<int,char>>temp;
        for(int z=0;z<10;z++)
        {
            while(!v1[z].empty())
            {
                temp.push_back({v1[z].front(),z+'0'});
                v1[z].pop_front();
            }
        }
        sort(temp.begin(),temp.end());
        for(auto x:temp)ans.push_back(x.second);
        return ans;
    }
};
