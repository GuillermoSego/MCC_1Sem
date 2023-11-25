
# include <stdio.h>

// Función para imprimir números unitarios en formato texto.
void unit(int u){
    printf(u == 1 ? "uno" : u == 2 ? "dos" : u == 3 ? "tres" : u == 4 ? "cuatro" : 
    u == 5 ? "cinco" : u == 6 ? "seis" : u == 7 ? "siete" : u == 8 ? "ocho" : 
    u == 9 ? "nueve" : "");
}

// Función para imprimir números de decenas en formato texto.
void deca(int num){
    int u = (num / 10) % 10;

    // Si el número es entre 11 y 19 (excepto 16-19 que no se manejan aquí)
    printf(u == 1 && num % 10 > 0 ? "dieci" : u == 2 && num % 10 > 0 ? "veinti" : 
    u == 1 && num % 10 == 0 ? "diez" : u == 2 && num % 10 == 0 ? "veinte" :
    u == 3 ? "treinta" : u == 4 ? "cuarenta" : u == 5 ? "cincuenta" : u == 6 ? "sesenta" : 
    u == 7 ? "setenta" : u == 8 ? "ochenta" : u == 9 ? "noventa" : "");

    // Añadir "y" si es necesario, por ejemplo, "treinta y uno"
    if (num % 10 > 1 && u > 2) {
        printf(" y ");
    }
}

// Función para imprimir números de centenas en formato texto.
void hecta(int num){
    int u = (num / 100) % 10 ;

    printf(u == 1 && num % 100 > 0 ? "ciento": u == 1 && num % 100 == 0 ? "cien" : 
    u == 2 ? "doscientos" : u == 3 ? "trescientos" : 
    u == 4 ? "cuatrocientos" : u == 5 ? "quinientos" : u == 6 ? "seiscientos" : 
    u == 7 ? "setecientos" : u == 8 ? "ochocientos" : u == 9 ? "novecientos" : "");
}

// Función para imprimir los miles en formato texto.
void kilo(int u){
    printf(u == 1 ? "mil " : u == 2 ? "dosmil " : u == 3 ? "tresmil " : 
    u == 4 ? "cuatromil " : u == 5 ? "cincomil " : u == 6 ? "seismil " : 
    u == 7 ? "sietemil " : u == 8 ? "ochomil " : u == 9 ? "nuevemil ": "");
}

// Función para imprimir el nombre del mes basado en un número.
void month_function(int u){
    printf(u == 1 ? "enero" : u == 2 ? "febrero" : u == 3 ? "marzo" : 
    u == 4 ? "abril" : u == 5 ? "mayo" : u == 6 ? "junio" : 
    u == 7 ? "julio" : u == 8 ? "agosto" : u == 9 ? "septiembre" : 
    u == 10 ? "octubre" : u == 11 ? "noviembre" : u == 12 ? "diciembre" : "mes invalido");
}

// Función para manejar números especiales entre 11-15.
void special_deca(int u){
    printf(u == 11 ? "once" : u == 12 ? "doce" : u == 13 ? "trece" : u == 14 ? "catorce" : 
    u == 15 ? "quince" : "");
}


int main(){

    // Necesitamos incializar los 8 digitos de la fecha
    int day, month, year;

    // Se escanea la fecha
    printf("Introduce la fecha en formato dd/mm/aaaa con diagonales \n");
    scanf("%d/%d/%d", &day, &month, &year);

    // Pruebas
    // day = 13 ,month = 6, year = 1015;
    
    // Imprime los dias
    if (day/10 == 1 && day % 10 > 0 && day % 10 < 6 ){
        special_deca(day);
    } else{
        deca(day);
        unit(day % 10);
    }
    
    printf(" de ");

    // Imprime los meses
    month_function(month);

    printf(" de ");

    // Imprime los años
    kilo(year / 1000);
    hecta(year);
    if ((year/10)%10 == 1 && year % 10 > 0 && year % 10 < 6 ){
        special_deca(year % 100);
    } else{
        deca(year % 100);
        unit(year % 10);
    }    
  

    return 0;
}