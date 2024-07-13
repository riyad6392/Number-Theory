#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define N 5000000
int phi[N+1];
unsigned long long pcm[N+1];

void seiv()
{
  for(int i=1;i<=N;i++)
  {
      phi[i]=i;
  }
  for(int i=2;i<=N;i++)
  {
      if(phi[i]==i)
      {
          for(int j=i;j<=N;j+=i)
          {
              phi[j]-=phi[j]/i;
          }

      }
  }

}

int main()
{
    ll n,m,t;
    seiv();
    pcm[1]=1;
    for(int i=2;i<=N;i++)
    {
        unsigned long long pp=((unsigned long long)phi[i]*(unsigned long long)phi[i]);
        pcm[i]=pcm[i-1]+pp;
    }
    cin>>t;
    for(int i=1;i<=t;i++)
    {
      cin>>n>>m;
     unsigned long long ans=pcm[m]-pcm[n-1];
     cout<<"Case "<<i<<": "<<ans<<endl;

    }



}
