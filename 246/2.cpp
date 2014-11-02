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


int H[1<<20],A[1<<20];
int hc[1<<20],ac[1<<20];
int main()
{
 ios_base::sync_with_stdio(0);

 int n;

 fill(ac,0); fill(hc,0);

 cin>>n;

 for(int i=1;i<=n;i++)
 {
      cin>>H[i]>>A[i];

    hc[ H[i] ]++;
    ac[ A[i] ]++;
 }

 for(int i=1;i<=n;i++)
 {
       int tt=2*(n-1);

       int h=n-1;

        h+=hc[ A[i] ];

        cout<<h<<" "<<tt-h<<endl;
 }


 return 0;

}
