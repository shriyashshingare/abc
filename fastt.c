#include<stdio.h>

int Compact(int m, int n, int arr[50][50],int brr[m*n][3])
{
    brr[0][0]=m;
    brr[0][1]=n;
    int k=1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {

    if(arr[i][j]!=0)
            {
                brr[k][0]=i;
                brr[k][1]=j;
                brr[k][2]=arr[i][j];
                k++;

            }

        }
    }
    brr[0][2]=k-1;

    return k;
}

void Display(int rows,int brr[rows][3])
{

    for(int i=0;i<rows;i++)
    {
        printf("\n");
        for(int j=0;j<3;j++)
        {
            printf(" %d   ",brr[i][j]);
        }
        printf("\n");
    }
}

void SimpleTranspose(int brr[20][3],int brrt[20][3])
{
     int i,j,k,n;
     brrt[0][0]=brr[0][0];
     brrt[0][1]=brr[0][0];
     brrt[0][2]=brr[0][2];


     k=1;
     n=brr[0][2];

     for(i=0;i<brr[0][1];i++)
         for(j=1;j<=n;j++)
             //if a column number of current triple==i then insert the current triple in b2
             if(i==brr[j][1])
             {
                 brrt[k][0]=i;
                 brrt[k][1]=brr[j][0];
                 brrt[k][2]=brr[j][2];
                 k++;
             }

}


void fastTransepose(int B[20][3],int C[20][3])
{
     int i,j,m,n,pos[3]={0,0,0},count[3]={0,0,0};
     for (i=1;i<=B[0][2];i++)
    {
 m = B[i][1];
 count[m]++;
    }
    pos[0] = 1;
    for (i=1;i<B[0][1];i++)
    {
 pos[i] = pos [i-1] + count[i-1];
    }
    for (i=1;i<=B[0][2];i++)
    {
 m = B[i][1];
 n= pos[m];
 pos[m]++;
 C[n][0] = B[i][1];
 C[n][1] = B[i][0];
 C[n][2] = B[i][2];
    }
    C[0][0] = B[0][0];
    C[0][1] = B[0][1];
    C[0][2] = B[0][2];
}
