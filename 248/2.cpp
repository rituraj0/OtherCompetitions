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

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

int in[1005][1005];
int row,col;
int len[4][1005][1005];
int ht[1005];

bool cool( int x, int y)
{
     if( x>=0 && x< row && y >=0 && y<col ) return true;
     return false;
}

int dfs( int w, int x, int y)
{
     if( !cool(x,y)) return 0;

     if( len[w][x][y]!=-1 ) return len[w][x][y];

     int ans=0;

     if( in[x][y]==1)
         ans=1+dfs( w, x+dx[w] , y+dy[w]);

     return len[w][x][y]=ans;
}

int solve( int mx , int curr)
{
     int ans=ht[curr];
     int l=curr,r=curr;

     for( int lm=ht[curr];lm>0;lm--)
     {
           while( (l>=0) && ( ht[l] >=lm)  )l--;
           while( (r<mx) && ( ht[r] >=lm)  )r++;
           ans=max( ans , lm*(r-l-1) );
     }
     return ans;
}

int main()
{
 ios_base::sync_with_stdio(0);

 int Q;

 cin>>row>>col>>Q;

 for(int i=0;i<row;i++)
     for(int j=0;j<col;j++)
      cin>>in[i][j];

   fill(len,-1)   ;

  for(int w=0;w<4;w++)
     for(int i=0;i<row;i++)
      for(int j=0;j<col;j++)
         dfs(w,i,j);

  int op,x,y;

  while(Q--)
  {
       cin>>op>>x>>y;
       x--;y--;

       if(op==1)
       {
            in[x][y]=1-in[x][y];

            for(int w=0;w<4;w++)
            {
                        for(int i=0;i<row;i++) len[w][i][y]=-1;
                        for(int i=0;i<col;i++) len[w][x][i]=-1;

                        for(int i=0;i<row;i++) dfs(w,i,y);
                        for(int i=0;i<col;i++) dfs(w,x,i);
            }
       }
      else
      {
            int ans=0;

            for(int i=0;i<col;i++) ht[i]=len[0][x][i]; ans=max( ans , solve(col,y) );
            for(int i=0;i<col;i++) ht[i]=len[3][x][i]; ans=max( ans , solve(col,y) );

            for(int i=0;i<row;i++) ht[i]=len[1][i][y]; ans=max( ans , solve(row,x) );
            for(int i=0;i<row;i++) ht[i]=len[2][i][y]; ans=max( ans , solve(row,x) );

            cout<<ans<<endl;
      }
  }


 return 0;

}
