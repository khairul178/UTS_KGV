#include <iostream>
#include <glut.h>
#include <math.h>

using namespace std;

float xr = 0, yr = 0;
const double phi = 3.14;

void lingkaran(int r, int n, int xt, int yt) {  //bulan
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 306; i++) {
		float sudut = i * (2 * phi / n);
		float x = xt + r * cos(sudut);
		float y = yt + r * sin(sudut);
		glVertex2f(x, y);
	}
}



void unit(void)
{
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glLineWidth(4.0f);
}



void kapal()
{
	glColor3ub(139, 69, 19); //kapal bawah
	glBegin(GL_QUADS);
	glVertex2f(30 + xr, 125);
	glVertex2f(250 + xr, 125);
	glVertex2f(210 + xr, 80);
	glVertex2f(70 + xr, 80);

	glEnd();

	glColor3ub(184, 134, 11);//kapal atas
	glBegin(GL_QUADS);
	glVertex2f(70 + xr, 155);
	glVertex2f(180 + xr, 155);
	glVertex2f(205 + xr, 125);
	glVertex2f(70 + xr, 125);

	glEnd();

	glColor3ub(0, 0, 0);//jendela
	glBegin(GL_QUADS);
	glVertex2f(80 + xr, 145);
	glVertex2f(97 + xr, 145);
	glVertex2f(97 + xr, 133);
	glVertex2f(80 + xr, 133);

	glEnd();

	glColor3ub(0, 0, 0);//jendela
	glBegin(GL_QUADS);
	glVertex2f(108 + xr, 145);
	glVertex2f(125 + xr, 145);
	glVertex2f(125 + xr, 133);
	glVertex2f(108 + xr, 133);

	glEnd();

	glColor3ub(0, 0, 0);//jendela
	glBegin(GL_QUADS);
	glVertex2f(136 + xr, 145);
	glVertex2f(153 + xr, 145);
	glVertex2f(153 + xr, 133);
	glVertex2f(136 + xr, 133);

	glEnd();

	glColor3ub(0, 0, 0);//jendela
	glBegin(GL_QUADS);
	glVertex2f(163 + xr, 145);
	glVertex2f(180 + xr, 145);
	glVertex2f(180 + xr, 133);
	glVertex2f(163 + xr, 133);
	glEnd();

	glFlush();
	glutPostRedisplay();
}

void userdraw()
{
	glBegin(GL_QUADS);
	glColor3ub(0, 191, 255);
	glVertex2f(0, 100);
	glVertex2f(500, 100);
	glColor3ub(0, 0, 128);
	glVertex2f(500, 0);
	glVertex2f(0, 0);

	glEnd();

	glColor3ub(224, 255, 255);
	lingkaran(20, 50, 440, 265);
	glEnd();


	kapal();
	glEnd();

}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	userdraw();
	glutSwapBuffers();
}


void tombolnya(int key, int x, int y) {
	switch (key) {

	case GLUT_KEY_RIGHT:
		xr++;
		cout << x << endl;
		glutPostRedisplay();
		break;

	case GLUT_KEY_LEFT:
		xr--;
		cout << x << endl;
		glutPostRedisplay();
		break;

	case GLUT_KEY_UP:
		yr;
		cout << y << endl;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		yr;
		cout << y << endl;
		glutPostRedisplay();
		break;

	}
}


int main(int argc, char** argv)
{
	glutInit(&__argc, __argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(150, 10);
	glutInitWindowSize(1000, 600);
	glutCreateWindow("Kapal Laut");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0.0, 500.0, 0.0, 300.0);
	glutIdleFunc(display);
	glutDisplayFunc(display);
	unit();
	glutSpecialFunc(tombolnya);
	glutMainLoop();

}