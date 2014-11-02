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

string in[1001][10];
int row,col,k,w;


int boss[1010];

int root(int x)
{
     if( boss[x]==x) return x;
     return  root( boss[x]);
}




int main()
{
 ios_base::sync_with_stdio(0);

 cin>>row>>col>>k>>w;

 for(int i=1;i<=k;i++)
     for(int j=0;j<row;j++)
       cin>>in[i][j];

   if(k==1)
   {
       cout<<row*col*w<<endl;
       cout<<"1 0\n";
       return 0;
   }

  for(int i=1;i<=k;i++)
     for(int j=i+1;j<=k;j++)
     {
             int d=0;
              for(int a=0;a<row;a++)
                 for(int b=0;b<col;b++)
                   if( in[i][a][b]!=in[j][a][b])
                     d++;

              cout<<i<<"  "<<j<<"  "<<d<<endl;

              all[d*w].pb( mp(i,j));
     }

   for(int i=1;i<=k;i++)
     all[row*col].pb( mp(i,i));

 fill(done,0);

 int sm=0;

 for(int i=0;i<=100000;i++)
 {
       for(int j=0;j<all[i].sz;j++)
       {
            pair<int,int> curr=all[i][j];

            if( curr.X==curr.Y)
            {
                if( !done[curr.X])
            }

            if( done[curr.X] && done[curr.Y])
                 continue;

            if( (!done[curr.X]) && (!done[curr.Y]) )
            {
                ans.pb( mp(curr.X,0) );
                ans.pb( mp(curr.Y,curr.X));
                sm+=row*col;
                sm+=i*w;
                done[curr.X]=done[curr.Y]=true;
                continue;
            }

            if( (!done[curr.X]) && done[curr.Y] )
            {
                 ans.pb( mp(curr.X,curr.Y) );
                 sm+=i*w;
                 done[ curr.X]=true;
                 continue;
            }

            if( (done[curr.X]) && (!done[curr.Y]) )
            {
                 ans.pb( mp( curr.Y , curr.X) );
                 sm+=i*w;
                 done[ curr.Y]=true;
            }
       }
 }

 cout<<sm<<endl;

 for(int i=0;i<ans.sz;i++)
     cout<<ans[i].X<<" "<<ans[i].Y<<endl;


 return 0;

}
