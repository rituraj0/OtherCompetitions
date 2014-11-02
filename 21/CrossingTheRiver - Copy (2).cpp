#include<algorithm>
#include<iostream>
#include <sstream>
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




class CrossingTheRiver {
public:

  bool cool(vector<int> rem, int dp, int wl, int wh, int ll, int lh , int ww, int lw)
    {
        // we need at least one block of each of the heights between wl and wh:
        for (int i=wl; i<=wh; i++) 
            if ( (--ww < 0) || (--rem[i] < 0) ) 
                return false;
                    
        // we need at least one block of each of the heights between ll and lh:
            if ( (--landWidth < 0) || (--rem[x] < 0) ) {
                return false;
            }
        }
        // count the number of blocks in the intervals that we can use.
        // inter is the number of blocks that can be used both to fill the water
        // and to fill the land.
        
        int inter = 0;
        int landonly = 0;
        int wateronly = 0;
        for (int x=depth; x<=100; x++) {
            bool water = ( wl <= x && x <= wh);
            bool land  = ( ll <= x && x <= lh);
            if ( water && land ) {
                inter += rem[x];
            } else if (water) {
                wateronly  += rem[x];
            } else if (land) {
                landonly += rem[x];
            }
        }
        // first use the blocks not in the intersection.
        waterWidth = max(0, waterWidth - wateronly);
        landWidth = max(0, landWidth - landonly);
        // use the remaining blocks
        return ( waterWidth + landWidth <= inter );
    }

    string isItEvenPossible( int ww, int landWidth, vector <int> blockHeight, int depth)
    {
        int n = blockHeight.size();
        vector<int> count(101, 0);
        for (int i=0; i<n; i++) {
            count[ blockHeight[i] ]++;
        }
        if (count[depth] >= waterWidth) {
            return "POSSIBLE";
        }
        for (int wl=depth; wl<=depth+1; wl++) if (count[wl]) {
            for (int wh=wl; wh<=100; wh++) if (count[wh]) {
                for (int ll=wh-depth; ll<=wh-depth+1; ll++) {
                    if ( (ll < 0) || count[ll] == 0 ) {
                        continue;
                    }
                    for (int lh=ll; lh<=100; lh++) if (count[lh]) {
                        if (possiblePick(waterWidth, landWidth, count,
                                         depth, wl,wh, ll,lh)) {
                            return "POSSIBLE";
                        }
                    }
                }
            }
        }
        return "IMPOSSIBLE";
    }
};




#include<ctime>


double test0() {
	int p0 = 3;
	int p1 = 3;
	int t2[] = {3,4,4,5,5, 6};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	CrossingTheRiver * obj = new CrossingTheRiver();
	clock_t start = clock();
	string my_answer = obj->isItEvenPossible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "POSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 3;
	int p1 = 3;
	int t2[] = {3,4,4,5,6, 6};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	CrossingTheRiver * obj = new CrossingTheRiver();
	clock_t start = clock();
	string my_answer = obj->isItEvenPossible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "IMPOSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 5;
	int p1 = 2;
	int t2[] = {4,4,4,4,4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 4;
	CrossingTheRiver * obj = new CrossingTheRiver();
	clock_t start = clock();
	string my_answer = obj->isItEvenPossible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "POSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 5;
	int p1 = 5;
	int t2[] = {5,5,5,5,5,5, 2,3,4,4,6, 7, 3, 2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	CrossingTheRiver * obj = new CrossingTheRiver();
	clock_t start = clock();
	string my_answer = obj->isItEvenPossible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "POSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 5;
	int p1 = 7;
	int t2[] = {6,6,6,6,6,6,6, 6,6,6,6,6,7,8,9,10};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 5;
	CrossingTheRiver * obj = new CrossingTheRiver();
	clock_t start = clock();
	string my_answer = obj->isItEvenPossible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "POSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int p0 = 1;
	int p1 = 1;
	int t2[] = {5,3,4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	CrossingTheRiver * obj = new CrossingTheRiver();
	clock_t start = clock();
	string my_answer = obj->isItEvenPossible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "IMPOSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
