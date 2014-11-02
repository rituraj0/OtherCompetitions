#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(s) ((int)(s.size()))
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

 int in[10];

 int sm=0;

 for(int i=0;i<5;i++)
 {
     cin>>in[i];
     sm+=in[i];
 }

 if( (sm >0 ) &&  (sm%5==0) )
    cout<<sm/5<<endl;
 else
    cout<<"-1"<<endl;

 return 0;

}
