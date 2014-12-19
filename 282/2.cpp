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


string text ,pat;

bool endhere[100009];

bool lcp[100009];

void init()
{
    int n=text.size();
    int m=pat.size();

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

    }
}

int main()
{
 ios_base::sync_with_stdio(0);

 while(1)
 {
     cin>>text>>pat;

     fill(endhere,0);

      init();

      for(int i=0;i<n;i++)
         if( endhere[i])
          cout<<i<<" - ";
 }


 return 0;

}
