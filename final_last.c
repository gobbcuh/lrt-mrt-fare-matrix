#include <stdio.h>

int main()
{
    char LRT1Stations[20][20] = {"Baclaran", "Edsa", "Libertad", "Gil Puyat", "Vito Cruz", "Quirino", "Pedro Gil", "UN Avenue", "Central", "Carriedo", "D. Jose", "Bambang", "Tayuman", "Blumentritt", "Abad Santos", "R. Papa", "5th Avenue", "Monumento", "Balintawak", "Fernando Poe Jr."};
    
    int LRT1Fares_beep[20][20] = {{0, 14, 15, 16, 17, 18, 19, 20, 22, 23, 23, 24, 25, 26, 27, 28, 29, 30, 33, 35}, {14, 0, 15, 15, 17, 18, 19, 20, 21, 22, 23, 24, 24, 25, 26, 27, 28, 29, 32, 34}, {15, 15, 0, 14, 15, 16, 17, 18, 20, 21, 22, 22, 23, 24, 25, 26, 27, 28, 31, 33}, {16, 15, 14, 0, 15, 16, 17, 17, 19, 20, 21, 21, 22, 23, 24, 25, 26, 27, 30, 32}, {17, 17, 15, 15, 0, 14, 15, 16, 18, 19, 19, 20, 21, 22, 23, 24, 25, 26, 29, 31}, {18, 18, 16, 16, 14, 0, 14, 15, 17, 18, 18, 19, 20, 21, 22, 23, 24, 25, 28, 30}, {19, 19, 17, 17, 15, 14, 0, 14, 16, 17, 17, 18, 19, 20, 21, 22, 23, 24, 27, 29}, {20, 20, 18, 17, 16, 15, 14, 0, 15, 16, 16, 17, 18, 19, 20, 21, 22, 23, 26, 28}, {22, 21, 20, 19, 18, 17, 16, 15, 0, 14, 15, 16, 17, 17, 18, 19, 20, 22, 24, 27}, {23, 22, 21, 20, 19, 18, 17, 16, 14, 0, 14, 15, 16, 16, 18, 18, 20, 21, 24, 26}, {23, 23, 22, 21, 19, 18, 17, 16, 15, 14, 0, 14, 15, 16, 17, 18, 19, 20, 23, 25}, {24, 24, 22, 21, 20, 19, 18, 17, 16, 15, 14, 0, 14, 15, 16, 17, 18, 19, 22, 24}, {25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 0, 14, 15, 16, 17, 18, 21, 23}, {26, 25, 24, 23, 22, 21, 20, 19, 17, 16, 16, 15, 14, 0, 14, 15, 16, 18, 20, 23}, {27, 26, 25, 24, 23, 22, 21, 20, 18, 18, 17, 16, 15, 14, 0, 14, 15, 17, 19, 22}, {28, 27, 26, 25, 24, 23, 22, 21, 19, 18, 18, 17, 16, 15, 14, 0, 14, 16, 18, 21}, {29, 28, 27, 26, 25, 24, 23, 22, 20, 20, 19, 18, 17, 16, 15, 14, 0, 15, 17, 20}, {30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 18, 17, 16, 15, 0, 16, 18}, {33, 32, 31, 30, 29, 28, 27, 26, 24, 24, 23, 22, 21, 20, 19, 18, 17, 16, 0, 16}, {35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 23, 22, 21, 20, 18, 16, 0}};

    int LRT1Fares_single_journey[20][20] = {{0, 15, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30, 30, 30, 30, 35, 35}, {15, 0, 15, 15, 20, 20, 20, 20, 25, 25, 25, 25, 25, 25, 30, 30, 30, 30, 35, 35}, {15, 15, 0, 15, 15, 20, 20, 20, 20, 25, 25, 25, 25, 25, 25, 30, 30, 30, 35, 35}, {20, 15, 15, 0, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 25, 30, 30, 30, 35}, {20, 20, 15, 15, 0, 15, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30, 35}, {20, 20, 20, 20, 15, 0, 15, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30}, {20, 20, 20, 20, 15, 15, 0, 15, 20, 20, 20, 20, 20, 20, 25, 25, 25, 25, 30, 30}, {20, 20, 20, 20, 20, 15, 15, 0, 15, 20, 20, 20, 20, 20, 20, 25, 25, 25, 30, 30}, {25, 25, 20, 20, 20, 20, 20, 15, 0, 15, 15, 20, 20, 20, 20, 20, 20, 25, 25, 30}, {25, 25, 25, 20, 20, 20, 20, 20, 15, 0, 15, 15, 20, 20, 20, 20, 20, 25, 25, 30}, {25, 25, 25, 25, 20, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 20, 20, 20, 25, 25}, {25,25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 20, 20, 25, 25}, {25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 20, 25, 25}, {30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 20, 25}, {30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 25}, {30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 0, 15, 20, 20, 25}, {30, 30, 30, 30, 25, 25, 25, 25, 20, 20, 20, 20, 20, 20, 15, 15, 0, 15, 20, 20}, {30, 30, 30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 20, 15, 0, 20, 20}, {35, 35, 35, 30, 30, 30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 0, 20}, {35, 35, 35, 35, 35, 30, 30, 30, 30, 30, 25, 25, 25, 25, 25, 25, 20, 20, 20, 0}};

    char LRT2Stations[13][10] = {"Recto", "Legarda", "Pureza", "V. Mapa", "J. Ruiz", "Gilmore", "Betty Go", "Cubao", "Anonas", "Katipunan", "Santolan", "Marikina", "Antipolo"};

    int LRT2Fares_beep[13][13] = {{0, 15, 16, 18, 19, 21, 22, 23, 25, 26, 28, 31, 33}, {15, 0, 15, 17, 18, 19, 21, 22, 24, 25, 27, 29, 32}, {16, 15, 0, 15, 16, 18, 19, 20, 22, 23, 26, 28, 30}, {18, 17, 15, 0, 15, 16, 17, 19, 20, 22, 24, 26, 29}, {19, 18, 16, 15, 0, 14, 16, 17, 19, 20, 22, 24, 27}, {21, 19, 18, 16, 14, 0, 15, 16, 18, 19, 21, 23, 26}, {22, 21, 19, 17, 16, 15, 10, 15, 16, 18, 20, 22, 25}, {23, 22, 20, 19, 17, 16, 15, 0, 15, 16, 19, 21, 23}, {25, 24, 22, 20, 19, 18, 16, 15, 0, 14, 17, 19, 22}, {26, 25, 23, 22, 20, 19, 18, 16, 14, 0, 16, 18, 21}, {28, 27, 26, 24, 22, 21, 20, 19, 17, 16, 0, 15, 18}, {31, 29, 28, 26, 24, 23, 22, 21, 19, 18, 15, 0, 16}, {33, 32, 30, 29, 27, 26, 25, 23, 22, 21, 18, 16, 0}};

    int LRT2Fares_single_journey[13][13] = {{0, 15, 20, 20, 20, 25, 25, 25, 25, 30, 30, 35, 35}, {15, 0, 15, 20, 20, 20, 25, 25, 25, 25, 30, 30, 35}, {20, 15, 0, 15, 20, 20, 20, 20, 25, 25, 30, 30, 30}, {20, 20, 15, 0, 15, 20, 20, 20, 20, 25, 25, 30}, {20, 20, 20, 15, 0, 15, 20, 20, 20, 20, 25, 25, 30}, {25, 20, 20, 20, 15, 0, 15, 20, 20, 20, 25, 25, 30}, {25, 25, 20, 20, 20, 15, 0, 15, 20, 20, 20, 25, 25}, {25, 25, 20, 20, 20, 20, 15, 0, 15, 20, 20, 25, 25}, {25, 25, 25, 20, 20, 20, 20, 15, 0, 15, 20, 20, 25}, {30, 25, 25, 25, 20, 20, 20, 20, 15, 0, 20, 20, 25}, {30, 30, 30, 25, 25, 25, 20, 20, 20, 20, 0, 15, 20}, {35, 30, 30, 30, 25, 25, 25, 25, 20, 20, 15, 0, 20}, {35, 35, 30, 30, 30, 30, 25, 25, 25, 25, 20, 20, 0}};

    char MRT3Stations[13][20] = {"North Avenue", "Quezon Avenue", "GMA Kamuning", "Araneta", "Santolan-Annapolis", "Ortigas", "Shaw Boulevard", "Boni Avenue", "Guadalupe", "Buendia", "Ayala", "Magallanes", "Taft Avenue"};

    int MRT3Fares_beep[13][13] = {{0, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24, 28, 28}, {13, 0, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24, 28}, {13, 13, 0, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24}, {16, 13, 13, 0, 13, 13, 16, 16, 20, 20, 20, 24, 24}, {16, 16, 13, 13, 0, 13, 13, 16, 16, 20, 20, 20, 24}, {20, 16, 16, 13, 13, 0, 13, 13, 16, 16, 20, 20, 20}, {20, 20, 16, 16, 13, 13, 0, 13, 13, 16, 16, 20, 20}, {20, 20, 20, 16, 16, 13, 13, 0, 13, 13, 16, 16, 20}, {24, 20, 20, 20, 16, 16, 13, 13, 0, 13, 13, 16, 16}, {24, 24, 20, 20, 20, 16, 16, 13, 13, 0, 13, 13, 16}, {24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0, 13, 13}, {28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0, 13}, {28, 28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0}};

    int MRT3Fares_single_journey [13][13] = {{0, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24, 28, 28}, {13, 0, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24, 28}, {13, 13, 0, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24}, {16, 13, 13, 0, 13, 13, 16, 16, 20, 20, 20, 24, 24}, {16, 16, 13, 13, 0, 13, 13, 16, 16, 20, 20, 20, 24}, {20, 16, 16, 13, 13, 0, 13, 13, 16, 16, 20, 20, 20}, {20, 20, 16, 16, 13, 13, 0, 13, 13, 16, 16, 20, 20}, {20, 20, 20, 16, 16, 13, 13, 0, 13, 13, 16, 16, 20}, {24, 20, 20, 20, 16, 16, 13, 13, 0, 13, 13, 16, 16}, {24, 24, 20, 20, 20, 16, 16, 13, 13, 0, 13, 13, 16}, {24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0, 13, 13}, {28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0, 13}, {28, 28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0}};

    int railwayLine, cardType, passengerStatus, initialStation, endStation;
    float currentFare, overallFare = 0.0, passengerDiscount = 1.00;
    char passengerChoice;

    printf("\t\tWelcome to Railway Lines Fare Matrix\n----------------------------------------------------");
    // Prompt the user for the railway line
    printf("\nRailway Network Lines:\n1. LRT-1\n2. LRT-2\n3. MRT-3\n\n");

    do
    {
        printf("Your railway line: ");
        scanf("%d", &railwayLine);

        switch(railwayLine)
        {
            case 1:
                printf("You are currently riding LRT-1!\n");
                break;
                
            case 2:
                printf("You are currently riding LRT-2!\n");
                break;
                
            case 3:
                printf("You are currently riding MRT-3!\n");
                break;
                
            default:
                printf("Invalid. Please enter a valid railway network line number.\n");
                break;
        }
    } while (railwayLine != 1 && railwayLine != 2 && railwayLine != 3);


    printf("----------------------------------------------------\n");
    printf("Card Types:\n1. Stored Value (Beep) Fare Card\n2. Single Journey Fare Card\n");
   
    do
    {
        if (railwayLine == 1 || railwayLine == 2 || railwayLine == 3)
        {
            printf("\nEnter your card: ");
            scanf("%d", &cardType);

            switch(cardType)
            {
                case 1:
                    printf("Your card is: Stored Value (Beep) Fare Card\n");
                    break;
                    
                case 2:
                    printf("Your card is: Single Journey Fare Card\n");
                    break;
                    
                default:
                    printf("Invalid. Please enter a valid card type number.\n");
                    break;
            }
        }
    } while (cardType != 1 && cardType != 2);
   
    printf("----------------------------------------------------\n");

    printf("Select one that applies:\n1. PWD\n2. Senior Citizen\n3. Student\n4. Regular Passenger\n");
   
    do
    {
        if (railwayLine == 1 || railwayLine == 2 || railwayLine == 3)
        {
            printf("\nEnter your status: ");
            scanf("%d", &passengerStatus);

            if (passengerStatus == 1 || passengerStatus == 2)
            {
                passengerDiscount = 0.70;
                printf("You are eligible for a 30%% discount\n");
            }
            else if (passengerStatus == 3)
            {
                passengerDiscount = 0.80;
                printf("You are eligible for a 20%% discount\n");
            }
            else if (passengerStatus == 4)
            {
                printf("No discount will be applied\n");
            }
            else
            {
                printf("Invalid. Please enter a valid status number.\n");
            }
        }
    } while (passengerStatus < 1 || passengerStatus > 4);

    printf("----------------------------------------------------\n");

    if (railwayLine == 1)
    {
        printf("Choose from the following LRT1 stations:\n");
        int i = 0;
        do
        {
            printf("%d. %s\n", i + 1, LRT1Stations[i]);
            i++;
        } while (i < 20);
    }
    else if (railwayLine == 2)
    {
        printf("Choose from the following LRT2 stations:\n");
        int i = 0;
        do
        {
            printf("%d. %s\n", i + 1, LRT2Stations[i]);
            i++;
        } while (i < 13);
    }
    else if (railwayLine == 3)
    {
        printf("Choose from the following MRT3 stations:\n");
        int i = 0;
        do
        {
            printf("%d. %s\n", i + 1, MRT3Stations[i]);
            i++;
        } while (i < 13);
    }

    do
    {
        printf("\nEnter your initial station: ");
        scanf("%d", &initialStation);
        
        if ((railwayLine == 1 && (initialStation < 1 || initialStation > 20)) ||
            (railwayLine == 2 && (initialStation < 1 || initialStation > 13)) ||
            (railwayLine == 3 && (initialStation < 1 || initialStation > 13)))
        {
            printf("Invalid. Please enter a valid initial station number.\n");
        }
    } while ((railwayLine == 1 && (initialStation < 1 || initialStation > 20)) || (railwayLine == 2 && (initialStation < 1 || initialStation > 13)) || (railwayLine == 3 && (initialStation < 1 || initialStation > 13)));

    do
    {
        do
        {
            printf("\nEnter your destination station: ");
            scanf("%d", &endStation);
            
            if ((railwayLine == 1 && (endStation < 1 || endStation > 20)) || (railwayLine == 2 && (endStation < 1 || endStation > 13)) ||(railwayLine == 3 && (endStation < 1 || endStation > 13)))
            {
                printf("Invalid. Please enter a valid destination station number.\n");
            }
        } while ((railwayLine == 1 && (endStation < 1 || endStation > 20)) || (railwayLine == 2 && (endStation < 1 || endStation > 13)) || (railwayLine == 3 && (endStation < 1 || endStation > 13)));

        if (railwayLine == 1 || railwayLine || 2 || railwayLine == 3)
        {
            if (initialStation == endStation)
            {
                printf("You're already at your destination.\n");
                printf("Would you like to proceed to another station?\nY if YES\nN if NO\n");
                printf("Your choice: ");
                scanf(" %c", &passengerChoice);
                if (passengerChoice == 'Y' || passengerChoice == 'y')
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
        }

        if (railwayLine == 1)
        {
            if (cardType == 1)
            {
                currentFare = LRT1Fares_beep[initialStation - 1][endStation - 1] * passengerDiscount;
            }
            else
            {
                currentFare = LRT1Fares_single_journey[initialStation - 1][endStation - 1] * passengerDiscount;
            }
        }
        else if (railwayLine == 2)
        {
            if (cardType == 1)
            {
                currentFare = LRT2Fares_beep[initialStation - 1][endStation - 1] * passengerDiscount;
            }
            else
            {
                currentFare = LRT2Fares_single_journey[initialStation - 1][endStation - 1] * passengerDiscount;
            }
        }
        else if (railwayLine == 3)
        {
            if (cardType == 1)
            {
                currentFare = MRT3Fares_beep[initialStation - 1][endStation - 1] * passengerDiscount;
            }
            else
            {
                currentFare = MRT3Fares_single_journey[initialStation - 1][endStation - 1] * passengerDiscount;
            }
        }

        char initialStationName[20];
        char endStationName[20];

        int j = 0;
        while (j < 20)
        {
            if (railwayLine == 1)
            {
                initialStationName[j] = LRT1Stations[initialStation - 1][j];
                endStationName[j] = LRT1Stations[endStation - 1][j];
            }
            else if (railwayLine == 2)
            {
                initialStationName[j] = LRT2Stations[initialStation - 1][j];
                endStationName[j] = LRT2Stations[endStation - 1][j];
            }
            else
            {
                initialStationName[j] = MRT3Stations[initialStation - 1][j];
                endStationName[j] = MRT3Stations[endStation - 1][j];
            }
            j++;
        }

        overallFare = overallFare + currentFare;
        
        printf("\nFare from %s to %s is: PHP %.2f\n", initialStationName, endStationName, currentFare);
        printf("Current overall fare: PHP %.2f\n", overallFare);

        if (railwayLine == 1 && endStation == 11) // Transfer from LRT1 to LRT2 (D. Jose to Recto)
        {  
            printf("\nYou have arrived at D. Jose, which intersects with LRT-2.\nWould you like to transfer to LRT-2?\nY if YES\nN if NO\n");
            printf("Your choice: ");
            scanf(" %c", &passengerChoice);

            if (passengerChoice == 'Y' || passengerChoice == 'y')
            {
                railwayLine = 2;
                initialStation = 1;
                
                printf("----------------------------------------------------\n");
                printf("You are now riding LRT-2.\nCurrent station: Recto\n");

                printf("\nWould you like to proceed to another station?\nY if YES\nN if NO");
                printf("\nYour choice: ");
                scanf(" %c", &passengerChoice);

                if (passengerChoice == 'Y' || passengerChoice == 'y')
                {
                    printf("\nChoose from the following LRT2 stations:\n");
                    int i = 0;
                    do
                    {
                        printf("%d. %s\n", i + 1, LRT2Stations[i]);
                        i++;
                    } while (i < 13);
                    continue;
                }
                else if (passengerChoice == 'N' || passengerChoice == 'n')
                {
                    printf("----------------------------------------------------\n");
                    printf("Your total fare for the entire trip is: PHP %.2f\n", overallFare);
                    printf("Thank you for using Railway Lines Fare Matrix Calculator!\n");
                    return 0;
                }
                else
                {
                    printf("Invalid. Please input between 'Y' or 'N' only\n");
                }
            }
        }
        else if (railwayLine == 2 && endStation == 1) // Transfer from LRT2 to LRT1 (Recto to D. Jose)
        {  
            printf("\nYou have arrived at Recto, which intersects with LRT-1.\nWould you like to transfer to LRT-1?\nY if YES\nN if NO\n");
            printf("Your choice: ");
            scanf(" %c", &passengerChoice);

            if (passengerChoice == 'Y' || passengerChoice == 'y')
            {
                railwayLine = 1;
                initialStation = 11;
                
                printf("----------------------------------------------------\n");
                printf("You are now riding LRT-1.\nCurrent station: D. Jose\n");

                printf("\nWould you like to proceed to another station?\nY if YES\nN if NO");
                printf("\nYour choice: ");
                scanf(" %c", &passengerChoice);

                if (passengerChoice == 'Y' || passengerChoice == 'y')
                {
                    printf("\nChoose from the following LRT1 stations:\n");
                    int i = 0;
                    do
                    {
                        printf("%d. %s\n", i + 1, LRT1Stations[i]);
                        i++;
                    } while (i < 20);
                    continue;
                }
            }
        }
        else if (railwayLine == 1 && endStation == 2) // Transfer from LRT1 to MRT3 (EDSA to Taft)
        {  
            printf("\nYou have arrived at EDSA, which intersects with MRT-3.\nWould you like to transfer to MRT-3?\nY if YES\nN if NO\n");
            printf("Your choice: ");
            scanf(" %c", &passengerChoice);

            if (passengerChoice == 'Y' || passengerChoice == 'y')
            {
                railwayLine = 3; 
                initialStation = 13;  
                
                printf("----------------------------------------------------\n");
                printf("You are now riding MRT-3.\nCurrent station: Taft Avenue\n");
                printf("\nChoose from the following MRT3 stations:\n");
                int i = 0;
                do
                {
                    printf("%d. %s\n", i + 1, MRT3Stations[i]);
                    i++;
                } while (i < 13);
                continue;
            }
        }
        else if (railwayLine == 2 && endStation == 8) // Transfer from LRT2 to MRT3 (Cubao to Araneta)
        {  
            printf("\nYou have arrived at Cubao, which intersects with MRT-3.\nWould you like to transfer to MRT-3?\nY if YES\nN if NO\n");
            printf("Your choice: ");
            scanf(" %c", &passengerChoice);
           
            if (passengerChoice == 'Y' || passengerChoice == 'y')
            {
                railwayLine = 3;
                initialStation = 4;
                
                printf("----------------------------------------------------\n");
                printf("You are now riding MRT-3.\nCurrent station: Cubao\n");
                printf("\nChoose from the following MRT3 stations:\n");
                int i = 0;
                do
                {
                    printf("%d. %s\n", i + 1, MRT3Stations[i]);
                    i++;
                } while (i < 13);
                continue;
            }
        }
        else if (railwayLine == 3 && endStation == 4) // Transfer from MRT3 to LRT2 (Araneta to Cubao)
        {  
            printf("\nYou have arrived at Cubao, which intersects with LRT-2.\nWould you like to transfer to LRT-2?\nY if YES\nN if NO\n");
            printf("Your choice: ");
            scanf(" %c", &passengerChoice);

            if (passengerChoice == 'Y' || passengerChoice == 'y')
            {
                railwayLine = 2;
                initialStation = 8; 
                
                printf("----------------------------------------------------\n");
                printf("You are now riding LRT-2.\nCurrent station: Anonas\n");
                printf("\nChoose from the following LRT2 stations:\n");
                int i = 0;
                do
                {
                    printf("%d. %s\n", i + 1, LRT2Stations[i]);
                    i++;
                } while (i < 13);
                continue;
            }
        }
        else if (railwayLine == 3 && endStation == 13) // Transfer from MRT3 to LRT1 (Taft to EDSA)
        {  
            printf("\nYou have arrived at Taft Avenue, which intersects with LRT-1.\nWould you like to transfer to LRT-1?\nY if YES\nN if NO\n");
            printf("Your choice: ");
            scanf(" %c", &passengerChoice);

            if (passengerChoice == 'Y' || passengerChoice == 'y')
            {
                railwayLine = 1; 
                initialStation = 2;
                
                printf("----------------------------------------------------\n");
                printf("You are now riding LRT-1.\nCurrent station: EDSA\n");
                printf("\nChoose from the following LRT1 stations:\n");
                int i = 0;
                do
                {
                    printf("%d. %s\n", i + 1, LRT1Stations[i]);
                    i++;
                } while (i < 20);
                continue;
            }
        }

        printf("\nWould you like to proceed to another station?\nY if YES\nN if NO");
        printf("\nYour choice: ");
        scanf(" %c", &passengerChoice);

        if (passengerChoice == 'Y' || passengerChoice == 'y')
        {
            initialStation = endStation;
        }


    } while (passengerChoice == 'Y' || passengerChoice == 'y');

    printf("----------------------------------------------------\n");
    printf("Your total fare for the entire trip is: PHP %.2f\n", overallFare);
    printf("Thank you for using Railway Lines Fare Matrix Calculator!\n");

    return 0;
}