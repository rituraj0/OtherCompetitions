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


#define maxn 100009

string text ,pat;
int n,m;

bool endhere[maxn];

int lcp[maxn];

void init()
{
     n=text.size();
     m=pat.size();

     //compute lcp
    lcp[0]=0;

    int len=0;

    for(int i=1;i<m;)
    {
        if( pat[i]==pat[len])
        {
            len++;
            lcp[i]=len;
            i++;
        }
        else if( len > 0)
        {
            len= lcp[len-1];
        }
        else
        {
           len=0;
           lcp[i]=len;
           i++;
        }
    }


    // match in
    len=0;

    for(int i=0;i<n;)
    {
         if( text[i] == pat[len])
         {
           len++;
           i++;
         }

         if( len == m)
         {
             endhere[i-1] = true;
             len=lcp[len-1];
         }
         else if( (i<n) && (text[i]!=pat[len]) )
         {
            if( len > 0)
             len = lcp[len-1];
            else
             i++;
         }
    }//end match for

}

int last[maxn];

ll dp[maxn];
ll sum[maxn];

const ll mod= 1000000007LL;
            //1000000007
int main()
{
 ios_base::sync_with_stdio(0);

     cin>>text>>pat;

     fill(endhere,0);

      init();

//     int fs=-1;
//
//     for(int i=0;i<n;i++)
//         if( endhere[i])
//         {
//           fs=i+1;
//           break;
//         }
//
//       if( fs==-1)
//       {
//           cout<<"0"<<endl;
//           continue;
//       }
//
//      for(int i=0;i<n;i++)
//         if( endhere[i])
//             cout<<i<<" - ";
//
//          cout<<endl;

      int seen = -1;

      for(int i=1;i<=n;i++)
      {
          if( i >= m)
             {
                if( endhere[i-1])
                {
                    seen=i-m;
                   // cout<<i<<"  "<<seen<<endl;
                }
             }

           last[i]=seen;
      }

//      for(int i=1;i<=n;i++)
//        cout<<last[i]<<" - ";
//
//      cout<<"\n\n";

      dp[0]=1;
      sum[0]=1;

      for(int i=1;i<=n;i++)
      {
          dp[i]=dp[i-1];

          if( last[i]!=-1)
             dp[i]= (dp[i] + sum[ last[i] ] )%mod;

           sum[i]= (sum[i-1] + dp[i])%mod;
      }

      cout<<(mod+dp[n]-1)%mod<<endl;

 return 0;

}


//9125835
