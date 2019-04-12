#include "displayScreen.h"
#include <windows.h>
#include <GL/glut.h>
#include <string.h>
#include <iostream>

displayScreen::displayScreen()
{
    //ctor
}

displayScreen::~displayScreen()
{
    //dtor
}

void displayScreen::bitmap_output(int x, int y, char *string, void *font)
{
	int len, i;

	glRasterPos2f(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(font, string[i]);
	}
}

void displayScreen::display_text()
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



