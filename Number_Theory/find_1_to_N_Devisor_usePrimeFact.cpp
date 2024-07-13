#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(NULL);
#define endl '\n';
const int mx=2e5+10;

typedef long long ll;
typedef pair<ll, ll>  pll;
bool mark[mx];

vector<ll>primes;
vector<vector<pll>>p_facto(mx);
vector<vector<pll>>ans(mx);

ll cnt[mx];


void sieve() {
    mark[0] = mark[1] = 1;
    primes.push_back(2);
    int lim = sqrt(mx * 1.0) + 2;
    for (int i = 4; i < mx; i += 2) mark[i] = 1;
    for (int i = 3; i < mx; i += 2) {
        if (!mark[i]) {
            primes.push_back(i);
            if (i <= lim)
                for (int j = i * i; j < mx; j += i)
                    mark[j] = 1;
        }
    }
}


int main() {
    FIO;
    sieve();
    map<ll,ll>mp;
    ll nn;
    cin>>nn;
    ll ev=0;
    for(ll i = 1; i <=nn; i++) {   // "prime factorization"
        ll n = i;
        int cnt=1;
        for(auto j : primes) {
            if(j * j > n) break;
            if(n % j != 0) continue;
            ll a = 0;
            while(n % j == 0) {
                n = n / j;
                a++;
            }
           if(a%2!=0)cnt*=j;
        }

        if(n > 1) cnt*=n;
       if(cnt!=1)mp[cnt]++;
       else
       {
           ev++;
       }
    }
    ll ans=ev*ev;
    for(auto a : mp)
    {
        ll pq=a.second;
        //cout<<pq<<endl;
       // ll kl=pq*(pq+1)/2;
        ans+=pq*pq;


    }
    //ans=ans*(ans+1)/2;
    cout<<ans<<endl;





    return 0;

}
