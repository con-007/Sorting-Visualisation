#include "Ini.h"
#include <windows.h>
#include <GL/glut.h>
#include <iostream>


using namespace std;

Ini::Ini()
{
    //ctor
}

Ini::~Ini()
{
    //dtor
}

void Ini::Initialize() {
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
