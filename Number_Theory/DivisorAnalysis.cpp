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
    vector<ll>prim(n+2);
    vector<ll>pw(n+2);
    for(ll i=1; i<=n; i++)
    {
        cin>>prim[i]>>pw[i];
    }
    ll no_divi=1;
    for(ll i=1; i<=n; i++)
    {
        no_divi=((pw[i]+1)*no_divi)%mod;
    }
    ll sum_divi=1;
    for(ll i=1; i<=n; i++)
    {
        ll kk=pw[i]+1;
        kk=kk%mod;
        ll pww=power(prim[i],kk);
        pww=((pww-1)+mod)%mod;
        ll ns=prim[i]-1;
        pww=(pww*(inv(ns)))%mod;
        sum_divi=(sum_divi * pww)%mod;
    }
    ll pr_divi=1;
    bool odd=false;
    int pos;
    for(int i=1; i<=n; i++)
    {
        if(pw[i]%2==1)
        {
            odd=true;
            pos=i;
        }
    }
    if(odd)
    {
        ll outEx=1;
        for(int j=1; j<=n; j++)
        {
            if(j==pos)
            {
                outEx=(outEx*(pw[j]+1)/2)%(mod-1);
            }
            else
                outEx=(outEx*(pw[j]+1))%(mod-1);
        }
        for(int i=1; i<=n; i++)
        {
            pr_divi=(pr_divi*power(prim[i],(pw[i]*outEx)%(mod-1)))%mod;

        }
    }
    else
    {
        ll outEx=1;
        for(int j=1; j<=n; j++)
        {
            outEx=(outEx*(pw[j]+1))%(mod-1);
        }
        for(int i=1; i<=n; i++)
        {
            pr_divi=(pr_divi*power(prim[i],((pw[i]/2)*outEx)%(mod-1)))%mod;

        }


    }

    cout<<no_divi<<" "<<sum_divi<<" "<<pr_divi<<endl;







}
