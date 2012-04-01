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
    
    system(SYSTEM_CLEAR);
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
    
    system(SYSTEM_CLEAR);
    printf("\n\n\n\n");
    printf("\t\t\t     MERCHANTILISM\n\n\n");
    printf("\t\t\t [P]lay the game\n\n");
    printf("\t\t\t [H]ow to play\n\n");
    printf("\t\t\t [Q]uit\n");
}

void display_help(void) {
    
    system(SYSTEM_CLEAR);
    printf("Instructions on how to play the game:\n");
    printf("Use the keyboard to type menu choices. Press ENTER to confirm your choice.\n");
    printf("Win the game by increasing your net balance to %.0f or greater.\n",WINNING_BALANCE);
    printf("If your net balance falls below %.0f, you lose.\n",LOSING_BALANCE);
    printf("Press ENTER to continue.");
}

void display_destination_choice_menu(LOCATION *loc_array[],int number_of_locations) {
    
    printf("\n");
    printf("[B]ank\n");
    int i;
    for (i = 0; i < number_of_locations; i++) {
        printf("%s\n",loc_array[i]->menu_name);
    }
    printf("[Q]uit\n\n");
    printf("Where do you want to go?: ");
}

void display_bank_actions_menu(void) {
    
    printf("\n");
    printf("You are at the Bank\n\n"); 
    printf("[L]OAN\n");
    printf("[P]AY DEBT\n");
    printf("[M]AIN MENU\n\n");
    printf("What would you like to do?: ");
}

void display_location_actions_menu(LOCATION *location) {
    
}

void display_endgame_message(GAME_STATE game_state) {
    
    switch (game_state) {
        case WIN:
            printf("Congratulations!  You won!");
            break;
        case LOSS:
            printf("Sorry, you lost.");
            break;
        default:
            break;
    }
    printf("\nPress ENTER to continue");
}
