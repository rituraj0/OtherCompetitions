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


int lcp[5005][5005];
string a,b;
int al[5005],bl[5005];

void lc( string x, string y)
{
   fill(lcp,0);
   int n=x.sz;
   int m=y.sz;

   for(int i=n-1;i>=0;i--)
     for(int j=m-1;j>=0;j--)
       if( x[i]==y[j])
         lcp[i][j]=1+lcp[i+1][j+1];
}

int main()
{
 ios_base::sync_with_stdio(0);

 cin>>a>>b;

int n=a.sz;
int m=b.sz;

   lc(a,a);

    for(int i=0;i<n;i++)
    {
         int mx=0;

         for(int j=0;j<n;j++)
             if(i!=j)
              mx=max(mx, lcp[i][j]);

         mx++;

         al[i]=mx;
    }

    lc(b,b);

    for(int i=0;i<m;i++)
    {
         int mx=0;

           for(int j=0;j<m;j++)
            if(i!=j)
             mx=max( mx, lcp[i][j] );

           mx++;

       bl[i]=mx;
    }

    lc(a,b);

    int ans=(1<<20);

      for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
      {
           int tp=max( al[i] , bl[j] );

            if( lcp[i][j]>=tp)
                 ans=min( ans , tp);
      }

      if( ans==(1<<20) )
         cout<<"-1\n";
      else
          cout<<ans<<endl;

      return 0;

}
