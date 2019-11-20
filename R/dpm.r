#' Calculates the Projection Median (see Durocher 2009)
#'
#' This function allows you to calculate the projection median approximately or exactly in 2D.
#' @param data a nxd matrix of your data. For two dimensions, d must be 2
#' @param N Number of vectors to generate in the Monte Carlo algorithm
#' @param method Which Monte Carlo algorithm to use? As per Durocher et. al 2017
#' @param exact2D calculate the pm exactly *data must be 2 dimensions
#' @keywords multivariate, robust, location
#' @export
#' @examples
#' data<-cbind(rnorm(151),rnorm(151))
#' dpm(data)
#' dpm(data,exact2D=TRUE)


dpm<-function(data,N=10000,method=1,exact2D=F){
  if(exact2D)
    return(projectionMedian2D(data))
  else
    return(projectionMedianMC_cpp(data,N=N,method=method))
}
