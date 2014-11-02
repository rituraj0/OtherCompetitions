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
#define fo freopen("outputTest.txt","w",stdout)

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

#define maxn (1<<10)


int n;



vector<double> a,b;


void process( int t)
{
    cin>>n;

     a.resize(n);
     b.resize(n);

    for(int i=0;i<n;i++)
         cin>>a[i];

    for(int i=0;i<n;i++)
          cin>>b[i];

    sort(a.bg,a.en);
    sort(b.bg,b.en);

//
//      cout<<"\n\n";
//
//       for(int i=0;i<n;i++)
//         cout<<a[i]<<"  ";
//
//      cout<<"\n\n";
//
//    for(int i=0;i<n;i++)
//          cout<<b[i]<<"  ";
//
//          cout<<"\n\n";


   //fair game

   int ans=0;

   bool done[20];

   fill(done,0);

   for(int i=n-1;i>=0;i--)
   {

           int id=-1;

             for(int j=0;j<n;j++)
                 if( !done[j])
                   if( a[i] < b[j])
                 {
                      id=j;
                      break;
                }

                if(id==-1)
                {
                      ans++;

                      for(int j=0;j<n;j++)
                          if( !done[j])
                      {
                          id=j;
                          break;
                      }
                }

                done[id]=true;
   }

   cout<<ans<<endl;



}

int main()
{

   fi;fo;


   int test;


   cin>>test;

   for(int i=1;i<=test;i++)
     process(i);


 return 0;

}
