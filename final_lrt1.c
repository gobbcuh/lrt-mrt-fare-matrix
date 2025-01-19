#include <stdio.h>

int main()
{
    char LRT1Stations[20][20] = {"Baclaran", "Edsa", "Libertad", "Gil Puyat", "Vito Cruz", "Quirino", "Pedro Gil", "UN Avenue", "Central", "Carriedo", "D. Jose", "Bambang", "Tayuman", "Blumentritt", "Abad Santos", "R. Papa", "5th Avenue", "Monumento", "Balintawak", "Fernando Poe Jr."};
    
    int LRT1Fares_beep[20][20] = {{0, 14, 15, 16, 17, 18, 19, 20, 22, 23, 23, 24, 25, 26, 27, 28, 29, 30, 33, 35}, {14, 0, 15, 15, 17, 18, 19, 20, 21, 22, 23, 24, 24, 25, 26, 27, 28, 29, 32, 34}, {15, 15, 0, 14, 15, 16, 17, 18, 20, 21, 22, 22, 23, 24, 25, 26, 27, 28, 31, 33}, {16, 15, 14, 0, 15, 16, 17, 17, 19, 20, 21, 21, 22, 23, 24, 25, 26, 27, 30, 32}, {17, 17, 15, 15, 0, 14, 15, 16, 18, 19, 19, 20, 21, 22, 23, 24, 25, 26, 29, 31}, {18, 18, 16, 16, 14, 0, 14, 15, 17, 18, 18, 19, 20, 21, 22, 23, 24, 25, 28, 30}, {19, 19, 17, 17, 15, 14, 0, 14, 16, 17, 17, 18, 19, 20, 21, 22, 23, 24, 27, 29}, {20, 20, 18, 17, 16, 15, 14, 0, 15, 16, 16, 17, 18, 19, 20, 21, 22, 23, 26, 28}, {22, 21, 20, 19, 18, 17, 16, 15, 0, 14, 15, 16, 17, 17, 18, 19, 20, 22, 24, 27}, {23, 22, 21, 20, 19, 18, 17, 16, 14, 0, 14, 15, 16, 16, 18, 18, 20, 21, 24, 26}, {23, 23, 22, 21, 19, 18, 17, 16, 15, 14, 0, 14, 15, 16, 17, 18, 19, 20, 23, 25}, {24, 24, 22, 21, 20, 19, 18, 17, 16, 15, 14, 0, 14, 15, 16, 17, 18, 19, 22, 24}, {25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 0, 14, 15, 16, 17, 18, 21, 23}, {26, 25, 24, 23, 22, 21, 20, 19, 17, 16, 16, 15, 14, 0, 14, 15, 16, 18, 20, 23}, {27, 26, 25, 24, 23, 22, 21, 20, 18, 18, 17, 16, 15, 14, 0, 14, 15, 17, 19, 22}, {28, 27, 26, 25, 24, 23, 22, 21, 19, 18, 18, 17, 16, 15, 14, 0, 14, 16, 18, 21}, {29, 28, 27, 26, 25, 24, 23, 22, 20, 20, 19, 18, 17, 16, 15, 14, 0, 15, 17, 20}, {30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 18, 17, 16, 15, 0, 16, 18}, {33, 32, 31, 30, 29, 28, 27, 26, 24, 24, 23, 22, 21, 20, 19, 18, 17, 16, 0, 16}, {35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 23, 22, 21, 20, 18, 16, 0}};

    int LRT1Fares_single_journey [20][20] = {{0, 15, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30, 30, 30, 30, 35, 35}, {15, 0, 15, 15, 20, 20, 20, 20, 25, 25, 25, 25, 25, 25, 30, 30, 30, 30, 35, 35}, {15, 15, 0, 15, 15, 20, 20, 20, 20, 25, 25, 25, 25, 25, 25, 30, 30, 30, 35, 35}, {20, 15, 15, 0, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 25, 30, 30, 30, 35}, {20, 20, 15, 15, 0, 15, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30, 35}, {20, 20, 20, 20, 15, 0, 15, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30}, {20, 20, 20, 20, 15, 15, 0, 15, 20, 20, 20, 20, 20, 20, 25, 25, 25, 25, 30, 30}, {20, 20, 20, 20, 20, 15, 15, 0, 15, 20, 20, 20, 20, 20, 20, 25, 25, 25, 30, 30}, {25, 25, 20, 20, 20, 20, 20, 15, 0, 15, 15, 20, 20, 20, 20, 20, 20, 25, 25, 30}, {25, 25, 25, 20, 20, 20, 20, 20, 15, 0, 15, 15, 20, 20, 20, 20, 20, 25, 25, 30}, {25, 25, 25, 25, 20, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 20, 20, 20, 25, 25}, {25,25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 20, 20, 25, 25}, {25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 20, 25, 25}, {30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 20, 25}, {30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 25}, {30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 0, 15, 20, 20, 25}, {30, 30, 30, 30, 25, 25, 25, 25, 20, 20, 20, 20, 20, 20, 15, 15, 0, 15, 20, 20}, {30, 30, 30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 20, 15, 0, 20, 20}, {35, 35, 35, 30, 30, 30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 0, 20}, {35, 35, 35, 35, 35, 30, 30, 30, 30, 30, 25, 25, 25, 25, 25, 25, 20, 20, 20, 0}};
    
    printf("          Welcome to LRT 1\n----------------------------------------");
    
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
    } while (passengerStatus < 1 || passengerStatus > 4);
    
    printf("----------------------------------------\n");
    
    int initialStation = 0, endStation;
    float currentFare;
    char passengerChoice;
    
    printf("Choose from the following LRT 1 stations:\n");
    printf("1. Baclaran    6. Quirino     11. D. Jose       16. R. Papa\n2. EDSA        7. Pedro Gil   12. Bambang       17. 5th Avenue\n3. Libertad    8. UN Avenue   13. Tayuman       18. Monumento\n4. Gil Puyat   9. Central     14. Blumentritt   19. Balintawak\n5. Vito Cruz   10. Carriedo   15. Abad Santos   20. Fernando Poe Jr.\n");
    
    do
    {
        printf("\nEnter your initial station (1-20): ");
        scanf("%d", &initialStation);
        
        if (initialStation < 1 || initialStation > 20)
        {
            printf("Invalid initial station. Please input a valid station number.\n");
        }
    } while (initialStation < 1 || initialStation > 20);

    do
    {
        do
        {
            printf("\nEnter your destination (1-20): ");
            scanf("%d", &endStation);
            
            if (endStation < 1 || endStation > 20)
            {
                printf("Invalid destination. Please input a valid station number.\n");
            }

        } while (endStation < 1 || endStation > 20);

        if (initialStation == endStation)
        {
            printf("\nYou're already at your destination.\n");
        }
        
        if (initialStation != endStation) 
        {
            if (cardType == 1)
            {
                currentFare = LRT1Fares_beep[initialStation - 1][endStation - 1] * passengerDiscount;
            }
            else if (cardType == 2)
            {
                currentFare = LRT1Fares_single_journey[initialStation - 1][endStation - 1] * passengerDiscount;
            }

            overallFare = overallFare + currentFare;

            printf("\nYour fare from %s to %s is: PHP %.2f", LRT1Stations[initialStation - 1], LRT1Stations[endStation - 1], currentFare);
            printf("\nCurrent Overall Fare: PHP %.2f\n", overallFare);
        }
        
        if (endStation == 11)  
        {
            char transferChoice;
            printf("\nCurrent Station: D. Jose");
            printf("\nDo you want to transfer to LRT 2?\nY if YES\nN if NO\nYour choice: ");
            scanf(" %c", &transferChoice);
            
            if (transferChoice == 'Y' || transferChoice == 'y')
            {
                printf("----------------------------------------\n");
                printf("You're now in LRT 2!\n");
                return 0;
            }
        }
        else if (endStation == 2)  
        {
            char transferChoice;
            printf("\nCurrent Station: EDSA");
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

        printf("\nWould you like to proceed to another station?\nY if YES\nN if NO\n");

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
            printf("Choose from the following LRT 1 stations:\n");
            printf("1. Baclaran    6. Quirino     11. D. Jose       16. R. Papa\n2. EDSA        7. Pedro Gil   12. Bambang       17. 5th Avenue\n3. Libertad    8. UN Avenue   13. Tayuman       18. Monumento\n4. Gil Puyat   9. Central     14. Blumentritt   19. Balintawak\n5. Vito Cruz   10. Carriedo   15. Abad Santos   20. Fernando Poe Jr.");
            printf("\n\nYour current station is: %s\n", LRT1Stations[initialStation - 1]); 
        }

    } while (passengerChoice == 'Y' || passengerChoice == 'y');

    printf("----------------------------------------\n");

    printf("Your total fare for the entire trip is: PHP %.2f\nThank you for using LRT 1 Fare Matrix Calculator!\nHave a safe ride!\n", overallFare);

    return 0;
}