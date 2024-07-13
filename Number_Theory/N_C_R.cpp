#include<bits/stdc++.h>
using  namespace  std;
#define mod 1000000007
#define ll long long int

/*
jodi mod na kore korte hoi
ll ncr(ll n,ll r)
{

   ll mn=min(n,r);
   ll nn=1,rr=1;
   for(int i=1;i<=mn;i++)
   {
       if(n==0 || r==0)break;
       nn*=n;
       rr*=r;
       ll gc=__gcd(nn,rr);
       n--;
       r--;
       nn/=gc;
       rr/=gc;

   }

   return max(nn,rr);

}

ll derangement(ll n) // kaw tar position a thakte parbe na  (1 2 3 = 3 1 2)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;

    if(dp[n]!=-1)
        return dp[n];

    ll kl=(n-1)*(derangement(n-1)+(derangement(n-2)));

    return dp[n]=kl;

}

*/

ll factorial[1004];
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
ll nCr(ll n,ll r)
{
    if(n==r or r==0)
        return 1;
    ll num=factorial[n];
    ll denm=(factorial[r]*factorial[n-r])%mod;
    num = (num*inv(denm))%mod;
    return num;
}


int main()
{
    ll n,r,n1,r1,k,ans,t;
    factorial[0] = 1;
    for (int i = 1; i <= 1000; i++)
    {
        factorial[i] = factorial[i - 1] * i % mod;
    }

    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cin>>n>>k;
        int ar[n];
        map<int,int>mp;
        for(int j=0; j<n; j++)
        {
            cin>>ar[j];
            mp[ar[j]]++;
        }
        sort(ar,ar+n);
        reverse(ar,ar+n);
        int pp=ar[k-1];
        //cout<<"PP "<<pp<<endl;
        int qq=mp[pp];
        int rr=0;
        for(int j=0; j<n; j++)
        {
            if(ar[j]>pp)
            {
                rr++;
            }
            else
                break;
        }
        rr=k-rr;
        //n1= factorial[qq];
        // r1=factorial[rr];
        // cout<<qq<<" "<<rr<<endl;
        ans=nCr(qq,rr);

        cout<<ans<<endl;
    }
    return 0;
}

