'''
Enunciado del problema:

Utilice una pila (stack) para determinar, para un entero n y una secuencia de 
enteros dada de longitud n, si la secuencia es un palíndromo o no. Es decir, debe 
indicarse si la secuencia se lee igual de izquierda a derecha que al revés (sin 
invertir los dígitos dentro de cada entero).

Entrada
La entrada consiste en un entero n y una secuencia de 
enteros de longitud n.

Salida
Es necesario escribir "SI" o "NO" según convenga.

Observación
Para resolver este ejercicio, basta con utilizar un 
montón de enteros para guardar la primera mitad de 
la secuencia y tratar cada entero restante sólo una 
vez.

Ejemplo de entrada y salida

Input
4 10 20 20 10
Output
SI

Input
5 1 2 3 2 2
Output
NO

'''
pila=[]
# El primero numero indica la cantidad de N enteros que seran ingresados
datos_entrada = list(map(int, input().split(" ")))

#Checamos si es inpar la entrada 
if datos_entrada[0] % 2 != 0:
    #Si es inpar, se elimina el numero central de la lista
    datos_entrada.pop(int(datos_entrada[0]/2)+1)

#Se llena la pila con la mitad de los datos
for i in range(1, (len(datos_entrada)//2)+1):
    pila.append(datos_entrada[i])

#Comapramos el top de la pila con la mitad de la lista
result = False
for i in range(len(datos_entrada)//2, len(datos_entrada)):
    if pila == []:
        break
    if pila.pop() != datos_entrada[i+1]:
        print("NO")
        result = False
        break
if result:
    print("SI")