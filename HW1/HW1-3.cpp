#include "OJ.h"
#include "Point.h"

#include <bits/stdc++.h>
using namespace std;

bool update(int n, vector<Point> &points) {
	bool ret = false;
	if (n <= 1) return ret;
	Line L1 = {points[0], points[2] - points[0]};
	Line L2 = {points[1], points[3] - points[1]};
	if (intersection(L1, L2)) {
		ret = true;
		Point tmp;
		tmp = points[0]; points[0] = points[1]; points[1] = tmp;
	}
	/*
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
	*/
	return ret;
}

void naive(vector<Point> &points){
	int n = (int) points.size()/2;
	if (n == 1) {
		oj.set_match(points);
		return;
	}
	
	do{
        oj.set_match(points);
        display();
    } while ( update(n,points) );
}

void partition(vector<Point> &points, vector<Point> &sub1, vector<Point> &sub2) {
	int n = points.size() / 2;
	int founded = 0;
	int i, j, rats_cnt, holes_cnt;
	Point base, base1, base2;
	for (i = 0; i < n; i ++) {	// rats
		for (j = 0; j < n; j ++) {	// holes
			base = points[n+j] - points[i];
			rats_cnt = 0, holes_cnt = 0;
			for (int p = 0; p < n; p ++) {
				if (p != i && (points[p] - points[i]) % base < 0) rats_cnt ++;
			    if (p != j && (points[n+p] - points[i]) % base < 0) holes_cnt ++;	
			}
			if (rats_cnt == holes_cnt) {
				base1 = points[i]; base2 = points[n+j];
				founded = 1;
				break;
			}
		}
		if (founded) break;
	}
	
	sub1.clear(); sub2.clear();

	for (int p = 0; p < n; p ++) {
		if (p == i) continue;
		if ((points[p] - points[i]) % base < 0) sub1.push_back(points[p]);
		else sub2.push_back(points[p]);
	}
	for (int p = 0; p < n; p ++) {
		if (p == j) continue;
		if ((points[n+p] - points[i]) % base < 0) sub1.push_back(points[n+p]);
		else sub2.push_back(points[n+p]);
	}
	points.clear();
	points.push_back(base1);
	points.push_back(base2);
}

void DC(vector<Point> &points){
    // boundary case (naive) ...
	if (points.size() <= 4) {
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
