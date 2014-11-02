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

ll z[100009];
string in;

ll stringSimilarity()
{
  fill(z,0);
  int n=in.sz;
  z[0]=n;

  int l=0,r=0;

  for(int i=1;i<n;i++)
  {
       if( r < i)
       {
            l=r=i;

            while( (r<n) && (in[r-l]==in[r]) )
            {
                r++;
            }
            z[i]=r-l;
            r--;

            continue;
       }

       int b=r-i+1;
       int k=i-l;

       if( z[k]<b)
       {
           z[i]=z[k];
       }
       else
       {
           l=i;

            while( (r<n) && (in[r-l]==in[r]) )
            {
                r++;
            }
            z[i]=r-l;
            r--;
       }
  }

  ll ans=0;

  for(int i=0;i<n;i++)
     ans+=z[i];

   return ans;

}

int main()
{

    int  t, i;

    cin>>t;

    for (i=0;i<t;i++)
        {
        cin>>in;
        ll ans=stringSimilarity();
        cout<<ans<<endl;
       }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
