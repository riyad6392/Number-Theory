#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll phi(ll p)
{
    ll ans=p;
    ll pq=sqrt(p);
    for(int i=2;i<=pq;i++)
    {
        if(p%i==0)
        {
            while(p%i==0)
            {
                p/=i;
            }
            ans=ans-(ans/i);
        }
    }
    if(p>1)
    {
         ans=ans-(ans/p);
    }
    return ans;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,m;
        cin>>a>>m;
        ll p=__gcd(a,m);
        p=m/p;
       ll ano= phi(p);
       cout<<ano<<endl;


    }
}
