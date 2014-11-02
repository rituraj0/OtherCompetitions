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
#include<map>
#include<set>
using namespace std;

#define pb push_back


class NewArenaPassword 
{
public:

vector<char >comp[55];//every component 

vector<int> graf[55]; //conflict graph 
bool visit[55];

string old;

void  dfs(int curr ,  int cn )
{
   if( visit[curr] )
     return ;
     
     comp[ cn].pb( old[curr] );
  
     visit[curr]=true;
          
     for(int i=0;i<graf[curr].size() ;i++ )
       dfs(  graf[curr][i]  , cn);
}

int process( int u )
{
   int cont[30];
   
   memset(cont,0,sizeof(cont) );
   
   for(int i=0;i<comp[u].size();i++)
     cont[  comp[u][i]-'a' ]++;
     
     int mx=0,total=0;
     
     for(int i=0;i<30;i++)
       {mx=max( mx  , cont[i] );
        total+=cont[i];
       }
       
       return (total-mx);
   }
       

int  minChange(string old, int K) 
{
  this->old=old;
   int n=old.size();
   
   memset( visit, 0, sizeof(visit) );
   
   for(int i=0 ,j=n-K ; j < n ;i++,j++)
    { graf[i].pb(j);
       graf[j].pb(i);
     }
     
    int cn=0;
     
   for(int i=0;i<K;i++)
     if( !visit[i]  )
       {dfs( i , cn );
        cn++;
        }
   
   for(int j=n-K;j<n;j++)
     if( !visit[j] )
       {
          dfs(j,cn);
           cn++;
     }
          
           
           	int ans=0;
           	
        for(int i=0;i<cn;i++)
           ans+=process(i);
             
           return ans;                    			       			
}

};


double test0() {
	string p0 = "topcoderopen";
	int p1 = 5;
	NewArenaPassword * obj = new NewArenaPassword();
	clock_t start = clock();
	int my_answer = obj->minChange(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "puyopuyo";
	int p1 = 4;
	NewArenaPassword * obj = new NewArenaPassword();
	clock_t start = clock();
	int my_answer = obj->minChange(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "loool";
	int p1 = 3;
	NewArenaPassword * obj = new NewArenaPassword();
	clock_t start = clock();
	int my_answer = obj->minChange(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = "arena";
	int p1 = 5;
	NewArenaPassword * obj = new NewArenaPassword();
	clock_t start = clock();
	int my_answer = obj->minChange(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string p0 = "amavckdkz";
	int p1 = 7;
	NewArenaPassword * obj = new NewArenaPassword();
	clock_t start = clock();
	int my_answer = obj->minChange(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
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
