#ifndef __LPsolver_h
#define __LPsolver_h
#include <cassert>
#include <vector>
#include <iostream>
#include "glpk.h"

void massert(bool passed, const char *msg)
{
	if( !passed )
	{
		std::cerr << msg << std::endl;
		assert(0);
	}
}

/*
** optimize z = c^T x  (optimize: GLP_MIN or GLP_MAX)
** subject to Ax <= b
** 
** return z
*/

double lp_solver(int optimize, const std::vector<double>& c, const std::vector<std::vector<double>>& A, std::vector<double> &x, const std::vector<double> &b)
{
	massert(c.size() == x.size(), "c's length doesn't match x's length");
	massert(A[0].size() == x.size(), "# cols in A doesn't match x's length");
	massert(A.size() == b.size(), "# rows in A doesn't match b's length");

	glp_prob *lp = glp_create_prob();
	glp_smcp parameter;
	glp_init_smcp(&parameter);
	parameter.msg_lev = GLP_MSG_ERR;
	glp_set_obj_dir(lp, optimize);
	glp_add_rows(lp, A.size());
	glp_add_cols(lp, A[0].size());

	for(int i=0; i<(int)b.size(); ++i)
		glp_set_row_bnds(lp, i+1, GLP_UP, 0, b[i]);

	for(int i=0; i<(int)x.size(); ++i)
	{
		glp_set_col_bnds(lp, i+1, GLP_FR, 0, 0);
		glp_set_obj_coef(lp, i+1, c[i]);
	}

	int m = A.size()*A[0].size();
	int *ia = new int[m+1];
	int *ja = new int[m+1];
	double *ar = new double[m+1];
	int ptr =0;

	for(int i=0; i<(int)A.size(); ++i)
		for(int j=0; j<(int)A[0].size(); ++j)
		{
			++ptr;
			ia[ptr] = i+1;
			ja[ptr] = j+1;
			ar[ptr] = A[i][j];
		}

	glp_load_matrix(lp, ptr, ia, ja, ar);
	glp_simplex(lp, &parameter);
	double z = glp_get_obj_val(lp);

	for(int i=0; i<(int)x.size(); ++i)
		x[i] = glp_get_col_prim(lp, i+1);

	return z;
}

#endif
