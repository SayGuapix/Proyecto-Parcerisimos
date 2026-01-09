#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <windows.h>
#include <stdlib.h>
#include <ctime >
#include <cctype>
#include <cstdlib>
#include <conio.h>
#include <random>
//colores
#define Negro 0
#define Azul 1
#define Verde 2
#define Aguamarina 3
#define Rojo 4
#define Purpura 5
#define Amarillo 6
#define Blanco 7
#define Gris 8
#define Azul_Claro 9
#define Verde_claro 10 //A
#define Aguamarina_claro 11 // B
#define Rojo_Claro 12 // C
#define Purpura_claro 13// E
#define Amarillo_claro 14// D
#define Blanco_Brillante 15 //F
//bibliotecas
#include "funciones.h"
using namespace std;

int main (int argc, char *argv[]) {
	fadeMaxButton();
	system("mode con: cols=100 lines=23");
	SetConsoleTitle("Banco Parcerisimos");
	
do{
	inicio();
	
	if(respuesta == 1){
    Retirar();
}		
if(respuesta == 2){
	Depositar();
}
if(respuesta == 3){
    system("cls");
	tui();
	celuco();
	
	console_backforegroundcolor (Negro,Amarillo);
	fila = 7;
	columna = 38;
	Console_SetCursorPosition(columna, fila);
	cout << "Numero de celular: ";
	cin >> numero;

	if(numero == celular){
	system("cls");
	tui();
	Informacion();
	}
	else{
	system("cls");
	tui();
	
	console_backforegroundcolor (Negro,Aguamarina_claro);
	fila = 2;
	columna = 29;
	Console_SetCursorPosition(columna, fila);
	cout << "Parece que eres nuevo, crea una cuenta :)";
	
	fila = 7;
	columna = 38;
	Console_SetCursorPosition(columna, fila);
	cout << "numero de celular: ";
	
	console_backforegroundcolor (Negro,Amarillo);
	fila = 9;
	columna = 38;
	Console_SetCursorPosition(columna, fila);
	cout << "Dinos tu nombre: ";
	
	fila = 11;
	columna = 38;
	Console_SetCursorPosition(columna, fila);
	cout << "Digita tu edad: ";
	
	console_backforegroundcolor (Negro,Blanco_Brillante);
	fila = 7;
	columna = 57;
	Console_SetCursorPosition(columna, fila);
	cin >> celular;
	
	console_backforegroundcolor (Negro,Aguamarina_claro);
	fila = 9;
	columna = 38;
	Console_SetCursorPosition(columna, fila);
	cout << "Dinos tu nombre: ";
	console_backforegroundcolor (Negro,Blanco_Brillante);
	fila = 9;
	columna = 55;
	Console_SetCursorPosition(columna, fila);
	cin >> nombre;
	
	console_backforegroundcolor (Negro,Aguamarina_claro);
	fila = 11;
	columna = 38;
	Console_SetCursorPosition(columna, fila);
	cout << "Digita tu edad: ";
	console_backforegroundcolor (Negro,Blanco_Brillante);
	fila = 11;
	columna = 54;
	Console_SetCursorPosition(columna, fila);
	cin >> edad;
	
	estado = 1;
	Informacion();
	}
}		
	
if(respuesta == 4){
	system("cls");
	tui();
	
	console_backforegroundcolor (Negro,Amarillo);
	fila = 7;
	columna = 38;
	Console_SetCursorPosition(columna, fila);
	cout << "Numero de celular: ";
	cin >> numero;
	
	if(numero == celular){
		system("cls");
		tui();
		Configuracion();
	}
	else{
		system("cls");
		tui();
		
		console_backforegroundcolor (Negro,Aguamarina_claro);
		fila = 2;
		columna = 29;
		Console_SetCursorPosition(columna, fila);
		cout << "Parece que eres nuevo, crea una cuenta :)";
		
		console_backforegroundcolor (Negro,Amarillo);
		fila = 7;
		columna = 38;
		Console_SetCursorPosition(columna, fila);
		cout << "Dinos tu nombre: ";
		
		fila = 9;
		columna = 38;
		Console_SetCursorPosition(columna, fila);
		cout << "numero de celular: ";
		
		fila = 11;
		columna = 38;
		Console_SetCursorPosition(columna, fila);
		cout << "Digita tu edad: ";
		
		console_backforegroundcolor (Negro,Blanco_Brillante);
		fila = 7;
		columna = 55;
		Console_SetCursorPosition(columna, fila);
		cin >> nombre;
		
		fila = 9;
		columna = 57;
		Console_SetCursorPosition(columna, fila);
		cin >> celular;
		
		fila = 11;
		columna = 54;
		Console_SetCursorPosition(columna, fila);
		cin >> edad;
		
		estado = 1;
		Informacion();
	}
}
}while(respuesta != 5);
	system("cls");
	Set_Cursor(0);
	
	console_backforegroundcolor (Negro,Azul);
	fila = 4;
	columna = 32;
	Console_SetCursorPosition(columna, fila);
	cout << "Gracias por";

	console_backforegroundcolor (Negro,Aguamarina);
	fila = 5;
	columna = 32;
	Console_SetCursorPosition(columna, fila);
	cout << "usar";
	
	console_backforegroundcolor (Negro,Azul_Claro);
	fila = 6;
	columna = 32;
	Console_SetCursorPosition(columna, fila);
	cout << "nuestro";
	
	console_backforegroundcolor (Negro,Aguamarina_claro);
	fila = 7;
	columna = 32;
	Console_SetCursorPosition(columna, fila);
	cout << "Banco ;)";
	
	console_backforegroundcolor (Negro,Azul_Claro);
	fila = 6;
	columna = 56;
	Console_SetCursorPosition(columna, fila);
	cout << "LOS";
	console_backforegroundcolor (Negro, Aguamarina_claro);
	fila = 7;
	columna = 60;
	Console_SetCursorPosition(columna, fila);
	cout << "PARCERISIMOS";
	console_backforegroundcolor (Negro,Aguamarina);
	fila = 15;
	columna = 33;
	Console_SetCursorPosition(columna, fila);
	cout << "preciona cualquier tecla para salir";
	
	
	console_backforegroundcolor (Negro,Azul_Claro);
	fila = 3;
	columna = 58;
	Console_SetCursorPosition(columna, fila);
	cout << "   O   ";
	fila = 4;
	columna = 58;
	Console_SetCursorPosition(columna, fila);
	cout << "  /|\\/";
	fila = 5;
	columna = 58;
	Console_SetCursorPosition(columna, fila);
	cout << " / | ";
	fila = 6;
	columna = 60;
	Console_SetCursorPosition(columna, fila);
	cout << "/ \\ ";

	console_backforegroundcolor (Negro,Aguamarina_claro);
	fila = 3;
	columna = 64;
	Console_SetCursorPosition(columna, fila);
	cout << "  O   ";
	fila = 4;
	columna = 64;
	Console_SetCursorPosition(columna, fila);
	cout << "\\/|\\/ ";
	fila = 5;
	columna = 64;
	Console_SetCursorPosition(columna, fila);
	cout << "  | ";
	fila = 6;
	columna = 64;
	Console_SetCursorPosition(columna, fila);
	cout << " / \\ ";

	
	console_backforegroundcolor (Negro,Negro);
	return 0;
}

