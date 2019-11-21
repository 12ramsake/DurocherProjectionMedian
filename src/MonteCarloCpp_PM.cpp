//library(RcppArmadillo)
//Sys.setenv("PKG_CXXFLAGS"="-std=c++11")
//#include <Rcpp.h>
//#include <iostream.h>
#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace Rcpp;

// [[Rcpp::export()]]
arma::mat getPM1(arma::mat u,arma::mat  data){
  
  arma::mat proj;
  arma::mat medians;
  //for each unit vector
  //data projections
  u=normalise(u,2,0);
  proj= data * u;
  //compute the median
  medians= median(proj, 0 );
  for(unsigned int i=0;i<medians.n_cols;i++){
     u.col(i)=as_scalar(medians.col(i))*u.col(i);
   }
   medians=mean(u,1);
  return medians*u.n_rows;
}

// [[Rcpp::export()]]
arma::uvec getMedInd(arma::vec curr_col,double med,bool even){
  
  arma::uvec index;
  unsigned int n1,n2;
  if(!even){
    index.zeros(1);
    for(unsigned int i=0;i<curr_col.size();i++){
      if(curr_col(i)==med){
        index=i;
        break;
      }
    }
  }
  else{
    index=sort_index(curr_col);
    n1=(curr_col.size()/2);
    n2=n1+1;
    index=index.subvec(n1-1,n2-1);
    }
  return index;
  }

// [[Rcpp::export()]]
arma::mat getPM2(arma::mat u,arma::mat  data){

  arma::mat proj;
  arma::mat medians;
  arma::vec pm;
  arma::uvec ind;
  arma::vec w;
  bool even= data.n_rows%2==0;
  w.zeros(data.n_rows);
  //for each unit vector
  //data projections
  u=normalise(u,2,0);
  proj= data * u;
  //compute the median
  medians= median(proj, 0 );
  //Rcout<<medians<<" \n";
  for(unsigned int i=0;i<medians.n_cols;i++){
    ind=getMedInd(proj.col(i),as_scalar(medians.col(i)),even );
    // Rcout<<as_scalar(ind)<<" w \n";
    // Rcout<<(double)w((int)as_scalar(ind))+1/medians.n_cols<<" \n";
    for(unsigned int j=0;j<ind.size();j++)
      w(ind[j])+=1/((double)medians.n_cols*(double)ind.size());
    //pm=pm+data.row(as_scalar(ind)).t();
    //+data.row(as_scalar(ind));
  }
 // Rcout<<w<<" \n";
  pm=data.t()*w;
  return pm;
}
  

/*** R
normalize<-function(x){
  return(x/sqrt(sum(x^2)))
}
n=10

# x1<-apply(x1,MARGIN=1,normalize)

dat=cbind(rnorm(n),rnorm(n),rnorm(n))
dim(dat)
dim(x1)
d=10
n=5
N=50000
set.seed(440)
x1<-replicate(N,rnorm(d))
dat=replicate(d,rnorm(n))
getPM1(x1,dat)
getPM2(x1,dat)
set.seed(440)
# projectionMedianMC(dat,N=N,method=1)
# projectionMedianMC(dat,N=N,method=2)

*/
