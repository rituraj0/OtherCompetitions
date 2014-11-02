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
#define sz size()

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

string solve( )
{
      string in;
      cin>>in;

    int a=0,b=0,c=0;

      int i=0;

      while( (in[i]=='|') && (i<in.sz) )
        {
            i++;
            a++;
        }

         i++;

      while((in[i]=='|') && (i<in.sz) )
      {
          i++;
          b++;
      }

      i++;

      while((in[i]=='|') && (i<in.sz))
      {
        i++;
        c++;
      }


      for(int i=1;i<=in.sz;i++)
          for(int j=1;j<=in.sz;j++)
            for(int k=1;k<=in.sz;k++)
            {
                  if(i+j+k==a+b+c)
                     if(i+j==k)
                  {
                       if( abs(a-i) + abs(j-b) + abs(c-k) <=2 )
                       {
                            string ans="";

                            for(int m=0;m<i;m++)
                                  ans+="|";

                              ans+="+";

                             for(int m=0;m<j;m++)
                                 ans+="|";

                                 ans+="=";

                               for(int m=0;m<k;m++)
                                 ans+="|";

                                 return ans;


                       }

                  }

            }


            return "Impossible";

}

int main()
{
	 ios_base::sync_with_stdio(0);

	 cout<<solve();

 return 0;

}
