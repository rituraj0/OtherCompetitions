#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
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

#define print(a) cout<<(#a)<<" = "<<a<<"  ";
#define println(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );

vector <string> parse(string s, string c)
{
  int len = c.length(), p = -len, np;
  vector <string> ans;

  do
    {
      np = s.find(c, p+len);
      ans.push_back(s.substr(p+len, np - p - len));
      p = np;
    }
  while (p != string::npos);

  return ans;
}


/*Solution code starts here */

#define maxn (1<<25)

int ulta( int in)
{
    int ans=0;

     while(in>0)
     {
        ans=ans*10;
        ans+=in%10;
        in=in/10;
     }

     return ans;
}

bool prime[maxn];//i th ith odd number
bool done[maxn];

int main()
{

  fill(prime,true);
  fill(done,0);


 for(int i=1;i<maxn;i++)
     if( prime[i] )
        {
             int curr=2*i+1;

             for(int j=3*curr;j<2*maxn;j+=2*curr)
                 prime[j/2]=false;
        }
//
//      for(int i=1;i<maxn;i++)
//         if( prime[i])
//          cout<<" - "<<2*i+1<<" ";

        int cont=0;


    for(int i=1;i<maxn;i++)
           if(!done[i])
             if( prime[i] )
               {
                    int curr=2*i+1;

                    int tp=ulta(curr);

                    if(curr==tp)
                        continue;

                      if(tp%2==0)
                        continue;

                   if(tp<2*maxn)
                    {
                       if( prime[tp/2] )
                       {
                          printf("%d\n",curr);

                          done[i]=done[tp/2]=true;

                         cont++;
                       }
                   }

              }

              cout<<cont<<endl;


 return 0;

}
