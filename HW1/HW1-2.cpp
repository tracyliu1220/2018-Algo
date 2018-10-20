#include "OJ.h"
#include "Point.h"

#include <bits/stdc++.h>
using namespace std;

bool update(int n, vector<Point> &points) {
	bool ret = false;
	Line L1 = {points[1], points[3] - points[1]};
	Line L2 = {points[0], points[2] - points[0]};
	if (intersection(L1, L2)) {
		ret = true;
		Point tmp;
		tmp = points[0]; points[0] = points[1]; points[1] = tmp;
	}
	return ret;
}

void partition(vector<Point> &points, vector<Point> &sub1, vector<Point> &sub2) {
	int n = points.size() / 2;

		
}

void naive(vector<Point> &points){
    int n = (int) points.size()/2;
    do{
        oj.set_match(points);
        display();
    } while ( update(n,points) );
}

void DC(vector<Point> &points){
    // boundary case (naive) ...
	if (points.size() == 4)
		naive(points);

    vector<Point> sub1, sub2;
    partition(points,sub1,sub2);
    //oj.set_match(points);
	oj.set_match(sub1);
    oj.set_match(sub2);
    display();

    // D&C ...
	DC(sub1);
	DC(sub2);
}
