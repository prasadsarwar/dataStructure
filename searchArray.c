#include <stdio.h>

int main(){
	//array creation
	int size,i,key;
	printf("Enter size of array");
	scanf("%d",&size);
	
	int arr[size];
	printf("Enter array elements");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	
	// Display Array
	printf("Entered array elements are:");
	for(i=0;i<size;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
	int ch,flag=0;
	printf("Enter Searching Method\n");
	printf("1 ; Linear search\n2:Binary search");
	printf("\nEnter Choice\t");
	scanf("%d",&ch);
	
	printf("\nEnter search element\t");
	scanf("%d",&key);
	switch(ch){
		case 1:
			// Linear Search
			for(i=0;i<size;i++){
				if(arr[i] == key){
					printf("element %d found at position %d\n",key,i+1);
					flag=1;
				}
			}
			if(flag==0){
				printf("Element not found");
			}
			break;
	}
	return 0;
}
