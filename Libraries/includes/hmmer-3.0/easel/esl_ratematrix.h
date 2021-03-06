/* Routines for manipulating evolutionary rate matrices.
 * 
 * SRE, Tue Jul 13 16:09:05 2004 [St. Louis]
 * SVN $Id: esl_ratematrix.h 162 2007-04-10 23:50:12Z eddys $
 */
#ifndef ESL_RATEMATRIX_INCLUDED
#define ESL_RATEMATRIX_INCLUDED
extern "C" {

/* 1. Setting standard rate matrix models. */
extern int esl_rmx_SetWAG(ESL_DMATRIX *Q, double *pi); 
extern int esl_rmx_SetJukesCantor(ESL_DMATRIX *Q);
extern int esl_rmx_SetKimura(ESL_DMATRIX *Q, double alpha, double beta);
extern int esl_rmx_SetF81(ESL_DMATRIX *Q, double *pi);
extern int esl_rmx_SetHKY(ESL_DMATRIX *Q, double *pi, double alpha, double beta); 

/* 2. Debugging routines for validating or dumping rate matrices. */
extern int esl_rmx_ValidateP(ESL_DMATRIX *P, double tol, char *errbuf);
extern int esl_rmx_ValidateQ(ESL_DMATRIX *Q, double tol, char *errbuf);

/* 3. Other routines in the exposed ratematrix API. */
extern int    esl_rmx_ScaleTo(ESL_DMATRIX *Q, double *pi, double unit);
extern int    esl_rmx_E2Q(ESL_DMATRIX *E, double *pi, ESL_DMATRIX *Q);
extern double esl_rmx_RelativeEntropy(ESL_DMATRIX *P, double *pi);
extern double esl_rmx_ExpectedScore  (ESL_DMATRIX *P, double *pi);

}
#endif /*ESL_RATEMATRIX_INCLUDED*/
