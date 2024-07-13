#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=2000001;
int phi[N];
int main()
{
    for(int i=0;i<=N;i++)
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
    cout<<phi[20]<<endl;

}

