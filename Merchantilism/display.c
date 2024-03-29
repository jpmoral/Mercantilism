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
    printf("[L]oan\n");
    printf("[P]ay Debt\n");
    printf("[I]nvest\n");
    printf("[W]ithdraw Investment\n");
    printf("[M]ain Menu\n\n");
    printf("What would you like to do?: ");
}

void display_location_actions_menu(LOCATION *location) {
    
    printf("\n");
    printf("You are in %s.\n\n",location->name); 
    display_location_stocks_and_prices(location);
    printf("[A] Buy lumber    [F] Sell lumber\n");
    printf("[B] Buy stone     [G] Sell stone\n");
    printf("[C] Buy silk      [H] Sell silk\n");
    printf("[D] Buy ore       [I] Sell ore\n");
    printf("[E] Buy gems      [J] Sell gems\n");
    printf("[M]ain Menu\n\n");
    printf("What would you like to do?: ");
}

void display_location_stocks_and_prices(LOCATION *loc) {
    
    printf("\n");
    printf("STOCKS AVAILABLE and MARKET PRICES:\n");
    printf("========================\n");
    printf("LUMBER: %i  PRICE: %i\n", loc->lumber_available, loc->lumber_price);
    printf("STONE: %i  PRICE: %i\n", loc->stone_available, loc->stone_price);
    printf("SILK: %i  PRICE: %i\n", loc->silk_available, loc->silk_price);
    printf("ORE: %i  PRICE: %i\n", loc->ore_available, loc->ore_price);
    printf("GEMS: %i  PRICE: %i\n", loc->gem_available, loc->gem_price);
    printf("========================\n");
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
