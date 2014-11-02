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
 ios_base::sync_with_stdio(0);

 int n,x,sm=0,d;

 cin>>n>>d;

 for(int i=1;i<=n;i++)
 {
     cin>>x;
     sm+=x;
 }

 int req=(n-1)*10+sm;

 if( req> d)
     {cout<<"-1\n";
       return 0;
     }

  int ans=2*(n-1) + (d-req)/5;

  cout<<ans<<endl;



 return 0;

}
