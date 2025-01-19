#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STATIONS_MRT3 13
#define MAX_STATIONS_LRT1 21
#define MAX_STATIONS_LRT2 13

float get_discount(char card_type[]) {
    if (strcmp(card_type, "Student") == 0) {
        return 0.20; 
    } else if (strcmp(card_type, "PWD/Senior") == 0) {
        return 0.30; 
    } else if (strcmp(card_type, "Beep") == 0) {
        return 0.0; 
    } else if (strcmp(card_type, "Regular") == 0) {
        return 0.0; 
    }
    return 0.0; 
}

float calculate_fare(int initial_index, int final_index, int fares[][MAX_STATIONS_LRT1]) {
    return fares[initial_index][final_index];
}

void display_stations_lrt1() {
    printf("LRT 1 Stations:\n");
    printf("1: Baclaran LRT Station\n");
    printf("2: EDSA LRT Station\n");
    printf("3: Libertad LRT Station\n");
    printf("4: Gil Puyat LRT Station\n");
    printf("5: Vito Cruz LRT Station\n");
    printf("6: Quirino LRT Station\n");
    printf("7: Pedro Gil LRT Station\n");
    printf("8: United Nations LRT Station\n");
    printf("9: Central Terminal LRT Station\n");
    printf("10: Carriedo LRT Station\n");
    printf("11: Doroteo Jose LRT Station\n");
    printf("12: Bambang LRT Station\n");
    printf("13: Tayuman LRT Station\n");
    printf("14: Blumentritt LRT Station\n");
    printf("15: Abad Santos LRT Station\n");
    printf(“16: R.PAPA LRT Station\n”);
    printf("17: 5th Avenue LRT Station\n");
    printf("18: Monumento LRT Station\n");
    printf("19: Balintawak LRT Station\n");
    printf("20: Roosevelt LRT Station\n");
}
void display_stations_lrt2() {
    printf("LRT 2 Stations:\n");
    printf("1: Antipolo\n");
    printf("2: Marikina-Pasig\n");
    printf("3: Santolan\n");
    printf("4: Katipunan\n");
    printf("5: Anonas\n");
    printf("6: Araneta Center Cubao\n");
    printf("7: Betty Go-Belmonte\n");
    printf("8: Gilmore\n");
    printf("9: J. Ruiz\n");
    printf("10: V. Mapa\n");
    printf("11: Pureza\n");
    printf("12: Legarda\n");
    printf("13: Recto\n");
}

void display_stations_mrt3() {
    printf("MRT 3 Stations:\n");
    printf("1: North Avenue\n");
    printf("2: Quezon Avenue\n");
    printf("3: GMA Kamuning\n");
    printf("4: Araneta Center Cubao\n");
    printf("5: Santolan Annapolis\n");
    printf("6: Ortigas\n");
    printf("7: Shaw Boulevard\n");
    printf("8: Boni\n");
    printf("9: Guadalupe\n");
    printf("10: Buendia\n");
    printf("11: Ayala\n");
    printf("12: Magallanes\n");
    printf("13: Taft Avenue\n");
}

int main() {
    char card_type[20];
    int line_choice;
    int initial_station, final_station;
    float total_fare = 0.0, discount, ride_fare;
    int distance_traveled = 0;

    // Updated fare matrices for LRT-1, LRT-2, and MRT-3
    int lrt1_fares[MAX_STATIONS_LRT1][MAX_STATIONS_LRT1] = {
        {0, 12, 14, 15, 15, 16, 16, 17, 18, 18, 19, 20, 20, 21, 21, 22, 23, 24, 24, 25, 30},
        {12, 0, 12, 14, 14, 15, 15, 16, 17, 17, 18, 19, 19, 20, 20, 21, 22, 23, 23, 24, 29},
        {14, 12, 0, 12, 12, 13, 13, 14, 15, 15, 16, 17, 17, 18, 18, 19, 20, 21, 21, 22, 27},
        {15, 14, 12, 0, 12, 12, 12, 13, 14, 14, 15, 16, 16, 17, 17, 18, 19, 20, 20, 21, 26},
        {15, 14, 12, 12, 0, 12, 12, 13, 14, 14, 15, 16, 16, 17, 17, 18, 19, 20, 20, 21, 26},
        {16, 15, 13, 12, 12, 0, 12, 12, 13, 13, 14, 15, 15, 16, 16, 17, 18, 19, 19, 20, 25},
        {16, 15, 13, 12, 12, 12, 0, 12, 13, 13, 14, 15, 15, 16, 16, 17, 18, 19, 19, 20, 25},
        {17, 16, 14, 13, 13, 12, 12, 0, 12, 12, 13, 14, 14, 15, 15, 16, 17, 18, 18, 19, 24},
        {18, 17, 15, 14, 14, 13, 13, 12, 0, 12, 12, 13, 13, 14, 14, 15, 16, 17, 17, 18, 23},
        {18, 17, 15, 14, 14, 13, 13, 12, 12, 0, 12, 13, 13, 14, 14, 15, 16, 17, 17, 18, 23},
        {19, 18, 16, 15, 15, 14, 14, 13, 12, 12, 0, 12, 12, 13, 13, 14, 15, 16, 16, 17, 22},
        {20, 19, 17, 16, 16, 15, 15, 14, 13, 13, 12, 0, 12, 12, 12, 13, 14, 15, 15, 16, 21},
        {20, 19, 17, 16, 16, 15, 15, 14, 13, 13, 12, 12, 0, 12, 12, 13, 14, 15, 15, 16, 21},
        {21, 20, 18, 17, 17, 16, 16, 15, 14, 14, 13, 12, 12, 0, 12, 12, 13, 14, 14, 15, 20},
        {21, 20, 18, 17, 17, 16, 16, 15, 14, 14, 13, 12, 12, 12, 0, 12, 13, 14, 14, 15, 20},
        {22, 21, 19, 18, 18, 17, 17, 16, 15, 15, 14, 13, 13, 12, 12, 0, 12, 13, 13, 14, 19},
        {23, 22, 20, 19, 19, 18, 18, 17, 16, 16, 15, 14, 14, 13, 13, 12, 0, 12, 12, 13, 18},
        {24, 23, 21, 20, 20, 19, 19, 18, 17, 17, 16, 15, 15, 14, 14, 13, 12, 0, 12, 12, 17},
        {24, 23, 21, 20, 20, 19, 19, 18, 17, 17, 16, 15, 15, 14, 14, 13, 12, 12, 0, 12, 16},
        {30, 29, 27, 26, 26, 25, 25, 24, 23, 23, 22, 21, 21, 20, 20, 19, 18, 17, 17, 16, 0}
    };

    int lrt2_fares[MAX_STATIONS_LRT2][MAX_STATIONS_LRT2] = {
        {0, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24},
        {12, 0, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23},
        {13, 12, 0, 12, 13, 14, 15, 16, 17, 18, 19, 20, 22},
        {14, 13, 12, 0, 12, 13, 14, 15, 16, 17, 18, 19, 21},
        {15, 14, 13, 12, 0, 12, 13, 14, 15, 16, 17, 18, 20},
        {16, 15, 14, 13, 12, 0, 12, 13, 14, 15, 16, 17, 19},
        {17, 16, 15, 14, 13, 12, 0, 12, 13, 14, 15, 16, 18},
        {18, 17, 16, 15, 14, 13, 12, 0, 12, 13, 14, 15, 17},
        {19, 18, 17, 16, 15, 14, 13, 12, 0, 12, 13, 14, 16},
        {20, 19, 18, 17, 16, 15, 14, 13, 12, 0, 12, 13, 15},
        {21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 0, 12, 14},
        {22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 0, 13},
        {24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 0}
    };

    float mrt3_fare = 28.0; // Fixed fare for MRT-3

    printf("Select Card Type (Regular, Beep, Student, PWD/Senior): ");
    scanf("%s", card_type);
    discount = get_discount(card_type);

    while (1) {
        printf("Select Train Line (1 for LRT 1, 2 for LRT 2, 3 for MRT 3): ");
        scanf("%d", &line_choice);

        if (line_choice == 1) {
            display_stations_lrt1();
            printf("Enter Initial Destination (1-21): ");
            scanf("%d", &initial_station);
            printf("Enter Final Destination (1-21): ");
            scanf("%d", &final_station);
            ride_fare = calculate_fare(initial_station - 1, final_station - 1, lrt1_fares);
            distance_traveled += abs(final_station - initial_station) + 1;
            total_fare += ride_fare;
        } else if (line_choice == 2) {
            display_stations_lrt2();
            printf("Enter Initial Destination (1-13): ");
            scanf("%d", &initial_station);
            printf("Enter Final Destination (1-13): ");
            scanf("%d", &final_station);
            ride_fare = calculate_fare(initial_station - 1, final_station - 1, lrt2_fares);
            distance_traveled += abs(final_station - initial_station) + 1;
            total_fare += ride_fare;
        } else if (line_choice == 3) {
            display_stations_mrt3();
            printf("Enter Initial Destination (1-13): ");
            scanf("%d", &initial_station);
            printf("Enter Final Destination (1-13): ");
            scanf("%d", &final_station);
            ride_fare = mrt3_fare;  // Fixed fare for MRT-3
            distance_traveled += abs(final_station - initial_station) + 1;
            total_fare += ride_fare;
        } else {
            printf("Invalid line choice. Please try again.\n");
            continue;
        }

        char ride_again[4];
        printf("Do you want to ride again? (yes/no): ");
        scanf("%s", ride_again);
        if (strcmp(ride_again, "yes") != 0) {
            break;
        }

        printf("Setting your last destination as the new initial destination.\n");
    }

    
    float discounted_fare = total_fare * (1 - discount);
    printf("\nTotal distance traveled: %d stations.\n", distance_traveled);
    printf("Total fare before discount: ₱%.2f\n", total_fare);
    printf("Discount: %.0f%%\n", discount * 100);
    printf("Total fare after discount: ₱%.2f\n", discounted_fare);
    printf("Thank you for riding!\n");

    return 0;
}
