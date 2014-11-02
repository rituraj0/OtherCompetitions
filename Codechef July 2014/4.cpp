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
int cont[maxn];

int cn;

int nextt[maxn];
bool done[maxn];

void dfs( int u)
{
     if( done[u] ) return;

     done[u]=true; cont[cn]++;

     dfs( nextt[u] );
}

int maxi[maxn];

void prime( int in)
{
   int tp=in;

   for(int i=2;i*i<=in;i++)
   {
         int curr=0;

         while(tp%i==0)
         {
             curr++;
             tp=tp/i;
         }

         maxi[i]=max( maxi[i],curr);
   }

   if(tp>1)
    maxi[tp]=max( maxi[tp] , 1);//
}

ll lcm( vector<int> in)
{
   fill(maxi,0);

   for(int i=0;i<in.sz;i++)
            {
                prime( in[i] );
            }

      ll ans=1;

      for(ll i=2;i<maxn;i++)
      {
           for(int j=1;j<=maxi[i];j++)
             ans=(ans*i)%mod;
      }

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

       vector<int> tp;

       for(int i=1;i<=cn;i++)
         tp.pb( cont[i]);

        cout<<lcm(tp)<<endl;
}

int main()
{
   int test;

//   while(1)
//   {
//       vector<int> in;
//       int n,x;
//
//        cin>>n;
//
//        for(int i=0;i<n;i++)
//        {
//            cin>>x;
//            in.pb(x);
//        }
//
//        cout<<lcm(in)<<endl;
//   }

   scanf("%d",&test);

   while(test--)
   {
       solve();
   }


 return 0;

}
