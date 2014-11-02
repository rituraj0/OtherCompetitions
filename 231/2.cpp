#include<algorithm>
#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<fstream>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#include<set>
using namespace std;

#define pb push_back
#define mp make_pair
#define Y second
#define X first

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;



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

int len,x;

string ret="Impossible";

void solve( int n2)
{
     vector<int> ans;

      int rem=0;
      ans.pb( n2);

      while( ans.size() <= len)
      {
           int curr=10*rem + ans [ ans.size()-1];
             ans.pb( curr/x );
             rem=curr%x;
      }

      if( ans[0]==ans[ ans.size()-1 ] )
         if( ans[1]!=0)
          {
            string tp(len,'0');

            for(int i=1;i<=len;i++)
                  tp[i-1]=('0'+ans[i]);

            ret=min( ret , tp);

      }



}

int main()
{
	 ios_base::sync_with_stdio(0);

	 cin>>len>>x;


	 for(int i=1;i<=9;i++)
         solve(i);

     cout<<ret<<endl;

 return 0;

}
