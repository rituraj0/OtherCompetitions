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

#define maxn  5005

int maxi[maxn];
int add[maxn];
int op[maxn],l[maxn],r[maxn],val[maxn];

int main()
{
 ios_base::sync_with_stdio(0);

 int n,m;

 cin>>n>>m;

 fill(add,0);

 fill( maxi , 63);//value at last , after all operations
 for(int i=0;i<=n;i++)
    maxi[i]=1e9;

 //cout<<maxi[0]<<endl;

 //int op, l , r, val;

 for(int i=0;i<m;i++)
 {
     cin>>op[i]>>l[i]>>r[i]>>val[i];

     if( op[i]==1)
     {
         for(int j=l[i];j<=r[i];j++)
             add[j]+=val[i];
     }
     else
      {
         for(int j=l[i];j<=r[i];j++)
           maxi[j] = min( maxi[j] , val[i]-add[j] );
      }
 }

 fill(add,0);

 for(int i=0;i<m;i++)
 {
    if( op[i]==1)
     {
          for(int j=l[i];j<=r[i];j++)
             add[j]+=val[i];
     }
    else
    {
        int mx = -(1e9);

         for(int j=l[i];j<=r[i];j++)
        {
            mx=max(mx, maxi[j] + add[j] );
        }

        if( mx!=val[i])
        {
            cout<<"NO\n";
            return 0;
        }
    }
 }

 cout<<"YES\n";
 for(int i=1;i<=n;i++)
    cout<<maxi[i]<<" ";



 return 0;

}
