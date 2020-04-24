// /**************************************************************
// *	threadHello.c - simple multi-threaded program.            *
// *   compile with: >gcc -lp threadHello.c -o threadHello       *                                              *
// **************************************************************/
// /*

// # Name: Andy
// # Date: 1/31/20
// # Title: Lab4 Part 3 – Matrix 
// # Description: multiplies 2 matrixes together using threads
// */

#include<stdio.h> 
#include<pthread.h> 
#include<unistd.h> 
#include<stdlib.h> 

// Each element is calculated by the adding the threads
void *multiply(void* arg) // calculate with threads going by row and column, calculating by each element
{ 
	int *data = (int *)arg; 
	int k = 0, i = 0; 
	
	int x = data[0]; 
	for (i = 1; i <= x; i++) 
		k += data[i]*data[i+x]; 
	
	int *p = (int*)malloc(sizeof(int)); 
	*p = k; 
	pthread_exit(p); // pointer is passed as a pointer
} 

int main() 
{ 
    int a, b, c, d;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);

	int matrixA[a][b]; 
	int matrixB[c][d]; 
	
	int r1=a,c1=b,r2=c,c2=d,i,j,k; 

    printf("\n");
    srand(time(NULL)); //storing row and column elements in data 
			
     for (i = 0; i < r1; i++) // creates matrix B with random values
		for (j = 0; j < c1; j++) 
			matrixA[i][j] = rand() % 10; 

	for (i = 0; i < r2; i++) // creates matrix B with random values
		for (j = 0; j < c2; j++) 
			matrixB[i][j] = rand() % 10; 

    // prints matrix a
	for (i = 0; i < r1; i++){ 
		for(j = 0; j < c1; j++) 
			printf("%d ",matrixA[i][j]); 
		printf("\n"); 
	} 

    printf("\n");

    // prints matrix b
	for (i = 0; i < r2; i++){ 
		for(j = 0; j < c2; j++) 
			printf("%d ",matrixB[i][j]); 
		printf("\n");	 
	} 
	
    printf("\n");

	int max = r1*c2; 
	
    // making a thread of array of size of the resulting matrix, r1 x c2
	pthread_t *threads; 
	threads = (pthread_t*)malloc(max*sizeof(pthread_t)); 
	
	int count = 0; 
	int* data = NULL; 
	for (i = 0; i < r1; i++) 
		for (j = 0; j < c2; j++) 
		{ 
			data = (int*)malloc(max*sizeof(int)); //storing row and column elements in data as a long integer, malloc memory which is in heap
			data[0] = c1; 
			for (k = 0; k < c1; k++) 
				data[k+1] = matrixA[i][k]; 
	
			for (k = 0; k < r2; k++) 
				data[k+c1+1] = matrixB[k][j]; 
			
			pthread_create(&threads[count++], NULL, multiply, (void*)data); 	
		} 
	
	printf("Calculated matrix: \n"); 
	for (i = 0; i < max; i++) 
	{ 
	    void *k; 	
	    pthread_join(threads[i], &k); 
		int *p = (int *)k; 
	    printf("%d ",*p); 
	    if ((i + 1) % c2 == 0) 
		    printf("\n"); 
	} 
return 0; 
} 