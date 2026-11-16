#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 5
#define MAX_NOMBRE 50

/* Arreglos paralelos: el mismo indice identifica los datos de un producto. */
char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
int demanda[MAX_PRODUCTOS];
float tiempoUnitario[MAX_PRODUCTOS];
float recursoUnitario[MAX_PRODUCTOS];
int cantidad = 0;

/* Prototipos */
int buscarProducto(const char nombre[]);
void registrarProducto(void);
void listarProductos(void);
void editarProducto(void);
void eliminarProducto(void);
void calcularProduccion(void);
void leerTexto(const char mensaje[], char destino[], int capacidad);
int leerEnteroPositivo(const char mensaje[]);
float leerRealNoNegativo(const char mensaje[]);

int main(void) {
    int opcion;

    do {
        printf("\n========== SISTEMA DE OPTIMIZACION DE PRODUCCION ==========\n");
        printf("1. Registrar producto\n");
        printf("2. Mostrar productos\n");
        printf("3. Editar producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Calcular requerimientos y verificar capacidad\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Entrada no valida. Ingrese un numero del menu.\n");
            opcion = 0;
            continue;
        }
        /* Consumir el salto de linea pendiente antes de usar fgets(). */
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }

        switch (opcion) {
            case 1: registrarProducto(); break;
            case 2: listarProductos(); break;
            case 3: editarProducto(); break;
            case 4: eliminarProducto(); break;
            case 5: calcularProduccion(); break;
            case 6: printf("\nPrograma finalizado.\n"); break;
            default: printf("\nOpcion fuera del menu.\n");
        }
    } while (opcion != 6);

    return 0;
}

void leerTexto(const char mensaje[], char destino[], int capacidad) {
    int c;
    printf("%s", mensaje);
    if (fgets(destino, capacidad, stdin) == NULL) {
        destino[0] = '\0';
        return;
    }
    /* Si fgets encontro el salto de linea, reemplazarlo; si no, limpiar excedente. */
    {
        char *salto = strchr(destino, '\n');
        if (salto != NULL) {
            *salto = '\0';
        } else {
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
    }
}

int leerEnteroPositivo(const char mensaje[]) {
    int valor, resultado, c;
    do {
        printf("%s", mensaje);
        resultado = scanf("%d", &valor);
        if (resultado != 1 || valor < 0) {
            printf("Ingrese un numero entero mayor o igual a cero.\n");
            while ((c = getchar()) != '\n' && c != EOF) {}
            valor = -1;
        } else {
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
    } while (valor < 0);
    return valor;
}

float leerRealNoNegativo(const char mensaje[]) {
    float valor;
    int resultado, c;
    do {
        printf("%s", mensaje);
        resultado = scanf("%f", &valor);
        if (resultado != 1 || valor < 0) {
            printf("Ingrese un valor numerico mayor o igual a cero.\n");
            while ((c = getchar()) != '\n' && c != EOF) {}
            valor = -1.0f;
        } else {
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
    } while (valor < 0);
    return valor;
}

int buscarProducto(const char nombre[]) {
    int i;
    for (i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], nombre) == 0) {
            return i;
        }
    }
    return -1;
}

void registrarProducto(void) {
    char nuevoNombre[MAX_NOMBRE];

    if (cantidad >= MAX_PRODUCTOS) {
        printf("\nNo se pueden registrar mas de %d productos.\n", MAX_PRODUCTOS);
        return;
    }

    leerTexto("\nNombre del producto: ", nuevoNombre, MAX_NOMBRE);
    if (nuevoNombre[0] == '\0') {
        printf("El nombre no puede quedar vacio.\n");
        return;
    }
    if (buscarProducto(nuevoNombre) != -1) {
        printf("Ya existe un producto con ese nombre.\n");
        return;
    }

    strcpy(nombres[cantidad], nuevoNombre);
    demanda[cantidad] = leerEnteroPositivo("Cantidad demandada (unidades): ");
    tiempoUnitario[cantidad] = leerRealNoNegativo("Tiempo por unidad (horas): ");
    recursoUnitario[cantidad] = leerRealNoNegativo("Recurso por unidad (unidades de recurso): ");
    cantidad++;

    printf("Producto registrado correctamente.\n");
}

void listarProductos(void) {
    int i;
    if (cantidad == 0) {
        printf("\nNo existen productos registrados.\n");
        return;
    }

    printf("\n%-4s %-24s %-12s %-15s %-18s\n",
           "No.", "Producto", "Demanda", "Tiempo/u (h)", "Recurso/u");
    for (i = 0; i < cantidad; i++) {
        printf("%-4d %-24s %-12d %-15.2f %-18.2f\n",
               i + 1, nombres[i], demanda[i],
               tiempoUnitario[i], recursoUnitario[i]);
    }
}

void editarProducto(void) {
    char referencia[MAX_NOMBRE], nuevoNombre[MAX_NOMBRE];
    int pos, otraPos;

    if (cantidad == 0) {
        printf("\nNo hay productos para editar.\n");
        return;
    }

    leerTexto("\nNombre exacto del producto que desea editar: ",
              referencia, MAX_NOMBRE);
    pos = buscarProducto(referencia);

    if (pos == -1) {
        printf("No se encontro el producto.\n");
        return;
    }

    printf("\nDatos actuales: demanda=%d, tiempo/u=%.2f, recurso/u=%.2f\n",
           demanda[pos], tiempoUnitario[pos], recursoUnitario[pos]);

    leerTexto("Nuevo nombre: ", nuevoNombre, MAX_NOMBRE);
    if (nuevoNombre[0] != '\0') {
        otraPos = buscarProducto(nuevoNombre);
        if (otraPos != -1 && otraPos != pos) {
            printf("Ese nombre ya pertenece a otro producto. Se conserva el nombre anterior.\n");
        } else {
            strcpy(nombres[pos], nuevoNombre);
        }
    }

    demanda[pos] = leerEnteroPositivo("Nueva demanda (unidades): ");
    tiempoUnitario[pos] = leerRealNoNegativo("Nuevo tiempo por unidad (horas): ");
    recursoUnitario[pos] = leerRealNoNegativo("Nuevo recurso por unidad: ");
    printf("Producto actualizado correctamente.\n");
}

void eliminarProducto(void) {
    char referencia[MAX_NOMBRE];
    int pos, i;

    if (cantidad == 0) {
        printf("\nNo hay productos para eliminar.\n");
        return;
    }

    leerTexto("\nNombre exacto del producto que desea eliminar: ",
              referencia, MAX_NOMBRE);
    pos = buscarProducto(referencia);

    if (pos == -1) {
        printf("No se encontro el producto.\n");
        return;
    }

    /* Desplazar todos los arreglos para cerrar el espacio eliminado. */
    for (i = pos; i < cantidad - 1; i++) {
        strcpy(nombres[i], nombres[i + 1]);
        demanda[i] = demanda[i + 1];
        tiempoUnitario[i] = tiempoUnitario[i + 1];
        recursoUnitario[i] = recursoUnitario[i + 1];
    }
    cantidad--;
    printf("Producto eliminado correctamente.\n");
}

void calcularProduccion(void) {
    float tiempoTotal = 0.0f, recursoTotal = 0.0f;
    float tiempoDisponible, recursoDisponible;
    int i;

    if (cantidad == 0) {
        printf("\nRegistre al menos un producto antes de calcular.\n");
        return;
    }

    for (i = 0; i < cantidad; i++) {
        tiempoTotal += demanda[i] * tiempoUnitario[i];
        recursoTotal += demanda[i] * recursoUnitario[i];
    }

    printf("\n========== REQUERIMIENTOS DE PRODUCCION ==========\n");
    for (i = 0; i < cantidad; i++) {
        printf("%s: tiempo=%.2f h | recursos=%.2f\n",
               nombres[i],
               demanda[i] * tiempoUnitario[i],
               demanda[i] * recursoUnitario[i]);
    }
    printf("\nTiempo total requerido: %.2f horas\n", tiempoTotal);
    printf("Recursos totales requeridos: %.2f unidades\n", recursoTotal);

    tiempoDisponible = leerRealNoNegativo(
        "\nIngrese el tiempo de produccion disponible (horas): ");
    recursoDisponible = leerRealNoNegativo(
        "Ingrese la cantidad de recursos disponibles: ");

    printf("\n========== EVALUACION DE CAPACIDAD ==========\n");
    if (tiempoTotal <= tiempoDisponible && recursoTotal <= recursoDisponible) {
        printf("RESULTADO: La fabrica SI puede cumplir la demanda.\n");
    } else {
        printf("RESULTADO: La fabrica NO puede cumplir toda la demanda.\n");
        if (tiempoTotal > tiempoDisponible) {
            printf("- Falta tiempo: %.2f horas.\n", tiempoTotal - tiempoDisponible);
        }
        if (recursoTotal > recursoDisponible) {
            printf("- Faltan recursos: %.2f unidades.\n", recursoTotal - recursoDisponible);
        }
    }
}
