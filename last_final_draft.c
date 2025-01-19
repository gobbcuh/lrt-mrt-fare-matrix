
if (railwayLine == 1 && endStation == 16) // Transfer from LRT1 to LRT2 (D. Jose to Recto)
{  
    printf("\n\tYou have arrived at D. Jose, which intersects with LRT-2.\n\tWould you like to transfer to LRT-2?\n\tY if YES\n\tN if NO\n");
    printf("\tYour choice: ");
    scanf(" %c", &passengerChoice);
    
    do
    {
        printf("\n\tWould you like to transfer to LRT-2?\n\tY if YES\n\tN if NO\n");
        printf("\tYour choice: ");
        scanf(" %c", &passengerChoice);
    
        if (passengerChoice == 'Y' || passengerChoice == 'y')
        {
            railwayLine = 2;
            initialStation = 1;
            
            printf("----------------------------------------------------\n");
            printf("\tYou are now riding LRT-2.\n");

            printf("\n\tWould you like to proceed to another station?\n\tY if YES\n\tN if NO");
            printf("\n\tYour choice: ");
            scanf(" %c", &passengerChoice);

            if (passengerChoice == 'Y' || passengerChoice == 'y')
            {
                printf("\n\tChoose from the following LRT-2 stations:\n");
                int i = 0;
                do
                {
                    printf("\t%d. %s\n", i + 1, LRT2Stations[i]);
                    i++;
                } while (i < 13);
                
                printf("\n\tCurrent Station: Recto\n");
                continue;
            }
            else if (passengerChoice == 'N' || passengerChoice == 'n')
            {
                printf("----------------------------------------------------\n");
                printf("\tYour total fare for the entire trip: PHP %.2f\n", overallFare);
                printf("\tThank you for using Railway Lines Fare Matrix Calculator!\n");
                return 0;
            }
            else
            {
                printf("\tInvalid. Please input either 'Y' or 'N' only\n");
            }
        }
        else if (passengerChoice == 'N' || passengerChoice == 'n')
        {
            break;
        }
        else
        {
            printf("\tInvalid. Please input either 'Y' or 'N' only\n");
        }
    } while (passengerChoice == 'Y' || passengerChoice == 'y' || passengerChoice == 'N' || passengerChoice == 'n');
}