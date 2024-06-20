#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<string.h>
//#include <stdlib.h>
int turn;
void doort(int v);
GLfloat xx = 0.0, zz = 0.0,xx1=1;
float lx = 0.0f, lz = -1.0f , angle=0.0;
static GLdouble viewer[] = { 0.0, 0.2, 4.2 };
static GLdouble lat[] = { 0.0, 0.2, 0.0 };
GLfloat oo = 0, cr = 0,cb=0,cg=0;
void *font = GLUT_BITMAP_HELVETICA_18;
float i,theta;
void output(float x, float y, char *s)
{
	glRasterPos2f(x, y);
	for (unsigned int i = 0; i<strlen(s); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
	}
}

void createBase(double inclination) {
    // right edge
    glColor3d(255.0 / 255, 0, 0);
    glPushMatrix();
    glTranslated(0, 0, 0);
    glRotatef(inclination, 0, 0, 1);
    glScaled(1, 0.03, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    // right base edge
    glPushMatrix();
    glTranslated(-0.707 + 0.246, -0.351, 0);
    glScaled(0.23, 0.03, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    // right top edge
    glPushMatrix();
    glTranslated(0.46, 0.35, 0);
    glScaled(-0.23, 0.03, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    // slide part
    glColor3d(5.0 / 255, 47.0 / 255, 51.0 / 255);
    glPushMatrix();
    glTranslated(0, 0, -0.1);
    glRotatef(inclination, 0, 0, 1);
    glScaled(1, 0.001, -0.2);
    glutSolidCube(1);
    glPopMatrix();

    // slide base part
    glPushMatrix();
    glTranslated(-0.707 + 0.246, -0.351, -0.1);
    glScaled(0.23, 0.001, -0.2);
    glutSolidCube(1);
    glPopMatrix();

    // slide top part
    glPushMatrix();
    glTranslated(0.46, 0.35, -0.1);
    glScaled(0.23, 0.001, -0.2);
    glutSolidCube(1);
    glPopMatrix();

    // left edge
    glPushMatrix();
    glTranslated(0, 0, -0.2);
    glRotatef(inclination, 0, 0, 1);
    glScaled(1, 0.03, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    // left base edge
    glPushMatrix();
    glTranslated(-0.707 + 0.246, -0.351, -0.2);
    glScaled(0.23, 0.03, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    // left top edge
    glPushMatrix();
    glTranslated(0.46, 0.35, -0.2);
    glScaled(-0.23, 0.03, 0.01);
    glutSolidCube(1);
    glPopMatrix();
}

void createStairs() {
    // right stairs edge
    glColor3d(255.0 / 255, 0, 0);
    glPushMatrix();
    glTranslated(0.56, -0.01, 0);
    glScaled(0.03, 0.71, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    // left stairs edge
    glPushMatrix();
    glTranslated(0.56, -0.01, -0.2);
    glScaled(0.03, 0.71, 0.01);
    glutSolidCube(1);
    glPopMatrix();
}

void createBars() {
    // bar 1
    glColor3d(5.0 / 255.0, 47.0 / 255, 51.0 / 255);
    glPushMatrix();
    glTranslated(0.56, 0.18, -0.1);
    glScaled(0.03, 0.03, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    // bar 2
    glPushMatrix();
    glTranslated(0.56, 0.03, -0.1);
    glScaled(0.03, 0.03, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    // bar 3
    glPushMatrix();
    glTranslated(0.56, -0.12, -0.1);
    glScaled(0.03, 0.03, 0.2);
    glutSolidCube(1);
    glPopMatrix();

    // bar 4
    glPushMatrix();
    glTranslated(0.56, -0.27, -0.1);
    glScaled(0.03, 0.03, 0.2);
    glutSolidCube(1);
    glPopMatrix();
}

void createFrame() {
    // frame right side
    glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
    for (double i = 0.36; i <= 0.56; i += 0.05) {
        glPushMatrix();
        glTranslated(i, 0.464, 0);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();
    }

    // frame left side
    for (double i = 0.36; i <= 0.56; i += 0.05) {
        glPushMatrix();
        glTranslated(i, 0.464, -0.2);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();
    }

    // frame top
    glPushMatrix();
    glTranslated(0.46, 0.55, 0);
    glScaled(-0.23, 0.03, 0.01);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.46, 0.55, -0.2);
    glScaled(-0.23, 0.03, 0.01);
    glutSolidCube(1);
    glPopMatrix();
}

void drawSlide(double inclination) {
    createBase(inclination);
    createStairs();
    createBars();
    createFrame();
}


void tfs(int v)
{
	cr += 0.01;
	cb += 0.001;
	cg += 0.0001;
	if (cr > 1.0)
	{
		cr = 0;

	}
	 if (cb > 1.0)
	{
		cb = 0;

	}
	if (cg > 1.0)
	{
		cg = 0;

	}

	glutPostRedisplay();
	glutTimerFunc(100, tfs, 0);

}
void drawPerson(float x, float y, float z, float scale, float armAngle) {
    // Draw the body
    glPushMatrix();
    glColor3f(1.0, 0.8, 0.6); // Skin color
    glTranslatef(x, y, z);
    glScalef(0.1 * scale, 0.3 * scale, 0.1 * scale);
    glutSolidCube(1.0);
    glPopMatrix();

    // Draw the head
    glPushMatrix();
    glColor3f(1.0, 0.8, 0.6); // Skin color
    glTranslatef(x, y + 0.25 * scale, z);
    glutSolidSphere(0.08 * scale, 20, 20);
    glPopMatrix();

    // Draw the arms
    glPushMatrix();
    glColor3f(0.5, 0.35, 0.05); // Arm color
    glTranslatef(x - 0.1 * scale, y, z);
    glRotatef(armAngle, 1, 0, 0);
    glScalef(0.1 * scale, 0.02 * scale, 0.02 * scale);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5, 0.35, 0.05); // Arm color
    glTranslatef(x + 0.1 * scale, y, z);
    glRotatef(-armAngle, 1, 0, 0);
    glScalef(0.1 * scale, 0.02 * scale, 0.02 * scale);
    glutSolidCube(1.0);
    glPopMatrix();

    // Draw the legs
    glPushMatrix();
    glColor3f(0.5, 0.35, 0.05); // Leg color
    glTranslatef(x - 0.05 * scale, y - 0.15 * scale, z);
    glScalef(0.02 * scale, 0.1 * scale, 0.02 * scale);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5, 0.35, 0.05); // Leg color
    glTranslatef(x + 0.05 * scale, y - 0.15 * scale, z);
    glScalef(0.02 * scale, 0.1 * scale, 0.02 * scale);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawStreetLight() {
    // Draw the pole
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3); // Dark grey for the pole
    glTranslatef(0.0, 0.5, 0.0); // Position pole on the ground
    glScalef(0.05, 3.0, 0.05); // Scale the pole to a tall cylinder
    glutSolidCube(1.0); // Draw the pole as a scaled cube
    glPopMatrix();

    // Draw the horizontal arm
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3); // Dark grey for the arm
    glTranslatef(0.0, 2.0, -0.25); // Position the arm at the top of the pole
    glScalef(0.05, 0.05, 0.5); // Scale the arm to a long, thin shape
    glutSolidCube(1.0); // Draw the arm as a scaled cube
    glPopMatrix();

    // Draw the light fixture
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8); // Light grey for the fixture
    glTranslatef(0.0, 2.0, -0.5); // Position the fixture at the end of the arm
    glScalef(0.1, 0.1, 0.1); // Scale the fixture
    glutSolidCube(1.0); // Draw the fixture as a scaled cube
    glPopMatrix();

    // Draw the bulb
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0); // Yellow for the bulb
    glTranslatef(0.0, 1.9, -0.5); // Position the bulb just below the fixture
    glutSolidSphere(0.05, 20, 20); // Draw the bulb as a sphere
    glPopMatrix();
}


void outercover()
{

    glPushMatrix();
    glColor3f( 0.329412,  0.329412,  0.329412);
    glTranslatef(0.0, -0.125, 0.0);
    glScalef(40.0, 0.01, 40.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f( 1,  1,  1);
    glTranslatef(0.0, -0.1, 0.0);
    glScalef(0.02, 0.01, 40);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f( 1,  1,  1);
    glTranslatef(1, -0.1, 0.0);
    glScalef(0.02, 0.01, 40);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f( 1,  1,  1);
    glTranslatef(-1, -0.1, 0.0);
    glScalef(0.02, 0.01, 40);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-3.0, 0, 0.0);

        // Draw house
        glPushMatrix();
        glColor3f(0.5, 0.35, 0.05);
        glTranslatef(0.0, 0.4, 0.0);
        glutSolidCube(1.0);
        glPopMatrix();

        //draw door
        glPushMatrix();
        glColor3f(1.0, 0.5, 0.0);
        glTranslatef(0.38, 0.1, 0.0);
        glScalef(1, 1.5 , 1);
        glutSolidCube(0.25);
        glPopMatrix();

        glPushMatrix();
         glColor3f(0.5, 0.8, 1.0);
        glTranslatef(0.38, 0.5, 0.2);
        glutSolidCube(0.25);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.5, 0.8, 1.0);
        glTranslatef(0.38, 0.5, -0.2);
        glutSolidCube(0.25);
        glPopMatrix();

        // Draw the roof
        glPushMatrix();
        glRotatef(90, 0, 1, 0);
        glColor3f(0.8, 0.0, 0.0);
        glBegin(GL_TRIANGLES);
        // torugao
        glVertex3f(-0.5, 0.9, 0.5);
        glVertex3f(0.5, 0.9, 0.5);
        glVertex3f(0.0, 1.4, 0.5);
        // trougao
        glVertex3f(-0.5, 0.9, -0.5);
        glVertex3f(0.5, 0.9, -0.5);
        glVertex3f(0.0, 1.4, -0.5);
        glEnd();

        glBegin(GL_QUADS);
        // kvadrat
        glVertex3f(-0.5, 0.9, 0.5);
        glVertex3f(0.0, 1.4, 0.5);
        glVertex3f(0.0, 1.4, -0.5);
        glVertex3f(-0.5, 0.9, -0.5);
        // kvadrat
        glVertex3f(0.5, 0.9, 0.5);
        glVertex3f(0.0, 1.4, 0.5);
        glVertex3f(0.0, 1.4, -0.5);
        glVertex3f(0.5, 0.9, -0.5);
        glEnd();
        glPopMatrix();

        //odzak
        glPushMatrix();
        glColor3f(1.0, 0.5, 0.0);
        glTranslatef(0.0, 1.25, -0.2);
        glScalef(0.5, 1.5 ,0.5);
        glutSolidCube(0.3);
        glPopMatrix();

        //siri deo odzaka
        glPushMatrix();
        glColor3f(1.0, 0.5, 0.0);
        glTranslatef(0.0, 1.45, -0.2);
        glScalef(1, 0.4 ,1 );
        glutSolidCube(0.2);
        glPopMatrix();

        //smoke
        glPushMatrix();
        glColor3f(1, 1, 1.0);
        glTranslatef(0.0, 1.55, -0.24);
        glutSolidSphere(0.075, 20, 20);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(0.0, 1.6, -0.18);
        glutSolidSphere(0.085, 20, 20);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(0.0, 1.7, -0.25);
        glutSolidSphere(0.085, 20, 20);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0, 0, 3);
            glRotatef(90, 0,1,0);
            // Main building
    glPushMatrix();
    glColor3f(0.576471, 0.858824, 0.439216); // Light yellow
    glTranslatef(0.0, 0.5, 0.0);
    glutSolidCube(2.0); // Main building body
    glPopMatrix();

    // Roof for the main building
    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0); // Raise roof to top of the main building
    glColor3f(0.3, 0.3, 0.3); // Dark grey
    glBegin(GL_TRIANGLES);
        // Front face
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(0.0, 1.5, 0.5);

        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(0.0, 1.5, 0.5);
        glVertex3f(-1.0, 1.0, -1.0);

        // Back face
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(0.0, 1.5, -0.5);

        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(0.0, 1.5, -0.5);
        glVertex3f(-1.0, 1.0, 1.0);
        glEnd();

        glBegin(GL_QUADS);
        // Right face
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(0.0, 1.5, -0.5);
        glVertex3f(0.0, 1.5, 0.5);

        // Left face
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(0.0, 1.5, -0.5);
        glVertex3f(0.0, 1.5, 0.5);
        glEnd();
        glPopMatrix();

    // Windows on the main building
    glColor3f(0.5, 0.8, 1.0); // Light blue
    float windowSize = 0.2;
    float windowGap = 0.5;

    // Draw rows of windows on one side
    for (float y = 0.4; y <= 0.8; y += windowGap) {
        for (float x = -0.8; x <= 0.8; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 1.01);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    for (float y = 0.8; y <= 0.9; y += windowGap) {
        for (float x = -0.8; x <= 0.8; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 1.01);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    for (float y = 1.2; y <= 1.6; y += windowGap) {
        for (float x = -0.8; x <= 0.8; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 1.01);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    // First additional floor (right wing)
    glPushMatrix();
    glColor3f(0.576471, 0.858824, 0.439216); // Light yellow
    glTranslatef(1.5, 0.5, 0);
    glScalef(1.0, 2.8, 2.2);
    glutSolidCube(1.0); // Right wing
    glPopMatrix();

    // Roof for the right wing
    glPushMatrix();
    glTranslatef(0, 0.9, 0.0); // Raise roof to top of the right wing
    glColor3f(0.3, 0.3, 0.3); // Dark grey
    // Front face
        glBegin(GL_TRIANGLES);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(2.0, 1.0, 1.0);
        glVertex3f(1.5, 1.5, 0.5);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(2.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(1.5, 1.5, 0.5);
        glEnd();

        // Back face
        glBegin(GL_TRIANGLES);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(2.0, 1.0, -1.0);
        glVertex3f(1.5, 1.5, -0.5);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(2.0, 1.0, -1.0);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(1.5, 1.5, -0.5);
        glEnd();

        // Right face
        glBegin(GL_QUADS);
        glVertex3f(2.0, 1.0, 1.0);
        glVertex3f(2.0, 1.0, -1.0);
        glVertex3f(1.5, 1.5, -0.5);
        glVertex3f(1.5, 1.5, 0.5);
        glEnd();

        // Left face
        glBegin(GL_QUADS);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(1.5, 1.5, -0.5);
        glVertex3f(1.5, 1.5, 0.5);
        glEnd();

    glPopMatrix();

    // Second additional floor (left wing)
    glPushMatrix();
    glColor3f(0.576471, 0.858824, 0.439216); // Light yellow
    glTranslatef(-1.5, 0.5, 0);
    glScalef(1.0, 2.8, 2.2);
    glutSolidCube(1.0); // Left wing
    glPopMatrix();

    // Roof for the left wing
    glPushMatrix();
    glTranslatef(0, 0.9, 0.0); // Raise roof to top of the left wing
    glColor3f(0.3, 0.3, 0.3); // Dark grey
    // Front face
        glBegin(GL_TRIANGLES);
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(-2.0, 1.0, 1.0);
        glVertex3f(-1.5, 1.5, 0.5);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(-2.0, 1.0, 1.0);
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(-1.5, 1.5, 0.5);
        glEnd();

        // Back face
        glBegin(GL_TRIANGLES);
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(-2.0, 1.0, -1.0);
        glVertex3f(-1.5, 1.5, -0.5);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(-2.0, 1.0, -1.0);
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(-1.5, 1.5, -0.5);
        glEnd();

        // Right face
        glBegin(GL_QUADS);
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(-1.5, 1.5, -0.5);
        glVertex3f(-1.5, 1.5, 0.5);
        glEnd();

        // Left face
        glBegin(GL_QUADS);
        glVertex3f(-2.0, 1.0, 1.0);
        glVertex3f(-2.0, 1.0, -1.0);
        glVertex3f(-1.5, 1.5, -0.5);
        glVertex3f(-1.5, 1.5, 0.5);
        glEnd();
    glEnd();
    glPopMatrix();

        glPopMatrix();

    glPopMatrix();

    //drvo
    glPushMatrix();
    glTranslatef(-2.6, 0, 0.5);
    GLUquadricObj *stablo = gluNewQuadric();

    glPushMatrix();
    glColor3f(0.5, 0.35, 0.05); // Brown color for the trunk
    glTranslatef(0.5, -0.1, -1.7);
    glRotatef(180, 0, 1, 1);
    gluCylinder(stablo, 0.04, 0.04, 0.7, 20, 20);
    glPopMatrix();

    // Canopy - large leaves
    glPushMatrix();
    glColor3f(0.0, 0.8, 0.0); // Green color for the leaves
    glTranslatef(0.5, 0.75, -1.7);
    glScalef(0.5, 1, 0.5);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    // Canopy - medium leaves
    glPushMatrix();
    glColor3f(0.0, 0.8, 0.0); // Green color for the leaves
    glTranslatef(0.5, 1.0, -1.7);
    glScalef(0.4, 1, 0.4);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    // Canopy - small leaves
    glPushMatrix();
    glColor3f(0.0, 0.8, 0.0); // Green color for the leaves
    glTranslatef(0.5, 1.2, -1.7);
    glScalef(0.3, 1, 0.3);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    // Additional smaller leaves
    glPushMatrix();
    glColor3f(0.0, 0.8, 0.0); // Green color for the leaves
    glTranslatef(0.3, 0.8, -1.5);
    glutSolidSphere(0.2, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.8, 0.0); // Green color for the leaves
    glTranslatef(0.5, 1, -1.6);
    glutSolidSphere(0.25, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.8, 0.0); // Green color for the leaves
    glTranslatef(0.7, 1.1, -1.9);
    glutSolidSphere(0.3, 10, 10);
    glPopMatrix();

    glPopMatrix();



    glPushMatrix();
    glTranslatef(-3.0, 0.0, -3.0);
    glRotatef(90,0,1,0); // Position the mosque relative to the house

    // Main mosque building
    glPushMatrix();
    glColor3f(0.85, 0.85, 0.1); // Yellow color for the main building
    glTranslatef(0.0, 0.5, 0.0);
    glutSolidCube(2.0); // Main mosque building body
    glPopMatrix();

    // Dome on top of the mosque
    glPushMatrix();
    glColor3f(0.7, 0.0, 0.0); // Red color for the dome
    glTranslatef(0.0, 1.5, 0.0);
    glutSolidSphere(0.8, 20, 20);
    glPopMatrix();

    // Minaret of the mosque
    glPushMatrix();
    glColor3f(0.85, 0.85, 0.1); // Yellow color for the minaret
    glTranslatef(1.5, 0.0, 0.0);
    glScalef(0.3, 6.0, 0.3); // Scale the minaret
    glutSolidCube(1.0);
    glPopMatrix();

    // Top of the minaret
    glPushMatrix();
    glColor3f(0.7, 0.0, 0.0); // Red color for the top of the minaret
    glTranslatef(1.5, 3.2, 0.0);
    glutSolidSphere(0.3, 20, 20);
    glPopMatrix();



    // Draw the door of the mosque
    glPushMatrix();
    glColor3f(0.5, 0.35, 0.05); // Brown color for the door
    glTranslatef(0, 0.25, 1);
    glScalef(0.5, 0.7, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5, 0.35, 0.05); // Brown color for the window
    glTranslatef(-0.4, 1, 1);
    glScalef(0.5, 0.5, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5, 0.35, 0.05); // Brown color for the window
    glTranslatef(0.3, 1, 1);
    glScalef(0.5, 0.5, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    // Second building
    glPushMatrix();
    glTranslatef(3.0, 0.0, 0); // Position the building relative to the house

    // Main building
    glPushMatrix();
    glColor3f(0.372549, 0.623529,  0.623529); // Light yellow
    glTranslatef(0.0, 0.5, 0.0);
    glutSolidCube(2.0); // Main building body
    glPopMatrix();

    // Roof for the main building
    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0); // Raise roof to top of the main building
    glColor3f(0.3, 0.3, 0.3); // Dark grey
    glBegin(GL_TRIANGLES);
        // Front face
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(0.0, 1.5, 0.5);

        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(0.0, 1.5, 0.5);
        glVertex3f(-1.0, 1.0, -1.0);

        // Back face
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(0.0, 1.5, -0.5);

        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(0.0, 1.5, -0.5);
        glVertex3f(-1.0, 1.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
        // Right face
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(0.0, 1.5, -0.5);
        glVertex3f(0.0, 1.5, 0.5);

        // Left face
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(0.0, 1.5, -0.5);
        glVertex3f(0.0, 1.5, 0.5);
    glEnd();
    glPopMatrix();

    // Windows on the main building
    glColor3f(0.5, 0.8, 1.0); // Light blue

    // Draw rows of windows on one side
    for (float y = 0.4; y <= 0.8; y += windowGap) {
        for (float x = -0.8; x <= 0.8; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 1.01);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    for (float y = 0.8; y <= 0.9; y += windowGap) {
        for (float x = -0.8; x <= 0.8; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 1.01);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    for (float y = 1.2; y <= 1.6; y += windowGap) {
        for (float x = -0.8; x <= 0.8; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 1.01);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    glPopMatrix();

    // Third building
    glPushMatrix();
    glTranslatef(5.0, 0.0, 0.0); // Position the building relative to the house

    // Main building
    glPushMatrix();
    glColor3f(0.8, 0.6, 0.2); // Light brown
    glTranslatef(0.0, 0.5, 0.0);
    glutSolidCube(1.5); // Main building body
    glPopMatrix();

    // Roof for the main building
    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0); // Raise roof to top of the main building
    glColor3f(0.5, 0.3, 0.1); // Dark brown
    glBegin(GL_TRIANGLES);
        // Front face
        glVertex3f(-0.75, 0.75, 0.75);
        glVertex3f(0.75, 0.75, 0.75);
        glVertex3f(0.0, 1.25, 0.25);

        glVertex3f(-0.75, 0.75, 0.75);
        glVertex3f(0.0, 1.25, 0.25);
        glVertex3f(-0.75, 0.75, -0.75);

        // Back face
        glVertex3f(-0.75, 0.75, -0.75);
        glVertex3f(0.75, 0.75, -0.75);
        glVertex3f(0.0, 1.25, -0.25);

        glVertex3f(-0.75, 0.75, -0.75);
        glVertex3f(0.0, 1.25, -0.25);
        glVertex3f(-0.75, 0.75, 0.75);
    glEnd();

    glBegin(GL_QUADS);
        // Right face
        glVertex3f(0.75, 0.75, 0.75);
        glVertex3f(0.75, 0.75, -0.75);
        glVertex3f(0.0, 1.25, -0.25);
        glVertex3f(0.0, 1.25, 0.25);

        // Left face
        glVertex3f(-0.75, 0.75, 0.75);
        glVertex3f(-0.75, 0.75, -0.75);
        glVertex3f(0.0, 1.25, -0.25);
        glVertex3f(0.0, 1.25, 0.25);
    glEnd();
    glPopMatrix();

    // Windows on the main building
    glColor3f(0.6, 0.6, 0.8); // Light gray
    windowSize = 0.15;
    windowGap = 0.35;

    // Draw rows of windows on one side
    for (float y = 0.3; y <= 0.6; y += windowGap) {
        for (float x = -0.6; x <= 0.6; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 0.76);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    for (float y = 0.7; y <= 1.0; y += windowGap) {
        for (float x = -0.6; x <= 0.6; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 0.76);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    // Second building
    glPushMatrix();
    glTranslatef(8.0, 0.0, 0); // Position the building relative to the house

    // Main building
    glPushMatrix();
    glColor3f( 0.560784, 0.560784, 0.737255); // Light yellow
    glTranslatef(0.0, 0.5, 0.0);
    //glScalef(1,1.5,1);
    glutSolidCube(2.0); // Main building body
    glPopMatrix();

    // Roof for the main building
    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0); // Raise roof to top of the main building
    glColor3f(0.3, 0.3, 0.3); // Dark grey
    glBegin(GL_TRIANGLES);
        // Front face
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(0.0, 1.5, 0.5);

        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(0.0, 1.5, 0.5);
        glVertex3f(-1.0, 1.0, -1.0);

        // Back face
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(0.0, 1.5, -0.5);

        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(0.0, 1.5, -0.5);
        glVertex3f(-1.0, 1.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
        // Right face
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(0.0, 1.5, -0.5);
        glVertex3f(0.0, 1.5, 0.5);

        // Left face
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(0.0, 1.5, -0.5);
        glVertex3f(0.0, 1.5, 0.5);
    glEnd();
    glPopMatrix();

    // Windows on the main building
    glColor3f(0.5, 0.8, 1.0); // Light blue

    // Draw rows of windows on one side
    for (float y = 0.4; y <= 0.8; y += windowGap) {
        for (float x = -0.8; x <= 0.8; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 1.01);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    for (float y = 0.8; y <= 0.9; y += windowGap) {
        for (float x = -0.8; x <= 0.8; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 1.01);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    for (float y = 1.2; y <= 1.3; y += windowGap) {
        for (float x = -0.8; x <= 0.8; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 1.01);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    glPopMatrix();

    // Third building
    glPushMatrix();
    glTranslatef(11.0, 0.0, 0.0); // Position the building relative to the house

    // Main building
    glPushMatrix();
    glColor3f(0.8, 0.6, 0.2); // Light brown
    glTranslatef(0.0, 0.5, 0.0);
    glutSolidCube(1.5); // Main building body
    glPopMatrix();

    // Roof for the main building
    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0); // Raise roof to top of the main building
    glColor3f(0.5, 0.3, 0.1); // Dark brown
    glBegin(GL_TRIANGLES);
        // Front face
        glVertex3f(-0.75, 0.75, 0.75);
        glVertex3f(0.75, 0.75, 0.75);
        glVertex3f(0.0, 1.25, 0.25);

        glVertex3f(-0.75, 0.75, 0.75);
        glVertex3f(0.0, 1.25, 0.25);
        glVertex3f(-0.75, 0.75, -0.75);

        // Back face
        glVertex3f(-0.75, 0.75, -0.75);
        glVertex3f(0.75, 0.75, -0.75);
        glVertex3f(0.0, 1.25, -0.25);

        glVertex3f(-0.75, 0.75, -0.75);
        glVertex3f(0.0, 1.25, -0.25);
        glVertex3f(-0.75, 0.75, 0.75);
    glEnd();

    glBegin(GL_QUADS);
        // Right face
        glVertex3f(0.75, 0.75, 0.75);
        glVertex3f(0.75, 0.75, -0.75);
        glVertex3f(0.0, 1.25, -0.25);
        glVertex3f(0.0, 1.25, 0.25);

        // Left face
        glVertex3f(-0.75, 0.75, 0.75);
        glVertex3f(-0.75, 0.75, -0.75);
        glVertex3f(0.0, 1.25, -0.25);
        glVertex3f(0.0, 1.25, 0.25);
    glEnd();
    glPopMatrix();

    // Windows on the main building
    glColor3f(0.6, 0.6, 0.8); // Light gray
    windowSize = 0.15;
    windowGap = 0.35;

    // Draw rows of windows on one side
    for (float y = 0.3; y <= 0.6; y += windowGap) {
        for (float x = -0.6; x <= 0.6; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 0.76);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    for (float y = 0.7; y <= 1.0; y += windowGap) {
        for (float x = -0.6; x <= 0.6; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 0.76);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    glPopMatrix();

    // Second building
    glPushMatrix();
    glTranslatef(3.0, 0.0, 0); // Position the building relative to the house

    // Main building
    glPushMatrix();
    glColor3f(1.0, 0.498039, 0.0); // Light yellow
    glTranslatef(0.0, 0.5, 0.0);
    glScalef(1,1.5,1);
    glutSolidCube(2.0); // Main building body
    glPopMatrix();

    // Roof for the main building
    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0); // Raise roof to top of the main building
    glColor3f(0.3, 0.3, 0.3); // Dark grey
    glBegin(GL_TRIANGLES);
        // Front face
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(0.0, 1.5, 0.5);

        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(0.0, 1.5, 0.5);
        glVertex3f(-1.0, 1.0, -1.0);

        // Back face
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(0.0, 1.5, -0.5);

        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(0.0, 1.5, -0.5);
        glVertex3f(-1.0, 1.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
        // Right face
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(0.0, 1.5, -0.5);
        glVertex3f(0.0, 1.5, 0.5);

        // Left face
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(0.0, 1.5, -0.5);
        glVertex3f(0.0, 1.5, 0.5);
    glEnd();
    glPopMatrix();

    // Windows on the main building
    glColor3f(0.5, 0.8, 1.0); // Light blue

    // Draw rows of windows on one side
    for (float y = 0.4; y <= 0.8; y += windowGap) {
        for (float x = -0.8; x <= 0.8; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 1.01);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    for (float y = 0.8; y <= 0.9; y += windowGap) {
        for (float x = -0.8; x <= 0.8; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 1.01);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    for (float y = 1.1; y <= 1.6; y += windowGap) {
        for (float x = -0.8; x <= 0.8; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 1.01);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    glPopMatrix();

    // Third building
    glPushMatrix();
    glTranslatef(6.0, 0.0, 0.0); // Position the building relative to the house

    // Main building
    glPushMatrix();
    glColor3f(0.184314, 0.309804, 0.184314); // Light brown
    glTranslatef(0.0, 0.5, 0.0);
    glutSolidCube(1.5); // Main building body
    glPopMatrix();

    // Roof for the main building
    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0); // Raise roof to top of the main building
    glColor3f(0.5, 0.3, 0.1); // Dark brown
    glBegin(GL_TRIANGLES);
        // Front face
        glVertex3f(-0.75, 0.75, 0.75);
        glVertex3f(0.75, 0.75, 0.75);
        glVertex3f(0.0, 1.25, 0.25);

        glVertex3f(-0.75, 0.75, 0.75);
        glVertex3f(0.0, 1.25, 0.25);
        glVertex3f(-0.75, 0.75, -0.75);

        // Back face
        glVertex3f(-0.75, 0.75, -0.75);
        glVertex3f(0.75, 0.75, -0.75);
        glVertex3f(0.0, 1.25, -0.25);

        glVertex3f(-0.75, 0.75, -0.75);
        glVertex3f(0.0, 1.25, -0.25);
        glVertex3f(-0.75, 0.75, 0.75);
    glEnd();

    glBegin(GL_QUADS);
        // Right face
        glVertex3f(0.75, 0.75, 0.75);
        glVertex3f(0.75, 0.75, -0.75);
        glVertex3f(0.0, 1.25, -0.25);
        glVertex3f(0.0, 1.25, 0.25);

        // Left face
        glVertex3f(-0.75, 0.75, 0.75);
        glVertex3f(-0.75, 0.75, -0.75);
        glVertex3f(0.0, 1.25, -0.25);
        glVertex3f(0.0, 1.25, 0.25);
    glEnd();
    glPopMatrix();

    // Windows on the main building
    glColor3f(0.6, 0.6, 0.8); // Light gray
    windowSize = 0.15;
    windowGap = 0.35;

    // Draw rows of windows on one side
    for (float y = 0.3; y <= 0.6; y += windowGap) {
        for (float x = -0.6; x <= 0.6; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 0.76);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    for (float y = 0.7; y <= 1.0; y += windowGap) {
        for (float x = -0.6; x <= 0.6; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 0.76);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    glPopMatrix();



    glPopMatrix();


    glPopMatrix();
    //DESNO SI BRATE

    //desna strana ulice
    glPushMatrix();
     glTranslatef(3,0,0);
     glRotatef(90, 0, -1, 0);
     glPushMatrix();
    glTranslatef(5.0, 0.0, 0.0); // Position the building relative to the house

    // Main building
    glPushMatrix();
    glColor3f(0.8, 0.6, 0.2); // Light brown
    glTranslatef(0.0, 0.5, 0.0);
    glutSolidCube(1.5); // Main building body
    glPopMatrix();

    // Roof for the main building
    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0); // Raise roof to top of the main building
    glColor3f(0.5, 0.3, 0.1); // Dark brown
    glBegin(GL_TRIANGLES);
        // Front face
        glVertex3f(-0.75, 0.75, 0.75);
        glVertex3f(0.75, 0.75, 0.75);
        glVertex3f(0.0, 1.25, 0.25);

        glVertex3f(-0.75, 0.75, 0.75);
        glVertex3f(0.0, 1.25, 0.25);
        glVertex3f(-0.75, 0.75, -0.75);

        // Back face
        glVertex3f(-0.75, 0.75, -0.75);
        glVertex3f(0.75, 0.75, -0.75);
        glVertex3f(0.0, 1.25, -0.25);

        glVertex3f(-0.75, 0.75, -0.75);
        glVertex3f(0.0, 1.25, -0.25);
        glVertex3f(-0.75, 0.75, 0.75);
    glEnd();

    glBegin(GL_QUADS);
        // Right face
        glVertex3f(0.75, 0.75, 0.75);
        glVertex3f(0.75, 0.75, -0.75);
        glVertex3f(0.0, 1.25, -0.25);
        glVertex3f(0.0, 1.25, 0.25);

        // Left face
        glVertex3f(-0.75, 0.75, 0.75);
        glVertex3f(-0.75, 0.75, -0.75);
        glVertex3f(0.0, 1.25, -0.25);
        glVertex3f(0.0, 1.25, 0.25);
    glEnd();
    glPopMatrix();

    // Windows on the main building
    glColor3f(0.6, 0.6, 0.8); // Light gray
    windowSize = 0.15;
    windowGap = 0.35;

    // Draw rows of windows on one side
    for (float y = 0.3; y <= 0.6; y += windowGap) {
        for (float x = -0.6; x <= 0.6; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 0.76);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    for (float y = 0.7; y <= 1.0; y += windowGap) {
        for (float x = -0.6; x <= 0.6; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 0.76);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }


    glPopMatrix();

    //drvo
    glPushMatrix();
    glTranslatef(2.5, 0, 2.7);

    glPushMatrix();
    glColor3f(0.5, 0.35, 0.05); // Brown color for the trunk
    glTranslatef(0.5, -0.1, -1.7);
    glRotatef(180, 0, 1, 1);
    gluCylinder(stablo, 0.04, 0.04, 0.7, 20, 20);
    glPopMatrix();

    // Canopy - large leaves
    glPushMatrix();
    glColor3f(0.0, 0.8, 0.0); // Green color for the leaves
    glTranslatef(0.5, 0.75, -1.7);
    glScalef(0.5, 1, 0.5);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    // Canopy - medium leaves
    glPushMatrix();
    glColor3f(0.0, 0.8, 0.0); // Green color for the leaves
    glTranslatef(0.5, 1.0, -1.7);
    glScalef(0.4, 1, 0.4);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    // Canopy - small leaves
    glPushMatrix();
    glColor3f(0.0, 0.8, 0.0); // Green color for the leaves
    glTranslatef(0.5, 1.2, -1.7);
    glScalef(0.3, 1, 0.3);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    //ljuljaska
    glTranslatef(-0.7, 0,-3.0);
    glRotatef(75, 0, 1, 0);
    //desne ukrstene
    glPushMatrix();
    glRotatef(15, 0, 1, 0);
    glColor3f(0.5, 0.35, 0.05);
    glTranslatef(0, -0.1, 1.2);
    glRotatef(180, 0, 1, 1);
    glRotatef(-20, 0, 1, 0);
    gluCylinder(stablo, 0.02, 0.02, 0.7, 20, 20);
    glTranslatef(-0.4, 0, 0);
    glRotatef(30, 0, 1, 0);
    gluCylinder(stablo, 0.02, 0.02, 0.8, 20, 20);
    glPopMatrix();

    //leve ukrstene
    glPushMatrix();
    glRotatef(15, 0, 1, 0);
    glColor3f(0.5, 0.35, 0.05);
    glTranslatef(0, -0.1, 2.2);
    glRotatef(180, 0, 1, 1);
    glRotatef(-20, 0, 1, 0);
    gluCylinder(stablo, 0.02, 0.02, 0.7, 20, 20);
    glTranslatef(-0.4, 0, 0);
    glRotatef(30, 0, 1, 0);
    gluCylinder(stablo, 0.02, 0.02, 0.8, 20, 20);
    glPopMatrix();

    //sipka gore
    glPushMatrix();
    glRotatef(15, 0, 1, 0);
    glColor3f(0.5, 0.35, 0.05);
    glTranslatef(0.225, 0.55, 1.2);
    gluCylinder(stablo, 0.02, 0.02, 1, 20, 20);
    glPopMatrix();

    //zice
    glPushMatrix();
    glColor3f(0.5, 0.35, 0.05);
    glTranslatef(0.6, 0.08, 1.4);
    glRotatef(180, 0, 1, 1);
    gluCylinder(stablo, 0.02, 0.02, 0.5, 20, 20);
    glTranslatef(-0.08, 0.3, 0);
    gluCylinder(stablo, 0.02, 0.02, 0.5, 20, 20);
    glPopMatrix();

    //sediste?
    glPushMatrix();
    glRotatef(15, 0, 1, 0);
    glColor3f(1.0, 0.5, 0.0);
    glTranslatef(0.25, 0.08, 1.65);
    glScalef(0.6, 0.2 ,1.2 );
    glutSolidCube(0.4);
    glPopMatrix();
    glPopMatrix();


    glPopMatrix();
     // Second building
    glPushMatrix();
    glTranslatef(1.0, 0.0, 0); // Position the building relative to the house

    // Main building
    glPushMatrix();
    glColor3f(0.22, 0.69, 0.87); // Light yellow
    glTranslatef(0.0, 0.5, 0.0);
    glScalef(1,1.5,1);
    glutSolidCube(2.0); // Main building body
    glPopMatrix();


    // Windows on the main building
    glColor3f(1, 1, 1.0); // Light blue

    // Draw rows of windows on one side
    for (float y = 0.4; y <= 0.8; y += windowGap) {
        for (float x = -0.8; x <= 0.8; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 1.01);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    for (float y = 0.8; y <= 0.9; y += windowGap) {
        for (float x = -0.8; x <= 0.8; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 1.01);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    for (float y = 1.2; y <= 1.6; y += windowGap) {
        for (float x = -0.8; x <= 0.8; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 1.01);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }



    glPopMatrix();

    glPushMatrix();
        glTranslatef(-18.0, 0.0, 2); // Position the street light
        int numStreetLights = 12;
        float streetLightSpacing = 3.0; // Distance between each street light
        for (int i = 0; i < numStreetLights; ++i) {
            glPushMatrix();
                float xPos = i * streetLightSpacing;
                glTranslatef(xPos, 0.0, 2.2); // Adjust Z coordinate as needed
                drawStreetLight(); // Draw the street light at current position
            glPopMatrix();
        };
    glPopMatrix();

    glPushMatrix();
    glRotatef(180,0,1,0);
        glTranslatef(-12.0, 0.0, -4); // Position the street light
        numStreetLights = 12;
        streetLightSpacing = 3.0; // Distance between each street light
        for (int i = 0; i < numStreetLights; ++i) {
            glPushMatrix();
                float xPos = i * streetLightSpacing;
                glTranslatef(xPos, 0.0, 2.2); // Adjust Z coordinate as needed
                drawStreetLight(); // Draw the street light at current position
            glPopMatrix();
        };
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
     glTranslatef(3,0,-8);
     glRotatef(90, 0, -1, 0);
     glPushMatrix();
    glTranslatef(5.0, 0.0, 0.0); // Position the building relative to the house

    // Main building
    glPushMatrix();
    glColor3f(0.419608, 0.137255, 0.556863); // Light brown
    glTranslatef(0.0, 0.5, 0.0);
    glutSolidCube(1.5); // Main building body
    glPopMatrix();

    // Roof for the main building
    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0); // Raise roof to top of the main building
    glColor3f(0.184314, 0.309804, 0.309804); // Dark brown
    glBegin(GL_TRIANGLES);
        // Front face
        glVertex3f(-0.75, 0.75, 0.75);
        glVertex3f(0.75, 0.75, 0.75);
        glVertex3f(0.0, 1.25, 0.25);

        glVertex3f(-0.75, 0.75, 0.75);
        glVertex3f(0.0, 1.25, 0.25);
        glVertex3f(-0.75, 0.75, -0.75);

        // Back face
        glVertex3f(-0.75, 0.75, -0.75);
        glVertex3f(0.75, 0.75, -0.75);
        glVertex3f(0.0, 1.25, -0.25);

        glVertex3f(-0.75, 0.75, -0.75);
        glVertex3f(0.0, 1.25, -0.25);
        glVertex3f(-0.75, 0.75, 0.75);
    glEnd();

    glBegin(GL_QUADS);
        // Right face
        glVertex3f(0.75, 0.75, 0.75);
        glVertex3f(0.75, 0.75, -0.75);
        glVertex3f(0.0, 1.25, -0.25);
        glVertex3f(0.0, 1.25, 0.25);

        // Left face
        glVertex3f(-0.75, 0.75, 0.75);
        glVertex3f(-0.75, 0.75, -0.75);
        glVertex3f(0.0, 1.25, -0.25);
        glVertex3f(0.0, 1.25, 0.25);
    glEnd();
    glPopMatrix();

    // Windows on the main building
    glColor3f(0.6, 0.6, 0.8); // Light gray
    windowSize = 0.15;
    windowGap = 0.35;

    // Draw rows of windows on one side
    for (float y = 0.3; y <= 0.6; y += windowGap) {
        for (float x = -0.6; x <= 0.6; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 0.76);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    for (float y = 0.7; y <= 1.0; y += windowGap) {
        for (float x = -0.6; x <= 0.6; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 0.76);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }


    glPopMatrix();

    //drvo
    glPushMatrix();
    glTranslatef(2.5, 0, 2.7);

    glPushMatrix();
    glColor3f(0.5, 0.35, 0.05); // Brown color for the trunk
    glTranslatef(0.5, -0.1, -1.7);
    glRotatef(180, 0, 1, 1);
    gluCylinder(stablo, 0.04, 0.04, 0.7, 20, 20);
    glPopMatrix();

    // Canopy - large leaves
    glPushMatrix();
    glColor3f(0.0, 0.8, 0.0); // Green color for the leaves
    glTranslatef(0.5, 0.75, -1.7);
    glScalef(0.5, 1, 0.5);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    // Canopy - medium leaves
    glPushMatrix();
    glColor3f(0.0, 0.8, 0.0); // Green color for the leaves
    glTranslatef(0.5, 1.0, -1.7);
    glScalef(0.4, 1, 0.4);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    // Canopy - small leaves
    glPushMatrix();
    glColor3f(0.0, 0.8, 0.0); // Green color for the leaves
    glTranslatef(0.5, 1.2, -1.7);
    glScalef(0.3, 1, 0.3);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    glPushMatrix();
    //ljuljaska
    /*glTranslatef(-0.7, 0,-3.0);
    glRotatef(75, 0, 1, 0);
    //desne ukrstene
    glPushMatrix();
    glRotatef(15, 0, 1, 0);
    glColor3f(0.5, 0.35, 0.05);
    glTranslatef(0, -0.1, 1.2);
    glRotatef(180, 0, 1, 1);
    glRotatef(-20, 0, 1, 0);
    gluCylinder(stablo, 0.02, 0.02, 0.7, 20, 20);
    glTranslatef(-0.4, 0, 0);
    glRotatef(30, 0, 1, 0);
    gluCylinder(stablo, 0.02, 0.02, 0.8, 20, 20);
    glPopMatrix();

    //leve ukrstene
    glPushMatrix();
    glRotatef(15, 0, 1, 0);
    glColor3f(0.5, 0.35, 0.05);
    glTranslatef(0, -0.1, 2.2);
    glRotatef(180, 0, 1, 1);
    glRotatef(-20, 0, 1, 0);
    gluCylinder(stablo, 0.02, 0.02, 0.7, 20, 20);
    glTranslatef(-0.4, 0, 0);
    glRotatef(30, 0, 1, 0);
    gluCylinder(stablo, 0.02, 0.02, 0.8, 20, 20);
    glPopMatrix();

    //sipka gore
    glPushMatrix();
    glRotatef(15, 0, 1, 0);
    glColor3f(0.5, 0.35, 0.05);
    glTranslatef(0.225, 0.55, 1.2);
    gluCylinder(stablo, 0.02, 0.02, 1, 20, 20);
    glPopMatrix();

    //zice
    glPushMatrix();
    glColor3f(0.5, 0.35, 0.05);
    glTranslatef(0.6, 0.08, 1.4);
    glRotatef(180, 0, 1, 1);
    gluCylinder(stablo, 0.02, 0.02, 0.5, 20, 20);
    glTranslatef(-0.08, 0.3, 0);
    gluCylinder(stablo, 0.02, 0.02, 0.5, 20, 20);
    glPopMatrix();

    //sediste?
    glPushMatrix();
    glRotatef(15, 0, 1, 0);
    glColor3f(1.0, 0.5, 0.0);
    glTranslatef(0.25, 0.08, 1.65);
    glScalef(0.6, 0.2 ,1.2 );
    glutSolidCube(0.4);
    glPopMatrix();
    glPopMatrix();*/

    glTranslatef(0.7, 0,-3.0);
    glRotatef(115,0,1,0);
    glScalef(1.5, 1.5, 1.5);
    drawSlide(45);

    glPopMatrix();


    glPopMatrix();
     // Second building
    glPushMatrix();
    glTranslatef(1.0, 0.0, 0); // Position the building relative to the house

    // Main building
    glPushMatrix();
    glColor3f(0.309804,  0.184314,  0.184314); // Light yellow
    glTranslatef(0.0, 0.5, 0.0);
    glScalef(1,1.5,1);
    glutSolidCube(2.0); // Main building body
    glPopMatrix();


    // Windows on the main building
    glColor3f(1, 1, 1.0); // Light blue

    // Draw rows of windows on one side
    for (float y = 0.4; y <= 0.8; y += windowGap) {
        for (float x = -0.8; x <= 0.8; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 1.01);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    for (float y = 0.8; y <= 0.9; y += windowGap) {
        for (float x = -0.8; x <= 0.8; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 1.01);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    for (float y = 1.2; y <= 1.6; y += windowGap) {
        for (float x = -0.8; x <= 0.8; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 1.01);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }



    glPopMatrix();
     glPopMatrix();
     glPushMatrix();
        glTranslatef(3,0,-18);
     glRotatef(180, 0, -1, 0);
     glPushMatrix();

        // Draw house
        glPushMatrix();
        glColor3f(0.5, 0.35, 0.05);
        glTranslatef(0.0, 0.4, 0.0);
        glutSolidCube(1.0);
        glPopMatrix();

        //draw door
        glPushMatrix();
        glColor3f(1.0, 0.5, 0.0);
        glTranslatef(0.38, 0.1, 0.0);
        glScalef(1, 1.5 , 1);
        glutSolidCube(0.25);
        glPopMatrix();

        glPushMatrix();
         glColor3f(0.5, 0.8, 1.0);
        glTranslatef(0.38, 0.5, 0.2);
        glutSolidCube(0.25);
        glPopMatrix();

        glPushMatrix();
        glColor3f(0.5, 0.8, 1.0);
        glTranslatef(0.38, 0.5, -0.2);
        glutSolidCube(0.25);
        glPopMatrix();

        // Draw the roof
        glPushMatrix();
        glRotatef(90, 0, 1, 0);
        glColor3f(0.8, 0.0, 0.0);
        glBegin(GL_TRIANGLES);
        // torugao
        glVertex3f(-0.5, 0.9, 0.5);
        glVertex3f(0.5, 0.9, 0.5);
        glVertex3f(0.0, 1.4, 0.5);
        // trougao
        glVertex3f(-0.5, 0.9, -0.5);
        glVertex3f(0.5, 0.9, -0.5);
        glVertex3f(0.0, 1.4, -0.5);
        glEnd();

        glBegin(GL_QUADS);
        // kvadrat
        glVertex3f(-0.5, 0.9, 0.5);
        glVertex3f(0.0, 1.4, 0.5);
        glVertex3f(0.0, 1.4, -0.5);
        glVertex3f(-0.5, 0.9, -0.5);
        // kvadrat
        glVertex3f(0.5, 0.9, 0.5);
        glVertex3f(0.0, 1.4, 0.5);
        glVertex3f(0.0, 1.4, -0.5);
        glVertex3f(0.5, 0.9, -0.5);
        glEnd();
        glPopMatrix();

        //odzak
        glPushMatrix();
        glColor3f(1.0, 0.5, 0.0);
        glTranslatef(0.0, 1.25, -0.2);
        glScalef(0.5, 1.5 ,0.5);
        glutSolidCube(0.3);
        glPopMatrix();

        //siri deo odzaka
        glPushMatrix();
        glColor3f(1.0, 0.5, 0.0);
        glTranslatef(0.0, 1.45, -0.2);
        glScalef(1, 0.4 ,1 );
        glutSolidCube(0.2);
        glPopMatrix();

        //smoke
        glPushMatrix();
        glColor3f(1, 1, 1.0);
        glTranslatef(0.0, 1.55, -0.24);
        glutSolidSphere(0.075, 20, 20);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(0.0, 1.6, -0.18);
        glutSolidSphere(0.085, 20, 20);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(0.0, 1.7, -0.25);
        glutSolidSphere(0.085, 20, 20);
        glPopMatrix();

        //bazen
    glPushMatrix();
    glColor3f(0.5, 0.35, 0.05);
    glTranslatef(-2.0, -0.05, 0.5);
    glScalef(1, 0.15 , 3);
    glutSolidCube(1.0);
    glPopMatrix();

    //voda
    glPushMatrix();
    glColor3f(0.5, 0.8, 1.0);
    glTranslatef(-2.0, 0, 0.5);
    glScalef(1, 0.15 , 3);
    glutSolidCube(0.9);
    glPopMatrix();

    //stepenice za bazen
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(-1.5, 0, 0);
    glRotatef(180, 0, 1, 1);
    gluCylinder(stablo, 0.02, 0.02, 0.5, 20, 20);
    glTranslatef(0, 0.2, 0);
    gluCylinder(stablo, 0.02, 0.02, 0.5, 20, 20);
    glPopMatrix();

    //horizontala
    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(-1.5, 0, 0);
    gluCylinder(stablo, 0.02, 0.02, 0.2, 20, 20);
    glTranslatef(0, 0.1, 0);
    gluCylinder(stablo, 0.02, 0.02, 0.2, 20, 20);
    glTranslatef(0, 0.1, 0);
    gluCylinder(stablo, 0.02, 0.02, 0.2, 20, 20);
    glTranslatef(0, 0.1, 0);
    gluCylinder(stablo, 0.02, 0.02, 0.2, 20, 20);
    glTranslatef(0, 0.1, 0);
    gluCylinder(stablo, 0.02, 0.02, 0.2, 20, 20);
    glPopMatrix();

    //odskocna daska
    glPushMatrix();
    glColor3f(0.8, 0.0, 0.0);
    glTranslatef(-1.7, 0.5, 0.1);
    glScalef(1, 0.05 , 0.7);
    glutSolidCube(0.5);
    glPopMatrix();

    // Draw picnic table
    glPushMatrix();
    glColor3f(0.4, 0.2, 0.1);
    glTranslatef(-0.5, 0.2, -1.6);
    glScalef(2, 0.1, 1);
    glutSolidCube(0.5);
    glPopMatrix();

    //drzac stola
    glPushMatrix();
    glColor3f(0.5, 0.35, 0.05);
    glTranslatef(-0.5, -0.1, -1.6);
    glRotatef(180, 0, 1, 1);
    gluCylinder(stablo, 0.04, 0.04, 0.3, 20, 20);
    glPopMatrix();

    //stolice
    glPushMatrix();
    glColor3f(0.4, 0.2, 0.1);
    glTranslatef(-0.5, 0.075, -2);
    glScalef(2, 0.1, 0.2);
    glutSolidCube(0.5);
    glPopMatrix();

    //drzaci stolice
    glPushMatrix();
    glColor3f(0.5, 0.35, 0.05);
    glTranslatef(-0.1, -0.1, -2);
    glRotatef(180, 0, 1, 1);
    gluCylinder(stablo, 0.04, 0.04, 0.15, 20, 20);
    glPopMatrix();

    //drzaci stolice
    glPushMatrix();
    glColor3f(0.5, 0.35, 0.05);
    glTranslatef(-0.9, -0.1, -2);
    glRotatef(180, 0, 1, 1);
    gluCylinder(stablo, 0.04, 0.04, 0.15, 20, 20);
    glPopMatrix();

    //stolice
    glPushMatrix();
    glColor3f(0.4, 0.2, 0.1);
    glTranslatef(-0.5, 0.075, -1.2);
    glScalef(2, 0.1, 0.2);
    glutSolidCube(0.5);
    glPopMatrix();

    //drzaci stolice
    glPushMatrix();
    glColor3f(0.5, 0.35, 0.05);
    glTranslatef(-0.1, -0.1, -1.2);
    glRotatef(180, 0, 1, 1);
    gluCylinder(stablo, 0.04, 0.04, 0.15, 20, 20);
    glPopMatrix();

    //drzaci stolice
    glPushMatrix();
    glColor3f(0.5, 0.35, 0.05);
    glTranslatef(-0.9, -0.1, -1.2);
    glRotatef(180, 0, 1, 1);
    gluCylinder(stablo, 0.04, 0.04, 0.15, 20, 20);
    glPopMatrix();

    //rostilj
    // Draw barbecue grill base
    glPushMatrix();
    glColor3f(0.8, 0.1, 0.1);
    glTranslatef(-0.4, 0.25, -0.65);
    glScalef(1, 0.2, 1);
    glutSolidCube(0.3);
    glPopMatrix();

    // Grill bars
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glTranslatef(-0.4, 0.4, -0.65);
    glRotatef(45, 1, 0, 0);
    glScalef(1, 0.03, 1);
    glutSolidCube(0.3);
    glPopMatrix();

    //nozice
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glTranslatef(-0.3, -0.1, -0.7);
    glRotatef(180, 0, 1, 1);
    gluCylinder(stablo, 0.02, 0.02, 0.33, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glTranslatef(-0.5, -0.1, -0.7);
    glRotatef(180, 0, 1, 1);
    gluCylinder(stablo, 0.02, 0.02, 0.33, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glTranslatef(-0.3, -0.1, -0.55);
    glRotatef(180, 0, 1, 1);
    gluCylinder(stablo, 0.02, 0.02, 0.33, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glTranslatef(-0.5, -0.1, -0.55);
    glRotatef(180, 0, 1, 1);
    gluCylinder(stablo, 0.02, 0.02, 0.33, 20, 20);
    glPopMatrix();

    //ping pong table
    // Draw table surface
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(-2.5, 0.25, -2.6);
    glRotatef(90, 0, 1 ,0);
    glScalef(2, 0.1, 1);
    glutSolidCube(0.5);
    glPopMatrix();

    // Draw the net
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-2.5, 0.3, -2.6);
    glScalef(0.5, 0.08, 0.02); // Net dimensions
    glutSolidCube(1.0);
    glPopMatrix();

    //drzac stola
    glPushMatrix();
    glColor3f(0.25, 0.25, 0.25);
    glTranslatef(-2.35, -0.15, -2.3);
    glRotatef(180, 0, 1, 1);
    gluCylinder(stablo, 0.01, 0.01, 0.4, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.25, 0.25, 0.25);
    glTranslatef(-2.35, -0.15, -2.9);
    glRotatef(180, 0, 1, 1);
    gluCylinder(stablo, 0.01, 0.01, 0.4, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.25, 0.25, 0.25);
    glTranslatef(-2.65, -0.15, -2.3);
    glRotatef(180, 0, 1, 1);
    gluCylinder(stablo, 0.01, 0.01, 0.4, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.25, 0.25, 0.25);
    glTranslatef(-2.65, -0.15, -2.9);
    glRotatef(180, 0, 1, 1);
    gluCylinder(stablo, 0.01, 0.01, 0.4, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -0.15, 0);
    drawPerson(-2.3, 0.35, -2, 1.2, 65);
    drawPerson(-2.7, 0.35, -3.2, 1.2, -65);
    glPopMatrix();

        glPushMatrix();
            glTranslatef(0, 0, -7);
            glRotatef(90,0,1,0);
            // Main building
    glPushMatrix();
    glColor3f(0.576471, 0.858824, 0.439216); // Light yellow
    glTranslatef(0.0, 0.5, 0.0);
    glutSolidCube(2.0); // Main building body
    glPopMatrix();

    // Roof for the main building
    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0); // Raise roof to top of the main building
    glColor3f(0.3, 0.3, 0.3); // Dark grey
    glBegin(GL_TRIANGLES);
        // Front face
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(0.0, 1.5, 0.5);

        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(0.0, 1.5, 0.5);
        glVertex3f(-1.0, 1.0, -1.0);

        // Back face
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(0.0, 1.5, -0.5);

        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(0.0, 1.5, -0.5);
        glVertex3f(-1.0, 1.0, 1.0);
        glEnd();

        glBegin(GL_QUADS);
        // Right face
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(0.0, 1.5, -0.5);
        glVertex3f(0.0, 1.5, 0.5);

        // Left face
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(0.0, 1.5, -0.5);
        glVertex3f(0.0, 1.5, 0.5);
        glEnd();
        glPopMatrix();

    // Windows on the main building
    glColor3f(0.5, 0.8, 1.0); // Light blue
    windowSize = 0.2;
    windowGap = 0.5;

    // Draw rows of windows on one side
    for (float y = 0.4; y <= 0.8; y += windowGap) {
        for (float x = -0.8; x <= 0.8; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 1.01);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    for (float y = 0.8; y <= 0.9; y += windowGap) {
        for (float x = -0.8; x <= 0.8; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 1.01);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    for (float y = 1.2; y <= 1.6; y += windowGap) {
        for (float x = -0.8; x <= 0.8; x += windowGap) {
            glPushMatrix();
            glTranslatef(x, y, 1.01);
            glutSolidCube(windowSize);
            glPopMatrix();
        }
    }

    // First additional floor (right wing)
    glPushMatrix();
    glColor3f(0.576471, 0.858824, 0.439216); // Light yellow
    glTranslatef(1.5, 0.5, 0);
    glScalef(1.0, 2.8, 2.2);
    glutSolidCube(1.0); // Right wing
    glPopMatrix();

    // Roof for the right wing
    glPushMatrix();
    glTranslatef(0, 0.9, 0.0); // Raise roof to top of the right wing
    glColor3f(0.3, 0.3, 0.3); // Dark grey
    // Front face
        glBegin(GL_TRIANGLES);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(2.0, 1.0, 1.0);
        glVertex3f(1.5, 1.5, 0.5);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(2.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(1.5, 1.5, 0.5);
        glEnd();

        // Back face
        glBegin(GL_TRIANGLES);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(2.0, 1.0, -1.0);
        glVertex3f(1.5, 1.5, -0.5);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(2.0, 1.0, -1.0);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(1.5, 1.5, -0.5);
        glEnd();

        // Right face
        glBegin(GL_QUADS);
        glVertex3f(2.0, 1.0, 1.0);
        glVertex3f(2.0, 1.0, -1.0);
        glVertex3f(1.5, 1.5, -0.5);
        glVertex3f(1.5, 1.5, 0.5);
        glEnd();

        // Left face
        glBegin(GL_QUADS);
        glVertex3f(1.0, 1.0, 1.0);
        glVertex3f(1.0, 1.0, -1.0);
        glVertex3f(1.5, 1.5, -0.5);
        glVertex3f(1.5, 1.5, 0.5);
        glEnd();

    glPopMatrix();

    // Second additional floor (left wing)
    glPushMatrix();
    glColor3f(0.576471, 0.858824, 0.439216); // Light yellow
    glTranslatef(-1.5, 0.5, 0);
    glScalef(1.0, 2.8, 2.2);
    glutSolidCube(1.0); // Left wing
    glPopMatrix();

    // Roof for the left wing
    glPushMatrix();
    glTranslatef(0, 0.9, 0.0); // Raise roof to top of the left wing
    glColor3f(0.3, 0.3, 0.3); // Dark grey
    // Front face
        glBegin(GL_TRIANGLES);
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(-2.0, 1.0, 1.0);
        glVertex3f(-1.5, 1.5, 0.5);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(-2.0, 1.0, 1.0);
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(-1.5, 1.5, 0.5);
        glEnd();

        // Back face
        glBegin(GL_TRIANGLES);
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(-2.0, 1.0, -1.0);
        glVertex3f(-1.5, 1.5, -0.5);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(-2.0, 1.0, -1.0);
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(-1.5, 1.5, -0.5);
        glEnd();

        // Right face
        glBegin(GL_QUADS);
        glVertex3f(-1.0, 1.0, 1.0);
        glVertex3f(-1.0, 1.0, -1.0);
        glVertex3f(-1.5, 1.5, -0.5);
        glVertex3f(-1.5, 1.5, 0.5);
        glEnd();

        // Left face
        glBegin(GL_QUADS);
        glVertex3f(-2.0, 1.0, 1.0);
        glVertex3f(-2.0, 1.0, -1.0);
        glVertex3f(-1.5, 1.5, -0.5);
        glVertex3f(-1.5, 1.5, 0.5);
        glEnd();
    glEnd();
    glPopMatrix();

        glPopMatrix();

    glPopMatrix();

    //drvo
    glPushMatrix();
    glTranslatef(-2.6, 0, 0.5);

    glPushMatrix();
    glColor3f(0.5, 0.35, 0.05); // Brown color for the trunk
    glTranslatef(0.5, -0.1, -1.7);
    glRotatef(180, 0, 1, 1);
    gluCylinder(stablo, 0.04, 0.04, 0.7, 20, 20);
    glPopMatrix();

    // Canopy - large leaves
    glPushMatrix();
    glColor3f(0.0, 0.8, 0.0); // Green color for the leaves
    glTranslatef(0.5, 0.75, -1.7);
    glScalef(0.5, 1, 0.5);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    // Canopy - medium leaves
    glPushMatrix();
    glColor3f(0.0, 0.8, 0.0); // Green color for the leaves
    glTranslatef(0.5, 1.0, -1.7);
    glScalef(0.4, 1, 0.4);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    // Canopy - small leaves
    glPushMatrix();
    glColor3f(0.0, 0.8, 0.0); // Green color for the leaves
    glTranslatef(0.5, 1.2, -1.7);
    glScalef(0.3, 1, 0.3);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

    // Additional smaller leaves
    glPushMatrix();
    glColor3f(0.0, 0.8, 0.0); // Green color for the leaves
    glTranslatef(0.3, 0.8, -1.5);
    glutSolidSphere(0.2, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.8, 0.0); // Green color for the leaves
    glTranslatef(0.5, 1, -1.6);
    glutSolidSphere(0.25, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.8, 0.0); // Green color for the leaves
    glTranslatef(0.7, 1.1, -1.9);
    glutSolidSphere(0.3, 10, 10);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();

    glPopMatrix();




}
void house()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(viewer[0], viewer[1], viewer[2], lat[0], lat[1], lat[2], 0.0, 1.0, 0.0);
	gluLookAt(viewer[0], viewer[1], viewer[2], viewer[0] + lx, lat[1], viewer[2]+lz, 0.0, 1.0, 0.0);
	//gluLookAt(0, 1, 0, 0, 0, 0, 0.0f, 0.0f, 1.0f);

	glPushMatrix();
	glTranslatef(0.0, 0.2, 3.2);
	glScalef(0.5, 0.5, 0.0);
	glPopMatrix();

	outercover();
	glutSwapBuffers();
}


void specialKey(int key, int x, int y) {

	int q = viewer[0];
	int w = viewer[1];
	int e = viewer[2];
	float fraction = 0.1f;

	switch (key) {
	case GLUT_KEY_LEFT:
		angle -= 0.02f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_RIGHT:
		angle += 0.02f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_UP:
	/*	if ((q<1 && q>-1))
		{
		//if(w<0.5 && w >0.0)
		{
			if (e<=1 && e>-1)

		{*/
			viewer[0] += lx * fraction;
			viewer[2] += lz * fraction;
	/*	}
		}
		}
		else
		{
			viewer[0] = 0.0;
			viewer[1] = 0.3;
			viewer[2] = 1.0;

			lat[0] = 0.0 ;
			lat[1] = 0.0;
			lat[2] = 0.0;
		}*/
		break;
	case GLUT_KEY_DOWN:
		viewer[0] -= lx * fraction;
		viewer[2] -= lz * fraction;
		break;

	case GLUT_KEY_PAGE_UP:
		viewer[1] += 0.1;
		lat[1] += 0.1;
		break;
	case GLUT_KEY_PAGE_DOWN:
		viewer[1] -= 0.1;
		lat[1] -= 0.1;
		break;
	}
	glutPostRedisplay();
}
void changeSize(int w, int h)
{


	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;


	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);


	glLoadIdentity();


	gluPerspective(40.0f, ratio, 0.1f, 10.0f);

	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH|GLUT_ALPHA);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("magistrala");

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutDisplayFunc(house);
	glutReshapeFunc(changeSize);
	glDepthFunc(GL_LEQUAL);
	glutSpecialFunc(specialKey);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	tfs(0);
	glAlphaFunc(GL_GREATER, 0.1);
		glEnable(GL_ALPHA_TEST);

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutMainLoop();
	return 0;
}
