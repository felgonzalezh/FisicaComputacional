#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "tarea72.h"

int main(void){
  FILE *fileout;
  double h;
  int i;
  int n_points;
  h=0.01;
  n_points=(int)((1500.0+h)/h);
  
  /*   los valores de k=10 y C=28 son de prueba   */
  /*   aqui k=G*M C=4*pi*contante     */

  double *y_1;
  double *y_2;
  double *t;
  double *P;
  
  y_1 = malloc(n_points * sizeof(double));
  y_2 = malloc(n_points * sizeof(double));
  t = malloc(n_points * sizeof(double));
  P = malloc(n_points * sizeof(double));
  
  if(!y_1){
    printf("There is something wrong with array x\n");
    exit(1);
  }
  if(!y_2){
    printf("There is something wrong with array y\n");
    exit(1);
  }
  if(!t){
    printf("There is something wrong with array y\n");
    exit(1);
  }
  
  /*condiciones iniciales son de prueba*/
  t[0]=0;
  y_1[0]=1.7;
  y_2[0]=0;
  P[0]=5.6*pow(10,-11);
  
  double k, Cp, gamma, C, G, M, m;
  G=6.67*pow(10,-4);
  M=1.0;
  gamma=5.0/3.0;
  m=1.0*pow(10,-5);
  k=G*M;
  C=P[0]*4.0*3.1416*pow(y_1[0],3*gamma)/m;

  /*  printf("%f %f %f %f %f",G,M,k,y_1[0],C);
  /* Cp=P[0]*pow(((4.0*3.1416/3.0)*(pow(y_1[0],3))),gamma);*/
  
  /*  k=10.0;
      C=28.0;*/

  /*variables de la rutina de runge kuta a 4 orden*/
  double t1,t2,t3;
  double y1_1,y2_1,y3_1, k1_y1,k2_y1,k3_y1,k4_y1,average_ky1;
  double y1_2,y2_2,y3_2, k1_y2,k2_y2,k3_y2,k4_y2,average_ky2;

  fileout=fopen("tarea7.dat", "w");
  if(!fileout){
    printf("There is something wrong with file\n");
    exit(1);
  }

  for(i=1;i<n_points;i++){
    k1_y1=y1_prima(n_points, t[i-1],y_2[i-1]);
    k1_y2=y2_prima(n_points, k, C, t[i-1],y_1[i-1],y_2[i-1]);
    
    t[i]=t[i-1]+h;
    y_1[i]=y_1[i-1]+(h*k1_y1); 
    y_2[i]=y_2[i-1]+(h*k1_y2); 

    /*first step*/
    t1 = t[i-1] + (h/2.0);
    y1_1 = y_1[i-1] + (h/2.0)*k1_y1;
    y2_1 = y_2[i-1] + (h/2.0)*k1_y2;

    k2_y1=y1_prima(n_points, t1,y2_1);
    k2_y2=y2_prima(n_points, k, C, t1,y1_1,y2_1);

      /*second step*/
    t2 = t[i-1] + (h/2.0);
    y2_1 = y_1[i-1] + (h/2.0)*k2_y1;
    y2_2 = y_2[i-1] + (h/2.0)*k2_y2;

    k3_y1=y1_prima(n_points, t2,y2_2);
    k3_y2=y2_prima(n_points, k, C, t2,y2_1,y2_2);
       
      /*third step*/
    t3 = t[i-1] + h;
    y3_1 = y_1[i-1] + h*k3_y1;
    y3_2 = y_2[i-1] + h*k3_y2;
    
    k4_y1=y1_prima(n_points, t3,y3_2);
    k4_y2=y2_prima(n_points, k, C, t3,y3_1,y3_2);
    
    /*fourth step*/
    average_ky1 = (1.0/6.0)*(k1_y1 + 2.0*k2_y1 + 2.0*k3_y1 + k4_y1);
    average_ky2 = (1.0/6.0)*(k1_y2 + 2.0*k2_y2 + 2.0*k3_y2 + k4_y2);
    
    t[i] = t[i-1] + h;
    y_1[i] = y_1[i-1] + h*average_ky1;
    y_2[i] = y_2[i-1] + h*average_ky2;
    P[i]=P[0]*pow((y_1[0]/y_1[i]),5)*pow(10,11);
    
    fprintf(fileout, "%f  %f %f %f \n", t[i], y_1[i], y_2[i], P[i]);
  }
  fclose(fileout);
  
  return 0;
}

