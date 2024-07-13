#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
ll power(ll base, ll p)
{
    ll ans=1;
    while(p)
    {
        if(p%2==1)
        {
            ans=(ans*base)%mod;
            p--;
        }
        else
        {
            base=(base*base)%mod;
            p/=2;
        }
    }
    return ans%mod;
}
ll inv(ll n)
{
    return power(n,mod-2);
}
int main()
{
    ll n;
    cin>>n;
    ll ans=n;
    ans=ans%mod;
    for(ll i=2; i<=n; i++)
    {
        ll p=n/i; //koita devisor ase
        ll q=n/p;  // same devisor p-q range
        ll sm1,sm2;
        sm1=((q%mod)*((q+1)%mod))%mod;
        sm1 = (sm1*inv(2))%mod;

        sm2=((i%mod)*((i-1)%mod))%mod;
        sm2 = (sm2*inv(2))%mod;
        //cout<<sm1<<" "<<sm2<<endl;

        ll ad=((sm1-sm2)+mod)%mod;
       // cout<<ad<<endl;

        ll pa=(ad*p)%mod;
        ans=(ans+pa)%mod;
        i=q;

    }
    cout<<ans<<endl;
}
