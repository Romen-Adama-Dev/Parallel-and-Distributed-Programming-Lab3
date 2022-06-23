#include<stdio.h>
#include<omp.h>

//Define the loop size with variable
#define s 150000
omp_lock_t lock;

int main(){
 omp_set_num_threads(4);
 	int chunk_size = 3;
	int i;
	double a, t;

	printf("Parallel determinated with chunk size = 3 and Static mode \n");
	t = omp_get_wtime();

 #pragma omp parallel for schedule(static,chunk_size)
 for(int i=0;i<s;i++){
	 a*=0.5;
 }
 	printf("Time: %f \n",omp_get_wtime() - t);
	printf("Parallel determinated with chunk default size and Static mode \n");
	t = omp_get_wtime();

 #pragma omp parallel for schedule(static)
 for(i=0;i<s;i++){
	 a*=0.5;
 }
	printf("Time: %f \n",omp_get_wtime() - t);
	printf("Parallel determinated with chunk size = 3 and Dinamic mode \n");
	t = omp_get_wtime();

 #pragma omp parallel for schedule(dynamic,chunk_size)
 for(i=0;i<s;i++){
	 a*=0.5;
 }
 	printf("Time: %f \n",omp_get_wtime() - t);
	printf("Parallel determinated with chunk default size and Dinamic mode \n");
	t = omp_get_wtime();

 #pragma omp parallel for schedule(dynamic)
 for(i=0;i<s;i++){
	 a*=0.5;
 }
 printf("Time: %f \n",omp_get_wtime() - t);
}
//Romen A. Caetano Ramírez