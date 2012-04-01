//
//  player_and_locations.c
//  Mercantilism
//
//  Created by JP Moral on 3/31/12.
//  Copyright (c) 2012 Codeflux. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player_and_locations.h"
#include "Constants.h"

void initialize_player(PLAYER *player) {
    
    player->cash = PLAYER_STARTING_MONEY;
    player->debt = PLAYER_STARTING_DEBT;
    player->investment = 0;
    updatePlayerNetBalance(player);
}

void initialize_locations(LOCATION *loc_array[], int number_of_locations) {
    
    srand((unsigned)time(NULL));
    loc_array[0]->name = RED_TOWN;
    loc_array[0]->menu_name = RED_TOWN_MENU;
    loc_array[0]->lumber_available = rand()%(RED_TOWN_LUMBER_MAX_RESTOCK - RED_TOWN_LUMBER_MIN_RESTOCK + 1) + RED_TOWN_LUMBER_MIN_RESTOCK;
    loc_array[0]->stone_available = rand()%(RED_TOWN_STONE_MAX_RESTOCK - RED_TOWN_STONE_MIN_RESTOCK + 1) + RED_TOWN_STONE_MIN_RESTOCK;
    loc_array[0]->silk_available = rand()%(RED_TOWN_SILK_MAX_RESTOCK - RED_TOWN_SILK_MIN_RESTOCK + 1) + RED_TOWN_SILK_MIN_RESTOCK;
    loc_array[0]->ore_available = rand()%(RED_TOWN_ORE_MAX_RESTOCK - RED_TOWN_ORE_MIN_RESTOCK + 1) + RED_TOWN_ORE_MIN_RESTOCK;
    loc_array[0]->gem_available = rand()%(RED_TOWN_GEM_MAX_RESTOCK - RED_TOWN_GEM_MIN_RESTOCK + 1) + RED_TOWN_GEM_MIN_RESTOCK;
    
    loc_array[0]->lumber_price = rand()%(RED_TOWN_LUMBER_MAX_PRICE - RED_TOWN_LUMBER_MIN_PRICE + 1) + RED_TOWN_LUMBER_MIN_PRICE;
    loc_array[0]->stone_price = rand()%(RED_TOWN_STONE_MAX_PRICE - RED_TOWN_STONE_MIN_PRICE + 1) + RED_TOWN_STONE_MIN_PRICE;
    loc_array[0]->silk_price = rand()%(RED_TOWN_SILK_MAX_PRICE - RED_TOWN_SILK_MIN_PRICE + 1) + RED_TOWN_SILK_MIN_PRICE;
    loc_array[0]->ore_price = rand()%(RED_TOWN_ORE_MAX_PRICE - RED_TOWN_ORE_MIN_PRICE + 1) + RED_TOWN_ORE_MIN_PRICE;
    loc_array[0]->gem_price = rand()%(RED_TOWN_GEM_MAX_PRICE - RED_TOWN_GEM_MIN_PRICE + 1) + RED_TOWN_GEM_MIN_PRICE;
    
    loc_array[0]->lumber_min_restock = RED_TOWN_LUMBER_MIN_RESTOCK;
    loc_array[0]->stone_min_restock = RED_TOWN_STONE_MIN_RESTOCK;
    loc_array[0]->silk_min_restock = RED_TOWN_SILK_MIN_RESTOCK;
    loc_array[0]->ore_min_restock = RED_TOWN_ORE_MIN_RESTOCK;
    loc_array[0]->gem_min_restock = RED_TOWN_GEM_MIN_RESTOCK;
    
    loc_array[0]->lumber_max_restock = RED_TOWN_LUMBER_MAX_RESTOCK;
    loc_array[0]->stone_max_restock = RED_TOWN_STONE_MAX_RESTOCK;
    loc_array[0]->silk_max_restock = RED_TOWN_SILK_MAX_RESTOCK;
    loc_array[0]->ore_max_restock = RED_TOWN_ORE_MAX_RESTOCK;
    loc_array[0]->gem_max_restock = RED_TOWN_GEM_MAX_RESTOCK;
    
    loc_array[0]->lumber_min_price = RED_TOWN_LUMBER_MIN_PRICE;
    loc_array[0]->stone_min_price = RED_TOWN_STONE_MIN_PRICE;
    loc_array[0]->silk_min_price = RED_TOWN_SILK_MIN_PRICE;
    loc_array[0]->ore_min_price = RED_TOWN_ORE_MIN_PRICE;
    loc_array[0]->gem_min_price = RED_TOWN_GEM_MIN_PRICE;
    
    loc_array[0]->lumber_max_price = RED_TOWN_LUMBER_MAX_PRICE;
    loc_array[0]->stone_max_price = RED_TOWN_STONE_MAX_PRICE;
    loc_array[0]->silk_max_price = RED_TOWN_SILK_MAX_PRICE;
    loc_array[0]->ore_max_price = RED_TOWN_ORE_MAX_PRICE;
    loc_array[0]->gem_max_price = RED_TOWN_GEM_MAX_PRICE;
    
    loc_array[1]->name = AZURE_VALLEY;
    loc_array[1]->menu_name = AZURE_VALLEY_MENU;
    loc_array[1]->lumber_available = rand()%(AZURE_VALLEY_LUMBER_MAX_RESTOCK - AZURE_VALLEY_LUMBER_MIN_RESTOCK + 1) + AZURE_VALLEY_LUMBER_MIN_RESTOCK;
    loc_array[1]->stone_available = rand()%(AZURE_VALLEY_STONE_MAX_RESTOCK - AZURE_VALLEY_STONE_MIN_RESTOCK + 1) + AZURE_VALLEY_STONE_MIN_RESTOCK;
    loc_array[1]->silk_available = rand()%(AZURE_VALLEY_SILK_MAX_RESTOCK - AZURE_VALLEY_SILK_MIN_RESTOCK + 1) + AZURE_VALLEY_SILK_MIN_RESTOCK;
    loc_array[1]->ore_available = rand()%(AZURE_VALLEY_ORE_MAX_RESTOCK - AZURE_VALLEY_ORE_MIN_RESTOCK + 1) + AZURE_VALLEY_ORE_MIN_RESTOCK;
    loc_array[1]->gem_available = rand()%(AZURE_VALLEY_GEM_MAX_RESTOCK - AZURE_VALLEY_GEM_MIN_RESTOCK + 1) + AZURE_VALLEY_GEM_MIN_RESTOCK;
    
    loc_array[1]->lumber_price = rand()%(AZURE_VALLEY_LUMBER_MAX_PRICE - AZURE_VALLEY_LUMBER_MIN_PRICE + 1) + AZURE_VALLEY_LUMBER_MIN_PRICE;
    loc_array[1]->stone_price = rand()%(AZURE_VALLEY_STONE_MAX_PRICE - AZURE_VALLEY_STONE_MIN_PRICE + 1) + AZURE_VALLEY_STONE_MIN_PRICE;
    loc_array[1]->silk_price = rand()%(AZURE_VALLEY_SILK_MAX_PRICE - AZURE_VALLEY_SILK_MIN_PRICE + 1) + AZURE_VALLEY_SILK_MIN_PRICE;
    loc_array[1]->ore_price = rand()%(AZURE_VALLEY_ORE_MAX_PRICE - AZURE_VALLEY_ORE_MIN_PRICE + 1) + AZURE_VALLEY_ORE_MIN_PRICE;
    loc_array[1]->gem_price = rand()%(AZURE_VALLEY_GEM_MAX_PRICE - AZURE_VALLEY_GEM_MIN_PRICE + 1) + AZURE_VALLEY_GEM_MIN_PRICE;
    
    loc_array[1]->lumber_min_restock = AZURE_VALLEY_LUMBER_MIN_RESTOCK;
    loc_array[1]->stone_min_restock = AZURE_VALLEY_STONE_MIN_RESTOCK;
    loc_array[1]->silk_min_restock = AZURE_VALLEY_SILK_MIN_RESTOCK;
    loc_array[1]->ore_min_restock = AZURE_VALLEY_ORE_MIN_RESTOCK;
    loc_array[1]->gem_min_restock = AZURE_VALLEY_GEM_MIN_RESTOCK;
    
    loc_array[1]->lumber_max_restock = AZURE_VALLEY_LUMBER_MAX_RESTOCK;
    loc_array[1]->stone_max_restock = AZURE_VALLEY_STONE_MAX_RESTOCK;
    loc_array[1]->silk_max_restock = AZURE_VALLEY_SILK_MAX_RESTOCK;
    loc_array[1]->ore_max_restock = AZURE_VALLEY_ORE_MAX_RESTOCK;
    loc_array[1]->gem_max_restock = AZURE_VALLEY_GEM_MAX_RESTOCK;
    
    loc_array[1]->lumber_min_price = AZURE_VALLEY_LUMBER_MIN_PRICE;
    loc_array[1]->stone_min_price = AZURE_VALLEY_STONE_MIN_PRICE;
    loc_array[1]->silk_min_price = AZURE_VALLEY_SILK_MIN_PRICE;
    loc_array[1]->ore_min_price = AZURE_VALLEY_ORE_MIN_PRICE;
    loc_array[1]->gem_min_price = AZURE_VALLEY_GEM_MIN_PRICE;
    
    loc_array[1]->lumber_max_price = AZURE_VALLEY_LUMBER_MAX_PRICE;
    loc_array[1]->stone_max_price = AZURE_VALLEY_STONE_MAX_PRICE;
    loc_array[1]->silk_max_price = AZURE_VALLEY_SILK_MAX_PRICE;
    loc_array[1]->ore_max_price = AZURE_VALLEY_ORE_MAX_PRICE;
    loc_array[1]->gem_max_price = AZURE_VALLEY_GEM_MAX_PRICE;
    
    loc_array[2]->name = EMERALD_CITY;
    loc_array[2]->menu_name = EMERALD_CITY_MENU;
    loc_array[2]->lumber_available = rand()%(EMERALD_CITY_LUMBER_MAX_RESTOCK - EMERALD_CITY_LUMBER_MIN_RESTOCK + 1) + EMERALD_CITY_LUMBER_MIN_RESTOCK;
    loc_array[2]->stone_available = rand()%(EMERALD_CITY_STONE_MAX_RESTOCK - EMERALD_CITY_STONE_MIN_RESTOCK + 1) + EMERALD_CITY_STONE_MIN_RESTOCK;
    loc_array[2]->silk_available = rand()%(EMERALD_CITY_SILK_MAX_RESTOCK - EMERALD_CITY_SILK_MIN_RESTOCK + 1) + EMERALD_CITY_SILK_MIN_RESTOCK;
    loc_array[2]->ore_available = rand()%(EMERALD_CITY_ORE_MAX_RESTOCK - EMERALD_CITY_ORE_MIN_RESTOCK + 1) + EMERALD_CITY_ORE_MIN_RESTOCK;
    loc_array[2]->gem_available = rand()%(EMERALD_CITY_GEM_MAX_RESTOCK - EMERALD_CITY_GEM_MIN_RESTOCK + 1) + EMERALD_CITY_GEM_MIN_RESTOCK;
    
    loc_array[2]->lumber_price = rand()%(EMERALD_CITY_LUMBER_MAX_PRICE - EMERALD_CITY_LUMBER_MIN_PRICE + 1) + EMERALD_CITY_LUMBER_MIN_PRICE;
    loc_array[2]->stone_price = rand()%(EMERALD_CITY_STONE_MAX_PRICE - EMERALD_CITY_STONE_MIN_PRICE + 1) + EMERALD_CITY_STONE_MIN_PRICE;
    loc_array[2]->silk_price = rand()%(EMERALD_CITY_SILK_MAX_PRICE - EMERALD_CITY_SILK_MIN_PRICE + 1) + EMERALD_CITY_SILK_MIN_PRICE;
    loc_array[2]->ore_price = rand()%(EMERALD_CITY_ORE_MAX_PRICE - EMERALD_CITY_ORE_MIN_PRICE + 1) + EMERALD_CITY_ORE_MIN_PRICE;
    loc_array[2]->gem_price = rand()%(EMERALD_CITY_GEM_MAX_PRICE - EMERALD_CITY_GEM_MIN_PRICE + 1) + EMERALD_CITY_GEM_MIN_PRICE;
    
    loc_array[2]->lumber_min_restock = EMERALD_CITY_LUMBER_MIN_RESTOCK;
    loc_array[2]->stone_min_restock = EMERALD_CITY_STONE_MIN_RESTOCK;
    loc_array[2]->silk_min_restock = EMERALD_CITY_SILK_MIN_RESTOCK;
    loc_array[2]->ore_min_restock = EMERALD_CITY_ORE_MIN_RESTOCK;
    loc_array[2]->gem_min_restock = EMERALD_CITY_GEM_MIN_RESTOCK;
    
    loc_array[2]->lumber_max_restock = EMERALD_CITY_LUMBER_MAX_RESTOCK;
    loc_array[2]->stone_max_restock = EMERALD_CITY_STONE_MAX_RESTOCK;
    loc_array[2]->silk_max_restock = EMERALD_CITY_SILK_MAX_RESTOCK;
    loc_array[2]->ore_max_restock = EMERALD_CITY_ORE_MAX_RESTOCK;
    loc_array[2]->gem_max_restock = EMERALD_CITY_GEM_MAX_RESTOCK;
    
    loc_array[2]->lumber_min_price = EMERALD_CITY_LUMBER_MIN_PRICE;
    loc_array[2]->stone_min_price = EMERALD_CITY_STONE_MIN_PRICE;
    loc_array[2]->silk_min_price = EMERALD_CITY_SILK_MIN_PRICE;
    loc_array[2]->ore_min_price = EMERALD_CITY_ORE_MIN_PRICE;
    loc_array[2]->gem_min_price = EMERALD_CITY_GEM_MIN_PRICE;
    
    loc_array[2]->lumber_max_price = EMERALD_CITY_LUMBER_MAX_PRICE;
    loc_array[2]->stone_max_price = EMERALD_CITY_STONE_MAX_PRICE;
    loc_array[2]->silk_max_price = EMERALD_CITY_SILK_MAX_PRICE;
    loc_array[2]->ore_max_price = EMERALD_CITY_ORE_MAX_PRICE;
    loc_array[2]->gem_max_price = EMERALD_CITY_GEM_MAX_PRICE;
    
    loc_array[3]->name = GREY_CANYON;
    loc_array[3]->menu_name = GREY_CANYON_MENU;
    loc_array[3]->lumber_available = rand()%(GREY_CANYON_LUMBER_MAX_RESTOCK - GREY_CANYON_LUMBER_MIN_RESTOCK + 1) + GREY_CANYON_LUMBER_MIN_RESTOCK;
    loc_array[3]->stone_available = rand()%(GREY_CANYON_STONE_MAX_RESTOCK - GREY_CANYON_STONE_MIN_RESTOCK + 1) + GREY_CANYON_STONE_MIN_RESTOCK;
    loc_array[3]->silk_available = rand()%(GREY_CANYON_SILK_MAX_RESTOCK - GREY_CANYON_SILK_MIN_RESTOCK + 1) + GREY_CANYON_SILK_MIN_RESTOCK;
    loc_array[3]->ore_available = rand()%(GREY_CANYON_ORE_MAX_RESTOCK - GREY_CANYON_ORE_MIN_RESTOCK + 1) + GREY_CANYON_ORE_MIN_RESTOCK;
    loc_array[3]->gem_available = rand()%(GREY_CANYON_GEM_MAX_RESTOCK - GREY_CANYON_GEM_MIN_RESTOCK + 1) + GREY_CANYON_GEM_MIN_RESTOCK;
    
    loc_array[3]->lumber_price = rand()%(GREY_CANYON_LUMBER_MAX_PRICE - GREY_CANYON_LUMBER_MIN_PRICE + 1) + GREY_CANYON_LUMBER_MIN_PRICE;
    loc_array[3]->stone_price = rand()%(GREY_CANYON_STONE_MAX_PRICE - GREY_CANYON_STONE_MIN_PRICE + 1) + GREY_CANYON_STONE_MIN_PRICE;
    loc_array[3]->silk_price = rand()%(GREY_CANYON_SILK_MAX_PRICE - GREY_CANYON_SILK_MIN_PRICE + 1) + GREY_CANYON_SILK_MIN_PRICE;
    loc_array[3]->ore_price = rand()%(GREY_CANYON_ORE_MAX_PRICE - GREY_CANYON_ORE_MIN_PRICE + 1) + GREY_CANYON_ORE_MIN_PRICE;
    loc_array[3]->gem_price = rand()%(GREY_CANYON_GEM_MAX_PRICE - GREY_CANYON_GEM_MIN_PRICE + 1) + GREY_CANYON_GEM_MIN_PRICE;
    
    loc_array[3]->lumber_min_restock = GREY_CANYON_LUMBER_MIN_RESTOCK;
    loc_array[3]->stone_min_restock = GREY_CANYON_STONE_MIN_RESTOCK;
    loc_array[3]->silk_min_restock = GREY_CANYON_SILK_MIN_RESTOCK;
    loc_array[3]->ore_min_restock = GREY_CANYON_ORE_MIN_RESTOCK;
    loc_array[3]->gem_min_restock = GREY_CANYON_GEM_MIN_RESTOCK;
    
    loc_array[3]->lumber_max_restock = GREY_CANYON_LUMBER_MAX_RESTOCK;
    loc_array[3]->stone_max_restock = GREY_CANYON_STONE_MAX_RESTOCK;
    loc_array[3]->silk_max_restock = GREY_CANYON_SILK_MAX_RESTOCK;
    loc_array[3]->ore_max_restock = GREY_CANYON_ORE_MAX_RESTOCK;
    loc_array[3]->gem_max_restock = GREY_CANYON_GEM_MAX_RESTOCK;
    
    loc_array[3]->lumber_min_price = GREY_CANYON_LUMBER_MIN_PRICE;
    loc_array[3]->stone_min_price = GREY_CANYON_STONE_MIN_PRICE;
    loc_array[3]->silk_min_price = GREY_CANYON_SILK_MIN_PRICE;
    loc_array[3]->ore_min_price = GREY_CANYON_ORE_MIN_PRICE;
    loc_array[3]->gem_min_price = GREY_CANYON_GEM_MIN_PRICE;
    
    loc_array[3]->lumber_max_price = GREY_CANYON_LUMBER_MAX_PRICE;
    loc_array[3]->stone_max_price = GREY_CANYON_STONE_MAX_PRICE;
    loc_array[3]->silk_max_price = GREY_CANYON_SILK_MAX_PRICE;
    loc_array[3]->ore_max_price = GREY_CANYON_ORE_MAX_PRICE;
    loc_array[3]->gem_max_price = GREY_CANYON_GEM_MAX_PRICE;
    
    loc_array[4]->name = PIRATE_COVE;
    loc_array[4]->menu_name = PIRATE_COVE_MENU;
    loc_array[4]->lumber_available = rand()%(PIRATE_COVE_LUMBER_MAX_RESTOCK - PIRATE_COVE_LUMBER_MIN_RESTOCK + 1) + PIRATE_COVE_LUMBER_MIN_RESTOCK;
    loc_array[4]->stone_available = rand()%(PIRATE_COVE_STONE_MAX_RESTOCK - PIRATE_COVE_STONE_MIN_RESTOCK + 1) + PIRATE_COVE_STONE_MIN_RESTOCK;
    loc_array[4]->silk_available = rand()%(PIRATE_COVE_SILK_MAX_RESTOCK - PIRATE_COVE_SILK_MIN_RESTOCK + 1) + PIRATE_COVE_SILK_MIN_RESTOCK;
    loc_array[4]->ore_available = rand()%(PIRATE_COVE_ORE_MAX_RESTOCK - PIRATE_COVE_ORE_MIN_RESTOCK + 1) + PIRATE_COVE_ORE_MIN_RESTOCK;
    loc_array[4]->gem_available = rand()%(PIRATE_COVE_GEM_MAX_RESTOCK - PIRATE_COVE_GEM_MIN_RESTOCK + 1) + PIRATE_COVE_GEM_MIN_RESTOCK;
    
    loc_array[4]->lumber_price = rand()%(PIRATE_COVE_LUMBER_MAX_PRICE - PIRATE_COVE_LUMBER_MIN_PRICE + 1) + PIRATE_COVE_LUMBER_MIN_PRICE;
    loc_array[4]->stone_price = rand()%(PIRATE_COVE_STONE_MAX_PRICE - PIRATE_COVE_STONE_MIN_PRICE + 1) + PIRATE_COVE_STONE_MIN_PRICE;
    loc_array[4]->silk_price = rand()%(PIRATE_COVE_SILK_MAX_PRICE - PIRATE_COVE_SILK_MIN_PRICE + 1) + PIRATE_COVE_SILK_MIN_PRICE;
    loc_array[4]->ore_price = rand()%(PIRATE_COVE_ORE_MAX_PRICE - PIRATE_COVE_ORE_MIN_PRICE + 1) + PIRATE_COVE_ORE_MIN_PRICE;
    loc_array[4]->gem_price = rand()%(PIRATE_COVE_GEM_MAX_PRICE - PIRATE_COVE_GEM_MIN_PRICE + 1) + PIRATE_COVE_GEM_MIN_PRICE;
    
    loc_array[4]->lumber_min_restock = PIRATE_COVE_LUMBER_MIN_RESTOCK;
    loc_array[4]->stone_min_restock = PIRATE_COVE_STONE_MIN_RESTOCK;
    loc_array[4]->silk_min_restock = PIRATE_COVE_SILK_MIN_RESTOCK;
    loc_array[4]->ore_min_restock = PIRATE_COVE_ORE_MIN_RESTOCK;
    loc_array[4]->gem_min_restock = PIRATE_COVE_GEM_MIN_RESTOCK;
    
    loc_array[4]->lumber_max_restock = PIRATE_COVE_LUMBER_MAX_RESTOCK;
    loc_array[4]->stone_max_restock = PIRATE_COVE_STONE_MAX_RESTOCK;
    loc_array[4]->silk_max_restock = PIRATE_COVE_SILK_MAX_RESTOCK;
    loc_array[4]->ore_max_restock = PIRATE_COVE_ORE_MAX_RESTOCK;
    loc_array[4]->gem_max_restock = PIRATE_COVE_GEM_MAX_RESTOCK;
    
    loc_array[4]->lumber_min_price = PIRATE_COVE_LUMBER_MIN_PRICE;
    loc_array[4]->stone_min_price = PIRATE_COVE_STONE_MIN_PRICE;
    loc_array[4]->silk_min_price = PIRATE_COVE_SILK_MIN_PRICE;
    loc_array[4]->ore_min_price = PIRATE_COVE_ORE_MIN_PRICE;
    loc_array[4]->gem_min_price = PIRATE_COVE_GEM_MIN_PRICE;
    
    loc_array[4]->lumber_max_price = PIRATE_COVE_LUMBER_MAX_PRICE;
    loc_array[4]->stone_max_price = PIRATE_COVE_STONE_MAX_PRICE;
    loc_array[4]->silk_max_price = PIRATE_COVE_SILK_MAX_PRICE;
    loc_array[4]->ore_max_price = PIRATE_COVE_ORE_MAX_PRICE;
    loc_array[4]->gem_max_price = PIRATE_COVE_GEM_MAX_PRICE;
}

void updateGameData(PLAYER *player, LOCATION *loc_array[]) {
    
    srand((unsigned)time(NULL));
    int i;
    for (i = 0; i < 1; i++) {
        
        loc_array[i]->lumber_available = loc_array[i]->lumber_available + rand()%(loc_array[i]->lumber_max_restock - loc_array[i]->lumber_min_restock) + loc_array[i]->lumber_min_restock;
        loc_array[i]->stone_available = loc_array[i]->stone_available + rand()%(loc_array[i]->stone_max_restock - loc_array[i]->stone_min_restock) + loc_array[i]->stone_min_restock;
        loc_array[i]->silk_available = loc_array[i]->silk_available + rand()%(loc_array[i]->silk_max_restock - loc_array[i]->silk_min_restock) + loc_array[i]->silk_min_restock;
        loc_array[i]->ore_available = loc_array[i]->ore_available + rand()%(loc_array[i]->ore_max_restock - loc_array[i]->ore_min_restock) + loc_array[i]->ore_min_restock;
        loc_array[i]->gem_available = loc_array[i]->gem_available + rand()%(loc_array[i]->gem_max_restock - loc_array[i]->gem_min_restock) + loc_array[i]->gem_min_restock;
        
        loc_array[i]->lumber_price = rand()%(loc_array[i]->lumber_max_price - loc_array[i]->lumber_min_price) + loc_array[i]->lumber_min_price;
        loc_array[i]->stone_price = rand()%(loc_array[i]->stone_max_price - loc_array[i]->stone_min_price) + loc_array[i]->stone_min_price;
        loc_array[i]->silk_price = rand()%(loc_array[i]->silk_max_price - loc_array[i]->silk_min_price) + loc_array[i]->silk_min_price;
        loc_array[i]->ore_price = rand()%(loc_array[i]->ore_max_price - loc_array[i]->ore_min_price) + loc_array[i]->ore_min_price;
        loc_array[i]->gem_price = rand()%(loc_array[i]->gem_max_price - loc_array[i]->gem_min_price) + loc_array[i]->gem_min_price;
    }
    
    player->investment = player->investment + player->investment*INVESTMENT_INTEREST_RATE;
    player->debt = player->debt + player->debt*DEBT_INTEREST_RATE;
    updatePlayerNetBalance(player);
}

void updatePlayerNetBalance(PLAYER *player) {
    
    float cash = player->cash;
    float inv = player->investment;
    float debt = player->debt;
    
    player->net_balance = (cash - debt - (debt / 3.0) + inv);
}