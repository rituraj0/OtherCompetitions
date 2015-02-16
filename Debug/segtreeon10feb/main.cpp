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

#define maxn 300009

int val[maxn],N;

/* count number of  bit diff */
//fromhttps://sites.google.com/site/indy256/algo/sparse_table_rmq
int logtable[maxn];

void  populate_log()
{
    fill( logtable,0);

    for(int i=2;i<=N;i++)
        logtable[i]=logtable[i>>1]+1;
}
/* RMQ using sparse table */
int mini[maxn][20];

void mini_process()
{
    for(int i=0;i<N;i++)
        mini[i][0]=i;

    for(int len=1 ; (1<<len)<=N; len++)
      for(int i=0;i+(1<<len)-1 < N ;i++)
      {
         int  mid = i+ (1<<(len-1) );

         if( val[ mini[i][len-1] ] < val[ mini[mid][len-1] ])
         {
             mini[i][len]=mini[i][len-1];
         }
        else
        {
            mini[i][len] = mini[mid][len-1];
        }
    }
}

int mini_query ( int st, int ed)
{
     int diff= logtable[ ed-st ];
     int lf = val[ mini[st][diff] ];
     int rt = val [ mini[ed-(1<<diff)+1][diff] ];
     return min(lf,rt);
    // bit =
}

/* RMQ using sparse table */
int gcd[maxn][20];

void gcd_process()
{
    for(int i=0;i<N;i++)
        gcd[i][0]=val[i];

    for(int len=1 ; (1<<len)<=N; len++)
      for(int i=0;i+(1<<len)-1 < N ;i++)
      {
         int  mid = i+ (1<<(len-1) );

         gcd[i][len]= __gcd( gcd[i][len-1] , gcd[mid][len-1] );
      }
}


int gcd_query ( int st, int ed)
{
     int diff= logtable[ ed-st ];
     int lf = gcd[st][diff] ;
     int rt = gcd[ed-(1<<diff)+1][diff] ;
     return __gcd(lf,rt);
    // gcd compexity is number og digit ( in base 10 ) , of minimum number , from wiwkiperdia
}

vector<int>  solve( int len)
{
   vector<int> ans;

   for(int i=0;i+len-1<N;i++)
     if( gcd_query(i,i+len-1)==mini_query(i,i+len-1))
       ans.pb(i+1);

   return ans;
}

int main()
{
 ios_base::sync_with_stdio(0);

 cin>>N;

 for(int i=0;i<N;i++)
    cin>>val[i];

 //poppilte log table
  populate_log();

  //build mini tree
  mini_process();

  //build gcd tree
  gcd_process();

  //now start query

   int a, b;

 // cout<<mini_query(1,4)<<"  "<<gcd_query(1,4)<<endl;

   vector<int> ans=solve(1);
   int len =1;

  int lo = 1 ,hi = N;//lo always true

  while( lo < hi)
  {
      int mid = (lo+hi+1)/2;

       vector<int> tp = solve(mid);

       if( sz(tp)>0)
       {
           len = mid;
           ans = tp;
           lo=mid;
       }
       else
       {
          hi=mid-1;
       }
  }

  cout<<sz(ans)<<" "<<len-1<<endl;

  for(int i=0;i<sz(ans);i++)
    cout<<ans[i]<<" ";

 return 0;

}
