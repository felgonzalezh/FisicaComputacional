#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>

float *load_data(char *filein, int *nf, int *nc){
  FILE *in;
  float *array;
  in = fopen(filein, "r");
  do{
    c = fgetc(in);
    if(c=='\n'){
      nf++;
    }
    if(!(data = malloc(sizeof(float)*nf *nc))){
      fprintf(stderr, "Problem with memory allocation");
      exit(1);
    }
    
  return 0;
}

int main (int arcg, char **argv){

  FILE *in;
  char *filein="movimiento.dat";
  float *data;
  int i, j, nf, nc;
  i, j=0;
  nf = 0;
  nc =2;
  char c;
  
  in = fopen(filein, "r");
  
  /*  do{
    c = fgetc(in);
    if(c=='\n'){
      nf++;
    }
  }while(c!=EOF);

  if(!(data = malloc(sizeof(float)*nf *nc))){
      fprintf(stderr, "Problem with memory allocation");
      exit(1);
      }*/

  data=load_data(filein, &nf,&nc);
  
  /*  for(i=0;i<nc;i++){
    for(j=0;j<nf;j++){
      data = j + (nc * i) ;
    }
    }*/

  printf("%d", nf);

  fclose(in);



  /* data=load_data(filein, &nf,&nc);

  /*  FILE *in;
  char filename argv[1];
  int i;
in = fopen(filename, "r");
  if(!in){
    printf("problems opening the file %s\n", filename);
    exit(1);
  }
  
  printf("Now I am reading\n");
  for(i=0;i<20;i++){
    fscanf(in, "%d\n", &var);
    printf("value = %d\n", var);
  }
  fclose(in);*/
  return 0;
}
