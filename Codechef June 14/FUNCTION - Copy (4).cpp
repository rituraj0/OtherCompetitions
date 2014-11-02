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

#define  mod 1000000007

bool cool ( ll x, ll curr , ll y)
{
     //check if x is leass than curr^y
     double ans=1,mul=curr;
     ll tp=1;

     while( y >0)
     {
          if( y&1)
          {
              tp=tp*curr;
              ans=ans*mul;
              if( ans > x)
                 return false;
          }

          y=y/2;
          curr=curr*curr;
          mul=mul*mul;
          if( (y>0) && (mul > x) )
             return false;

     }

     if( tp<=x)
         return true;

     return false;
}

//one opti x ko last root se start  kar sakte hai
ll root( ll y , ll x, ll hi)//x^(1/y)
{
    ll lo=1;

    ll ans=1;

    while( lo <=hi)
    {
        ll mid=lo+(hi-lo)/2;

        bool hp=cool(x,mid,y);

        if( hp )
        {
            ans=mid;
            lo=mid+1;
        }
       else
       {
           hi=mid-1;
       }

    }

    return ans;
}

ll in[10005],sum[10005];
int n,Q;

void solve()
{
    scanf("%d%d",&n,&Q);

     for(int i=1;i<=n;i++)
         scanf("%lld",&in[i]);

         ll y=in[1]%mod;



     fill(sum,0);
     for(int i=n;i>=0;i--)
         sum[i]=(sum[i+1]+in[i])%mod;

     ll x;

     for(int q=1;q<=Q;q++)
     {
           scanf("%lld",&x);

           ll xm=x%mod;
           print(xm);
           ll am=(xm*y)%mod;
           print(am);

           ll last=x;

           ll ans=0;

           for(int i=1;i<=n;i++)
           {
               ll rt=root(i,x,last);
               last=rt;
//               ll rt=pow( (double)x , (double)(1.0/(double)i) );
               if(rt==1)
               {
                   ans=(ans+ sum[i] )%mod;
                   break;

               }
              else
              {   in[i]=in[i]%mod;
                  rt=rt%mod;
                  ll add=(in[i]*rt)%mod;
                  ans=(ans+ add)%mod;
              }

           }

           printf("%lld ",ans);

     }

}

int main()
{
// ios_base::sync_with_stdio(0);

// while(1)
// {
//     ll a,b;
//     cin>>a>>b;
//     cout<<root(a,b)<<"\n\n";
// }

//// solve();
//
// ll in=(1LL<<62);
//  cout<<root(31,in)<<endl;

   int test;
   scanf("%d",&test);

   while(test--)
   {
      solve();
      printf("\n");
   }
 return 0;

}
