#include<bits/stdc++.h>
#define ll long long int
using namespace std;
string res="";

ll cnt_string(ll a, ll b)
{
    ll cnt=1;
    ll n=a+b;
    ll r=a;
    for(int i=0; i<r; i++) // N_C_R = N! / A!;
    {
        cnt*=(n-i);
        cnt/=(i+1);
    }
    return cnt;

}

void solve(ll a,ll b, ll k)
{
    if(a==0 && b==0)
        return;
    ll lf=(a==0) ? 0 : cnt_string(a-1,b);
    ll rf=(b==0) ? 0 : cnt_string(a,b-1);
    if(lf>=k)
    {
        res+='a';
        solve(a-1,b,k);
    }
    else
    {
        res+='b';
        solve(a,b-1,k-lf);
    }


}


int main()
{
    ll a,b,k;
    cin>>a>>b>>k;
    solve(a,b,k);
    cout<<res<<endl;


}

