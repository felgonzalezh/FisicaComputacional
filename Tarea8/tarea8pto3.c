#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
  FILE *fileout;
 
  int i;
  int n_points;
  n_points=100.0;
  double delta_x, delta_t;
  delta_x=(5.0-(-5.0))/n_points;
  delta_t=0.00003;

  double alpha;
  alpha=(delta_t)/((delta_x)*(delta_x));

  double *u_inicial;
  u_inicial = malloc(n_points * sizeof(double));
  double *x;
  x = malloc(n_points * sizeof(double));
  double *u_new;
  u_new = malloc(n_points * sizeof(double));
  double *u_now;
  u_now = malloc(n_points * sizeof(double));
  
  x[0]=-5;
  
  u_inicial[0]=0;
  u_inicial[n_points-1]=0;
 
 for(i=1;i<n_points;i++){
   x[i]= x[i-1]+delta_x;
   u_inicial[i]=exp(-x[i]*x[i]);
   }
  

 for(i=1;i<n_points;i++){
   u_new[i]= (alpha*u_inicial[i+1])+((1-2*alpha)*u_inicial[i])+(alpha*u_inicial[i-1]);
   u_now[i]=u_new[i];
 }
  
 
  double time;
  time=1000;
  int j;
/*tiempo de 0 a 0.03*/
  for(j=1;j<time;j++){
    for(i=1;i<n_points;i++){
         u_new[i] = alpha*u_now[i+1]+((1-2*alpha)*u_now[i])+(alpha*u_now[i-1]);
    }
    for(i=1;i<n_points;i++){
      u_now[i] = u_new[i];
    }
    
  }
fileout=fopen("tarea81.dat","w");  
for(i=1;i<n_points;i++){
   fprintf(fileout,"%f %f %f \n ",x[i], u_inicial[i], u_now[i] );

  }
   
  /*tiempo de 0 a 0.06*/
  for(j=1000;j<(2*time);j++){
    for(i=1;i<n_points;i++){
         u_new[i] = alpha*u_now[i+1]+((1-2*alpha)*u_now[i])+(alpha*u_now[i-1]);
    }
    for(i=1;i<n_points;i++){
      u_now[i] = u_new[i];
    }
    
  }
fileout=fopen("tarea82.dat","w");  
for(i=1;i<n_points;i++){
   fprintf(fileout,"%f %f %f \n ",x[i], u_inicial[i], u_now[i] );
  }
 /*tiempo de 0 a 0.09*/
  for(j=2000;j<(3*time);j++){
    for(i=1;i<n_points;i++){
         u_new[i] = alpha*u_now[i+1]+((1-2*alpha)*u_now[i])+(alpha*u_now[i-1]);
    }
    for(i=1;i<n_points;i++){
      u_now[i] = u_new[i];
    }
    
  }
fileout=fopen("tarea83.dat","w");  
for(i=1;i<n_points;i++){
   fprintf(fileout,"%f %f %f \n ",x[i], u_inicial[i], u_now[i] );
  }
/*tiempo de 0 a 0.12*/
  for(j=3000;j<(4*time);j++){
    for(i=1;i<n_points;i++){
         u_new[i] = alpha*u_now[i+1]+((1-2*alpha)*u_now[i])+(alpha*u_now[i-1]);
    }
    for(i=1;i<n_points;i++){
      u_now[i] = u_new[i];
    }
    
  }
fileout=fopen("tarea84.dat","w");  
for(i=1;i<n_points;i++){
   fprintf(fileout,"%f %f %f \n ",x[i], u_inicial[i], u_now[i] );
  }


/*tiempo de 0 a 0.15*/
  for(j=4000;j<(5*time);j++){
    for(i=1;i<n_points;i++){
         u_new[i] = alpha*u_now[i+1]+((1-2*alpha)*u_now[i])+(alpha*u_now[i-1]);
    }
    for(i=1;i<n_points;i++){
      u_now[i] = u_new[i];
    }
    
  }
fileout=fopen("tarea85.dat","w");  
for(i=1;i<n_points;i++){
   fprintf(fileout,"%f %f %f \n ",x[i], u_inicial[i], u_now[i] );
  }


/*tiempo de 0 a 0.18*/
  for(j=5000;j<(6*time);j++){
    for(i=1;i<n_points;i++){
         u_new[i] = alpha*u_now[i+1]+((1-2*alpha)*u_now[i])+(alpha*u_now[i-1]);
    }
    for(i=1;i<n_points;i++){
      u_now[i] = u_new[i];
    }
    
  }
fileout=fopen("tarea86.dat","w");  
for(i=1;i<n_points;i++){
   fprintf(fileout,"%f %f %f \n ",x[i], u_inicial[i], u_now[i] );
  }

/*tiempo de 0 a 0.21*/
  for(j=6000;j<(7*time);j++){
    for(i=1;i<n_points;i++){
         u_new[i] = alpha*u_now[i+1]+((1-2*alpha)*u_now[i])+(alpha*u_now[i-1]);
    }
    for(i=1;i<n_points;i++){
      u_now[i] = u_new[i];
    }
    
  }
fileout=fopen("tarea87.dat","w");  
for(i=1;i<n_points;i++){
   fprintf(fileout,"%f %f %f \n ",x[i], u_inicial[i], u_now[i] );
  }

/*tiempo de 0 a 0.24*/
  for(j=7000;j<(8*time);j++){
    for(i=1;i<n_points;i++){
         u_new[i] = alpha*u_now[i+1]+((1-2*alpha)*u_now[i])+(alpha*u_now[i-1]);
    }
    for(i=1;i<n_points;i++){
      u_now[i] = u_new[i];
    }
    
  }
fileout=fopen("tarea88.dat","w");  
for(i=1;i<n_points;i++){
   fprintf(fileout,"%f %f %f \n ",x[i], u_inicial[i], u_now[i] );
  }

/*tiempo de 0 a 0.27*/
  for(j=8000;j<(9*time);j++){
    for(i=1;i<n_points;i++){
         u_new[i] = alpha*u_now[i+1]+((1-2*alpha)*u_now[i])+(alpha*u_now[i-1]);
    }
    for(i=1;i<n_points;i++){
      u_now[i] = u_new[i];
    }
    
  }
fileout=fopen("tarea89.dat","w");  
for(i=1;i<n_points;i++){
   fprintf(fileout,"%f %f %f \n ",x[i], u_inicial[i], u_now[i] );
  }

/*tiempo de 0 a 0.30*/
  for(j=9000;j<(10*time);j++){
    for(i=1;i<n_points;i++){
         u_new[i] = alpha*u_now[i+1]+((1-2*alpha)*u_now[i])+(alpha*u_now[i-1]);
    }
    for(i=1;i<n_points;i++){
      u_now[i] = u_new[i];
    }
    
  }
fileout=fopen("tarea810.dat","w");  
for(i=1;i<n_points;i++){
   fprintf(fileout,"%f %f %f \n ",x[i], u_inicial[i], u_now[i] );
  }


  return 0;
}

