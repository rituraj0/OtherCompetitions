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


bool dp[500][550];

 int row,col;

 int id( int r, int c)
 {
     return r*col+c;
 }

int main()
{
 ios_base::sync_with_stdio(0);

 fill(dp,0);

 cin>>row>>col;


 string hor,ver;

 cin>>hor;

 cin>>ver;

 for(int i=0;i<row;i++)
 {
     if( hor[i]=='>' )
     {
         for(int j=1;j<col;j++)
         {
             dp[ id(i,j-1) ][  id(i,j)]=true;

             //cout<<id(i,j-1)<<"  "<<id(i,j)<<endl;
         }
     }
    else
    {
         for(int j=col-2;j>=0;j--)
         {
             dp[ id(i,j+1) ][  id(i,j)]=true;

              //cout<<id(i,j+1)<<"  "<<id(i,j)<<endl;
         }

    }

 }


 for(int i=0;i<col;i++)
 {

      if( ver[i]=='^')
      {
            for(int j=row-2;j>=0;j--)
            {
                dp[ id(j+1,i) ][ id(j,i)]=true;

                 //cout<<id(j+1,i)<<"  "<<id(j,i)<<endl;
            }
      }
     else
     {
            for(int j=1;j<row;j++)
            {
                dp[ id(j-1,i) ][ id(j,i)]=true;

               // cout<<id(j-1,i)<<"  "<<id(j,i)<<endl;
            }
     }
 }

 int all=row*col;

 for(int i=0;i<all;i++)
      dp[i][i]=true;

 for(int k=0;k<all;k++)
     for(int i=0;i<all;i++)
       for(int j=0;j<all;j++)
         dp[i][j]=(dp[i][j]|| ( dp[i][k] && dp[k][j]) );

 bool cool=true;

 for(int i=0;i<all;i++)
     for(int j=0;j<all;j++)
       if( ! dp[i][j])
         cool=false;

 if( cool)
    cout<<"YES"<<endl;
 else
    cout<<"NO"<<endl;

 return 0;

}
