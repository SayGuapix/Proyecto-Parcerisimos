#ifndef DECLARACIONES_H
#define DECLARACIONES_H

using namespace std;

//declaraciones globales
int columna, fila;
int total_dinero;

string nombre;
unsigned int celular;
int otro;
string valido;
int estado;
int cambiado;
int historial_retiro;
int historial_deposito;

int edad;
string edad_;

unsigned int numero;
string numero_;

int cambiar;
string cambiar_;

int respuesta;
string respuesta_;

int sacar;
string sacar_;

int enviar;
string enviar_;


string Convert_ToString(float numero){
	stringstream cadena_char;
	cadena_char << numero;
	return cadena_char.str();
}

void console_backforegroundcolor (int background_color, int foreground_color){
	
	int colorBF_int=
		background_color*16+foreground_color;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorBF_int);
}

void Console_SetCursorPosition(int columna, int fila){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = columna;
	dwPos.Y = fila;
	SetConsoleCursorPosition(hcon, dwPos);
}

void Set_Cursor(int value){
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	cci.bVisible = value;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void fadeMaxButton(){
	HWND consoleWindow;
	consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE,GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

void Thread_Sleep(double tiempo)
{
	clock_t tiempo_inicial = clock();
	double e = 0;
	do
	{
	e = 1000 * double(clock() - tiempo_inicial) / CLOCKS_PER_SEC;
	} while (e < tiempo);
}

void tui(){
	char caract1, caract2, caract3;
	caract1 = 223; //techo
	caract2 = 220; //piso
	caract3 = 219; //paredes
	int columna, fila;
		
	console_backforegroundcolor (Negro,Aguamarina_claro);
	fila = 0; //techo
	for( columna = 0; columna<=99; columna=columna+1 ){
     	Console_SetCursorPosition(columna, fila); 
		cout << caract1;
	}
	
	console_backforegroundcolor (Negro,Aguamarina_claro);
	fila = 22; //barra de estado
	for( columna =0; columna<=99; columna=columna+1 ){
		Console_SetCursorPosition(columna, fila); 
		cout << caract2;
	}
		
	console_backforegroundcolor (Negro,Aguamarina_claro);
	columna = 0; //paredes
	for( fila = 0; fila<=22; fila=fila+1 ){
		Console_SetCursorPosition(columna, fila); 
		cout << caract3;
	}
		
	columna = 99; //paredes
	for( fila = 0; fila<=22; fila=fila+1 ){
		Console_SetCursorPosition(columna, fila); 
		cout << caract3;
	}
}


void inicio(){
	system("cls");
	tui();
			
	console_backforegroundcolor (Negro,Aguamarina_claro);
	fila = 1;
	columna = 40;
	Console_SetCursorPosition(columna, fila);
	cout << "BANCO PARCERISIMOS";
			
	console_backforegroundcolor (Negro,Amarillo);
	fila = 11;
	columna = 42;
	Console_SetCursorPosition(columna, fila);
	cout << "1. Retirar";
	console_backforegroundcolor (Negro,Verde_claro);
	fila = 13;
	columna = 42;
	Console_SetCursorPosition(columna, fila);
	cout << "2. Depositar";
	console_backforegroundcolor (Negro,Azul_Claro);
	fila = 15;
	columna = 42;
	Console_SetCursorPosition(columna, fila);
	cout << "3. Ver cuenta";
	console_backforegroundcolor (Negro,Amarillo_claro);
	fila = 17;
	columna = 42;
	Console_SetCursorPosition(columna, fila);
	cout << "4. Configurar cuenta";
	console_backforegroundcolor (Negro,Rojo_Claro);
	fila = 19;
	columna = 42;
	Console_SetCursorPosition(columna, fila);
	cout << "5. Salir";
	
	console_backforegroundcolor (Negro,Blanco_Brillante);
	fila = 7;
	columna = 38;
	Console_SetCursorPosition(columna, fila);
	cout << "Que vamos a hacer hoy? = ";
	console_backforegroundcolor (Negro,Amarillo_claro);
	getline(cin, respuesta_);
	istringstream(respuesta_) >> respuesta;
}

	
class operaciones{
	public:
	int dinero;
	int total;
	
void depositar(){
	total += dinero;
	historial_deposito = dinero;
}
void retirar(){	
	if (dinero <= total) {
	total -= dinero;
	historial_retiro = dinero;
} 
    else {
		system("cls");
		tui();
		
		console_backforegroundcolor (Negro,Rojo_Claro);
		fila = 9;
		columna = 40;
		Console_SetCursorPosition(columna, fila);
		cout << "Dinero insuficiente";
		
		console_backforegroundcolor (Negro,Blanco);
		fila = 11;
		columna = 36;
		Console_SetCursorPosition(columna, fila);
		cout << "Revisa los fondos de tu cuenta";
		fila = 12;
		columna = 39;
		Console_SetCursorPosition(columna, fila);
		cout << "e intentalo nuevamente";
	}
	}
	Operaciones(){
	total = 0; 
	}
};

operaciones cuenta;

void Informacion(){
	system("cls");
	tui();
	
	console_backforegroundcolor (Negro,Azul_Claro);
	fila = 2;
	columna = 40;
	Console_SetCursorPosition(columna, fila);
	cout << "BANCO PARCERISIMOS";	
	
	console_backforegroundcolor (Negro,Aguamarina_claro);
	fila = 5;
	columna = 5;
	Console_SetCursorPosition(columna, fila);
	cout << "Esta es toda la informacion de tu cuenta:";
	
	console_backforegroundcolor (Negro,Blanco_Brillante);
	fila = 8;
	columna = 5;
	Console_SetCursorPosition(columna, fila);
	cout << "Nombre: " << nombre;
	
	fila = 9;
	columna = 5;
	Console_SetCursorPosition(columna, fila);
	cout << "Numero de cuenta: " << celular;
	
	fila = 10;
	columna = 5;
	Console_SetCursorPosition(columna, fila);
	cout << "edad: " << edad;
	
	console_backforegroundcolor (Negro,Amarillo);
	fila = 12;
	columna = 5;
	Console_SetCursorPosition(columna, fila);
	cout << "Dinero: " << cuenta.total;
	
	console_backforegroundcolor (Negro,Blanco_Brillante);
	fila = 13;
	columna = 5;
	Console_SetCursorPosition(columna, fila);
	cout << "Estado de la cuenta: ";
	
	if(estado == 1){
	console_backforegroundcolor (Negro,Verde_claro);
	fila = 13;
	columna = 26;
	Console_SetCursorPosition(columna, fila);
	cout << "Activa";
	}
	if(estado == 2){
		console_backforegroundcolor (Negro,Rojo_Claro);
		fila = 13;
		columna = 26;
		Console_SetCursorPosition(columna, fila);
		cout << "Desactivada";
		
		console_backforegroundcolor (Negro,Gris);
		fila = 17;
		columna = 60;
		Console_SetCursorPosition(columna, fila);
		cout << "Esta cuenta no puede retirar";
		fila = 18;
		columna = 60;
		Console_SetCursorPosition(columna, fila);
		cout << "ni recibir dinero.";
	}
	
	console_backforegroundcolor (Negro,Blanco_Brillante);
	fila = 5;
	columna = 70;
	Console_SetCursorPosition(columna, fila);
	cout << "ultimo movimiento: ";
	
	console_backforegroundcolor (Negro,Verde);
	fila =7;
	columna = 65;
	Console_SetCursorPosition(columna, fila);
	cout << historial_deposito << " Dolares fueron consignados.";
	
	console_backforegroundcolor (Negro,Rojo);
	fila = 8;
	columna = 65;
	Console_SetCursorPosition(columna, fila);
	cout << historial_retiro << " Dolares fueron retirados.";
	
	console_backforegroundcolor (Negro,Aguamarina_claro);
	fila = 20;
	columna = 5;
	Console_SetCursorPosition(columna, fila);
	system("pause");
	inicio();
}

void Configuracion(){
	system("cls");
	tui();
	
	do{
	console_backforegroundcolor (Negro,Aguamarina_claro);
	fila = 2;
	columna = 42;
	Console_SetCursorPosition(columna, fila);
	cout << "CONFIGURACION";
	
	console_backforegroundcolor (Negro,Amarillo);
	fila = 11;
	columna = 40;
	Console_SetCursorPosition(columna, fila);
	cout << "1. Cambiar nombre";
	fila = 13;
	columna = 40;
	Console_SetCursorPosition(columna, fila);
	cout << "2. Cambiar edad";
	fila = 15;
	columna = 40;
	Console_SetCursorPosition(columna, fila);
	cout << "3. Cambiar numero";
	fila = 17;
	columna = 40;
	Console_SetCursorPosition(columna, fila);
	cout << "4. Activar/Desactivar";
	if(estado == 1){
	console_backforegroundcolor (Negro,Aguamarina_claro);
	fila = 2;
	columna = 80;
	Console_SetCursorPosition(columna, fila);
	cout << "Cuenta";
	console_backforegroundcolor (Negro,Verde_claro);
	fila = 2;
	columna = 87;
	Console_SetCursorPosition(columna, fila);
	cout << "Activada";
	}
	if(estado == 2){
	console_backforegroundcolor (Negro,Aguamarina_claro);
	fila = 2;
	columna = 80;
	Console_SetCursorPosition(columna, fila);
	cout << "Cuenta";
	console_backforegroundcolor (Negro,Rojo_Claro);
	fila = 2;
	columna = 87;
	Console_SetCursorPosition(columna, fila);
	cout << "Desactivada";
	}
	console_backforegroundcolor (Negro,Amarillo_claro);
	fila = 19;
	columna = 40;
	Console_SetCursorPosition(columna, fila);
	cout << "5. Guardar y Salir";
	
	console_backforegroundcolor (Negro,Blanco_Brillante);
	fila = 7;
	columna = 38;
	Console_SetCursorPosition(columna, fila);
	cout << "Que quieres cambiar? = ";
	console_backforegroundcolor (Negro,Amarillo_claro);
	getline(cin, cambiar_);
	istringstream(cambiar_) >> cambiar;
	
	if(cambiar == 1){
		console_backforegroundcolor (Negro,Gris);
		fila = 13;
		columna = 40;
		Console_SetCursorPosition(columna, fila);
		cout << "2. Cambiar edad";
		fila = 15;
		columna = 40;
		Console_SetCursorPosition(columna, fila);
		cout << "3. Cambiar numero";
		fila = 17;
		columna = 40;
		Console_SetCursorPosition(columna, fila);
		cout << "4. Activar/Desactivar";
		fila = 19;
		columna = 40;
		Console_SetCursorPosition(columna, fila);
		cout << "5. Guardar y Salir";
		
		console_backforegroundcolor (Negro,Aguamarina_claro);
		fila = 11;
		columna = 40;
		Console_SetCursorPosition(columna, fila);
		cout << "   Cambiar nombre";
		
		fila = 7;
		columna = 38;
		Console_SetCursorPosition(columna, fila);
		cout << "                                ";
		
		console_backforegroundcolor (Negro,Blanco_Brillante);
		console_backforegroundcolor (Negro,Blanco_Brillante);
		fila = 7;
		columna = 38;
		Console_SetCursorPosition(columna, fila);
		cout << "Que quieres cambiar? = ";
		console_backforegroundcolor (Negro,Amarillo_claro);
		getline(cin, cambiar_);
		istringstream(cambiar_) >> nombre;
	}
	if(cambiar == 2){
		console_backforegroundcolor (Negro,Gris);
		fila = 11;
		columna = 40;
		Console_SetCursorPosition(columna, fila);
		cout << "1. Cambiar nombre";
		fila = 15;
		columna = 40;
		Console_SetCursorPosition(columna, fila);
		cout << "3. Cambiar numero";
		fila = 17;
		columna = 40;
		Console_SetCursorPosition(columna, fila);
		cout << "4. Activar/Desactivar";
		fila = 19;
		columna = 40;
		Console_SetCursorPosition(columna, fila);
		cout << "5. Guardar y Salir";
		
		console_backforegroundcolor (Negro,Aguamarina_claro);
		fila = 13;
		columna = 40;
		Console_SetCursorPosition(columna, fila);
		cout << "   Cambiar edad";
		
		fila = 7;
		columna = 38;
		Console_SetCursorPosition(columna, fila);
		cout << "                                ";
		
		console_backforegroundcolor (Negro,Blanco_Brillante);
		fila = 7;
		columna = 38;
		Console_SetCursorPosition(columna, fila);
		cout << "Que quieres cambiar? = ";
		console_backforegroundcolor (Negro,Amarillo_claro);
		getline(cin, cambiar_);
		istringstream(cambiar_) >> edad;
	}
	if(cambiar == 3){
		console_backforegroundcolor (Negro,Gris);
		fila = 11;
		columna = 40;
		Console_SetCursorPosition(columna, fila);
		cout << "1. Cambiar nombre";
		fila = 13;
		columna = 40;
		Console_SetCursorPosition(columna, fila);
		cout << "2. Cambiar edad";
		fila = 17;
		columna = 40;
		Console_SetCursorPosition(columna, fila);
		cout << "4. Activar/Desactivar";
		fila = 19;
		columna = 40;
		Console_SetCursorPosition(columna, fila);
		cout << "5. Guardar y Salir";
		
		console_backforegroundcolor (Negro,Aguamarina_claro);
		fila = 15;
		columna = 40;
		Console_SetCursorPosition(columna, fila);
		cout << "   Cambiar numero";
		
		fila = 7;
		columna = 38;
		Console_SetCursorPosition(columna, fila);
		cout << "                                ";
		
		console_backforegroundcolor (Negro,Blanco_Brillante);
		fila = 7;
		columna = 38;
		Console_SetCursorPosition(columna, fila);
		cout << "Que quieres cambiar? = ";
		console_backforegroundcolor (Negro,Amarillo_claro);
		getline(cin, cambiar_);
		istringstream(cambiar_) >> celular;
	}
	if(cambiar == 4){
		console_backforegroundcolor (Negro,Gris);
		fila = 11;
		columna = 40;
		Console_SetCursorPosition(columna, fila);
		cout << "1. Cambiar nombre";
		fila = 13;
		columna = 40;
		Console_SetCursorPosition(columna, fila);
		cout << "2. Cambiar edad";
		fila = 15;
		columna = 40;
		Console_SetCursorPosition(columna, fila);
		cout << "3. Cambiar numero";
		fila = 19;
		columna = 40;
		Console_SetCursorPosition(columna, fila);
		cout << "5. Guardar y Salir";
		
		console_backforegroundcolor (Negro,Aguamarina_claro);
		fila = 17;
		columna = 40;
		Console_SetCursorPosition(columna, fila);
		cout << "   Activar/Desactivar";
		
		console_backforegroundcolor (Negro,Verde_claro);
		fila = 16;
		columna = 65;
		Console_SetCursorPosition(columna, fila);
		cout << "1. Activar   ";
		
		console_backforegroundcolor (Negro,Rojo_Claro);
		fila = 18;
		columna = 65;
		Console_SetCursorPosition(columna, fila);
		cout << "2. desactivar  ";
		
		fila = 7;
		columna = 38;
		Console_SetCursorPosition(columna, fila);
		cout << "                                ";
		
		console_backforegroundcolor (Negro,Blanco_Brillante);
		fila = 7;
		columna = 38;
		Console_SetCursorPosition(columna, fila);
		cout << "Que quieres cambiar? = ";
		console_backforegroundcolor (Negro,Amarillo_claro);
		getline(cin, cambiar_);
		istringstream(cambiar_) >> estado;
		
	}
	
	system("cls");
	tui();
}while(cambiar != 5);
respuesta = 0;
cambiar = 0;

}

void Retirar(){
	system("cls");
	tui();
	
	// Lista de codigos para retirar
	srand(time(0));
	vector<string> codigos = {
		"1212",
			"4488",
			"2314",
			"9979", 
			"2765",
			"2115"
	};
	int indice = rand() % codigos.size();	

	console_backforegroundcolor (Negro,Amarillo);
	fila = 7;
	columna = 38;
	Console_SetCursorPosition(columna, fila);
	cout << "numero: ";
	cin >> numero;
	
	if(numero != celular){
		system("cls");
		tui();
		
		console_backforegroundcolor (Negro,Rojo_Claro);
		fila = 10;
		columna = 38;
		Console_SetCursorPosition(columna, fila);
		cout << "El usuario no existe";
		
		fila = 20;
		columna = 5;
		Console_SetCursorPosition(columna, fila);
		system("pause");
		inicio();
	}
    else{
		do{
			system("cls");
			tui();
			
			if(estado == 2){
				system("cls");
				tui();
				
				console_backforegroundcolor (Negro,Rojo);
				fila = 7;
				columna = 36;
				Console_SetCursorPosition(columna, fila);
				cout << "Esta cuenta esta desactivada.";
				
				console_backforegroundcolor (Negro,Aguamarina_claro);
				fila = 20;
				columna = 5;
				Console_SetCursorPosition(columna, fila);
				system("pause");
				respuesta = 0;
				numero = -1;
				valido = codigos[indice];
				
			}
			if(estado == 1){
			console_backforegroundcolor (Negro,Blanco);
			fila = 11;
			columna = 38;
			Console_SetCursorPosition(columna, fila);
			cout << "Codigo de seguridad: ";
			
			console_backforegroundcolor (Negro,Purpura_claro);
			fila = 9;
			columna = 40;
			Console_SetCursorPosition(columna, fila);
			cout << "Tu codigo es: " << codigos[indice] << endl;
			
			console_backforegroundcolor (Negro,Verde);
			fila = 11;
			columna = 38;
			Console_SetCursorPosition(columna, fila);
			cout << "Codigo de seguridad: ";
			cin >> valido;
			}
		}while(valido != codigos[indice]);
		
		if(estado == 1){
		system("cls");
		tui();
		
		fila = 9;
		columna = 38;
		Console_SetCursorPosition(columna, fila);
		cout << "cantidad: ";
		cin >> cuenta.dinero;
		
		console_backforegroundcolor (Negro,Amarillo_claro);
		fila = 13;
		columna = 38;
		Console_SetCursorPosition(columna, fila);
		cout << cuenta.dinero << "$" << " retirados con exito";
		cuenta.retirar();
		
		console_backforegroundcolor (Negro,Aguamarina_claro);
		fila = 20;
		columna = 5;
		Console_SetCursorPosition(columna, fila);
		system("pause");
		inicio();
		}
	}
}
	
void Depositar(){
	system("cls");
	tui();
	
	console_backforegroundcolor (Negro,Amarillo);
	fila = 7;
	columna = 38;
	Console_SetCursorPosition(columna, fila);
	cout << "Numero a depositar: ";
	
	fila = 9;
	columna = 38;
	Console_SetCursorPosition(columna, fila);
	cout << "cantidad: ";
	
	console_backforegroundcolor (Negro,Blanco_Brillante);
	fila = 7;
	columna = 58;
	Console_SetCursorPosition(columna, fila);
	getline(cin, enviar_);
	istringstream(enviar_) >> enviar;
	
	if(estado == 2 && enviar == celular){
		system("cls");
		tui();
		
		console_backforegroundcolor (Negro,Rojo);
		fila = 7;
		columna = 36;
		Console_SetCursorPosition(columna, fila);
		cout << "Esta cuenta esta desactivada.";
		
		console_backforegroundcolor (Negro,Aguamarina_claro);
		fila = 20;
		columna = 5;
		Console_SetCursorPosition(columna, fila);
		system("pause");
		respuesta = 0;
		numero = -1;
	}
	
	if(estado == 1 && enviar == celular){
	
	fila = 9;
	columna = 48;
	Console_SetCursorPosition(columna, fila);
	cin >> cuenta.dinero;
	cuenta.depositar();
	
	console_backforegroundcolor (Negro,Verde_claro);
	fila = 13;
	columna = 38;
	Console_SetCursorPosition(columna, fila);
	cout << cuenta.dinero << "$" << " depositado a " << nombre << " con exito";
	
	console_backforegroundcolor (Negro,Aguamarina_claro);
	fila = 20;
	columna = 5;
	Console_SetCursorPosition(columna, fila);
	system("pause");
	respuesta = 0;
	}
	
	if(enviar != celular){
	fila = 9;
	columna = 48;
	Console_SetCursorPosition(columna, fila);
	cin >> otro;
	
	console_backforegroundcolor (Negro,Verde_claro);
	fila = 13;
	columna = 38;
	Console_SetCursorPosition(columna, fila);
	cout << otro << "$" << " depositado con exito";
	
	console_backforegroundcolor (Negro,Aguamarina_claro);
	fila = 20;
	columna = 5;
	Console_SetCursorPosition(columna, fila);
	system("pause");
	inicio();
	respuesta = 0;
	}
	enviar = -1;
}
	
void celuco(){
	console_backforegroundcolor (Negro,Gris);
	fila = 9;
	columna = 39;
	Console_SetCursorPosition(columna, fila);
	cout << "  ___________" << endl;
	fila = 10;
	columna = 39;
	Console_SetCursorPosition(columna, fila);
	cout << " /     o     \\" << endl;
	console_backforegroundcolor (Negro,Blanco);
	fila = 10;
	columna = 41;
	Console_SetCursorPosition(columna, fila);
	cout << "      o" << endl;
	console_backforegroundcolor (Negro,Gris);
	fila = 11;
	columna = 39;
	Console_SetCursorPosition(columna, fila);
	cout << "||            |" << endl;
	fila = 12;
	columna = 39;
	Console_SetCursorPosition(columna, fila);
	cout << "||            |" << endl;
	fila = 13;
	columna = 39;
	Console_SetCursorPosition(columna, fila);
	cout << "||            |" << endl;
	fila = 14;
	columna = 39;
	Console_SetCursorPosition(columna, fila);
	cout << "||            |" << endl;
	fila = 15;
	columna = 39;
	Console_SetCursorPosition(columna, fila);
	cout << "||     $$$    |" << endl;
	fila = 16;
	columna = 39;
	Console_SetCursorPosition(columna, fila);
	cout << "||            |" << endl;
	fila = 17;
	columna = 39;
	Console_SetCursorPosition(columna, fila);
	cout << "||            |" << endl;
	fila = 18;
	columna = 39;
	Console_SetCursorPosition(columna, fila);
	cout << "||            |" << endl;fila = 14;
	columna = 39;
	Console_SetCursorPosition(columna, fila);
	cout << "||            |" << endl;
	fila = 19;
	columna = 39;
	Console_SetCursorPosition(columna, fila);
	cout << " \\\\_=__[]__<_/" << endl;
	console_backforegroundcolor (Negro,Blanco_Brillante);
	fila = 19;
	columna = 43;
	Console_SetCursorPosition(columna, fila);
	cout << "=" << endl;
	console_backforegroundcolor (Negro,Verde);
	fila = 19;
	columna = 46;
	Console_SetCursorPosition(columna, fila);
	cout << "[]" << endl;
	console_backforegroundcolor (Negro,Rojo);
	fila = 19;
	columna = 50;
	Console_SetCursorPosition(columna, fila);
	cout << "<" << endl;
}
	
#endif
