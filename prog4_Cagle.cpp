/*******************************
Name: Bryan Cagle
Class: CSCE 4230.001
Due Date: 03-24-2016
Description: The purpose of this program
is to modify the robot.c code to add another segment
as well as add more functionality.

Created from source code/initial settings of robot.c as base
*******************************/

#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0, wrist=0, fingers=0,xrot=0,yrot=0,SWtoggle=0,persToggle=0;

void init(void) 
{
   	glClearColor (0.0, 0.0, 0.0, 0.0);
   	glShadeModel (GL_FLAT);
}

void display(void)
{
	int w = glutGet(GLUT_WINDOW_WIDTH);
   	int h = glutGet(GLUT_WINDOW_HEIGHT);

	//The reshape function is placed here to allow it to be changed using a keypress when glutPostRedisplay is called
	if(w>h)
	glViewport(((w-h)/2),0,h,h);
	else
	glViewport(0,((h-w)/2),w,w);

	glMatrixMode (GL_PROJECTION);
   	glLoadIdentity ();

	//Toggles between using glFrustum and glOrtho perspectives
   	if(persToggle==0)
	glFrustum(-0.7,0.7,-0.7,0.7,1,30);
   	else 
	glOrtho(-13,13,-13,13,-1,30);


   	glMatrixMode(GL_MODELVIEW);
   	glLoadIdentity();   
   	glTranslatef (0.0, 0.0, -20.0);
   	glRotatef(xrot,1,0,0); //Allows for X-camera rotation when changed through keypress
   	glRotatef(yrot,0,1,0); //Y-camera rotation when changed through keypress
   	glTranslatef (0.0, 0.0, 20.0);
   	glTranslatef (0.0, 0.0, -20.0);
   
   	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   	
	//Drawing the shoulder
	glPushMatrix();
   	glRotatef ((GLfloat) shoulder, 0, 0, 1.0);
   	glTranslatef (2.5, 0.0, 0.0);
   	glPushMatrix();
	glColor3d(0,0,1);
   	glScalef (5.0, 1.0, 1.0);
	
	//Toggles for when the drawn model is a wireframe or solid for the shoulder
	if(SWtoggle!=1){
   		glutWireCube (1.0);
		glDisable(GL_DEPTH_TEST);
		}
	else{
		glutSolidCube(1.0);
		glEnable(GL_DEPTH_TEST);
		}

   	glPopMatrix();
   	
	//Drawing the elbow
	glTranslatef (2.2, 0.0, 0.0);
   	glRotatef ((GLfloat) elbow, 0, 0, 1.0);
   	glTranslatef (2.2, 0.0, 0.0);
   	glPushMatrix();
	glColor3d(0,1,0);
   	glScalef (4.0, 1.0, 1.0);
  	
	if(SWtoggle!=1){
   		glutWireCube (1.0);
		glDisable(GL_DEPTH_TEST);
		}
	else{
		glutSolidCube(1.0);
		glEnable(GL_DEPTH_TEST);
		}
	
	glPopMatrix();

	//Drawing the wrist
   	glTranslatef (1.4, 0.0, 0.0);
   	glRotatef ((GLfloat) wrist, 0, 0, 1.0);
 	glTranslatef (1.4, 0.0, 0.0);
   	glPushMatrix();
	glColor3d(1,0,0);
   	glScalef (2.0, 1.0, 1.0);
  	
	if(SWtoggle!=1){
   		glutWireCube (1.0);
		glDisable(GL_DEPTH_TEST);
		}
	else{
		glutSolidCube(1.0);
		glEnable(GL_DEPTH_TEST);
		}
	
	glPopMatrix();

	//Drawing the Fingers
   	glTranslatef (.7, 0, 0.17);
   	glRotatef ((GLfloat) fingers, 0, 0, 1.0);
 	glTranslatef (.7, 0, 0.17);
   	glPushMatrix();
	glColor3d(1,0,1);
   	glScalef (1.3, 0.25, .25);
  	
	if(SWtoggle!=1){
   		glutWireCube (1.0);
		glTranslatef (0, 0, -1.3);
		glutWireCube (1.0);
		glTranslatef (0, 0, -1.3);
		glutWireCube (1.0);
		glDisable(GL_DEPTH_TEST);
		}
	else{
		glutSolidCube (1.0);
		glTranslatef (0, 0, -1.3);
		glutSolidCube (1.0);
		glTranslatef (0, 0, -1.3);
		glutSolidCube (1.0);
		glEnable(GL_DEPTH_TEST);
		}
	
	glPopMatrix();

	//Draws second segment of fingers
	glTranslatef (.7, 0, 0);
   	glRotatef ((GLfloat) fingers, 0, 0, 1.0);
 	glTranslatef (.7, 0, 0);
   	glPushMatrix();
	glColor3d(1,0,1);
   	glScalef (1.3, 0.25, .25);
  	
	if(SWtoggle!=1){
   		glutWireCube (1.0);
		glTranslatef (0, 0, -1.3);
		glutWireCube (1.0);
		glTranslatef (0, 0, -1.3);
		glutWireCube (1.0);
		glDisable(GL_DEPTH_TEST);
		}
	else{
		glutSolidCube (1.0);
		glTranslatef (0, 0, -1.3);
		glutSolidCube (1.0);
		glTranslatef (0, 0, -1.3);
		glutSolidCube (1.0);
		glEnable(GL_DEPTH_TEST);
		}
	
	glPopMatrix();
   	glPopMatrix();
   	glutSwapBuffers();
}

void reshape (int w, int h)
{
 
	if(w>h)
	glViewport(((w-h)/2),0,h,h);
	else
	glViewport(0,((h-w)/2),w,w);

	glMatrixMode (GL_PROJECTION);
   	glLoadIdentity ();
   	if(persToggle==0)
	glFrustum(-0.7,0.7,-0.7,0.7,1,30);
   	else 
	glOrtho(-13,13,-13,13,-1,30);


   	glMatrixMode(GL_MODELVIEW);
   	glLoadIdentity();   
   	glTranslatef (0.0, 0.0, -20.0);
   	glRotatef(xrot,1,0,0);
   	glRotatef(yrot,0,1,0);
   	glTranslatef (0.0, 0.0, 20.0);
   	glTranslatef (0.0, 0.0, -20.0);
}
void MenuSelect(int idCommand)
{
	//Each menu selection has a seperate purpose for each action on the animation
        switch(idCommand)
        {
	//First six cases handle  rotation of each part of the arm in both directions
        case 's':
         	shoulder = (shoulder + 5) % 360;
         	glutPostRedisplay();
         	break;
      	case 'S':
         	shoulder = (shoulder - 5) % 360;
       	 	glutPostRedisplay();
         	break;
      	case 'e':
         	elbow = (elbow + 5) % 360;
         	glutPostRedisplay();
         	break;
      	case 'E':
         	elbow = (elbow - 5) % 360;
         	glutPostRedisplay();
         	break;
	case 'w':
		wrist=(wrist+5)%360;
		glutPostRedisplay();
		break;
	case 'W':
		wrist=(wrist-5)%360;
		glutPostRedisplay();
		break;
	case 'f':
		fingers=(fingers+5)%360;
		glutPostRedisplay();
		break;
	case 'F':
		fingers=(fingers-5)%360;
		glutPostRedisplay();
		break;
	//Following four cases handle camera rotations in both directions
	case 'x':
		xrot=(xrot+10)%360;
		glutPostRedisplay();
		break;
	case 'X':
		xrot=(xrot-10)%360;
		glutPostRedisplay();
		break;
	case 'y':
		yrot=(yrot+10)%360;
		glutPostRedisplay();
		break;
	case 'Y':
		yrot=(yrot-10)%360;
		glutPostRedisplay();
		break;
	//Toggles between wireframe and solid filled models
	case 'h':
		if(SWtoggle==0)
		SWtoggle=1;
		else
		SWtoggle=0;
		glutPostRedisplay();
		break;
	//Toggles perspective matrix used
	case 'p':
		if(persToggle==0)
		persToggle=1;
		else
		persToggle=0;
		glutPostRedisplay();
		break;
        case 27: exit(0); break; //ends program
                default: break;
        }
}
int BuildMenu(void)
{
	//Menu created with each function as well as the keypress alternative
	int menu;
	menu=glutCreateMenu(MenuSelect);
	glutAddMenuEntry("Rotate Shoulder + (s)",'s');
	glutAddMenuEntry("Rotate Shoulder - (S)", 'S');
	glutAddMenuEntry("Rotate Elbow + (e)", 'e');
	glutAddMenuEntry("Rotate Elbow - (E)", 'E');
	glutAddMenuEntry("Rotate Wrist + (w)", 'w');
	glutAddMenuEntry("Rotate Wrist - (W)", 'W');
	glutAddMenuEntry("Rotate Fingers + (f)", 'f');
	glutAddMenuEntry("Rotate Fingers - (F)", 'F');
	glutAddMenuEntry("Rotate Camera X-Axis + (x)", 'x');
	glutAddMenuEntry("Rotate Camera X-Axis - (X)", 'X');
	glutAddMenuEntry("Rotate Camera Y-Axis + (y)", 'y');
	glutAddMenuEntry("Rotate Camera Y-Axis - (Y)", 'Y');
	glutAddMenuEntry("Toggle Wireframe/Solid Fill (h)", 'h');
	glutAddMenuEntry("Toggle glOrtho/glFrustum (p)", 'p');
	glutAddMenuEntry("Exit Program (ESC)", 27);
}
void keyboard (unsigned char key, int x, int y)
{
	//Keypresses redirect to the menu presses
   	switch (key) {
      	case 's':
         	MenuSelect('s');
         	break;
      	case 'S':
         	MenuSelect('S');
         	break;
      	case 'e':
         	MenuSelect('e');
         	break;
      	case 'E':
        	MenuSelect('E');
        	break;
	case 'w':
		MenuSelect('w');
		break;
	case 'W':
		MenuSelect('W');
		break;
	case 'f':
		MenuSelect('f');
		break;
	case 'F':
		MenuSelect('F');
		break;
	case 'x':
		MenuSelect('x');
		break;
	case 'X':
		MenuSelect('X');
		break;
	case 'y':
		MenuSelect('y');
		break;
	case 'Y':
		MenuSelect('Y');
		break;
	case 'h':
		MenuSelect('h');
		break;
	case 'p':
		MenuSelect('p');
		break;
      	case 27:
		MenuSelect(27);
      		break;
      	default:
         	break;
   }
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (500, 500); 
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Program 4: Robot Arm");
	init ();
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	BuildMenu();
   	glutAttachMenu(GLUT_RIGHT_BUTTON);
   	glutMainLoop();
   	return 0;
}
