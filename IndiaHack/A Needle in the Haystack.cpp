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

char in[100009];
char tx[1009];

int aval[30];
int req[30];

int test,n,m;

int main()
{


   scanf("%d",&test);

   for(int t=0;t<test;t++)
   {
        scanf("%s",in);
         n=strlen(in);

        scanf("%s",tx);
        m=strlen(tx);

        if(m<n)
        {
            printf("NO");
            continue;
        }

        for(int i=0;i<26;i++)
        {
            req[i]=0;
            aval[i]=0;
        }

        for(int i=0;i<m;i++)
        {
            req[ tx[i]-'a']++;
        }





   }

 return 0;

}
