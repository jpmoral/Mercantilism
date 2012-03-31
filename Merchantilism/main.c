//
//  main.c
//  Merchantilism
//
//  Created by JP Moral on 3/29/12.
//  Copyright (c) 2012 Codeflux. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Constants.h"
#include "player_and_locations.h"

void main_menu();
void display_player_profile(PLAYER *);

int main (int argc, const char * argv[]) {
    
    PLAYER *player = (PLAYER *)malloc(sizeof(PLAYER));
    LOCATION *red = (LOCATION *)malloc(sizeof(PLAYER)), *azure = (LOCATION *)malloc(sizeof(PLAYER)), *emerald = (LOCATION *)malloc(sizeof(PLAYER)), *grey = (LOCATION *)malloc(sizeof(PLAYER)), *pirate = (LOCATION *)malloc(sizeof(PLAYER));
    LOCATION *loc_array[] = {red, azure, emerald, grey, pirate};
    
    initialize_player(player);
    initialize_locations(loc_array, NUMBER_OF_LOCATIONS);
    
    display_player_profile(player);
    
    return 0;
}

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
