//EQUIPO NUM 6 ---- TUNG TUNG  SAHUR 
// NERY YAHIR GAMBOA MEJIA 
// JORGE ALFREDO ZUNUM GOMEZ
//ALEZANDER REYES LAN
// NOE GOMEZ GARCIA 
//JOSE FERNANDO DOMINGUEZ MONZON


#include <stdio.h>
#include <stdlib.h>

int main() {
    //funcion principal del programa (variables)
    int D = 0, i, j, opcion, prestamos[14][4], devoluciones[14][4], netos[14][4], totales[4], limite[44]; //declaracion de variables y arreglos 
    float promedios[4], porcentaje[4];
    char categorias[4][10] = {"Infantil", "Novela", "Tecnica", "Otros"};
    int topCategoria[4], diaPico[100];

    //inicializacion de arreglos y variables (inicializa todo en 0)
    for (i = 0; i < 14; i++) {
        for (j = 0; j < 4; j++) {
            prestamos[i][j] = 0;
            devoluciones[i][j] = 0;
            netos[i][j] = 0;
        }
    }
//inicializa todo en 0
    for (i = 0; i < 4; i++) {
        totales[i] = 0;
        promedios[i] = 0;
        porcentaje[i] = 0;
        topCategoria[i] = 0;
        diaPico[i] = 0;

          
    }
    system("cls"); //limpia la pantalla 
    printf("\n");


  //bucle principal del programa, dependiendo de la opcion en la operacion que hara el switch
    do {
        printf("Biblioteca de Barrio: Prestamos, Devoluciones y Estadisticas\n\n");
        printf("====== MENU ======\n\n");
        printf("|1|.- Capturar\n");
        printf("|2|.- Reportes\n");
        printf("|3|.- Top y picos\n");
        printf("|4|.- Alertas\n");
        printf("|5|.- Reporte de la semana\n");
        printf("|6|.- Reporte consolidado\n");
        printf("[7]. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        system("cls");

        switch (opcion) {  //evalua la opcion ingresada del usuario
            case 1: //opcion para capturar la opcion que se elegio
            printf("\t=== CAPTURAR DATOS === \n");
                printf("\nIngrese el numero de dias a registrar: ");
                scanf("%d", &D);

                if (D >= 1 && D <= 14) { //verifica que el numero de dias sea valido
                    for (i = 0; i < D; i++) { //bucle para cada dia
                        printf("Dia %d:\n", i + 1); //imp el dia actual 
                        for (j = 0; j < 4; j++) {
                            printf("Ingrese la cantidad de prestamos de la categoria de libros de %s: ", categorias[j]);
                            scanf("%d", &prestamos[i][j]);
                            printf("Ingrese la cantidad de devoluciones de la categoria de libros de %s: ", categorias[j]);
                            scanf("%d", &devoluciones[i][j]);

                            if (prestamos[i][j] < 0 || devoluciones[i][j] < 0) { //verifica que los prestamos y devoluciones no sean negativos 
                                printf("=== ERROR === Los prestamos y devoluciones no pueden ser negativos.\n\n");
                                i--;
                                break;
                            }

                            netos[i][j] = prestamos[i][j] - devoluciones[i][j]; //calcula el neto d ela categoria actual
                            totales[j] += netos[i][j]; //acomula el total de la categoria actual

                            if (netos[i][j] > topCategoria[j]) { // verifica si el neto actual  es mayor que top de categorias
                                topCategoria[j] = netos[i][j]; //actuliza el top d ela categoria 
                                diaPico[j] = i + 1; //actuliza el dia pico de la categoria 
                            }system("cls"); //limpia la pantalla 
                        }
                    }
                } 
                else { //en caso de que dias o sea valido
                    printf("\n\n\t=== ERROR === El numero de dias debe estar entre 1 y 14.\n\n");
                }
                break;
            case 2:
            
                printf("\n\t=== REPORTES ===\n");
                for (i = 0; i < D; i++) {
                    printf("Dia.- %d\n", i + 1);
                    for (j = 0; j < 4; j++) {
                        printf("La categoria %s tiene un total de libros pendientes de: %d libros\n\n", categorias[j], netos[i][j]);
                    }
                }

                for (i = 0; i < 4; i++) {
                    promedios[i] = (float)totales[i] / D;
                    porcentaje[i] = ((float)totales[i] / (totales[0] + totales[1] + totales[2] + totales[3])) * 100;
                    printf("Promedio de %s: %.2f\n", categorias[i], promedios[i]);
                    printf("Porcentaje de %s: %.2f%%\n\n", categorias[i], porcentaje[i]);
                }
                if (D == 0) { 
                    printf("\n=== ERROR === Primero debe capturar los datos.\n\n");}
                break;
            case 3:
                printf("\n\t=== TOP Y PICOS ===\n");
                for (i = 0; i < 4; i++) {
                    printf("Top de libros de %s: %d en el dia %d\n\n", categorias[i], topCategoria[i], diaPico[i]);
                }
                if (D == 0) { 
                    printf("\n=== ERROR === Primero debe capturar los datos (Opcion 1).\n\n");}
                break;
                case 4: 
                printf("\n\t=== ALERTAS!! ===\n");
                
                // Si no se han capturado datos, salir
                if (D <= 0) {
                    printf("=== ERROR === Primero debe capturar los datos (Opcion 1).\n\n");
                    break;
                }
                
                int limite_prestamos = 44; // Definimos el lÃ­mite aquÃ­
                int alerta_encontrada = 0;

                // Bucle para cada dÃ­a capturado
                for (i = 0; i < D; i++) {
                    // Bucle para cada categorÃ­a
                    for (j = 0; j < 4; j++) { 
                        // Verifica si los prestamos superan el limite de 44
                        if (prestamos[i][j] >= limite_prestamos) { 
                            printf("ALERTA!! - La categoria de los libros de %s supero el limite de %d en el dia %d (Prestamos: %d)\n\n", 
                                   categorias[j], limite_prestamos, i + 1, prestamos[i][j]); 
                            alerta_encontrada = 1;
                        }
                    }
                }
                
                // Si el bucle terminÃ³ sin encontrar ninguna alerta
                if (alerta_encontrada == 0) {
                    printf("NO HAY ALERTAS, TODO EN ORDEN ^w^\n\n");
                }
                break;
            case 5: 
            printf("\t=== REPORTE SEMANAL ===\n");
                for (i = 0; i < D; i++) {
                printf("Dia.-  %d\n", i + 1);
                for (j = 0; j < 4; j++) {
                        printf("Libros de la categoria de %s: cuenta con un total de prestamos de %d\n", categorias[j], prestamos[i][j]);
                        printf("Libros de la categoria de %s: cuenta con un total de devoluciones de %d\n\n", categorias[j], devoluciones[i][j] );
                    }
                }
                if (D == 0) { 
                    printf("\n=== ERROR === Primero debe capturar los datos (Opcion 1).\n\n");}
                break;
                case 6: // REPORTE FINAL CONSOLIDADO 
                if (D == 0) {
                    printf("=== ERROR === Primero debe capturar los datos (Opcion 1).\n\n");
                } else {
                    printf("\n\t=== REPORTE FINAL CONSOLIDADO  ===\n");
                    
                    // Recalcular la suma total de netos (necesario para el cÃ¡lculo de porcentaje)
                    int sumaTotalNetos = 0;
                    for (i = 0; i < 4; i++) {
                        sumaTotalNetos += totales[i];
                    }

                    printf("\n------------------------------------------------------------------------\n");
                    printf("| %-10s | %-15s | %-12s | %-10s |\n", 
                           "CATEGORIA", "NETO ACUMULADO", "PROM. DIARIO", "PORCENTAJE");
                    printf("------------------------------------------------------------------------\n");

                    for (i = 0; i < 4; i++) {
                        // CÃ¡lculo de Promedios
                        promedios[i] = (D > 0) ? (float)totales[i] / D : 0.0;
                        
                        // CÃ¡lculo de Porcentajes
                        if (sumaTotalNetos > 0) {
                            porcentaje[i] = ((float)totales[i] / sumaTotalNetos) * 100;
                        } else {
                            porcentaje[i] = 0.0;
                        }
                        
                        // ImpresiÃ³n de fila del reporte (Formato tabular)
                        printf("| %-10s | %15d | %12.2f | %10.2f%% |\n", 
                               categorias[i], totales[i], promedios[i], porcentaje[i]);
                    }
                    printf("------------------------------------------------------------------------\n");
                    printf("| %-10s | %15d | %12s | %10.2f%% |\n", 
                           "TOTALES", sumaTotalNetos, "-", (sumaTotalNetos != 0 ? 100.00 : 0.00)); 
                    printf("------------------------------------------------------------------------\n");
                }
                break;
            case 7:
                printf("\n\t=== SALIENDO DEL SISTEMA ===\n");
                printf(".....\n");
                printf("....\n");
                printf("...\n");
                printf("..\n");
                printf(".\n");
                printf("Programa finalizado, que tenga un buen dia ^w^");
                break;
            default:
                printf("=== OPCION INVALIDA ===. Por favor, ingrese una opcion valida.\n");
        }
    } while (opcion != 7);

   
    printf("\n");

    return 0;
}