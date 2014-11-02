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
#include<iomanip>
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

double w[200][200];
double a[200][200],b[200][200];



int main()
{
 ios_base::sync_with_stdio(0);

 int n;

 cin>>n;


 for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        cin>>w[i][j];


   for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
   {
          a[i][j]=(w[i][j]+w[j][i])/2.0;
          b[i][j]=(w[i][j]-w[j][i])/2.0;
   }


    for(int i=0;i<n;i++,cout<<endl)
      for(int j=0;j<n;j++,cout<<" ")
        cout<<std::setprecision(9)<<a[i][j];


      for(int i=0;i<n;i++,cout<<endl)
      for(int j=0;j<n;j++,cout<<" ")
        cout<<std::setprecision(9)<<b[i][j];




 return 0;

}
