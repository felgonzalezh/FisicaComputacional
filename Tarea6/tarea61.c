#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "tarea62.h"


int main(void){
  FILE *fileout;
  double h;
  int i,j;
  int n_points;
  h=0.01;
  n_points=(int)((30.0+h)/h);

  double sigma, rho, beta;
  sigma=10.0;
  rho=28;
  beta=2.666;
  
  double *x;
  double *y;
  double *z;
  double *t;
  
  x = malloc(n_points * sizeof(double));
  y = malloc(n_points * sizeof(double));
  z = malloc(n_points * sizeof(double));
  t = malloc(n_points * sizeof(double));
  
  if(!x){
    printf("There is something wrong with array x\n");
    exit(1);
  }
  if(!y){
    printf("There is something wrong with array y\n");
    exit(1);
  }
if(!z){
    printf("There is something wrong with array x\n");
    exit(1);
  }
  if(!t){
    printf("There is something wrong with array y\n");
    exit(1);
  }


/*variables de la rutina de runge kuta a 4 orden*/
double t1,t2,t3;
  double x1,x2,x3, k1_x,k2_x,k3_x,k4_x,average_kx;
double y1,y2,y3, k1_y,k2_y,k3_y,k4_y,average_ky;
double z1,z2,z3, k1_z,k2_z,k3_z,k4_z,average_kz;

  /*10 diferentes condiciones iniciales condiciones iniciales*/
  srand48 (time(NULL));
  t[0]=0;

for(j=1;j<11;j++){

if(j==1){
fileout=fopen("tarea6_1.dat", "w");
  x[0]=drand48() * (10.0+10.0) - 10.0;
  y[0]=drand48() * (10.0+10.0) - 10.0;
  z[0]=drand48() * (10.0+10.0) - 10.0;
}
if(j==2){
fileout=fopen("tarea6_2.dat", "w");
 x[0]=drand48() * (10.0+10.0) - 10.0;
  y[0]=drand48() * (10.0+10.0) - 10.0;
  z[0]=drand48() * (10.0+10.0) - 10.0;
}
if(j==3){
fileout=fopen("tarea6_3.dat", "w");
x[0]=drand48() * (10.0+10.0) - 10.0;
  y[0]=drand48() * (10.0+10.0) - 10.0;
  z[0]=drand48() * (10.0+10.0) - 10.0;
}
if(j==4){
fileout=fopen("tarea6_4.dat", "w");
x[0]=drand48() * (10.0+10.0) - 10.0;
  y[0]=drand48() * (10.0+10.0) - 10.0;
  z[0]=drand48() * (10.0+10.0) - 10.0;
}
if(j==5){
fileout=fopen("tarea6_5.dat", "w");
x[0]=drand48() * (10.0+10.0) - 10.0;
  y[0]=drand48() * (10.0+10.0) - 10.0;
  z[0]=drand48() * (10.0+10.0) - 10.0;
}
if(j==6){
fileout=fopen("tarea6_6.dat", "w");
x[0]=drand48() * (10.0+10.0) - 10.0;
  y[0]=drand48() * (10.0+10.0) - 10.0;
  z[0]=drand48() * (10.0+10.0) - 10.0;
}
if(j==7){
fileout=fopen("tarea6_7.dat", "w");
x[0]=drand48() * (10.0+10.0) - 10.0;
  y[0]=drand48() * (10.0+10.0) - 10.0;
  z[0]=drand48() * (10.0+10.0) - 10.0;
}
if(j==8){
fileout=fopen("tarea6_8.dat", "w");
x[0]=drand48() * (10.0+10.0) - 10.0;
  y[0]=drand48() * (10.0+10.0) - 10.0;
  z[0]=drand48() * (10.0+10.0) - 10.0;
}
if(j==9){
fileout=fopen("tarea6_9.dat", "w");
x[0]=drand48() * (10.0+10.0) - 10.0;
  y[0]=drand48() * (10.0+10.0) - 10.0;
  z[0]=drand48() * (10.0+10.0) - 10.0;
}
if(j==10){
fileout=fopen("tarea6_10.dat", "w");
x[0]=drand48() * (10.0+10.0) - 10.0;
  y[0]=drand48() * (10.0+10.0) - 10.0;
  z[0]=drand48() * (10.0+10.0) - 10.0;
}

/*printf(" %f %f %f \n", x[0], y[0], z[0]);*/
  if(!fileout){
    printf("There is something wrong with file\n");
    exit(1);
  }


  for(i=1;i<n_points;i++){
    k1_x=x_prima(n_points,sigma,t[i-1],x[i-1],y[i-1]);
    k1_y=y_prima(n_points,rho,t[i-1],x[i-1],y[i-1],z[i-1]);
    k1_z=z_prima(n_points,beta,t[i-1],x[i-1],y[i-1],z[i-1]);

    t[i]=t[i-1]+h;
    x[i]=x[i-1]+(h*k1_x);
    y[i]=y[i-1]+(h*k1_y);
    z[i]=z[i-1]+(h*k1_z);
 
    /*first step*/
    t1 = t[i-1] + (h/2.0);
    x1 = x[i-1] + (h/2.0)*k1_x;
    y1 = y[i-1] + (h/2.0)*k1_y;
    z1 = z[i-1] + (h/2.0)*k1_z;

    k2_x=x_prima(n_points,sigma,t1,x1,y1);
    k2_y=y_prima(n_points,rho,t1,x1,y1,z1);
    k2_z=z_prima(n_points,beta,t1,x1,y1,z1);
  
      /*second step*/
    t2 = t[i-1] + (h/2.0);
    x2 = x[i-1] + (h/2.0)*k2_x;
    y2 = y[i-1] + (h/2.0)*k2_y;
    z2 = z[i-1] + (h/2.0)*k2_z;

    k3_x=x_prima(n_points,sigma,t2,x2,y2);
    k3_y=y_prima(n_points,rho,t2,x2,y2,z2);
    k3_z=z_prima(n_points,beta,t2,x2,y2,z2);
       
      /*third step*/

    t3 = t[i-1] + h;
    x3 = x[i-1] + h*k3_x;
    y3 = y[i-1] + h*k3_y;
    z3 = z[i-1] + h*k3_z;

    k4_x=x_prima(n_points,sigma,t3,x3,y3);
    k4_y=y_prima(n_points,rho,t3,x3,y3,z3);
    k4_z=z_prima(n_points,beta,t3,x3,y3,z3);

      /*fourth step*/
    average_kx = (1.0/6.0)*(k1_x + 2.0*k2_x + 2.0*k3_x + k4_x);
    average_ky = (1.0/6.0)*(k1_y + 2.0*k2_y + 2.0*k3_y + k4_y);
    average_kz = (1.0/6.0)*(k1_z + 2.0*k2_z + 2.0*k3_z + k4_z);
    
    t[i] = t[i-1] + h;
    x[i] = x[i-1] + h*average_kx;
    y[i] = y[i-1] + h*average_ky;
    z[i] = z[i-1] + h*average_kz;
       
    fprintf(fileout, "%f %f %f %f \n", t[i], x[i], y[i], z[i]);
  }
  fclose(fileout);
}  
  return 0;
}



