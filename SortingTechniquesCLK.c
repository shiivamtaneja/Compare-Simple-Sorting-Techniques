// C program to compare simple sorting
// techniques using system clock.
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

// A function to implement Bubble Sort
void bubbleSort(int A[],int len)
{        
	int i,j;
    for(i=0;i<len;i++)
    {
        for(j=0;j<len-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                int t=A[j];
                A[j]=A[j+1];
                A[j+1]=t;
            }
        }
    }
}

// A function to implement Insertion Sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;  
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// A function to implement Selection Sort
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    
    for (i = 0; i < n-1; i++)
    {
        
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        
           if(min_idx != i){
                   int t=arr[min_idx];
                   arr[min_idx]=arr[i];
                   arr[i]=t;
           }
            
    }
}

// A function to implement insertion 
// in array.
void inserData(int A[],int len)
{
	int i;
    for(i=0;i<len;i++)
    {
        A[i]=rand()%1000;
    }
}

// Driver code
int main()
{
    int a[100010];
    int len=20000;
    int i;
    int itr=5;
    
	printf("This code is by Shivam Taneja.\n");
    
    printf("Bubble Sort:-\nSize \tTime\n");
    for(i=1;i<=itr;i++){
        
        clock_t startT=0,endT=0;        
                
        inserData(a,len);
        
        startT=clock();
        
        bubbleSort(a,len);
        
        endT=clock()-startT;
        
        double Time=((double)endT/CLK_TCK);
        
        printf("%d \t%f seconds\n",len, Time);
        
        len+=20000;     
    }
    
    len=20000;
    printf("\nInsertion Sort:-\n");
    for(i=1;i<=itr;i++){
        
        clock_t startT=0,endT=0;        
                
        inserData(a,len);
        
        startT=clock();
        
        insertionSort(a,len);
        
        endT=clock()-startT;
        
        double Time=((double)endT/CLK_TCK);
        
        printf("%d \t%f seconds\n",len, Time);
        
        len+=20000;
        
    }
    
    len=20000;
    printf("\nSelection Sort:-\n");
    for(i=1;i<=itr;i++){
        
        clock_t startT=0,endT=0;        
                
        inserData(a,len);
        
        startT=clock();
        
        selectionSort(a,len);
        
        endT=clock()-startT;
        
        double Time=((double)endT/CLK_TCK);
        
        printf("%d \t%f seconds\n",len, Time);
        
        len+=20000;//        
    }
    return 0;    
}
