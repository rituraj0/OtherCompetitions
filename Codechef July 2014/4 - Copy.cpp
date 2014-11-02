#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz size()
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;
#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
const double pi     =   acos(-1.0);
const double eps    =   1e-8;
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */

#define maxn 100009
ll mod=(1e9)+7;

int boss[maxn];
ll cont[maxn];
int cn;
int nextt[maxn];

bool done[maxn];

void dfs( int u)
{
     if( done[u] ) return;

     done[u]=true; cont[cn]++;

     dfs( nextt[u] );
}


ll inv(ll x, ll M) {

    cout<<" in inv "<<x<<"\n";
  ll a = 1, b = x;
  while (b != 1) {
    ll c = M / b;
    a *= c; a %= M;
    b *= c; b %= M;
    if (b > M/2) { a = M - a; b = M - b; }
  }

  cout<<" out inv "<<a<<endl;
  return a;
}


ll lcm( vector<ll> in)
{
    if(in.sz==0) return 1;//kya return hoga ?


    cout<<"in lcm\n";

    ll ans=in[0];

    print(ans);

    for(int i=1;i<in.sz;i++)
    {
            ll up=(ans*in[i])%mod;
            ll dn=__gcd( ans , in[i]);
            ll mul=inv(dn,mod);
            ans=(up*mul)%mod;

            print(ans);
    }

    cout<<"out of lcm\n";

    return ans;
}
void solve( )
{
     int n;

     scanf("%d",&n);

     for(int i=1;i<=n;i++)
        scanf("%d",&nextt[i]);

      cn=0;

      fill(done,0); fill(cont,0);

      for(int i=1;i<=n;i++)
         if( !done[i] )
           {cn++;
            dfs(i);
           }


//      print(cn);
//
//      for(int i=1;i<=cn;i++)
//         cout<<cont[i]<<"  ";

        vector<ll> tp;
        for(int i=1;i<=cn;i++)
             tp.pb( cont[i] );

      ll ans=lcm(tp);

     printf("%lld\n",ans);

     // print(ans);
}

int main()
{
   int test;

   while(1)
   {
       vector<ll> in;
       int n,x;

        cin>>n;

        for(int i=0;i<n;i++)
        {
            cin>>x;
            in.pb(x);
        }

        cout<<lcm(in)<<endl;
   }

//   scanf("%d",&test);
//
//   while(test--)
//   {
//       solve();
//   }


 return 0;

}
