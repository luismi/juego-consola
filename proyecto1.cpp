#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>

#define PERS_GAL 4//Personajes galeria
#define MIEM_EJER 5//Miembros ejercito
#define SALDOMAXIMO 1000

using namespace std;

/* Estructuras */

struct personaje{
    string nombre;
    string tipo;
    int valor;
    int defensa;
    int ataque;
    int salud;
    bool estado;
};

struct ejercito{
    struct personaje miembros[MIEM_EJER];
    string nombre;
};

/* Variables globales */

ejercito players1;
ejercito players2;
personaje galeria[PERS_GAL];   //Galer�a de personajes del juego
int puntos_1 = SALDOMAXIMO;
int puntos_2 = SALDOMAXIMO;
int fase;               
int id_enemigo, id_propio, aux_salud, ataque;
bool todoCorrecto = false;
int numero;

//Prototipos

void pedir_nombres_jugadores();
void cargar_galeria();
void imprimir_galeria();
void pedir_player1(int &sold, int &pos);
void imprimir_equipo1();
void imprimir_equipo2();
void menu_campo();
void luchar_1();
void luchar_2();
void salida_p1();
void salida_p2();
void cargar_p1();
void cargar_p2();
void terminar_p1();
void terminar_p2();

//Funcion que sobrecarga personajes 

void cargar_galeria()
{
    galeria[0].nombre="Debil";
    galeria[0].valor=25;
    galeria[0].ataque=1;
    galeria[0].defensa=1;
    galeria[0].salud=50;
    galeria[0].estado=true;
    
    galeria[1].nombre="Ofensivo";
    galeria[1].valor=250;
    galeria[1].ataque=2;
    galeria[1].defensa=4;
    galeria[1].salud=50;
    galeria[1].estado=true;
    
    galeria[2].nombre="Defensivo";
    galeria[2].valor=250;
    galeria[2].ataque=4;
    galeria[2].defensa=2;
    galeria[2].salud=50;
    galeria[2].estado=true;
    
    galeria[3].nombre="Destructor";
    galeria[3].valor=450;
    galeria[3].ataque=3;
    galeria[3].defensa=5;
    galeria[3].salud=50;
    galeria[3].estado=true;
}

//Funcion que pide nombre jugadores

void pedir_nombres_jugadores()
{
    int i;
    cout <<"Introduce nombre jugador 1: ";
    fflush (stdin);
    getline (cin,players1.nombre);
    fflush (stdin);
    cout <<"Introduce nombre jugador 2: ";
    fflush (stdin);
    getline (cin,players2.nombre);    
}

void imprimir_galeria()
{
    int i;
    cout << "PERSONAJES DEL JUEGO:" <<endl;
    for (i=0 ; i<PERS_GAL ;i++)
    {
        cout <<i<< " - " << galeria[i].nombre<<"\tDef."
        << i << " - " << galeria[i].defensa<<" At."
        << i << " - " << galeria[i].ataque<<" PRECIO/VALOR: "
        << galeria[i].valor<<endl;
    }
    cout << endl;
}

//Funcion que asigna personajes a players1

void pedir_player1(int &sold, int &pos)
{ 
    int i;
    cout << "Insertar el soldado ID (0-: 3):" << endl;
    cin >> sold;
    fflush (stdin);
    cout << "Colocar en posicion: "<<endl;
    cin >> pos;
    fflush (stdin);
    if (sold >0 && sold<=3 &&  pos>=0 &&  pos<=3) //Tiene que estar entre 0 y 3, y entre 0 y 4 respectivamente
    {   
        
        if (players1.miembros[pos].salud ==50)
        {
            puntos_1 = puntos_1 + players1.miembros[pos].valor;
        }
        //Ahora restamos el saldo
        puntos_1 = puntos_1 - galeria[sold].valor;
        
        //Copiamos el soldado de la galeria al ejercito
        players1.miembros[pos] = galeria[sold];     
    }
    
                                                         
}
void imprimir_equipo1(){
    int i;
    for (i=0;i<MIEM_EJER;i++)
    {
        if (players1.miembros[i].salud==50)
        {
            cout <<"["<<i<<"]\t" << players1.miembros[i].nombre << "\tValor: " << players1.miembros[i].valor;
        }
        else
        {
            cout << "[" << i << "]\t\t\t" << "Valor: ";
        } 
        cout << endl;
    }
    cout << "-----------------------------------" << endl;
    cout << "Creando ejercito jugador: " << players1.nombre << endl;
    cout << "-----------------------------------" << endl;
    cout << "Puntos disponibles: "<< puntos_1 << endl;
    cout << "-----------------------------------" << endl;
    cout << "1 - Agregar/modificar soldado" << endl;
    cout << "2 - Cargar ejercito basico" << endl;
    cout << "0 - Equipo terminado" << endl;
    cout << "Opcion: " << endl;   
    
}
void pedir_player2(int &sold, int &pos)
{ 
    puntos_1=0;
    int i;
    cout << "Insertar el soldado ID (0-: 3):" << endl;
    cin >> sold;
    fflush (stdin);
    cout << "Colocar en posicion: "<<endl;
    cin >> pos;
    fflush (stdin);
    if (sold>0 && sold<=3 && sold>0 && pos<=4){
        if (players2.miembros[pos].salud ==50){
            puntos_2 = puntos_2 + players2.miembros[pos].valor;
        }
        //Ahora restamos el saldo
        puntos_2 = puntos_2 - galeria[sold].valor;
        
        //Copiamos el soldado de la galer�a al ej�rcito
        players2.miembros[pos] = galeria[sold];     
    }
}

void cargar_p1(){
    players1.miembros[0] = galeria[0];
    players1.miembros[1] = galeria[0];
    players1.miembros[2] = galeria[1];
    players1.miembros[3] = galeria[2];
    players1.miembros[4] = galeria[3];
    puntos_1=0;
}
    
void cargar_p2(){
    players2.miembros[0] = galeria[0];
    players2.miembros[1] = galeria[0];
    players2.miembros[2] = galeria[1];
    players2.miembros[3] = galeria[2];
    players2.miembros[4] = galeria[3];
    puntos_2=0;
}
    
void imprimir_equipo2()
{
    int i;
    for (i=0;i<MIEM_EJER;i++)
    {
        if (players2.miembros[i].salud==50)
        {
            cout <<"["<<i<<"]\t" << players2.miembros[i].nombre << "\tValor: " << players1.miembros[i].valor;

        }
        else
        {
            cout << "[" << i << "]\t\t\t" << "Valor: ";
        } 
        cout << endl;
    }
    cout << "-----------------------------------" << endl;
    cout << "Creando ejercito jugador: " << players2.nombre << endl;
    cout << "-----------------------------------" << endl;
    cout << "Puntos disponibles: "<< puntos_2 << endl;
    cout << "-----------------------------------" << endl;
    cout << "1 - Agregar/modificar soldado" << endl;
    cout << "2 - Cargar ejercito basico" << endl;
    cout << "0 - Equipo terminado" << endl;
    cout << "Opcion: " << endl;   
}

void salida_p1()//Comprobamos que todos los personajes del jugador 1 tienen un perfil
{
    int i;
    for (i=0;i<MIEM_EJER;i++){
        if (players1.miembros[i].salud==50)
			todoCorrecto=true;
		else todoCorrecto=false;
    }
}
void salida_p2()//Comprobamos que todos los personajes del jugador 2 tienen un perfil
{
    int i;
    for (i=0;i<MIEM_EJER;i++){
        if (players2.miembros[i].salud==50)
            todoCorrecto=true;
		else todoCorrecto=false;
    }
}

//Campo de Batalla
void menu_campo()
{   
    int i;
    cout << "===================================================" << endl;
    cout << "         CAMPO DE BATALLA           " << endl;
    cout << "===================================================" << endl;
    cout << players1.nombre << "\t\t\t\t" << players2.nombre << endl;
    cout << "----------------------------------------------------" << endl;
    for (i=0;i<MIEM_EJER;i++)
    {
        cout <<"["<<i<<"] " << players1.miembros[i].nombre << " Ps:" << players1.miembros[i].salud  << "\t\t["<<i<<"] "
        << players2.miembros[i].nombre << " Ps:" << players2.miembros[i].salud << endl;
    }
    cout << "----------------------------------------------------" << endl;
}
void luchar_1()//Turno del jugador 1
{
    string salir;
    int op,i;
	cout << "==============TURNO DEL JUGADOR: " <<  players1.nombre << "===============" << endl;
	cout << "1 - Realizar ataque" << endl;
	cout << "2 - Pasar turno" << endl;
	cout << "3 - Abandonar partida" << endl;
	cout << "[Opcion]:" << endl;
	cin >> op;
	fflush (stdin);
	switch (op){
		 case 1:
			{
            numero = rand()%101;//Obtenemos un numero aleatorio
			cout << players1.nombre << " con que personaje realizas el ataque? (ID): " << endl;
			cin >>  id_propio;//Personaje con el que queremos atacar
			fflush (stdin);
			cout << "A que personaje quieres de " << players2.nombre << " quieres atacar? (ID):" << endl;
			cin >> id_enemigo;//Personaje con el que queremos luchar
			fflush (stdin);
			if (players1.miembros[id_propio].salud <= 0){//Comprobamos que el personaje esta vivo
                 players1.miembros[id_propio].estado = false;
                 players1.miembros[id_propio].nombre = "-------------------";
            }
            if (players2.miembros[id_enemigo].salud <= 0){//Comprobamos que el personaje esta vivo
                 players2.miembros[id_enemigo].estado = false;
                 players2.miembros[id_enemigo].nombre = "------------------";
            }
			if (players1.miembros[id_enemigo].estado == true && players2.miembros[id_enemigo].estado == true)
			{//Realizamos el ataque segun el numero aleatorio
                if (numero <=4) ataque =0;
                if (numero >=5 && numero<=95) ataque = (players1.miembros[id_propio].ataque * (numero/5)) / players2.miembros[id_enemigo].defensa;
                if (numero >=96 && numero<=100)  ataque = ((players1.miembros[id_propio].ataque +1) * (numero/5)) / (players2.miembros[id_enemigo].defensa-1);
    				players2.miembros[id_enemigo].salud = players2.miembros[id_enemigo].salud - ataque;
    				cout << "Se ha realizado un impacto de " << ataque << " Puntos de Salud" << endl;
    				fase=4;//Cambio de turno
            }
            else{
                 cout <<"Los muertos no pueden luchar."<<endl;
            }     
			fflush (stdin);
			cout << "Pulse Intro para continuar ..." << endl;
			getchar();
			break;
        }
		case 2:
		{
		  fase=4;//Cambio de turno
		  break;
		}
		case 3:
		{
            cout << "Para salir introducir 'salir' "<<endl;
            getline (cin,salir);
            fflush (stdin);
            if (salir=="salir") fase = 5;//Sale del bucle principal
			break;
		}
		default: break;
    }
}   
void luchar_2()
{
    string salir;
    int op,i;
	cout << "==============TURNO DEL JUGADOR: " <<  players2.nombre << "===============" << endl;
	cout << "1 - Realizar ataque" << endl;
	cout << "2 - Pasar turno" << endl;
	cout << "3 - Abandonar partida" << endl;
	cout << "[Opcion]:" << endl;
	cin >> op;
	fflush (stdin);
	switch (op) {
		case 1:
		{ 
            numero = rand () % 101;
			cout << players2.nombre << " con que personaje realizas el ataque? (ID): " << endl;
			cin >>  id_propio;
			fflush (stdin);
			cout << "A que personaje quieres de " << players1.nombre << " quieres atacar? (ID):" << endl;
			cin >> id_enemigo;
			fflush (stdin);
			if (players1.miembros[id_enemigo].salud <= 0)
            {
                players1.miembros[id_enemigo].estado = false;
                players2.miembros[id_enemigo].nombre = "-------------------";
                }
            if (players2.miembros[id_propio].salud <= 0)
            {
                players2.miembros[id_propio].estado = false;
                players2.miembros[id_propio].nombre = "-------------------";
            }
			if (players1.miembros[id_enemigo].estado == true && players2.miembros[id_enemigo].estado == true)
			{
                if (numero <=4) ataque =0;
    			if (numero >=5 && numero<=95) ataque = ataque = (players2.miembros[id_propio].ataque * (numero/5)) / players1.miembros[id_enemigo].defensa;
    			if (numero >=96 && numero<=100)  ataque = ((players2.miembros[id_propio].ataque +1) * (numero/5)) / (players1.miembros[id_enemigo].defensa-1);
                    players1.miembros[id_enemigo].salud = players1.miembros[id_enemigo].salud - ataque;
                    cout << "Se ha realizado un impacto de " << ataque<< " Puntos de Salud" << endl;
                    fase=3;
                }
            else{
                cout <<"Los muertos no pueden luchar"<<endl;
            }
			fflush (stdin);
			cout << "Pulse Intro para continuar ..." << endl;
			getchar();
			break;
			}
		case 2:
		{
			fase =3;//Cambio de turno
			break;
		}
		case 3:
		{
            cout << "Para salir introducir 'salir' "<<endl;
            getline (cin,salir);
            if (salir=="salir") fase = 5;//Sale del bucle principal
			break;
		}
		default: break;
	}
}
void terminar_p1()
{
    int i,contador;
    contador=0;
    for (i=0;i>MIEM_EJER;i++){//Comprobamos si hay miembros vivos, sino gameover
        if (players2.miembros[i].estado==true){
		  contador++;
        }
    }
    if(contador>4){
        cout <<"Gameover: ganador"<<players1.nombre<<endl;
        fase=5;//Se cumple la condicion de salida del bucle
    }  
}
void terminar_p2()
{
    int i,contador;
    contador=0;
    for (i=0;i>MIEM_EJER;i++){//Comprobamos si hay miembros vivos, sino gameover
        if (players1.miembros[i].estado==true){
            contador++;
        }
    }
    if(contador>4){
        cout <<"Gameover: ganador"<<players2.nombre<<endl;
        fase=5;//Se cumple la condicion de salida del bucle
        }
}
//Programa principal
int main(int argc, char *argv[])
{
    int op,sold,pos,i;
    fase=1;
	cargar_galeria();
    pedir_nombres_jugadores();
	do{
		while(!todoCorrecto || fase ==1){//Crear el ejercito del player 1
        {
            
            system ("cls");
            imprimir_galeria();
            imprimir_equipo1();
			fflush (stdin);
			cin >> op;
			fflush (stdin);
        
			switch (op)
            {
				case 1: //a�adir soldado
				{ 
                    pedir_player1(sold,pos);
					imprimir_equipo1();
					
					break;
				}
				case 2: //Cargar desde funcion
				{
                    cargar_p1();
					break;
				}
				case 0: //OK. Equipo terminado
				{
                    
                    //Comprobar aqui si puntos_1 es menor que 0
                    //Si es negativo, no le deja salir
                    if (puntos_1 >= 0){
                        
                        salida_p1();//Comprobar si el equipo es correcto
                        fase=2;//Siguiente fase
                    }
                    else{
                        //Rebasado el saldo maximo
                        fase=1;
                    }
					break;
				}
				default: break;
			}
		}
        }
        todoCorrecto == false;
		while (fase==2 || todoCorrecto==false) //Crear el ejercito del player 2
        {
			system ("cls");
			imprimir_galeria();
            imprimir_equipo2();
			fflush (stdin);
			cin >> op;
			fflush (stdin);
			switch (op) {
				case 1://a�adir soldado
				{
					pedir_player2(sold,pos);
					imprimir_equipo2();
					break;
				}
				case 2://Cargar desde funcion
				{
                    cargar_p2();
					break;
				}
				case 0://OK. Equipo terminado
				{
				    //Comprueba si puntos_2 es menor que 0
                    //Si es negativo, no le deja salir
                    if (puntos_2 >= 0){
                        
                        salida_p2();//Comprobar si el equipo es correcto
                        fase=3;//Siguiente fase
                    }
                    else{
                        //Rebasado el saldo maximo
                        fase=2;
                    }
					break;
				}				
				default: break;
			}
		}
		
		
        if (fase==3)  //luchar_1: Turno del equipo de player 1
		{   
            
			system ("cls");
			menu_campo();
			luchar_1();
			terminar_p1();//Funcion para que se termine el juego cuando gana player2(No funciona)
		}
		
		if (fase==4)  //luchar_2: Turno del equipo de player 2
		{
			system ("cls");
			menu_campo();
		    luchar_2();
            terminar_p2();//Funcion para que se termine el juego cuando gana player1(No funciona)
		}
		
	} while (fase!=5);
	
    system ("pause");
    return EXIT_SUCCESS;
}













