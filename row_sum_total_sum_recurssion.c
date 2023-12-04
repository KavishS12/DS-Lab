//row sum and total sum of matrix using recursion(without pointers or global variable)

#include<stdio.h>

int arrSum(int n,int arr[10][10],int row,int i,int sum){
    sum = sum + arr[row-1][i-1];
    if(n>i){
        arrSum(n,arr,row,i+1,sum);
    }
    else return sum;
}

int totalSum(int m,int n,int arr[10][10],int row,int sum){
    sum = sum + arrSum(n,arr,row,1,0);
    if(m>row){
        totalSum(m,n,arr,row+1,sum);
    }
    else return sum;
}


int main()
{
    int m,n,i,j;
    int a[10][10];
    printf("enter the number of rows and columns of the matrix\n");
    scanf("%d%d",&m,&n);

    printf("enter the elements:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("Matrix is:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    int row;
    printf("Enter the row whose sum is to be found:");
    scanf("%d",&row);
    int row_sum = arrSum(n,a,row,1,0);
    printf("Row sum:%d\n",row_sum);

    int tot_sum = totalSum(m,n,a,1,0);
    printf("Total sum : %d",tot_sum);
}
