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
const double eps    =   1e-6;
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */

#define  mod 1000000007

vector<int> prime[70];
double save[70];

double root(int n,double in,  double gess)
{
    double A=in;
	double _n= (double) n;
	double x[2];
	x[0] = A;
	x[1] = gess+0.5;

//	print(x[1]);

	while( fabs( x[0] - x[1] ) > 0.001)
	{
		x[1] = x[0];
		x[0] = (1/_n)*(((_n-1)*x[1]) + (A/pow(x[1],_n-1)));

	}

	cout<<n<<"  "<<in<<"  "<<gess<<"  "<<x[0]<<endl;

	return x[0];
}


ll in[10005],sum[10005];
int n,Q;

void solve()
{
    scanf("%d%d",&n,&Q);

     for(int i=1;i<=n;i++)
         { scanf("%lld",&in[i]);
           in[i]=in[i]%mod;
         }


     fill(sum,0);
     for(int i=n;i>=0;i--)
         sum[i]=(sum[i+1]+in[i])%mod;

     ll x;

     for(int q=1;q<=Q;q++)
     {
           scanf("%lld",&x);

           ll last=x;

           ll ans=0;

           save[1]=x;

           for(int i=1;i<=n;i++)
           {
               double rt=x;

               if( i > 1)
               {
                    int prev=i/prime[i][0];
                    rt=root(prime[i][0], save[prev], save[ prime[i][0]-1 ] );
                    save[i]=rt;
               }

                ll curr=rt;
//               ll rt=pow( (double)x , (double)(1.0/(double)i) );
               if(curr==1)
               {
                   ans=(ans+ sum[i] )%mod;

                   cout<<i<<"   "<<sum[i]<<"  "<<"BREAK \n";
                   //break;
               }
              else
              {
                  curr=curr%mod;
                  ll add=(in[i]*curr)%mod;
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

   for(int i=2;i<70;i++)
     for(int j=2;j<=i;j++)
       if( i%j==0)
         prime[i].pb(j);

   int test;

   scanf("%d",&test);

   while(test--)
   {
      solve();
      printf("\n");
   }
 return 0;

}
