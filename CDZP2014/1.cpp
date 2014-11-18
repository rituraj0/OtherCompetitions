#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(s) ((int)(s.size()))
#define bg begin()
#define en end()
#define Y second
#define X first
typedef int ll;
#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
const double pi     =   acos(-1.0);
const double eps    =   1e-8;
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */

ll dp[15];
string go;

inline void solve(int test)
{


}

int main()
{
 int test;
  int tp,x,n;

 //scanf("%d",&test);

 cin>>test;


 while(test--)
 {
         cin>>go;

         n=go.size();

       dp[0]=1;

     for(int i=1;i<=n;i++)
     {
           tp=0;

           if( go[i-1]!='0')
             tp=dp[i-1];

            if( i > 1)
                {
                     x= ( go[i-2]-'0')*10 + (go[i-1]-'0');

                    if( x <=26 )
                        tp+=dp[i-2];
               }

          dp[i]=tp;
     }


   cout<<dp[n]<<endl;
 }

 return 0;

}


