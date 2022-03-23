/*
*	Autor: Daniel Gianetto
*	
*	Objetivo: Adaptar el modo de juego "Sim Dragon" del juego Dragon Ball Z Budokai Tenkaichi 3 de PS2 a un juego de consola en C++.
* 
*/
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <cstdlib>

using namespace std;

struct Personaje
{
	string nombre; //Nombre del personaje.
	int vida; //Empieza en 100. Se puede aumentar hasta 150 con power ups.
	int ataque; //Maximo obtenible = 30. Minimo posible = 5;
	int defensa; //Maximo obtenible = 30. Minimo posible = 5;

	int codigoSeleccion; //Especie de ID que tendra relevancia a la hora de la selección del personaje.
};

struct Enemigo
{
	string nombre = "Cell";
	int vida = 200;
	int ataque = 35;
	int defensa = 25;
};

int inicializarPersonajesJugables(Personaje* arrayPersonajes, const int tamArray)
{
	int retorno = -1;

	string auxNombre[3] = { "Goku","Vegeta","Gohan" };
	int auxVida[3] = { 100,100,100 };
	int auxAtaque[3] = { 10,12,15 };
	int auxDefensa[3] = { 10,8,5 };
	int codigoSeleccion[3] = { 1,2,3 };

	if (arrayPersonajes != NULL && tamArray >= 1)
	{
		for (int i = 0; i < tamArray; i++)
		{
			arrayPersonajes[i].nombre = auxNombre[i];
			arrayPersonajes[i].vida = auxVida[i];
			arrayPersonajes[i].ataque = auxAtaque[i];
			arrayPersonajes[i].defensa = auxDefensa[i];
			arrayPersonajes[i].codigoSeleccion = codigoSeleccion[i];
		}
	}
	return retorno;
}

int menuConChar(char* variableOpcion, const char mensaje[], const char mensajeError[], char letraA, char letraB)
{
	int retorno = -1;
	char auxOpcion;

	if (variableOpcion != NULL && mensaje != NULL && mensajeError != NULL)
	{
		retorno = 0;

		cout << mensaje;
		cin >> auxOpcion;
		system("cls");

		while (auxOpcion != letraA && auxOpcion != letraB)
		{
			cout << mensajeError;
			cin >> auxOpcion;
			system("cls");
		}

		*variableOpcion = auxOpcion;
	}
	
	return retorno;
}

int menuConInt(int* variableOpcion, const char mensaje[], const char mensajeError[], int min, int max)
{
	int retorno = -1;
	int auxOpcion;

	if (variableOpcion != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		cout << mensaje;
		cin >> auxOpcion;
		system("cls");

		while (auxOpcion < 1 || auxOpcion> 3)
		{
			cout << mensajeError;
			cin >> auxOpcion;
			system("cls");
		}

		*variableOpcion = auxOpcion;
	}

	return retorno;
}

int mostrarPersonajeSeleccionado(Personaje* arrayPersonajes, int personajeSeleccionado, int tamArray)
{
	int retorno = -1;
	int i;

	if (arrayPersonajes != NULL && personajeSeleccionado != NULL && tamArray > 0)
	{
		for (i = 0; i < tamArray; i++)
		{
			if (personajeSeleccionado == arrayPersonajes[i].codigoSeleccion)
			{
				cout << "Eligio a " << arrayPersonajes[i].nombre << endl;
				system("pause");
				system("cls");
			}
		}
	}

	return retorno;
}

void mostrarUnPersonaje(Personaje* personaje)
{
	cout << endl << "\t  " << personaje->nombre << endl << "\tVida: " << personaje->vida << endl << "\tAtaque: " << personaje->ataque << endl << "\tDefensa: " << personaje->defensa << endl;
}

int mostrarTodos(Personaje* arrayPersonajes, int tamArray)
{
	int retorno = -1;
	int i;

	if (arrayPersonajes != NULL && tamArray >= 1)
	{
		retorno = 0;
		for (i = 0; i < tamArray; i++)
		{
			mostrarUnPersonaje(&arrayPersonajes[i]);
		}
	}
	return retorno;
}

int entrenamiento(Personaje* personaje)
{
	int retorno = -1;
	srand(time(NULL));
	int puntosAtaqueObtenidos;
	int puntosDefensaObtenidos;
	int cansancio; //Resta puntos de vida luego de entrenar.
	if (personaje != NULL)
	{
		retorno = 0;

		puntosAtaqueObtenidos = 1 + rand() % (6 - 1);
		puntosDefensaObtenidos = 1 + rand() % (6 - 1); //Se guarda ambos numeros "aleatorios" en las variables.

		personaje->ataque += puntosAtaqueObtenidos;
		if (personaje->ataque > 30)
		{
			personaje->ataque = 30;
		}

		personaje->defensa += puntosDefensaObtenidos;
		if (personaje->defensa > 30)
		{
			personaje->defensa = 30;
		}

		cout << "\t\t--ENTRENAMIENTO TERMINADO--\nTu ataque era de " << personaje->ataque - puntosAtaqueObtenidos << " puntos y tras entrenar obtuviste " << puntosAtaqueObtenidos << " de ataque.\nTu defensa era de " <<
				personaje->defensa - puntosDefensaObtenidos << " puntos y tras entrenar obtuviste " << puntosDefensaObtenidos << " de defensa." << endl;
		cout <<"\t\t\t-Ataque: " << personaje->ataque << endl << "\t\t\t-Defensa: " << personaje->defensa << endl;
		system("pause");
		system("cls");

		cansancio = 5 + rand() % (10 - 5);
		personaje->vida -= cansancio;

		if (personaje->vida <= 0)
		{
			personaje->vida = 0;
			cout << "El entrenamiento fue tan intenso que " << personaje->nombre << " perdio toda su energia y murio!!\n\t\t\t-Vida: " << personaje->vida << endl;
			system("pause");
			system("cls");
		}
		else
		{
			cout << "Al entrenar todo el dia " << personaje->nombre << " se siente cansado por lo que pierde " << cansancio << " de vida.\n\t\t\t-Vida: " << personaje->vida << endl;
			system("pause");
			system("cls");
		}
	}
	return retorno;
}

int explorar(Personaje* personaje, int* semillaDisponible, int* banderaPowerUpA)
{
	int retorno = -1;

	srand(time(NULL));
	char respuesta;
	int encuentroRandom;
	int probabilidadPowerUpA;

	encuentroRandom = 1 + rand() % (3 - 1);
	
	if (personaje != NULL && semillaDisponible != NULL && banderaPowerUpA != NULL)
	{
		switch (encuentroRandom)
		{
			case 1:
				if (*banderaPowerUpA != 1)
				{
					cout << "Pasas por la Corporacion Capsula y al encontrarte con Bulma ella te pregunta:\n\"" << personaje->nombre << ", te gustaria ser mi sujeto de prueba para verificar si mi nuevo invento funciona?\"\nBulma espera tu respuesta (s-si/n-no): ";
					cin >> respuesta;
					system("cls");

					while (respuesta != 's' && respuesta != 'n')
					{
						cout << "Bulma: ¿Que? No entendi.\nRecorda s=si y n=no, intenta de nuevo: ";
						cin >> respuesta;
						system("cls");
					}

					probabilidadPowerUpA = 1 + rand() % (11 - 1);
					if (respuesta == 'n')
					{
						cout << "Bulma: Que lastima! Hasta la proxima, " << personaje->nombre << endl;
						system("pause");
						system("cls");
						break;
					}
					else
					{
						if (respuesta == 's' && probabilidadPowerUpA <= 5)
						{
							cout << "Bulma: Genial!" << endl;
							system("pause");
							system("cls");

							
							personaje->vida -= 15;
							personaje->ataque -= 5;
							if (personaje->ataque < 5)
							{
								personaje->ataque = 5;
							}
							personaje->defensa -= 5;
							if (personaje->defensa < 5)
							{
								personaje->defensa = 5;
							}
							cout << "Bulma: Ups! Algo salio mal, tal vez funcione la proxima!\nAl fallar el invento de Bulma perdes 15 puntos de vida, 5 de ataque y 5 de defensa!\n\t\t\tVida: " << personaje->vida <<
								"\n\t\t\tAtaque: " << personaje->ataque << "\n\t\t\tDefensa: " << personaje->defensa << endl;
							system("pause");
							system("cls");
							break;
						}
						else if(respuesta == 's' && probabilidadPowerUpA >= 6)
						{
							cout << "Bulma: Genial!" << endl;
							system("pause");
							system("cls");

							cout << "Bulma: Sii! Funciono, muchas gracias, " << personaje->nombre << ".\nEl nuevo invento de Bulma funciona de maravilla, tu vida maxima aumenta 50 puntos!" << endl;
							system("pause");
							system("cls");

							*banderaPowerUpA = 1;
						}
					}
				}
				else
				{
					cout << "Pasas por la Corporacion Capsula pero pareciera que no hay nadie, decidis volves a casa!" << endl;
				}
				break;
			case 2:
				if (*semillaDisponible != 1)
				{
					cout << "Decidis parar en la Torre de Karin para entrenar, al terminar obtenes 5 puntos de ataque y defensa.\nComo regalo por visitarlo el Maestro Karin te da una semilla del hermitaño!" << endl;
					personaje->ataque += 5;
					if (personaje->ataque > 30)
					{
						cout << "Tu ataque esta al maximo!" << endl;
						personaje->ataque = 30;
					}
					personaje->defensa += 5;
					if (personaje->defensa > 30)
					{
						cout << "Tu defensa esta al maximo!" << endl;
						personaje->defensa = 30;
					}
					*semillaDisponible = 1;
					system("pause");
					system("cls");
				}
				else
				{
					cout << "Decidis parar en la Torre de Karin para entrenar pero el Maestro Karin te dice que no tiene nada nuevo que enseñarte!." << endl;
					system("pause");
					system("cls");
				}
				break;
		}	
	}

	return retorno;
}

int descanso(Personaje* personaje, int* banderaPowerUpA)
{
	srand(time(NULL));
	int retorno = -1;
	int vidaRecuperada;
	int puntosAtaquePerdidos;
	int puntosDefensaPerdidos;

	if (personaje != NULL && banderaPowerUpA != NULL)
	{
		retorno = 0;
			
		vidaRecuperada = 1 + rand() % (10 - 1);
		puntosAtaquePerdidos = 1 + rand() % (5 - 1);
		puntosDefensaPerdidos = 1 + rand() % (5 - 1);

		personaje->vida += vidaRecuperada;
		if (*banderaPowerUpA != 1 && personaje->vida > 100)
		{
			personaje->vida = 100;
		}
		else
		{
			if (*banderaPowerUpA == 1 && personaje->vida > 150)
			{
				personaje->vida = 150;
			}
		}

		personaje->ataque -= puntosAtaquePerdidos;
		if (personaje->ataque < 5)
		{
			personaje->ataque = 5;
		}

		personaje->defensa -= puntosDefensaPerdidos;
		if (personaje->defensa < 5)
		{
			personaje->defensa = 5;
		}
		
		cout << "\t\t--DESCANSASTE TODO EL DIA--\nAl terminar su descanso " << personaje->nombre << " recupera " << vidaRecuperada << " de vida pero pierde " << puntosAtaquePerdidos << " de ataque y " << puntosDefensaPerdidos << " de defensa." << endl;
		cout << "\t\t\t-Vida: " << personaje->vida << endl << "\t\t\t-Ataque: " << personaje->ataque << endl << "\t\t\t-Defensa: " << personaje->defensa << endl;
		system("pause");
		system("cls");
	
	}
	return retorno;
}

int consumirSemilla(Personaje* personaje, int* usoDisponible, int* banderaPowerUpA)
{
	int retorno = -2;
	int cantVidaRegenerada;

	cantVidaRegenerada = personaje->vida / 2;

	if (personaje != NULL && usoDisponible != NULL && banderaPowerUpA != NULL)
	{
		retorno = 0;
		if (*usoDisponible == 1)
		{
			cout << "No te quedan mas semillas del hermitaño!!" << endl;
			system("pause");
			system("cls");
		}
		else
		{
			personaje->vida += cantVidaRegenerada;
			if (*banderaPowerUpA != 1 && personaje->vida > 100)
			{
				personaje->vida = 100;

				personaje->ataque += 5;
				if (personaje->ataque < 30)
				{
					personaje->ataque = 30;
				}

				personaje->defensa += 5;
				if (personaje->defensa < 30)
				{
					personaje->defensa = 30;
				}

				cout << "--CONSUMISTE TU SEMILLA SENSU--" << endl << personaje->nombre << " recupera " << cantVidaRegenerada << " y gana 5 puntos de ataque y defensa.\n\t\t\t-Vida: " << personaje->vida <<
					"\n\t\t\t-Ataque: " << personaje->ataque << "\n\t\t\t-Defensa: " << personaje->defensa << endl;
				*usoDisponible = 1;
				system("pause");
				system("cls");
			}
			else
			{
				if (*banderaPowerUpA == 1 && personaje->vida > 150)
				{
					personaje->vida = 150;
					personaje->ataque += 5;
					if (personaje->ataque < 30)
					{
						personaje->ataque = 30;
					}

					personaje->defensa += 5;
					if (personaje->defensa < 30)
					{
						personaje->defensa = 30;
					}
					cout << "--CONSUMISTE TU SEMILLA SENSU--" << endl << personaje->nombre << " recupera " << cantVidaRegenerada << " y gana 5 puntos de ataque y defensa.\n\t\t\t-Vida: " << personaje->vida <<
						"\n\t\t\t-Ataque: " << personaje->ataque << "\n\t\t\t-Defensa: " << personaje->defensa << endl;
					*usoDisponible = 1;
					system("pause");
					system("cls");
				}
				else
				{
					personaje->ataque += 5;
					if (personaje->ataque < 30)
					{
						personaje->ataque = 30;
					}

					personaje->defensa += 5;
					if (personaje->defensa < 30)
					{
						personaje->defensa = 30;
					}
					cout << "--CONSUMISTE TU SEMILLA SENSU--" << endl << personaje->nombre << " recupera " << cantVidaRegenerada << " y gana 5 puntos de ataque y defensa.\n\t\t\t-Vida: " << personaje->vida <<
						"\n\t\t\t-Ataque: " << personaje->ataque << "\n\t\t\t-Defensa: " << personaje->defensa << endl;
					*usoDisponible = 1;
					system("pause");
					system("cls");
				}				
			}		
		}
	}

	return retorno;
}

int combateFinal(Personaje* personaje, Enemigo* enemigo, int banderaPowerUp)
{
	int retorno = -1;

	int turno = 0;
	int cantCapsulas = 3;
	int accionCombate;

	int danioInfligido = 10;
	int danioTotal = 0;

	if (personaje != NULL && enemigo != NULL)
	{
		cout << "--CELL SE ACERCA--" << endl;
		system("pause");
		system("cls");

		do
		{
			cout << "--DERROTA A CELL--" << endl;
			cout << "HP " << personaje->nombre << ": " << personaje->vida;
			cout << " HP Cell: " << enemigo->vida << endl << endl;

			if (turno == 0)
			{
				cout << "1.Atacar.\n2.Usar capsula curativa(" << cantCapsulas << ")." << endl;
				cin >> accionCombate;

				switch (accionCombate)
				{
					case 1:
						danioTotal = danioInfligido + (personaje->ataque - enemigo->defensa);
						cout << personaje->nombre << " ataca a Cell!" << "\nCell recibe " << danioTotal << " puntos de daño!" << endl;
						enemigo->vida -= danioTotal;
						system("pause");
						system("cls");

						turno = 1;
						break;
					case 2:
						if (cantCapsulas == 0)
						{
							system("cls");
							cout << "--DERROTA A CELL--" << endl;
							cout << "HP " << personaje->nombre << ": " << personaje->vida;
							cout << " HP Cell: " << enemigo->vida << endl << endl;
							cout << "No te quedan mas Capsulas Curativas!" << endl;
							system("pause");
							system("cls");
						}
						else
						{
							cout << personaje->nombre << " uso una Capsula Curativa y recupera 35 puntos de vida!" << endl;
							personaje->vida += 35;
							if (banderaPowerUp == 1 && personaje->vida > 150)
							{
								personaje->vida = 150;
							}
							else
							{
								if (banderaPowerUp == 0 && personaje->vida > 100)
								{
									personaje->vida = 100;
								}
							}
							cantCapsulas--;
							system("pause");
							system("cls");

							turno = 1;
						}
						break;
				}
			}
			else
			{
				if (turno == 1)
				{
					if (enemigo->vida <= 30)
					{
						srand(time(NULL));
						int multiplicadorCura = 1 + rand() % (3 - 1);
						int curaTotal = 15 * multiplicadorCura;

						danioTotal = danioInfligido + (enemigo->ataque - personaje->defensa);

						cout << "Cell ataca a " << personaje->nombre << " y recupera " << curaTotal << " puntos de vida!\n" <<
							personaje->nombre << " recibe " << danioTotal << " puntos de daño!" << endl;

						personaje->vida -= danioTotal;
						enemigo->vida += curaTotal;
						system("pause");
						system("cls");

						turno = 0;
					}
					else
					{
						danioTotal = danioInfligido + (enemigo->ataque - personaje->defensa);
						cout << "Cell ataca a " << personaje->nombre << "!\n" << personaje->nombre << " recibe " << danioTotal << " puntos de daño!" << endl;
						personaje->vida -= danioTotal;
						system("pause");
						system("cls");

						turno = 0;
					}
				}
			}
		} while (personaje->vida > 0 && enemigo->vida > 0);
	}
	
	return retorno;
}

int main()
{
	const int cantPersonajes = 3;
	Personaje personajes[cantPersonajes];
	Enemigo cell;

	char seleccionMenu;
	char volverAlMenu;
	int seleccionPersonaje = 0;
	int seleccionAccion = 0;

	int cuentaRegresiva = 0;

	int banderaMostrarMensaje = 0;
	int banderaSemilla = 0;
	int banderaPowerUpBulma = 0;

	inicializarPersonajesJugables(personajes, cantPersonajes);
	do
	{
		menuConChar(&seleccionMenu, "--SIM DRAGON--\na)JUGAR.\nb)SALIR.\nSeleccione una opcion : ", "--SIM DRAGON--\na)JUGAR.\nb)SALIR.\nError, intente de nuevo: ", 'a', 'b');
		switch (seleccionMenu)
		{
			case 'a':
				cout << "--SELECCION DE PERSONAJE--";
				mostrarTodos(personajes,cantPersonajes);
				menuConInt(&seleccionPersonaje, "Seleccione un personaje (1-Goku, 2-Vegeta, 3-Gohan): ", "Personaje invalido, intente de nuevo (1-Goku, 2-Vegeta, 3-Gohan): ", 1, 3);
				mostrarPersonajeSeleccionado(personajes, seleccionPersonaje, cantPersonajes);

				do
				{
					if (cuentaRegresiva == 15 && banderaMostrarMensaje != 1)
					{
						cout << "A partir de este momento tendras 15 dias para volverte lo mas fuerte posible y enfrentar a Cell!!" << endl;
						banderaMostrarMensaje = 1;
						system("pause");
						system("cls");
					}

					cout << "\t\tDIAS RESTANTES: " << cuentaRegresiva << endl;
					cout << "\t  1.Entrenar.\n\t  2.Explorar.\n\t  3.Descansar.\n\t  4.Consumir Semilla Sensu.\n\t  5.Ver Stats.\n\t  Seleccione una accion: ";
					cin >> seleccionAccion;
					system("cls");

					switch (seleccionAccion)
					{
						case 1:
							entrenamiento(&personajes[seleccionPersonaje - 1]);
							cuentaRegresiva--;
							break;
						case 2:
							explorar(&personajes[seleccionPersonaje - 1], &banderaPowerUpBulma, &banderaSemilla);
							cuentaRegresiva--;
							break;
						case 3:
							descanso(&personajes[seleccionPersonaje - 1],&banderaPowerUpBulma);
							cuentaRegresiva--;
							break;
						case 4:
							consumirSemilla(&personajes[seleccionPersonaje - 1], &banderaSemilla, &banderaPowerUpBulma);
							break;
						case 5:
							mostrarUnPersonaje(&personajes[seleccionPersonaje - 1]);
							system("pause");
							system("cls");
							break;
					}	
				} while (personajes[seleccionPersonaje - 1].vida != 0 && cuentaRegresiva != 0);

				if (cuentaRegresiva == 0)
				{
					combateFinal(&personajes[seleccionPersonaje - 1], &cell, banderaPowerUpBulma);
				}

				if (personajes[seleccionPersonaje - 1].vida <= 0)
				{
					cout << "\t\t\t--CELL TE DERROTO! FIN DEL JUEGO--\nDesea volver al menu principal? (s=si/n=no): ";
					cin >> volverAlMenu;
					system("cls");
				}
				else
				{
					if (cell.vida <= 0)
					{
						cout << "\t\t\t--ENHORABUENA, VENCISTE A CELL!--\nDesea volver al menu principal? (s=si/n=no): ";
						cin >> volverAlMenu;
						system("cls");
					}
				}
				break;
		}
	} while (seleccionMenu != 'b'  && volverAlMenu != 'n'); //b = salir del juego.

	return 0;
}