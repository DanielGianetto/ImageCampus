/*
*	ANALISIS_TM_TP1_GianettoDaniel
* 
*	1. Elegir uno de los posibles escenarios listados abajo.
*	2. Realizar el juego para que funcione con 1 solo jugador.
*	3. Hacer que para iniciar una nueva partida haya que reiniciar el programa.
*	No tiene que haber un game loop implementado.
*	4. Utilizar "if" y todos sus derivados para realización del juego.
*	5. Utilizar "switch" para la realización del juego.
*/
#include <iostream>

using namespace std;

int main()
{
	int opcion;

	cout << "\t\t\t---GOD OF WAR---" << endl;
	system("pause");
	system("cls");

	cout << "Luego de matar a Cloto, Kratos utiliza los hilos del destino a su favor para enfrentarse a Zeus!" << endl;
	system("pause");
	cout << "1-Revisar la sala antes de atravesar el portal.\n2-Atravesar el portal que se abrio al manipular los hilos del destino.\n3-La venganza nunca es buena mata el alma y la envenena.\nQue vas a hacer?: ";
	cin >> opcion;

	if (opcion < 1 || opcion > 3)
	{
		system("cls");
		cout << "Luego de matar a Cloto, Kratos utiliza los hilos del destino a su favor para enfrentarse a Zeus!" << endl;
		cout << "1-Revisar la sala antes de atravesar el portal.\n2-Atravesar el portal que se abrio al manipular los hilos del destino.\n3-La venganza nunca es buena mata el alma y la envenena.\nAccion invalida, intenta de nuevo: ";
		cin >> opcion;
	}

	switch (opcion)
	{
		case 1: //Revisar la sala antes de atravesar el portal.
			system("cls");
			cout << "No hay mucho que ver, el cadaver de Cloto en el centro de la sala, algunas criaturas muertas..." << endl;
			system("pause");
			cout << "Tirada a un costado Kratos ve una gema verde brillante! La recoge y atraviesa el portal el cual lo lleva al pasado!" << endl;
			system("pause");
			system("cls");
			cout << "Al llegar, Kratos se ve a si mismo en el lugar en el que habia sido traicionado, Rodas, y a unos metros de el se encuentra Zeus atravezando con su espada al Kratos del pasado!" << endl;
			system("pause");
			cout << "Kratos corre y embiste a Zeus.\nZeus: *cae al suelo* Que? Como es posible? Las hermanas del destino te han ayudado, algo inesperado.\nKratos: Las hermanas estan muertas."
				"\nZeus: Te he subestimado... Un error que no pretendo repetir." << endl;
			system("pause");
			cout << "1-Recoger la Espada del Olimpo (espada de Zeus).\n2-Atacar a Zeus a mano limpia.\nQue vas a hacer?: ";
			cin >> opcion;

			if (opcion < 1 || opcion > 2)
			{
				cout << "Al llegar, Kratos se ve a si mismo en el lugar en el que habia sido traicionado y a unos metros de el se encuentra Zeus atravezando con su espada al Kratos del pasado!" << endl;
				cout << "Kratos corre y embiste a Zeus.\nZeus: *cae al suelo* Que? Como es posible? Las hermanas del destino te han ayudado, algo inesperado.\nKratos: Las hermanas estan muertas."
					"\nZeus: Te he subestimado... Un error que no pretendo repetir." << endl;
				cout << "1-Recoger la Espada del Olimpo (espada de Zeus).\n2-Atacar a Zeus.\nAccion invalida, intenta de nuevo: ";
				cin >> opcion;
			}

			switch (opcion)
			{
				case 1: //Recoger la Espada del Olimpo (espada de Zeus).
					system("cls");
					cout << "Zeus se lanza hacia Kratos para golpearlo pero este ultimo recoge justo a tiempo la Espada del Olimpo y se cubre.\nEl golpe lo envia lejos de Rodas al lugar que servira de arena para este combate." << endl;
					system("pause");
					cout << "Zeus: *se acerca volando al lugar* Ahora te mostrare el verdadero poder de un dios!" << endl;
					system("pause");
					cout << "Zeus se tira al vacio... Aparece a los pocos segundos siendo de un tamano colosal, solo se ve su torso, y ataca a Kratos invocando rayos!" << endl;
					system("pause");
					cout << "1-Concentrarse en esquivar los ataques de Zeus.\n2-Correr de frente e intentar apunalar en el estomago a Zeus.\nQue vas a hacer?: ";
					cin >> opcion;

					if (opcion < 1 || opcion > 2)
					{
						system("cls");
						cout << "Zeus se tira al vacio... Aparece a los pocos segundos siendo de un tamano colosal, solo se ve su torso, y ataca a Kratos invocando rayos!" << endl;
						cout << "1-Concentrarse en esquivar los ataques de Zeus.\n2-Correr de frente e intentar apunalar en el estomago a Zeus.\nAccion invalida, intenta de nuevo: ";
						cin >> opcion;
					}

					switch (opcion)
					{
						case 1: //Concentrarse en esquivar los ataques de Zeus.
							system("cls");
							cout << "Kratos esquiva con exito los rayos invocados por Zeus y contraataca!" << endl;
							system("pause");
							cout << "Luego de ser golpeado por Kratos, Zeus invoca a tres sirenas!" << endl;
							system("pause");
							cout << "1-Derrotar a las sirenas una a una teniendo cuidado con los ataques de Zeus.\n2-Ignorar a la sirenas y atacar a Zeus.\nQue vas a hacer?: ";
							cin >> opcion;

							if (opcion < 1 || opcion > 2)
							{
								system("cls");
								cout << "Luego de ser golpeado por Kratos, Zeus invoca a tres sirenas!" << endl;
								cout << "1-Derrotar a las sirenas una a una teniendo cuidado con los ataques de Zeus.\n2-Ignorar a la sirenas y atacar a Zeus.\nAccion invalida, intenta de nuevo: ";
								cin >> opcion;
							}

							switch (opcion)
							{
							case 1: //Derrotar a las sirenas una a una teniendo cuidado con los ataques de Zeus.
								system("cls");
								cout << "Mientras logra esquivar los ataques de Zeus, Kratos mata a las sirenas..." << endl;
								system("pause");
								cout << "Al ser derrotadas cada sirena produjo un sonido en direccion a Zeus aturdiendolo." << endl;
								system("pause");
								cout << "Kratos ataca a Zeus, este se debilita y vuelve a su tamaño normal, seguido de esto contraataca!" << endl;
								system("pause");
								cout << "1-Utilizar la Furia de Cronos.\n2-Atacar sin importar lo que haga Zeus.\nQue vas a hacer?: ";
								cin >> opcion;

								if (opcion < 1 || opcion > 2)
								{
									system("cls");
									cout << "Kratos ataca a Zeus, este se debilita y vuelve a su tamaño normal, seguido de esto contraataca!" << endl;
									cout << "1-Utilizar la Furia de Cronos.\n2-Atacar sin importar lo que haga Zeus.\nAccion invalida, intenta de nuevo: ";
									cin >> opcion;
								}
								else
								{
									switch (opcion)
									{
										case 1: //Utilizar la Furia de Cronos.
											system("cls");
											cout << "Al utilizar la Furia de Cronos, Zeus vuelve a ser aturdido! Kratos aprovecha esto y lo ataca!" << endl;
											system("pause");
											cout << "Al recuperarse Zeus embiste y recupera su espada con la cual comienza a lanzar rayos!" << endl;
											system("pause");
											cout << "1-Reflejar los ataque con el Vellocino de Oro.\n2-Concentrarse en esquivar los rayos.\nQue vas a hacer?: ";
											cin >> opcion;

											if (opcion < 1 || opcion > 2)
											{
												system("cls");
												cout << "Al utilizar la Furia de Cronos, Zeus vuelve a ser aturdido! Kratos aprovecha esto y lo ataca!" << endl;
												cout << "Al recuperarse Zeus embiste y recupera su espada con la cual comienza a lanzar rayos!" << endl;
												cout << "1-Reflejar los ataque con el Vellocino de Oro.\n2-Concentrarse en esquivar los rayos.\nAccion invalida, intenta de nuevo: ";
												cin >> opcion;
											}
											else
											{
												switch (opcion)
												{
													case 1: //Reflejar los ataque con el Vellocino de Oro.
														system("cls");
														cout << "Kratos refleja los ataques de Zeus con exito provandole mucho dano!" << endl;
														system("pause");
														cout << "Zeus se levante y retrocede, se vuelve a hacer gigante!" << endl;
														system("pause");
														cout << "1-Embaucar a Zeus.\n2-Seguir peleando.\nQue vas a hacer: ";
														cin >> opcion;

														if (opcion < 1 || opcion > 2)
														{
															system("cls");
															cout << "Kratos refleja los ataques de Zeus con exito provandole mucho dano!" << endl;
															cout << "Zeus se levante y retrocede, se vuelve a hacer gigante!" << endl;
															cout << "1-Embaucar a Zeus.\n2-Seguir peleando.\nAccion invalida, intenta de nuevo: ";
															cin >> opcion;
														}
														else
														{
															switch (opcion)
															{ 
																case 1: //Embaucar a Zeus.
																	system("cls");
																	cout << "Kratos: Me rindo, Zeus!" << endl;
																	system("pause");
																	cout << "Zeus vuelve a su tamano normal y se acerca a Kratos quien se arrodillo dandole la espalda para ser ejecutado.\nKratos: Liberame del tormento que es la vida."
																		"\nZeus: Hijo mio te liberare de la vida... Pero tu tormento acaba de comenzar." << endl;
																	system("pause");
																	cout << "Antes de ser abatido Kratos se levanta, esquiva el ataque y utilizando las Espada de Atenea clava cada brazo de Zeus a un pilar destruido que yacia a un costado de la arena en la que combatian!" << endl;
																	system("pause");
																	cout << "Luego toma la Espada del Olimpo e intenta rematarlo cuando aparece Atenea quien se interpone entre la espada y Zeus!\nLa gema que Kratos recogio antes de cruzar el portal comienza a brillar." << endl;
																	system("pause");
																	cout << "1.Usar la gema.\n2-Continuar con el ataque.\n3-Retroceder y no hacer nada.\nQue vas a hacer?: ";
																	cin >> opcion;

																	if (opcion < 1 || opcion > 3)
																	{
																		system("cls");
																		cout << "Luego toma la Espada del Olimpo e intenta rematarlo cuando aparece Atenea quien se interpone entre la espada y Zeus!\nAtenea: Kratos! No lo hagas!\nLa gema que Kratos recogio antes de cruzar el portal comienza a brillar." << endl;
																		cout << "1.Usar la gema.\n2-Continuar con el ataque.\n3-Retroceder y no hacer nada.\nAccion invalida, intenta de nuevo: ";
																		cin >> opcion;
																	}
																	else
																	{
																		if (opcion == 1) //Usar la gema.
																		{
																			system("cls");
																			cout << "Al usar la gema el tiempo se realentiza para todos menos para Kratos, detiene su ataque, empuja a un costado a Atenea y remata a Zeus!" << endl;
																			system("pause");
																			cout << "Zeus cae muerto en el suelo y con su muerte el Olimpo comienza a colapsar provocando un cataclismo en el que mueren millones y destruye una buena parte del mundo." << endl;
																			system("pause");
																			cout << "Kratos logro escapar y volver al presente el cual se ve afectado por lo causado al final de su pelea con Zeus" << endl;
																			system("pause");
																			cout << "Luego de ver el estado en el que quedo el mundo emprende un nuevo viaje esta vez sin un destino claro." << endl;
																			system("pause");
																			system("cls");
																			cout << "\t\t\t---FIN---" << endl;
																		}
																		else if (opcion == 2) //Continuar con el ataque.
																		{
																			system("cls");
																			cout << "Kratos no se detiene, Atenea queda entre la espada y Zeus siendo atravezada de lado a lado!" << endl;
																			system("pause");
																			cout << "Kratos: Atenea! No!\nAtenea: No pretendia pelear contigo, Kratos, pero si iba a defender el Olimpo...\nKratos: No buscaba destruir al Olimpo, solo a Zeus!\n"
																				"Atenea: Zeus es el Olimpo, si el muere todo llegara a su fin." << endl;
																			system("pause");
																			cout << "Al ver que Atenea fue abatida por Kratos, Zeus escapa mientras estos dos hablaban." << endl;
																			system("pause");
																			cout << "Luego de decir sus ultimas palabras, Atenea muere y, a los pocos segundos, su cuerpo desaparece." << endl;
																			system("pause");
																			cout << "Lo sucedido provoca que Kratos sienta odio hacia todo el Olimpo, toma a los titanes como aliados y prepara un futuro ataque..." << endl;
																			system("pause");
																			system("cls");
																			cout << "\t\t\t---FIN---" << endl;
																		}
																		else //Retroceder y no hacer nada.
																		{				
																			system("cls");
																			cout << "Al ver a Atenea, Kratos detiene su ataque y retrocede!" << endl;
																			system("pause");
																			cout << "Zeus vuelve en si, se libera y embiste hacia Kratos tirando a un lado a Atenea en el proceso." << endl;
																			system("pause");
																			cout << "Kratos recibe el golpe de Zeus y cae al suelo, seguido de esto es apunalado por Zeus quien luego lo ataca nuevamente y lo remata." << endl;
																			system("pause");
																			system("cls");
																			cout << "\t\t\t---FIN---" << endl;
																		}
																	}
																	break;
																case 2: //Seguir peleando.
																	system("cls");
																	cout << "Kratos no hace mas que seguir atacando pero, al haberse vuelto gigante nuevamente, Zeus mantiene la ventaja!" << endl;
																	system("pause");
																	cout << "Zeus golpea con ambas manos a Kratos, lo que deja a este ultimo estampado en el suelo y muerto!" << endl;
																	system("pause");
																	system("cls");
																	cout << "\t\t\t---FIN---" << endl;
																	break;
															}
														}
														break;
													case 2: //Concentrarse en esquivar los rayos.
														system("cls");
														cout << "Kratos esquiva tres de los cuatro rayos lanzados por Zeus! El cuarto lo golpea y le provoca dano pero puede seguir peleando." << endl;
														system("pause");
														cout << "Zeus se levante y retrocede, se vuelve a hacer gigante!" << endl;
														system("pause");
														cout << "1-Embaucar a Zeus.\n2-Seguir peleando.\nQue vas a hacer: ";
														cin >> opcion;

														if (opcion < 1 || opcion > 2)
														{
															system("cls");
															cout << "Kratos refleja los ataques de Zeus con exito provandole mucho dano!" << endl;
															cout << "Zeus se levante y retrocede, se vuelve a hacer gigante!" << endl;
															cout << "1-Embaucar a Zeus.\n2-Seguir peleando.\nAccion invalida, intenta de nuevo: ";
															cin >> opcion;
														}
														else
														{
															switch (opcion)
															{
															case 1: //Embaucar a Zeus.
																system("cls");
																cout << "Kratos: Me rindo, Zeus!" << endl;
																system("pause");
																cout << "Zeus vuelve a su tamano normal y se acerca a Kratos quien se arrodillo dandole la espalda para ser ejecutado.\nKratos: Liberame del tormento que es la vida."
																	"\nZeus: Hijo mio te liberare de la vida... Pero tu tormento acaba de comenzar." << endl;
																system("pause");
																cout << "Antes de ser abatido Kratos se levanta, esquiva el ataque y utilizando las Espada de Atenea clava cada brazo de Zeus a un pilar destruido que yacia a un costado de la arena en la que combatian!" << endl;
																system("pause");
																cout << "Luego toma la Espada del Olimpo e intenta rematarlo cuando aparece Atenea quien se interpone entre la espada y Zeus!\nLa gema que Kratos recogio antes de cruzar el portal comienza a brillar." << endl;
																system("pause");
																cout << "1.Usar la gema.\n2-Continuar con el ataque.\n3-Retroceder y no hacer nada.\nQue vas a hacer?: ";
																cin >> opcion;

																if (opcion < 1 || opcion > 3)
																{
																	system("cls");
																	cout << "Luego toma la Espada del Olimpo e intenta rematarlo cuando aparece Atenea quien se interpone entre la espada y Zeus!\nAtenea: Kratos! No lo hagas!\nLa gema que Kratos recogio antes de cruzar el portal comienza a brillar." << endl;
																	cout << "1.Usar la gema.\n2-Continuar con el ataque.\n3-Retroceder y no hacer nada.\nAccion invalida, intenta de nuevo: ";
																	cin >> opcion;
																}
																else
																{
																	if (opcion == 1) //Usar la gema.
																	{
																		system("cls");
																		cout << "Al usar la gema el tiempo se realentiza para todos menos para Kratos, detiene su ataque, empuja a un costado a Atenea y remata a Zeus!" << endl;
																		system("pause");
																		cout << "Zeus cae muerto en el suelo y con su muerte el Olimpo comienza a colapsar provocando un cataclismo en el que mueren millones y destruye una buena parte del mundo." << endl;
																		system("pause");
																		cout << "Kratos logro escapar y volver al presente el cual se ve afectado por lo causado al final de su pelea con Zeus" << endl;
																		system("pause");
																		cout << "Luego de ver el estado en el que quedo el mundo emprende un nuevo viaje esta vez sin un destino claro." << endl;
																		system("pause");
																		system("cls");
																		cout << "\t\t\t---FIN---" << endl;
																	}
																	else if (opcion == 2) //Continuar con el ataque.
																	{
																		system("cls");
																		cout << "Kratos no se detiene, Atenea queda entre la espada y Zeus siendo atravezada de lado a lado!" << endl;
																		system("pause");
																		cout << "Kratos: Atenea! No!\nAtenea: No pretendia pelear contigo, Kratos, pero si iba a defender el Olimpo...\nKratos: No buscaba destruir al Olimpo, solo a Zeus!\n"
																			"Atenea: Zeus es el Olimpo, si el muere todo llegara a su fin." << endl;
																		system("pause");
																		cout << "Al ver que Atenea fue abatida por Kratos, Zeus escapa mientras estos dos hablaban." << endl;
																		system("pause");
																		cout << "Luego de decir sus ultimas palabras, Atenea muere y, a los pocos segundos, su cuerpo desaparece." << endl;
																		system("pause");
																		cout << "Lo sucedido provoca que Kratos sienta odio hacia todo el Olimpo, toma a los titanes como aliados y prepara un futuro ataque..." << endl;
																		system("pause");
																		system("cls");
																		cout << "\t\t\t---FIN---" << endl;
																	}
																	else //Retroceder y no hacer nada.
																	{
																		system("cls");
																		cout << "Al ver a Atenea, Kratos detiene su ataque y retrocede!" << endl;
																		system("pause");
																		cout << "Zeus vuelve en si, se libera y embiste hacia Kratos tirando a un lado a Atenea en el proceso." << endl;
																		system("pause");
																		cout << "Kratos recibe el golpe de Zeus y cae al suelo, seguido de esto es apunalado por Zeus quien luego lo ataca nuevamente y lo remata." << endl;
																		system("pause");
																		system("cls");
																		cout << "\t\t\t---FIN---" << endl;
																	}
																}
																break;
															case 2: //Seguir peleando.
																system("cls");
																cout << "Kratos no hace mas que seguir atacando pero, al haberse vuelto gigante nuevamente, Zeus mantiene la ventaja!" << endl;
																system("pause");
																cout << "Zeus golpea con ambas manos a Kratos, lo que deja a este ultimo estampado en el suelo y muerto!" << endl;
																system("pause");
																system("cls");
																cout << "\t\t\t---FIN---" << endl;
																break;
															}
														}
														break;
												}
											}
											break;
										case 2: //Atacar sin importar lo que haga Zeus.
											system("cls");
											cout << "Kratos se deja cegar por su ira y ataca a Zeus pero este ultimo logra alcanzarlo con un potente rayo, fulminandolo en el acto!" << endl;
											system("pause");
											system("cls");
											cout << "\t\t\t---FIN---" << endl;
											break;
									}
								}								
								break;
							case 2: //Ignorar a la sirenas y atacar a Zeus.
								system("cls");
								cout << "Kratos intenta atacar a Zeus pero las sirenas no se lo permiten emitiendo un sonido muy potente." << endl;
								system("pause");
								cout << "Al ser aturdido por las sirenas, Kratos queda con la guardia baja y es devorado por ellas." << endl;
								system("pause");
								system("cls");
								cout << "\t\t\t---FIN---" << endl;
								break;
							}
							break;
						case 2: //Correr de frente e intentar apunalar en el estomago a Zeus.
							system("cls");
							cout << "Kratos corre de frente a Zeus lo que lo convierte en un blanco facil." << endl;
							system("pause");
							cout << "Zeus toma con sus manos a Kratos y lo aplasta contra el piso destrozando su cuerpo" << endl;
							system("pause");
							system("cls");
							cout << "\t\t\t---FIN---" << endl;
							break;
					}
					break;
				case 2: //Atacar a Zeus.
					system("cls");
					cout << "En su hambre de violencia Kratos no logra golpear a Zeus y este ultimo contraataca con la espada provandole a Kratos una herida mortal..." << endl;
					system("pause");
					system("cls");
					cout << "\t\t\t---FIN---" << endl;
					break;
			}

			break;
		case 2: //Atravesar el portal que se abrio al manipular los hilos del destino.
			system("cls");
			cout << "Kratos atraviesa el portal para viajar al pasado y enfrentarse a Zeus de una vez por todas." << endl;
			system("pause");
			cout << "Al llegar, Kratos se ve a si mismo en el lugar en el que habia sido traicionado y a unos metros de el se encuentra Zeus atravezando con su espada al Kratos del pasado!" << endl;
			cin >> opcion;

			if (opcion < 1 || opcion > 2)
			{
				cout << "Al llegar, Kratos se ve a si mismo en el lugar en el que habia sido traicionado y a unos metros de el se encuentra Zeus atravezando con su espada al Kratos del pasado!" << endl;
				cout << "Kratos corre y embiste a Zeus.\nZeus: *cae al suelo* Que? Como es posible? Las hermanas del destino te han ayudado, algo inesperado.\nKratos: Las hermanas estan muertas."
					"\nZeus: Te he subestimado... Un error que no pretendo repetir." << endl;
				cout << "1-Recoger la Espada del Olimpo (espada de Zeus).\n2-Atacar a Zeus.\nAccion invalida, intenta de nuevo: ";
				cin >> opcion;
			}

			switch (opcion)
			{
			case 1: //Recoger la Espada del Olimpo (espada de Zeus).
				system("cls");
				cout << "Zeus se lanza hacia Kratos para golpearlo pero este ultimo recoge justo a tiempo la Espada del Olimpo y se cubre.\nEl golpe lo envia lejos de Rodas al lugar que servira de arena para este combate." << endl;
				system("pause");
				cout << "Zeus: *se acerca volando al lugar* Ahora te mostrare el verdadero poder de un dios!" << endl;
				system("pause");
				cout << "Zeus se tira al vacio... Aparece a los pocos segundos siendo de un tamano colosal, solo se ve su torso, y ataca a Kratos invocando rayos!" << endl;
				system("pause");
				cout << "1-Concentrarse en esquivar los ataques de Zeus.\n2-Correr de frente e intentar apunalar en el estomago a Zeus.\nQue vas a hacer?: ";
				cin >> opcion;

				if (opcion < 1 || opcion > 2)
				{
					system("cls");
					cout << "Zeus se tira al vacio... Aparece a los pocos segundos siendo de un tamano colosal, solo se ve su torso, y ataca a Kratos invocando rayos!" << endl;
					cout << "1-Concentrarse en esquivar los ataques de Zeus.\n2-Correr de frente e intentar apunalar en el estomago a Zeus.\nAccion invalida, intenta de nuevo: ";
					cin >> opcion;
				}

				switch (opcion)
				{
				case 1: //Concentrarse en esquivar los ataques de Zeus.
					system("cls");
					cout << "Kratos esquiva con exito los rayos invocados por Zeus y contraataca!" << endl;
					system("pause");
					cout << "Luego de ser golpeado por Kratos, Zeus invoca a tres sirenas!" << endl;
					system("pause");
					cout << "1-Derrotar a las sirenas una a una teniendo cuidado con los ataques de Zeus.\n2-Ignorar a la sirenas y atacar a Zeus.\nQue vas a hacer?: ";
					cin >> opcion;

					if (opcion < 1 || opcion > 2)
					{
						system("cls");
						cout << "Luego de ser golpeado por Kratos, Zeus invoca a tres sirenas!" << endl;
						cout << "1-Derrotar a las sirenas una a una teniendo cuidado con los ataques de Zeus.\n2-Ignorar a la sirenas y atacar a Zeus.\nAccion invalida, intenta de nuevo: ";
						cin >> opcion;
					}

					switch (opcion)
					{
					case 1: //Derrotar a las sirenas una a una teniendo cuidado con los ataques de Zeus.
						system("cls");
						cout << "Mientras logra esquivar los ataques de Zeus, Kratos mata a las sirenas..." << endl;
						system("pause");
						cout << "Al ser derrotadas cada sirena produjo un sonido en direccion a Zeus aturdiendolo." << endl;
						system("pause");
						cout << "Kratos ataca a Zeus, este se debilita y vuelve a su tamaño normal, seguido de esto contraataca!" << endl;
						system("pause");
						cout << "1-Utilizar la Furia de Cronos.\n2-Atacar sin importar lo que haga Zeus.\nQue vas a hacer?: ";
						cin >> opcion;

						if (opcion < 1 || opcion > 2)
						{
							system("cls");
							cout << "Kratos ataca a Zeus, este se debilita y vuelve a su tamaño normal, seguido de esto contraataca!" << endl;
							cout << "1-Utilizar la Furia de Cronos.\n2-Atacar sin importar lo que haga Zeus.\nAccion invalida, intenta de nuevo: ";
							cin >> opcion;
						}
						else
						{
							switch (opcion)
							{
							case 1: //Utilizar la Furia de Cronos.
								system("cls");
								cout << "Al utilizar la Furia de Cronos, Zeus vuelve a ser aturdido! Kratos aprovecha esto y lo ataca!" << endl;
								system("pause");
								cout << "Al recuperarse Zeus embiste y recupera su espada con la cual comienza a lanzar rayos!" << endl;
								system("pause");
								cout << "1-Reflejar los ataque con el Vellocino de Oro.\n2-Concentrarse en esquivar los rayos.\nQue vas a hacer?: ";
								cin >> opcion;

								if (opcion < 1 || opcion > 2)
								{
									system("cls");
									cout << "Al utilizar la Furia de Cronos, Zeus vuelve a ser aturdido! Kratos aprovecha esto y lo ataca!" << endl;
									cout << "Al recuperarse Zeus embiste y recupera su espada con la cual comienza a lanzar rayos!" << endl;
									cout << "1-Reflejar los ataque con el Vellocino de Oro.\n2-Concentrarse en esquivar los rayos.\nAccion invalida, intenta de nuevo: ";
									cin >> opcion;
								}
								else
								{
									switch (opcion)
									{
									case 1: //Reflejar los ataque con el Vellocino de Oro.
										system("cls");
										cout << "Kratos refleja los ataques de Zeus con exito provandole mucho dano!" << endl;
										system("pause");
										cout << "Zeus se levante y retrocede, se vuelve a hacer gigante!" << endl;
										system("pause");
										cout << "1-Embaucar a Zeus.\n2-Seguir peleando.\nQue vas a hacer: ";
										cin >> opcion;

										if (opcion < 1 || opcion > 2)
										{
											system("cls");
											cout << "Kratos refleja los ataques de Zeus con exito provandole mucho dano!" << endl;
											cout << "Zeus se levante y retrocede, se vuelve a hacer gigante!" << endl;
											cout << "1-Embaucar a Zeus.\n2-Seguir peleando.\nAccion invalida, intenta de nuevo: ";
											cin >> opcion;
										}
										else
										{
											switch (opcion)
											{
											case 1: //Embaucar a Zeus.
												system("cls");
												cout << "Kratos: Me rindo, Zeus!" << endl;
												system("pause");
												cout << "Zeus vuelve a su tamano normal y se acerca a Kratos quien se arrodillo dandole la espalda para ser ejecutado.\nKratos: Liberame del tormento que es la vida."
													"\nZeus: Hijo mio te liberare de la vida... Pero tu tormento acaba de comenzar." << endl;
												system("pause");
												cout << "Antes de ser abatido Kratos se levanta, esquiva el ataque y utilizando las Espada de Atenea clava cada brazo de Zeus a un pilar destruido que yacia a un costado de la arena en la que combatian!" << endl;
												system("pause");
												cout << "Luego toma la Espada del Olimpo e intenta rematarlo cuando aparece Atenea quien se interpone entre la espada y Zeus!" << endl;
												system("pause");
												cout << "1-Continuar con el ataque.\n3-Retroceder y no hacer nada.\nQue vas a hacer?: ";
												cin >> opcion;

												if (opcion < 1 || opcion > 3)
												{
													system("cls");
													cout << "Luego toma la Espada del Olimpo e intenta rematarlo cuando aparece Atenea quien se interpone entre la espada y Zeus!\nAtenea: Kratos! No lo hagas!" << endl;
													cout << "1-Continuar con el ataque.\n3-Retroceder y no hacer nada.\nAccion invalida, intenta de nuevo: ";
													cin >> opcion;
												}
												else
												{
													if (opcion == 1) //Continuar con el ataque.
													{
														system("cls");
														cout << "Kratos no se detiene, Atenea queda entre la espada y Zeus siendo atravezada de lado a lado!" << endl;
														system("pause");
														cout << "Kratos: Atenea! No!\nAtenea: No pretendia pelear contigo, Kratos, pero si iba a defender el Olimpo...\nKratos: No buscaba destruir al Olimpo, solo a Zeus!\n"
															"Atenea: Zeus es el Olimpo, si el muere todo llegara a su fin." << endl;
														system("pause");
														cout << "Al ver que Atenea fue abatida por Kratos, Zeus escapa mientras estos dos hablaban." << endl;
														system("pause");
														cout << "Luego de decir sus ultimas palabras, Atenea muere y, a los pocos segundos, su cuerpo desaparece." << endl;
														system("pause");
														cout << "Lo sucedido provoca que Kratos sienta odio hacia todo el Olimpo, toma a los titanes como aliados y prepara un futuro ataque..." << endl;
														system("pause");
														system("cls");
														cout << "\t\t\t---FIN---" << endl;
													}
													else //Retroceder y no hacer nada.
													{
														system("cls");
														cout << "Al ver a Atenea, Kratos detiene su ataque y retrocede!" << endl;
														system("pause");
														cout << "Zeus vuelve en si, se libera y embiste hacia Kratos tirando a un lado a Atenea en el proceso." << endl;
														system("pause");
														cout << "Kratos recibe el golpe de Zeus y cae al suelo, seguido de esto es apunalado por Zeus quien luego lo ataca nuevamente y lo remata." << endl;
														system("pause");
														system("cls");
														cout << "\t\t\t---FIN---" << endl;
													}
												}
												break;
											case 2: //Seguir peleando.
												system("cls");
												cout << "Kratos no hace mas que seguir atacando pero, al haberse vuelto gigante nuevamente, Zeus mantiene la ventaja!" << endl;
												system("pause");
												cout << "Zeus golpea con ambas manos a Kratos, lo que deja a este ultimo estampado en el suelo y muerto!" << endl;
												system("pause");
												system("cls");
												cout << "\t\t\t---FIN---" << endl;
												break;
											}
										}
										break;
									case 2: //Concentrarse en esquivar los rayos.
										break;
									}
								}
								break;
							case 2: //Atacar sin importar lo que haga Zeus
								system("cls");
								cout << "Kratos se deja cegar por su ira y ataca a Zeus pero este ultimo logra alcanzarlo con un potente rayo, fulminandolo en el acto!" << endl;
								system("pause");
								system("cls");
								cout << "\t\t\t---FIN---" << endl;
								break;
							}
						}
						break;
					case 2: //Ignorar a la sirenas y atacar a Zeus.
						system("cls");
						cout << "Kratos intenta atacar a Zeus pero las sirenas no se lo permiten emitiendo un sonido muy potente." << endl;
						system("pause");
						cout << "Al ser aturdido por las sirenas, Kratos queda con la guardia baja y es devorado por ellas." << endl;
						system("pause");
						system("cls");
						cout << "\t\t\t---FIN---" << endl;
						break;
					}
					break;
				case 2: //Correr de frente e intentar apunalar en el estomago a Zeus.
					system("cls");
					cout << "Kratos corre de frente a Zeus lo que lo convierte en un blanco facil." << endl;
					system("pause");
					cout << "Zeus toma con sus manos a Kratos y lo aplasta contra el piso destrozando su cuerpo, este ultimo muere instantaneamente!" << endl;
					system("pause");
					system("cls");
					cout << "\t\t\t---FIN---" << endl;
					break;
				}
				break;
			case 2: //Atacar a Zeus.
				system("cls");
				cout << "En su hambre de violencia Kratos no logra golpear a Zeus y este ultimo contraataca con la espada provandole a Kratos una herida mortal..." << endl;
				system("pause");
				system("cls");
				cout << "\t\t\t---FIN---" << endl;
				break;
			}
			break;
		case 3: //La venganza nunca es buena mata el alma y la envenena.
			system("cls");
			cout << "Frente al portal Kratos se replantea muchas cosas... Decide no atravesarlo." << endl;
			system("pause");
			system("cls");
			cout << "Una vez fuera de la guarida de Cloto, Kratos emprende un nuevo viaje." << endl;
			system("pause");
			system("cls");
			cout << "Meses mas tarde, finaliza su viaje con exito y se establece una cabana en medio del campo... \nTal ves pueda vivir en paz y dejar atras su violento pasado." << endl;
			system("pause");
			cout << "\t\t\t---FIN---" << endl;
			break;
	}

	return 0;
}