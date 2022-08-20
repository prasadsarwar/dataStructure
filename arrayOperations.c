#include <stdio.h>

int main(){
	//array creation
	
	int size,i;

	printf("Enter size of Array");
	scanf("%d",&size);
	
	int arr[size];
	
	printf("Enter Array elements\n");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	
	//display before array
	printf("Array elements are:\n");
	for(i=0;i<size;i++){
		printf("%d\t",arr[i]);
	}
	
	//operations
	
	int ch;
	printf("\nChoose Operation:\n");
	printf("1: Insertion of new element\n");
	printf("2: Deletion of element\n");
	printf("3: Merge two arrays\n");
	
	scanf("%d",&ch);
	switch(ch){
		case 1:
			//insertion of elements	
			
			int elePos,eleVal;
			printf("Enter Position");
			scanf("%d",&elePos);
			printf("Enter Value");
			scanf("%d",&eleVal);
			
			elePos--;
			
			for(i=size;i>=elePos;i--){
				arr[i+1] = arr[i];			
			} 
			arr[elePos] = eleVal;
			
			for(i=0;i<=size;i++){
				printf("%d\t",arr[i]);
			}
			break;
			
		case 2:
			//Deletion of elements
			
			
			printf("Enter Position");
			scanf("%d",&elePos);
			
			elePos--;
			
			for(i=elePos;i<size-1;i++){
				arr[i] = arr[i+1];
			}			 
			
			for(i=0;i<size-1;i++){
				printf("%d\t",arr[i]);
			}
			printf("\n");
			break;
			
		case 3: 
			//Merging arrays
			
			int size2;
			printf("Enter size of second Array");
			scanf("%d",&size2);
	
			int arr2[size2];
	
			printf("Enter Array-2 elements\n");
			for(i=0;i<size2;i++){
				scanf("%d",&arr2[i]);
			}
			
			//actual merge
			
			int size3 = size + size2;
			int merge[size3];
			
			for(i=0;i<size;i++){
				merge[i] = arr[i];
				merge[i+size] = arr2[i];
			}
			
			for(i=0;i<size3;i++){
				printf("%d",merge[i]);
			}
			break;
			
		default: 
			printf("Enter valid choice");
			break;
	}
	
	
	return 0;
}










