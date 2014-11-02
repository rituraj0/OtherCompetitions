#include <bits/stdc++.h>
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
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */

#define maxn 405

int n,m;
int in_order[405];
int latest[maxn][maxn];

void solve()
{
    vector<int> comp;

    scanf("%d%d",&n,&m);

    for(int i=1;i<=m;i++)
        scanf("%d",&in_order[i]);
//
//    int i=1;
//
//    while(i<=m)
//    {
//        int curr=in_order[i];
//         comp.pb( in_order[i]);
//
//         while( i <=m)
//         {
//                if( curr==in_order[i])
//                {
//                    i++;
//                }
//               else
//               {
//                   break;
//               }
//         }
//
//    }
//
//    m=comp.sz;


//   for(int i=0;i<comp.sz;i++)
//     cout<<comp[i]<<"  ";

     fill( latest[m+1],63);

     for(int i=m;i>=1;i--)
     {
          for(int j=1;j<=400;j++)
             latest[i][j]=latest[i+1][j];

           latest[i][ in_order[i] ]=i;
     }

     set<int> memo;

      int pf=0;

     for(int i=1;i<=m;i++)
     {
          if( memo.find(in_order[i])!=memo.end())//no page fault;
             continue;

           pf++;

          if( memo.size() < n)//an empty page
          { memo.insert( in_order[i] );
            continue;
          }

          //now remove
          vector< pair<int,int> >temp;

           for(int j=1;j<=400;j++)
              if( memo.find(j)!=memo.end())
                {
                    temp.pb( mp( latest[i][j] ,j) );
                }

          sort(temp.bg,temp.end());

          int rem=temp[ ((int)temp.sz)-1 ].Y;

          memo.erase( memo.find(rem) );
           memo.insert(in_order[i]);
     }

     cout<<pf<<endl;
}


int main()
{
 int test;
 scanf("%d",&test);

 while(test--)
 {
     solve();
 }

 return 0;

}
