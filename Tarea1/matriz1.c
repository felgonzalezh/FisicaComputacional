#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>

/*declaracion de funciones*/
float *load_data(char *filein, int *nf, int *nc);
float *transpose(float *m, int nf, int nc);
float *multip(float *n, float *m);

/*funcion main*/
int main (int arcg, char **argv){
  
  FILE *in;
  char *filein="movimiento1.dat";
  float *matrizG;
  float *Gtranspuesta;
  int i, j;  
  i=0;j=0; 
  int nf, nc;
  /*  nf=0;
  nc =0;
  */
  in = fopen(filein, "r");
  
  matrizG=load_data(filein, &nf, &nc);

  /*  for(i=0;i<6;i++){
    printf("%f \n", matrizG[i]);
    }*/
  
  /* for(i=0;i<100;i++){
    printf("%f %f %f \n", (matrizG[3*i]),(matrizG[3*i+1]), (matrizG[3*i+2]));
    }*/

    Gtranspuesta=transpose(matrizG, 3, 3);

    for(i=0;i<6;i++){
    printf("trans %f \n", Gtranspuesta[i]);
    }
  return 0;
  }


/*funciones*/
float *load_data(char *filein, int *nf, int *nc){

  FILE *in;
  char c;
  float *array;
  float *G;
  float t, x;
  int l, i;
  i=0;
  l=0;
  in = fopen(filein, "r");
  do{
    c = fgetc(in);
    if(c=='\n'){
      l++;
     }
  }while(c!=EOF);
printf("%d \n", l);
   *nf =l;
   *nc =2;
  
  if(!(array = malloc(sizeof(float)*l *2))){
    fprintf(stderr, "Problem with memory allocation");
    exit(1);
  }

  if(!(G = malloc(sizeof(float)*l *3))){
    fprintf(stderr, "Problem with memory allocation");
    exit(1);
  }
  
  rewind(in);
 
  printf("Now I am reading\n");
    
  for(i=0;i<l;i++){
    fscanf(in, "%f %f\n", &(array[2*i]), &(array[2*i +1]));
    t=array[i*2];
    x=array[2*i +1];
    /*    printf("%f %f\n", t, x);*/
    G[3*i]=1.0;
    G[3*i+1]=t;
    G[3*i+2]=0.5*(t*t);
    /*  printf("%f %f %f \n", (G[3*i]),(G[3*i+1]), (G[3*i+2]));*/
  }
  
  fclose(in);  
  return G;
}

/*void *transpose(float *m, int nf, int nc){
  int i,j,pos_ij,pos_ji;
  float tmp;
  float *mt;
  for(i=0;i<nc;i++){
    for(j=i;j<nf;j++){
      pos_ij=i+(nf*j);
      pos_ji=j+(nc*i);
      tmp=m[pos_ij];
      m[pos_ij]=m[pos_ji];
      m[pos_ji]=tmp;
      printf("t %f \n", m[i]);

    }
  }
  return 0;
  }*/
    
float *transpose(float *m, int nf, int nc){
  int i,j,pos_ij,pos_ji;
  float tmp;
  float *mt;
  for(i=0;i<nf;i++){
    for(j=0;j<nc;j++){
      pos_ij=j+(nc*i);
      pos_ji=i+(nf*j);
      tmp=m[pos_ij];
      /*  m[pos_ij]=m[pos_ji];*/
      mt[pos_ji]=tmp;
      mt[pos_ij]=m[pos_ji];
      printf("t %f \n", mt[i]);
    }
  }
  return mt;
}

/*   pos_ji=i+(nf*j);
       mt[pos_ij]=tmp;
      tmp=m[pos_ji];
      /*   tmp=m[pos_ij];
      m[pos_ij]=m[pos_ji];
      mt[pos_ij]=tmp;
    }
    /*  printf("t %f \n", mt[i]);*/


/*oat *multip(float *n, float *m, int nf, int nc){
  int i,j,k;
  float c;
  float *C;

    
  return m;
  }*/

  /* fclose(in);
  printf("Now I am reading\n");
  for(i=0;i<nf;i++){
    fscanf(in, "%d \n", &nf);
    printf("value = %d\n", var);
  }
  fclose(in);*/

  /*  for(i=0;i<nc;i++){
    for(j=0;j<nf;j++){
      data = j + (nc * i) ;
    }
    }*/
