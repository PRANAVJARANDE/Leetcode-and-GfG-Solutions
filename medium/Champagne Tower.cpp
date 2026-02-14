class Solution {
public:
    double champagneTower(int poured, int r, int c) 
    {   
        vector<vector<double>>qt(103,vector<double>(103,0));
        qt[0][0]=poured;
        for(int i=0;i<102;i++)
        {
            for(int j=0;j<102;j++)
            {
                if(qt[i][j]>=1)
                {
                    double nx=(qt[i][j]-1.0)/2;
                    qt[i+1][j]+=nx;
                    qt[i+1][j+1]+=nx;
                    qt[i][j]=1;
                }
            }
        }
        return qt[r][c];
    }
};
