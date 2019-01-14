#include <iostream>
#include <vector>
#include "lp_solver.h"
using namespace std;

/*
** optimize z = c^T y  (optimize: GLP_MIN or GLP_MAX)
** subject to Ay <= b
** 
** return z
*/

//double lp_solver(int optimize, const vector<double>& c, const vector<vector<double> >& A, vector<double> &y, const vector<double> &b);

int main(){

	/*
	 * The following code solves the linear program
	 * 
	 * minimize    7 y1 + 11 y2 + 13 y3
	 * subject to  y1 - y3 <= 1
	 *             2 y1 + y2 + 3 y3 <= 2
	 *
	 *
	 * i.e. return min{c^T y : Ay <= b}
	 */

	vector<vector<double> > A;
	A.resize(18);
	for(int i=0; i<2; ++i){
		A[i].resize(10);
	}	
	A[0][0] = A[0][1] = 150, A[0][6] = A[0][7] =  75;
	A[1][2] = A[1][3] = 200, A[1][6] = A[1][7] = 100, A[1][8] = A[1][9] = 120;
	A[2][4] = A[2][5] = 150, A[2][8] = A[2][9] =  80;

	for (int i = 0; i < 5; i ++)
		A[3 + i][2 * i] = 1;

	for (int i = 0; i < 10; i ++)
		A[8 + i][i] = -1;

	vector<double> y;
	y.resize(3);

	vector<double> c;
	c.resize(18);
	for (int i = 0; i < 8; i ++)
		cin >> c[i];

	vector<double> b;
	b.resize(10);
	for (int i = 0; i < 10; i ++)
		cin >> b[i];

	
	double z = lp_solver(GLP_MAX, c, A, y, b);

	cout << "the optimal objective value is " << z << endl;
	cout << "the optimal solution is (";	
	for(int i=0; i<3; ++i){
		cout << y[i] << ((i==2) ? "" : ",");
	}
	cout << ")" << endl;
	return 0;
}

