#include<bits/stdc++.h>
#define ll long long int
#define mod 100000007
using namespace std;
const int N=5000004;
vector<ll>prm(N+6,0);
int vis[N];
ll divi[N+10];
ll pw[N+6];
ll power(ll base , ll p)
{
    ll ans=1;
    while(p)
    {
        if(p%2==1)
        {
            ans=(ans*base)%mod;
            p--;
        }
        else{
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

void siv()
{
    prm[1]=1;
    for(int i=2; i<=N; i++)
    {
        if(prm[i]==0)
        {
            prm[i]=i;
            for(int j=i; j<=N; j+=i)
            {
                if(prm[j]==0)
                {
                    prm[j]=i;
                }
            }
        }

    }

}

void pcl()
{
    divi[1]=1;
    ll ans=1;
    for(int i=2; i<=10; i++)
    {
        int pp=i;
        while(pp!=1)
        {
            int temp=prm[pp];
            int cnt=0;
            while(pp%temp==0)
            {
                pp/=temp;
                cnt++;
            }
            ll dd=pw[temp];
            ans=(ans*inv(dd+1))%mod;
            cout<<ans<<endl;
            ans=(ans*(dd+cnt+1))%mod;
            cout<<ans<<endl;
            pw[temp]=pw[temp+cnt];



        }
        divi[i]=(ans*divi[i-1])%mod;




    }


}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    siv();
    pcl();

    ll n;
    while(cin>>n)
    {
        if(n==0)
            break;

         cout<<divi[n]<<endl;




    }


}
