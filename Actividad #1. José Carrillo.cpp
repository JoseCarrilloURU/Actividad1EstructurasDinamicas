// Actividad #1 Estructuras dinamicas de datos. Jose Carrillo

#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{

    int dato;
    struct nodo * siguiente;

}NODO;

 NODO * CrearNodo(int dato);
 int InsertarInicio(NODO **cabeza, int dato);
 int InsertarFinal(NODO **cabeza, int dato);
 void ImprimirLista(NODO *cabeza);
 int EstaVacia(NODO *cabeza);
 int ExisteElemento(NODO *, int dato );

int main (){

    NODO *cabeza = NULL ;
    int res, var, flag, opc;



    InsertarInicio(&cabeza, 3);
    InsertarInicio(&cabeza, 7);
    InsertarInicio(&cabeza, 0);
    InsertarInicio(&cabeza, 3);
    InsertarFinal(&cabeza, 9);
    InsertarFinal(&cabeza, 8);
    InsertarFinal(&cabeza, 2);
    InsertarFinal(&cabeza, 3);
    
    do{
    ImprimirLista(cabeza);  
    
 printf ("\nIntroduzca un numero a buscar: ");
    scanf ("%d", &var);
    res=  ExisteElemento(cabeza , var);
    if(res ==1 ){
        printf("\nEl elemento buscado esta en la lista.");
    }else{
        printf("\nEl elemento buscado NO esta en la lista.");
    }
    
    printf ("\n\nDesea buscar de nuevo? \n0 = N; 1 = Y\nSu opcion: ");
        scanf ("%d", &opc);
        printf ("\n");
        switch (opc){
        case 0: flag = 0;
  break;
  case 1: flag = 1;
  break;
  default: printf ("El valor no esta en el rango.");
  flag = 0;
  break; 
 }   
 
 
}while (flag != 0);


    return 0 ;
}

NODO * CrearNodo(int dato){

    NODO *nuevo = NULL;

    nuevo = (NODO*)malloc (sizeof(NODO));

    if (nuevo != NULL){
        nuevo ->dato = dato;
        nuevo ->siguiente = NULL;
    }

    return nuevo;
}
 int InsertarInicio(NODO **cabeza, int dato){

     NODO  *nuevo = NULL;
     nuevo = CrearNodo(dato);
     if(nuevo != NULL){
        nuevo ->siguiente = *cabeza;
        *cabeza =nuevo;
        return 1;
     }

     return 0 ;
 }

void ImprimirLista(NODO *cabeza){

    NODO *nAux = cabeza;

    while( nAux != NULL){
        printf("%d ", nAux ->dato);
        nAux= nAux ->siguiente;
    }

  }

int InsertarFinal(NODO **cabeza, int dato){

   NODO  *nuevo = NULL, *nAux= * cabeza;

   nuevo = CrearNodo(dato);

   if( nuevo != NULL){
        while(nAux ->siguiente!=NULL){
            nAux  = nAux ->siguiente;
        }
        nAux ->siguiente= nuevo;
        return 1;
   }

   return 0 ;
   }


int EstaVacia(NODO *cabeza){
    if(cabeza == NULL){
        return 1 ;
    }else {
        return 0 ;
    }
}

 int ExisteElemento(NODO * cabeza, int dato ){
    NODO *nAux = cabeza;

    while(nAux != NULL){
        if(nAux ->dato== dato){
            return 1;
        }
        nAux  = nAux ->siguiente;
    }

    return 0 ;
 }
