#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>
#include <stdlib.h>
#include <string.h>

/*declaracion de funciones*/
int n_lines(char *filein);
float *load_data(char *filein, int nf, int nc);
float *matrizG(float *m, int nf, int nc);
float *datosx(float *m, int nf, int nc);
float *multiplicacion(float *m, float *n, int nf, int nc, int nc1);
float *transpose(float *m, int nf, int nc);
float *Adjunta(float *m);
float Det(float *m);

/*funcion main*/
int main(int argc, char **argv){ 
  FILE *in;
 
  char *filein="movimiento.dat";
    int l;
    
  float *array;
  l=n_lines(filein);
  
  array=load_data(filein, l, 2);
  
  float *posicion;
  posicion=datosx(array,l,1);

  float *matrizg;
  matrizg=matrizG(array,l,3);

  float *Gtranspuesta;
  Gtranspuesta=transpose(matrizg, l, 3);

/*multiplicacion de matrices, se define una matriz M auxiliar*/
  float *M;
  int i; 
  i=0; 
  if(!(M = malloc(sizeof(float)*3 *3))){
    fprintf(stderr, "Problem with memory allocation");
    exit(1);
  }
  
  M=multiplicacion(Gtranspuesta,matrizg,l,3,3);
   for(i=0;i<9;i++){
   }

   float *Adj;
   if(!(Adj = malloc(sizeof(float)*3 *3))){
     fprintf(stderr, "Problem with memory allocation");
     exit(1);
   }
   Adj=Adjunta(M);
   float det;
   det=Det(M);
   
   float *I;
   float *Ii;
   if(!(I = malloc(sizeof(float)*3 *3))){
     fprintf(stderr, "Problem with memory allocation");
     exit(1);
   }
   Ii=(transpose(Adj, 3, 3));
   
   for(i=0;i<9;i++){
     I[i]=(Ii[i])/det;
    }

   /*Sean MN y MO dos matrices auxiliares para multiplicar dos matrices*/
   float *MN;
   float *MO;

   if(!(MO = malloc(sizeof(float)*3 *3))){
     fprintf(stderr, "Problem with memory allocation");
     exit(1);
 }

    MN=multiplicacion(Gtranspuesta,posicion,l,1,3);
       MO=multiplicacion(I,MN,3,1,3);
 
 if(!(in=fopen("parametros_movimiento.dat", "w"))){
    printf("problem opening file %s\n","parametros_movimiento.dat" );
    exit(1);
 }else{
      fprintf(in,"%f %f %f",MO[0],MO[1],MO[2]); 
   }
 fclose(in);
 return 0;
}

/*funciones*/
int n_lines(char *filein){
 FILE *in;
 char c;
 int l;
 l=0;
 in = fopen(filein, "r");
 do{
    c = fgetc(in);
    if(c=='\n'){
      l++;
    }
 }while(c!=EOF);
 return l;
}

float *load_data(char *filein, int nf, int nc){
  FILE *in;
  float *array;
  int i;
  i=0;
  if(!(array = malloc(sizeof(float)*nf *2))){
    fprintf(stderr, "Problem with memory allocation");
    exit(1);
  }
  in = fopen(filein, "r");
  for(i=0;i<nf;i++){
    fscanf(in, "%f %f\n", &(array[2*i]), &(array[2*i +1]));
  }
 fclose(in);  
  return array;
}

float *matrizG(float *m, int nf, int nc){
  int i;
  float *G;
  float t;
  i=0;t=0;
  if(!(G = malloc(sizeof(float)*nf *3))){
    fprintf(stderr, "Problem with memory allocation");
    exit(1);
  }
  for(i=0;i<nf;i++){
    t=m[i*2];
    G[3*i]=1.0;
    G[3*i+1]=t;
    G[3*i+2]=0.5*(t*t);
  }
  return G;
}

float *datosx(float *m, int nf, int nc){
  int i;
  float x;
  float *dx;
  i=0;x=0;
  if(!( dx= malloc(sizeof(float)*nf *3))){
    fprintf(stderr, "Problem with memory allocation");
    exit(1);
  }
  for(i=0;i<nf;i++){
    x=m[(i*2)+1];
    dx[i]=x;
  }
  return dx;
}

float *transpose(float *m, int nf, int nc){
  int i,j,pos_ij,pos_ji;
  float tmp;
  float *mt;
    if(!(mt = malloc(sizeof(float)*nf *nc))){
    fprintf(stderr, "Problem with memory allocation");
    exit(1);
    }

  for(i=0;i<nf;i++){
      for(j=0;j<nc;j++){
      pos_ij=j+(nc*i);
      pos_ji=i+(nf*j);
      tmp=m[pos_ij];     
      mt[pos_ji]=tmp;
    }
  }
  return mt;
}

float *multiplicacion(float *m, float *n, int nf, int nc, int nc1){
  int i,j,k, pos_ij,pos_ji;
  float a,b,c,d;
  float *H;
  if(!(H = malloc(sizeof(float)*nf *nc))){
    fprintf(stderr, "Problem with memory allocation");
    exit(1);
  }
   
  for(i=0;i<nc1;i++){
   
    for(k=0;k<nc;k++){
      d=0;
      for(j=0;j<nf;j++){
	pos_ij=j+(nf*i);
	pos_ji=(nc*j)+k;
	a=m[pos_ij];     
	b=n[pos_ji];
	c=a*b;
	d=d+c;
      }
    H[(nc*i)+k]=d;
    }
  }
   return H;
}

float *Adjunta(float *m){
  float *cf;

  if(!(cf = malloc(sizeof(float)*3 *3))){
    fprintf(stderr, "Problem with memory allocation");
    exit(1);
  }
  cf[0]= ((m[4]*m[8])-(m[5]*m[7]));
  cf[1]=-((m[3]*m[8])-(m[5]*m[6]));
  cf[2]= ((m[3]*m[7])-(m[4]*m[6]));
  cf[3]=-((m[1]*m[8])-(m[2]*m[7]));
  cf[4]= ((m[0]*m[8])-(m[2]*m[6]));
  cf[5]=-((m[0]*m[7])-(m[1]*m[6]));
  cf[6]= ((m[1]*m[5])-(m[2]*m[4]));
  cf[7]=-((m[0]*m[5])-(m[2]*m[3]));
  cf[8]= ((m[0]*m[4])-(m[1]*m[3]));
  
  return cf;
} 

float Det(float *m){
  float det;
  det=((m[0])*((m[4]*m[8])-(m[5]*m[7])))-((m[1])*((m[3]*m[8])-(m[5]*m[6])))+((m[2])*((m[3]*m[7])-(m[4]*m[6])));
  return det;
  }

