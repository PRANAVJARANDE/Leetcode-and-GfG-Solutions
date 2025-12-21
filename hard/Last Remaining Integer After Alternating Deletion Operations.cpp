#define ll long long
class Solution {
public:
long long lastInteger(long long n) 
{
    bool turn=0;
    ll d=1;
    ll a=1;
    while(a!=n)
    {
        if(turn==0)
        {
            if((n-a)%(d*2)!=0)n-=d;
        }
        else
        {
            if((n-a)%(d*2)!=0)a+=d;
        }
        d*=2;
        turn=1-turn;
    }
    return a;
}

};
