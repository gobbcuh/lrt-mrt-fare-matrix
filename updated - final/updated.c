#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// LRT-MRT fare matrix

const char LRT1Stations[25][25] = {"Dr. Santos", "Ninoy Aquino Avenue", "PITX", "Mia Road", "Redemptionist-Aseana", "Baclaran", "EDSA", "Libertad", "Gil Puyat", "Vito Cruz", "Quirino", "Pedro Gil", "UN Avenue", "Central", "Carriedo", "D. Jose", "Bambang", "Tayuman", "Blumentritt", "Abad Santos", "R. Papa", "5th Avenue", "Monumento", "Balintawak", "Fernando Poe Jr."};

const int LRT1Fares_beep[25][25] = 
{
    {0, 15, 17, 18, 19, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 35, 37, 38, 41, 43},
    {15, 0, 15, 16, 17, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 33, 35, 36, 39, 41},
    {17, 15, 0, 15, 16, 18, 18, 20, 20, 22, 23, 24, 25, 26, 27, 28, 29, 29, 30, 31, 32, 33, 35, 37, 39},
    {18, 16, 15, 0, 14, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 28, 30, 30, 32, 33, 36, 38},
    {19, 17, 16, 14, 0, 15, 16, 17, 18, 19, 20, 21, 22, 24, 24, 25, 26, 27, 28, 29, 30, 31, 32, 35, 37},
    {21, 19, 18, 16, 15, 0, 14, 15, 16, 17, 18, 19, 20, 22, 23, 23, 24, 25, 26, 27, 28, 29, 30, 33, 35},
    {22, 20, 18, 17, 16, 14, 0, 15, 15, 17, 18, 19, 20, 21, 22, 23, 24, 24, 25, 26, 27, 28, 29, 32, 34},
    {23, 21, 20, 18, 17, 15, 15, 0, 14, 15, 16, 17, 18, 20, 21, 22, 22, 23, 24, 25, 26, 27, 28, 31, 33},
    {24, 22, 20, 19, 18, 16, 15, 14, 0, 15, 16, 17, 17, 19, 20, 21, 21, 22, 23, 24, 25, 26, 27, 30, 32},
    {25, 23, 22, 20, 19, 17, 17, 15, 15, 0, 14, 15, 16, 18, 19, 19, 20, 21, 22, 23, 24, 25, 26, 29, 31},
    {26, 24, 23, 21, 20, 18, 18, 16, 16, 14, 0, 14, 15, 17, 18, 18, 19, 20, 21, 22, 23, 24, 25, 28, 30},
    {27, 25, 24, 22, 21, 19, 19, 17, 17, 15, 14, 0, 14, 16, 17, 17, 18, 19, 20, 21, 22, 23, 24, 27, 29},
    {28, 26, 25, 23, 22, 20, 20, 18, 17, 16, 15, 14, 0, 15, 16, 16, 17, 18, 19, 20, 21, 22, 23, 26, 28},
    {29, 27, 26, 24, 24, 22, 21, 20, 19, 18, 17, 16, 15, 0, 14, 15, 16, 17, 17, 18, 19, 20, 22, 24, 27},
    {30, 28, 27, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 14, 0, 14, 15, 16, 16, 18, 18, 20, 21, 24, 26},
    {31, 29, 28, 26, 25, 23, 23, 22, 21, 19, 18, 17, 16, 15, 14, 0, 14, 15, 16, 17, 18, 19, 20, 23, 25},
    {32, 30, 29, 27, 26, 24, 24, 22, 21, 20, 19, 18, 17, 16, 15, 14, 0, 14, 15, 16, 17, 18, 19, 22, 24},
    {33, 31, 29, 28, 27, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 0, 14, 15, 16, 17, 18, 21, 23},
    {34, 32, 30, 28, 28, 26, 25, 24, 23, 22, 21, 20, 19, 17, 16, 16, 15, 14, 0, 14, 15, 16, 18, 20, 23},
    {35, 33, 31, 30, 29, 27, 26, 25, 24, 23, 22, 21, 20, 18, 18, 17, 16, 15, 14, 0, 14, 15, 17, 19, 22},
    {35, 33, 32, 30, 30, 28, 27, 26, 25, 24, 23, 22, 21, 19, 18, 18, 17, 16, 15, 14, 0, 14, 16, 18, 21},
    {37, 35, 33, 32, 31, 29, 28, 27, 26, 25, 24, 23, 22, 20, 20, 19, 18, 17, 16, 15, 14, 0, 15, 17, 20},
    {38, 36, 35, 33, 32, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 18, 17, 16, 15, 0, 16, 18},
    {41, 39, 37, 36, 35, 33, 32, 31, 30, 29, 28, 27, 26, 24, 24, 23, 22, 21, 20, 19, 18, 17, 16, 0, 16},
    {43, 41, 39, 38, 37, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 23, 22, 21, 20, 18, 16, 0}
};

const int LRT1Fares_single_journey[25][25] = 
{
    {0, 15, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30, 30, 30, 30, 35, 35, 35, 35, 35, 35, 40, 40, 45, 45},
    {15, 0, 15, 20, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30, 30, 30, 30, 35, 35, 35, 35, 35, 40, 40, 45},
    {20, 15, 0, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 30, 30, 30, 30, 30, 30, 35, 35, 35, 35, 40, 40},
    {20, 20, 15, 0, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30, 30, 30, 30, 30, 35, 35, 40, 40},
    {20, 20, 20, 15, 0, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30, 30, 30, 30, 35, 35, 35, 40},
    {25, 20, 20, 20, 15, 0, 15, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30, 30, 30, 30, 35, 35},
    {25, 20, 20, 20, 20, 15, 0, 15, 15, 20, 20, 20, 20, 25, 25, 25, 25, 25, 25, 30, 30, 30, 30, 35, 35},
    {25, 25, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 20, 20, 25, 25, 25, 25, 25, 25, 30, 30, 30, 35, 35},
    {25, 25, 20, 20, 20, 20, 15, 15, 0, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 25, 30, 30, 30, 35},
    {25, 25, 25, 20, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30, 35},
    {30, 25, 25, 25, 20, 20, 20, 20, 20, 15, 0, 15, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30},
    {30, 25, 25, 25, 25, 20, 20, 20, 20, 15, 15, 0, 15, 20, 20, 20, 20, 20, 20, 25, 25, 25, 25, 30, 30},
    {30, 30, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 0, 15, 20, 20, 20, 20, 20, 20, 25, 25, 25, 30, 30},
    {30, 30, 30, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 0, 15, 15, 20, 20, 20, 20, 20, 20, 25, 25, 30},
    {30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 0, 15, 15, 20, 20, 20, 20, 20, 25, 25, 30},
    {35, 30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 20, 20, 20, 25, 25},
    {35, 30, 30, 30, 30, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 20, 20, 25, 25},
    {35, 35, 30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 20, 25, 25},
    {35, 35, 30, 30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 20, 25},
    {35, 35, 35, 30, 30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 0, 15, 15, 20, 20, 25},
    {35, 35, 35, 30, 30, 30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 0, 15, 20, 20, 25},
    {40, 35, 35, 35, 35, 30, 30, 30, 30, 25, 25, 25, 25, 20, 20, 20, 20, 20, 20, 15, 15, 0, 15, 20, 20},
    {40, 40, 35, 35, 35, 30, 30, 30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 20, 15, 0, 20, 20},
    {45, 40, 40, 40, 35, 35, 35, 35, 30, 30, 30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 0, 20},
    {45, 45, 40, 40, 40, 35, 35, 35, 35, 35, 30, 30, 30, 30, 30, 25, 25, 25, 25, 25, 25, 20, 20, 20, 0}
};

const char LRT2Stations[13][10] = {"Recto", "Legarda", "Pureza", "V. Mapa", "J. Ruiz", "Gilmore", "Betty Go", "Cubao", "Anonas", "Katipunan", "Santolan", "Marikina", "Antipolo"};

const int LRT2Fares_beep[13][13] = 
{
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
    {33, 32, 30, 29, 27, 26, 25, 23, 22, 21, 18, 16, 0}
};

const int LRT2Fares_single_journey[13][13] = 
{
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
    {35, 35, 30, 30, 30, 30, 25, 25, 25, 25, 20, 20, 0}
};

const char MRT3Stations[13][20] = {"North Avenue", "Quezon Avenue", "GMA Kamuning", "Araneta", "Santolan-Annapolis", "Ortigas", "Shaw Boulevard", "Boni Avenue", "Guadalupe", "Buendia", "Ayala", "Magallanes", "Taft Avenue"};

const int MRT3Fares_beep[13][13] = 
{
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
    {28, 28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0}
};

const int MRT3Fares_single_journey [13][13] = 
{
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
    {28, 28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 0}
};

// function declaration/prototypes

void delay(unsigned int secs);
void intro_loading();
void wait_loading();
void print_with_delay(char *text, int delay_msg);
void exit_loading(int overallFare);

int main()
{
    int railwayLine, cardType, passengerStatus, initialStation, endStation;
    double overallFare = 0.0, passengerDiscount = 1.00;
    char continueChoice;

    intro_loading();
    delay(100);

    printf("\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t  LRT-MRT FARE CALCULATOR\n");
    printf("\t\t\t\t\t----------------------------------------------------------------------------\n");

    print_with_delay("\n\t\t\t\t\t\t   Hello, commuter! Let's make your trip planning easier!\n", 30);
    print_with_delay("\t\t\t\t\t    This program will help you calculate your fare for LRT and MRT rides.\n", 30);
    print_with_delay("\t\t\t\t\t\t Simply follow the prompts to select your starting station\n", 30);
    print_with_delay("\t\t\t\t\t\t  and destination, and we will calculate the fare for you.\n", 30);
    print_with_delay("\t\t\t\t\t      If you're transferring lines, we will guide you through it too!\n", 30);

    printf("\n\t\t\t\t\t----------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\tWould you like to continue?\n\t\t\t\t\tPress [Y] if YES and [N] if NO\n");

    do
    {
        printf("\n\t\t\t\t\tEnter your choice: ");
        scanf(" %c", &continueChoice);

        if (continueChoice != 'Y' && continueChoice != 'y' && continueChoice != 'N' && continueChoice != 'n')
        {
            printf("\t\t\t\t\tOops! Choose between [Y] and [N] only.\n");
        }

    } while (continueChoice != 'Y' && continueChoice != 'y' && continueChoice != 'N' && continueChoice != 'n');

    if (continueChoice == 'Y' || continueChoice == 'y')
    {
        intro_loading();
        delay(1000);
    }
    else if (continueChoice == 'N' || continueChoice == 'n')
    {
        exit_loading(overallFare);
        delay(1000);
        return 0;
    }

    // error starts from here. it keeps on printing, do not proceed

    printf("\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t  LRT-MRT FARE CALCULATOR\n");
    printf("\t\t\t\t\t----------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t  [1] LRT-1     [3] MRT-3\n\t\t\t\t\t\t\t\t  [2] LRT-2     [4] EXIT");
    printf("\n\t\t\t\t\t--------------------------------------------------------------------------\n");

    printf("\t\t\t\t\tPlease choose your current Railway Network Line.\n");

    do
    {
        printf("\t\t\t\t\tYour railway line: ");
        scanf("%d", &railwayLine);

        while (getchar() != '\n');

        switch(railwayLine)
        {
            case 1:
                printf("\t\t\t\t\tYou are currently riding LRT-1!\n");
                wait_loading();
                break;
                
            case 2:
                printf("\t\t\t\t\tYou are currently riding LRT-2!\n");
                wait_loading();
                break;
                
            case 3:
                printf("\t\t\t\t\tYou are currently riding MRT-3!\n");
                wait_loading();
                break;
            
            case 4:
                exit_loading(overallFare);
                delay(1000);
                return 0;
                
            default:
                printf("\t\t\t\t\tInvalid. Please enter a valid railway network line number.\n\n");
                break;
        }

    } while (railwayLine < 1 || railwayLine > 4);

    printf("\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t  LRT-MRT FARE CALCULATOR\n");
    printf("\t\t\t\t\t----------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t  [1] Stored Value (Beep) Card\n\t\t\t\t\t\t\t\t  [2] Single Journey Card");
    printf("\n\t\t\t\t\t--------------------------------------------------------------------------\n");

    printf("\t\t\t\t\tPlease choose your current Card Type.");

    do
    {
        if (railwayLine == 1 || railwayLine == 2 || railwayLine == 3)
        {
            printf("\n\t\t\t\t\tEnter your card: ");
            scanf("%d", &cardType);

            while (getchar() != '\n');

            switch(cardType)
            {
                case 1:
                    printf("\t\t\t\t\tYour card: Stored Value (Beep) Fare Card\n");
                    wait_loading();
                    break;
                    
                case 2:
                    printf("\t\t\t\t\tYour card: Single Journey Fare Card\n");
                    wait_loading();
                    break;
                    
                default:
                    printf("\t\t\t\t\tInvalid. Please enter a valid card type number.\n");
                    wait_loading();
                    break;
            }
        }

    } while (cardType != 1 && cardType != 2);

    printf("\n\n\n\n\n\t\t\t\t\t----------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t  LRT-MRT FARE CALCULATOR\n");
    printf("\t\t\t\t\t----------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t  [1] PWD\n\t\t\t\t\t\t\t\t  [2] Senior Citizen\n\t\t\t\t\t\t\t\t  [3] Student\n\t\t\t\t\t\t\t\t  [4] Regular Passenger");
    printf("\n\t\t\t\t\t--------------------------------------------------------------------------\n");

    printf("\t\t\t\t\tPlease choose one that applies.");

    do
    {
        if (railwayLine == 1 || railwayLine == 2 || railwayLine == 3)
        {
            printf("\n\t\t\t\t\tEnter your status: ");
            scanf("%d", &passengerStatus);

            while (getchar() != '\n');

            if (passengerStatus == 1 || passengerStatus == 2)
            {
                passengerDiscount = 0.70;
                printf("\t\t\t\t\tYou are eligible for a 30%% discount\n");
            }
            else if (passengerStatus == 3)
            {
                passengerDiscount = 0.80;
                printf("\t\t\t\t\tYou are eligible for a 20%% discount\n");
            }
            else if (passengerStatus == 4)
            {
                printf("\t\t\t\t\tNo discount will be applied\n");
            }
            else
            {
                printf("\t\t\t\t\tInvalid. Please enter a valid status number.\n");
            }
        }
        
    } while (passengerStatus < 1 || passengerStatus > 4);
        
    return 0;
}

// function definitions

void delay(unsigned int secs)
{
    clock_t interval = clock() + secs;
    while (interval > clock());
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

void exit_loading(int overallFare)
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
    printf("\t\t\t\t\t\t\t\tOverall Fare: %d\n\n\n\n\n", overallFare);
}