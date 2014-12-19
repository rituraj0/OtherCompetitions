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

 string in[105];

 int comp[105][105];

int main()
{
 ios_base::sync_with_stdio(0);

 int row,col;

 cin>>row>>col;

 for(int i=0;i<row;i++)
     cin>>in[i];

 fill( comp ,-1 );

 int ans=0;

 for(int k=0;k<col;k++)
 {
     bool cool=true;

     for(int i=0;i<row;i++)
        for(int j=i+1;j<row;j++)
        {
           if( cool )
           {
                if(comp[i][j] < 1)//first or till now both are equal
                {
                    if( in[i][k] > in[j][k])
                        { cool = false;
                        }
                }
           }
        }

        if(!cool)
        {  ans++;
           continue;
        }

      for(int i=0;i<row;i++)
         for(int j=i+1;j<row;j++)
          {
                if(comp[i][j] < 1)//first or till now both are equal
                {
                    if( in[i][k] == in[j][k] )
                    {
                        comp[i][j]=0;
                    }
                    else if( in[i][k] < in[j][k] )
                    {
                        comp[i][j]=1;
                    }
                }
           }
 }

 cout<<ans<<endl;

 return 0;

}
