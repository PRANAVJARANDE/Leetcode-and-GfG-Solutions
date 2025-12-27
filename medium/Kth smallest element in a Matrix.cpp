//Optimized O( (2n)log(diff)
class Solution {
  public:
    int kthSmallest(vector<vector<int>> &a, int k) 
    {
        int n=a.size();
        int l=a[0][0],r=a[n-1][n-1];
        int ans=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            
            int cnt=0;
            int i=0,j=n-1;
            while(i<n && j>=0)
            {
                while(j>=0 && a[i][j]>mid)j--;
                cnt+=j+1;
                i++;
            }
            
            if(cnt<k)
            {
                l=mid+1;
            }
            else
            {
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
        
    }
};




// O(n*n log(n*n)  --   klogk
class Solution {
  public:
    int n;
    
    bool issafe(int x,int y)
    {
        return x>=0 && y>=0 && x<n && y<n;
    }
    
    int kthSmallest(vector<vector<int>>&a, int k) 
    {
        n=a.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q1;
        q1.push({a[0][0],{0,0}});
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0]=1;
        while(!q1.empty())
        {
            auto pr=q1.top();
            q1.pop();
            
            int val=pr.first;
            int x=pr.second.first;
            int y=pr.second.second;
            
            k--;
            if(k==0)return val;
            if(issafe(x+1,y) && vis[x+1][y]==0)
            {
                vis[x+1][y]=1;
                q1.push({a[x+1][y],{x+1,y}});
            }
            if(issafe(x,y+1) && vis[x][y+1]==0)
            {
                vis[x][y+1]=1;
                q1.push({a[x][y+1],{x,y+1}});
            }
        }
        return -1;
        
    }
};
