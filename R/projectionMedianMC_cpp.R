#' Calculates the Projection Median using the Monte Carlo approximations in Durocher et. al 2017
#'
#' This function allows you to calculate the projection median approximately or exactly in 2D.
#' @param data a nxd matrix of your data.
#' @param N Number of vectors to generate in the Monte Carlo algorithm
#' @param method Which Monte Carlo algorithm to use? As per Durocher et. al 2017
#' @keywords multivariate, robust, location, Monte Carlo
#' @export
#' @examples
#'
projectionMedianMC_cpp<-function(data,N=10000,method=1){

  x1<-replicate(N,rnorm(ncol(data)))
  if(method==1){
    getPM1(x1,data)
  }
  else{
    getPM2(x1,data)
  }

  return(pm)
}
