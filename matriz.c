#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>


float *load_data(char *filein, int *nf, int *nc);
int main (int arcg, char **argv){
  
  FILE *in;
  char *filein="movimiento.dat";
  float *data;
  int i, j;
  i=0;j=0;
 
  int nf, nc;
  nf=0;
  nc =0;

  in = fopen(filein, "r");
  
  data=load_data(filein, &nf, &nc);
  
  return 0;
}
float *load_data(char *filein, int *nf, int *nc){
  
  FILE *in;
  char c;
  float *array;
  int l, i;
  i=0;
  
  in = fopen(filein, "r");
  do{
    c = fgetc(in);
    if(c=='\n'){
      l++;
    }
  }while(c!=EOF);
  
  *nf =l;
  *nc =2;
  
  if(!(array = malloc(sizeof(float)*l *2))){
    fprintf(stderr, "Problem with memory allocation");
    exit(1);
  }
  
  rewind(in);
  
  printf("Now I am reading\n");
  /*  
       for(i=0;i<l;i++){
	 fscanf(in, "%d \n", nf);
	 printf("value = %d \n", nf);
	 }
	 fclose(in);*/
  
  return array;
}

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
