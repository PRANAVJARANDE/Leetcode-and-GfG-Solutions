class Solution {
  public:
  
    
    int pour(int fromCap, int toCap, int d)
    {
        int from=fromCap,to=0;
        int step=1; 
        while(from!=d && to!=d)
        {
            int temp=min(from,toCap-to);
            to+=temp;
            from-=temp;
            step++;
    
            if(from==d || to==d)break;
    
            if(from==0)
            {
                from=fromCap;
                step++;
            }
            if(to==toCap)
            {
                to=0;
                step++;
            }
        }
        return step;
    }

    int minSteps(int m, int n, int d)
    {
        if(m>n)swap(m, n);
        if(d>n)return -1;
    
        
        if(d%gcd(m,n)!=0)return -1;
    
        return min(pour(n,m,d),pour(m,n,d));
    }

};
