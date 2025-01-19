#include <stdio.h>

    char LRT1Stations[20][20] = {"Baclaran", "Edsa", "Libertad", "Gil Puyat", "Vito Cruz", "Quirino", "Pedro Gil", "UN Avenue", "Central", "Carriedo", "D. Jose", "Bambang", "Tayuman", "Blumentritt", "Abad Santos", "R. Papa", "5th Avenue", "Monumento", "Balintawak", "Fernando Poe Jr."};
    
    int LRT1Fares_beep[20][20] = {{0, 14, 15, 16, 17, 18, 19, 20, 22, 23, 23, 24, 25, 26, 27, 28, 29, 30, 33, 35}, {14, 0, 15, 15, 17, 18, 19, 20, 21, 22, 23, 24, 24, 25, 26, 27, 28, 29, 32, 34}, {15, 15, 0, 14, 15, 16, 17, 18, 20, 21, 22, 22, 23, 24, 25, 26, 27, 28, 31, 33}, {16, 15, 14, 0, 15, 16, 17, 17, 19, 20, 21, 21, 22, 23, 24, 25, 26, 27, 30, 32}, {17, 17, 15, 15, 0, 14, 15, 16, 18, 19, 19, 20, 21, 22, 23, 24, 25, 26, 29, 31}, {18, 18, 16, 16, 14, 0, 14, 15, 17, 18, 18, 19, 20, 21, 22, 23, 24, 25, 28, 30}, {19, 19, 17, 17, 15, 14, 0, 14, 16, 17, 17, 18, 19, 20, 21, 22, 23, 24, 27, 29}, {20, 20, 18, 17, 16, 15, 14, 0, 15, 16, 16, 17, 18, 19, 20, 21, 22, 23, 26, 28}, {22, 21, 20, 19, 18, 17, 16, 15, 0, 14, 15, 16, 17, 17, 18, 19, 20, 22, 24, 27}, {23, 22, 21, 20, 19, 18, 17, 16, 14, 0, 14, 15, 16, 16, 18, 18, 20, 21, 24, 26}, {23, 23, 22, 21, 19, 18, 17, 16, 15, 14, 0, 14, 15, 16, 17, 18, 19, 20, 23, 25}, {24, 24, 22, 21, 20, 19, 18, 17, 16, 15, 14, 0, 14, 15, 16, 17, 18, 19, 22, 24}, {25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 0, 14, 15, 16, 17, 18, 21, 23}, {26, 25, 24, 23, 22, 21, 20, 19, 17, 16, 16, 15, 14, 0, 14, 15, 16, 18, 20, 23}, {27, 26, 25, 24, 23, 22, 21, 20, 18, 18, 17, 16, 15, 14, 0, 14, 15, 17, 19, 22}, {28, 27, 26, 25, 24, 23, 22, 21, 19, 18, 18, 17, 16, 15, 14, 0, 14, 16, 18, 21}, {29, 28, 27, 26, 25, 24, 23, 22, 20, 20, 19, 18, 17, 16, 15, 14, 0, 15, 17, 20}, {30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 18, 17, 16, 15, 0, 16, 18}, {33, 32, 31, 30, 29, 28, 27, 26, 24, 24, 23, 22, 21, 20, 19, 18, 17, 16, 0, 16}, {35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 23, 22, 21, 20, 18, 16, 0}};

    int LRT1Fares_single_journey [20][20] = {{0, 15, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30, 30, 30, 30, 35, 35}, {15, 0, 15, 15, 20, 20, 20, 20, 25, 25, 25, 25, 25, 25, 30, 30, 30, 30, 35, 35}, {15, 15, 0, 15, 15, 20, 20, 20, 20, 25, 25, 25, 25, 25, 25, 30, 30, 30, 35, 35}, {20, 15, 15, 0, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 25, 30, 30, 30, 35}, {20, 20, 15, 15, 0, 15, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30, 35}, {20, 20, 20, 20, 15, 0, 15, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30}, {20, 20, 20, 20, 15, 15, 0, 15, 20, 20, 20, 20, 20, 20, 25, 25, 25, 25, 30, 30}, {20, 20, 20, 20, 20, 15, 15, 0, 15, 20, 20, 20, 20, 20, 20, 25, 25, 25, 30, 30}, {25, 25, 20, 20, 20, 20, 20, 15, 0, 15, 15, 20, 20, 20, 20, 20, 20, 25, 25, 30}, {25, 25, 25, 20, 20, 20, 20, 20, 15, 0, 15, 15, 20, 20, 20, 20, 20, 25, 25, 30}, {25, 25, 25, 25, 20, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 20, 20, 20, 25, 25}, {25,25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 20, 20, 25, 25}, {25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 20, 25, 25}, {30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 20, 25}, {30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 25}, {30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 0, 15, 20, 20, 25}, {30, 30, 30, 30, 25, 25, 25, 25, 20, 20, 20, 20, 20, 20, 15, 15, 0, 15, 20, 20}, {30, 30, 30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 20, 15, 0, 20, 20}, {35, 35, 35, 30, 30, 30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 0, 20}, {35, 35, 35, 35, 35, 30, 30, 30, 30, 30, 25, 25, 25, 25, 25, 25, 20, 20, 20, 0}};

    char LRT2Stations[13][10] = {"Recto", "Legarda", "Pureza", "V. Mapa", "J. Ruiz", "Gilmore", "Betty Go", "Cubao", "Anonas", "Katipunan", "Santolan", "Marikina", "Antipolo"};

    int LRT2Fares_beep[13][13] = {{0, 15, 16, 18, 19, 21, 22, 23, 25, 26, 28, 31, 33}, {15, 0, 15, 17, 18, 19, 21, 22, 24, 25, 27, 29, 32}, {16, 15, 0, 15, 16, 18, 19, 20, 22, 23, 26, 28, 30}, {18, 17, 15, 0, 15, 16, 17, 19, 20, 22, 24, 26, 29}, {19, 18, 16, 15, 0, 14, 16, 17, 19, 20, 22, 24, 27}, {21, 19, 18, 16, 14, 0, 15, 16, 18, 19, 21, 23, 26}, {22, 21, 19, 17, 16, 15, 10, 15, 16, 18, 20, 22, 25}, {23, 22, 20, 19, 17, 16, 15, 0, 15, 16, 19, 21, 23}, {25, 24, 22, 20, 19, 18, 16, 15, 0, 14, 17, 19, 22}, {26, 25, 23, 22, 20, 19, 18, 16, 14, 0, 16, 18, 21}, {28, 27, 26, 24, 22, 21, 20, 19, 17, 16, 0, 15, 18}, {31, 29, 28, 26, 24, 23, 22, 21, 19, 18, 15, 0, 16}, {33, 32, 30, 29, 27, 26, 25, 23, 22, 21, 18, 16, 0}};

    int LRT2Fares_single_journey[13][13] = {{0, 15, 20, 20, 20, 25, 25, 25, 25, 30, 30, 35, 35}, {15, 0, 15, 20, 20, 20, 25, 25, 25, 25, 30, 30, 35}, {20, 15, 0, 15, 20, 20, 20, 20, 25, 25, 30, 30, 30}, {20, 20, 15, 0, 15, 20, 20, 20, 20, 25, 25, 30}, {20, 20, 20, 15, 0, 15, 20, 20, 20, 20, 25, 25, 30}, {25, 20, 20, 20, 15, 0, 15, 20, 20, 20, 25, 25, 30}, {25, 25, 20, 20, 20, 15, 0, 15, 20, 20, 20, 25, 25}, {25, 25, 20, 20, 20, 20, 15, 0, 15, 20, 20, 25, 25}, {25, 25, 25, 20, 20, 20, 20, 15, 0, 15, 20, 20, 25}, {30, 25, 25, 25, 20, 20, 20, 20, 15, 0, 20, 20, 25}, {30, 30, 30, 25, 25, 25, 20, 20, 20, 20, 0, 15, 20}, {35, 30, 30, 30, 25, 25, 25, 25, 20, 20, 15, 0, 20}, {35, 35, 30, 30, 30, 30, 25, 25, 25, 25, 20, 20, 0}};
    
    char MRT3Stations [13][20] = {"North Avenue", "Quezon Avenue", "GMA Kamuning", "Cubao-Araneta", "Santolan-Annapolis", "Ortigas", "Shaw Boulevard", "Boni Avenue", "Guadalupe", "Buendia", "Ayala", "Magallanes", "Taft Avenue"};

    int MRT3Fares_beep[13][13] = {{0, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24, 28, 28}, {13, 0, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24, 28}, {13, 13, 0, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24}, {16, 13, 13, 0, 13, 13, 16, 16, 20, 20, 20, 24, 24}, {16, 16, 13, 13, 0, 13, 13, 16, 16, 20, 20, 20, 24}, {20, 16, 16, 13, 13, 0, 13, 13, 16, 16, 20, 20, 20}, {20, 20, 16, 16, 13, 13, 0, 13, 13, 16, 16, 20, 20}, {20, 20, 20, 16, 16, 13, 13, 0, 13, 13, 16, 16, 20}, {24, 20, 20, 20, 16, 16, 13, 13, 0, 13, 13, 16, 16}, {24, 24, 20, 20, 20, 16, 16, 13, 13, 0, 13, 13, 16}, {24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0, 13, 13}, {28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0, 13}, {28, 28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0}};
    
    int MRT3Fares_single_journey[13][13] = {{0, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24, 28, 28}, {13, 0, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24, 28}, {13, 13, 0, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24}, {16, 13, 13, 0, 13, 13, 16, 16, 20, 20, 20, 24, 24}, {16, 16, 13, 13, 0, 13, 13, 16, 16, 20, 20, 20, 24}, {20, 16, 16, 13, 13, 0, 13, 13, 16, 16, 20, 20, 20}, {20, 20, 16, 16, 13, 13, 0, 13, 13, 16, 16, 20, 20}, {20, 20, 20, 16, 16, 13, 13, 0, 13, 13, 16, 16, 20}, {24, 20, 20, 20, 16, 16, 13, 13, 0, 13, 13, 16, 16}, {24, 24, 20, 20, 20, 16, 16, 13, 13, 0, 13, 13, 16}, {24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0, 13, 13}, {28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0, 13}, {28, 28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0}};


int main() 
{
    int railwayLine, cardType, passengerStatus, initialStation, endStation;
    float overallFare = 0.0, currentFare, passengerDiscount = 1.00;
    char passengerChoice;

    // Prompt the user for the railway line
    do 
    {
        printf("Choose your initial railway network line:\n1. LRT-1\n2. LRT-2\n3. MRT-3\n");
        printf("Your railway line: ");
        scanf("%d", &railwayLine);
        if (railwayLine < 1 || railwayLine > 3) 
        {
            printf("Invalid. Please enter a valid railway line number.\n");
        }
    } while (railwayLine < 1 || railwayLine > 3);

    // Prompt for card type
    do 
    {
        printf("\nCard Types:\n1. Stored Value (Beep) Fare Card\n2. Single Journey Fare Card\n");
        printf("Enter your card type: ");
        scanf("%d", &cardType);
        if (cardType != 1 && cardType != 2) 
        {
            printf("Invalid. Please enter a valid card type number.\n");
        }
    } while (cardType != 1 && cardType != 2);
    
    // Ask for passenger status to determine discount
    do 
    {
        if (railwayLine == 1 || railwayLine == 2) 
        {
            printf("\nEnter your status:\n1. Senior Citizen\n2. PWD (Person with Disability)\n3. Student\n4. Regular\n");
            printf("Enter your status: ");
            scanf("%d", &passengerStatus);

            if (passengerStatus == 1 || passengerStatus == 2) 
            {
                passengerDiscount = 0.70; // 30% discount
                printf("You are eligible for a 30%% discount\n");
            } 
            else if (passengerStatus == 3) 
            {
                passengerDiscount = 0.80; // 20% discount
                printf("You are eligible for a 20%% discount\n");
            } 
            else if (passengerStatus == 4) 
            {
                printf("No discount will be applied\n");
            } 
            else {
                printf("Invalid. Please enter a valid status number.\n");
            }
        }
    } while (passengerStatus < 1 || passengerStatus > 4);

    // First trip: Print the relevant stations and ask for the initial station
    printf("\nChoose your station:\n");

    // Print stations based on the initial railway line
    if (railwayLine == 1) 
    {
        for (int i = 0; i < 20; i++) 
        {
            printf("%d. %s\n", i + 1, LRT1Stations[i]);
        }
    } 
    else if (railwayLine == 2) 
    {
        for (int i = 0; i < 13; i++) 
        {
            printf("%d. %s\n", i + 1, LRT2Stations[i]);
        }
    } 
    else if (railwayLine == 3) 
    {
        for (int i = 0; i < 13; i++) 
        {
            printf("%d. %s\n", i + 1, MRT3Stations[i]);
        }
    }

    // Enter the initial station (for the first trip)
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
    } while ((railwayLine == 1 && (initialStation < 1 || initialStation > 20)) ||
             (railwayLine == 2 && (initialStation < 1 || initialStation > 13)) ||
             (railwayLine == 3 && (initialStation < 1 || initialStation > 13)));

    // Main travel loop
    do 
    {
        // Enter the destination station
        do 
        {
            printf("\nEnter your destination station: ");
            scanf("%d", &endStation);
            if ((railwayLine == 1 && (endStation < 1 || endStation > 20)) ||
                (railwayLine == 2 && (endStation < 1 || endStation > 13)) ||
                (railwayLine == 3 && (endStation < 1 || endStation > 13))) 
            {
                printf("Invalid. Please enter a valid destination station number.\n");
            }
        } while ((railwayLine == 1 && (endStation < 1 || endStation > 20)) ||
                 (railwayLine == 2 && (endStation < 1 || endStation > 13)) ||
                 (railwayLine == 3 && (endStation < 1 || endStation > 13)));

        // Check if the initial and destination stations are the same
        if (initialStation == endStation) 
        {
            printf("You're already at your destination.\n");
            printf("Would you like to proceed to another station? (Y/N): ");
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

        // Fare calculation based on the selected line and card type
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
            } else 
            {
                currentFare = MRT3Fares_single_journey[initialStation - 1][endStation - 1] * passengerDiscount;
            }
        }

        // Get station names for fare message
        char *initialStationName = railwayLine == 1 ? LRT1Stations[initialStation - 1] : 
                                    railwayLine == 2 ? LRT2Stations[initialStation - 1] : 
                                    MRT3Stations[initialStation - 1];

        char *endStationName = railwayLine == 1 ? LRT1Stations[endStation - 1] : 
                               railwayLine == 2 ? LRT2Stations[endStation - 1] : 
                               MRT3Stations[endStation - 1];

        overallFare = overallFare + currentFare;
        printf("Fare from %s to %s is: PHP %.2f\n", initialStationName, endStationName, currentFare);
        printf("Current overall fare: PHP %.2f\n", overallFare);

        // Handle transfers at intersection stations
        if (railwayLine == 1 && endStation == 11) 
        {  // D. Jose (LRT1 -> LRT2)
            printf("You have arrived at D. Jose, which intersects with LRT-2.\nWould you like to transfer to LRT-2? (Y/N): ");
            scanf(" %c", &passengerChoice);
            if (passengerChoice == 'Y' || passengerChoice == 'y') 
            {
                railwayLine = 2;  // Switch to LRT-2
                initialStation = 1;  // Reset to Recto in LRT-2
                printf("You are now riding LRT-2. Current station: Recto\n");
                // Print LRT-2 stations after transferring
                printf("\nChoose your station:\n");
                for (int i = 0; i < 13; i++) 
                {
                    printf("%d. %s\n", i + 1, LRT2Stations[i]);
                }
                continue;
            }
        } 
        else if (railwayLine == 2 && endStation == 1) 
        {  // Recto (LRT2 -> LRT1)
            printf("You have arrived at Recto, which intersects with LRT-1.\nWould you like to transfer to LRT-1? (Y/N): ");
            scanf(" %c", &passengerChoice);
            if (passengerChoice == 'Y' || passengerChoice == 'y') 
            {
                railwayLine = 1;  // Switch to LRT-1
                initialStation = 11;  // Start at D. Jose in LRT-1
                printf("You are now riding LRT-1. Current station: D. Jose\n");
                // Print LRT-1 stations after transferring
                printf("\nChoose your station:\n");
                for (int i = 0; i < 20; i++) 
                {
                    printf("%d. %s\n", i + 1, LRT1Stations[i]);
                }
                continue;
            }
        } 
        else if (railwayLine == 1 && endStation == 2) 
        {  // EDSA (LRT1 -> MRT3)
            printf("You have arrived at EDSA, which intersects with MRT-3.\nWould you like to transfer to MRT-3? (Y/N): ");
            scanf(" %c", &passengerChoice);
            if (passengerChoice == 'Y' || passengerChoice == 'y') 
            {
                railwayLine = 3;  // Switch to MRT-3
                initialStation = 12;  // Start at Taft Avenue in MRT-3
                printf("You are now riding MRT-3. Current station: Taft Avenue\n");
                // Print MRT-3 stations after transferring
                printf("\nChoose your station:\n");
                for (int i = 0; i < 13; i++) 
                {
                    printf("%d. %s\n", i + 1, MRT3Stations[i]);
                }
                continue;
            }
        } 
        else if (railwayLine == 2 && endStation == 9) 
        {  // Anonas (LRT2 -> MRT3)
            printf("You have arrived at Anonas, which intersects with MRT-3.\nWould you like to transfer to MRT-3? (Y/N): ");
            scanf(" %c", &passengerChoice);
            if (passengerChoice == 'Y' || passengerChoice == 'y') 
            {
                railwayLine = 3;  // Switch to MRT-3
                initialStation = 4;  // Start at Cubao in MRT-3
                printf("You are now riding MRT-3. Current station: Cubao\n");
                // Print MRT-3 stations after transferring
                printf("\nChoose your station:\n");
                for (int i = 0; i < 13; i++) 
                {
                    printf("%d. %s\n", i + 1, MRT3Stations[i]);
                }
                continue;
            }
        } 
        else if (railwayLine == 3 && endStation == 4) 
        {  // Cubao (MRT3 -> LRT2)
            printf("You have arrived at Cubao, which intersects with LRT-2.\nWould you like to transfer to LRT-2? (Y/N): ");
            scanf(" %c", &passengerChoice);
            if (passengerChoice == 'Y' || passengerChoice == 'y') 
            {
                railwayLine = 2;  // Switch to LRT-2
                initialStation = 9;  // Start at Anonas in LRT-2
                printf("You are now riding LRT-2. Current station: Anonas\n");
                // Print LRT-2 stations after transferring
                printf("\nChoose your station:\n");
                for (int i = 0; i < 13; i++) 
                {
                    printf("%d. %s\n", i + 1, LRT2Stations[i]);
                }
                continue;
            }
        } 
        else if (railwayLine == 3 && endStation == 13) 
        {  // Taft (MRT3 -> LRT1)
            printf("You have arrived at Taft Avenue, which intersects with LRT-1.\nWould you like to transfer to LRT-1? (Y/N): ");
            scanf(" %c", &passengerChoice);
            if (passengerChoice == 'Y' || passengerChoice == 'y') 
            {
                railwayLine = 1;  // Switch to LRT-1
                initialStation = 2;  // Start at EDSA in LRT-1
                printf("You are now riding LRT-1. Current station: EDSA\n");
                // Print LRT-1 stations after transferring
                printf("\nChoose your station:\n");
                for (int i = 0; i < 20; i++) 
                {
                    printf("%d. %s\n", i + 1, LRT1Stations[i]);
                }
                continue;
            }
        }

        // Ask if the user wants to proceed to another station
        printf("Would you like to proceed to another station? (Y/N): ");
        scanf(" %c", &passengerChoice);

        // Set the current station for the next trip
        if (passengerChoice == 'Y' || passengerChoice == 'y') 
        {
            initialStation = endStation;  // The current station is now the previous destination

            // Print stations based on the current line
            printf("\nChoose your station:\n");

            if (railwayLine == 1) 
            {
                for (int i = 0; i < 20; i++) 
                {
                    printf("%d. %s\n", i + 1, LRT1Stations[i]);
                }
            } 
            else if (railwayLine == 2) 
            {
                for (int i = 0; i < 13; i++) 
                {
                    printf("%d. %s\n", i + 1, LRT2Stations[i]);
                }
            } 
            else if (railwayLine == 3) 
            {
                for (int i = 0; i < 13; i++) 
                {
                    printf("%d. %s\n", i + 1, MRT3Stations[i]);
                }
            }

            // Display the current station
            printf("\nCurrent station: %s\n", railwayLine == 1 ? LRT1Stations[initialStation - 1] : 
                                                 railwayLine == 2 ? LRT2Stations[initialStation - 1] : 
                                                                    MRT3Stations[initialStation - 1]);
        }

    } while (passengerChoice == 'Y' || passengerChoice == 'y');

    // End the trip and display total fare
    printf("----------------------------------------\n");
    printf("Your total fare for the entire trip is: PHP %.2f\n", overallFare);
    printf("Thank you for using the Fare Matrix Calculator!\n");

    return 0;
}