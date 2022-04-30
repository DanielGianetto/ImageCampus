/*			-- 08/04/2022 -- ANALISIS_TP2_TM_GianettoDaniel --

	Condiciones mínimas:
		1. Realizar el juego para que funcione con 1 solo jugador.
		2. Incluir dentro del código fuente un Enum.
		3. Utilizar un switch para alternar entre los elementos del Enum.
		4. Debe existir un bucle de juego (utilizando, por ej, "do while").
		5. El juego debe hacer uso de un random.
*/
#include <iostream>
#include <time.h>
#include <cstdlib> //Libreria agregada por error al usar system("pause") y system("cls"). Error "system" is ambiguous y Error "pause" is ambiguous.

using namespace std;

int main()
{
	srand(time(NULL));

	//Enumeradores.
	enum Pokemon { Charmander = 1, Bulbasaur, Squirtle };
	enum Menu { Play = 1, Credits, QuitGame };
	enum CombatActions { Attack = 1, UsePotion };

	//Variables del Jugador.
	int playersChoice = 0;
	Pokemon pokemonSelected;
	Menu optionSelected;
	CombatActions playersAction;
	string playersName;
	string playersPokemon;
	float playersDamageModifier;
	float playersPokemonHP = 100.0f;

	int randomPokemonAttackSkill;
	int playersEvasion;

	int playerPotions = 3;

	//Variables CPU.
	int cpusRandomChoice = 0;
	Pokemon cpusPokemon;
	CombatActions cpusAction;
	string cpusPokemonName;
	float cpusDamageModifier;
	float cpusPokemonHP = 100.0f;

	int randomCpuPokemonAttackSkill;
	int cpusEvasion;

	int cpuPotions = 3;
	int cpuUsePotion;

	//Variable para definir los turnos.
	bool playersTurn = true;

	//Variable compartida.
	float baseDamage = 10.0f;
	float damageDone;

	//Loop Menu Principal.
	do
	{
		do
		{
			system("cls");
			cout << "\t\t\t\t--POKEMON--\n\t\t\t\t  1.PLAY\n\t\t\t\t 2.CREDITS\n\t\t\t\t  3.QUIT\n\t\t\t     Choose an option: ";
			cin >> playersChoice;

		}while (playersChoice < 1 || playersChoice > 3); //Validacion de seleccion en el menu principal.

		//optionSelected = (Menu)playersChoice;
		optionSelected = static_cast<Menu>(playersChoice);

		//Menu principal.
		switch (optionSelected)
		{
		case Play:
			system("cls");
			cout << "PROFESSOR OAK: Good morning! You must be the new kid in town, what's your name?" << endl << "\n\t\t\t\tMy name is: ";
			cin >> playersName;
			system("cls");
			cout << "PROFESSOR OAK: That's a cool name! Nice to meet you, " << playersName << "!" << endl;
			system("pause");
			

			//Validacion.
			do
			{
				system("cls");
				cout << "PROFESSOR OAK: I'm sure that you are here because you want to become a Pokemon Trainer, right?\n\t\t\t\t1.YES\n\t\t\t\t2.NO\n\t\t\t   Choose an option: ";
				cin >> playersChoice;

			}while (playersChoice < 1 || playersChoice > 2);

			//Bucle que ante una respuesta negativa hace que PROFESSOR OAK te vuelva a preguntar como pasa en algunos juegos que al poner NO te vuelven a preguntar una y otra vez.
			while (playersChoice == 2)
			{
				system("cls");
				cout << "PROFESSOR OAK: What? Let me ask you again. You are here because you want to become a Pokemon Trainer, right?\n\t\t\t\t1.YES\n\t\t\t\t2.NO\n\t\t\t   Choose an option: ";
				cin >> playersChoice;
			}

			if (playersChoice == 1)
			{
				system("cls");
				cout << "PROFESSOR OAK: I knew it! I have three pokemons with me right now!." << endl;
				system("pause");
				system("cls");
				cout << "PROFESSOR OAK: Charmander a Fire type pokemon, Bulbasaur a Grass type pokemon and Squirtle a Water type pokemon. Before choosing one let me explain how types work!" << endl;
				system("pause");

				do
				{					
					system("cls");
					cout << "PROFESSOR OAK: Fire is effective against Grass but weak against Water, Grass is effective against Water but weak against Fire, and finally, Water is effective against Fire but weak against Grass. You may choose one pokemon!" << endl;
					system("pause");
					cout << "\n\t\t\t     1.CHARMANDER\n\t\t\t     2.BULBASAUR\n\t\t\t     3.SQUIRTLE\n\t\t\t Choose your pokemon: ";
					cin >> playersChoice;

				}while (playersChoice < 1 || playersChoice > 3);

				pokemonSelected = static_cast<Pokemon>(playersChoice);

				switch (pokemonSelected)
				{
					case Charmander:
						system("cls");
						cout << "\n\t\t\tYou chose CHARMANDER!" << endl;
						system("pause");

						//Al seleccionar a Charmander se guarda el nombre del pokemon para ser mostrado durante el combate.
						playersPokemon = "CHARMANDER";

						system("cls");
						cout << "PROFESSOR OAK: One more thing about type effectiveness, " << playersName << "!\nIf your pokemon type is effective against your rival it deals x2.0 damage, if they are the same type both deal x1.0 damage and if yours is weak against your rival's pokemon type yours deals x0.5 damage! Keep that in mind!" << endl;
						system("pause");
						system("cls");
						cout << "PROFESSOR OAK: Oh, almost forgot to introduce my grandson GARY." << endl;
						system("pause");
						system("cls");
						cout << "GARY: Grandpa, I want a pokemon too!" << endl;
						system("pause");
						system("cls");
						cout << "PROFESSOR OAK: Sure, GARY. Pick one of these!" << endl;
						system("pause");

						//Seleccion random del pokemon de la cpu.						
						cpusRandomChoice = rand() % 3 + 1;
						cpusPokemon = static_cast<Pokemon>(cpusRandomChoice);

						switch (cpusPokemon)
						{
							case Charmander:
								system("cls");
								cout << "\n\t\t\tGARY chose CHARMANDER!" << endl;
								system("pause");

								cpusPokemonName = "CHARMANDER";

								system("cls");
								cout << "You have the same pokemon! Damage modifier set to x1.0!";
								system("pause");

								playersDamageModifier = 1.0f;
								cpusDamageModifier = 1.0f;
								break;

							case Bulbasaur:
								system("cls");
								cout << "\n\t\t\tGARY chose BULBASAUR!" << endl;
								system("pause");

								cpusPokemonName = "BULBASAUR";

								system("cls");
								cout << "Your pokemon is effective against BULBASAUR! Damage modifier set to x2.0!" << endl;
								system("pause");

								playersDamageModifier = 2.0f;
								cpusDamageModifier = 0.5f;
								break;

							case Squirtle:
								system("cls");
								cout << "\n\t\t\tGARY chose SQUIRTLE!" << endl;
								system("pause");

								cpusPokemonName = "SQUIRTLE";

								system("cls");
								cout << "Your pokemon is weak against SQUIRTLE! Damage modifier set to x0.5!" << endl;
								system("pause");

								playersDamageModifier = 0.5f;
								cpusDamageModifier = 2.0f;
								break;

							default:
								system("cls");
								cout << "Error setting CPU's pokemon and damage modifier." << endl;
								system("pause");
								break;
						}
						break;

					case Bulbasaur:
						system("cls");
						cout << "\n\t\t\tYou chose BULBASAUR!" << endl;
						system("pause");

						//Al seleccionar a Bulbasaur se guarda el nombre del pokemon para ser mostrado durante el combate.
						playersPokemon = "BULBASAUR";

						system("cls");
						cout << "PROFESSOR OAK: One more thing about type effectiveness, " << playersName << "!\nIf your pokemon type is effective against your rival it deals x2.0 damage, if they are the same type both deal x1.0 damage and if yours is weak against your rival's pokemon type yours deals x0.5 damage! Keep that in mind!" << endl;
						system("pause");
						system("cls");
						cout << "PROFESSOR OAK: Oh, almost forgot to introduce my grandson GARY." << endl;
						system("pause");
						system("cls");
						cout << "GARY: Grandpa, I want a pokemon too!" << endl;
						system("pause");
						system("cls");
						cout << "PROFESSOR OAK: Sure, GARY. Pick one of these!" << endl;
						system("pause");

						//Seleccion random del pokemon de la cpu.
						cpusRandomChoice = rand() % 3 + 1;
						cpusPokemon = static_cast<Pokemon>(cpusRandomChoice);

						switch (cpusPokemon)
						{
							case Charmander:
								system("cls");
								cout << "\n\t\t\tGARY chose CHARMANDER!" << endl;
								system("pause");

								cpusPokemonName = "CHARMANDER";

								system("cls");
								cout << "Your pokemon is weak against CHARIZARD! Damage modifier set to x0.5!" << endl;
								system("pause");

								playersDamageModifier = 0.5f;
								cpusDamageModifier = 2.0f;
								break;

							case Bulbasaur:
								system("cls");
								cout << "\n\t\t\tGARY chose BULBASAUR!" << endl;
								system("pause");

								cpusPokemonName = "BULBASAUR";

								system("cls");
								cout << "You have the same pokemon! Damage modifier set to x1.0!" << endl;
								system("pause");

								playersDamageModifier = 1.0f;
								cpusDamageModifier = 1.0f;
								break;

							case Squirtle:
								system("cls");
								cout << "\n\t\t\tGARY chose SQUIRTLE!" << endl;
								system("pause");

								cpusPokemonName = "SQUIRTLE";

								system("cls");
								cout << "Your pokemon is strong against SQUIRTLE! Damage modifier set to x2.0!" << endl;
								system("pause");

								playersDamageModifier = 2.0f;
								cpusDamageModifier = 0.5f;
								break;

							default:
								system("cls");
								cout << "Error setting CPU's pokemon and damage modifier." << endl;
								system("pause");
								break;
						}
						break;

					case Squirtle:
						system("cls");
						cout << "\n\t\t\tYou chose SQUIRTLE!" << endl;
						system("pause");

						//Al seleccionar a Bulbasaur se guarda el nombre del pokemon para ser mostrado durante el combate.
						playersPokemon = "SQUIRTLE";

						system("cls");
						cout << "PROFESSOR OAK: One more thing about type effectiveness, " << playersName << "!\nIf your pokemon type is effective against your rival it deals x2.0 damage, if they are the same type both deal x1.0 damage and if yours is weak against your rival's pokemon type yours deals x0.5 damage! Keep that in mind!" << endl;
						system("pause");
						system("cls");
						cout << "PROFESSOR OAK: Oh, almost forgot to introduce my grandson GARY." << endl;
						system("pause");
						system("cls");
						cout << "GARY: Grandpa, I want a pokemon too!" << endl;
						system("pause");
						system("cls");
						cout << "PROFESSOR OAK: Sure, GARY. Pick one of these!" << endl;
						system("pause");

						//Seleccion random del pokemon de la cpu.
						cpusRandomChoice = rand() % 3 + 1;
						cpusPokemon = static_cast<Pokemon>(cpusRandomChoice);

						switch (cpusPokemon)
						{
							case Charmander:
								system("cls");
								cout << "\n\t\t\tGARY chose CHARMANDER!" << endl;
								system("pause");

								cpusPokemonName = "CHARMANDER";

								system("cls");
								cout << "Your pokemon is effective against CHARIZARD! Damage modifier set to x2.0!" << endl;
								system("pause");

								playersDamageModifier = 2.0f;
								cpusDamageModifier = 0.5f;
								break;

							case Bulbasaur:
								system("cls");
								cout << "\n\t\t\tGARY chose BULBASAUR!" << endl;
								system("pause");

								cpusPokemonName = "BULBASAUR";

								system("cls");
								cout << "Your pokemon is weak against BULBASAUR! Damage modifier set to x0.5!" << endl;
								system("pause");

								playersDamageModifier = 0.5f;
								cpusDamageModifier = 2.0f;
								break;

							case Squirtle:
								system("cls");
								cout << "\n\t\t\tGARY chose SQUIRTLE!" << endl;
								system("pause");

								cpusPokemonName = "SQUIRTLE";

								system("cls");
								cout << "You have the same pokemon! Damage modifier set to x1.0!" << endl;
								system("pause");

								playersDamageModifier = 1.0f;
								cpusDamageModifier = 1.0f;
								break;

							default:
								system("cls");
								cout << "Error setting CPU's pokemon and damage modifier." << endl;
								system("pause");
								break;
							}
							break;

					default:
						system("cls");
						cout << "Error choosing pokemon." << endl;
						system("pause");
						break;

				}//Final switch(pokemonSelected).

			}//Final if(playersChoice == 1).

			system("cls");
			cout << "GARY: Nice! I have a " << cpusPokemonName << "!" << endl;
			system("pause");
			system("cls");
			cout << "GARY: Let's fight, " << playersName << "! I'll show you what I got!" << endl;
			system("pause");

			//Main game loop.
			do
			{
				if (playersTurn == true)
				{
					do
					{
						system("cls");
						cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
						cout << "\n\t\t\t     1.ATTACK\n\t\t\t   2.USE POTION\n\t\t         CHOOSE AN ACTION: ";
						cin >> playersChoice;

					}while (playersChoice < 1 || playersChoice > 2);

					playersAction = static_cast<CombatActions>(playersChoice);

					switch (playersAction)
					{
					case Attack:
						randomPokemonAttackSkill = rand() % 3 + 1;

						system("cls");
						cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;

						if (pokemonSelected == Charmander)
						{
							if (randomPokemonAttackSkill == 1)
							{
								system("cls");
								cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
								cout << "\n\t\t" << playersName << ": " << playersPokemon << " use Ember!" << endl;
								system("pause");
							}
							else if (randomPokemonAttackSkill == 2)
							{
								system("cls");
								cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
								cout << "\n\t\t" << playersName << ": " << playersPokemon << " use Flamethrower!" << endl;
								system("pause");
							}
							else
							{
								system("cls");
								cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
								cout << "\n\t\t" << playersName << ": " << playersPokemon << " use Inferno!" << endl;
								system("pause");
							}
						}

						if (pokemonSelected == Bulbasaur)
						{
							if (randomPokemonAttackSkill == 1)
							{
								system("cls");
								cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
								cout << "\n\t\t" << playersName << ": " << playersPokemon << " use Vine Whip!" << endl;
								system("pause");
							}
							else if (randomPokemonAttackSkill == 2)
							{
								system("cls");
								cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
								cout << "\n\t\t" << playersName << ": " << playersPokemon << " use Razor Leaf!" << endl;
								system("pause");
							}
							else
							{
								system("cls");
								cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
								cout << "\n\t\t\t" << playersName << ": " << playersPokemon << " use Solar Beam!" << endl;
								system("pause");
							}
						}

						if (pokemonSelected == Squirtle)
						{
							if (randomPokemonAttackSkill == 1)
							{
								system("cls");
								cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
								cout << "\n\t\t" << playersName << ": " << playersPokemon << " use Water Gun!" << endl;
								system("pause");
							}
							else if (randomPokemonAttackSkill == 2)
							{
								system("cls");
								cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
								cout << "\n\t\t" << playersName << ": " << playersPokemon << " use Aqua Tail!" << endl;
								system("pause");
							}
							else
							{
								system("cls");
								cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
								cout << "\n\t\t" << playersName << ": " << playersPokemon << " use Hidro Pump!" << endl;
								system("pause");
							}
						}

						cpusEvasion = rand() % 100 + 1;

						if (cpusEvasion <= 60)
						{
							damageDone = 10 + (baseDamage * playersDamageModifier);

							system("cls");
							cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
							cout << "\n\t\t" << playersPokemon << " deals " << damageDone << " to GARY's " << cpusPokemonName << "!" << endl;

							cpusPokemonHP -= damageDone;
							system("pause");

							if (cpusPokemonHP < 0)
							{
								cpusPokemonHP == 0;
							}
						}
						else
						{
							system("cls");
							cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
							cout << "\n\t\tGARY's " << cpusPokemonName << " evades " << playersPokemon << " attack!" << endl;
							system("pause");
						}

						playersTurn = false;

						break;

					case UsePotion:
						system("cls");
						cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;

						if (playerPotions > 0 && playersPokemonHP < 100)
						{
							system("cls");
							cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
							cout << "\n\t\t" << playersName << " uses a Potion! " << playersPokemon << " recovers 20 HP!" << endl;
							playersPokemonHP += 20;
							system("pause");

							if (playersPokemonHP > 100)
							{
								playersPokemonHP = 100;
							}

							playerPotions--;

							playersTurn = false;
						}
						else
						{
							if (playersPokemonHP == 100)
							{
								cout << "\n\t\tYour pokemon's health if full!" << endl;
								system("pause");
							}
							else
							{
								cout << "\n\t\tYou don't have any Potions left!" << endl;
								system("pause");
							}
						}
						break;

					default:
						cout << "Error executing Combat Action." << endl;
						system("pause");
						break;
					}//Final del turno del Jugador.
				}
				else
				{

					randomCpuPokemonAttackSkill = rand() % 3 + 1;

					if (cpusPokemon == Charmander)
					{
						if (randomCpuPokemonAttackSkill == 1)
						{
							system("cls");
							cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
							cout << "\n\t\tGARY: " << cpusPokemonName << " use Ember!" << endl;
							system("pause");
						}
						else if (randomCpuPokemonAttackSkill == 2)
						{
							system("cls");
							cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
							cout << "\n\t\tGARY: " << cpusPokemonName << " use Flamethrower!" << endl;
							system("pause");
						}
						else
						{
							system("cls");
							cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
							cout << "\n\t\tGARY: " << cpusPokemonName << " use Inferno!" << endl;
							system("pause");
						}
					}

					if (cpusPokemon == Bulbasaur)
					{
						if (randomCpuPokemonAttackSkill == 1)
						{
							system("cls");
							cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
							cout << "\n\t\tGARY: " << cpusPokemonName << " use Vine Whip!" << endl;
							system("pause");
						}
						else if (randomCpuPokemonAttackSkill == 2)
						{
							system("cls");
							cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
							cout << "\n\t\tGARY: " << cpusPokemonName << " use Razor Leaf!" << endl;
							system("pause");
						}
						else
						{
							system("cls");
							cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
							cout << "\n\t\tGARY: " << cpusPokemonName << " use Solar Beam!" << endl;
							system("pause");
						}
					}

					if (cpusPokemon == Squirtle)
					{
						if (randomCpuPokemonAttackSkill == 1)
						{
							system("cls");
							cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
							cout << "\n\t\tGARY: " << cpusPokemonName << " use Water Gun!" << endl;
							system("pause");
						}
						else if (randomCpuPokemonAttackSkill == 2)
						{
							system("cls");
							cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
							cout << "\n\t\tGARY: " << cpusPokemonName << " use Aqua Tail!" << endl;
							system("pause");
						}
						else
						{
							system("cls");
							cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
							cout << "\n\t\tGARY: " << cpusPokemonName << " use Hidro Pump!" << endl;
							system("pause");
						}
					}

					playersEvasion = rand() % 100 + 1;

					if (playersEvasion <= 60)
					{
						damageDone = 10 + (baseDamage * cpusDamageModifier);

						system("cls");
						cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
						cout << "\n\t\t" << cpusPokemonName << " deals " << damageDone << " to " << playersName << "'s " << playersPokemon << "!" << endl;

						playersPokemonHP -= damageDone;
						system("pause");
						system("cls");

						if (playersPokemonHP < 0)
						{
							playersPokemonHP == 0;
						}

						playersTurn = true;
					}
					else
					{
						system("cls");
						cout << playersName << "'s " << playersPokemon << " HP: " << playersPokemonHP << "\t\tGARY's " << cpusPokemonName << " HP: " << cpusPokemonHP << endl;
						cout << "\n\t\t" << playersName << "'s " << playersPokemon << " evades " << cpusPokemonName << " attack!" << endl;
						system("pause");
						system("cls");
						playersTurn = true;
					}

				}//Final turno de la CPU.
	
			} while (playersPokemonHP > 0 && cpusPokemonHP > 0);

			if (playersPokemonHP == 0)
			{
				system("cls");
				cout << "GARY: Ha ha, I knew I was a better Pokemon Trainer than you, " << playersName << "!" << endl;
				system("pause");
				system("cls");
				cout << "\n\t\t\t\t-=GAME OVER=-" << endl;
				system("pause");
			}
			else
			{
				system("cls");
				cout << "GARY: Oh man! I'll beat you next time, " << playersName << "!" << endl;
				system("pause");
				system("cls");
				cout << "\n\t\t\t\t-=CONGRATULATIONS!=-\n\t\t\t\t -=YOU BEAT GARY=-" << endl;
				system("pause");
			}

			//Seteo de la vida de ambos, Jugador y CPU, a HP = 100.
			playersPokemonHP = 100.0f;
			cpusPokemonHP = 100.0f;

			//Seteo de la cantidad de pociones del Jugador a su valor inicial.
			playerPotions = 3;

			break;//Final case Menu::Play.

		case Credits:
			system("cls");
			cout << "\t\t\t\t-=POKEMON by Daniel Gianetto=-" << endl;
			system("pause");
			break;

		case QuitGame:
			system("cls");
			cout << "\t\t\t\t-=Thanks for playing=-" << endl;
			system("pause");
			break;
		}

	} while (optionSelected != QuitGame);


	return 0;
}