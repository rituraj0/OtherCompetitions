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

int n;
int in[1<<15];

int main()
{
	 ios_base::sync_with_stdio(0);

	 cin>>n;

	 for(int i=0;i<n;i++)
         cin>>in[i];

     sort(in,in+n);

      int cost=(1<<30),st=-1,diff=-1;

      //enumarte   y=d*x+b

      for(int d=0;d<=20005;d++)
      {
           int mx=-(1<<30),mn=(1<<30);

              for(int i=0;i<n;i++)
              {
                  mx=max(mx, in[i]- i*d  );
                  mn=min(mn ,in[i]-i*d  );
              }

           int b=(mx-mn+1)/2; //adjust b

            if( b < cost )
            {
                 cost=b;
                 st=mn+b;
                 diff=d;

            }
      }


      cout<<cost<<endl<<st<<" "<<diff<<endl;

       return 0;
}
