
# Proyecto_Final_Graficaci-n-
En esta imagen podemos observar las librerías que declaramos y vamos a utilizar, también añadimos un GLUint que es el que contiene el número de imágenes que se utilizaran para las texturas
![image](https://user-images.githubusercontent.com/60747457/97510640-c9de5e80-194a-11eb-8074-0cf47522c958.png)

También declaramos un GLfloat el cual nos va a indicar el valor del inicial del Angulo donde se ubicará la luz en el eje x dentro del método Display() y se logra observar cómo ajustamos la imagen al tamaño actual de la pantalla cuando se maximice o minimice.
![image](https://user-images.githubusercontent.com/60747457/97510736-014d0b00-194b-11eb-9345-5d13a4d535b4.png)

Aquí se muestra el método para cargar y llevar a cabo la asignación de texturas
![image](https://user-images.githubusercontent.com/60747457/97510773-1cb81600-194b-11eb-81fe-84b7b6a3cc1d.png)

En esta parte es donde añadimos la imagen que será el centro de la flor y agregamos la generación de la textura en las coordenadas. Este paso lo realizamos con cada una de las 7 hojas, el tronco, pétalo verde, florero, base
![image](https://user-images.githubusercontent.com/60747457/97510865-496c2d80-194b-11eb-97e9-5926ab489255.png)

En esta parte cargamos las imágenes que vamos a utilizar como texturas, cabe resaltar que el formato de imagen debe ser .BMP

![image](https://user-images.githubusercontent.com/60747457/97510919-6a348300-194b-11eb-84ab-3c86f8822fbb.png)

En esta parte haremos uso del Keyboard con el cual podemos manipular el movimiento de la figura con las teclas que están declaradas ahí mismo.
![image](https://user-images.githubusercontent.com/60747457/97510961-89331500-194b-11eb-928b-49444a063ec3.png)


Este es el método principal, con el cual iniciaremos la ventana, su posición, tamaño y título de la misma.
También realizamos la carga de las texturas a utilizar, indicamos la función para dibujar la figura, indicamos la función que controlara el escalado de la ventana, cuando la ventana sea escalada entonces se ejecutara una función., en donde llamamos la función del teclado para mover la figura presionando teclas y finalmente llamamos el bucle que redibuja la ventana


![image](https://user-images.githubusercontent.com/60747457/97511040-b384d280-194b-11eb-9dcd-7779b28bff73.png)
