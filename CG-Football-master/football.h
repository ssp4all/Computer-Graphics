/*
 * football.h
 * max(abs(x),abs(y)) = c
 *
 *  Created on: 10-May-2017
 *      Author: Bad Sam
 */

#ifndef FOOTBALL_H_
#define FOOTBALL_H_

#endif /* FOOTBALL_H_ */
#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void box(float mx, float my, float tx, float ty) {
	glBegin(GL_POLYGON);
	glVertex2f(mx, my);
	glVertex2f(tx, my);
	glVertex2f(tx, ty);
	glVertex2f(mx, ty);
	glEnd();
}

void box(int x, int y) {

}

void circle_draw(int x, int y, int r) {
	int i;
	float angle;
	glColor3f(0, 0.5, 1);
	glBegin(GL_POLYGON);
	//x = 10, y = 50, r = 30;
	for (i = 0; i < 360; i++) {
		angle = i * (3.14 / 180);
		glVertex2f((x + r * cos(angle)), (y + r * sin(angle)));
	}
	glEnd();

	glLineWidth(2.0);
	glColor3f(1, 1, 1);
	glBegin(GL_LINE_LOOP);
	//x = 10, y = 50, r = 30;
	for (i = 0; i < 360; i++) {
		angle = i * (3.14 / 180);
		glVertex2f((x + r * cos(angle)), (y + r * sin(angle)));
	}
	glEnd();
}

void circle_draw_empty(int x, int y, int r) {
	int i;
	float angle;
	glBegin(GL_LINE_LOOP);
	//x = 10, y = 50, r = 30;
	for (i = 0; i < 360; i++) {
		angle = i * (3.14 / 180);
		glVertex2f((x + r * cos(angle)), (y + r * sin(angle)));
	}
	glEnd();
}

void football_goal() {
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-500, -80);
	glVertex2f(-500, 80);
	glVertex2f(-440, 80);
	glVertex2f(-440, -80);
	glEnd();

	glColor3f(0.4342, 0.3453, 0.4342);
	glBegin(GL_QUADS);
	glVertex3f(-500, -80, 0.0);
	glVertex3f(-500, 80, 0.0);
	glVertex3f(-440, 80, 0.0);
	glVertex3f(-440, -80, 0.0);
	glEnd();
}

void ground() {
	glColor3f(0.183, 0.57651, 0.156);
	glBegin(GL_QUADS);
	glVertex2f(-500, -500);
	glVertex2f(-500, 500);
	glVertex2f(500, 500);
	glVertex2f(500, -500);
	glEnd();

	circle_draw(0, 0, 30);
	circle_draw(-500, 0, 200);
	circle_draw(500, 0, 200);

	glColor3f(1, 1, 1);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(0, -500);
	glVertex2f(0, 500);
	glEnd();

	football_goal();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(940, 0, 0);
	football_goal();
	glPopMatrix();

}

void soccer() {
	float i, x, y, r;
	float angle;
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	x = 0, y = 0, r = 30;
	for (i = 0; i < 360; i++) {
		angle = i * (3.14 / 180);
		glVertex2f((x + r * cos(angle)), (y + r * sin(angle)));
	}
	glEnd();

	glColor3f(135/255.0,206/255.0,250/255.0);
	glBegin(GL_LINE_STRIP);
	x = 0, y = 0, r = 0;
	for (i = 0;; i += 30) {
		angle = i * (3.14 / 180);
		glVertex2f((x + r * cos(angle)), (y + r * sin(angle)));
		r+=0.7;
		if (r >= 30)
			break;
	}

	glEnd();

}

void soccer_motion() {
	glLoadIdentity();

}

