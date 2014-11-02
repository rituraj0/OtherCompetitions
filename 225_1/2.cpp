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

#define inf  1000000100
#define pii pair<int,int>

pii prev[100010],curr[100010],blocked[100010];

int main()
{
 ios_base::sync_with_stdio(0);

 int n,m;

 cin>>n>>m;

 for(int i=1;i<=m;i++)
 {
   int x,y;
   cin>>x>>y;
   blocked[i]=mp(x,y);;
 }

 sort( blocked+1,blocked+m+1);

  blocked[0]=mp(0,0);

 int cc=0,pc=1;

 prev[pc]=mp(1,1);

 for(int i=1;i<=m;i++)
 {

       if( blocked[i].X!=blocked[i-1].X+1)
       {
           pc=1;
           prev[1].Y=n;
       }

       int j;

       for(j=i;j<=m&&blocked[j].X==blocked[i].X;j++);

       j--;

       cc=0;

       int ls=1;

       for(int k=i;k<=j;k++)
       {
             if( blocked[k].Y-1>=ls)
             {
                 curr[++cc].X=ls;
                 curr[cc].Y=blocked[k].Y-1;
             }
             ls=blocked[k].Y+1;
       }

       if( ls <=n)
       {
           curr[++cc].X=ls;
           curr[+cc].Y=n;
       }

       for(int k=1;k<=cc;k++)
       {
            int st=1,dr=pc,ret=-1;

            while(st<=dr)
            {
                int mid=(st+dr)/2;

                if( prev[mid].Y>=curr[k].X)
                {
                    ret=prev[mid].X;
                    dr=mid-1;
                }
                else
                {
                    st=mid+1;
                }
            }

            if(ret==-1 || ret > curr[k].Y)
                 curr[k].X=curr[k].Y=inf;
            else
                 curr[k].X=max(ret,curr[k].X);

       }

            pc=0;

            for(int k=1;k<=cc;k++)
                 if( curr[k].X!=inf && curr[k].Y!=inf)
                   prev[++pc]=curr[k];

            if(pc==0)
            {
                cout<<"-1\n";
                return 0;
            }

            i=j;
 }

 if( blocked[m].X!=n)
 {
     pc=1;
     prev[1].Y=n;
 }

 if( prev[pc].Y==n)
    cout<<2*n-2<<endl;
 else
    cout<<"-1\n";

 return 0;

}
