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


int main()
{


 int test;
 cin>>test;

 while(test--)
 {
  ll m,n;

    cin>>n>>m;

   ll o1=(n+1)/2 , o2=(m+1)/2;
   ll e1=n/2 ,e2=m/2;

 ll up=o1*e2+e1*o2;
 ll down=m*n;
 ll gc=__gcd(up,down);
 up=up/gc;
 down=down/gc;
 cout<<up<<"/"<<down<<endl;
 }

 return 0;

}
