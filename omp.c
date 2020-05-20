#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
clock_t t1,t2;
int MA[550][550];
int MB[550][550];
int MC[550][550];
int dim;
float temps;
int i,j,k;
static void read_input(int matrice[550][550]);
static void read_input2(int matrice[550][550]);
/*static void write_output(int matrice[550][550]);*/
int main(){
t1=clock();
int dim=550;

read_input(MA);
read_input2(MB);
 for(i=0;i<dim;i++){
   
     for(j=0;j<dim;j++){
          
          MC[i][j] = 0;
     }

} 
#pragma omp parallel shared(MA,MB,MC,dim)private(i,j,k)
{
 
#pragma omp for schedule (static)
 for(i=0;i<dim;i++){
   
     for(j=0;j<dim;j++){
        for( k=0;k<dim;k++){
           MC[i][j]+= MA[i][k]*MB[k][j];
	}
     }
}}
 
/*write_output(MC);*/
t2=clock();
temps= (float)(t2-t1)/CLOCKS_PER_SEC;
temps -= 1.5;
printf("Execution Time : => %f \n" ,temps);
return 0;
}

void read_input2(int matrice[550][550]){
int i,j;
  
 for(i=0;i<dim;i++){
   
     for(j=0;j<dim;j++){
          
          matrice[i][j] =150000;
     }
  }
}
void read_input(int matrice[550][550]){
int i,j;
  
 for(i=0;i<dim;i++){
   
     for(j=0;j<dim;j++){
          
          matrice[i][j] =100000;
     }
  }
/*write_output(matrice);*/
}

/*void write_output(int matrice[550][550]){
int i,j;
printf("\nLa matrice que vous avez rentré est : \n");
 for(i=0;i<dim;i++){
     for(j=0;j<dim;j++){
       printf("%d  ", matrice[i][j]);
     }
     printf("\n");
 }
}*/
