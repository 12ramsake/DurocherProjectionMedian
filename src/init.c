#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME:
   Check these declarations against the C/Fortran source code.
*/

/* .Call calls */
extern SEXP _DurocherProjectionMedian_getMedInd(SEXP, SEXP, SEXP);
extern SEXP _DurocherProjectionMedian_getPM1(SEXP, SEXP);
extern SEXP _DurocherProjectionMedian_getPM2(SEXP, SEXP);
extern SEXP _DurocherProjectionMedian_rcpparma_bothproducts(SEXP);
extern SEXP _DurocherProjectionMedian_rcpparma_hello_world();
extern SEXP _DurocherProjectionMedian_rcpparma_innerproduct(SEXP);
extern SEXP _DurocherProjectionMedian_rcpparma_outerproduct(SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"_DurocherProjectionMedian_getMedInd",             (DL_FUNC) &_DurocherProjectionMedian_getMedInd,             3},
    {"_DurocherProjectionMedian_getPM1",                (DL_FUNC) &_DurocherProjectionMedian_getPM1,                2},
    {"_DurocherProjectionMedian_getPM2",                (DL_FUNC) &_DurocherProjectionMedian_getPM2,                2},
    {"_DurocherProjectionMedian_rcpparma_bothproducts", (DL_FUNC) &_DurocherProjectionMedian_rcpparma_bothproducts, 1},
    {"_DurocherProjectionMedian_rcpparma_hello_world",  (DL_FUNC) &_DurocherProjectionMedian_rcpparma_hello_world,  0},
    {"_DurocherProjectionMedian_rcpparma_innerproduct", (DL_FUNC) &_DurocherProjectionMedian_rcpparma_innerproduct, 1},
    {"_DurocherProjectionMedian_rcpparma_outerproduct", (DL_FUNC) &_DurocherProjectionMedian_rcpparma_outerproduct, 1},
    {NULL, NULL, 0}
};

void R_init_DurocherProjectionMedian(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
