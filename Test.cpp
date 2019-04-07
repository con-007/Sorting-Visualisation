#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#define SORT_NO 4	// Number of sorting algorithms
#define MAX 80		// Array size
int a[MAX];
int swapflag=0;		// To check swapping
int i=0,j=0;
int flag=0;			// For Insertion Sort
int dirflag=0;		// For Ripple Sort, to change direction at the ends
int count=1;		// For Ripple Sort, to keep count of how many are sorted at the end
int k=0;
int sorting=0;		// 1 if Sorted
int sort_count=0;

using namespace std;

void bitmap_output(int x, int y, char *string, void *font)
{
	int len, i;

	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(font, string[i]);
	}
}

void display_text()
{
	glColor3f(0,0,0);
	bitmap_output(150, 665, "   SORTING ALGORITHMS VISUALISATION ",GLUT_BITMAP_TIMES_ROMAN_24);
	glBegin(GL_LINE_LOOP);
		glVertex2f(150, 650);
		glVertex2f(450, 650);
	glEnd();

	glColor3f(1,0.5,0.5);
		bitmap_output(10, 575, "Press Enter to start and press 'a' to change algorithm then 'i' to start and 'Esc' to end program after each sort.",GLUT_BITMAP_9_BY_15);
		bitmap_output(10, 555, "Sequence: Bubblesort, Selectionsort, Insertionsort, Ripplesort",GLUT_BITMAP_9_BY_15);
}

void Initialize() {
	int t;

	for(t=0;t<MAX;t++){
		a[t]=rand()%100+1;
		cout<<a[t]<<" ";
	}

	i=j=0;
	dirflag=0;
	count=1;
	flag=0;

	glClearColor(1,1,1,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 699,0,799);
}

int notsorted(){
	int q;
	for(q=0;q<MAX-1;q++)
	{
		if(a[q]>a[q+1])
			return 1;
	}
	return 0;
}

void display()
{
	int t;
	glClear(GL_COLOR_BUFFER_BIT);

        display_text();
		for(t=0;t<MAX;t++)
		{
			glColor3f(0,1,0);
			glBegin(GL_QUAD_STRIP);
				glVertex2f(10+(700/(MAX+1))*t,50);
				glVertex2f(10+(700/(MAX+1))*(t+1),50);
				glVertex2f(10+(700/(MAX+1))*(t+1),50+a[t]*4);
				glVertex2f(10+(700/(MAX+1))*t,50+a[t]*4);
			glEnd();
		}

		if(swapflag || sorting==0)
		{
			glColor3f(1,0,0);
			glBegin(GL_POLYGON);
				glVertex2f(10+(700/(MAX+1))*j,50);
				glVertex2f(10+(700/(MAX+1))*(j+1),50);
				glVertex2f(10+(700/(MAX+1))*(j+1),50+a[j]*4);
				glVertex2f(10+(700/(MAX+1))*j,50+a[j]*4);
			glEnd();
			swapflag=0;
		}
	glFlush();
}

// Insertion Sort
void insertionsort()
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

// Selection Sort
void selectionsort()
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
void bubblesort()
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
void ripplesort()
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


void makedelay(int)
{
	if(sorting)
	{
		switch(sort_count)
		{
			case 0:	bubblesort();		break;
			case 1:	selectionsort();	break;
			case 2: insertionsort();	break;
			case 3: ripplesort();		break;
		}
	}
	glutPostRedisplay();
	glutTimerFunc(0.000001,makedelay,1);
}

void keyboard (unsigned char key, int x, int y)
{
    if(key==13) k=1;
	if (k==1 && sorting!=1)
	{
		switch (key)
		{
			case 27	 :	exit (0);
			case 'i' :	Initialize(); break;
			case 'a' :	sort_count=(sort_count+1)%SORT_NO;	break;
		}
		sorting=1;
	}
}


int main(int argc, char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1200,600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Visual Representation of Sorting Algorithms");
    Initialize();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0.000005,makedelay,1);
    glutMainLoop();
}
