#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod=1000000007;
ll powr(ll a,ll b)
{
    if(b==0)return 1;
    ll result=powr(a,b/2);
    result=(result*result)%mod;
    if(b%2==1)
    {
        result=(result*a)%mod;
    }
    return result%mod;

}

int main()
{


       ll n,m;
       cin>>n>>m;
       ll pp=powr(2,m);
       pp--;
       ll ans=powr(pp,n);
       cout<<ans<<endl;



}
