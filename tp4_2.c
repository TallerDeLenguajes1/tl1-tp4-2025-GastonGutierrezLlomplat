#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 5
#define MAX_PRODUCTOS 10

// Considere la siguiente situación: En una distribuidora necesita implementar la carga de
// productos de preventistas, los cuales recolectan los productos que sus clientes van
// necesitando. El sistema que se utiliza en la empresa es desarrollado por equipos de
// programadores donde cada equipo se encarga de una tarea específica. Usted forma parte del
// equipo de programación que se encargará de hacer el módulo para los preventistas:

// i) Desarrollar una interfaz por consola donde se solicite al usuario la cantidad de
// clientes.
// ii) Solicitar al usuario la carga de los clientes creados dinámicamente en el paso anterior.
// iii) A medida que se dé de alta cada cliente, Generar aleatoriamente la cantidad de
// productos asociados al cliente y sus características.
// Ej: producto cargado nro. 2
// Producto {
// ProductoID=2
// Cantidad = 1;
// *TipoProducto = “Snack”;
// PrecioUnitario = 100;
// }
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
    if (cantidadClientes < 1 && cantidadClientes > MAX_CLIENTES) {
        printf("\nCantidad de clientes incorrecta, los clientes deben estar entre 1 y 5.");
        return 1;
    }


    return 0;
}