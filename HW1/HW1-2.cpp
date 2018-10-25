#include "OJ.h"
#include "Point.h"

#include <bits/stdc++.h>
using namespace std;

bool update(int n, vector<Point> &points) {
	bool ret = false;
	for (int i = 0; i < n; i ++) {
		for (int j = i + 1; j < n; j ++) {
			Line L1 = {points[i], points[n+i] - points[i]};
			Line L2 = {points[j], points[n+j] - points[j]};
			if (intersection(L1, L2)) {
				ret = true;
				Point tmp;
				tmp = points[i]; points[i] = points[j]; points[j] = tmp;
			}
		}
	}
	return ret;
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
	if (points.size() <= 3000) {
		naive(points);
		return;
	}

    vector<Point> sub1, sub2;
    partition(points,sub1,sub2);
    oj.set_match(points);
	oj.set_match(sub1);
    oj.set_match(sub2);
    display();

    // D&C ...
	DC(sub1);
	DC(sub2);
}
