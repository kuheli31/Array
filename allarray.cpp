#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Display(struct Array arr)//CASE 1
{
    int i;
    for(i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}

void Insert(struct Array *arr,int x,int index)//CASE 2
{
    int i;
    if(index>=0 && index<=arr->length)
    {
    for(i=arr->length ; i>index ; i--)
    {
        arr->A[i]=arr->A[i-1];
    }
    arr->A[index]=x;
    arr->length++;
    }
}

void Delete(struct Array *arr,int index)//CASE 3
{
    int i;
    if(index>=0 && index<arr->length)
    {
        for(i=index ; i<arr->length-1 ;i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
    }
    else 
    {
        printf("Invalid index.");
    }
}

int Linear1(struct Array *arr,int x)//CASE 4
{
    int i;
    for(i=0 ; i<arr->length ;i++)
    {
        if(x == arr->A[i])
        {
            printf("Found at index=%d",i);
            return i;
        }
    }
    printf("Not Found.");
    return -1;
    
}

int Linear2(struct Array *arr,int x)//CASE 5
{
    int i;
    for(i=0 ; i<arr->length ;i++)
    {
        if(x == arr->A[i])
        {
            swap(&arr->A[i],&arr->A[0]);
            printf("Found at index=%d",i);
            return 0;
        }
    }
    printf("Not Found.");
    return -1;
}

int Binary(struct Array *arr, int start ,int end,int x)//CASE 6
{
    int mid;
    while (start<=end)
    {
        mid=(start+end)/2;
        if (x == arr->A[mid])
        {
            printf("Found at index=%d",mid);
            return mid;
        }
        else if (x < arr->A[mid])
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    printf("Not Found.");
    return -1;
}

int rBinary(struct Array *arr, int start ,int end,int x)//CASE 7
{
    int mid;
    if(start<=end)
    {
        mid=(start+end)/2;
        if (x == arr->A[mid])
        {
            return mid;
        }
        else if (x < arr->A[mid])
        {
            return rBinary(arr, start, mid - 1, x);
        }
        else
        {
            return rBinary(arr, mid + 1, end, x);
        }
    }
    return -1;
}

void Get(struct Array *arr,int index)//CASE 8
{
    if(index>=0 && index<arr->length)
    {
        printf("The element in that index is=%d",arr->A[index]);
    }
    else 
    {
        printf("Invalid index.");
    }
}

void Set(struct Array *arr,int x,int index)//CASE 9
{
    if(index>=0 && index<arr->length)
    {
        arr->A[index]=x;
    }
    else 
    {
        printf("Invalid index.");
    }
}

void Max(struct Array *arr)//CASE 10
{
	int i;
	int max=arr->A[0];
	for(i=0;i<arr->length;i++)
	{
		if(arr->A[i]>max)
		{
			max=arr->A[i];
		}
	}
	printf("Maximum number is=%d",max);
}

void Min(struct Array *arr)//CASE 11
{
	int i;
	int min=arr->A[0];
	for(i=0;i<arr->length;i++)
	{
		if(arr->A[i]<min)
		{
			min=arr->A[i];
		}
	}
	printf("Minimum number is=%d",min);
}

void Sum(struct Array *arr)//CASE 12
{
	int i,sum=0;
	for(i=0;i<arr->length;i++)
	{
		sum=sum+arr->A[i];
	}
	printf("Sum is=%d",sum);
}

int rSum(struct Array *arr,int n)//CASE 13
{
	if(n<0)
	{
		return 0;
	}
	else
	{
		return rSum(arr,n-1) + arr->A[n];
	}
}

void Avg(struct Array *arr)//CASE 14
{
	int i,sum=0;
	double avg;
	for(i=0;i<arr->length;i++)
	{
		sum=sum+arr->A[i];
	}
	printf("Average is=%d",sum/arr->length);
}

void Reverse1(struct Array *arr)//CASE 15
{
	int i,j;
	int *B = (int *)malloc(arr->length * sizeof(int));
	for(i=arr->length-1,j=0 ; i>=0 ; i--,j++)
	{
		B[j]=arr->A[i];
	}
	for(i=0;i<arr->length;i++)
	{
		arr->A[i]=B[i];
	}
}

void Reverse2(struct Array *arr)//CASE 16
{
	int i,j;
	for(j=arr->length-1,i=0 ; i<j ; j--,i++)
	{
		int temp=arr->A[i];
		arr->A[i]=arr->A[j];
		arr->A[j]=temp;
	}
}

int InsertSorted(struct Array *arr,int x)//CASE 17
{
	int i;
	i=arr->length-1;
	while(arr->A[i]>x)
	{
		arr->A[i+1]=arr->A[i];
		i--;
	}
	arr->A[i+1]=x;
	arr->length++;
}

void CheckSortedOrNot(struct Array *arr)//CASE 18
{
	int i;
	for(i=0 ; i<arr->length-1 ; i++)
	{
		if(arr->A[i]>arr->A[i+1])
		{
			printf("Not Sorted.");
		}
		else
		{
			printf("Sorted.");
		}
	}
}

void LeftNegative(struct Array *arr)//CASE 19
{
	int i=0;
	int j=arr->length-1;
	while(i<j)
	{
		while(arr->A[i]<0)
		{
            i++;
        }
		while(arr->A[j]>=0)
		{
			j--;
		}
		if(i<j)
		{
			swap(&arr->A[i] , &arr->A[j]);
			i++;
        	j--;
		}
	}
}

void Merge(int A[],int B[],int C[],int m,int n)//CASE 20
{
    int i=0,j=0,k=0;
    while(i<m && j<n) 
	{
        if(A[i]<B[j]) 
		{
            C[k++]=A[i++];
        }
		else 
		{
            C[k++]=B[j++];
        }
    }
    while(i<m) 
	{
        C[k++]=A[i++];
    }
    while(j<n) 
	{
        C[k++]=B[j++];
    }
}

struct Array* Union(struct Array *arr1,struct Array *arr2)//CASE 21
 {
    int i,j,k;
    i=j=k=0;
    
struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            arr3->A[k++]=arr2->A[j++];
        else
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for(i=0;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(j=0;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];
    
    arr3->length=k;
    arr3->size=10;
    
    return arr3;
}

struct Array* Intersection(struct Array *arr1,struct Array *arr2)//CASE 22
 {
    int i,j,k;
    i=j=k=0;
    
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else if(arr1->A[i]==arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    
    arr3->length=k;
    arr3->size=10;
    
    return arr3;
 }
 
struct Array* Difference(struct Array *arr1,struct Array *arr2)//CASE 23
{
	int i,j,k;
    i=j=k=0;
    
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
for(i=0;i<arr1->length;i++)
    arr3->A[k++]=arr1->A[i];
    arr3->length=k;
    arr3->size=10;
    return arr3;
}

int main()
{
	char ch1;
	
	do
	{
    struct Array arr1,arr2,arr3;
    int ch,i;

    printf("Enter size of an first array=");
    scanf("%d",&arr1.size);
    
    arr1.A=(int *)malloc(arr1.size*sizeof(int)); 

    printf("Enter length of an first array=");
    scanf("%d",&arr1.length);

    printf("\nEnter elements for first array:\n");
    for(i=0;i<arr1.length;i++)
    {
        scanf("%d",&arr1.A[i]);
    }
    
    printf("1.To display all elements of array.\n");
    printf("2.To insert an element.\n");
    printf("3.To delete an element.\n");
    printf("4.To do Linear Search of an element.\n");
    printf("5.To do Linear Search using transposition method.\n");
    printf("6.To do Binary Search using loop.\n");
    printf("7.To do Binary Search using recursion.\n");
    printf("8.Using get(index) operator.\n");
    printf("9.Using set(index) operator.\n");
    printf("10.Using Max() operator.\n");
    printf("11.Using Min() operator.\n");
    printf("12.Using Sum() operator.\n");
    printf("13.Using Sum() operator by recursion.\n");
    printf("14.Using Avg() operator.\n");
    printf("15.Reverse an array by method 1.\n");
    printf("16.Reverse an array by method 2.\n");
    printf("17.To insert new element in a sorted array.\n");
    printf("18.To check if a list is already sorted or not.\n");
    printf("19.To sort negative numbers on left side.\n");
    printf("20.To merge two arrays.\n");
    printf("21.To do union set operations on array.\n");
    printf("22.To do intersection set operations on array.\n");
    printf("23.To do difference set operations on array.\n");

    printf("\nEnter your choice:");
    scanf("%d",&ch);

    int x,index,start,end,result;

    switch(ch)
    {
        case 1:
        printf("Elements are:");
        Display(arr1);
        break;

        case 2:
        printf("Enter an element to insert:");
        scanf("%d",&x);
        printf("Enter index where element will be inserted:");
        scanf("%d",&index);
        Insert(&arr1,x,index);
        printf("Updated array: ");
        Display(arr1);
        break;

        case 3:
        printf("Enter the index where element will be deleted:");
        scanf("%d",&index);
        Delete(&arr1,index);
        printf("Updated array: ");
        Display(arr1);
        break;

        case 4:
        printf("Enter an element to search:");
        scanf("%d",&x);
        Linear1(&arr1,x);
        break;

        case 5:
        printf("Enter an element to search:");
        scanf("%d",&x);
        Linear2(&arr1,x);
        break;

        case 6:
        printf("Enter an element to search:");
        scanf("%d",&x);
        start = 0;
        end = arr1.length - 1;
        Binary(&arr1,start,end,x);
        break;

        case 7:
        printf("Enter an element to search:");
        scanf("%d",&x);
        start = 0;
        end = arr1.length - 1;
        result = rBinary(&arr1, start, end, x);
        if(result != -1)
            printf("Found at index=%d\n", result);
        else
            printf("Not Found.\n");
        break;

        case 8:
        printf("Enter the index of the element:");
        scanf("%d",&index);
        Get(&arr1,index);
        break;

        case 9:
        printf("Enter the index where element will be set:");                                                                                                                              
        scanf("%d",&index);
        printf("Enter the element to set:");
        scanf("%d",&x);
        Set(&arr1,x,index);
        printf("Updated array: ");
        Display(arr1);
        break;

		case 10:
		Max(&arr1);
		break;
		
		case 11:
		Min(&arr1);
		break;
		
		case 12:
		Sum(&arr1);
		break;
		
		case 13:
		printf("Sum of array elements using recursion is=%d\n", rSum(&arr1, arr1.length - 1));
		break;	
		
		case 14:
		Avg(&arr1);
		break;
		
		case 15:
		Reverse1(&arr1);
		printf("After Reversing:");
		Display(arr1);
		break;
		
		case 16:
		Reverse2(&arr1);
		printf("After Reversing:");
		Display(arr1);
		break;
		
		case 17:
		printf("Enter an element to be inserted in a sorted array=");
		scanf("%d",&x);
		InsertSorted(&arr1,x);
		printf("Updated array: ");
        Display(arr1);
        break;
        
        case 18:
        CheckSortedOrNot(&arr1);
        break;
        
        case 19:
        LeftNegative(&arr1);
        printf("Updated array: ");
        Display(arr1);
        
        case 20:
        Merge(arr1.A, arr2.A, arr3.A, arr1.length, arr2.length);
        printf("Merged Array: ");
        for(i=0; i< arr1.length + arr2.length; i++) 
		{
            printf("%d ", arr3.A[i]);
        }
        printf("\n");
        break;
        
        case 21:
        printf("Enter size of second array=");
    	scanf("%d", &arr2.size);
		arr2.A=(int *)malloc(arr2.size*sizeof(int));
		printf("Enter length of second array=");
    	scanf("%d", &arr2.length);
    	printf("\nEnter elements for the second array:\n");
    	for(i=0;i<arr2.length;i++) 
		{
        	scanf("%d",&arr2.A[i]);
    	}
    	struct Array *arr3; 
		arr3=Union(&arr1,&arr2);
		printf("After Union="); 
		Display(*arr3);
		break;
		
		case 22:
		printf("Enter size of second array=");
    	scanf("%d", &arr2.size);
		arr2.A=(int *)malloc(arr2.size*sizeof(int));
		printf("Enter length of second array=");
    	scanf("%d", &arr2.length);
    	printf("\nEnter elements for the second array:\n");
    	for(i=0;i<arr2.length;i++) 
		{
        	scanf("%d",&arr2.A[i]);
    	}
		arr3=Intersection(&arr1,&arr2); 
		printf("After Intersection=");
		Display(*arr3);
		break;
		
		case 23:
		printf("Enter size of second array=");
    	scanf("%d", &arr2.size);
		arr2.A=(int *)malloc(arr2.size*sizeof(int));
		printf("Enter length of second array=");
    	scanf("%d", &arr2.length);
    	printf("\nEnter elements for the second array:\n");
    	for(i=0;i<arr2.length;i++) 
		{
        	scanf("%d",&arr2.A[i]);
    	}
		arr3=Difference(&arr1,&arr2); 
		printf("After Difference=");
		Display(*arr3);
		break;
		
		default:
		printf("Invalid choice.");
		break;
		
	    }
    printf("\nTo continue press 'Y' or 'y' for yes=");
    getchar(); 
    ch1=getchar();
    } while (ch1 == 'Y' || ch1 == 'y');
    
    return 0;
}