class Robot {
public:

    int n,m;
    int dir;
    int px,py;
    const int MOD=4;

    Robot(int width, int height) {
        n=width;
        m=height;
        px=0;
        py=0;
        dir=0;    
    }
    
    void step(int num) 
    {
        num=num%(2*(m+n-2));
        while(num)
        {
            if(dir==0)
            {
                int mx=n-py-1;
                if(num>mx)
                {
                    dir=1;
                    num-=mx;
                    py+=mx;
                }
                else
                {
                    py+=num;
                    num=0;
                }
            }
            else if(dir==1)
            {
                int mx=m-px-1;
                if(num>mx)
                {
                    dir=2;
                    num-=mx;
                    px+=mx;
                }
                else
                {
                    px+=num;
                    num=0;
                }
            }
            else if(dir==2)
            {
                int mx=py;
                if(num>mx)
                {
                    dir=3;
                    num-=mx;
                    py=0;
                }
                else
                {
                    py-=num;
                    num=0;
                }
            }
            else
            {
                int mx=px;
                if(num>mx)
                {
                    dir=0;
                    num-=mx;
                    px=0;
                }
                else
                {
                    px-=num;
                    num=0;
                }
            }
        }

        if(px==0 && py==0 && (n+m-2)>0)
        {
            dir=3;
        }
    }
    
    vector<int> getPos() {
        return {py,px};
    }
    
    string getDir() {
        if(dir==0)return "East";
        else if(dir==1)return "North";
        else if(dir==2)return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
