#include<bits/stdc++.h>
#define ll long long int
#define mod 100000007
using namespace std;
const int N=5000004;
vector<ll>prm(N,0);
int vis[N];
vector<ll>div(N,0);


void siv()
{
    prm[1]=1;
    for(int i=2; i<N; i++)
    {
        if(prm[i]==0)
        {
            prm[i]=i;
            for(int j=i; j<N; j+=i)
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
    div[1]=1;
    for(int i=2; i<=N; i++)
    {
        int pp=i;
        ll ans=1;
        while(pp!=1)
        {
           int temp=prm[pp];
            int cnt=1;
            while(pp%temp==0)
            {
                pp/=temp;
                cnt++;
            }
            ans=(ans*cnt)%mod;

        }
        div[i]=(ans*div[i-1])%mod;




    }


}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    siv();
    ll n;
    while(cin>>n)
    {
        if(n==0)
            break;
        if(n==1)
        {
            cout<<1<<endl;
            continue;

        }
        ll ans=1;
        vector<ll>vt(n+1,0);
        int k=n-1;
        for(int i=2; i<=n; i++)
        {
            int pp=i;
            while(pp%prm[pp]==0)
            {
                if(pp==1)
                    break;
                vt[prm[pp]]+=k;
                pp/=prm[pp];
            }
            k--;
        }
        for(auto a : vt)
        {
            //cout<<a<<" ";
            a++;
            ans=(ans*a)%mod;
        }
        //cout<<endl;

        cout<<ans<<endl;;


    }


}

