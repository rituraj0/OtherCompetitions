#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(s) ((int)(s.size()))
#define bg begin()
#define en end()
typedef long long ll;
#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
const double pi     =   acos(-1.0);
const double eps    =   1e-8;
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */

#define maxn 10000

bool cool( int x1, int y1 , int x2, int y2 , int x3, int y3 )
{
   int a= x1*(y2-y3);
   int b= x2*(y3-y1);
   int c= x3*(y1-y2);

  // cout<<x1<<" "<<y1<<" "<<x2<<"  "<<y2<<"  "<<x3<<"  "<<y3<<endl;

 //  cout<<a+b+c<<endl;

   return (a+b+c == 0);
}

int X[maxn] , Y[maxn];

bool done[maxn];

int main()
{
 ios_base::sync_with_stdio(0);
 int n;


 cin>>n;

 int a,b;

 cin>>a>>b;


 for(int i=1;i<=n;i++)
 cin>>X[i]>>Y[i];

 fill(done,0);

 int ans=0;

 for(int i=1;i<=n;i++)
      if( !done[i] )//atke this
        {
             for(int j=1;j<=n;j++)
                  if( !done[j])
                    {
                        if( cool(a,b,X[i],Y[i] , X[j] , Y[j] ) )
                            done[j]=true;
                    }

            ans++;
        }


    cout<<ans<<endl;


 return 0;

}
