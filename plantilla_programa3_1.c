
//Directivas del preprocesador
#include <stdio.h>
#include <stdlib.h>
//Prototipos
void PedirDatos(int codigos[], float saldos[], int num_cli);
void Movimientos(int codigos[], float saldos[], int num_cli);
char Menu();
void EscribirDatos(int codigos[], int num);
void BuscarClientes(int codigos[], float saldos[], int num_cli, float cant_lim, int buscados_codigos[]);
void Limpiar();
void Mostrar_Datos_Enteros(int codigos[], int n);
void Mostrar_Datos_Reales(float saldos[], int n);

int main (void)
{
	int codigos[100],buscados[100], num_cli;
	float saldos[100], cant_lim;
  char menu_return;
  
    
      printf("Cuantos clientes desea buscar: ");
  	  scanf("%d", &num_cli);	
	    PedirDatos(codigos, saldos, num_cli);
      char opcion;
      
do{
      opcion = Menu();
     switch(opcion)
  {
       
     
    	case 'a': 
    	Movimientos(codigos, saldos,num_cli);
    	break;
    	case 'b':
		  printf("Que cantidad limite de dinero desea buscar: ");
		  scanf("%f", &cant_lim);
      printf("\n\n");
		  BuscarClientes(codigos, saldos, num_cli,cant_lim,buscados);
    	break;
   	 	case 'c': 
      Mostrar_Datos_Enteros(codigos,num_cli);
      Mostrar_Datos_Reales(saldos,num_cli);
    	break;
    	case 'd': 
    	break;
		  default:
			printf("\nOpcion Incorrecta\n");
		}
	}while(opcion !='d');

	
	return 0;
}
char Menu()
{     char opcion;
      printf("a)Ingresar y sacar dinero.\n\nb)Buscar clientes.\n\nc)Ver datos.\n\nd)Salir del programa\n");
      scanf(" %c", &opcion);
      return opcion;
}
void Limpiar(){
/* A rellenar por el alumno */
}
void BuscarClientes(int codigos[], float saldos[], int num_cli, float cant_lim, int buscados_codigos[]){
	int a=0; //Añado un iterador para saber el nº de personas buscadas y guardarlas por orden en el array
	float buscados_saldos[100];  //Añado un array para pasarlo a la funcion para poder imprimir tambien los saldos de los buscados
 for(int i=0; i<num_cli; i++)
 {
	if(saldos[i] >= cant_lim)
	{   
		buscados_codigos[a] = codigos[i];
		buscados_saldos[a] = saldos[i];
		a++;
		
	}
 }
  Mostrar_Datos_Enteros(buscados_codigos,a);
  Mostrar_Datos_Reales(buscados_saldos,a);
 

}    
void Mostrar_Datos_Enteros(int codigos[], int n)
{
for(int i=0; i<n; i++)
	{
		printf("Cliente con Codigo: %d\n" , codigos[i]);
	}

}   
void Mostrar_Datos_Reales(float saldos[], int n)
{
for(int i=0; i<n; i++)
	{
		printf("Saldo del cliente %d : %.2f\n" ,i+1, saldos[i]);
	}
  printf("\n\n");
}                                              //array añadido con los saldos de los buscados
void EscribirDatos(int codigos[], int num)
{

	
    

}

void Movimientos(int codigos[], float saldos[], int num_cli){
	int codigo = 0;
  printf("Introduzca el codigo de la persona que desea buscar: ");
  scanf("%d", &codigo);
  printf("\n");
  char opcion;
  int a=0;
  for(int i=0; i<num_cli; i++)
  {
    
     if(codigo == codigos[i])
     {
          a++;
          printf("a)Sacar dinero\n\nb)Depositar dinero\n\n");
          scanf(" %c", &opcion);
          if(opcion == 'a')
          {
              printf("Cuanto dinero desea sacar: ");
              float DineroRetirado = 0;
              scanf(" %f", &DineroRetirado);
              printf("\n");
              if(DineroRetirado <= saldos[i])
              {
                  saldos[i] -= DineroRetirado;
                  printf("Acaba de retirar: %.2f euros\nSu saldo actual es: %.2f euros\n\n",DineroRetirado, saldos[i]);
              }else
              {
                  printf("No puede retirar mas dinero del que tiene en la cuenta\n\n");
              }
              
              
          }else
          {
           printf("Cuanto dinero desea depositar: ");
           float DineroDepositado = 0;
           scanf(" %f", &DineroDepositado);
           saldos[i] += DineroDepositado;
           printf("Acaba de depositar: %.2f euros\nSu saldo actual es: %.2f\n\n",DineroDepositado, saldos[i]);
           
          }
     }
  }
  if(a == 0)
     {
       printf("El codigo introducido no existe\n");
     }

}

void PedirDatos(int codigos[], float saldos[], int num_cli){
	for(int i=0; i<num_cli; i++)
  {
    do
    {
      printf("Introduzca el codigo de la persona num %d: ",i+1);
      scanf("%d", &codigos[i]);
      printf("Introduzca el saldo de la persona num %d: ",i+1);
      scanf("%f",&saldos[i]);
      if(codigos[i] < 0 || saldos[i] < 0)
      {
          printf("Ni el codigo ni el saldo puede ser negativo\n");
      }
      
    }while(codigos[i] < 0 || saldos[i] < 0);
      
      printf("\n");
  }

}




