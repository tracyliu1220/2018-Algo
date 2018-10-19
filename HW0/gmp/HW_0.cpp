#include <iostream>
#include <gmp.h>
#include <stdio.h>
using namespace std;

int main() {

	mpf_t M;
	mpf_t D;

	mpf_init2(M, 120000);
	mpf_init2(D, 120000);

	mpf_set_si(M, 1);
	mpf_set_si(D, 6);

	for (int i = 0; i < 18500; i ++) {
		mpf_ui_sub(M, 4, M);
		mpf_sqrt(M, M);
		mpf_ui_sub(M, 2, M);

		mpf_mul_ui(D, D, 2); 
	}
	
	mpf_sqrt(M, M);
	mpf_mul(M, M, D);
	mpf_div_ui(M, M, 2);

	char* s = (char*)malloc(sizeof(char)*12000);

	gmp_sprintf(s, "%.10100Ff\n", M); 
	
	//for (int i = 0; i < 10200; i ++) {
	//	cout << s[i];
	//	if (i % 1000 == 0) cout << '\n';
	//}

	int T;
	cin >> T;

	int l, r;
	while (T --) {
		cin >> l >> r;
		for (int i = l; i <= r; i ++)
			cout << s[i+1];
		cout << '\n';
	}
}
