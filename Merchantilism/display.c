//
//  display.c
//  Mercantilism
//
//  Created by JP Moral on 3/31/12.
//  Copyright (c) 2012 Codeflux. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include "Constants.h"
#include "player_and_locations.h"

void display_player_profile(PLAYER *player) {
    
    system("clear");
    printf("PROFILE:\n");
    printf("========================\n");
    printf("CASH: %.2f\n", player->cash);
    printf("INVESTMENT: %.2f\tINTEREST:%.2f\n", player->investment, INVESTMENT_INTEREST_RATE);
    printf("DEBT: %.2f\tINTEREST:%.2f\n", player->debt,DEBT_INTEREST_RATE);
    printf("NET BALANCE: %.2f\n", player->net_balance);
    printf("INVENTORY:\n");
    printf("LUMBER: %d\n",player->lumber);
    printf("STONE: %d\n",player->stone);
    printf("SILK: %d\n",player->silk);
    printf("ORE: %d\n",player->ore);
    printf("GEM: %d\n",player->gem);
    printf("========================\n");
}

void display_main_menu(void) {
    
    system("clear");
    printf("\n\n\n\n");
    printf("\t\t\t     MERCHANTILISM\n\n\n");
    printf("\t\t\t [P]lay the game\n\n");
    printf("\t\t\t [H]ow to play\n\n");
    printf("\t\t\t [Q]uit\n");
}

void display_destination_choice_menu(LOCATION *loc_array[],int number_of_locations) {
    
    printf("\n\n");
    printf("[B}ank\n");
    int i;
    for (i = 0; i < number_of_locations; i++) {
        printf("%s\n",loc_array[i]->menu_name);
    }
    printf("[Q]uit\n");
    printf("\n\nWhere do you want to go?: ");
}

void display_bank_actions_menu(void) {
    
}

void display_location_actions_menu(LOCATION *location) {
    
}

