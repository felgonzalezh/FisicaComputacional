#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double y_prima(int n_points, double x, double y);

int main(void){
  FILE *fileout;
  double h;
  int i;
  int n_points;
  h=0.05;
  n_points=(int)((1.0+h)/h);

  double *x;
  double *y;
  double z,z2,z3,z4, average_z  ,x1,x2,x3,y1,y2,y3;

  x = malloc(n_points * sizeof(int));
  y = malloc(n_points * sizeof(double));
  
  if(!x){
    printf("There is something wrong with array x\n");
    exit(1);
  }
  if(!y){
    printf("There is something wrong with array y\n");
    exit(1);
  }

  fileout=fopen("1oed_rungekuta4.dat", "w");
 if(!fileout){
    printf("There is something wrong with file\n");
    exit(1);
  }
  x[0]=0;

  for(i=1;i<n_points;i++){
    z=y_prima(n_points,x[i-1],y[i-1]);
    x[i]=x[i-1]+h;
    y[i]=y[i-1]+(h*z);
  
    
  
    /*first step*/
    x1 = x[i-1] + (h/2.0);
    y1 = y[i-1] + (h/2.0)*z;
    z2 = y_prima(n_points,x1, y1);
    
      /*second step*/
    x2 = x[i-1] + (h/2.0);
    y2 = y[i-1] + (h/2.0)*z2;
    z3 = y_prima(n_points,x2, y2);
        
      /*third step*/
    x3 = x[i-1] + h;
    y3 = y[i-1] + h*z3;
    z4 = y_prima(n_points,x3, y3);
    
      /*fourth step*/
    average_z = (1.0/6.0)*(z + 2.0*z2 + 2.0*z3 + z4);
    
    x[i] = x[i-1] + h;
    y[i] = y[i-1] + h*average_z;
    
    fprintf(fileout, "%f  %f \n", x[i], y[i]);
  }
  fclose(fileout);
  
  return 0;
}

double y_prima(int n_points, double x, double y){
  double y_p;
  y_p=(y*y)+1;
  return y_p;
}
