#include<stdio.h>
typedef struct Student
{
    int RollNo;
    char Name[20],Division;
    float Percentage;

}Student;


void Accept(int n,Student s1[20])
{
    for(int i=0;i<n;i++)
    {
    printf("Student %d",i+1);
    printf("\nEnter a Name of student\n");
    scanf("%s",s1[i].Name);
    printf("Enter a Roll Number of student \n");
    scanf("%d",&s1[i].RollNo);
    printf("Enter a Division of Student \n");
    scanf(" %c",&s1[i].Division);
    printf("Enter a percentage of student\n");
    scanf("%f",&s1[i].Percentage);
    }
}

void Display(int n,Student s1[20])
{
    printf("\n Name \t Roll Number \t Division \t Percentage \t");
    for(int i=0;i<n;i++)
    {
    printf("\n %s \t %d             \t %c \t          %f \t ",s1[i].Name,s1[i].RollNo,s1[i].Division,s1[i].Percentage);
    }
}



int LinearSearch(int n,Student s1[20],int limit)
{

    int flag=-1;


    for(int i=0;i<n;i++)
    {

        if(limit==s1[i].RollNo)
        {

            flag=i;
            return flag;
        }
    }
    if(flag==-1)
    {
        return -1;
    }
}

int BinarySearch(int n,Student s1[20],int limit)
{
    int low = n-n;
    int high = n-1;
    int mid;
    while(low<=high)
    {
        mid=(high-low)/2;

        if(limit==s1[mid].RollNo)
        {
            return mid;
        }
        else if(limit<s1[mid].RollNo)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }

    return -1;
}


void BubbleSort(int n,Student s1[20])
{
    Student temp;
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(s1[j].RollNo>s1[j+1].RollNo)
            {
                temp=s1[j];
                s1[j]=s1[j+1];
                s1[j+1]=temp;
            }

        }
	printf("\nPASS NO %d\n",i+1);
	//printf("Bubbled out element is %d",s1[j].RollNo);
	Display(n,s1);

    }
}

void SelectionSort(int n,Student s1[20])
{
    int min;
    Student temp;
    for(int i=0;i<n;i++)
    {
	min=i;
        for(int j=i+1;j<n;j++)
        {
            if(s1[j].RollNo<s1[i].RollNo)
            {
                min=j;
            }


        }
	if(min!=i)
	{
		temp=s1[i];
		s1[i]=s1[min];
		s1[min]=temp;
	}
        printf("\nPASS NO %d\n",i+1);
	//printf("\nMinimum element is %d\n",s1[i].RollNo);
	Display(n,s1);
    }
}

void InsertionSort(int n,Student s1[20])
{
	int d;
	Student temp;
	for(int i=0;i<=n-1;i++)
	{

		d=i;
		while(d>0 && s1[d-1].RollNo>s1[d].RollNo)
		{
			temp=s1[d];
			s1[d]=s1[d-1];
			s1[d-1]=temp;
		}

	printf("\nPASS NO %d\n",i+1);
	//printf("%d elements are sorted \n",i+1);
	Display(n,s1);
	}
}
