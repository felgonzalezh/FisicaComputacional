/*
This program takes 3 arguments: float float float
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define USAGE "./a.out a b h"



float funcion(float x);
int main(int argc, char **argv){

  float a;
  float b;
  float h;
  int n_points;
  int i;
  
  a = 0.0;
  b = 0.0;
  h = 0.0;
  n_points=0;


  if(argc!=4){
    printf("USAGE: %s\n", USAGE);
    exit(1);
  }
  
  /*initialize the variable according to the arguments*/
  a = atof(argv[1]);
  b = atof(argv[2]);
  h = atof(argv[3]);

  n_points = (int)((b-a)/h);

  float cuad,in,k;

  in=0;
  cuad=0;
  k=0;


  for(i=0;i<n_points;i++){
    cuad=h*(funcion(a+i*h));
    in=cuad+k;
    k=in;
    /*   printf("suma %f\n   ", in);*/
  }

  printf("%f \n", in);
   return 0;
}

float funcion(float x){
  float y;
  y=(1.0)/(sqrt(1+cos(x)*sin(x)));
  return y;
}
