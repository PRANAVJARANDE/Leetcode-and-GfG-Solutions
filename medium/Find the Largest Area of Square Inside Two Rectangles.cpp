class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& v1, vector<vector<int>>& v2) 
    {
        long long smax=0;
        int n=v1.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x1=v1[i][0],y1=v1[i][1];
                int x2=v2[i][0],y2=v2[i][1];
                int x3=v1[j][0],y3=v1[j][1];
                int x4=v2[j][0],y4=v2[j][1];

                int xmin=max(x1,x3);
                int xmax=min(x2,x4);
                int ymin=max(y1,y3);
                int ymax=min(y2,y4);

                if(xmin<xmax && ymin<ymax)
                {
                    long long s1=xmax-xmin;
                    long long s2=ymax-ymin;
                    smax=max(smax,min(s1,s2));
                }
            }
        }
        long long ans=smax*smax;
        return ans;
    }
};
