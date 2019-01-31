//Shriyash Shingare
//203707
#include<stdio.h>

void accept(char *str)
	{
		printf("Enter a string\n");
		scanf("%s",str); //to get the string
	}

void display(char *str)
	{
		printf("The string is: %s\n",str);
	}

int length(char *str)
	{
		int i=0;
		while(*str!='\0')
	{
		str++;
		i++;
	}
		return i;
}

void copy(char *str1, char *str2)
	{
		int len1=length(str1);
		int len2=length(str2);
		for(int i=0;i<len1;i++)
	{
		*(str2+i)=*(str1+i);

	}

	}

void compare(char *str1,char *str2)
	{
		int len1=length(str1);
		int len2=length(str2);
		int count=0;
	if(len1!=len2)
	{
		printf("The strings are not equal\n");
	}
	else
	{
		for(int i=0;i<len1;i++)
		{
			if(*(str1+i)==*(str2+i))
		{
			count++;
		}
    }
		if(count==len1)
		{
			printf("The strings are equal\n");
		}
		else
		{
			printf("The strings are not equal\n");
		}

  }
}

void reverse(char *str)
{
	char temp[10];
	int len=length(str);
	for(int i=0;i<len;i++)
	{
		temp[i]=*(str+len-1-i);
	}
	temp[len]='\0';
	printf("The string in reverse is: %s\n",temp);
}

void concatenate(char *str1,char *str2)
{
	int len1=length(str1);
	int len2=length(str2);
	for(int i=0;i<=len2;i++)
	{
		*(str1+len1+i)=*(str2+i);
	}
}

void palindrome(char *str)
{
	char temp[10];
	int count=0;
	int len = length(str);
	for(int i=0;i<len;i++)
	{
		temp[i]=*(str-1-i+len);
	}
	temp[len]='\0';

	for(int i=0;i<len;i++)
	{

		if(*(str+i)==temp[i])
		{
			count++;
		}
		else
		{
			count=count+0;
		}
	}
	if(count == len)
	{
		printf("The string entered is a palindrome\n");
	}
	else
	{
		printf("The entered string is not a palindrome\n");
	}
}

void sub_string(char *str1,char *str2)
{
    int len1 = length(str1);
    int len2 = length(str2);
    int total_occur=0,count=0;
    int i,j=0;
    for(int i=0;i<len2;i++)
    {
        for(;j<len1;j++)
        {
            if(*(str1+j)==*(str2+i))
            {
                count++;
                i++;
            }
            else
            {
            	count=0;
                i=0;
            }
            if(count==(len2))
            {
                total_occur++;
                count=0;
                i=0;
            }
        }

    }
    if(total_occur==0)
    {
        printf("Not a substring\n");
    }
    else
    {
        printf("It is a substring and no. of occurences: %d \n",total_occur);
    }

}
int main()
{
  int i,j;
  char s[10],g[10];
  do
  {
    printf("Make a choice: \n");
    printf("1.Accept 2.Display 3.Length 4.Copy 5.Concatenate 6.Compare 7.Reverse 8.Palindrome 9.Substring 10.Exit\n");
    scanf("%d",&i);
    switch(i)
    {
      case 1:
      accept(s);
      j=0;
      break;
      case 2:
      display(s);
      j=0;
      break;
      case 3:
      accept(s);
      printf("The length of the string is %d\n",length(s));
      j=0;
      break;
      case 4:
      accept(s);
      copy(s,g);
      printf("The copied string is: %s\n",g);
      j=0;
      break;
      case 5:
      accept(s);
      accept(g);
      concatenate(s,g);
      printf("The concatenated string is: %s\n",s);
      j=0;
      break;
      case 6:
      accept(s);
      accept(g);
      compare(s,g);
      j=0;
      break;
      case 7:
      accept(s);
      display(s);
      reverse(s);
      j=0;
      break;
      case 8:
      accept(s);
      palindrome(s);
      j=0;
      break;
      case 9:
      j=0;
      accept(s);
      accept(g);
      sub_string(s,g);
      break;
      case 10:
      printf("Program Exited!!\n");
      j=1;
      break;
      default:
      printf("Enter a valid choice.\n");
      j=0;
      break;
    }
  }while(j==0);

}
