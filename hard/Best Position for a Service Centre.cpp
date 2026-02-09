class Solution {
public:

    vector<int>dx{-1,1,0,0};
    vector<int>dy{0,0,-1,1};

    double calculate(vector<vector<int>>&v1,double a,double b)
    {
        double ans=0;
        for(auto pt:v1)
        {
            double x=pt[0];
            double y=pt[1];
            double d=sqrt(((a-x)*(a-x))+((b-y)*(b-y)));
            ans+=d;
        }
        return ans;
    }


    double getMinDistSum(vector<vector<int>>&a) 
    {
        int n=a.size();
        double sx=0,sy=0;
        for(auto x:a)
        {
            sx+=x[0];
            sy+=x[1];
        }
        sx/=n;
        sy/=n;

        double dis=calculate(a,sx,sy);

        double step=50;
        while(step>0.000001)
        {
            double tx=sx;
            double ty=sy;
            double tdis=dis;

            for(int z=0;z<4;z++)
            {
                double nx=sx+(dx[z]*step);
                double ny=sy+(dy[z]*step);
                double ndis=calculate(a,nx,ny);
                if(ndis<dis)
                {
                    tx=nx;
                    ty=ny;
                    tdis=ndis;
                }
            }
            if(tx==sx && ty==sy)step/=2;
            dis=tdis;
            sx=tx;
            sy=ty;
        }
        return dis;
    }
};
