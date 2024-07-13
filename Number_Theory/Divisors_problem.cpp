#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        map<ll,ll>mp;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            for(int j=2;j*j<=x;j++)
            {
                while(x%j==0)
                {
                    x/=j;
                    mp[j]++;
                }

            }
            if(x>1)
            {
                mp[x]++;
            }

        }
        ll ans=0,rem=0;
        for(auto a : mp)
        {
            ans+=a.second/2;
            rem+=a.second%2;
        }
        ans+=rem/3;
        cout<<ans<<endl;

    }

}
