#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz size()
#define bg begin()
#define en end()
#define Y second
#define X first
typedef unsigned long long ll;
#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
const double pi     =   acos(-1.0);
const double eps    =   1e-8;
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */

ll C[100][100];

ll m;
int k;

void init()
{
    fill(C,0);

    for(int i=0;i<70;i++)
         C[i][0]=1;

    for(int i=1;i<70;i++)
         for(int j=1;j<70;j++)
           C[i][j]=(C[i-1][j-1]+C[i-1][j]);

}


ll cont( ll in)//k set bits , 1 to in-1
{
    ll ans=0,cn=0;

    for(int i=63;i>=0;i--)
    {
          ll mask=(1LL<<i);
          ll one=(in&mask);

          if( ( one ) &&( ( k-cn) >=0 ) )
          {
              ans+=C[i][k-cn];
              cn++;
          }
    }

    if(cn==k)
         ans++;

    return ans;
}

ll solve( ll n)
{
    return cont(2*n)-cont(n);
}

int main()
{


 init();

 cin>>m>>k;

 ll lo=1,hi=1e18;

// solve(1);

 ll ans=-1;

 while( lo <=hi)
 {
     ll mid=lo+(hi-lo)/2;

      ll all=solve( mid);

      if( all==m)
      {
          ans=mid;
          break;
      }
     else if( all > m)
     {
         hi=mid-1;
     }
     else
     {
         lo=mid+1;
     }
 }

 cout<<ans<<endl;

 return 0;

}
