/*                      ANALISIS_TM_TP3_GianettoDaniel

        Desarrollo del TP3 "101".

        Condiciones mínimas:

            1. Realizar el juego para que funcione con 1 solo jugador.
            2. Hacer que cada vez que el jugador lance el dado el juego se pause y
               espere input por teclado para volver a lanzar (Esto antes de superar 25 y
               plantarse por primera vez).
            3. Una vez superado los 25, el juego se detiene a preguntar si el jugador desea
               lanzar nuevamente o anotarse los puntos.
            4. Cuando el jugador decide plantarse, se limpia el historial de lanzamientos
               de la pantalla y vuelve a comenzar "un turno nuevo" (Cuando el juego sea de
               a dos en realidad es el turno del siguiente jugador).
            5. Desarrollar el juego con las reglas explicadas en "Reglamento del Juego".

        Condiciones avanzadas:

            1. Una vez que el juego está completo y funciona correctamente para 1
               jugador hacer que funcione para 2 jugadores.
            2. Cuando el turno de un jugador termine (por el motivo que sea), debe ser el
               turno del siguiente jugador para lanzar el dado.
            3. Recordar que con cada nuevo turno la pantalla debe limpiarse.
            4. Hacer que el límite de 25 puntos para anotarse pueda ser modificado por
               el usuario.
*/
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));

    enum Menu { PLAY = 1, RULES, CREDITS, QUIT, CONTINUE = 1, STOP , ONEPLAYER = 1, TWOPLAYERS, YES = 1, NO};

    Menu playersChoice;
    int option;

    int dice;
    int rolledDice = 1;
    int tempScoreAccumulator = 0; //Acumulador de puntos del turno actual.
    int totalScore = 0; //Total de puntos en la partida.
    int playerTwoTotalScore = 0; //Total de puntos del jugador 2.

    int minCumulativeScore = 25; //Valor minimo acumulable.
    const int maxCumulativeScore = 99; //Valor maximo acumulable.
    const int winScore = 101; //Valor necesario para ganar.
    const int loseCumulativeScore = 1; //Valor que indica la perdida de los puntos acumulados.
    const int loseTotalScore = 100; //Valor que indica la perdida de los puntos totales.

    bool playerOneMinScore;
    bool playerTwoMinScore;
    bool playerTurn = true;

    do //Menu principal.
    {
        system("color 07");
        do //Validacion.
        {
            system("cls");
            cout << "\t\t------------------------------" << endl;
            cout << "\t\t\t     101" << endl;
            cout << "\t\t------------------------------" << endl;
            cout << "\t\t\t    JUGAR\n\t\t     REGLAMENTO DEL JUEGO\n\t\t\t   CREDITOS\n\t\t\t    SALIR" << endl;
            cout << "\t\t------------------------------" << endl;
            cout << "\t\tSeleccione una opcion (1 a 4): ";
            cin >> option;

        } while (option < PLAY || option > QUIT);

        playersChoice = static_cast<Menu>(option); //Casteo de int a Menu.

        switch (playersChoice)
        {
            case PLAY:
                system("cls");              
                cout << "\t\t------------------------------" << endl;
                cout << "\t\t\t     101" << endl;
                cout << "\t\t------------------------------" << endl;
                cout << "\t\t   LIMITE INICIAL ACTUAL: " << minCumulativeScore << endl;
                cout << "\t\t------------------------------" << endl;
                cout << "\t\t  DESEA MODIFICARLO? (1 o 2)" << endl;
                cout << "\t\t              SI " << endl;
                cout << "\t\t              NO " << endl;
                cout << "\t\t------------------------------" << endl;                               
                cin >> option;

                playersChoice = static_cast<Menu>(option);

                if (playersChoice == YES)
                {
                    do
                    {
                        system("cls");
                        cout << "\t\t------------------------------" << endl;
                        cout << "\t\t\t     101" << endl;
                        cout << "\t\t------------------------------" << endl;
                        cout << "\t\tLIMITE INICIAL ACTUAL: " << minCumulativeScore << endl;
                        cout << "\t\t------------------------------" << endl;
                        cout << "\t\tINGRESE EL NUEVO LIMITE INICIAL: " << endl;
                        cin >> option;
                    } while (option < 1 || option == 100 || option > 101);

                    minCumulativeScore = option;

                    system("cls");
                    cout << "\t\t------------------------------" << endl;
                    cout << "\t\t\t     101" << endl;
                    cout << "\t\t------------------------------" << endl;
                    cout << "\t\tLIMITE INICIAL MODIFICADO: " << minCumulativeScore << endl;
                    cout << "\t\t------------------------------" << endl;
                }

                do
                {
                    system("cls");
                    cout << "\t\t------------------------------" << endl;
                    cout << "\t\t\t     101" << endl;
                    cout << "\t\t------------------------------" << endl;
                    cout << "\t\tCUANTAS PERSONAS JUGARAN?(1 o 2)" << endl;
                    cout << "\t\t------------------------------" << endl;
                    cin >> option;
                } while (option < 1 || option > 2);

                playersChoice = static_cast<Menu>(option);

                switch (playersChoice) //Seleccion de cantidad de jugadores.
                {
                    case ONEPLAYER:
                        totalScore = 0;
                        system("color 0A");
                        do
                        {
                            if (totalScore >= minCumulativeScore)
                            {
                                playerOneMinScore = true;
                            }
                            else
                            {
                                playerOneMinScore = false;
                            }

                            while (tempScoreAccumulator < minCumulativeScore && playerOneMinScore != true)
                            {
                                dice = rand() % 6 + 1;

                                if (dice == loseCumulativeScore)
                                {
                                    tempScoreAccumulator = 0;
                                    rolledDice = 1;
                                }
                                else
                                {
                                    tempScoreAccumulator += dice;
                                }

                                ++rolledDice;

                                system("cls");                               
                                cout << "\t\t------------------------------" << endl;
                                cout << "\t\t   JUGADOR 1 - TIRADA NRO. " << rolledDice << endl;
                                cout << "\t\t------------------------------" << endl;
                                cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << totalScore << endl;
                                system("pause");
                            }

                            do
                            {
                                system("cls");
                                cout << "\t\t------------------------------" << endl;
                                cout << "\t\t   JUGADOR 1 - TIRADA NRO. " << rolledDice << endl;
                                cout << "\t\t------------------------------" << endl;
                                cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << totalScore << endl;
                                cout << "\n\t\t1-SEGUIR TIRANDO.\n\t\t2-ANOTAR PUNTOS." << endl;
                                cin >> option;
                            } while (option < CONTINUE || option > STOP);

                            playersChoice = static_cast<Menu>(option);

                            switch (playersChoice)
                            {
                                case CONTINUE:
                                    dice = rand() % 6 + 1;

                                    if (dice == loseCumulativeScore)
                                    {
                                        if (tempScoreAccumulator == 0)
                                        {
                                            rolledDice = 1;

                                            system("cls");
                                            cout << "\t\t------------------------------" << endl;
                                            cout << "\t\t   JUGADOR 1 - TIRADA NRO. " << rolledDice << endl;
                                            cout << "\t\t------------------------------" << endl;
                                            cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                            cout << "\n\t\t      Perdiste el turno!" << endl;
                                            cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << totalScore << endl;
                                            system("pause");
                                        }
                                        else
                                        {
                                            tempScoreAccumulator = 0;
                                            rolledDice = 1;

                                            system("cls");
                                            cout << "\t\t------------------------------" << endl;
                                            cout << "\t\t   JUGADOR 1 - TIRADA NRO. " << rolledDice << endl;
                                            cout << "\t\t------------------------------" << endl;
                                            cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                            cout << "\n\t\tPerdiste los puntos acumulados!" << endl;
                                            cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << totalScore << endl;
                                            system("pause");
                                        }                                   
                                    }
                                    else
                                    {
                                        tempScoreAccumulator += dice;
                                        ++rolledDice;
                                    }

                                    break;
                                case STOP:
                                    if (totalScore >= maxCumulativeScore && totalScore + tempScoreAccumulator != winScore)
                                    {
                                        tempScoreAccumulator = 0;
                                        rolledDice = 1;

                                        system("cls");
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t   JUGADOR 1 - TIRADA NRO. " << rolledDice << endl;
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                        cout << "\n\t\tNo se puede anotar mas de 99 puntos!" << endl;
                                        cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << totalScore << endl;
                                        system("pause");
                                    }
                                    else if (totalScore + tempScoreAccumulator == winScore)
                                    {
                                        totalScore += tempScoreAccumulator;
                                        tempScoreAccumulator = 0;
                                        rolledDice = 1;

                                        system("cls");
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t   JUGADOR 1 - TIRADA NRO. " << rolledDice << endl;
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                        cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << totalScore << endl;
                                        system("pause");
                                    }
                                    else if (totalScore + tempScoreAccumulator == loseTotalScore)
                                    {
                                        tempScoreAccumulator = 0;
                                        totalScore = 0;
                                        rolledDice = 1;

                                        system("cls");
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t   JUGADOR 1 - TIRADA NRO. " << rolledDice << endl;
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                        cout << "\n\t\tLlegaste a 100, has perdido todos tus puntos!" << endl;
                                        cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << totalScore << endl;
                                        system("pause");
                                    }
                                    else if (totalScore + tempScoreAccumulator > winScore)
                                    {
                                        tempScoreAccumulator = 0;
                                        rolledDice = 1;

                                        system("cls");
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t   JUGADOR 1 - TIRADA NRO. " << rolledDice << endl;
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                        cout << "\n\t\tTe pasaste, no acumulas puntos!" << endl;
                                        cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << totalScore << endl;
                                        system("pause");
                                    }
                                    else
                                    {
                                        rolledDice = 1;
                                        totalScore += tempScoreAccumulator;
                                        tempScoreAccumulator = 0;
                                    }
                                    break;
                                default:
                                    cout << "ERROR AL SELECCIONAR OPCION!" << endl;
                                    system("pause");
                                    break;
                            }

                        } while (totalScore < winScore);

                        if (totalScore == winScore)
                        {
                            system("cls");
                            cout << "\t\t------------------------------" << endl;
                            cout << "\t\t   JUGADOR 1 - TIRADA NRO. " << rolledDice << endl;
                            cout << "\t\t------------------------------" << endl;
                            cout << "\t\t\tULTIMO DADO: " << dice << endl;
                            cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << totalScore << endl;
                            cout << "\t\t------------------------------" << endl;
                            cout << "\t\t   FELICIDADES, HAS GANADO! " << endl;
                            cout << "\t\t------------------------------" << endl;
                            system("pause");
                        }

                        break; //Fin 1 jugador.
                    case TWOPLAYERS:
                        totalScore = 0;
                        playerTwoTotalScore = 0;

                        do
                        {
                            if (playerTurn == true)
                            {     
                                system("color 0A");
                                if (totalScore >= minCumulativeScore)
                                {
                                    playerOneMinScore = true;
                                }
                                else
                                {
                                    playerOneMinScore = false;
                                }

                                while (tempScoreAccumulator < minCumulativeScore && playerOneMinScore != true)
                                {
                                    dice = rand() % 6 + 1;

                                    if (dice == loseCumulativeScore)
                                    {
                                        tempScoreAccumulator = 0;
                                        rolledDice = 1;

                                        system("cls");
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t   JUGADOR 1 - TIRADA NRO. " << rolledDice << endl;
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                        cout << "\n\t\t      Perdiste el turno!" << endl;
                                        cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << totalScore << endl;
                                        system("pause");

                                        playerTurn = false;
                                        break;
                                    }
                                    else
                                    {
                                        tempScoreAccumulator += dice;
                                        ++rolledDice;

                                        system("cls");
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t   JUGADOR 1 - TIRADA NRO. " << rolledDice << endl;
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                        cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << totalScore << endl;
                                        system("pause");
                                    }                                  
                                }

                                if (playerTurn != false)
                                {
                                    do
                                    {
                                        system("cls");
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t   JUGADOR 1 - TIRADA NRO. " << rolledDice << endl;
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                        cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << totalScore << endl;
                                        cout << "\n\t\t1-SEGUIR TIRANDO.\n\t\t2-ANOTAR PUNTOS." << endl;
                                        cin >> option;
                                    } while (option < CONTINUE || option > STOP);
                                }
                                                               
                                playersChoice = static_cast<Menu>(option);

                                switch (playersChoice)
                                {
                                case CONTINUE:
                                    dice = rand() % 6 + 1;

                                    if (dice == loseCumulativeScore)
                                    {
                                        if (tempScoreAccumulator == 0)
                                        {
                                            rolledDice = 1;

                                            system("cls");
                                            cout << "\t\t------------------------------" << endl;
                                            cout << "\t\t   JUGADOR 1 - TIRADA NRO. " << rolledDice << endl;
                                            cout << "\t\t------------------------------" << endl;
                                            cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                            cout << "\n\t\t      Perdiste el turno!" << endl;
                                            cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << totalScore << endl;
                                            system("pause");

                                            playerTurn = false;
                                            break;
                                        }
                                        else
                                        {
                                            tempScoreAccumulator = 0;
                                            rolledDice = 1;

                                            system("cls");
                                            cout << "\t\t------------------------------" << endl;
                                            cout << "\t\t   JUGADOR 1 - TIRADA NRO. " << rolledDice << endl;
                                            cout << "\t\t------------------------------" << endl;
                                            cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                            cout << "\n\t\tPerdiste los puntos acumulados!" << endl;
                                            cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << totalScore << endl;
                                            system("pause");

                                            playerTurn = false;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        tempScoreAccumulator += dice;
                                        ++rolledDice;
                                    }

                                    break;
                                case STOP:
                                    if (totalScore >= maxCumulativeScore && totalScore + tempScoreAccumulator != winScore)
                                    {
                                        tempScoreAccumulator = 0;
                                        rolledDice = 1;

                                        system("cls");
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t   JUGADOR 1 - TIRADA NRO. " << rolledDice << endl;
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                        cout << "\n\t\tNo se puede anotar mas de 99 puntos!" << endl;
                                        cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << totalScore << endl;
                                        system("pause");

                                        playerTurn = false;
                                        break;
                                    }
                                    else if (totalScore + tempScoreAccumulator == winScore)
                                    {
                                        totalScore += tempScoreAccumulator;
                                        tempScoreAccumulator = 0;
                                        rolledDice = 1;

                                        system("cls");
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t   JUGADOR 1 - TIRADA NRO. " << rolledDice << endl;
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                        cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << totalScore << endl;
                                        system("pause");
                                    }
                                    else if (totalScore + tempScoreAccumulator == loseTotalScore)
                                    {
                                        tempScoreAccumulator = 0;
                                        totalScore = 0;
                                        rolledDice = 1;

                                        system("cls");
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t   JUGADOR 1 - TIRADA NRO. " << rolledDice << endl;
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                        cout << "\n\t\tLlegaste a 100, has perdido todos tus puntos!" << endl;
                                        cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << totalScore << endl;
                                        system("pause");

                                        playerTurn = false;
                                        break;
                                    }
                                    else if (totalScore + tempScoreAccumulator > winScore)
                                    {
                                        tempScoreAccumulator = 0;
                                        rolledDice = 1;

                                        system("cls");
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t   JUGADOR 1 - TIRADA NRO. " << rolledDice << endl;
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                        cout << "\n\t\tTe pasaste, no acumulas puntos!" << endl;
                                        cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << totalScore << endl;
                                        system("pause");

                                        playerTurn = false;
                                        break;
                                    }
                                    else
                                    {
                                        rolledDice = 1;
                                        totalScore += tempScoreAccumulator;
                                        tempScoreAccumulator = 0;

                                        playerTurn = false;
                                        break;
                                    }
                                    break;
                                default:
                                    cout << "ERROR AL SELECCIONAR OPCION!" << endl;
                                    system("pause");
                                    break;
                                }
                            }
                            else
                            {
                                system("color 0C");
                                if (playerTwoTotalScore >= minCumulativeScore)
                                {
                                    playerTwoMinScore = true;
                                }
                                else
                                {
                                    playerTwoMinScore = false;
                                }

                                while (tempScoreAccumulator < minCumulativeScore && playerTwoMinScore != true)
                                {
                                    dice = rand() % 6 + 1;

                                    if (dice == loseCumulativeScore)
                                    {
                                        tempScoreAccumulator = 0;
                                        rolledDice = 1;

                                        system("cls");
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t   JUGADOR 2 - TIRADA NRO. " << rolledDice << endl;
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                        cout << "\n\t\t      Perdiste el turno!" << endl;
                                        cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << playerTwoTotalScore << endl;
                                        system("pause");

                                        playerTurn = true;
                                        break;
                                    }
                                    else
                                    {
                                        tempScoreAccumulator += dice;
                                        ++rolledDice;

                                        system("cls");
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t   JUGADOR 2 - TIRADA NRO. " << rolledDice << endl;
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                        cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << playerTwoTotalScore << endl;
                                        system("pause");
                                    }                                   
                                }

                                if (playerTurn != true)
                                {
                                    do
                                    {
                                        system("cls");
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t   JUGADOR 2 - TIRADA NRO. " << rolledDice << endl;
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                        cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << playerTwoTotalScore << endl;
                                        cout << "\n\t\t1-SEGUIR TIRANDO.\n\t\t2-ANOTAR PUNTOS." << endl;
                                        cin >> option;
                                    } while (option < CONTINUE || option > STOP);
                                }

                                playersChoice = static_cast<Menu>(option);

                                switch (playersChoice)
                                {
                                case CONTINUE:
                                    dice = rand() % 6 + 1;

                                    if (dice == loseCumulativeScore)
                                    {
                                        if (tempScoreAccumulator == 0)
                                        {
                                            rolledDice = 1;

                                            system("cls");
                                            cout << "\t\t------------------------------" << endl;
                                            cout << "\t\t   JUGADOR 2 - TIRADA NRO. " << rolledDice << endl;
                                            cout << "\t\t------------------------------" << endl;
                                            cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                            cout << "\n\t\t      Perdiste el turno!" << endl;
                                            cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << playerTwoTotalScore << endl;
                                            system("pause");

                                            playerTurn = true;
                                            break;
                                        }
                                        else
                                        {
                                            tempScoreAccumulator = 0;
                                            rolledDice = 1;

                                            system("cls");
                                            cout << "\t\t------------------------------" << endl;
                                            cout << "\t\t   JUGADOR 2 - TIRADA NRO. " << rolledDice << endl;
                                            cout << "\t\t------------------------------" << endl;
                                            cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                            cout << "\n\t\tPerdiste los puntos acumulados!" << endl;
                                            cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << playerTwoTotalScore << endl;
                                            system("pause");

                                            playerTurn = true;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        tempScoreAccumulator += dice;
                                        ++rolledDice;
                                    }

                                    break;
                                case STOP:
                                    if (playerTwoTotalScore >= maxCumulativeScore && playerTwoTotalScore + tempScoreAccumulator != winScore)
                                    {
                                        tempScoreAccumulator = 0;
                                        rolledDice = 1;

                                        system("cls");
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t   JUGADOR 2 - TIRADA NRO. " << rolledDice << endl;
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                        cout << "\n\t\tNo se puede anotar mas de 99 puntos!" << endl;
                                        cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << playerTwoTotalScore << endl;
                                        system("pause");

                                        playerTurn = true;
                                        break;
                                    }
                                    else if (playerTwoTotalScore + tempScoreAccumulator == winScore)
                                    {
                                        playerTwoTotalScore += tempScoreAccumulator;
                                        tempScoreAccumulator = 0;
                                        rolledDice = 1;

                                        system("cls");
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t   JUGADOR 2 - TIRADA NRO. " << rolledDice << endl;
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                        cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << playerTwoTotalScore << endl;
                                        system("pause");
                                    }
                                    else if (playerTwoTotalScore + tempScoreAccumulator == loseTotalScore)
                                    {
                                        tempScoreAccumulator = 0;
                                        playerTwoTotalScore = 0;
                                        rolledDice = 1;

                                        system("cls");
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t   JUGADOR 2 - TIRADA NRO. " << rolledDice << endl;
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                        cout << "\n\t\tLlegaste a 100, has perdido todos tus puntos!" << endl;
                                        cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << playerTwoTotalScore << endl;
                                        system("pause");

                                        playerTurn = true;
                                        break;
                                    }
                                    else if (playerTwoTotalScore + tempScoreAccumulator > winScore)
                                    {
                                        tempScoreAccumulator = 0;
                                        rolledDice = 1;

                                        system("cls");
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t   JUGADOR 2 - TIRADA NRO. " << rolledDice << endl;
                                        cout << "\t\t------------------------------" << endl;
                                        cout << "\t\t\tULTIMO DADO: " << dice << endl;
                                        cout << "\n\t\tTe pasaste, no acumulas puntos!" << endl;
                                        cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << playerTwoTotalScore << endl;
                                        system("pause");

                                        playerTurn = true;
                                        break;
                                    }
                                    else
                                    {
                                        rolledDice = 1;
                                        playerTwoTotalScore += tempScoreAccumulator;
                                        tempScoreAccumulator = 0;

                                        playerTurn = true;
                                        break;
                                    }
                                    break;
                                default:
                                    cout << "ERROR AL SELECCIONAR OPCION!" << endl;
                                    system("pause");
                                    break;
                                }
                            }
                        } while (totalScore < winScore && playerTwoTotalScore < winScore);

                        if (totalScore == winScore)
                        {
                            system("cls");
                            cout << "\t\t------------------------------" << endl;
                            cout << "\t\t   JUGADOR 1 - TIRADA NRO. " << rolledDice << endl;
                            cout << "\t\t------------------------------" << endl;
                            cout << "\t\t\tULTIMO DADO: " << dice << endl;
                            cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << totalScore << endl;
                            cout << "\t\t------------------------------" << endl;
                            cout << "\t\t    JUGADOR 1 HA GANADO! " << endl;
                            cout << "\t\t------------------------------" << endl;
                            system("pause");
                        }
                        else
                        {
                            system("cls");
                            cout << "\t\t------------------------------" << endl;
                            cout << "\t\t   JUGADOR 2 - TIRADA NRO. " << rolledDice << endl;
                            cout << "\t\t------------------------------" << endl;
                            cout << "\t\t\tULTIMO DADO: " << dice << endl;
                            cout << "\n\t\tPUNTAJE ACUMULADO: " << tempScoreAccumulator << endl << "\t\tPUNTAJE TOTAL: " << playerTwoTotalScore << endl;
                            cout << "\t\t------------------------------" << endl;
                            cout << "\t\t    JUGADOR 2 HA GANADO! " << endl;
                            cout << "\t\t------------------------------" << endl;
                            system("pause");
                        }

                        break; //Fin 2 jugadores.
                    default:
                        cout << "ERROR AL SELECCIONAR CANTIDAD DE JUGADORES!" << endl;
                        system("pause");
                        break;
                }
                break; //Fin "PLAY".
            case RULES:
                system("cls");
                cout << "\t\t---------------------------------------------" << endl;
                cout << "\t\t\t      REGLAS DEL JUEGO" << endl;
                cout << "\t\t---------------------------------------------" << endl;
                cout << "\t-Se juega utilizando un solo dado de seis caras." << endl;
                cout << "\t-La cantidad minima de jugadores es dos pero se puede jugar de a uno." << endl;
                cout << "\t-El objetivo principal es llegar a los 101 puntos, quien lo haga ganara la partida." << endl;
                cout << "\t-Cada cara del dado suma puntos a excepcion del 1." << endl;
                cout << "\t-Al sacar 1 se perderan todos los puntos acumulados en el turno." << endl;
                cout << "\t-El jugador podra elegir entre seguir tirando el dado o anotar los puntos acumulados." << endl;
                cout << "\t-Si el jugador saca 1 y tenia puntos anotados, la proxima ronda vuelve a empezar\n\t desde esa cantidad anotada; de lo contrario empieza nuevamente desde 0." << endl;
                cout << "\t-Para que el jugador tenga la oportunidad de anotar los puntos acumulados primero\n\t debe haber superado los 25 puntos." << endl;
                cout << "\t-Luego de haber superado los 25 puntos por primera vez el jugador podra anotar los\n\t puntos acumulados cuando desee, esto hara que termine su turno." << endl;
                cout << "\t-Si alguno de los jugadores suma 100 puntos perdera todos sus puntos y debera empezar desde 0." << endl;
                cout << "\t-Si la suma del puntaje total y el puntaje acumulado en el turno supera los 101, se dara\n\t por terminado el turno del jugador y seguira con la cantidad de puntos previa." << endl;
                system("pause");
                break;
            case CREDITS:
                system("cls");
                cout << "\t\t------------------------------" << endl;
                cout << "\t\t\t     101" << endl;
                cout << "\t\t------------------------------" << endl;
                cout << "\t\t  Hecho por: Daniel Gianetto" << endl;
                cout << "\t\t------------------------------" << endl;
                system("pause");
                break;
            case QUIT:
                system("cls");
                cout << "\t\t------------------------------" << endl;
                cout << "\t\t      GRACIAS POR JUGAR!" << endl;
                cout << "\t\t------------------------------" << endl;                
                break;
            default:
                cout << "ERROR AL SELECCIONAR OPCION!" << endl;
                system("pause");
                break;
        }

    } while (playersChoice != QUIT);

}
