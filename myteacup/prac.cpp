
#include<GL/glut.h>
#include<adsprop.h>
int main(int argc , char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitDisplayString(50,50);
    glutInitWindowSize(640,480);
    glutCreateWindow(title);
    initGL();
    glutMainLoop();

    return 0;
}
