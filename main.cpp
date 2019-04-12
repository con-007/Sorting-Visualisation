#include <windows.h>
#include <GL/glut.h>
#include <Ini.h>
#include <sortAlgo.h>
#include <displayScreen.h>
#define SORT_NO 4	// Number of sorting algorithms

int a[MAX];
int swapflag=0;		// To check swapping
int i=0,j=0;
int flag=0;			// For Insertion Sort
int dirflag=0;		// For Ripple Sort, to change direction at the ends
int count=1;		// For Ripple Sort, to keep count of how many are sorted at the end
int k=0;
int sorting=0;		// 1 if Sorted
int sort_count=0;
Ini I;
sortAlgo S;
displayScreen D;



void display()
{
	int t;
	glClear(GL_COLOR_BUFFER_BIT);

        D.display_text();
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


void makedelay(int)
{
	if(sorting)
	{
		switch(sort_count)
		{
			case 0:	S.bubblesort();		break;
			case 1:	S.selectionsort();	break;
			case 2: S.insertionsort();	break;
			case 3: S.ripplesort();		break;
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
			case 'i' :	I.Initialize(); break;
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
    I.Initialize();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0.000005,makedelay,1);
    glutMainLoop();
}
