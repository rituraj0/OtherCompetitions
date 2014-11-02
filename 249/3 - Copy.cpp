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
int in[1006];
string ans[2010];

int x[1006],y[1006];


void draw( int a, int b, int c, int d , int ev)
{


     int diff=d-b;
     int add=1;
     if( diff < 0)
         add=-1;

     diff=abs(diff);

     cout<<a<<"  "<<b<<"  "<<c<<"  "<<d<<endl;

     for(int i=1;i<=diff;i++)
     {
         int tx=a+i;
         int ty=b+add*i+ev;

         if(add<0)
             ans[ty][tx]='/';
          else
               ans[ty][tx]='\\';

               cout<<ty<<" "<<tx<<"  "<<ans[ty][tx]<<endl;
     }
}


int main()
{
 ios_base::sync_with_stdio(0);

 cin>>n;

 for(int i=1;i<=n;i++)
     cin>>in[i];

  int tx=0,ty=0;

   x[0]=tx;y[0]=ty;

   int my=0;
   int mny=0;

   for(int i=1;i<=n;i++)
   {
        tx+=in[i];
        x[i]=tx;

         if(i%2==0)
             ty-=in[i];
         else
              ty+=in[i];

         y[i]=ty;

         my=max( my , y[i] );
         mny=min( mny , y[i]);
   }

 for(int i=0;i<=n;i++)
       y[i]=my-y[i];

  for(int i=0;i<=2006;i++)
     ans[i]=string(1005,' ');

   for(int i=1;i<=n;i++)
      {

       draw( x[i-1] , y[i-1] , x[i] , y[i] , i%2 );

      }

     print( my)   ; print(mny);


   for(int i=0;i<=my-mny+10;i++)
    {
         if( (ans[i].find("\\")==string::npos ) && ( ans[i].find("/")==string::npos ) )
             continue;
      cout<<ans[i].substr(1,tx)<<endl;;
    }

 return 0;

}
