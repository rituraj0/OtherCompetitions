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
 bool same[105];
 bool cool[105];

 int comp[105][105];

int main()
{
 ios_base::sync_with_stdio(0);

 int row,col;

 cin>>row>>col;

 for(int i=0;i<row;i++)
     cin>>in[i];

 fill(cool,true);

 fill(same , 0 );

 fill( comp ,-1 );

 for(int k=0;k<col;k++)
 {
     int maxi= -1;

     bool cool=true;

     for(int i=0;i<row;i++)
        for(int j=i+1;j<row;j++)
        {
           if( cool )
           {
                if(comp[i][j] < 1)//first or till not both are equal
                {
                    if( in[i][k] > in[j][k])
                        { cool = false;
                          continue;
                        }
                }

               if( comp[i][j] == 1) // i < j , kuchh bhi chelega
                  continue;

               if( comp[i][j] == 0)// i == j
                {
                    if(  in[i][k] > in[j][k])
                       {cool=false;
                        continue;
                       }
                }

                if( comp[i][j] < 1)
                {
                    if( in[i][k] == in[j][k] )
                         comp[i][j]=0;
                    else
                          comp[i][j] = 1;
                }


           }
        }



}

 int ans=0;

 for(int i=0;i<col;i++)
 {
     if( !cool[i])
     {
         ans++;
         continue;
     }

     if( same[i])
        continue;

     break;
 }

 cout<<ans<<endl;

 return 0;

}
