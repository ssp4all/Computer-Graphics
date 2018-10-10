#include "football.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define deltadist 10

int axis;
int goal11 = 0, goal22 = 0;
float phyx = 50, phyy = 0, angle = ((rand() % 314) + acos(-1) / 4 * 100) / 100,
		p1x(250), p1y(0), p2x = -p1x, p2y = 0;
bool UP = true, RIGHT = true;
bool GameOver = true;
bool Colided;

class Collider {
public:
	float L, R, T, B, M;
	Collider(float Mag) {
		M = Mag;
		SetVal(0, 0);
	}
	Collider() {
		SetVal(0, 0);
	}
	void SetVal(float x, float y) {
		L = x - M, R = x + M, B = y - M, T = y + M;
	}

} CC(30), CP1(30), CP2(30), Goal1(40), Goal2(40);

void init() {
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	//glOrtho(-1, 1.0, -1, 1.0, -1.0, 1.0);
	gluOrtho2D(-500, 500, -500, 500);
	glMatrixMode(GL_MODELVIEW);
}

void print_bitmap_string(void* font, char* s)    //func. for displaying text
		{
	if (s && strlen(s)) {
		while (*s) {
			glutBitmapCharacter(font, *s);
			s++;
		}
	}
}

void olympic_sign()                          //for drawing olympics sign
{
	glColor3f(0.78954, 0.234534, 0.1945735);
	circle_draw_empty(-80, 300, 50);
	glColor3f(0.18954, 0.534534, 0.1945735);
	circle_draw_empty(0, 300, 50);
	glColor3f(0.38954, 0.434534, 0.8945735);
	circle_draw_empty(80, 300, 50);
	glColor3f(0.88954, 0.834534, 0.8945735);
	circle_draw_empty(-40, 240, 50);
	glColor3f(0.58954, 0.334534, 0.7945735);
	circle_draw_empty(40, 240, 50);
	glutPostRedisplay();
}
void text()                                //All the text and their position
{
	glColor3f(1, 0.2435645, 0.26453253);
	glRasterPos2f(-140, 100);
	print_bitmap_string(GLUT_BITMAP_TIMES_ROMAN_24, (char *) "OpenLympics");

	/*	glColor3f(0.422545, 0.33134534, 0.84345);
	 glRasterPos2f(-440, -10);
	 print_bitmap_string(GLUT_BITMAP_HELVETICA_18, (char *) "Swimming");

	 glColor3f(0.422545, 0.33134534, 0.84345);
	 glRasterPos2f(-70, -10);
	 print_bitmap_string(GLUT_BITMAP_HELVETICA_18, (char *) "Running");*/

	glColor3f(0.422545, 0.33134534, 0.84345);
	glRasterPos2f(-125, -100);
	print_bitmap_string(GLUT_BITMAP_HELVETICA_18, (char *) "1 Start , 2 End");

	glColor3f(0.422545, 0.33134534, 0.84345);
	glRasterPos2f(-125, -250);
	if (goal11 > goal22)
		print_bitmap_string(GLUT_BITMAP_HELVETICA_18, (char *) "Player 1 Won ");
	else if (goal11 < goal22)
		print_bitmap_string(GLUT_BITMAP_HELVETICA_18, (char *) "Player 2 Won ");

	glColor3f(0.622545, 0.73134534, 0.24345);
	glRasterPos2f(250, -450);
	print_bitmap_string(GLUT_BITMAP_HELVETICA_10, (char *) "Acknowledgment");

	glColor3f(0.722545, 0.53134534, 0.24345);
	glRasterPos2f(250, -470);
	print_bitmap_string(GLUT_BITMAP_HELVETICA_10, (char *) "Mr. ABC");

	glutPostRedisplay();
}

void ScoreBoard() {
	char SA[] = { (char) (goal11 / 10 + 0x30), (char) (goal11 % 10 + 0x30), 0 };
	glColor3f(1, 0.2435645, 0.26453253);
	glRasterPos2f(-250, 400);
	print_bitmap_string(GLUT_BITMAP_TIMES_ROMAN_24, SA);

	char SB[] = { (char) (goal22 / 10 + 0x30), (char) (goal22 % 10 + 0x30), 0 };
	glColor3f(1, 0.2435645, 0.26453253);
	glRasterPos2f(250, 400);
	print_bitmap_string(GLUT_BITMAP_TIMES_ROMAN_24, SB);
}

void reshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500, width, -500, height);
	glMatrixMode(GL_MODELVIEW);

}

void endText(char *ch) {
	glClear(GL_COLOR_BUFFER_BIT);

	glRasterPos2f(0, 0);
	print_bitmap_string(GLUT_BITMAP_TIMES_ROMAN_24, ch);
	GameOver = true;
}

void FrontPage() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	box(-450, -50);                              //box 1
	box(-100, -50);                              //2
	box(250, -50);                               //3
	text();
	olympic_sign();
}

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT);
	ground();
	ScoreBoard();
	if (GameOver) {
		FrontPage();
		glutSwapBuffers();
	}
}

void mouse(int but, int stat, int x, int y) {
	if (but == GLUT_LEFT_BUTTON && stat == GLUT_DOWN)
		return;
	if (but == GLUT_RIGHT_BUTTON && stat == GLUT_DOWN) {

	}
	if (but == GLUT_MIDDLE_BUTTON && stat == GLUT_DOWN)
		axis = 2;
	glutPostRedisplay();
}

void Idle() {
	if (GameOver) {
		FrontPage();
		//ground();
		//ScoreBoard();
		glutSwapBuffers();
	}
	if (GameOver)
		return;
	glLoadIdentity();

	display();

	CP1.SetVal(p1x, p1y);
	glColor3f(255.0 / 255.0, 140.0 / 255.0, 0);
	box(CP1.L, CP1.B, CP1.R, CP1.T);

	CP2.SetVal(p2x, p2y);
	glColor3f(148 / 255.0, 0, 211 / 255.0);
	box(CP2.L, CP2.B, CP2.R, CP2.T);

	glColor3f(205 / 255.0, 133 / 255.0, 63 / 255.0);
	Goal1.SetVal(-500, 0);
	box(Goal1.L, Goal1.B, Goal1.R, Goal1.T);

	Goal2.SetVal(500, 0);
	box(Goal2.L, Goal2.B, Goal2.R, Goal2.T);

	CC.SetVal(phyx, phyy);
	//glPushMatrix();

	cerr << "->" << phyy << " " << phyx << endl << "->" << goal11 << " "
			<< goal22 << endl;
	;

	bool preCol = Colided;

	Colided =
			(((CC.R < CP1.R && CC.R > CP1.L) || (CC.L < CP1.R && CC.L > CP1.L))
					&& ((CC.T < CP1.T && CC.T > CP1.B)
							|| (CC.B < CP1.T && CC.B > CP1.B)));

	preCol =
			(((CC.R < CP2.R && CC.R > CP2.L) || (CC.L < CP2.R && CC.L > CP2.L))
					&& ((CC.T < CP2.T && CC.T > CP2.B)
							|| (CC.B < CP2.T && CC.B > CP2.B)));

	bool goal1 = (((CC.R < Goal1.R && CC.R > Goal1.L)
			|| (CC.L < Goal1.R && CC.L > Goal1.L))
			&& ((CC.T < Goal1.T && CC.T > Goal1.B)
					|| (CC.B < Goal1.T && CC.B > Goal1.B))), goal2 = (((CC.R
			< Goal2.R && CC.R > Goal2.L) || (CC.L < Goal2.R && CC.L > Goal2.L))
			&& ((CC.T < Goal2.T && CC.T > Goal2.B)
					|| (CC.B < Goal2.T && CC.B > Goal2.B)));
	;

	if (goal1 || goal2) {
		(goal1) ? goal11++ : goal22++;
		phyx = phyy = 0;
		if (goal11 > 3)
			endText((char *) "Player 1 Won");
		if (goal22 > 3)
			endText((char *) "Player 2 Won");
	}

	if (phyy > 500 - 30 || phyy < -500 + 30
			|| (Colided && (phyy > CP1.T || phyy < CP1.B))
			|| (preCol && (phyy > CP2.T || phyy < CP2.B)))
		UP = !UP;
	if (phyx > 500 - 30 || phyx < -500 + 30
			|| ((Colided && (phyx > CP1.R || phyx < CP1.L))
					&& !(Colided && (phyy > CP1.T || phyy < CP1.B)))

			|| ((preCol && (phyx > CP2.R || phyx < CP2.L))
					&& !(preCol && (phyy > CP2.T || phyy < CP2.B))))
		RIGHT = !RIGHT;

	(UP) ? phyy += deltadist * sin(angle) : phyy -= deltadist * sin(angle);
	(RIGHT) ? phyx += deltadist * cos(angle) : phyx -= deltadist * cos(angle);

	glTranslatef(phyx, phyy, 0);
	soccer();

	//glPopMatrix();

	glutSwapBuffers();
}

void keyboard(unsigned char ch, int x, int y) {
	switch (ch) {
	case 'W':
		if (p1y < 500)
			p1y += deltadist * 2;
		break;
	case 'A':
		if (p1x > -500)
			p1x -= deltadist * 2;
		break;
	case 'D':
		if (p1x < 500)
			p1x += deltadist * 2;
		break;
	case 'S':
		if (p1y > -500)
			p1y -= deltadist * 2;
		break;

	case 'U':
		if (p2y < 500)
			p2y += deltadist * 2;
		break;
	case 'H':
		if (p2x > -500)
			p2x -= deltadist * 2;
		break;
	case 'K':
		if (p2x < 500)
			p2x += deltadist * 2;
		break;
	case 'J':
		if (p2y > -500)
			p2y -= deltadist * 2;
		break;
	case '1':
		if (GameOver)
			GameOver = false;
		break;
	case '2':
		if (GameOver)
			exit(0);
		break;
	}
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutCreateWindow("ttt");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	//glutReshapeFunc(reshape);
	glutIdleFunc(Idle);
	init();

	glColor3f(1, 1, 1);
	glutMainLoop();
}

/*GLfloat stroke_scale = 0.5f;
 glMatrixMode(GL_MODELVIEW);
 glPushMatrix(); {
 glTranslatef(200,200 , 0.0);
 glScalef(stroke_scale, stroke_scale, stroke_scale);
 print_stroke_string(GLUT_STROKE_MONO_ROMAN, "OpenLympics");
 } glPopMatrix();
 */
