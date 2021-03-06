#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
  FILE *fileout;
  fileout=fopen("tarea8.dat","w");
  int i;
  int n_points;
  n_points=1000.0;
  double delta_x, delta_t;
  delta_x=(1.0-0.0)/n_points;
  delta_t=0.0005;
  double r;
  r=(1.0*delta_t)/(1.0*delta_x);
 

  double *u_inicial;
  u_inicial = malloc(n_points * sizeof(double));
  double *x;
  x = malloc(n_points * sizeof(double));
  double *u_new;
  u_new = malloc(n_points * sizeof(double));
  double *u_last;
  u_last = malloc(n_points * sizeof(double));
  double *u_now;
  u_now = malloc(n_points * sizeof(double));
  
  x[0]=0;
  
  u_inicial[0]=0;
  u_inicial[n_points-1]=0;
 
 for(i=0;i<n_points;i++){
   x[i]= x[i-1]+delta_x;
   u_inicial[i]=exp(-(( x[i]-0.3)*( x[i]-0.3))/0.01);
   }
  


 for(i=1;i<n_points;i++){
   u_new[i]= u_inicial[i]+(r*r/2.0)*(u_inicial[i+1]-2.0*u_inicial[i]+u_inicial[i-1]);
     u_last[i]= u_inicial[i];
     u_now[i]=u_new[i];
 }
  
 
  double time;
  time=900;
  int j;
  for(j=1;j<time;j++){
    for(i=1;i<n_points;i++){
         u_new[i] = (2.0*(1.0-r*r))*u_now[i]-u_last[i]+(r*r)*(u_now[i+1]+u_now[i-1]);
  }
  for(i=1;i<n_points;i++){
     u_last[i] = u_now[i];
     u_now[i] = u_new[i];
    }

   }
  
 
   for(i=1;i<n_points;i++){
     fprintf(fileout,"%f %f %f %f %f\n ",x[i], u_inicial[i], u_last[i],u_new[i],u_now[i] );
    }

  return 0;
}


