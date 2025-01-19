#include <stdio.h>

int main() 
{
    char LRT2Stations[13][10] = {"Recto", "Legarda", "Pureza", "V. Mapa", "J. Ruiz", "Gilmore", "Betty Go", "Cubao", "Anonas", "Katipunan", "Santolan", "Marikina", "Antipolo"};

    int LRT2Fares_beep[13][13] = {{0, 15, 16, 18, 19, 21, 22, 23, 25, 26, 28, 31, 33}, {15, 0, 15, 17, 18, 19, 21, 22, 24, 25, 27, 29, 32}, {16, 15, 0, 15, 16, 18, 19, 20, 22, 23, 26, 28, 30}, {18, 17, 15, 0, 15, 16, 17, 19, 20, 22, 24, 26, 29}, {19, 18, 16, 15, 0, 14, 16, 17, 19, 20, 22, 24, 27}, {21, 19, 18, 16, 14, 0, 15, 16, 18, 19, 21, 23, 26}, {22, 21, 19, 17, 16, 15, 10, 15, 16, 18, 20, 22, 25}, {23, 22, 20, 19, 17, 16, 15, 0, 15, 16, 19, 21, 23}, {25, 24, 22, 20, 19, 18, 16, 15, 0, 14, 17, 19, 22}, {26, 25, 23, 22, 20, 19, 18, 16, 14, 0, 16, 18, 21}, {28, 27, 26, 24, 22, 21, 20, 19, 17, 16, 0, 15, 18}, {31, 29, 28, 26, 24, 23, 22, 21, 19, 18, 15, 0, 16}, {33, 32, 30, 29, 27, 26, 25, 23, 22, 21, 18, 16, 0}};

    int LRT2Fares_single_journey[13][13] = {{0, 15, 20, 20, 20, 25, 25, 25, 25, 30, 30, 35, 35}, {15, 0, 15, 20, 20, 20, 25, 25, 25, 25, 30, 30, 35}, {20, 15, 0, 15, 20, 20, 20, 20, 25, 25, 30, 30, 30}, {20, 20, 15, 0, 15, 20, 20, 20, 20, 25, 25, 30}, {20, 20, 20, 15, 0, 15, 20, 20, 20, 20, 25, 25, 30}, {25, 20, 20, 20, 15, 0, 15, 20, 20, 20, 25, 25, 30}, {25, 25, 20, 20, 20, 15, 0, 15, 20, 20, 20, 25, 25}, {25, 25, 20, 20, 20, 20, 15, 0, 15, 20, 20, 25, 25}, {25, 25, 25, 20, 20, 20, 20, 15, 0, 15, 20, 20, 25}, {30, 25, 25, 25, 20, 20, 20, 20, 15, 0, 20, 20, 25}, {30, 30, 30, 25, 25, 25, 20, 20, 20, 20, 0, 15, 20}, {35, 30, 30, 30, 25, 25, 25, 25, 20, 20, 15, 0, 20}, {35, 35, 30, 30, 30, 30, 25, 25, 25, 25, 20, 20, 0}};

    printf("          Welcome to LRT 2\n----------------------------------------");
    
    int cardType;
    float overallFare = 0.0; 
    
    printf("\nCard Types:\n1. Stored Value (Beep) Fare Card\n2. Single Journey Fare Card\n");
    
    do 
    {
        printf("\nEnter your card: ");
        scanf("%d", &cardType);

        if (cardType == 1)
        {
            printf("Your card is: Stored Value (Beep) Fare Card\n");
        }
        else if (cardType == 2)
        {
            printf("Your card is: Single Journey Fare Card\n");
        }
        else
        {
            printf("Invalid. Please enter a valid card type number.\n");
        }
    } while (cardType != 1 && cardType != 2);
    
    printf("----------------------------------------\n");
    
    int passengerStatus;
    float passengerDiscount = 1.00;
    
    printf("Select one that applies:\n1. PWD\n2. Senior Citizen\n3. Student\n4. Regular Passenger\n");
    
    do 
    {
        printf("\nEnter your status: ");
        scanf("%d", &passengerStatus);

        if (passengerStatus == 1 || passengerStatus == 2 || passengerStatus == 3)
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
    } while (passengerStatus < 1 || passengerStatus > 4);
    
    printf("----------------------------------------\n");
    
    int initialStation = 0, endStation;
    float currentFare;
    char passengerChoice;
    
    printf("Choose from the following LRT 2 stations:\n");
    printf("1. Recto     5. J. Ruiz    8. Cubao       11. Santolan\n2. Legarda   6. Gilmore    9. Anonas      12. Marikina\n3. Pureza    7. Betty Go   10. Katipunan  13. Antipolo\n4. V. Mapa");
    
    do
    {
        printf("\nEnter your initial station (1-13): ");
        scanf("%d", &initialStation);
        
        if (initialStation < 1 || initialStation > 13)
        {
            printf("Invalid initial station. Please input a valid station number.\n");
        }
    } while (initialStation < 1 || initialStation > 13);

    do
    {
        do
        {
            printf("\nEnter your destination (1-13): ");
            scanf("%d", &endStation);
            
            if (endStation < 1 || endStation > 13)
            {
                printf("Invalid destination. Please input a valid station number.\n");
            }

        } while (endStation < 1 || endStation > 13);

        if (initialStation == endStation)
        {
            printf("\nYou're already at your destination.\n");
        }
        
        if (initialStation != endStation) 
        {
            if (cardType == 1)
            {
                currentFare = LRT2Fares_beep[initialStation - 1][endStation - 1] * passengerDiscount;
            }
            else if (cardType == 2)
            {
                currentFare = LRT2Fares_single_journey[initialStation - 1][endStation - 1] * passengerDiscount;
            }

            overallFare = overallFare + currentFare;

            printf("\nYour fare from %s to %s is: PHP %.2f", LRT2Stations[initialStation - 1], LRT2Stations[endStation - 1], currentFare);
            printf("\nCurrent Overall Fare: PHP %.2f\n", overallFare);
        }
        
        if (endStation == 1)  
        {
            char transferChoice;
            printf("\nCurrent Station: Recto");
            printf("\nDo you want to transfer to LRT 1?\nY if YES\nN if NO\nYour choice: ");
            scanf(" %c", &transferChoice);
            
            if (transferChoice == 'Y' || transferChoice == 'y')
            {
                printf("----------------------------------------\n");
                printf("You're now in LRT 1!\n");
                return 0;
            }
        }
        else if (endStation == 9)  
        {
            char transferChoice;
            printf("\nCurrent Station: Anonas");
            printf("\nDo you want to transfer to MRT 3?\nY if YES\nN if NO\nYour choice: ");
            scanf(" %c", &transferChoice);
    
            if (transferChoice == 'Y' || transferChoice == 'y')
            {
                printf("----------------------------------------\n");
                printf("You're now in MRT 3!\n");
                return 0;
            }
        }

        initialStation = endStation; 

        printf("\nWould you like to proceed to another station?\nY for YES\nN for NO\n");

        do 
        {
            printf("Your choice: ");
            scanf(" %c", &passengerChoice);

            if (passengerChoice != 'Y' && passengerChoice != 'y' && passengerChoice != 'N' && passengerChoice != 'n') 
            {
                printf("Invalid choice. Please enter 'Y' for YES or 'N' for NO.\n\n");
            }
        } while (passengerChoice != 'Y' && passengerChoice != 'y' && passengerChoice != 'N' && passengerChoice != 'n');

        if (passengerChoice == 'Y' || passengerChoice == 'y')
        {
            printf("----------------------------------------\n");
            printf("Choose from the following LRT 2 stations:\n");
            printf("1. Recto     5. J. Ruiz    8. Cubao       11. Santolan\n2. Legarda   6. Gilmore    9. Anonas      12. Marikina\n3. Pureza    7. Betty Go   10. Katipunan  13. Antipolo\n4. V. Mapa");
            printf("\n\nYour current station is: %s\n", LRT2Stations[initialStation - 1]); 
        }

    } while (passengerChoice == 'Y' || passengerChoice == 'y');

    printf("----------------------------------------\n");

    printf("Your total fare for the entire trip is: PHP %.2f\nThank you for using LRT 2 Fare Matrix Calculator!\nHave a safe ride!\n", overallFare);

    return 0;
}