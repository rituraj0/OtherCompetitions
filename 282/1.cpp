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


bool cool( vector<int> in)
{
    int cc=0;

     int n=sz(in);

     for(int i=0;i<n;i++)
     {
         if( in[i]==0)// (
            cc++;
         else
             cc--;


         if( cc < 0 )
            return false;
     }

     return (cc==0);
}

int main()
{
 ios_base::sync_with_stdio(0);


 string in;

 cin>>in;

 int n=sz(in);

 int lc=0,rc=0,hc=0;

 int last=-1;

 for(int i=0;i<n;i++)
      if( in[i]=='(' )
           lc++;
       else if( in[i]==')')
             rc++;
      else
          {
             hc++;
             last=i;
          }

  if( lc < rc + hc )
  {
      cout<<"-1\n";
      return 0;
  }


  vector<int> tp;


  for(int i=0;i<n;i++)
     if( in[i]=='(')
         tp.pb(0);
    else if( in[i]==')')
         tp.pb(1);
    else if( in[i]=='#')
    {
        int diff=1;

        if( i==last)
          diff = lc - (rc+hc-1);

        for(int j=0;j<diff;j++)
            tp.pb(1);
    }


    if( !cool(tp))
    {
        cout<<"-1\n";
        return 0;
    }

    for(int i=0;i<n;i++)
         if( in[i]=='#')
            {
                int diff=1;

                if( i==last)
                 diff = lc - (rc+hc-1);

                 cout<<diff<<endl;
            }

 return 0;

}
