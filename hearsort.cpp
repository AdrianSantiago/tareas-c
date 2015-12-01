#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<iostream>
using namespace std;


	typedef struct Nodo{
		int dato;
		Nodo *Sig;
		
	};

	     
        
        
		Nodo* InsertarAlFinal(Nodo* InicioLista)//funcion-------------------------------------
		
    {
             Nodo *NuevoNodo;
             NuevoNodo=(Nodo*)malloc(sizeof(Nodo));
             Nodo *Aux;
             Aux=(Nodo*)malloc(sizeof(Nodo));            
             cout<<"\n Dato:";
             cin>> NuevoNodo->dato;
             NuevoNodo->Sig=NULL;
            
            if (InicioLista==NULL)
              {       
             
             Aux=NuevoNodo;
             
              }
               else {
                      
                       
                       Aux=InicioLista;
                       while(InicioLista->Sig!=NULL)
                       {                                                 
                       
                       InicioLista=InicioLista->Sig;
                       
                       }
                                                                 
                        InicioLista->Sig= NuevoNodo;                        
                               
                    }
                        return Aux;
                       
	 
     }

	
        void Mostrar(Nodo* Lista)//funcion-----------------------------------------------
 {
            
            if(Lista!=NULL){
            while(Lista!= NULL){
            cout<<"| "<<Lista->dato<<" |";
           
            Lista=Lista->Sig;           
            }
        }else
        cout<<"no hay datos";
        
 }
 
 
 Nodo* heapsort(Nodo *inicio,int max)
 {
 	 
int A[max+1],j,item,temp,i,k,n; //es importante crear el arreglo temporal llamado a
n=max;
Nodo*aux1=inicio,*aux2=inicio;
for(i=1;i<=n;i++)           
{                     //se tiene que pasar los datos de la pila uno por uno al arreglo A
	A[i]=aux1->dato;
	aux1=aux1->Sig;
} 



for(k=n;k>0;k--)  
       { 
       for(i=1;i<=k;i++) 
        { 
          item=A[i]; 
          j=i/2; 
    
          while(j>0 && A[j]<item) //nos aseguramos de posicion en arreglo y comparamos
          { 
    
           A[i]=A[j];             
            i=j; 
            j=j/2; 

           } 
           
        A[i]=item; 
        } 

        //mandamos la ''raiz'' al final del arreglo 
		 temp=A[1]; 
         A[1]=A[k]; 
          A[k]=temp;;
		
      } 
cout<<"El orden es:"<<endl; 
 for(i=1;i<=n;i++) 
cout<<A[i] << endl; 


for(i=1;i<=max;i++)           //una vez teniendo el orden correcto se sobre escribe la pila
{                             //y se regresa la referencia de la direcion del primer nodo de la pila
	aux2->dato=A[i];
	aux2=aux2->Sig;
}

return inicio; 


 }
 
	
	
	
	
	
int main(void)
{
    
    Nodo *Inicio;
	Inicio=(Nodo*)malloc(sizeof(Nodo));
    char continuar='s';
    Inicio=NULL;
    
    
    
	do
    {
     
    cout<<"\n\n\t\t----Menu---\n1)Insertar\n2)Mostrar\n3)heapsort\n5)Salir\nOpcion:";
    cin>>continuar;
    fflush(stdin);
    system("cls");
    switch(continuar)
    {
  
    case '1':
               
         Inicio=InsertarAlFinal(Inicio);
         break;
         
    case '2':
    	Mostrar(Inicio);
        break;
    case '3':
    {
	
    	Nodo *aux;
    	aux=Inicio;
    	int numero=0;
    	while(aux!=NULL)
    	{
    		numero++;
    		aux=aux->Sig;
    	}
    Inicio=	heapsort(Inicio,numero );
    }
    	break;
    case '5':
         continuar='n';
         break;                                 
    default:
            continuar='s';                      
         break;
    }                        
                           
                            
                            
    }while(continuar!='n');
    
	
	system("pause>null");
	;
}
