#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>

void chucnang2(int n,int **a)
{
	for(int d=0;d<n;d++)
		for(int c=0;c<n;c++)
		{
			printf("a[%d][%d]=",d,c);scanf("%d",&a[d][c]);
			while (a[d][c]<0||a[d][c]>n*n)
			{printf("Nhap lai a[%d][%d]=",d,c);scanf("%d",&a[d][c]);}
		}
}

void puzzle(int n,int **a)
{
	for(int i=0;i<2*n+1;i++)	printf("*");printf("\n");
	for(int d=0;d<n;d++)
	{
		for(int c=0;c<n;c++)
		{
			printf("*%d",a[d][c]);
		}	
		printf("*\n");
	}
	for(int i=0;i<2*n+1;i++)	printf("*");printf("\n");
}

void swap(int &a, int &b)
{
   int temp = a;
   a = b;
   b = temp;
}

void chucnang3(int n,int **a)
{
	char t;
	scanf("%s",&t);
	for(int d=0;d<n;d++)
		for(int c=0;c<n;c++)
		{
			if (a[d][c]==0)
			{
				if(t=='l') {swap(a[d][c],a[d][c-1]);break;}
				else if(t=='r') {swap(a[d][c],a[d][c+1]);break;}
			}
		}
	for(int c=0;c<n;c++)
		for(int d=0;d<n;d++)	
			if(a[d][c]==0)
			{
				if(t=='u') {swap(a[d][c],a[d-1][c]);break;}
				else if(t=='d') {swap(a[d][c],a[d+1][c]);break;}
			}
} 

int main()
{
	int n,i,j=0;
	char b[5040];
	char t;
	int **a=NULL;
	printf("1/Nhap so N\n2/Nhap chuc nang 2\n3/Nhap chuc nang 3\n4/Chuc naang 4\n5/In ra cau hinh game\n6/Exit\n");
	scanf("%d",&i);
	while (i!=1)
	{
		printf("Chua chon chuc nang 1\nKhong the thuc hien cac chuc nang khac\nChon lai: ");
		scanf("%d",&i);
	}
	if(i==1)
	{
		printf("nhap so N(3<=N<=7):");
		scanf("%d",&n);
		while(n>7||n<3)
		{
			printf("nhap lai so N(3<=N<=7):");
			scanf("%d",&n);
		}
		a = (int **)malloc(n * sizeof(int *));
		for (int i = 0; i < n; i++)
       		a[i] = (int *)malloc(n * sizeof(int));
	}
	while(1)
	{
		printf("1/Nhap so N\n2/Nhap cau hinh game\n3/Move\n4/move list\n5/In ra cau hinh game\n6/Exit\n");
		scanf("%d",&i);
		if(i==1)
		{
			printf("nhap so N(3<=N<=7):");
			scanf("%d",&n);
			while(n>7||n<3)
			{
				printf("nhap lai so N(3<=N<=7):");
				scanf("%d",&n);
			}
			a = (int **)malloc(n * sizeof(int *));
			for (int i = 0; i < n; i++)
        		a[i] = (int *)malloc(n * sizeof(int));
		}
		else if(i==2) chucnang2(n,a);
		else if(i==3) 
		{
			chucnang3(n,a);
			b[j]=t;j++;
		}	
		else if(i==4) //error
		{
			for(int v=0;v<=j;v++)
				printf("%s",b[v]);
		}
		else if(i==5) puzzle(n,a);
		else if(i==6) exit(0);
	}
	return 0;
}

