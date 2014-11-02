#include<algorithm>
#include<iomanip> 
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
#include<ctime>
#include<map>
#include<set>
using namespace std;

#define pb push_back

class TreeUnionDiv2 
{
public:

int dist1[10][10], dist2[10][10];
vector<int> p;
int n;

int K;

int solve()
{

 int ans=0;
 
 for(int i=0;i<n;i++)
   for(int j=i+1;j<n;j++)
     {
        int x=p[i];
        int y=p[j];
        
         if( dist1[i][j] + dist2[x][y] + 2 ==K )
            ans++;
      }
      
      return ans;
   
}

int  maximumCycles(vector <string> tree1, vector <string> tree2, int K) 
{
 n=tree1.size();
 this->K=K;
 
 memset( dist1, 63 , sizeof(dist1));
 memset( dist2 ,63, sizeof(dist2) );
 
 for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
      {
        dist1[i][i]=dist2[i][i]=0;
        
        if( tree1[i][j]=='X' )
          dist1[i][j]=1;

        if( tree2[i][j]=='X' )
          dist2[i][j]=1;
          
          }

       for(int k=0;k<n;k++)
          for(int i=0;i<n;i++)
             for(int j=0;j<n;j++)              
                 {  dist1[i][j]=min( dist1[i][j] , dist1[i][k] + dist1[k][j] );
                     dist2[i][j]=min( dist2[i][j] , dist2[i][k] + dist2[k][j] );
                  }
                
           for(int i=0;i<n;i++)
            p.pb(i);
            
            int ans=0;
            
           do
           {
              ans=max(ans,solve() );
           
            }  while( next_permutation( p.begin() , p.end() ) );
            
            
            return ans;
                                  
	
}

};


double test0() {
	string t0[] = {"-X",
 "X-"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"-X",
 "X-"}
;
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 4;
	TreeUnionDiv2 * obj = new TreeUnionDiv2();
	clock_t start = clock();
	int my_answer = obj->maximumCycles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"-X-",
 "X-X",
 "-X-"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"-X-",
 "X-X",
 "-X-"}
;
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 5;
	TreeUnionDiv2 * obj = new TreeUnionDiv2();
	clock_t start = clock();
	int my_answer = obj->maximumCycles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"-X-",
 "X-X",
 "-X-"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"-X-",
 "X-X",
 "-X-"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 3;
	TreeUnionDiv2 * obj = new TreeUnionDiv2();
	clock_t start = clock();
	int my_answer = obj->maximumCycles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"-X---",
 "X-XXX",
 "-X---",
 "-X---",
 "-X---"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"-X-X-",
 "X-X-X",
 "-X---",
 "X----",
 "-X---"}
;
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 6;
	TreeUnionDiv2 * obj = new TreeUnionDiv2();
	clock_t start = clock();
	int my_answer = obj->maximumCycles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"-XX------",
 "X------X-",
 "X--XX-X--",
 "--X--X---",
 "--X------",
 "---X----X",
 "--X------",
 "-X-------",
 "-----X---"}

;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"-X-------",
 "X-X------",
 "-X-XX----",
 "--X---X--",
 "--X--X---",
 "----X--XX",
 "---X-----",
 "-----X---",
 "-----X---"}
;
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 7;
	TreeUnionDiv2 * obj = new TreeUnionDiv2();
	clock_t start = clock();
	int my_answer = obj->maximumCycles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 17;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
