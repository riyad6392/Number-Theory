// 2 3 5 7 6 9 =ans(4) longest subarray lcm(subarray)=produc of subarray
#include<bits/stdc++.h>
#define ll long long int
#define mod 100000007
using namespace std;
const int N=1e6+2;
vector<ll>prm(N,0);
int vis[N];
void siv()
{
    prm[1]=1;
    for(int i=2;i<N;i++)
    {
        if(prm[i]==0)
        {
            prm[i]=i;
            for(int j=i;j<N;j+=i)
            {
               if(prm[j]==0)
               {
                   prm[j]=i;
               }
            }
        }

    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    siv();
   for(int i=0;i<N;i++)
   {
       vis[i]=0;
   }
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       int ar[n+2];
       for(int i=1;i<=n;i++)
       {
           cin>>ar[i];
       }
       vector<int>mp(N);
       for(int i=0;i<N;i++)
       {
           mp[i]=0;
       }

       int ans=0;
       int p=1;
       for(int i=1;i<=n;i++)
       {
           int pp=ar[i];
           set<int>st;
           if(ar[i]==1)
           {
               st.insert(1);
           }
           else
           {
                while(pp%prm[pp]==0)
                {
                    if(pp==1) break;
                    st.insert(prm[pp]);
                    pp/=prm[pp];

                }

           }


           for(auto a : st)
           {
               if(mp[a]<p)
               {
                   mp[a]=i;
               }
               else
               {
                   p=mp[a]+1;
                   mp[a]=i;
               }

           }
           ans=max(ans,i-p+1);

       }
       if(ans==1)cout<<-1<<endl;
       else cout<<ans<<endl;




   }

}


