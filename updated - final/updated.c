#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <errno.h>

// LRT-MRT fare matrices
const char LRT1Stations[25][25] = {"Dr. Santos", "Ninoy Aquino Avenue", "PITX", "Mia Road", "Redemptionist-Aseana", "Baclaran", "EDSA", "Libertad", "Gil Puyat", "Vito Cruz", "Quirino", "Pedro Gil", "UN Avenue", "Central", "Carriedo", "D. Jose", "Bambang", "Tayuman", "Blumentritt", "Abad Santos", "R. Papa", "5th Avenue", "Monumento", "Balintawak", "Fernando Poe Jr."};

const int LRT1Fares_beep[25][25] = {
    {0, 19, 20, 22, 23, 26, 27, 28, 29, 31, 32, 33, 34, 36, 37, 38, 39, 40, 41, 42, 43, 45, 46, 49, 52},
    {19, 0, 18, 20, 21, 23, 24, 26, 27, 28, 29, 31, 32, 33, 35, 36, 36, 37, 38, 40, 41, 42, 44, 47, 50},
    {20, 18, 0, 18, 19, 22, 22, 24, 25, 27, 28, 29, 30, 32, 33, 34, 35, 36, 37, 38, 39, 40, 42, 45, 48},
    {22, 20, 18, 0, 17, 20, 20, 22, 23, 25, 26, 27, 28, 30, 31, 32, 33, 34, 35, 36, 37, 38, 40, 43, 46},
    {23, 21, 19, 17, 0, 18, 19, 21, 22, 23, 25, 26, 27, 29, 30, 31, 32, 33, 34, 35, 36, 37, 39, 42, 45},
    {26, 23, 22, 20, 18, 0, 17, 19, 20, 21, 22, 24, 25, 27, 28, 29, 30, 30, 31, 33, 34, 35, 37, 40, 43},
    {27, 24, 22, 20, 19, 17, 0, 18, 19, 20, 22, 23, 24, 26, 27, 28, 29, 30, 31, 32, 33, 34, 36, 39, 42},
    {28, 26, 24, 22, 21, 19, 18, 0, 17, 19, 20, 21, 22, 24, 25, 26, 27, 28, 29, 30, 31, 33, 34, 38, 40},
    {29, 27, 25, 23, 22, 20, 19, 17, 0, 18, 19, 20, 21, 23, 24, 25, 26, 27, 28, 29, 30, 32, 33, 37, 39},
    {31, 28, 27, 25, 23, 21, 20, 19, 18, 0, 17, 19, 20, 22, 23, 24, 25, 25, 26, 28, 29, 30, 32, 35, 38},
    {32, 29, 28, 26, 25, 22, 22, 20, 19, 17, 0, 17, 19, 20, 21, 22, 23, 24, 25, 27, 28, 29, 31, 34, 37},
    {33, 31, 29, 27, 26, 24, 23, 21, 20, 19, 17, 0, 17, 19, 20, 21, 22, 23, 24, 25, 26, 28, 29, 33, 35},
    {34, 32, 30, 28, 27, 25, 24, 22, 21, 20, 19, 17, 0, 18, 19, 20, 21, 22, 23, 24, 25, 27, 28, 32, 34},
    {36, 33, 32, 30, 29, 27, 26, 24, 23, 22, 20, 19, 18, 0, 17, 18, 19, 20, 21, 23, 23, 25, 27, 30, 33},
    {37, 35, 33, 31, 30, 28, 27, 25, 24, 23, 21, 20, 19, 17, 0, 17, 18, 19, 20, 21, 22, 24, 25, 29, 31},
    {38, 36, 34, 32, 31, 29, 28, 26, 25, 24, 22, 21, 20, 18, 17, 0, 17, 18, 19, 20, 21, 23, 24, 28, 30},
    {39, 36, 35, 33, 32, 30, 29, 27, 26, 25, 23, 22, 21, 19, 18, 17, 0, 17, 18, 20, 20, 22, 23, 27, 30},
    {40, 37, 36, 34, 33, 30, 30, 28, 27, 25, 24, 23, 22, 20, 19, 18, 17, 0, 17, 19, 20, 21, 23, 26, 29},
    {41, 38, 37, 35, 34, 31, 31, 29, 28, 26, 25, 24, 23, 21, 20, 19, 18, 17, 0, 18, 19, 20, 22, 25, 28},
    {42, 40, 38, 36, 35, 33, 32, 30, 29, 28, 27, 25, 24, 23, 21, 20, 20, 19, 18, 0, 17, 19, 20, 24, 26},
    {43, 41, 39, 37, 36, 34, 33, 31, 30, 29, 28, 26, 25, 23, 22, 21, 20, 20, 19, 17, 0, 18, 19, 23, 25},
    {45, 42, 40, 38, 37, 35, 34, 33, 32, 30, 29, 28, 27, 25, 24, 23, 22, 21, 20, 19, 18, 0, 18, 21, 24},
    {46, 44, 42, 40, 39, 37, 36, 34, 33, 32, 31, 29, 28, 27, 25, 25, 23, 23, 22, 20, 19, 18, 0, 20, 22},
    {49, 47, 45, 43, 42, 40, 39, 38, 37, 35, 34, 33, 32, 30, 29, 28, 27, 26, 25, 24, 23, 21, 20, 0, 19},
    {52, 50, 48, 46, 45, 43, 42, 40, 39, 38, 37, 35, 34, 33, 31, 30, 30, 29, 28, 26, 25, 24, 22, 19, 0}};

const int LRT1Fares_single_journey[25][25] = {
    {0, 20, 20, 25, 25, 30, 30, 30, 30, 35, 35, 35, 35, 40, 40, 40, 40, 40, 45, 45, 45, 45, 50, 50, 55},
    {20, 0, 20, 20, 25, 25, 25, 30, 30, 30, 30, 35, 35, 35, 35, 40, 40, 40, 40, 40, 45, 45, 45, 50, 50},
    {20, 20, 0, 20, 20, 25, 25, 25, 25, 30, 30, 30, 30, 35, 35, 35, 35, 40, 40, 40, 40, 40, 45, 45, 50},
    {25, 20, 20, 0, 20, 20, 20, 25, 25, 25, 30, 30, 30, 30, 35, 35, 35, 35, 35, 40, 40, 40, 40, 45, 50},
    {25, 25, 20, 20, 0, 20, 20, 25, 25, 25, 25, 30, 30, 30, 30, 35, 35, 35, 35, 35, 40, 40, 40, 45, 45},
    {30, 25, 25, 20, 20, 0, 20, 20, 20, 25, 25, 25, 25, 30, 30, 30, 30, 30, 35, 35, 35, 35, 40, 40, 45},
    {30, 25, 25, 20, 20, 20, 0, 20, 20, 20, 25, 25, 25, 30, 30, 30, 30, 30, 35, 35, 35, 35, 40, 40, 45},
    {30, 30, 25, 25, 25, 20, 20, 0, 20, 20, 20, 25, 25, 25, 25, 30, 30, 30, 30, 30, 35, 35, 35, 40, 40},
    {30, 30, 25, 25, 25, 20, 20, 20, 0, 20, 20, 20, 25, 25, 25, 25, 30, 30, 30, 30, 30, 35, 35, 40, 40},
    {35, 30, 30, 25, 25, 25, 20, 20, 20, 0, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30, 30, 30, 35, 35, 40},
    {35, 30, 30, 30, 25, 25, 25, 20, 20, 20, 0, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30, 30, 35, 35, 40},
    {35, 35, 30, 30, 30, 25, 25, 25, 20, 20, 20, 0, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30, 30, 35, 35},
    {35, 35, 30, 30, 30, 25, 25, 25, 25, 20, 20, 20, 0, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30, 35, 35},
    {40, 35, 35, 30, 30, 30, 30, 25, 25, 25, 20, 20, 20, 0, 20, 20, 20, 20, 25, 25, 25, 25, 30, 30, 35},
    {40, 35, 35, 35, 30, 30, 30, 25, 25, 25, 25, 20, 20, 20, 0, 20, 20, 20, 20, 25, 25, 25, 25, 30, 35},
    {40, 40, 35, 35, 35, 30, 30, 30, 25, 25, 25, 25, 20, 20, 20, 0, 20, 20, 20, 20, 25, 25, 25, 30, 30},
    {40, 40, 35, 35, 35, 30, 30, 30, 30, 25, 25, 25, 25, 20, 20, 20, 0, 20, 20, 20, 20, 25, 25, 30, 30},
    {40, 40, 40, 35, 35, 30, 30, 30, 30, 25, 25, 25, 25, 20, 20, 20, 20, 0, 20, 20, 20, 25, 25, 30, 30},
    {45, 40, 40, 35, 35, 35, 35, 30, 30, 30, 25, 25, 25, 25, 20, 20, 20, 20, 0, 20, 20, 20, 25, 25, 30},
    {45, 40, 40, 40, 35, 35, 35, 30, 30, 30, 30, 25, 25, 25, 25, 20, 20, 20, 20, 0, 20, 20, 20, 25, 30},
    {45, 45, 40, 40, 40, 35, 35, 35, 30, 30, 30, 30, 25, 25, 25, 25, 20, 20, 20, 20, 0, 20, 20, 25, 25},
    {45, 45, 40, 40, 40, 35, 35, 35, 35, 30, 30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 0, 20, 25, 25},
    {50, 45, 45, 40, 40, 40, 40, 35, 35, 35, 35, 30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 0, 20, 25},
    {50, 50, 45, 45, 45, 40, 40, 40, 40, 35, 35, 35, 35, 30, 30, 30, 30, 30, 25, 25, 25, 25, 20, 0, 20},
    {55, 50, 50, 50, 45, 45, 45, 40, 40, 40, 40, 35, 35, 35, 35, 30, 30, 30, 30, 30, 25, 25, 25, 20, 0}};

const char LRT2Stations[13][10] = {"Recto", "Legarda", "Pureza", "V. Mapa", "J. Ruiz", "Gilmore", "Betty Go", "Cubao", "Anonas", "Katipunan", "Santolan", "Marikina", "Antipolo"};

const int LRT2Fares_beep[13][13] = {
    {0, 15, 16, 18, 19, 21, 22, 23, 25, 26, 28, 31, 33},
    {15, 0, 15, 17, 18, 19, 21, 22, 24, 25, 27, 29, 32},
    {16, 15, 0, 15, 16, 18, 19, 20, 22, 23, 26, 28, 30},
    {18, 17, 15, 0, 15, 16, 17, 19, 20, 22, 24, 26, 29},
    {19, 18, 16, 15, 0, 14, 16, 17, 19, 20, 22, 24, 27},
    {21, 19, 18, 16, 14, 0, 15, 16, 18, 19, 21, 23, 26},
    {22, 21, 19, 17, 16, 15, 0, 15, 16, 18, 20, 22, 25},
    {23, 22, 20, 19, 17, 16, 15, 0, 15, 16, 19, 21, 23},
    {25, 24, 22, 20, 19, 18, 16, 15, 0, 14, 17, 19, 22},
    {26, 25, 23, 22, 20, 19, 18, 16, 14, 0, 16, 18, 21},
    {28, 27, 26, 24, 22, 21, 20, 19, 17, 16, 0, 15, 18},
    {31, 29, 28, 26, 24, 23, 22, 21, 19, 18, 15, 0, 16},
    {33, 32, 30, 29, 27, 26, 25, 23, 22, 21, 18, 16, 0}};

const int LRT2Fares_single_journey[13][13] = {
    {0, 15, 20, 20, 20, 25, 25, 25, 25, 30, 30, 35, 35},
    {15, 0, 15, 20, 20, 20, 25, 25, 25, 25, 30, 30, 35},
    {20, 15, 0, 15, 20, 20, 20, 20, 25, 25, 30, 30, 30},
    {20, 20, 15, 0, 15, 20, 20, 20, 20, 25, 25, 30, 30},
    {20, 20, 20, 15, 0, 15, 20, 20, 20, 20, 25, 25, 30},
    {25, 20, 20, 20, 15, 0, 15, 20, 20, 20, 25, 25, 30},
    {25, 25, 20, 20, 20, 15, 0, 15, 20, 20, 20, 25, 25},
    {25, 25, 20, 20, 20, 20, 15, 0, 15, 20, 20, 25, 25},
    {25, 25, 25, 20, 20, 20, 20, 15, 0, 15, 20, 20, 25},
    {30, 25, 25, 25, 20, 20, 20, 20, 15, 0, 20, 20, 25},
    {30, 30, 30, 25, 25, 25, 20, 20, 20, 20, 0, 15, 20},
    {35, 30, 30, 30, 25, 25, 25, 25, 20, 20, 15, 0, 20},
    {35, 35, 30, 30, 30, 30, 25, 25, 25, 25, 20, 20, 0}};

const char MRT3Stations[13][20] = {"North Avenue", "Quezon Avenue", "GMA Kamuning", "Araneta", "Santolan-Annapolis", "Ortigas", "Shaw Boulevard", "Boni Avenue", "Guadalupe", "Buendia", "Ayala", "Magallanes", "Taft Avenue"};

const int MRT3Fares_discounted[13][13] = {
    {0, 10, 10, 13, 13, 16, 16, 16, 19, 19, 19, 22, 22},
    {10, 0, 10, 10, 13, 13, 16, 16, 16, 19, 19, 19, 22},
    {10, 10, 0, 10, 10, 13, 13, 16, 16, 16, 19, 19, 19},
    {13, 10, 10, 0, 10, 10, 13, 13, 16, 16, 16, 19, 19},
    {13, 13, 10, 10, 0, 10, 10, 13, 13, 16, 16, 16, 19},
    {16, 13, 13, 10, 10, 0, 10, 10, 13, 13, 16, 16, 16},
    {16, 16, 13, 13, 10, 10, 0, 10, 10, 13, 13, 16, 16},
    {16, 16, 16, 13, 13, 10, 10, 0, 10, 10, 13, 13, 16},
    {19, 16, 16, 16, 13, 13, 10, 10, 0, 10, 10, 13, 13},
    {19, 19, 16, 16, 16, 13, 13, 10, 10, 0, 10, 10, 13},
    {19, 19, 19, 16, 16, 16, 13, 13, 10, 10, 0, 10, 10},
    {22, 19, 19, 19, 16, 16, 16, 13, 13, 10, 10, 0, 10},
    {22, 22, 19, 19, 19, 16, 16, 16, 13, 13, 10, 10, 0}};

const int MRT3Fares_single_journey[13][13] = {
    {0, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24, 28, 28},
    {13, 0, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24, 28},
    {13, 13, 0, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24},
    {16, 13, 13, 0, 13, 13, 16, 16, 20, 20, 20, 24, 24},
    {16, 16, 13, 13, 0, 13, 13, 16, 16, 20, 20, 20, 24},
    {20, 16, 16, 13, 13, 0, 13, 13, 16, 16, 20, 20, 20},
    {20, 20, 16, 16, 13, 13, 0, 13, 13, 16, 16, 20, 20},
    {20, 20, 20, 16, 16, 13, 13, 0, 13, 13, 16, 16, 20},
    {24, 20, 20, 20, 16, 16, 13, 13, 0, 13, 13, 16, 16},
    {24, 24, 20, 20, 20, 16, 16, 13, 13, 0, 13, 13, 16},
    {24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0, 13, 13},
    {28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0, 13},
    {28, 28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0}};

// Function declarations
void delay_ms(unsigned int milliseconds);
void intro_loading();
void wait_loading();
void print_with_delay(char *text, int delay_msg);
void exit_loading(double overallFare);
void print_header();
int read_int_input(const char *prompt, int min, int max);

// main function
int main()
{
    int railwayLine, cardType, passengerStatus, initialStation, endStation;
    double overallFare = 0.0, passengerDiscount = 1.00;
    char continueChoice;

    intro_loading();
    print_header();
    print_with_delay("\n\t\t\t\t\t\t   Hello, commuter! Let's make your trip planning easier!\n", 30);
    print_with_delay("\t\t\t\t\t    This program will help you calculate your fare for LRT and MRT rides.\n", 30);
    print_with_delay("\t\t\t\t\t\t Simply follow the prompts to select your starting station\n", 30);
    print_with_delay("\t\t\t\t\t\t  and destination, and we will calculate the fare for you.\n", 30);
    print_with_delay("\t\t\t\t\t      If you're transferring lines, we will guide you through it too!\n", 30);

    printf("\n\t\t\t\t\tWould you like to continue?\n\t\t\t\t\tPress [Y/N]\n");
    do
    {
        printf("\n\t\t\t\t\tEnter your choice (Y/N): ");
        continueChoice = toupper(getchar());
        while (getchar() != '\n')
            ;
        if (continueChoice != 'Y' && continueChoice != 'N')
        {
            printf("\t\t\t\t\tInvalid input. Please enter 'Y' or 'N' only.\n");
        }
    } while (continueChoice != 'Y' && continueChoice != 'N');

    if (continueChoice == 'N')
    {
        exit_loading(overallFare);
        delay_ms(1000);
        return 0;
    }

    intro_loading();
    print_header();
    printf("\t\t\t\t\t\t\t\t  [1] LRT-1     [3] MRT-3\n\t\t\t\t\t\t\t\t  [2] LRT-2     [4] EXIT\n");
    printf("\n\t\t\t\t\tPlease choose your current Railway Network Line.\n");

    railwayLine = read_int_input("\t\t\t\t\tYour railway line: ", 1, 4);
    switch (railwayLine)
    {
    case 1:
        printf("\t\t\t\t\tYou are currently riding LRT-1!\n");
        break;
    case 2:
        printf("\t\t\t\t\tYou are currently riding LRT-2!\n");
        break;
    case 3:
        printf("\t\t\t\t\tYou are currently riding MRT-3!\n");
        break;
    case 4:
        exit_loading(overallFare);
        delay_ms(1000);
        return 0;
    }

    print_header();
    printf("\t\t\t\t\t\t\t\t  [1] Stored Value (Beep) Card\n\t\t\t\t\t\t\t\t  [2] Single Journey Card\n");
    printf("\t\t\t\t\tPlease choose your current Card Type.\n");

    cardType = read_int_input("\t\t\t\t\tEnter your card: ", 1, 2);
    switch (cardType)
    {
    case 1:
        printf("\t\t\t\t\tYour card: Stored Value (Beep) Fare Card\n");
        break;
    case 2:
        printf("\t\t\t\t\tYour card: Single Journey Fare Card\n");
        break;
    }

    print_header();
    printf("\t\t\t\t\t\t\t\t  [1] PWD\n\t\t\t\t\t\t\t\t  [2] Senior Citizen\n\t\t\t\t\t\t\t\t  [3] Student\n\t\t\t\t\t\t\t\t  [4] Regular Passenger\n");
    printf("\t\t\t\t\tPlease choose one that applies.\n");

    passengerStatus = read_int_input("\t\t\t\t\tEnter your status: ", 1, 4);
    switch (passengerStatus)
    {
    case 1:
    case 2:
        passengerDiscount = 0.70;
        printf("\t\t\t\t\tYou are eligible for a 30%% discount\n");
        break;
    case 3:
        passengerDiscount = 0.80;
        printf("\t\t\t\t\tYou are eligible for a 20%% discount\n");
        break;
    case 4:
        passengerDiscount = 1.00;
        printf("\t\t\t\t\tNo discount will be applied\n");
        break;
    }

    print_header();
    if (railwayLine == 1)
    {
        printf("\t\t\t\t\tLRT-1 Stations:\n");
        for (int i = 0; i < 25; i++)
        {
            printf("\t\t\t\t\t[%2d] %s\n", i + 1, LRT1Stations[i]);
        }
        initialStation = read_int_input("\t\t\t\t\tEnter your starting station number: ", 1, 25) - 1;
        do
        {
            endStation = read_int_input("\t\t\t\t\tEnter your destination station number: ", 1, 25) - 1;
            if (endStation == initialStation)
            {
                printf("\t\t\t\t\tError: Starting and destination stations cannot be the same.\n");
            }
        } while (endStation == initialStation);

        if (cardType == 1)
        {
            overallFare = LRT1Fares_beep[initialStation][endStation] * passengerDiscount;
        }
        else
        {
            overallFare = LRT1Fares_single_journey[initialStation][endStation] * passengerDiscount;
        }
    }
    else if (railwayLine == 2)
    {
        printf("\t\t\t\t\tLRT-2 Stations:\n");
        for (int i = 0; i < 13; i++)
        {
            printf("\t\t\t\t\t[%2d] %s\n", i + 1, LRT2Stations[i]);
        }
        initialStation = read_int_input("\t\t\t\t\tEnter your starting station number: ", 1, 13) - 1;
        do
        {
            endStation = read_int_input("\t\t\t\t\tEnter your destination station number: ", 1, 13) - 1;
            if (endStation == initialStation)
            {
                printf("\t\t\t\t\tError: Starting and destination stations cannot be the same.\n");
            }
        } while (endStation == initialStation);

        if (cardType == 1)
        {
            overallFare = LRT2Fares_beep[initialStation][endStation] * passengerDiscount;
        }
        else
        {
            overallFare = LRT2Fares_single_journey[initialStation][endStation] * passengerDiscount;
        }
    }
    else if (railwayLine == 3)
    {
        printf("\t\t\t\t\tMRT-3 Stations:\n");
        for (int i = 0; i < 13; i++)
        {
            printf("\t\t\t\t\t[%2d] %s\n", i + 1, MRT3Stations[i]);
        }
        initialStation = read_int_input("\t\t\t\t\tEnter your starting station number: ", 1, 13) - 1;
        do
        {
            endStation = read_int_input("\t\t\t\t\tEnter your destination station number: ", 1, 13) - 1;
            if (endStation == initialStation)
            {
                printf("\t\t\t\t\tError: Starting and destination stations cannot be the same.\n");
            }
        } while (endStation == initialStation);

        if (passengerStatus == 1 || passengerStatus == 2 || passengerStatus == 3)
        {
            overallFare = MRT3Fares_discounted[initialStation][endStation];
        }
        else
        {
            overallFare = MRT3Fares_single_journey[initialStation][endStation];
        }
    }

    printf("\t\t\t\t\tYour fare: %.2f PHP\n", overallFare);
    exit_loading(overallFare);
    delay_ms(1000);
    return 0;
}

// Function definitions
void delay_ms(unsigned int milliseconds)
{
    Sleep(milliseconds);
}

void intro_loading()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\tStarting the program... Please wait! ");
    for (int i = 1; i <= 25; i++)
    {
        Sleep(100);
        printf("%c", 219);
    }
    system("cls");
}

void wait_loading()
{
    printf("\t\t\t\t\tLoading... Please wait! ");
    for (int i = 1; i <= 25; i++)
    {
        Sleep(100);
        printf("%c", 219);
    }
    printf("\n");
}

void print_with_delay(char *text, int delay_msg)
{
    while (*text)
    {
        putchar(*text++);
        fflush(stdout);
        Sleep(delay_msg);
    }
}

void exit_loading(double overallFare)
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\tExiting the program... Please wait! ");
    for (int i = 1; i <= 25; i++)
    {
        Sleep(100);
        printf("%c", 219);
    }
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t THANK YOU FOR VISITING LRT-MRT FARE CALCULATOR!\n");
    printf("\t\t\t\t\t\t\t\tOverall Fare: %.2f PHP\n\n\n\n\n", overallFare);
}

void print_header()
{
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t  LRT-MRT FARE CALCULATOR\n");
    printf("\t\t\t\t\t----------------------------------------------------------------------------\n");
}

int read_int_input(const char *prompt, int min, int max)
{
    int value;
    char buffer[100];
    int valid = 0;

    do
    {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        {
            printf("\t\t\t\t\tError reading input. Try again.\n");
            continue;
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        char *endptr;
        errno = 0;
        value = strtol(buffer, &endptr, 10);
        if (*endptr == '\0' && errno == 0 && value >= min && value <= max)
        {
            valid = 1;
        }
        else
        {
            printf("\t\t\t\t\tInvalid input. Please enter a number between %d and %d.\n\n", min, max);
        }
    } while (!valid);

    return value;
}