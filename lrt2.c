#include <stdio.h>

int main() 
{
    char LRT2Stations[13][10] = {"Recto", "Legarda", "Pureza", "V. Mapa", "J. Ruiz", "Gilmore", "Betty Go", "Cubao", "Anonas", "Katipunan", "Santolan", "Marikina", "Antipolo"};

    int LRT2Fares_beep[13][13] = {{0, 15, 16, 18, 19, 21, 22, 23, 25, 26, 28, 31, 33}, {15, 0, 15, 17, 18, 19, 21, 22, 24, 25, 27, 29, 32}, {16, 15, 0, 15, 16, 18, 19, 20, 22, 23, 26, 28, 30}, {18, 17, 15, 0, 15, 16, 17, 19, 20, 22, 24, 26, 29}, {19, 18, 16, 15, 0, 14, 16, 17, 19, 20, 22, 24, 27}, {21, 19, 18, 16, 14, 0, 15, 16, 18, 19, 21, 23, 26}, {22, 21, 19, 17, 16, 15, 10, 15, 16, 18, 20, 22, 25}, {23, 22, 20, 19, 17, 16, 15, 0, 15, 16, 19, 21, 23}, {25, 24, 22, 20, 19, 18, 16, 15, 0, 14, 17, 19, 22}, {26, 25, 23, 22, 20, 19, 18, 16, 14, 0, 16, 18, 21}, {28, 27, 26, 24, 22, 21, 20, 19, 17, 16, 0, 15, 18}, {31, 29, 28, 26, 24, 23, 22, 21, 19, 18, 15, 0, 16}, {33, 32, 30, 29, 27, 26, 25, 23, 22, 21, 18, 16, 0}};

    int LRT2Fares_single_journey[13][13] = {{0, 15, 20, 20, 20, 25, 25, 25, 25, 30, 30, 35, 35}, {15, 0, 15, 20, 20, 20, 25, 25, 25, 25, 30, 30, 35}, {20, 15, 0, 15, 20, 20, 20, 20, 25, 25, 30, 30, 30}, {20, 20, 15, 0, 15, 20, 20, 20, 20, 25, 25, 30}, {20, 20, 20, 15, 0, 15, 20, 20, 20, 20, 25, 25, 30}, {25, 20, 20, 20, 15, 0, 15, 20, 20, 20, 25, 25, 30}, {25, 25, 20, 20, 20, 15, 0, 15, 20, 20, 20, 25, 25}, {25, 25, 20, 20, 20, 20, 15, 0, 15, 20, 20, 25, 25}, {25, 25, 25, 20, 20, 20, 20, 15, 0, 15, 20, 20, 25}, {30, 25, 25, 25, 20, 20, 20, 20, 15, 0, 20, 20, 25}, {30, 30, 30, 25, 25, 25, 20, 20, 20, 20, 0, 15, 20}, {35, 30, 30, 30, 25, 25, 25, 25, 20, 20, 15, 0, 20}, {35, 35, 30, 30, 30, 30, 25, 25, 25, 25, 20, 20, 0}};

    printf("WELCOME TO LRT 2\n----------------------------------------\n");

    int cardType;
    float overallFare = 0;
    char input[10];

    printf("Card Types\n1. Stored Value (Beep) Fare Card\n2. Single Journey Fare Card\n\n");

    do 
    {
        printf("Enter your card: ");
        if (scanf("%s", input) != 1 || sscanf(input, "%d", &cardType) != 1 || (cardType != 1 && cardType != 2))
        {
            printf("Invalid. Please enter a valid card type number.\n\n");
        }
        else
        {
            if (cardType == 1)
            {
                printf("Your card is: Stored Value (Beep) Fare Card\n");
            }
            else if (cardType == 2)
            {
                printf("Your card is: Single Journey Fare Card\n");
            }
        }
    } while (cardType != 1 && cardType != 2);

    printf("----------------------------------------\n");

    int status;
    float discount = 1.00;

    printf("Please choose your status:\n1. Senior Citizen\n2. Person with Disabilities (PWD)\n3. Student\n4. Regular Passenger\n\n");

    do
    {
        printf("Enter your choice: ");
        if (scanf("%s", input) != 1 || sscanf(input, "%d", &status) != 1 || (status < 1 || status > 4))
        {
            printf("Invalid choice. Please enter a valid status number.\n\n");
        }
        else
        {
            if (status == 1 || status == 2 || status == 3)
            {
                discount = 0.80;
                printf("You are eligible for a 20%% discount.\n");
            }
            else if (status == 4)
            {
                printf("No discount will be applied.\n");
            }
        }

    } while (status < 1 || status > 4);

    printf("----------------------------------------\n");

    int initialStation = 0, endStation;
    float currentFare;
    char passengerChoice;

    printf("Choose from the following LRT 2 stations:\n");
    printf("1. Recto     6. Gilmore    10. Katipunan\n2. Legarda   7. Betty Go   11. Santolan\n3. Pureza    8. Cubao      12. Marikina\n4. V. Mapa   9. Anonas     13. Antipolo\n5. J. Ruiz\n");

    do
    {
        while (initialStation < 1 || initialStation > 13) 
        {
            printf("\nEnter your initial station (1-13): ");
            scanf("%s", input);

            if (sscanf(input, "%d", &initialStation) != 1 || initialStation < 1 || initialStation > 13) 
            {
                printf("Invalid initial station. Please enter a valid station number.\n");
                initialStation = 0; 
        }

        do
        {
            printf("\nEnter your destination (1-13): ");
            scanf("%s", input);

            if (sscanf(input, "%d", &endStation) != 1 || endStation < 1 || endStation > 13)
            {
                printf("Invalid destination. Please enter a valid station number.\n");
                endStation = 0; 
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
                currentFare = LRT2Fares_beep[initialStation - 1][endStation - 1] * discount;
            }
            else if (cardType == 2)
            {
                currentFare = LRT2Fares_single_journey[initialStation - 1][endStation - 1] * discount;
            }

            overallFare = overallFare + currentFare;

            printf("\nYour fare from %s to %s is: PHP %.2f", LRT2Stations[initialStation - 1], LRT2Stations[endStation - 1], currentFare);
            printf("\nCurrent Overall Fare: PHP %.2f\n", overallFare);
        }

        initialStation = endStation; 

        printf("\nWould you like to proceed to another?\nY for YES\nN for NO\n\n");

        do {
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
            printf("Choose your next destination:\n1. Recto     6. Gilmore    10. Katipunan\n2. Legarda   7. Betty Go   11. Santolan\n3. Pureza    8. Cubao      12. Marikina\n4. V. Mapa   9. Anonas     13. Antipolo\n5. J. Ruiz\n");
            printf("Your current station is: %s\n", LRT2Stations[initialStation - 1]); 
        }

    } while (passengerChoice == 'Y' || passengerChoice == 'y');

    printf("----------------------------------------\n");

    printf("Your total fare for the entire trip is: PHP %.2f\nThank you for using LRT 2 Fare Matrix Calculator!\nHave a safe ride!\n", overallFare);

    return 0;
}