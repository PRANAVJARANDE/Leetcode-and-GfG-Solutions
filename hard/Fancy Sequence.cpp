#define ll long long
class Fancy {
public:
    
    const ll MOD=1e9+7;
    ll a,b;
    vector<ll>v1;
    Fancy() 
    {
        a=1;
        b=0;
    }

    ll modPow(ll x,ll y) 
    {
        ll res=1;
        x=x%MOD;
        while(y>0) 
        {
            if(y%2==1)res=(res*x)%MOD;
            y=y/2;
            x=(x*x)%MOD;
        }
        return res;
    }
    
    void append(int val) 
    {
        val=(val-b+MOD)%MOD;
        val=(val*modPow(a,MOD-2))%MOD;
        v1.push_back(val);
    }
    
    void addAll(int inc) 
    {
        b=((b%MOD)+(inc%MOD))%MOD;
    }
    
    void multAll(int m) 
    {
        a=((a%MOD)*(m%MOD))%MOD;
        b=((b%MOD)*(m%MOD))%MOD;
    }
    
    int getIndex(int idx) 
    {
        if(idx>=v1.size())return -1;
        ll res=((((a%MOD)*(v1[idx]%MOD))%MOD)+(b%MOD))%MOD;
        return res;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
