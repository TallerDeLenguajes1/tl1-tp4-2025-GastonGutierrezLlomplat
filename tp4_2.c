#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CLIENTES 5
#define MAX_PRODUCTOS 10

// Considere la siguiente situación: En una distribuidora necesita implementar la carga de
// productos de preventistas, los cuales recolectan los productos que sus clientes van
// necesitando. El sistema que se utiliza en la empresa es desarrollado por equipos de
// programadores donde cada equipo se encarga de una tarea específica. Usted forma parte del
// equipo de programación que se encargará de hacer el módulo para los preventistas:


// iv) Implemente una función que calcule el costo total de un producto. Esta función debe
// recibir como parámetro el producto y devolver el resultado de calcular la Cantidad por
// el PrecioUnitario.
// v) Mostrar por pantalla todo lo cargado. Incluyendo un total a pagar por cliente
// (sumatoria del costo de todos los productos)

// Definiciones
char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

struct Producto
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
};

struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    struct Producto *Productos   // El tamaño de este arreglo depende de la variable
};

int main()
{
    srand(time(NULL));

    // Cantidad de clientes
    int cantidadClientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantidadClientes);

    // Control de cantidad de clientes
    if (cantidadClientes < 1 && cantidadClientes > MAX_CLIENTES)
    {
        printf("\nCantidad de clientes incorrecta, los clientes deben estar entre 1 y 5.");
        return 1;
    }

    // Arreglo dinámico de clientes
    struct Cliente *clientes = (struct Cliente *)malloc(sizeof(struct Cliente) * cantidadClientes);

    // Carga de datos para clientes
    for (int i = 0; i < cantidadClientes; i++)
    {
        clientes[i].ClienteID = i + 1;

        // Nombre del cliente
        char buffer[100];
        printf("\nIngrese el nombre del cliente: ");
        gets(buffer);
        clientes[i].NombreCliente = (char *)malloc(strlen(buffer) + 1);
        strcpy(clientes[i].NombreCliente, buffer); // strcpy(destino, origen)

        // Cantidad aleatoria de productos
        clientes[i].CantidadProductosAPedir = (rand() % 5) + 1; // Valores entre 1 y x, siempre (rand() % x) + 1

        // Arreglo dinámico de productos
        clientes[i].Productos = (struct Producto *)malloc(sizeof(struct Producto) * clientes[i].CantidadProductosAPedir);

        for (int j = 0; i < clientes[i].CantidadProductosAPedir; j++)
        {
            clientes[i].Productos[j].ProductoID = j + 1;
            clientes[i].Productos[j].Cantidad = (rand() % 10) + 1;
            int tipoIndex = (rand() % 5) + 1;
            clientes[i].Productos[j].TipoProducto = TiposProductos[tipoIndex];
            clientes[i].Productos[j].PrecioUnitario = rand() % (100 - 10 + 1) + 10; // Valores especificos: rand() % (max - min + 1) + min

        }
        
    }

    return 0;
}