Sistema de Optimización de Producción

1. Descripción del proyecto

Este proyecto consiste en el desarrollo de un sistema de optimización de producción para una fábrica de componentes electrónicos, utilizando el lenguaje de programación C.

El programa permite registrar y administrar hasta cinco productos, almacenar sus datos de producción y calcular el tiempo y los recursos necesarios para satisfacer la demanda.

Además, compara los requerimientos totales con la capacidad disponible de la fábrica para determinar si es posible cumplir con la producción solicitada.

2. Objetivo general

Desarrollar un sistema en lenguaje C que permita administrar los productos de una fábrica de componentes electrónicos, calcular sus requerimientos de producción y evaluar si los recursos y el tiempo disponibles son suficientes.

3. Integrantes del grupo

* Genesis Merino
* Camila Caiza
* Paul Gutierrez

Docente: Lino Cajas
Asignatura: Programación 1
Actividad: Ejercicio de Programación RC1

4. Funcionalidades del sistema

El programa cuenta con las siguientes funcionalidades:

* Registrar productos: permite ingresar hasta cinco productos.
* Listar productos: muestra los productos registrados y sus características.
* Buscar productos: localiza un producto mediante su nombre.
* Editar productos: permite modificar la información de un producto existente.
* Eliminar productos: elimina un producto registrado.
* Calcular producción: determina el tiempo y los recursos necesarios para fabricar los productos.
* Evaluar capacidad: compara los requerimientos de producción con los límites disponibles.

5. Variables utilizadas

El sistema trabaja con los siguientes datos:

Variable	Descripción
Nombre	Nombre del producto
Demanda	Cantidad de unidades solicitadas
Tiempo unitario	Tiempo necesario para fabricar una unidad
Recurso unitario	Recursos consumidos por unidad
Tiempo disponible	Capacidad máxima de tiempo
Recursos disponibles	Capacidad máxima de recursos

6. Modelo matemático

El sistema utiliza las siguientes fórmulas:

Tiempo requerido por producto:

Tiempo = Demanda × Tiempo unitario

Recursos requeridos por producto:

Recursos = Demanda × Recurso unitario

Tiempo total:

Tiempo total = Σ (Demanda × Tiempo unitario)

Recursos totales:

Recursos totales = Σ (Demanda × Recurso unitario)

La producción se considera factible cuando se cumplen simultáneamente las dos condiciones:

* Tiempo total ≤ Tiempo disponible.
* Recursos totales ≤ Recursos disponibles.

7. Tecnologías utilizadas

* Lenguaje de programación C.
* Compilador GCC.
* Arreglos paralelos.
* Funciones y programación modular.
* Estructuras de control: if, switch, for y do-while.
* Manejo de cadenas de caracteres.

8. Estructura del proyecto

Sistema-Optimizacion-Produccion/
│
├── sistema_optimizacion_produccion.c
├── diagrama_flujo_sistema.png
└── README.md

9. Compilación y ejecución

Para compilar el programa utilizando GCC:

gcc sistema_optimizacion_produccion.c -o sistema_produccion

Para ejecutar en Linux o macOS:

./sistema_produccion

En Windows:

sistema_produccion.exe

10. Ejemplo de resultados

Con los datos de prueba utilizados en el informe, el sistema obtiene:

* Tiempo total requerido: 14,60 horas.
* Recursos totales requeridos: 403 unidades.

Si la fábrica dispone de 16 horas y 450 unidades de recursos, puede cumplir con la producción solicitada.

Si alguna de las capacidades disponibles es inferior a la requerida, el programa informa que la producción no es factible.

11. Restricciones del proyecto

* Se permite registrar un máximo de cinco productos.
* Los datos se almacenan temporalmente en memoria.
* Se utilizan arreglos paralelos.
* No se utilizan estructuras (struct) ni archivos para almacenar los registros.
* La búsqueda se implementa mediante un recorrido secuencial.

12. Conclusión

El desarrollo de este sistema permite aplicar los conocimientos de programación en C mediante el uso de arreglos, funciones, ciclos, condicionales y manejo de cadenas.

La solución facilita la administración de los productos y permite calcular los requerimientos de producción para determinar si la capacidad disponible de la fábrica es suficiente.

Este proyecto demuestra cómo la programación puede utilizarse para resolver problemas relacionados con la planificación y optimización de procesos productivos.

⸻

Proyecto académico desarrollado para la asignatura Programación 1
