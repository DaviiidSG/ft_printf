*Este proyecto ha sido creado como parte del currículo de 42 por dserrano*

# Descripción

**Libft** es el primer proyecto del cursus, su objetivo principal es recrear distintas funciones de la librería estándar de C (libc) y algunas funciones adicionales que nos serán de gran utilidad a lo largo del cursus.

Este proyecto permite profundizar y entender mejor el funcionamiento interno de la memoria, el manejo de strings y la gestión de listas enlazadas simples.

# Instrucciones

## Compilación

Este proyecto incluye un **Makefile** que gestiona la compilación de forma automática y se puede usar con los siguientes comandos:

- ``make``: Compila los archivos fuente y genera la librería estática ``libft.a``.
- ``make clean``: Elimina los archivos objeto (``.o``).
- ``make fclean``: Elimina los archivos objeto y la librería estática ``libft.a``
- ``make re``: Compila todo desde cero usando ``fclean`` y luego ``make``.

## Instalación

Para usar **libft** en otros proyectos de C, primero hay que copiar la carpeta de la librería y añadir el siguiente *include* en el programa: ``#include "libft.h"``.\
Para compilar el proyecto hay que enlazarlo primero con la librería utilizando las siguientes flags:

- ``-L``: Sirve para indicar la ruta donde se encuentra el archivo ``libft.a``.
- ``-I``: (Opcional) Sirve para indicar la ruta donde se encuentra el archivo ``libft.h``. Por defecto busca en la carpeta actual.
- ``-l``: Sirve para indicar el nombre de la librería, pero hay que quitar el "lib" y el ".a". Es importante que esta flag se coloque **al final**.

Un ejemplo del comando para compilar enlazando la librería sería: ``cc main.c -L. -lft -o main``.

# Recursos

- Man pages
- C Programming Language (K&R)
- C Programming A Modern Approach 2nd edition. K. N. King

## Uso de IA

En este proyecto utilicé la IA para entender mejor el funcionamiento de algunas funciones no estándar.

# Detalles

Esta librería se divide en 3 bloques:

## 1. Funciones estándar de la libc

| Función         | Descripción                                                                                                                     |
| :-------------: | :-----------------------------------------------------------------------------------------------------------------------------: |
| ft_isalpha      | Comprueba si el parámetro recibido es un carácter alfabético válido.<br>Es equivalente a (isupper(c) || islower(c))             |
| ft_isdigit      | Comprueba si el parámetro recibido es un carácter numérico válido. (del 0 al 9)                                                 |
| ft_isalnum      | Comprueba si el parámetro recibido es un carácter alfanumérico válido.<br>Es equivalente a (ft_isalpha(c) || ft_isdigit(c))     |
| ft_isascii      | Comprueba si el parámetro recibido es un carácter ASCII válido.                                                                 |
| ft_isprint      | Comprueba si el parámetro recibido es un carácter imprimible válido.                                                            |
| ft_strlen       | Calcula la longitud del string recibido como parámetro excluyendo el byte nulo. ('\0')                                          |
| ft_memset       | Rellena *n* bytes de la memoria con el dato recibido como parámetro.                                                            |
| ft_bzero        | Rellena *n* bytes de la memoria con 0.                                                                                          |
| ft_memcpy       | Copia *n* bytes de una parte de la memoria a otra, ignorando posibles solapamientos.                                            |
| ft_memmove      | Copia *n* bytes de una parte de la memoria a otra, previene posibles solapamientos.                                             |
| ft_strlcpy      | Copia *n - 1* carácteres de un string a otro. Garantiza que el resultado termine con el byte nulo.                              |
| ft_strlcat      | Concatena dos cadenas. Garantiza que el resultado termine con el byte nulo.                                                     |
| ft_tolower      | Pasa un carácter de mayúscula a minúscula.                                                                                      |
| ft_toupper      | Pasa un carácter de minúscula a mayúscula.                                                                                      |
| ft_strchr       | Busca un carácter específico dentro del string pasado como parámetro.                                                           |
| ft_strrchr      | Busca un carácter específico dentro del string pasado como parámetro, comienza a buscar desde el final.                         |
| ft_strncmp      | Compara dos strings hasta el enésimo carácter.                                                                                  |
| ft_memchr       | Busca un carácter coincidente dentro de un área de memoria.                                                                     |
| ft_memcmp       | Compara dos espacios de memoria hasta *n* bytes.                                                                                |
| ft_strnstr      | Intenta buscar un string dentro de otro hasta n carácteres.                                                                     |
| ft_atoi         | Transforma un número en formato de string a formato entero.                                                                     |
| ft_calloc       | Reserva una cantidad arbitraria de bytes en memoria con un valor inicial de 0.                                                  |
| ft_strdup       | Duplica el string pasado como parámetro.                                                                                        |

## 2. Funciones adicionales

| Función         | Descripción                                                                                                                     |
| :-------------: | :-----------------------------------------------------------------------------------------------------------------------------: |
| ft_substr       | Copia a desde el enésimo carácter de un string hasta una distancia dada.                                                        |
| ft_strjoin      | Reserva memoria suficiente y concatena dos strings.                                                                             |
| ft_strtrim      | Elimina los carácteres coincidentes con los pasados como parámetros del principio y final de la cadena.                         |
| ft_split        | Divide un string dado un carácter separador.                                                                                    |
| ft_itoa         | Recibe un número entero como parámetro y devuelve un string con su representación.                                              |
| ft_strmapi      | Crea un nuevo string resultante de la aplicación de una función a cada carácter del string, ambos pasados como parámetros.      |
| ft_striteri     | Aplica la función a cada carácter del string, ambos pasados como argumentos a la función. Modifica el carácter si es necesario. |
| ft_putchar_fd   | Envía un carácter al descriptor de archivo especificado.                                                                        |
| ft_putstr_fd    | Envía un string al descriptor de archivo especificado.                                                                          |
| ft_putendl_fd   | Envía un string seguido de un salto de línea al descriptor de archivo especificado.                                             |
| ft_putnbr_fd    | Envía un número entero al descriptor de archivo especificado.                                                                   |

## 3. Funciones para manejar listas enlazadas

| Función         | Descripción                                                                                                                     |
| :-------------: | :-----------------------------------------------------------------------------------------------------------------------------: |
| ft_lstnew       | Reserva memoria y crea un nuevo nodo de una lista.                                                                              |
| ft_lstadd_front | Añade un nuevo nodo al principio de una lista.                                                                                  |
| ft_lstsize      | Devuelve la cantidad de nodos que hay en una lista.                                                                             |
| ft_lstlast      | Devuelve la dirección del último nodo de una lista.                                                                             |
| ft_lstadd_back  | Añade un nuevo nodo al final de una lista.                                                                                      |
| ft_lstdelone    | Elimina de una lista el nodo pasado como parámetro y libera la dirección de memoria que lo contiene.                            |
| ft_lstclear     | Elimina de una lista el nodo pasado como parámetro y todos los nodos siguientes, liberando la memoria de todos.                 |
| ft_lstiter      | Aplica una función al contenido de cada nodo de una lista.                                                                      |
| ft_lstmap       | Crea una nueva lista resultante de la aplicación de una función al contenido de cada nodo.                                      |
