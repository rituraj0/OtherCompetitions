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

int _all=0,_one=0,_no=0;
int n,m;

char ans[1005][2010];

int sum[2010];

bool solve( int mx)
{
     memset(sum,0,sizeof(sum));

     int all=_all;
     int one=_one;
     int no=_no;

     for(int i=0;i<n;i++)
     {
          for(int j=0;j<2*m;j+=2)
          {
                if( (sum[j]<mx) && (sum[j+1] < mx ) && (all >0 ) )
                {
                    all--;
                    sum[j]++;
                    sum[j+1]++;

                    ans[i][j]='1'; ans[i][j+1]='1';
                }
               else if( (sum[j] < mx ) && (one > 0) )
                {
                    one--;
                    sum[j]++;
                    ans[i][j]='1'; ans[i][j+1]='0';
                }
               else if( (sum[j+1]<mx) && (one >0) )
                {
                    one--;
                    sum[j+1]++;
                    ans[i][j]='0'; ans[i][j+1]='1';
                }
               else if( no > 0)
               {
                    no--;
                    ans[i][j]='0'; ans[i][j+1]='0';
               }
          }
     }

     if( (all > 0) || (one >0) || (no >0) )
         return false;

     return true;

}

int main()
{
	 ios_base::sync_with_stdio(0);

	 cin>>n>>m;

	 string tp;

    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
       {
         cin>>tp;

         if(tp=="11")
             _all++;
         else if( tp=="00")
              _no++;
         else
             _one++;
     }

     int lo=0,hi=n;
     int ret=-1;

     while(lo<=hi)
     {
         int mid=(lo+hi)/2;

         if( solve(mid) )
         {
             ret=mid;
             hi=mid-1;
         }
         else
         {
             lo=mid+1;
         }
     }

     solve(ret);

     for(int i=0;i<n;i++,cout<<endl)
        for(int j=0;j<2*m;j+=2,cout<<" ")
         cout<<ans[i][j]<<ans[i][j+1];

 return 0;

}
