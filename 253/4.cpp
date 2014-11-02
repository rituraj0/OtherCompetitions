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

int n;
double in[200];

int main()
{
 ios_base::sync_with_stdio(0);

// fi;fo;
//
// double a=0,b=1.0;
// double diff=(b-a)/allow;
//
// for(int i=0;i<=allow+2;i++)
// { cout<<a<<endl;
//    a+=diff;
// }

 cin>>n;

 for(int i=1;i<=n;i++)
    {
        cin>>in[i];

        if( in[i]==1.00)
           { printf("%.10lf\n",in[i]);
              return 0;
           }
    }

 sort(in+1,in+1+n);

 double ans=in[n],sum=in[n]/(1.0-in[n]), mul=(1-in[n]);

 for(int i=n-1;i>=1;i--)
 {
    sum+=in[i]/(1.0-in[i]);
    mul*=(1-in[i]);

    ans=max(ans,sum*mul);
 }

 printf("%.10lf\n",ans);

 return 0;

}
