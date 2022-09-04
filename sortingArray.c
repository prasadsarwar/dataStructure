#include <stdio.h>

int main(){
	//array creation
	
	int size,i,j;

	printf("Enter size of Array");
	scanf("%d",&size);
	
	int arr[size];
	
	printf("Enter Array elements\n");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	
	//display unsorted array
	printf("Array elements are:\n");
	for(i=0;i<size;i++){
		printf("%d\t",arr[i]);
	}
	
	//sorting operations
	
	int ch;
	printf("\nChoose Operation:\n");
	printf("1: Bubble Sort\n");
	printf("2: Selection Sort\n");
	printf("3: insertion Sort\n");
	
	
	scanf("%d",&ch);
	switch(ch){
		case 1:{
			//bubble sort
			
			int counter = 1;
			while(counter<size){
				for(i=0;i<size-counter;i++){
					if(arr[i]>arr[i+1]){
						int temp = arr[i];
						arr[i] = arr[i+1];
						arr[i+1] = temp;
					}
				}
				
				
				//display iterations
				
				printf("Iteration %d =>",counter);
				for(int j=0;j<size;j++){
					
					printf("\t%d",arr[j]);	
				}
				printf("\n");
				counter++;

			}
		}
			break;
			
		case 2: { 
	
			// selection sort
			
			for(i=0;i<size-1;i++){
				for(j=i+1;j<size;j++){
					if(arr[j]<arr[i]){
						int temp = arr[j];
						arr[j] = arr[i];
						arr[i] = temp;
					}
				}	
				
				//display iterations
				
				printf("Iteration %d =>",i+1);
				for(int j=0;j<size;j++){
					
					printf("\t%d",arr[j]);	
				}
				printf("\n");
			}
		}
			break;
		
		case 3:{
			// Insertion sort
			
			for(i=1;i<size;i++){
				int current = arr[i];
				j = i-1;
				while(arr[j]>current && j>=0){
					arr[j+1] = arr[j];
					j--;
				}
				arr[j+1] = current;
				
				//display iterations
				
				printf("Iteration %d =>",i);
				for(int j=0;j<size;j++){
					
					printf("\t%d",arr[j]);	
				}
				printf("\n");
			}
		}
			break;
			
		default:{
			printf("Enter Valid Choice\n");
		}
		
	}
	return 0;
}























