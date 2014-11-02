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


#define maxi (100009)

string in[maxi][2];
int P[maxi];


int main()
{
 ios_base::sync_with_stdio(0);

 int n;

 cin>>n;

    string x,y;

 for(int i=1;i<=n;i++)
     {
         cin>>x>>y;
         in[i][0]=x;//min(x,y);
         in[i][1]=y;//max(x,y);
     }

  for(int i=1;i<=n;i++)
     cin>>P[i];


 if(n==1)
 {
     cout<<"YES"<<endl;
     return 0;
 }


  string last=min(   in[ P[1] ][0] , in[ P[1] ][1]  );

  for(int i=2;i<=n;i++)
  {
        if( last < in[ P[i] ][0] )
             last=in[ P[i] ][0];
        else if( last < in[ P[i] ][1] )
              last = in[ P[i] ][1];
        else
        {
            cout<<"NO"<<endl;
            return 0;
        }
  }

     cout<<"YES"<<endl;
 return 0;

}
