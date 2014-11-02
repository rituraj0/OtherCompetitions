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

int id[35][35];
bool edge[600][600];
int nodes=0;

void add( int i , int j , int x, int y)
{
      edge[ id[i][j] ][ id[x][y] ]=edge[ id[x][y] ][ id[i][j] ]=true;
}


int main()
{
 ios_base::sync_with_stdio(0);


 id[1][1]=1; id[1][2]=2;

  nodes=3;

 for(int i=2;i<=31;i++)
     for(int j=1;j<=i;j++)
    {
        id[i][j]=nodes;
         nodes++;
    }

    fill(edge,0);

   for(int i=2;i<=31;i++)
     for(int j=1;j<=i;j++)
   {
        add(i,j,i-1,1);

           for(int k=1;k<j;k++)
               add(i,j,i-1,k);
   }

   int req;

   cin>>req;

   for(int i=0;i<30;i++)
      if( req&(1<<i) )
   {
       add(1,2,31,i+2);
   }

   cout<<nodes-1<<endl;

   for(int i=1;i<nodes;i++,cout<<endl)
      for(int j=1;j<nodes;j++)
        if( edge[i][j])
         cout<<"Y";
         else
          cout<<"N";

 return 0;

}
