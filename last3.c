#include <stdio.h>

char LRT1Stations[][20] = {
    "Baclaran", "EDSA", "Libertad", "Gil Puyat", "Vito Cruz", "Quirino", "Pedro Gil", 
    "UN Avenue", "Central", "Carriedo", "D. Jose", "Bambang", "Tayuman", "Blumentritt", 
    "Abad Santos", "R. Papa", "5th Avenue", "Monumento", "Balintawak", "Fernando Poe Jr."
};

char LRT2Stations[][20] = {
    "Recto", "Legarda", "Pureza", "V. Mapa", "J. Ruiz", "Gilmore", "Betty Go", 
    "Cubao", "Anonas", "Katipunan", "Santolan", "Marikina", "Antipolo"
};

char MRT3Stations[][20] = {
    "North Avenue", "Quezon Avenue", "Kamuning", "Cubao", "Santolan", "Ortigas", 
    "Shaw", "Boni", "Guadalupe", "Buendia", "Ayala", "Magallanes", "Taft Avenue"
};

int LRT1Fares_beep[20][20] = { /* Fill with LRT1 fare values */ };
int LRT1Fares_single_journey[20][20] = { /* Fill with LRT1 fare values */ };

int LRT2Fares_beep[13][13] = { /* Fill with LRT2 fare values */ };
int LRT2Fares_single_journey[13][13] = { /* Fill with LRT2 fare values */ };

int MRT3Fares_beep[13][13] = { /* Fill with MRT3 fare values */ };
int MRT3Fares_single_journey[13][13] = { /* Fill with MRT3 fare values */ };

int main() 
{
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
    // Prompt for card type
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
    // Ask for passenger status to determine discount
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
    // First trip: Print the relevant stations and ask for the initial station

    // Print stations based on the initial railway line
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
            } 
            else 
            {
                currentFare = MRT3Fares_single_journey[initialStation - 1][endStation - 1] * passengerDiscount;
            }
        }

        // Get station names for fare message
        char initialStationName[20];
        char endStationName[20];

        // Direct assignment using array indexing without pointers
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

        // Handle transfers at intersection stations
        if (railwayLine == 1 && endStation == 11) // D. Jose (LRT1 -> LRT2)
        {  
            printf("\nYou have arrived at D. Jose, which intersects with LRT-2.\nWould you like to transfer to LRT-2?\nY if YES\nN if NO\n");
            printf("Your choice: ");
            scanf(" %c", &passengerChoice);

            if (passengerChoice == 'Y' || passengerChoice == 'y') 
            {
                railwayLine = 2;  // Switch to LRT-2
                initialStation = 1;  // Reset to Recto in LRT-2
                printf("----------------------------------------------------\n");
                printf("You are now riding LRT-2.\nCurrent station: Recto\n");
                // Print LRT-2 stations after transferring
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
        else if (railwayLine == 2 && endStation == 1) // Recto (LRT2 -> LRT1)
        {  
            printf("\nYou have arrived at Recto, which intersects with LRT-1.\nWould you like to transfer to LRT-1?\nY if YES\nN if NO\n");
            printf("Your choice: ");
            scanf(" %c", &passengerChoice);

            if (passengerChoice == 'Y' || passengerChoice == 'y') 
            {
                railwayLine = 1;  // Switch to LRT-1
                initialStation = 11;  // Start at D. Jose in LRT-1
                printf("----------------------------------------------------\n");
                printf("You are now riding LRT-1.\nCurrent station: D. Jose\n");
                // Print LRT-1 stations after transferring
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
        else if (railwayLine == 1 && endStation == 2) // EDSA (LRT1 -> MRT3)
        {  
            printf("\nYou have arrived at EDSA, which intersects with MRT-3.\nWould you like to transfer to MRT-3?\nY if YES\nN if NO\n");
            printf("Your choice: ");
            scanf(" %c", &passengerChoice);

            if (passengerChoice == 'Y' || passengerChoice == 'y') 
            {
                railwayLine = 3;  // Switch to MRT-3
                initialStation = 12;  // Start at Taft Avenue in MRT-3
                printf("----------------------------------------------------\n");
                printf("You are now riding MRT-3.\nCurrent station: Taft Avenue\n");
                // Print MRT-3 stations after transferring
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
        else if (railwayLine == 2 && endStation == 9) // Anonas (LRT2 -> MRT3)
        {  
            printf("\nYou have arrived at Anonas, which intersects with MRT-3.\nWould you like to transfer to MRT-3?\nY if YES\nN if NO\n");
            printf("Your choice: ");
            scanf(" %c", &passengerChoice);
            
            if (passengerChoice == 'Y' || passengerChoice == 'y') 
            {
                railwayLine = 3;  // Switch to MRT-3
                initialStation = 4;  // Start at Cubao in MRT-3
                printf("----------------------------------------------------\n");
                printf("You are now riding MRT-3.\nCurrent station: Cubao\n");
                // Print MRT-3 stations after transferring
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
        else if (railwayLine == 3 && endStation == 4) // Cubao (MRT3 -> LRT2)
        {  
            printf("\nYou have arrived at Cubao, which intersects with LRT-2.\nWould you like to transfer to LRT-2?\nY if YES\nN if NO\n");
            printf("Your choice: ");
            scanf(" %c", &passengerChoice);

            if (passengerChoice == 'Y' || passengerChoice == 'y') 
            {
                railwayLine = 2;  // Switch to LRT-2
                initialStation = 9;  // Start at Anonas in LRT-2
                printf("----------------------------------------------------\n");
                printf("You are now riding LRT-2.\nCurrent station: Anonas\n");
                // Print LRT-2 stations after transferring
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
        else if (railwayLine == 3 && endStation == 13) // Taft (MRT3 -> LRT1)
        {  
            printf("\nYou have arrived at Taft Avenue, which intersects with LRT-1.\nWould you like to transfer to LRT-1?\nY if YES\nN if NO\n");
            printf("Your choice: ");
            scanf(" %c", &passengerChoice);

            if (passengerChoice == 'Y' || passengerChoice == 'y') 
            {
                railwayLine = 1;  // Switch to LRT-1
                initialStation = 2;  // Start at EDSA in LRT-1
                printf("----------------------------------------------------\n");
                printf("You are now riding LRT-1.\nCurrent station: EDSA\n");
                // Print LRT-1 stations after transferring
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

        // Ask if the user wants to proceed to another station
        printf("\nWould you like to proceed to another station?\nY if YES\nN if NO");
        printf("\nYour choice: ");
        scanf(" %c", &passengerChoice);

        // Set the current station for the next trip
        if (passengerChoice == 'Y' || passengerChoice == 'y') 
        {
            initialStation = endStation;  // The current station is now the previous destination
        }

    } while (passengerChoice == 'Y' || passengerChoice == 'y');

    // End the trip and display total fare
    printf("----------------------------------------------------\n");
    printf("Your total fare for the entire trip is: PHP %.2f\n", overallFare);
    printf("Thank you for using Railway Lines Fare Matrix Calculator!\n");

    return 0;
}