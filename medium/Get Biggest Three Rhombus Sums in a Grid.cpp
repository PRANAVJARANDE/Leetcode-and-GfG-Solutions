class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>&a) 
    {
        set<int>ans;
        int n=a.size();
        int m=a[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int r=0;r<n;r++)
                {
                    int res=0;
                    if(r==0)res=a[i][j];
                    else
                    {
                        int ct=i+r;
                        int t1=i,t2=i+(2*r),s1=j-r,s2=j+r;
                        if(t2>=n || s1<0 || s2>=m)break;

                        int x=i,y=j;
                        for(int k=0;k<r;k++)
                        {
                            res+=a[x][y];
                            x++;
                            y--;
                        }
                        for(int k=0;k<r;k++)
                        {
                            res+=a[x][y];
                            x++;
                            y++;
                        }
                        for(int k=0;k<r;k++)
                        {
                            res+=a[x][y];
                            x--; 
                            y++;
                        }
                        for(int k=0;k<r;k++)
                        {
                            res+=a[x][y];
                            x--; 
                            y--;
                        }
                    }
                    ans.insert(res);
                    if(ans.size()>3)ans.erase(ans.begin());
                }
            }
        }
        vector<int>v1;
        for(auto x:ans)v1.push_back(x);
        reverse(v1.begin(),v1.end());
        return v1;
    }
};
