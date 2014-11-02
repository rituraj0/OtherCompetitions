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

int main()
{
	 ios_base::sync_with_stdio(0);
	 
	 int test;
	 
	 cin>>test;
	 
	 while(test--)
	 {
	 	string in;
	 	
	 	cin>>in;
	 	
	 	if( in.find("010")!=string::npos or in.find("101")!=string::npos)
	 	  cout<<"Good";
	    else	  
	      cout<<"Bad";
	      cout<<endl;
    }
	 
	
 return 0;
 
}
