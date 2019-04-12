#include "sortAlgo.h"

sortAlgo::sortAlgo()
{
    //ctor
}

sortAlgo::~sortAlgo()
{
    //dtor
}

int sortAlgo::notsorted(){
	int q;
	for(q=0;q<MAX-1;q++)
	{
		if(a[q]>a[q+1])
			return 1;
	}
	return 0;
}

//Insertion Sort
void sortAlgo::insertionsort()
{
	int t;

	while(i<MAX)
	{
		if(flag==0){j=i; flag=1;}
		while(j<MAX-1)
		{
			if(a[j]>a[j+1])
			{
				swapflag=1;
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;

				goto A;
			}
			j++;
		}
		i++;
	}
	sorting=0;
	A:
	i=j=0;
}

//Selection Sort
void sortAlgo::selectionsort()
{
	int t,j,min,pos;

	while(notsorted())
	{
		while(i<MAX-1)
		{
			min=a[i+1];
			pos=i+1;
			if(i!=MAX-1)
			{
				for(j=i+2;j<MAX;j++)
				{
					if(min>a[j])
					{
						min=a[j];
						pos=j;
					}
				}
			}
			if(min<a[i])
			{

				t=a[pos];
				a[pos]=a[i];
				a[i]=t;
				goto A;
			}
			i++;
		}
	}
	sorting=0;
	i=j=0;
	A:;
}

//Bubble Sort
void sortAlgo::bubblesort()
{
	int t;
	while(notsorted())
	{
		while(j<MAX-1)
		{
			if(a[j]>a[j+1])
			{
				swapflag=1;
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				goto A;
			}
			j++;
			if(j==MAX-1) j=0;
		}
	}
	sorting=0;
	A: ;
}

//Ripple Sort
void sortAlgo::ripplesort()
{
	int t;
	while(notsorted() && sorting)
	{
		if(dirflag==0)
		{
			while(j<MAX-1)
			{
				if(a[j]>a[j+1])
				{
					swapflag=1;
					t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;

					goto A;
				}
				j++;
				if(j==MAX-1) {count++; j=MAX-count;	dirflag=1-dirflag;}
			}
		}
		else
		{
			while(j>=0)
			{
				if(a[j]>a[j+1])
				{
					swapflag=1;
					t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;

					goto A;
				}
				j--;
				if(j==0){ dirflag=1-dirflag;}
			}
		}
	}
	sorting=0;
	A: ;
}
