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

vector<int>  fail;

string A,B,virus;
int as,bs,vs;

vector<int> fail_array( string in)
{
    int n = sz(in);
    vector<int> ans( n+1, -1 );

    for(int i=1; i<=n ; i++)
    {
        int pos = ans[i-1];

        while( (pos != -1) && ( in[pos] != in[i-1] ) )
             pos = ans[pos];

        ans[i]= pos +1;
    }

    return ans;
}


int next_len( int pat_po ,char curr)
{
        while( (pat_po != -1)&&(pat_po == sz(virus) || virus[pat_po] != curr ) )
        {
            pat_po = fail[ pat_po];
        }

        pat_po++;

        return pat_po;
}

#define maxn 102
int memo[maxn][maxn][maxn];
int next[maxn][maxn][maxn];

int solve( int ap  , int bp , int len)
{
    if( len >= vs )
     return -(1<<20);

    if( ap==as || bp==bs )
    {
        return 0;
    }

    if( memo[ap][bp][len]!=-1)
         return memo[ap][bp][len];

    int ans = 0;

    if(  solve(ap+1,bp,len) > ans )
    {
        ans = solve(ap+1,bp,len);
        next[ap][bp][len]=0;//dont taje any char and incrament left
    }

    if(  solve(ap ,bp+1,len) > ans )
    {
        ans = solve(ap,bp+1,len);
        next[ap][bp][len]=1;//dont take this and incremnt rright
    }

    if( A[ap] == B[bp] )
    {
         if( solve(ap+1 ,bp+1,len) > ans )
          {
            ans = solve(ap+1,bp+1,len);
            next[ap][bp][len]=2;//dont take this and incremnt both
          }

          int n_len = next_len( len , A[ap]);

          if( solve(ap+1 ,bp+1, n_len) +1  > ans )
          {
            ans = solve( ap+1, bp+1, n_len ) + 1;
            next[ap][bp][len]=3;//TAKE this and incremnt both
          }
    }

    return  memo[ap][bp][len]=ans;
}

int main()
{
 ios_base::sync_with_stdio(0);

 cin>>A>>B>>virus;

 as=sz(A);
 bs=sz(B);
 vs=sz(virus);

 fail = fail_array(virus);

 fill(memo,-1);
 fill(next,-1);

 int L= solve(0,0,0);

  string ans="";

  int ap=0,bp=0,len=0;

  while( next[ap][bp][len]!=-1)
  {
      int x =  next[ap][bp][len];

      if( x==0)
        ap++;
      else if( x==1)
        bp++;
      else if( x==2)
      {
          ap++;
          bp++;
      }
      else
      {
          len = next_len( len , A[ap] );

          ans+=A[ap];

          ap++;
          bp++;
      }
  }

 // print(sz(ans));

  if( sz(ans)==0)
    cout<<"0"<<endl;
  else
  cout<<ans<<endl;



 return 0;

}
