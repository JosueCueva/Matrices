
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <windows.h>

using namespace std;

void imprimir(int matriz[][100],int,int);
void transpuesta(int matrizt[][100],int,int);
void sumamatrices(int matrizA[][100],int matrizB[][100],int,int,int,int);
void multimatrices(int matrizA[][100],int matrizB[][100],int matrizC[][100],int,int,int,int);

COORD coord={0,0};

void gotoxy(int x,int y)
{
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

float determinante(float A[100][100], short int n)
{
	short int i,j,k;
	float aux,pivote,pivote1,deter=1;
	for(int i=0;i<n;i++){
		pivote=A[i][i];
		for(int j=i+1;j<n;j++){
			pivote1=A[j][i];
			aux=pivote1/pivote;
			for(int k=0;k<n;k++){
				A[j][k]=A[j][k]-aux*A[i][k];
			}
		}
	}
	for(int i=0;i<n;i++)
		deter=deter*A[i][i];
		return deter;
}

int main(){
	short int i,j,n;               
	float A[100][100],deter;
	int opcion;
	int filas=0,columnas=0;
	int mat[100][100],matA[100][100],matB[100][100],matC[100][100],filasA,columnasA,filasB,columnasB;
	do{
		system("cls");
		cout<<"\tMENU DE OPCIONES"<<endl;
		cout<<"1.- Matriz transpuesta"<<endl;
		cout<<"2.- Suma de Matrices"<<endl;
		cout<<"3.- Multiplicacion de Matrices"<<endl;
		cout<<"4.- Determinante de una matriz"<<endl;
		cout<<"5.- Salir"<<endl;
		cout<<"Ingresa una opcion......."<<endl;
		cin>>opcion;
		switch(opcion){
			case 1:
				system("cls");
			    srand(time(0));
			    cout<<"\tMatriz"<<endl;
			    cout<<"Ingrese el numero de filas"<<endl;
			    cin>>filas;
			    cout<<"Ingrese el numero de columnas"<<endl;
			    cin>>columnas;
			    cout<<"Ingreso de matriz"<<endl;
			    imprimir(mat,filas,columnas);
				cout<<endl;
				cout<<"Matriz Transpuesta"<<endl;
				transpuesta(mat,filas,columnas);
					cout<<endl;
					system("PAUSE");
					break;
			case 2:
				system("cls");
				sumamatrices(matA,matB,filasA,columnasA,filasB,columnasB);
				    cout<<endl;
				    system("PAUSE");
				    break;
			case 3:
				system("cls");
				multimatrices(matA,matB,matC,filasA,columnasA,filasB,columnasB);
				    cout<<endl;
				    system("PAUSE");
				    break;
			case 4:
				    system("cls");
	                cout<<"Introduzca el numero de elementos: ";
	                cin>>n;
	                cout<<"Introduzca los valores de la matriz: "<<endl;
	                for(int i=0;i<n;i++){
		                for(int j=0;j<n;j++){
			                gotoxy(j*10,i+3);
			                cin>>A[i][j];
		                }
	                }
	                deter=determinante(A,n);
	                cout<<"\nLa determinante es: "<<deter<<endl;
	                cout<<endl;
	                system("PAUSE");
	                break;
			case 5:
				cout<<"Proceso terminado"<<endl;
					system("PAUSE");
					break;
			default:
				cout<<"Ingrese una opcion valida.....";
				    cout<<endl;
				    system("PAUSE");
				    break;
		}
	}while(opcion!=5);
	
	return 0;
}

void imprimir(int matriz[][100],int filas1,int columnas1)
{
    for(int i=0; i<filas1;i++){
		for(int j=0; j<columnas1; j++){
			cout<<"Ingrese el valor de ("<<i<<","<<j<<") = ";
			cin>>matriz[i][j];
		}
	}
	cout<<"Matriz Original"<<endl;
	for(int i=0;i<filas1;i++){
		for(int j=0;j<columnas1;j++){
			if(matriz[i][j]>=0 and matriz[i][j]<=9)
				cout<<matriz[i][j]<<"  ";
			else
			    cout<<matriz[i][j]<<" "; 	
		}
		cout<<endl;
	}
}

void transpuesta(int matrizt[][100],int filas2,int columnas2)
{
	for(int j=0;j<columnas2;j++){
		for(int i=0;i<filas2;i++){
			if(matrizt[i][j]>=0 and matrizt[i][j]<=9)
				cout<<matrizt[i][j]<<"  ";
			else
			    cout<<matrizt[i][j]<<" "; 	
		}
		cout<<endl;
	}
}

void sumamatrices(int matrizA[][100],int matrizB[][100],int filasA,int columnasA,int filasB,int columnasB)
{
	cout<<"\tMatriz A"<<endl;
	cout<<"Ingrese el numero de filas\n";
	cin>>filasA;
	cout<<"Ingrese el numero de Columnas\n";
	cin>>columnasA;
    cout<<"Ingreso de Matriz A\n";
	for(int i=0; i<filasA;i++){//mueve en las filas
		for(int j=0; j<columnasA; j++){//mueve en las columnas
			cout<<"Ingrese el valor de ("<<i<<","<<j<<") = ";
			cin>>matrizA[i][j];
		}
	}
	cout<<"\tMatriz B"<<endl;
	cout<<"Ingrese el numero de filas\n";
	cin>>filasB;
	cout<<"Ingrese el numero de Columnas\n";
	cin>>columnasB;
    cout<<"Ingreso de Matriz B\n";
	for(int i=0; i<filasB;i++){//mueve en las filas
		for(int j=0; j<columnasB; j++){//mueve en las columnas
			cout<<"Ingrese el valor de ("<<i<<","<<j<<") = ";
			cin>>matrizB[i][j];
		}
	}
	cout<<"\tMatriz A"<<endl;
		for(int i=0;i<filasA;i++){
		for(int j=0;j<columnasA;j++){
			if(matrizA[i][j]>=0 and matrizA[i][j]<=9)
				cout<<matrizA[i][j]<<"  ";
			else
			    cout<<matrizA[i][j]<<" "; 	
		}
		cout<<endl;
	}
	cout<<"\tMatriz B"<<endl;
	for(int i=0;i<filasB;i++){
		for(int j=0;j<columnasB;j++){
			if(matrizB[i][j]>=0 and matrizB[i][j]<=9)
				cout<<matrizB[i][j]<<"  ";
			else
			    cout<<matrizB[i][j]<<" "; 	
		}
		cout<<endl;
	}
	if(filasA==filasB and columnasA==columnasB){
	cout<<"\tSuma Matriz A + B"<<endl;
	for(int i=0;i<filasA;i++){
		for(int j=0;j<columnasA;j++){
			cout<<matrizA[i][j]+matrizB[i][j]<<" ";
			}
			cout<<endl;
		}		
	}else{
		cout<<"\nNo se puede realizar la suma de las matrices ya que no son de la misma dimension"<<endl;
	}
}

void multimatrices(int matrizA[][100],int matrizB[][100],int matrizC[][100],int filasA,int columnasA,int filasB,int columnasB)
{
	cout<<"\tMatriz A"<<endl;
	cout<<"Ingrese el numero de filas\n";
	cin>>filasA;
	cout<<"Ingrese el numero de Columnas\n";
	cin>>columnasA;
    cout<<"Ingreso de Matriz A\n";
	for(int i=0; i<filasA;i++){//mueve en las filas
		for(int j=0; j<columnasA; j++){//mueve en las columnas
			cout<<"Ingrese el valor de ("<<i<<","<<j<<") = ";
			cin>>matrizA[i][j];
		}
	}
	cout<<"\tMatriz B"<<endl;
	cout<<"Ingrese el numero de filas\n";
	cin>>filasB;
	cout<<"Ingrese el numero de Columnas\n";
	cin>>columnasB;
    cout<<"Ingreso de Matriz B\n";
	for(int i=0; i<filasB;i++){//mueve en las filas
		for(int j=0; j<columnasB; j++){//mueve en las columnas
			cout<<"Ingrese el valor de ("<<i<<","<<j<<") = ";
			cin>>matrizB[i][j];
		}
	}
	cout<<"\tMatriz A"<<endl;
		for(int i=0;i<filasA;i++){
		for(int j=0;j<columnasA;j++){
			if(matrizA[i][j]>=0 and matrizA[i][j]<=9)
				cout<<matrizA[i][j]<<"  ";
			else
			    cout<<matrizA[i][j]<<" "; 	
		}
		cout<<endl;
	}
	cout<<"\tMatriz B"<<endl;
	for(int i=0;i<filasB;i++){
		for(int j=0;j<columnasB;j++){
			if(matrizB[i][j]>=0 and matrizB[i][j]<=9)
				cout<<matrizB[i][j]<<"  ";
			else
			    cout<<matrizB[i][j]<<" "; 	
		}
		cout<<endl;
	}
	if(columnasA==filasB){
	cout<<"\tMultiplicacion Matrices A x B"<<endl;
	    for(int i=0;i<filasA;i++){
		    for(int j=0;j<columnasB;j++){
			    matrizC[i][j]=0;
			        for(int k=0;k<columnasA;k++){
				        matrizC[i][j]+=matrizA[i][k]*matrizB[k][j];
			        }
			}
	    }
		            for(int i=0;i<filasA;i++){
				        for(int j=0;j<columnasB;j++){
					        if(matrizC[i][j]>=0 and matrizC[i][j]<=9)
							    cout<<matrizC[i][j]<<" ";
							else
							    cout<<matrizC[i][j]<<" ";			        
		                }
		                cout<<endl;
	                }
	}else{
		cout<<"\nNo se puede realizar la multiplicacion de las matrices ya que la columna de la matriz A no tiene la misma dimension que la fila de la matriz B";
	}
}
