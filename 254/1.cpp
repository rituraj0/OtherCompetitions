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


string in[200];


string solve( string ret , string tp)
{
     for(int i=0;i<tp.sz;i++)
         if( ret[i]=='.')
            ret[i]=tp[i];

     return ret;
}

int main()
{
 ios_base::sync_with_stdio(0);

 int row,col;

 cin>>row>>col;

 for(int i=0;i<row;i++)
     cin>>in[i];

  string a="",b="";

  for(int i=0;i<col;i++)
    if(i&1)
  {
      a+='W';
      b+='B';
  }
  else
  {
      a+='B';
      b+='W';
  }

  for(int i=0;i<row;i++)
    {

      if( i&1)
        in[i]=solve( in[i],a);
    else
         in[i]=solve( in[i],b);

         cout<<in[i]<<endl;
    }



 return 0;

}
