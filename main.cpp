#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#ifdef __APPLE__
#else
#endif
#include <stdlib.h>
#include <math.h>
#include <bits/stdc++.h>

#include "RGBpixmap.cpp"


#define PI 3.1415926535897932384626433832795
#define MaximumTheta 1.0
#define MinimumTheta 0.0009
#define MaximumRadious 10.5
#define MinimumRadious .9




using namespace std;

//DATATYPE DECLERATION
GLfloat IncrementTheta = 0.05;
GLint WindowSizX=640,WindowSizY=480;
GLfloat EyePosition_X=2.0,EyePosition_Y=1.3,EyePosition_Z= 2.0;
GLfloat Radious=3.3,ProRadious=3.0,InitialTheta1=0.716,InitialTheta2=0.403;
GLfloat Center_X=0.0,Center_Y=0.0,Center_Z=0.0;
GLfloat Up_X=0.0,Up_Y=1.0,Up_Z=0.0;
enum { ClockWise,AntiClockWise };
enum {Theta1,Theta2};
float Near=.05, Far=10.0,fova = 50.0;
GLint direction = AntiClockWise;
GLint PressMovenent=Theta1;

RGBpixmap pix[6];
/*
GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient[] = { 1.0, 0.7, 0.3, 1.0 };
GLfloat mat_diffuse[] = { 0.5, 0.1, 0.6, 1.0 };
GLfloat mat_specular[] = { 1, 1, 1, 1.0 };
GLfloat mat_shininess[] = {10};

GLfloat no_mat2[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient2[] = { 0, 0.3, 0.2, 1.0 };
GLfloat mat_diffuse2[] = { 0, 0.3, 0.2, 1.0 };
GLfloat mat_specular2[] = { 1, 1, 1, 1.0 };
GLfloat mat_shininess2[] = {10};

GLfloat no_mat3[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient3[] = { 0.4, 0, 0, 1.0 };
GLfloat mat_diffuse3[] = { 0.4, 0, 0, 1.0 };
GLfloat mat_specular3[] = { 0.5, 0.2, 0, 1.0 };
GLfloat mat_shininess3[] = {10};
*/
void wall1(){
/*
    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient2);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse2);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular2);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess2);
*/
    glBegin(GL_QUADS);

    glColor3f(0.91f,0.14f,0.14f);


    glVertex3f( 0.0f, 1.0f,0.0f);
    glVertex3f(0.0f, 1.0f,1.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glVertex3f( 0.0f, 0.0f, 0.0f);

    glVertex3f( -0.2f, 1.0f,0.0f);
    glVertex3f(-0.2f, 0.0f,0.0f);
    glVertex3f(-0.2f, 0.0f, 1.0f);
    glVertex3f( -0.2f, 1.0f, 1.0f);

    glVertex3f( 0.0f, 1.0f, 1.0f);
    glVertex3f(-0.2f, 1.0f, 1.0f);
    glVertex3f(-0.2f,0.0f, 1.0f);
    glVertex3f( 0.0f,0.0f, 1.0f);

    glVertex3f( 0.0f,1.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(-0.2f,0.0f,0.0f);
    glVertex3f(-0.2f, 1.0f,0.0f);

    glVertex3f(0.0f, 1.0f, 1.0f);
    glVertex3f(0.0f, 1.0f,0.0f);
    glVertex3f(-0.2f,1.0f,0.0f);
    glVertex3f(-0.2f,1.0f, 1.0f);

    glVertex3f(-0.2f, 0.0f,1.0f);
    glVertex3f(-0.2f, 0.0f, 0.0f);
    glVertex3f( 0.0f,0.0f, 0.0f);
    glVertex3f(0.0f,0.0f,1.0f);

    glEnd();


}

void wall2(){
/*
    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient2);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse2);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular2);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess2);
*/
    glBegin(GL_QUADS);

    glColor3f(0.91f,0.14f,0.14f);

    glVertex3f(2.0f, 1.0f,0.0f);
    glVertex3f(2.0f, 1.0f,1.0f);
    glVertex3f(2.0f, 0.0f, 1.0f);
    glVertex3f(2.0f, 0.0f, 0.0f);

    glVertex3f(1.8f, 1.0f,0.0f);
    glVertex3f(1.8f, 0.0f,0.0f);
    glVertex3f(1.8f, 0.0f, 1.0f);
    glVertex3f(1.8f, 1.0f, 1.0f);

    glVertex3f(2.0f, 1.0f, 1.0f);
    glVertex3f(1.8f, 1.0f, 1.0f);
    glVertex3f(1.8f,0.0f, 1.0f);
    glVertex3f(2.0f,0.0f, 1.0f);

    glVertex3f(2.0f,1.0f,0.0f);
    glVertex3f(2.0f,0.0f,0.0f);
    glVertex3f(1.8f,0.0f,0.0f);
    glVertex3f(1.8f, 1.0f,0.0f);

    glVertex3f(2.0f, 1.0f, 1.0f);
    glVertex3f(2.0f, 1.0f,0.0f);
    glVertex3f(1.8f,1.0f,0.0f);
    glVertex3f(1.8f,1.0f, 1.0f);

    glVertex3f(1.8f, 0.0f,1.0f);
    glVertex3f(1.8f, 0.0f, 0.0f);
    glVertex3f(2.0f,0.0f, 0.0f);
    glVertex3f(2.0f,0.0f,1.0f);

    glEnd();

}

void wall3(){
/*
    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient3);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse3);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular3);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess3);
    */
    glBegin(GL_QUADS);
    glColor3f(0.06,0.4,0.11);

    glVertex3f(-0.2f,-0.2f,1.0f);
    glVertex3f(-0.2f,-0.2f,0.0f);
    glVertex3f(0.0f,-0.2f,0.0f);
    glVertex3f(0.0f,-0.2f,1.0f);

    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,-0.2f,0.0f);
    glVertex3f(-0.2f,-0.2f,0.0f);
    glVertex3f(-0.2f,0.0f,0.0f);

    glVertex3f(0.0f,0.0f,1.0f);
    glVertex3f(-0.2f,0.0f,1.0f);
    glVertex3f(-0.2f,-0.2f,1.0f);
    glVertex3f(0.0f,-0.2f,1.0f);

    glVertex3f(0.0f,0.0f,1.0f);
    glVertex3f(0.0f,-0.2f,1.0f);
    glVertex3f(0.0f,-0.2f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);

    glVertex3f(-0.2f,0.0f,1.0f);
    glVertex3f(-0.2f,0.0f,0.0f);
    glVertex3f(-0.2f,-0.2f,0.0f);
    glVertex3f(-0.2f,-0.2f,1.0f);

    glVertex3f(1.8f,-0.2f,1.0f);
    glVertex3f(1.8f,-0.2f,0.0f);
    glVertex3f(2.0f,-0.2f,0.0f);
    glVertex3f(2.0f,-0.2f,1.0f);

    glVertex3f(2.0f,0.0f,0.0f);
    glVertex3f(2.0f,-0.2f,0.0f);
    glVertex3f(1.8f,-0.2f,0.0f);
    glVertex3f(1.8f,0.0f,0.0f);

    glVertex3f(1.8f,0.0f,1.0f);
    glVertex3f(1.8f,-0.2f,1.0f);
    glVertex3f(2.0f,-0.2f,1.0f);
    glVertex3f(2.0f,0.0f,1.0f);

    glVertex3f(1.8f,0.0f,1.0f);
    glVertex3f(1.8f,0.0f,0.0f);
    glVertex3f(1.8f,-0.2f,0.0f);
    glVertex3f(1.8f,-0.2f,1.0f);

    glVertex3f(2.0f,0.0f,1.0f);
    glVertex3f(2.0f,-0.2f,1.0f);
    glVertex3f(2.0f,-0.2f,0.0f);
    glVertex3f(2.0f,0.0f,0.0f);

    glVertex3f(1.8f,0.0f,0.0f);
    glVertex3f(1.8f,-0.2f,0.0f);
    glVertex3f(0.0f,-0.2f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);

    glVertex3f(1.8f,0.0f,1.0f);
    glVertex3f(0.0f,0.0f,1.0f);
    glVertex3f(0.0f,-0.2f,1.0f);
    glVertex3f(1.8f,-0.2f,1.0f);

    glVertex3f(1.8f,-0.2f,1.0f);
    glVertex3f(1.8f,-0.2f,0.0f);
    glVertex3f(2.0f,-0.2f,0.0f);
    glVertex3f(2.0f,-0.2f,1.0f);

    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,1.0f);
    glVertex3f(1.8f,0.0f,1.0f);
    glVertex3f(1.8f,0.0f,0.0f);

    glVertex3f(0.0f,-0.2f,1.0f);
    glVertex3f(0.0f,-0.2f,0.0f);
    glVertex3f(1.8f,-0.2f,0.0f);
    glVertex3f(1.8f,-0.2f,1.0f);

    glEnd();
}

void wall4(){

    /*glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient3);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse3);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular3);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess3);
*/

    glBegin(GL_QUADS);

    glColor3f(0.06,0.4,0.11);

    glVertex3f(1.8f,1.0f,0.0f);
    glVertex3f(2.0f,1.0f,0.0f);
    glVertex3f(2.0f,1.0f,-0.2f);
    glVertex3f(1.8f,1.0f,-0.2f);

    glVertex3f(1.8f,0.0f,0.0f);
    glVertex3f(2.0f,0.0f,0.0f);
    glVertex3f(2.0f,0.0f,-0.2f);
    glVertex3f(1.8f,0.0f,-0.2f);

    glVertex3f(1.8f,-0.2f,0.0f);
    glVertex3f(1.8f,-0.2f,-0.2f);
    glVertex3f(2.0f,-0.2f,-0.2f);
    glVertex3f(2.0f,-0.2f,0.0f);

    glVertex3f(2.0f,0.0f,0.0f);
    glVertex3f(2.0f,-0.2f,0.0f);
    glVertex3f(2.0f,-0.2f,-0.2f);
    glVertex3f(2.0f,0.0f,-0.2f);

    glVertex3f(2.0f,0.0f,-0.2f);
    glVertex3f(2.0f,-0.2f,-0.2f);
    glVertex3f(1.8f,-0.2f,-0.2f);
    glVertex3f(1.8f,0.0f,-0.2f);

    glVertex3f(1.8f,0.0f,0.0f);
    glVertex3f(1.8f,0.0f,-0.2f);
    glVertex3f(1.8f,-0.2f,-0.2f);
    glVertex3f(1.8f,-0.2f,0.0f);

    glVertex3f(2.0f,1.0f,-0.2f);
    glVertex3f(2.0f,0.0f,-0.2f);
    glVertex3f(1.8f,0.0f,-0.2f);
    glVertex3f(1.8f,1.0f,-0.2f);

    glVertex3f(2.0f,1.0f,0.0f);
    glVertex3f(2.0f,0.0f,0.0f);
    glVertex3f(2.0f,0.0f,-0.2f);
    glVertex3f(2.0f,1.0f,-0.2f);

    glVertex3f(1.8f,1.0f,0.0f);
    glVertex3f(1.8f,1.0f,-0.2f);
    glVertex3f(1.8f,0.0f,-0.2f);
    glVertex3f(1.8f,0.0f,0.0f);

    glVertex3f(0.0f,1.0f,0.0f);
    glVertex3f(0.0f,1.0f,-0.2f);
    glVertex3f(-0.2f,1.0f,-0.2f);
    glVertex3f(-0.2f,1.0f,0.0f);

    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,-0.2f);
    glVertex3f(-0.2f,0.0f,-0.2f);
    glVertex3f(-0.2f,0.0f,0.0f);

    glVertex3f(0.0f,-0.2f,0.0f);
    glVertex3f(-0.2f,-0.2f,0.0f);
    glVertex3f(-0.2f,-0.2f,-0.2f);
    glVertex3f(0.0f,-0.2f,-0.2f);

    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,-0.2f,0.0f);
    glVertex3f(0.0f,-0.2f,-0.2f);
    glVertex3f(0.0f,0.0f,-0.2f);

    glVertex3f(0.0f,0.0f,-0.2f);
    glVertex3f(0.0f,-0.2f,-0.2f);
    glVertex3f(-0.2f,-0.2f,-0.2f);
    glVertex3f(-0.2f,0.0f,-0.2f);

    glVertex3f(-0.2f,0.0f,0.0f);
    glVertex3f(-0.2f,0.0f,-0.2f);
    glVertex3f(-0.2f,-0.2f,-0.2f);
    glVertex3f(-0.2f,-0.2f,0.0f);

    glVertex3f(0.0f,1.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,0.0f,-0.2f);
    glVertex3f(0.0f,1.0f,-0.2f);

    glVertex3f(-0.2f,1.0f,0.0f);
    glVertex3f(-0.2f,1.0f,-0.2f);
    glVertex3f(-0.2f,0.0f,-0.2f);
    glVertex3f(-0.2f,0.0f,0.0f);

    glVertex3f(0.0f,1.0f,-0.2f);
    glVertex3f(0.0f,0.0f,-0.2f);
    glVertex3f(-0.2f,0.0f,-0.2f);
    glVertex3f(-0.2f,1.0f,-0.2f);

    glVertex3f(0.0f,1.0f,-0.2f);
    glVertex3f(1.8f,1.0f,-0.2f);
    glVertex3f(1.8f,0.0f,-0.2f);
    glVertex3f(0.0f,0.0f,-0.2f);

    glVertex3f(0.0f,0.0f,-0.2f);
    glVertex3f(1.8f,0.0f,-0.2f);
    glVertex3f(1.8f,-0.2f,-0.2f);
    glVertex3f(0.0f,-0.2f,-0.2f);

    glVertex3f(0.0f,1.0f,0.0f);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(1.8f,0.0f,0.0f);
    glVertex3f(1.8f,1.0f,0.0f);

    glVertex3f(0.0f,1.0f,0.0f);
    glVertex3f(1.8f,1.0f,0.0f);
    glVertex3f(1.8f,1.0f,-0.2f);
    glVertex3f(0.0f,1.0f,-0.2f);

    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(1.8f,0.0f,0.0f);
    glVertex3f(1.8f,0.0f,-0.2f);
    glVertex3f(0.0f,0.0f,-0.2f);

    glVertex3f(0.0f,-0.2f,0.0f);
    glVertex3f(0.0f,-0.2f,-0.2f);
    glVertex3f(1.8f,-0.2f,-0.2f);
    glVertex3f(1.8f,-0.2f,0.0f);

    glEnd();
}

void tablePlane(){

    /*glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
*/
    glBegin(GL_QUADS);

    glColor3f(0.4,0.08,0.82);

    glVertex3f(0.3f,0.3f,0.5f);
    glVertex3f(1.5f,0.3f,0.5f);
    glVertex3f(1.5f,0.3f,0.1f);
    glVertex3f(0.3f,0.3f,0.1f);

    glVertex3f(0.3f,0.2f,0.1f);
    glVertex3f(1.5f,0.2f,0.1f);
    glVertex3f(1.5f,0.2f,0.5f);
    glVertex3f(0.3f,0.2f,0.5f);

    glVertex3f(0.3f,0.3f,0.5f);
    glVertex3f(0.3f,0.2f,0.5f);
    glVertex3f(1.5f,0.2f,0.5f);
    glVertex3f(1.5f,0.3f,0.5f);

    glVertex3f(0.3f,0.3f,0.1f);
    glVertex3f(1.5f,0.3f,0.1f);
    glVertex3f(1.5f,0.2f,0.1f);
    glVertex3f(0.3f,0.2f,0.1f);

    glVertex3f(1.5f,0.3f,0.5f);
    glVertex3f(1.5f,0.2f,0.5f);
    glVertex3f(1.5f,0.2f,0.1f);
    glVertex3f(1.5f,0.3f,0.1f);

    glVertex3f(0.3f,0.3f,0.5f);
    glVertex3f(0.3f,0.3f,0.1f);
    glVertex3f(0.3f,0.2f,0.1f);
    glVertex3f(0.3f,0.2f,0.5f);

    glEnd();
}

void tableLeg1(){
    /*glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    */
    glBegin(GL_QUADS);

    glColor3f(0.4,0.08,0.82);

    glVertex3f(0.3f,0.2f,0.5f);
    glVertex3f(0.3f,0.2f,0.4f);
    glVertex3f(0.3f,0.0f,0.4f);
    glVertex3f(0.3f,0.0f,0.5f);

    glVertex3f(0.4f,0.2f,0.5f);
    glVertex3f(0.4f,0.0f,0.5f);
    glVertex3f(0.4f,0.0f,0.4f);
    glVertex3f(0.4f,0.2f,0.4f);

    glVertex3f(0.4f,0.2f,0.5f);
    glVertex3f(0.4f,0.2f,0.4f);
    glVertex3f(0.3f,0.2f,0.4f);
    glVertex3f(0.3f,0.2f,0.5f);

    glVertex3f(0.3f,0.0f,0.5f);
    glVertex3f(0.3f,0.0f,0.4f);
    glVertex3f(0.4f,0.0f,0.4f);
    glVertex3f(0.4f,0.0f,0.5f);

    glVertex3f(0.4f,0.2f,0.4f);
    glVertex3f(0.4f,0.0f,0.4f);
    glVertex3f(0.3f,0.0f,0.4f);
    glVertex3f(0.3f,0.2f,0.4f);

    glVertex3f(0.3f,0.2f,0.5f);
    glVertex3f(0.3f,0.0f,0.5f);
    glVertex3f(0.4f,0.0f,0.5f);
    glVertex3f(0.4f,0.2f,0.5f);

    glEnd();
}

void tableLeg2(){
 /*   glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
   */
    glBegin(GL_QUADS);

    glColor3f(0.4,0.08,0.82);

    glVertex3f(1.5f,0.2f,0.5f);
    glVertex3f(1.5f,0.2f,0.4f);
    glVertex3f(1.4f,0.2f,0.4f);
    glVertex3f(1.4f,0.2f,0.5f);

    glVertex3f(1.5f,0.0f,0.4f);
    glVertex3f(1.5f,0.0f,0.5f);
    glVertex3f(1.4f,0.0f,0.5f);
    glVertex3f(1.4f,0.0f,0.4f);

    glVertex3f(1.5f,0.2f,0.5f);
    glVertex3f(1.5f,0.0f,0.5f);
    glVertex3f(1.4f,0.0f,0.4f);
    glVertex3f(1.4f,0.2f,0.4f);

    glVertex3f(1.4f,0.2f,0.4f);
    glVertex3f(1.4f,0.0f,0.4f);
    glVertex3f(1.4f,0.0f,0.5f);
    glVertex3f(1.4f,0.2f,0.5f);

    glVertex3f(1.5f,0.2f,0.4f);
    glVertex3f(1.5f,0.0f,0.4f);
    glVertex3f(1.4f,0.0f,0.4f);
    glVertex3f(1.4f,0.2f,0.4f);

    glVertex3f(1.5f,0.2f,0.5f);
    glVertex3f(1.4f,0.2f,0.5f);
    glVertex3f(1.4f,0.0f,0.5f);
    glVertex3f(1.5f,0.0f,0.5f);

    glEnd();
}

void tableLeg3(){
    /*
    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    */
    glBegin(GL_QUADS);

    glColor3f(0.4,0.08,0.82);

    glVertex3f(0.3f,0.2f,0.1f);
    glVertex3f(0.3f,0.0f,0.1f);
    glVertex3f(0.3f,0.0f,0.2f);
    glVertex3f(0.3f,0.2f,0.2f);

    glVertex3f(0.4f,0.2f,0.1f);
    glVertex3f(0.4f,0.2f,0.2f);
    glVertex3f(0.4f,0.0f,0.2f);
    glVertex3f(0.4f,0.0f,0.1f);

    glVertex3f(0.3f,0.2f,0.1f);
    glVertex3f(0.4f,0.2f,0.1f);
    glVertex3f(0.4f,0.0f,0.1f);
    glVertex3f(0.3f,0.0f,0.1f);

    glVertex3f(0.4f,0.2f,0.2f);
    glVertex3f(0.3f,0.2f,0.2f);
    glVertex3f(0.3f,0.0f,0.2f);
    glVertex3f(0.4f,0.0f,0.2f);

    glVertex3f(0.4f,0.2f,0.2f);
    glVertex3f(0.4f,0.2f,0.1f);
    glVertex3f(0.3f,0.2f,0.1f);
    glVertex3f(0.3f,0.2f,0.2f);

    glVertex3f(0.4f,0.0f,0.2f);
    glVertex3f(0.3f,0.0f,0.2f);
    glVertex3f(0.3f,0.0f,0.1f);
    glVertex3f(0.4f,0.0f,0.1f);

    glEnd();
}

void tableLeg4(){
    /*
    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    */
    glBegin(GL_QUADS);

    glColor3f(0.4,0.08,0.82);

    glVertex3f(1.5f,0.2f,0.2f);
    glVertex3f(1.5f,0.2f,0.1f);
    glVertex3f(1.4f,0.2f,0.1f);
    glVertex3f(1.4f,0.2f,0.2f);

    glVertex3f(1.5f,0.0f,0.2f);
    glVertex3f(1.4f,0.0f,0.2f);
    glVertex3f(1.4f,0.0f,0.1f);
    glVertex3f(1.5f,0.0f,0.1f);

    glVertex3f(1.5f,0.2f,0.2f);
    glVertex3f(1.5f,0.0f,0.2f);
    glVertex3f(1.5f,0.0f,0.1f);
    glVertex3f(1.5f,0.2f,0.1f);

    glVertex3f(1.4f,0.2f,0.1f);
    glVertex3f(1.4f,0.0f,0.1f);
    glVertex3f(1.4f,0.0f,0.2f);
    glVertex3f(1.4f,0.2f,0.2f);

    glVertex3f(1.5f,0.2f,0.1f);
    glVertex3f(1.5f,0.0f,0.1f);
    glVertex3f(1.4f,0.0f,0.1f);
    glVertex3f(1.4f,0.2f,0.1f);

    glVertex3f(1.5f,0.2f,0.2f);
    glVertex3f(1.4f,0.2f,0.2f);
    glVertex3f(1.4f,0.0f,0.2f);
    glVertex3f(1.5f,0.0f,0.2f);


    glEnd();

}

void minarMiddle(){
    glBegin(GL_QUADS);

    glColor3f(1.0,1.0,1.0);

    glVertex3f(0.7f,0.35f,0.2f);
    glVertex3f(0.7f,0.35f,0.25f);
    glVertex3f(0.9f,0.35f,0.25f);
    glVertex3f(0.9f,0.35f,0.2f);

    glVertex3f(0.7f,0.3f,0.25f);
    glVertex3f(0.7f,0.3f,0.2f);
    glVertex3f(0.9f,0.3f,0.2f);
    glVertex3f(0.9f,0.3f,0.25f);

    glVertex3f(0.7f,0.35f,0.25f);
    glVertex3f(0.7f,0.3f,0.25f);
    glVertex3f(0.9f,0.3f,0.25f);
    glVertex3f(0.9f,0.35f,0.25f);

    glVertex3f(0.7f,0.35f,0.2f);
    glVertex3f(0.9f,0.35f,0.2f);
    glVertex3f(0.9f,0.3f,0.2f);
    glVertex3f(0.7f,0.3f,0.2f);

    glVertex3f(0.7f,0.3f,0.25f);
    glVertex3f(0.7f,0.35f,0.25f);
    glVertex3f(0.7f,0.35f,0.2f);
    glVertex3f(0.7f,0.3f,0.2f);

    glVertex3f(0.9f,0.35f,0.25f);
    glVertex3f(0.9f,0.3f,0.25f);
    glVertex3f(0.9f,0.3f,0.2f);
    glVertex3f(0.9f,0.35f,0.2f);
    /////////////////////////

    glVertex3f(0.7f,0.7f,0.2f);
    glVertex3f(0.7f,0.35f,0.2f);
    glVertex3f(0.7f,0.35f,0.25f);
    glVertex3f(0.7f,0.7f,0.25f);

    glVertex3f(0.75f,0.7f,0.25f);
    glVertex3f(0.75f,0.7f,0.25f);
    glVertex3f(0.75f,0.35f,0.25f);
    glVertex3f(0.75f,0.35f,0.25f);

    glVertex3f(0.7f,0.7f,0.25f);
    glVertex3f(0.7f,0.35f,0.25f);
    glVertex3f(0.75f,0.35f,0.25f);
    glVertex3f(0.75f,0.7f,0.25f);

    glVertex3f(0.7f,0.7f,0.2f);
    glVertex3f(0.75f,0.7f,0.2f);
    glVertex3f(0.75f,0.35f,0.2f);
    glVertex3f(0.7f,0.35f,0.2f);

    glVertex3f(0.7f,0.7f,0.2f);
    glVertex3f(0.7f,0.7f,0.25f);
    glVertex3f(0.75f,0.7f,0.25f);
    glVertex3f(0.75f,0.7f,0.2f);

    glVertex3f(0.75f,0.35f,0.2f);
    glVertex3f(0.75f,0.35f,0.25f);
    glVertex3f(0.7f,0.35f,0.25f);
    glVertex3f(0.7f,0.35f,0.2f);
/////////////////////////////////////////

    glVertex3f(0.85f,0.7f,0.2f);
    glVertex3f(0.85f,0.7f,0.25f);
    glVertex3f(0.9f,0.7f,0.25f);
    glVertex3f(0.9f,0.7f,0.2f);

    glVertex3f(0.9f,0.35f,0.2f);
    glVertex3f(0.9f,0.35f,0.25f);
    glVertex3f(0.85f,0.35f,0.25f);
    glVertex3f(0.85f,0.35f,0.2f);

    glVertex3f(0.85f,0.7f,0.2f);
    glVertex3f(0.85f,0.35f,0.2f);
    glVertex3f(0.85f,0.35f,0.25f);
    glVertex3f(0.85f,0.7f,0.25f);

    glVertex3f(0.9f,0.7f,0.2f);
    glVertex3f(0.9f,0.7f,0.25f);
    glVertex3f(0.9f,0.35f,0.25f);
    glVertex3f(0.9f,0.35f,0.2f);

    glVertex3f(0.9f,0.7f,0.25f);
    glVertex3f(0.85f,0.7f,0.25f);
    glVertex3f(0.85f,0.35f,0.25f);
    glVertex3f(0.9f,0.35f,0.25f);

    glVertex3f(0.85f,0.7f,0.2f);
    glVertex3f(0.9f,0.7f,0.2f);
    glVertex3f(0.9f,0.35f,0.2f);
    glVertex3f(0.85f,0.35f,0.2f);

///////////////////////////////////////////

    glVertex3f(1.0f,0.7f,0.2f);
    glVertex3f(1.0f,0.7f,0.25f);
    glVertex3f(1.05f,0.7f,0.25f);
    glVertex3f(1.05f,0.7f,0.2f);

    glVertex3f(1.0f,0.3f,0.2f);
    glVertex3f(1.05f,0.3f,0.2f);
    glVertex3f(1.05f,0.3f,0.25f);
    glVertex3f(1.0f,0.3f,0.25f);

    glVertex3f(1.0f,0.7f,0.2f);
    glVertex3f(1.0f,0.3f,0.2f);
    glVertex3f(1.0f,0.3f,0.25f);
    glVertex3f(1.0f,0.7f,0.25f);

    glVertex3f(1.05f,0.7f,0.25f);
    glVertex3f(1.05f,0.3f,0.25f);
    glVertex3f(1.05f,0.3f,0.2f);
    glVertex3f(1.05f,0.75f,0.2f);

    glVertex3f(1.0f,0.7f,0.25f);
    glVertex3f(1.0f,0.3f,0.25f);
    glVertex3f(1.05f,0.3f,0.25f);
    glVertex3f(1.05f,0.7f,0.25f);

    glVertex3f(1.0f,0.7f,0.2f);
    glVertex3f(1.05f,0.7f,0.2f);
    glVertex3f(1.05f,0.3f,0.2f);
    glVertex3f(1.0f,0.3f,0.2f);
////////////////////////////////////

    glVertex3f(0.9f,0.35f,0.2f);
    glVertex3f(0.9f,0.35f,0.25f);
    glVertex3f(1.0f,0.35f,0.25f);
    glVertex3f(1.0f,0.35f,0.2f);

    glVertex3f(1.0f,0.3f,0.2f);
    glVertex3f(1.0f,0.3f,0.25f);
    glVertex3f(0.9f,0.3f,0.25f);
    glVertex3f(0.9f,0.3f,0.2f);

    glVertex3f(0.9f,0.35f,0.2f);
    glVertex3f(0.9f,0.3f,0.2f);
    glVertex3f(0.9f,0.3f,0.25f);
    glVertex3f(0.9f,0.35f,0.25f);

    glVertex3f(1.0f,0.35f,0.2f);
    glVertex3f(1.0f,0.35f,0.25f);
    glVertex3f(1.0f,0.3f,0.25f);
    glVertex3f(1.0f,0.3f,0.2f);

    glVertex3f(0.9f,0.35f,0.25f);
    glVertex3f(0.9f,0.3f,0.25f);
    glVertex3f(1.0f,0.3f,0.25f);
    glVertex3f(1.0f,0.35f,0.25f);

    glVertex3f(0.9f,0.35f,0.2f);
    glVertex3f(1.0f,0.35f,0.2f);
    glVertex3f(1.0f,0.3f,0.2f);
    glVertex3f(0.9f,0.3f,0.2f);

    ////////////////////////////////////

    glVertex3f(0.7f,0.9f,0.3f);
    glVertex3f(0.7f,0.9f,0.35f);
    glVertex3f(0.75f,0.9f,0.35f);
    glVertex3f(0.75f,0.9f,0.3f);

    glVertex3f(0.75f,0.7f,0.2f);
    glVertex3f(0.75f,0.7f,0.25f);
    glVertex3f(0.7f,0.7f,0.25f);
    glVertex3f(0.7f,0.7f,0.2f);

    glVertex3f(0.7f,0.9f,0.3f);
    glVertex3f(0.7f,0.7f,0.2f);
    glVertex3f(0.7f,0.7f,0.25f);
    glVertex3f(0.7f,0.9f,0.35f);

    glVertex3f(0.75f,0.9f,0.3f);
    glVertex3f(0.75f,0.9f,0.35f);
    glVertex3f(0.75f,0.7f,0.25f);
    glVertex3f(0.75f,0.7f,0.2f);

    glVertex3f(0.7f,0.9f,0.35f);
    glVertex3f(0.7f,0.7f,0.25f);
    glVertex3f(0.75f,0.7f,0.25f);
    glVertex3f(0.75f,0.9f,0.35f);

    glVertex3f(0.7f,0.9f,0.3f);
    glVertex3f(0.75f,0.9f,0.3f);
    glVertex3f(0.75f,0.7f,0.2f);
    glVertex3f(0.7f,0.7f,0.2f);

    ////////////////////////////////////////////

    glVertex3f(0.85f,0.9f,0.3f);
    glVertex3f(0.85f,0.9f,0.35f);
    glVertex3f(0.9f,0.9f,0.35f);
    glVertex3f(0.9f,0.9f,0.3f);

    glVertex3f(0.9f,0.7f,0.2f);
    glVertex3f(0.9f,0.7f,0.25f);
    glVertex3f(0.85f,0.7f,0.25f);
    glVertex3f(0.85f,0.7f,0.2f);

    glVertex3f(0.85f,0.9f,0.3f);
    glVertex3f(0.85f,0.7f,0.2f);
    glVertex3f(0.85f,0.7f,0.25f);
    glVertex3f(0.85f,0.9f,0.35f);

    glVertex3f(0.9f,0.9f,0.3f);
    glVertex3f(0.9f,0.9f,0.35f);
    glVertex3f(0.9f,0.7f,0.25f);
    glVertex3f(0.9f,0.7f,0.2f);

    glVertex3f(0.85f,0.9f,0.35f);
    glVertex3f(0.85f,0.7f,0.25f);
    glVertex3f(0.9f,0.7f,0.25f);
    glVertex3f(0.9f,0.9f,0.35f);

    glVertex3f(0.85f,0.9f,0.3f);
    glVertex3f(0.9f,0.9f,0.3f);
    glVertex3f(0.9f,0.7f,0.2f);
    glVertex3f(0.85f,0.7f,0.2f);

    /////////////////////////////////////////

    glVertex3f(1.0f,0.9f,0.3f);
    glVertex3f(1.0f,0.9f,0.35f);
    glVertex3f(1.05f,0.9f,0.35f);
    glVertex3f(1.05f,0.9f,0.3f);

    glVertex3f(1.05f,0.7f,0.2f);
    glVertex3f(1.05f,0.7f,0.25f);
    glVertex3f(1.0f,0.7f,0.25f);
    glVertex3f(1.0f,0.7f,0.2f);

    glVertex3f(1.0f,0.9f,0.3f);
    glVertex3f(1.0f,0.7f,0.2f);
    glVertex3f(1.0f,0.7f,0.25f);
    glVertex3f(1.0f,0.9f,0.35f);

    glVertex3f(1.05f,0.9f,0.3f);
    glVertex3f(1.05f,0.9f,0.35f);
    glVertex3f(1.05f,0.7f,0.25f);
    glVertex3f(1.05f,0.7f,0.2f);

    glVertex3f(1.0f,0.9f,0.35f);
    glVertex3f(1.0f,0.7f,0.25f);
    glVertex3f(1.05f,0.7f,0.25f);
    glVertex3f(1.05f,0.9f,0.35f);

    glVertex3f(1.0f,0.9f,0.3f);
    glVertex3f(1.05f,0.9f,0.3f);
    glVertex3f(1.05f,0.7f,0.2f);
    glVertex3f(1.0f,0.7f,0.2f);
    //////////////////////////////////////////////////

    glVertex3f(0.75f,0.9f,0.3f);
    glVertex3f(0.75f,0.85f,0.3f);
    glVertex3f(0.75f,0.85f,0.35f);
    glVertex3f(0.75f,0.9f,0.35f);

    glVertex3f(0.85f,0.9f,0.3f);
    glVertex3f(0.85f,0.9f,0.35f);
    glVertex3f(0.85f,0.85f,0.35f);
    glVertex3f(0.85f,0.85f,0.3f);

    glVertex3f(0.75f,0.9f,0.35f);
    glVertex3f(0.75f,0.85f,0.35f);
    glVertex3f(0.85f,0.85f,0.35f);
    glVertex3f(0.85f,0.9f,0.35f);

    glVertex3f(0.75f,0.9f,0.3f);
    glVertex3f(0.85f,0.9f,0.3f);
    glVertex3f(0.85f,0.85f,0.3f);
    glVertex3f(0.75f,0.85f,0.3f);

    glVertex3f(0.75f,0.9f,0.3f);
    glVertex3f(0.75f,0.9f,0.35f);
    glVertex3f(0.85f,0.9f,0.35f);
    glVertex3f(0.85f,0.9f,0.3f);

    glVertex3f(0.85f,0.85f,0.3f);
    glVertex3f(0.85f,0.85f,0.35f);
    glVertex3f(0.75f,0.85f,0.35f);
    glVertex3f(0.75f,0.85f,0.3f);
    ////////////////////////////////

    glVertex3f(0.9f,0.9f,0.3f);
    glVertex3f(0.9f,0.85f,0.3f);
    glVertex3f(0.9f,0.85f,0.35f);
    glVertex3f(0.9f,0.9f,0.35f);

    glVertex3f(1.0f,0.9f,0.3f);
    glVertex3f(1.0f,0.9f,0.35f);
    glVertex3f(1.0f,0.85f,0.35f);
    glVertex3f(1.0f,0.85f,0.3f);

    glVertex3f(0.9f,0.9f,0.35f);
    glVertex3f(0.9f,0.85f,0.35f);
    glVertex3f(1.0f,0.85f,0.35f);
    glVertex3f(1.0f,0.9f,0.35f);

    glVertex3f(0.9f,0.9f,0.3f);
    glVertex3f(1.0f,0.9f,0.3f);
    glVertex3f(1.0f,0.85f,0.3f);
    glVertex3f(0.9f,0.85f,0.3f);

    glVertex3f(0.9f,0.9f,0.3f);
    glVertex3f(0.9f,0.9f,0.35f);
    glVertex3f(1.0f,0.9f,0.35f);
    glVertex3f(1.0f,0.9f,0.3f);

    glVertex3f(1.0f,0.85f,0.3f);
    glVertex3f(1.0f,0.85f,0.35f);
    glVertex3f(0.9f,0.85f,0.35f);
    glVertex3f(0.9f,0.85f,0.3f);

    glEnd();

}

void minarLeft2(){
    glBegin(GL_QUADS);

    glColor3f(1.0,1.0,1.0);

    glVertex3f(0.55f,0.32f,0.25f);
    glVertex3f(0.55f,0.32f,0.3f);
    glVertex3f(0.65f,0.32f,0.3f);
    glVertex3f(0.65f,0.32f,0.25f);

    glVertex3f(0.55f,0.3f,0.3f);
    glVertex3f(0.55f,0.3f,0.25f);
    glVertex3f(0.65f,0.3f,0.25f);
    glVertex3f(0.65f,0.3f,0.3f);

    glVertex3f(0.55f,0.32f,0.3f);
    glVertex3f(0.55f,0.3f,0.3f);
    glVertex3f(0.65f,0.3f,0.3f);
    glVertex3f(0.65f,0.32f,0.3f);

    glVertex3f(0.55f,0.32f,0.25f);
    glVertex3f(0.65f,0.32f,0.25f);
    glVertex3f(0.65f,0.3f,0.25f);
    glVertex3f(0.55f,0.3f,0.25f);

    glVertex3f(0.55f,0.3f,0.3f);
    glVertex3f(0.55f,0.32f,0.3f);
    glVertex3f(0.55f,0.32f,0.25f);
    glVertex3f(0.55f,0.3f,0.25f);

    glVertex3f(0.65f,0.32f,0.3f);
    glVertex3f(0.65f,0.3f,0.3f);
    glVertex3f(0.65f,0.3f,0.25f);
    glVertex3f(0.65f,0.32f,0.25f);
    /////////////////////////

    glVertex3f(0.55f,0.65f,0.25f);
    glVertex3f(0.55f,0.32f,0.25f);
    glVertex3f(0.55f,0.32f,0.3f);
    glVertex3f(0.55f,0.65f,0.3f);

    glVertex3f(0.57f,0.65f,0.3f);
    glVertex3f(0.57f,0.65f,0.3f);
    glVertex3f(0.57f,0.32f,0.3f);
    glVertex3f(0.57f,0.32f,0.3f);

    glVertex3f(0.55f,0.65f,0.3f);
    glVertex3f(0.55f,0.32f,0.3f);
    glVertex3f(0.57f,0.32f,0.3f);
    glVertex3f(0.57f,0.65f,0.3f);

    glVertex3f(0.55f,0.65f,0.25f);
    glVertex3f(0.57f,0.65f,0.25f);
    glVertex3f(0.57f,0.32f,0.25f);
    glVertex3f(0.55f,0.32f,0.25f);

    glVertex3f(0.55f,0.65f,0.25f);
    glVertex3f(0.55f,0.65f,0.3f);
    glVertex3f(0.57f,0.65f,0.3f);
    glVertex3f(0.57f,0.65f,0.25f);

    glVertex3f(0.57f,0.32f,0.25f);
    glVertex3f(0.57f,0.32f,0.3f);
    glVertex3f(0.55f,0.32f,0.3f);
    glVertex3f(0.55f,0.32f,0.25f);
/////////////////////////////////////////

    glVertex3f(0.63f,0.65f,0.25f);
    glVertex3f(0.63f,0.65f,0.3f);
    glVertex3f(0.65f,0.65f,0.3f);
    glVertex3f(0.65f,0.65f,0.25f);

    glVertex3f(0.65f,0.32f,0.25f);
    glVertex3f(0.65f,0.32f,0.3f);
    glVertex3f(0.63f,0.32f,0.3f);
    glVertex3f(0.63f,0.32f,0.25f);

    glVertex3f(0.63f,0.65f,0.25f);
    glVertex3f(0.63f,0.32f,0.25f);
    glVertex3f(0.63f,0.32f,0.3f);
    glVertex3f(0.63f,0.65f,0.3f);

    glVertex3f(0.65f,0.65f,0.25f);
    glVertex3f(0.65f,0.65f,0.3f);
    glVertex3f(0.65f,0.32f,0.3f);
    glVertex3f(0.65f,0.32f,0.25f);

    glVertex3f(0.65f,0.65f,0.3f);
    glVertex3f(0.63f,0.65f,0.3f);
    glVertex3f(0.63f,0.32f,0.3f);
    glVertex3f(0.65f,0.32f,0.3f);

    glVertex3f(0.63f,0.65f,0.25f);
    glVertex3f(0.65f,0.65f,0.25f);
    glVertex3f(0.65f,0.32f,0.25f);
    glVertex3f(0.63f,0.32f,0.25f);
//////////////////////////////////////////////////////

    glVertex3f(0.57f,0.65f,0.25f);
    glVertex3f(0.57f,0.65f,0.3f);
    glVertex3f(0.63f,0.65f,0.3f);
    glVertex3f(0.63f,0.65f,0.25f);

    glVertex3f(0.57f,0.63f,0.25f);
    glVertex3f(0.63f,0.63f,0.25f);
    glVertex3f(0.63f,0.63f,0.3f);
    glVertex3f(0.57f,0.63f,0.3f);

    glVertex3f(0.57f,0.65f,0.25f);
    glVertex3f(0.57f,0.63f,0.25f);
    glVertex3f(0.57f,0.63f,0.3f);
    glVertex3f(0.57f,0.65f,0.3f);

    glVertex3f(0.63f,0.65f,0.25f);
    glVertex3f(0.63f,0.65f,0.3f);
    glVertex3f(0.63f,0.63f,0.3f);
    glVertex3f(0.63f,0.63f,0.25f);

    glVertex3f(0.57f,0.65f,0.3f);
    glVertex3f(0.57f,0.63f,0.3f);
    glVertex3f(0.63f,0.63f,0.3f);
    glVertex3f(0.63f,0.65f,0.3f);

    glVertex3f(0.57f,0.63f,0.25f);
    glVertex3f(0.57f,0.65f,0.25f);
    glVertex3f(0.63f,0.65f,0.25f);
    glVertex3f(0.63f,0.63f,0.25f);

    glEnd();

}

void minarRight2(){
    glBegin(GL_QUADS);

    glColor3f(1.0,1.0,1.0);

    glVertex3f(1.1f,0.32f,0.25f);
    glVertex3f(1.1f,0.32f,0.3f);
    glVertex3f(1.2f,0.32f,0.3f);
    glVertex3f(1.2f,0.32f,0.25f);

    glVertex3f(1.1f,0.3f,0.3f);
    glVertex3f(1.1f,0.3f,0.25f);
    glVertex3f(1.2f,0.3f,0.25f);
    glVertex3f(1.2f,0.3f,0.3f);

    glVertex3f(1.1f,0.32f,0.3f);
    glVertex3f(1.1f,0.3f,0.3f);
    glVertex3f(1.2f,0.3f,0.3f);
    glVertex3f(1.2f,0.32f,0.3f);

    glVertex3f(1.1f,0.32f,0.25f);
    glVertex3f(1.2f,0.32f,0.25f);
    glVertex3f(1.2f,0.3f,0.25f);
    glVertex3f(1.1f,0.3f,0.25f);

    glVertex3f(1.1f,0.3f,0.3f);
    glVertex3f(1.1f,0.32f,0.3f);
    glVertex3f(1.1f,0.32f,0.25f);
    glVertex3f(1.1f,0.3f,0.25f);

    glVertex3f(1.2f,0.32f,0.3f);
    glVertex3f(1.2f,0.3f,0.3f);
    glVertex3f(1.2f,0.3f,0.25f);
    glVertex3f(1.2f,0.32f,0.25f);
    /////////////////////////

    glVertex3f(1.1f,0.65f,0.25f);
    glVertex3f(1.1f,0.32f,0.25f);
    glVertex3f(1.1f,0.32f,0.3f);
    glVertex3f(1.1f,0.65f,0.3f);

    glVertex3f(1.12f,0.65f,0.3f);
    glVertex3f(1.12f,0.65f,0.3f);
    glVertex3f(1.12f,0.32f,0.3f);
    glVertex3f(1.12f,0.32f,0.3f);

    glVertex3f(1.1f,0.65f,0.3f);
    glVertex3f(1.1f,0.32f,0.3f);
    glVertex3f(1.12f,0.32f,0.3f);
    glVertex3f(1.12f,0.65f,0.3f);

    glVertex3f(1.1f,0.65f,0.25f);
    glVertex3f(1.12f,0.65f,0.25f);
    glVertex3f(1.12f,0.32f,0.25f);
    glVertex3f(1.1f,0.32f,0.25f);

    glVertex3f(1.1f,0.65f,0.25f);
    glVertex3f(1.1f,0.65f,0.3f);
    glVertex3f(1.12f,0.65f,0.3f);
    glVertex3f(1.12f,0.65f,0.25f);

    glVertex3f(1.12f,0.32f,0.25f);
    glVertex3f(1.12f,0.32f,0.3f);
    glVertex3f(1.1f,0.32f,0.3f);
    glVertex3f(1.1f,0.32f,0.25f);
/////////////////////////////////////////

    glVertex3f(1.18f,0.65f,0.25f);
    glVertex3f(1.18f,0.65f,0.3f);
    glVertex3f(1.2f,0.65f,0.3f);
    glVertex3f(1.2f,0.65f,0.25f);

    glVertex3f(1.2f,0.32f,0.25f);
    glVertex3f(1.2f,0.32f,0.3f);
    glVertex3f(1.18f,0.32f,0.3f);
    glVertex3f(1.18f,0.32f,0.25f);

    glVertex3f(1.18f,0.65f,0.25f);
    glVertex3f(1.18f,0.32f,0.25f);
    glVertex3f(1.18f,0.32f,0.3f);
    glVertex3f(1.18f,0.65f,0.3f);

    glVertex3f(1.2f,0.65f,0.25f);
    glVertex3f(1.2f,0.65f,0.3f);
    glVertex3f(1.2f,0.32f,0.3f);
    glVertex3f(1.2f,0.32f,0.25f);

    glVertex3f(1.2f,0.65f,0.3f);
    glVertex3f(1.18f,0.65f,0.3f);
    glVertex3f(1.18f,0.32f,0.3f);
    glVertex3f(1.2f,0.32f,0.3f);

    glVertex3f(1.18f,0.65f,0.25f);
    glVertex3f(1.2f,0.65f,0.25f);
    glVertex3f(1.2f,0.32f,0.25f);
    glVertex3f(1.18f,0.32f,0.25f);
//////////////////////////////////////////////////////

    glVertex3f(1.12f,0.65f,0.25f);
    glVertex3f(1.12f,0.65f,0.3f);
    glVertex3f(1.18f,0.65f,0.3f);
    glVertex3f(1.18f,0.65f,0.25f);

    glVertex3f(1.12f,0.63f,0.25f);
    glVertex3f(1.18f,0.63f,0.25f);
    glVertex3f(1.18f,0.63f,0.3f);
    glVertex3f(1.12f,0.63f,0.3f);

    glVertex3f(1.12f,0.65f,0.25f);
    glVertex3f(1.12f,0.63f,0.25f);
    glVertex3f(1.12f,0.63f,0.3f);
    glVertex3f(1.12f,0.65f,0.3f);

    glVertex3f(1.18f,0.65f,0.25f);
    glVertex3f(1.18f,0.65f,0.3f);
    glVertex3f(1.18f,0.63f,0.3f);
    glVertex3f(1.18f,0.63f,0.25f);

    glVertex3f(1.12f,0.65f,0.3f);
    glVertex3f(1.12f,0.63f,0.3f);
    glVertex3f(1.18f,0.63f,0.3f);
    glVertex3f(1.18f,0.65f,0.3f);

    glVertex3f(1.12f,0.63f,0.25f);
    glVertex3f(1.12f,0.65f,0.25f);
    glVertex3f(1.18f,0.65f,0.25f);
    glVertex3f(1.18f,0.63f,0.25f);

    glEnd();

}

void minarLeft1(){
    glBegin(GL_QUADS);

    glColor3f(1.0,1.0,1.0);

    glVertex3f(0.4f,0.32f,0.3f);
    glVertex3f(0.4f,0.32f,0.35f);
    glVertex3f(0.5f,0.32f,0.35f);
    glVertex3f(0.5f,0.32f,0.3f);

    glVertex3f(0.4f,0.3f,0.35f);
    glVertex3f(0.4f,0.3f,0.3f);
    glVertex3f(0.5f,0.3f,0.3f);
    glVertex3f(0.5f,0.3f,0.35f);

    glVertex3f(0.4f,0.32f,0.35f);
    glVertex3f(0.4f,0.3f,0.35f);
    glVertex3f(0.5f,0.3f,0.35f);
    glVertex3f(0.5f,0.32f,0.35f);

    glVertex3f(0.4f,0.32f,0.3f);
    glVertex3f(0.5f,0.32f,0.3f);
    glVertex3f(0.5f,0.3f,0.3f);
    glVertex3f(0.4f,0.3f,0.3f);

    glVertex3f(0.4f,0.3f,0.35f);
    glVertex3f(0.4f,0.32f,0.35f);
    glVertex3f(0.4f,0.32f,0.3f);
    glVertex3f(0.4f,0.3f,0.3f);

    glVertex3f(0.5f,0.32f,0.35f);
    glVertex3f(0.5f,0.3f,0.35f);
    glVertex3f(0.5f,0.3f,0.3f);
    glVertex3f(0.5f,0.32f,0.3f);
    /////////////////////////

    glVertex3f(0.4f,0.57f,0.3f);
    glVertex3f(0.4f,0.32f,0.3f);
    glVertex3f(0.4f,0.32f,0.35f);
    glVertex3f(0.4f,0.57f,0.35f);

    glVertex3f(0.42f,0.57f,0.35f);
    glVertex3f(0.42f,0.57f,0.35f);
    glVertex3f(0.42f,0.32f,0.35f);
    glVertex3f(0.42f,0.32f,0.35f);

    glVertex3f(0.4f,0.57f,0.35f);
    glVertex3f(0.4f,0.32f,0.35f);
    glVertex3f(0.42f,0.32f,0.35f);
    glVertex3f(0.42f,0.57f,0.35f);

    glVertex3f(0.4f,0.57f,0.3f);
    glVertex3f(0.42f,0.57f,0.3f);
    glVertex3f(0.42f,0.32f,0.3f);
    glVertex3f(0.4f,0.32f,0.3f);

    glVertex3f(0.4f,0.57f,0.3f);
    glVertex3f(0.4f,0.57f,0.35f);
    glVertex3f(0.42f,0.57f,0.35f);
    glVertex3f(0.42f,0.57f,0.3f);

    glVertex3f(0.42f,0.32f,0.3f);
    glVertex3f(0.42f,0.32f,0.35f);
    glVertex3f(0.4f,0.32f,0.35f);
    glVertex3f(0.4f,0.32f,0.3f);
/////////////////////////////////////////

    glVertex3f(0.48f,0.57f,0.3f);
    glVertex3f(0.48f,0.57f,0.35f);
    glVertex3f(0.5f,0.57f,0.35f);
    glVertex3f(0.5f,0.57f,0.3f);

    glVertex3f(0.5f,0.32f,0.3f);
    glVertex3f(0.5f,0.32f,0.35f);
    glVertex3f(0.48f,0.32f,0.35f);
    glVertex3f(0.48f,0.32f,0.3f);

    glVertex3f(0.48f,0.57f,0.3f);
    glVertex3f(0.48f,0.32f,0.3f);
    glVertex3f(0.48f,0.32f,0.35f);
    glVertex3f(0.48f,0.57f,0.35f);

    glVertex3f(0.5f,0.57f,0.3f);
    glVertex3f(0.5f,0.57f,0.35f);
    glVertex3f(0.5f,0.32f,0.35f);
    glVertex3f(0.5f,0.32f,0.3f);

    glVertex3f(0.5f,0.57f,0.35f);
    glVertex3f(0.48f,0.57f,0.35f);
    glVertex3f(0.48f,0.32f,0.35f);
    glVertex3f(0.5f,0.32f,0.35f);

    glVertex3f(0.48f,0.57f,0.3f);
    glVertex3f(0.5f,0.57f,0.3f);
    glVertex3f(0.5f,0.32f,0.3f);
    glVertex3f(0.48f,0.32f,0.3f);
//////////////////////////////////////////////////////

    glVertex3f(0.42f,0.57f,0.3f);
    glVertex3f(0.42f,0.57f,0.35f);
    glVertex3f(0.48f,0.57f,0.35f);
    glVertex3f(0.48f,0.57f,0.3f);

    glVertex3f(0.42f,0.55f,0.3f);
    glVertex3f(0.48f,0.55f,0.3f);
    glVertex3f(0.48f,0.55f,0.35f);
    glVertex3f(0.42f,0.55f,0.35f);

    glVertex3f(0.42f,0.57f,0.3f);
    glVertex3f(0.42f,0.55f,0.3f);
    glVertex3f(0.42f,0.55f,0.35f);
    glVertex3f(0.42f,0.57f,0.35f);

    glVertex3f(0.48f,0.57f,0.3f);
    glVertex3f(0.48f,0.57f,0.35f);
    glVertex3f(0.48f,0.55f,0.35f);
    glVertex3f(0.48f,0.55f,0.3f);

    glVertex3f(0.42f,0.57f,0.35f);
    glVertex3f(0.42f,0.55f,0.35f);
    glVertex3f(0.48f,0.55f,0.35f);
    glVertex3f(0.48f,0.57f,0.35f);

    glVertex3f(0.42f,0.55f,0.3f);
    glVertex3f(0.42f,0.57f,0.3f);
    glVertex3f(0.48f,0.57f,0.3f);
    glVertex3f(0.48f,0.55f,0.3f);

    glEnd();

}

void minarRight1(){

    glBegin(GL_QUADS);

    glColor3f(1.0,1.0,1.0);

    glVertex3f(1.25f,0.32f,0.3f);
    glVertex3f(1.25f,0.32f,0.35f);
    glVertex3f(1.35f,0.32f,0.35f);
    glVertex3f(1.35f,0.32f,0.3f);

    glVertex3f(1.25f,0.3f,0.35f);
    glVertex3f(1.25f,0.3f,0.3f);
    glVertex3f(1.35f,0.3f,0.3f);
    glVertex3f(1.35f,0.3f,0.35f);

    glVertex3f(1.25f,0.32f,0.35f);
    glVertex3f(1.25f,0.3f,0.35f);
    glVertex3f(1.35f,0.3f,0.35f);
    glVertex3f(1.35f,0.32f,0.35f);

    glVertex3f(1.25f,0.32f,0.3f);
    glVertex3f(1.35f,0.32f,0.3f);
    glVertex3f(1.35f,0.3f,0.3f);
    glVertex3f(1.25f,0.3f,0.3f);

    glVertex3f(1.25f,0.3f,0.35f);
    glVertex3f(1.25f,0.32f,0.35f);
    glVertex3f(1.25f,0.32f,0.3f);
    glVertex3f(1.25f,0.3f,0.3f);

    glVertex3f(1.35f,0.32f,0.35f);
    glVertex3f(1.35f,0.3f,0.35f);
    glVertex3f(1.35f,0.3f,0.3f);
    glVertex3f(1.35f,0.32f,0.3f);
    /////////////////////////

    glVertex3f(1.25f,0.57f,0.3f);
    glVertex3f(1.25f,0.32f,0.3f);
    glVertex3f(1.25f,0.32f,0.35f);
    glVertex3f(1.25f,0.57f,0.35f);

    glVertex3f(1.27f,0.57f,0.35f);
    glVertex3f(1.27f,0.57f,0.35f);
    glVertex3f(1.27f,0.32f,0.35f);
    glVertex3f(1.27f,0.32f,0.35f);

    glVertex3f(1.25f,0.57f,0.35f);
    glVertex3f(1.25f,0.32f,0.35f);
    glVertex3f(1.27f,0.32f,0.35f);
    glVertex3f(1.27f,0.57f,0.35f);

    glVertex3f(1.25f,0.57f,0.3f);
    glVertex3f(1.27f,0.57f,0.3f);
    glVertex3f(1.27f,0.32f,0.3f);
    glVertex3f(1.25f,0.32f,0.3f);

    glVertex3f(1.25f,0.57f,0.3f);
    glVertex3f(1.25f,0.57f,0.35f);
    glVertex3f(1.27f,0.57f,0.35f);
    glVertex3f(1.27f,0.57f,0.3f);

    glVertex3f(1.27f,0.32f,0.3f);
    glVertex3f(1.27f,0.32f,0.35f);
    glVertex3f(1.25f,0.32f,0.35f);
    glVertex3f(1.25f,0.32f,0.3f);
/////////////////////////////////////////

    glVertex3f(1.33f,0.57f,0.3f);
    glVertex3f(1.33f,0.57f,0.35f);
    glVertex3f(1.35f,0.57f,0.35f);
    glVertex3f(1.35f,0.57f,0.3f);

    glVertex3f(1.35f,0.32f,0.3f);
    glVertex3f(1.35f,0.32f,0.35f);
    glVertex3f(1.33f,0.32f,0.35f);
    glVertex3f(1.33f,0.32f,0.3f);

    glVertex3f(1.33f,0.57f,0.3f);
    glVertex3f(1.33f,0.32f,0.3f);
    glVertex3f(1.33f,0.32f,0.35f);
    glVertex3f(1.33f,0.57f,0.35f);

    glVertex3f(1.35f,0.57f,0.3f);
    glVertex3f(1.35f,0.57f,0.35f);
    glVertex3f(1.35f,0.32f,0.35f);
    glVertex3f(1.35f,0.32f,0.3f);

    glVertex3f(1.35f,0.57f,0.35f);
    glVertex3f(1.33f,0.57f,0.35f);
    glVertex3f(1.33f,0.32f,0.35f);
    glVertex3f(1.35f,0.32f,0.35f);

    glVertex3f(1.33f,0.57f,0.3f);
    glVertex3f(1.35f,0.57f,0.3f);
    glVertex3f(1.35f,0.32f,0.3f);
    glVertex3f(1.33f,0.32f,0.3f);
//////////////////////////////////////////////////////

    glVertex3f(1.27f,0.57f,0.3f);
    glVertex3f(1.27f,0.57f,0.35f);
    glVertex3f(1.33f,0.57f,0.35f);
    glVertex3f(1.33f,0.57f,0.3f);

    glVertex3f(1.27f,0.55f,0.3f);
    glVertex3f(1.33f,0.55f,0.3f);
    glVertex3f(1.33f,0.55f,0.35f);
    glVertex3f(1.27f,0.55f,0.35f);

    glVertex3f(1.27f,0.57f,0.3f);
    glVertex3f(1.27f,0.55f,0.3f);
    glVertex3f(1.27f,0.55f,0.35f);
    glVertex3f(1.27f,0.57f,0.35f);

    glVertex3f(1.33f,0.57f,0.3f);
    glVertex3f(1.33f,0.57f,0.35f);
    glVertex3f(1.33f,0.55f,0.35f);
    glVertex3f(1.33f,0.55f,0.3f);

    glVertex3f(1.27f,0.57f,0.35f);
    glVertex3f(1.27f,0.55f,0.35f);
    glVertex3f(1.33f,0.55f,0.35f);
    glVertex3f(1.33f,0.57f,0.35f);

    glVertex3f(1.27f,0.55f,0.3f);
    glVertex3f(1.27f,0.57f,0.3f);
    glVertex3f(1.33f,0.57f,0.3f);
    glVertex3f(1.33f,0.55f,0.3f);

    glEnd();

}

void circle(){
    glColor3f(1,0,0);
    glScalef(0.1f,0.1f,0.05f);
    glTranslatef(8.75f,5.2f,2.3f);
    glutSolidSphere(2,20,20);


}





static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

float cx=0,cy=.3,cz=1.5, ox=0,oy=0,oz=0, hp_x=0, hp_y=1, hp_z=0;
float angel=0, angel1=0, dis=cz,  disHead=cz;
float angelHead = 0;

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 2500.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,1,1);

    glPushMatrix();
        glTranslatef(-0.8f,-0.5f,-1.4f);
       // glRotated(60,-6.0,0.0,0.0);
        //glRotated(a,0,1,0);
        gluLookAt(cx,cy,cz,ox,oy,oz,hp_x,hp_y,hp_z);
        glBindTexture(GL_TEXTURE_2D,2);
        glEnable(GL_TEXTURE_2D);
        wall1();
        wall2();
        wall3();
        wall4();
        glDisable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D,4);
        glEnable(GL_TEXTURE_2D);
        tablePlane();
        tableLeg1();
        tableLeg2();
        tableLeg3();
        tableLeg4();
        glDisable(GL_TEXTURE_2D);
        minarMiddle();
        minarLeft2();
        minarRight2();
        minarLeft1();
        minarRight1();
        circle();

    glPopMatrix();



    glutSwapBuffers();
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'q':
            exit(0);
            break;

//zoom in ---zoom out
        case 'Z':
            cx=cx+.08*cx;
            cz=cz+.08*cz;
            break;

        case 'z':
            cx=cx-.08*cx;
            cz=cz-.08*cz;
            break;

// rotation around the object
        case 'A':
            angel+=2;
            dis=sqrt(cx*cx+cz*cz);
            cx=dis*sin(angel*3.1416/180.0);
            cz=dis*cos(angel*3.1416/180.0);
            cout<<dis<<" "<<cx<<" "<<cz<<endl;
            break;

        case 'a':
            angel-=2;
            dis=sqrt(cx*cx+cz*cz);
            cx=dis*sin(angel*3.1416/180.0);
            cz=dis*cos(angel*3.1416/180.0);
            cout<<dis<<" "<<cx<<" "<<cz<<endl;
            break;

//pitch rotate around y axis
        case 'P':
            {

            angel1 = -5;
            double rdn = (angel1*3.1416)/180;
            double t1 = ox*cos(rdn)+oz*sin(rdn)-(cx-ox)*cos(rdn)-(cz-oz)*sin(rdn)+cx-ox;
            double t2 = -ox*sin(rdn)+oz*cos(rdn)+sin(rdn)*(cx-ox)-(cz-oz)*cos(rdn)+cz-oz;
            ox=t1;
            oz=t2;
            }
            break;

 //pitch rotate around y axis

        case 'p':
            {
            angel1 = +5;
            double rdn = (angel1*3.1416)/180;
            double t1 = ox*cos(rdn)+oz*sin(rdn)-(cx-ox)*cos(rdn)-(cz-oz)*sin(rdn)+cx-ox;
            double t2 = -ox*sin(rdn)+oz*cos(rdn)+sin(rdn)*(cx-ox)-(cz-oz)*cos(rdn)+cz-oz;
            ox=t1;
            oz=t2;
            }
            break;

    //yaw rotate around z axis
        case 'Y':
            {
            angel1 = +5;
            double rdn = (angel1*3.1416)/180;
            double t1 = hp_x*cos(rdn)-hp_y*sin(rdn);
            double t2 = hp_x*sin(rdn)+cos(rdn)*hp_y;
            hp_x=t1;
            hp_y=t2;
            }
            break;

    //yaw rotate around z axis
        case 'y':
            {
            angel1 = -5;
            double rdn = (angel1*3.1416)/180;
            double t1 = hp_x*cos(rdn)-hp_y*sin(rdn);
            double t2 = hp_x*sin(rdn)+cos(rdn)*hp_y;
            hp_x=t1;
            hp_y=t2;
            }
            break;

//roll rotate around x axis
        case 'R':
            {
            angel1 = +5;
            double rdn = (angel1*3.1416)/180;
            double t1 = oy*cos(rdn)-oz*sin(rdn)-(cy-oy)*cos(rdn)+(cz-oz)*sin(rdn)+cy-oy;
            double t2 = oy*sin(rdn)+cos(rdn)*oz-sin(rdn)*(cy-oy)-(cz-oz)*cos(rdn)+cz-oz;
            oy=t1;
            oz=t2;
            }
            break;

//roll rotate around x axis

        case 'r':
           {
           angel1 = -5;
           double rdn = (angel1*3.1416)/180;
           double t1 = oy*cos(rdn)-oz*sin(rdn)-(cy-oy)*cos(rdn)+(cz-oz)*sin(rdn)+cy-oy;
           double t2 = oy*sin(rdn)+cos(rdn)*oz-sin(rdn)*(cy-oy)-(cz-oz)*cos(rdn)+cz-oz;
           oy=t1;
           oz=t2;
           }
           break;



    }


    glutPostRedisplay();

}

static void idle(void)
{
    glutPostRedisplay();
}

GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat light_ambient[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_position[] = { 2.0, 25.0, 3.0, 1.0 };
/*
const GLfloat mat_ambiente[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffusee[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_speculare[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininesse[] = { 100.0f };
*/
/* Program entry point */
void Init()
{
	glEnable(GL_TEXTURE_2D);


    pix[0].makeCheckImage();
	pix[0].setTexture(1);

	pix[1].readBMPFile("D:\\4-2\\Slides\\CG Lab\\lab4_4208 texturing\\texturing with image 2\\teapot.bmp");
	pix[1].setTexture(2);

	pix[2].readBMPFile("D:\\4-2\\Slides\\CG Lab\\lab4_4208 texturing\\texturing with image 2\\jack.bmp");
	pix[2].setTexture(3);

	pix[3].readBMPFile("D:\\4-2\\Slides\\CG Lab\\lab4_4208 texturing\\texturing with image 2\\table.bmp");
	pix[3].setTexture(4);

    pix[4].readBMPFile("D:\\4-2\\Slides\\CG Lab\\lab4_4208 texturing\\texturing with image 2\\cone.bmp");
	pix[4].setTexture(5);



}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000,800);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Shohid Minar");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(0,0,0,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    //glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   /* glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambiente);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffusee);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_speculare);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininesse);
*/
    Init();
    glutMainLoop();

    return EXIT_SUCCESS;
}
