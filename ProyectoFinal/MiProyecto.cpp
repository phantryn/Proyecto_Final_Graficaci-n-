
//Se agregan las librerias
#include "stdafx.h"
// Libreria de utilidades open gl
#include <GL/glut.h>
// Libreria para el uso de texturas
#include "RgbImage.h"

//Contiene el # de imagenes que se utilizaran para las texturas
GLuint	texture[6];			// Almacenamiento Para Una Textura (NUEVO)

//Leer un mapa de textura desde un archivo de mapa de bits BMP.

// angulo de posicion inicial de la variable tronco
static int tronco= 90;
// Variables de rotación tipo float de openGL
GLfloat anguloEnx = 0.0f; // angulo en x
GLfloat anguloEny = 0.0f; // angulo en y
GLfloat anguloEnz = 0.0f; // angulo en z


// Valor del inicial del angulo donde se ubicará la luz en el eje x dentro del metodo display().
GLfloat movLuz = 10.0;
// Propiedades de la luz
float luz_ambiente [] = {0.2,0.2,0,0};
float luz_difusa [] = {1,1,1,0}; //color Luz

//Propiedades material
float mat_ambiente [] = {.3,0,0,1}; //{0.7,0,0,1};
float mat_difuso [] = {.5,0,0,1}; //{.9,0,0,1};
float mat_especular [] = {.8,.8,0,1}; //{.8,.8,0,1}; Reflejos
float mat_emision [] = {0,0,0,1};  //{0.5,0.5,0,0}; //{0,0,0,1};
float mat_brillo = 60; //90; //Difuminado del brillo


void ajusta(int ancho, int alto) {
	// ajustamos la imagen al tamaño actual de la pantalla cuando se maximise o minimise.
	const float ar = (float)ancho / (float)alto;
	// indicamos la posicion para el area de dibujo
	glViewport(0, 0, ancho, alto);
	// Declaramos el color de la pantalla
	glClearColor(0,0,0,0.0); // color negro
	glLightfv(GL_LIGHT0,GL_AMBIENT,luz_ambiente);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,luz_difusa);

	glLightf(GL_LIGHT0,GL_CONSTANT_ATTENUATION,.3); //.8
	// Habilitamos la iluminación
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	// Se reinicia la matriz projeccion para realiza la projeccion actualizada.
	glMatrixMode(GL_PROJECTION);
	// Reiniciamos las coordenadas
	glLoadIdentity();
	// Otorgamos el volumen de trabajo para cada dimension.
	glOrtho(-5,5,-5,5,-5,5); //alto,bajo,adelante,atras, izquierda,derecha
	//Reinicia el contenido de la pila de la matriz del modelador.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
// Metodo para cargar y llevar a cabo la asignación de texturas
// *filename equivalen a los apuntadores en memoria de las imagenes que se van a cargar.
void loadTextureFromFile(char *filename, char *filename1,char *filename2, char *filename3, char *filename4, char *filename5)
{
	// Color de la pantalla
   glClearColor (0.0, 0.0, 0.0, 0.0); // Negro (RGBA)
   // textura de la superficie (cuadrada o lisa)
   glShadeModel(GL_SMOOTH);// GL_FLAT
   glEnable(GL_DEPTH_TEST);

  RgbImage theTexMap( filename );	//0 centro
  RgbImage theTexMap1( filename1 ); //1 rosa
  RgbImage theTexMap2( filename2 ); //2 hoja
  RgbImage theTexMap3( filename3 ); //3 mesa
  RgbImage theTexMap4( filename4 ); //4 florero
  RgbImage theTexMap5( filename5 ); //5 tronco
// Alineación Pixel: cada fila es palabra alineados (alineado a un límite de 4 bytes)
// Por lo tanto, no hay necesidad de llamar glPixelStore (GL_UNPACK_ALIGNMENT

  //Textura de la mesa
   glGenTextures(1, &texture[0]);					// Crear la textura

   glBindTexture(GL_TEXTURE_2D, texture[0]);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	// Típica Generación textura utilizando datos del mapa de bits
	glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData() );

	//Textura hoja
   glGenTextures(1, &texture[1]); // Crea la textura

   glBindTexture(GL_TEXTURE_2D, texture[1]);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap1.GetNumCols(), theTexMap1.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap1.ImageData() );

   //Textura petalo
   glGenTextures(1, &texture[2]); // Crea la textura

   glBindTexture(GL_TEXTURE_2D, texture[2]);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap2.GetNumCols(), theTexMap2.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap2.ImageData() );

   //textura florero
   glGenTextures(1, &texture[3]); // Crea la textura

   glBindTexture(GL_TEXTURE_2D, texture[3]);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap3.GetNumCols(), theTexMap3.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap3.ImageData() );

      //textura mesa
   glGenTextures(1, &texture[4]); // Crea la textura

   glBindTexture(GL_TEXTURE_2D, texture[4]);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap4.GetNumCols(), theTexMap4.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap4.ImageData() );

         //textura tronco
   glGenTextures(1, &texture[5]); // Crea la textura

   glBindTexture(GL_TEXTURE_2D, texture[5]);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap5.GetNumCols(), theTexMap5.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, theTexMap5.ImageData() );
}


void display() {
    float luz_posicion [] = {movLuz,1.5,3,2};
	glLightfv(GL_LIGHT0,GL_POSITION,luz_posicion);
	glClear(GL_COLOR_BUFFER_BIT);
	//glPushMatrix();  //Foco

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambiente);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_difuso);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_especular);
	//glMaterialfv(GL_FRONT,GL_EMISSION,mat_emision);
	glMaterialf(GL_FRONT,GL_SHININESS,mat_brillo);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	//Centro flor
	glLoadIdentity();
	glEnable(GL_TEXTURE_GEN_S); //generación de la textura en las coordenadas
    glEnable(GL_TEXTURE_GEN_T);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

	glRotatef(anguloEnx,1.0f,0.0f,0.0f);
	glRotatef(anguloEny,0.0f,1.0f,0.0f);
	glRotatef(anguloEnz,0.0f,0.0f,1.0f);
	glRotatef(-90,1.0f,0.0f,0.0f);
	glColor3f(1, 1, 1);
	glTranslatef(-.5,.5,1.9);
	glPushMatrix();
	glTranslatef(0.60,0,0);
	glutSolidSphere(.80,30,30);
	glPopMatrix();


	glDisable(GL_TEXTURE_GEN_S); //apagamos la textura
    glDisable(GL_TEXTURE_GEN_T);

	//hoja1

	glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
    glEnable(GL_TEXTURE_GEN_T);
    glBindTexture(GL_TEXTURE_2D, texture[1]);
	glLoadIdentity();
		glRotatef(anguloEnx,1.0f,0.0f,0.0f);
		glRotatef(anguloEny,0.0f,1.0f,0.0f);
		glRotatef(anguloEnz,0.0f,0.0f,1.0f);
		glColor3f(1, 0, 1);//(1, 0, 1);
		glTranslatef(0.90,.90,-.3);
		glutSolidSphere(.70,30,30);
		glPopMatrix();

	//Hoja2
	glLoadIdentity();
		glRotatef(anguloEnx,1.0f,0.0f,0.0f);
		glRotatef(anguloEny,0.0f,1.0f,0.0f);
		glRotatef(anguloEnz,0.0f,0.0f,1.0f);
		glColor3f(1, 0, 1);
		glTranslatef(1.2,2,-.3);
		glutSolidSphere(.70,30,30);
		glPopMatrix();
	//Hoja3
	glLoadIdentity();
		glRotatef(anguloEnx,1.0f,0.0f,0.0f);
		glRotatef(anguloEny,0.0f,1.0f,0.0f);
		glRotatef(anguloEnz,0.0f,0.0f,1.0f);
		glColor3f(1, 0, 1);
		glTranslatef(.9,3,-.3);
		glutSolidSphere(.70,30,30);
		glPopMatrix();
	//Hoja4
	glLoadIdentity();
		glRotatef(anguloEnx,1.0f,0.0f,0.0f);
		glRotatef(anguloEny,0.0f,1.0f,0.0f);
		glRotatef(anguloEnz,0.0f,0.0f,1.0f);
		glColor3f(1, 0, 1);
		glTranslatef(-.1,3.3,-.3);
		glutSolidSphere(.70,30,30);
		glPopMatrix();
	//Hoja5
	glLoadIdentity();
		glRotatef(anguloEnx,1.0f,0.0f,0.0f);
		glRotatef(anguloEny,0.0f,1.0f,0.0f);
		glRotatef(anguloEnz,0.0f,0.0f,1.0f);
		glColor3f(1, 0, 1);
		glTranslatef(-.90,2.5,-.3);
		glutSolidSphere(.70,30,30);
		glPopMatrix();
	//Hoja6
	glLoadIdentity();
		glRotatef(anguloEnx,1.0f,0.0f,0.0f);
		glRotatef(anguloEny,0.0f,1.0f,0.0f);
		glRotatef(anguloEnz,0.0f,0.0f,1.0f);
		glColor3f(1, 0, 1);
		glTranslatef(-.95,1.35,-.3);
		glutSolidSphere(.70,30,30);
		glPopMatrix();
	//Hoja7
	glLoadIdentity();
		glRotatef(anguloEnx,1.0f,0.0f,0.0f);
		glRotatef(anguloEny,0.0f,1.0f,0.0f);
		glRotatef(anguloEnz,0.0f,0.0f,1.0f);
		glColor3f(1, 0, 1);
		glTranslatef(-.25,.65,-.3);
		glutSolidSphere(.70,30,30);
		glPopMatrix();
	glFlush();
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);

	//Petalo verde

	glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
    glEnable(GL_TEXTURE_GEN_T);
    glBindTexture(GL_TEXTURE_2D, texture[2]);
	glLoadIdentity();
		glRotatef(anguloEnx,1.0f,0.0f,0.0f);
		glRotatef(anguloEny,0.0f,1.0f,0.0f);
		glRotatef(anguloEnz,0.0f,0.0f,1.0f);
		glColor3f(0, 1, .5);//(0, 1, .5);
		glTranslatef(1,-2,-.3);
		glutSolidSphere(.70,7,7);
		glPopMatrix();
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);


	//Tronco
	glPushMatrix();
	glEnable(GL_TEXTURE_GEN_S); // Genera la textura en las coordenadas
    glEnable(GL_TEXTURE_GEN_T);
    glBindTexture(GL_TEXTURE_2D, texture[5]);
		glTranslatef(-1.0,0.0,0.0);
		glRotatef((GLfloat)tronco,0.0,0.0,1.0);
		glTranslatef(.6,-.3,0.0);
		glColor3f(0.5f, 0.5, -0.9f);
		glPushMatrix();
		glScalef(3.5,0.4,1.0);
		glutSolidCube(1.0);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();
	// florero:
	glLoadIdentity();
	glEnable(GL_TEXTURE_GEN_S); // Genera la textura en las coordenadas
    glEnable(GL_TEXTURE_GEN_T);
    glBindTexture(GL_TEXTURE_2D, texture[4]);
		glRotatef(anguloEnx,1.0f,0.0f,0.0f);
		glRotatef(anguloEny,0.0f,1.0f,0.0f);
		glRotatef(anguloEnz,0.0f,0.0f,1.0f);
		glRotatef(90,1.0f,0.0f,0.0f);
		glTranslatef(0,-.45,3);
		glColor3f(0.0f, 0.7f, 1.0f);
		glutSolidCone(1,1,10,5);
	glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();

	//Base
	glLoadIdentity();
	glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
    glEnable(GL_TEXTURE_GEN_T);
    glBindTexture(GL_TEXTURE_2D, texture[3]);

		glRotatef(anguloEnx,1.0f,0.0f,0.0f);
		glRotatef(anguloEny,0.0f,1.0f,0.0f);
		glRotatef(anguloEnz,0.0f,0.0f,1.0f);
		glTranslatef(-3.0f,-4.6,.2f);
		glColor3f(0.6f, 0.3f, 0.0f);//(0.2f, 0.1, -1.2f);
		glutSolidCube(1.5);
		glTranslatef(1.0f,-0.0,0.0f);
		glutSolidCube(1.5);
		glTranslatef(1.5f,-0.0,0.0f);
		glutSolidCube(1.5);
		glTranslatef(1.4f,0.0,0.0f);
		glutSolidCube(1.5);

	glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);

    //glFlush();
    glutSwapBuffers();
}

void init() {
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
}
//Cargamos las imagenes que usaremos como texturas
char* filename = "./centroA.bmp"; //0
char* filename1 = "./rosa.bmp"; //1
char* filename2 = "./hoja.bmp"; //2
char* filename3 = "./texturaMesa.bmp"; //3
char* filename4 = "./florerotextura.bmp"; //4
char* filename5 = "./tronco.bmp"; //5


void idle() {
	//anguloEny += 0.05f;
	//anguloEnz += 0.05f; //si activamos anguloEny u Enz y desactivamos en keyboard() desde la "u" hasta la "k"
	//nuestra imagen rotara sola.
	// Llamamos al metodo display()
    display();

}
// Con keyboard podemos manipular el movimiento de la figura con las teclas que menciona acontinuacion.
void keyboard(unsigned char key, int x, int y) {
    switch(key) {
		// 27 = tecla Esc permite cerrar la figura sin necesidad de dar clic en la X de la pantalla.
		case 27:
		exit(0);
		break;
		//Movimiento de la figura en eje x con incremento de 10.
		case 'u':
            anguloEnx=anguloEnx+10;
            break;
		//Movimiento de la figura en eje x con decremento de 10.
        case 'h':
            anguloEnx=anguloEnx-10;
            break;
		//Movimiento de la figura en eje y con incremento de 10.
		case 'i':
            anguloEny=anguloEny+10;
            break;
		//Movimiento de la figura en eje y con decremento de 10.
        case 'j':
            anguloEny=anguloEny-10;
            break;
		//Movimiento de la figura en eje z con incremento de 10.
		case 'o':
            anguloEnz=anguloEnz+10;
            break;
		//Movimiento de la figura en eje z con decremento de 10.
        case 'k':
            anguloEnz=anguloEnz-10;
            break;

		//Encender-Apagar Luz
		case 'e':
			//Activamos la luz
			glEnable(GL_LIGHTING);
			glEnable(GL_COLOR_MATERIAL);
		break;
		//Desactivamos la luz
		case 'a': glDisable(GL_LIGHTING);
		break;
		// Decrementamos el valor de la posicion de la luz con la variables movLuz que pertenece al eje X.
		case 's':
			movLuz-= 0.5;
		break;
		// Incrementamos el valor de la posicion de la luz con la variable movLuz que pertenece al eje x.
		case 'd':
			movLuz+= 0.5;
		break;

    }

	//glutPostRedisplay();
}
// Metodo principal
int main(int argc, char **argv) {
	// Inicializamos la ventana
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	// Indicamos la posicion de la ventana
    glutInitWindowPosition(10, 10);
	// Indicamos el tamaño de la ventana
    glutInitWindowSize(800, 400);
	// Indicamos el titulo de la ventana
    glutCreateWindow("Flor");

	// Texturas a usar
	loadTextureFromFile( filename, filename1, filename2, filename3,filename4, filename5);
	//Indicamos la funcion para dibujar la figura
    glutDisplayFunc(display);
	// Indicamos la funcion que controlara el escalado de la ventana
	glutReshapeFunc(ajusta);
    // Cuando la ventana sea escalada entonces se ejecutara esta funcion.
    glutIdleFunc(idle);
	// Llamamos la funcion del teclado para mover la figura presionando teclas
	glutKeyboardFunc(keyboard);
	//Llamamos el bucle que redibuja la ventana
    glutMainLoop();
    return 0;
}

