//
//  player_and_locations.c
//  Mercantilism
//
//  Created by JP Moral on 3/31/12.
//  Copyright (c) 2012 Codeflux. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "player_and_locations.h"
#include "Constants.h"

void initialize_player(PLAYER *player) {
    
    player->cash = PLAYER_STARTING_MONEY;
    player->debt = PLAYER_STARTING_DEBT;
    player->investment = 0;
    player->net_balance = 0;
}

void initialize_locations(LOCATION *loc_array[], int number_of_locations) {
    
    loc_array[0]->name = RED_TOWN;
    loc_array[0]->lumber_available = arc4random()%(RED_TOWN_LUMBER_MAX_RESTOCK - RED_TOWN_LUMBER_MIN_RESTOCK + 1) + RED_TOWN_LUMBER_MIN_RESTOCK;
    loc_array[0]->stone_available = arc4random()%(RED_TOWN_STONE_MAX_RESTOCK - RED_TOWN_STONE_MIN_RESTOCK + 1) + RED_TOWN_STONE_MIN_RESTOCK;
    loc_array[0]->silk_available = arc4random()%(RED_TOWN_SILK_MAX_RESTOCK - RED_TOWN_SILK_MIN_RESTOCK + 1) + RED_TOWN_SILK_MIN_RESTOCK;
    loc_array[0]->ore_available = arc4random()%(RED_TOWN_ORE_MAX_RESTOCK - RED_TOWN_ORE_MIN_RESTOCK + 1) + RED_TOWN_ORE_MIN_RESTOCK;
    loc_array[0]->gem_available = arc4random()%(RED_TOWN_GEM_MAX_RESTOCK - RED_TOWN_GEM_MIN_RESTOCK + 1) + RED_TOWN_GEM_MIN_RESTOCK;
    
    loc_array[0]->lumber_price = arc4random()%(RED_TOWN_LUMBER_MAX_PRICE - RED_TOWN_LUMBER_MIN_PRICE + 1) + RED_TOWN_LUMBER_MIN_PRICE;
    loc_array[0]->stone_price = arc4random()%(RED_TOWN_STONE_MAX_PRICE - RED_TOWN_STONE_MIN_PRICE + 1) + RED_TOWN_STONE_MIN_PRICE;
    loc_array[0]->silk_price = arc4random()%(RED_TOWN_SILK_MAX_PRICE - RED_TOWN_SILK_MIN_PRICE + 1) + RED_TOWN_SILK_MIN_PRICE;
    loc_array[0]->ore_price = arc4random()%(RED_TOWN_ORE_MAX_PRICE - RED_TOWN_ORE_MIN_PRICE + 1) + RED_TOWN_ORE_MIN_PRICE;
    loc_array[0]->gem_price = arc4random()%(RED_TOWN_GEM_MAX_PRICE - RED_TOWN_GEM_MIN_PRICE + 1) + RED_TOWN_GEM_MIN_PRICE;
    
    loc_array[1]->name = AZURE_VALLEY;
    loc_array[1]->lumber_available = arc4random()%(AZURE_VALLEY_LUMBER_MAX_RESTOCK - AZURE_VALLEY_LUMBER_MIN_RESTOCK + 1) + AZURE_VALLEY_LUMBER_MIN_RESTOCK;
    loc_array[1]->stone_available = arc4random()%(AZURE_VALLEY_STONE_MAX_RESTOCK - AZURE_VALLEY_STONE_MIN_RESTOCK + 1) + AZURE_VALLEY_STONE_MIN_RESTOCK;
    loc_array[1]->silk_available = arc4random()%(AZURE_VALLEY_SILK_MAX_RESTOCK - AZURE_VALLEY_SILK_MIN_RESTOCK + 1) + AZURE_VALLEY_SILK_MIN_RESTOCK;
    loc_array[1]->ore_available = arc4random()%(AZURE_VALLEY_ORE_MAX_RESTOCK - AZURE_VALLEY_ORE_MIN_RESTOCK + 1) + AZURE_VALLEY_ORE_MIN_RESTOCK;
    loc_array[1]->gem_available = arc4random()%(AZURE_VALLEY_GEM_MAX_RESTOCK - AZURE_VALLEY_GEM_MIN_RESTOCK + 1) + AZURE_VALLEY_GEM_MIN_RESTOCK;
    
    loc_array[1]->lumber_price = arc4random()%(AZURE_VALLEY_LUMBER_MAX_PRICE - AZURE_VALLEY_LUMBER_MIN_PRICE + 1) + AZURE_VALLEY_LUMBER_MIN_PRICE;
    loc_array[1]->stone_price = arc4random()%(AZURE_VALLEY_STONE_MAX_PRICE - AZURE_VALLEY_STONE_MIN_PRICE + 1) + AZURE_VALLEY_STONE_MIN_PRICE;
    loc_array[1]->silk_price = arc4random()%(AZURE_VALLEY_SILK_MAX_PRICE - AZURE_VALLEY_SILK_MIN_PRICE + 1) + AZURE_VALLEY_SILK_MIN_PRICE;
    loc_array[1]->ore_price = arc4random()%(AZURE_VALLEY_ORE_MAX_PRICE - AZURE_VALLEY_ORE_MIN_PRICE + 1) + AZURE_VALLEY_ORE_MIN_PRICE;
    loc_array[1]->gem_price = arc4random()%(AZURE_VALLEY_GEM_MAX_PRICE - AZURE_VALLEY_GEM_MIN_PRICE + 1) + AZURE_VALLEY_GEM_MIN_PRICE;
    
    loc_array[2]->name = EMERALD_CITY;
    loc_array[2]->lumber_available = arc4random()%(EMERALD_CITY_LUMBER_MAX_RESTOCK - EMERALD_CITY_LUMBER_MIN_RESTOCK + 1) + EMERALD_CITY_LUMBER_MIN_RESTOCK;
    loc_array[2]->stone_available = arc4random()%(EMERALD_CITY_STONE_MAX_RESTOCK - EMERALD_CITY_STONE_MIN_RESTOCK + 1) + EMERALD_CITY_STONE_MIN_RESTOCK;
    loc_array[2]->silk_available = arc4random()%(EMERALD_CITY_SILK_MAX_RESTOCK - EMERALD_CITY_SILK_MIN_RESTOCK + 1) + EMERALD_CITY_SILK_MIN_RESTOCK;
    loc_array[2]->ore_available = arc4random()%(EMERALD_CITY_ORE_MAX_RESTOCK - EMERALD_CITY_ORE_MIN_RESTOCK + 1) + EMERALD_CITY_ORE_MIN_RESTOCK;
    loc_array[2]->gem_available = arc4random()%(EMERALD_CITY_GEM_MAX_RESTOCK - EMERALD_CITY_GEM_MIN_RESTOCK + 1) + EMERALD_CITY_GEM_MIN_RESTOCK;
    
    loc_array[2]->lumber_price = arc4random()%(EMERALD_CITY_LUMBER_MAX_PRICE - EMERALD_CITY_LUMBER_MIN_PRICE + 1) + EMERALD_CITY_LUMBER_MIN_PRICE;
    loc_array[2]->stone_price = arc4random()%(EMERALD_CITY_STONE_MAX_PRICE - EMERALD_CITY_STONE_MIN_PRICE + 1) + EMERALD_CITY_STONE_MIN_PRICE;
    loc_array[2]->silk_price = arc4random()%(EMERALD_CITY_SILK_MAX_PRICE - EMERALD_CITY_SILK_MIN_PRICE + 1) + EMERALD_CITY_SILK_MIN_PRICE;
    loc_array[2]->ore_price = arc4random()%(EMERALD_CITY_ORE_MAX_PRICE - EMERALD_CITY_ORE_MIN_PRICE + 1) + EMERALD_CITY_ORE_MIN_PRICE;
    loc_array[2]->gem_price = arc4random()%(EMERALD_CITY_GEM_MAX_PRICE - EMERALD_CITY_GEM_MIN_PRICE + 1) + EMERALD_CITY_GEM_MIN_PRICE;
    
    loc_array[3]->name = GREY_CANYON;
    loc_array[3]->lumber_available = arc4random()%(GREY_CANYON_LUMBER_MAX_RESTOCK - GREY_CANYON_LUMBER_MIN_RESTOCK + 1) + GREY_CANYON_LUMBER_MIN_RESTOCK;
    loc_array[3]->stone_available = arc4random()%(GREY_CANYON_STONE_MAX_RESTOCK - GREY_CANYON_STONE_MIN_RESTOCK + 1) + GREY_CANYON_STONE_MIN_RESTOCK;
    loc_array[3]->silk_available = arc4random()%(GREY_CANYON_SILK_MAX_RESTOCK - GREY_CANYON_SILK_MIN_RESTOCK + 1) + GREY_CANYON_SILK_MIN_RESTOCK;
    loc_array[3]->ore_available = arc4random()%(GREY_CANYON_ORE_MAX_RESTOCK - GREY_CANYON_ORE_MIN_RESTOCK + 1) + GREY_CANYON_ORE_MIN_RESTOCK;
    loc_array[3]->gem_available = arc4random()%(GREY_CANYON_GEM_MAX_RESTOCK - GREY_CANYON_GEM_MIN_RESTOCK + 1) + GREY_CANYON_GEM_MIN_RESTOCK;
    
    loc_array[3]->lumber_price = arc4random()%(GREY_CANYON_LUMBER_MAX_PRICE - GREY_CANYON_LUMBER_MIN_PRICE + 1) + GREY_CANYON_LUMBER_MIN_PRICE;
    loc_array[3]->stone_price = arc4random()%(GREY_CANYON_STONE_MAX_PRICE - GREY_CANYON_STONE_MIN_PRICE + 1) + GREY_CANYON_STONE_MIN_PRICE;
    loc_array[3]->silk_price = arc4random()%(GREY_CANYON_SILK_MAX_PRICE - GREY_CANYON_SILK_MIN_PRICE + 1) + GREY_CANYON_SILK_MIN_PRICE;
    loc_array[3]->ore_price = arc4random()%(GREY_CANYON_ORE_MAX_PRICE - GREY_CANYON_ORE_MIN_PRICE + 1) + GREY_CANYON_ORE_MIN_PRICE;
    loc_array[3]->gem_price = arc4random()%(GREY_CANYON_GEM_MAX_PRICE - GREY_CANYON_GEM_MIN_PRICE + 1) + GREY_CANYON_GEM_MIN_PRICE;
    
    loc_array[4]->name = PIRATE_COVE;
    loc_array[4]->lumber_available = arc4random()%(PIRATE_COVE_LUMBER_MAX_RESTOCK - PIRATE_COVE_LUMBER_MIN_RESTOCK + 1) + PIRATE_COVE_LUMBER_MIN_RESTOCK;
    loc_array[4]->stone_available = arc4random()%(PIRATE_COVE_STONE_MAX_RESTOCK - PIRATE_COVE_STONE_MIN_RESTOCK + 1) + PIRATE_COVE_STONE_MIN_RESTOCK;
    loc_array[4]->silk_available = arc4random()%(PIRATE_COVE_SILK_MAX_RESTOCK - PIRATE_COVE_SILK_MIN_RESTOCK + 1) + PIRATE_COVE_SILK_MIN_RESTOCK;
    loc_array[4]->ore_available = arc4random()%(PIRATE_COVE_ORE_MAX_RESTOCK - PIRATE_COVE_ORE_MIN_RESTOCK + 1) + PIRATE_COVE_ORE_MIN_RESTOCK;
    loc_array[4]->gem_available = arc4random()%(PIRATE_COVE_GEM_MAX_RESTOCK - PIRATE_COVE_GEM_MIN_RESTOCK + 1) + PIRATE_COVE_GEM_MIN_RESTOCK;
    
    loc_array[4]->lumber_price = arc4random()%(PIRATE_COVE_LUMBER_MAX_PRICE - PIRATE_COVE_LUMBER_MIN_PRICE + 1) + PIRATE_COVE_LUMBER_MIN_PRICE;
    loc_array[4]->stone_price = arc4random()%(PIRATE_COVE_STONE_MAX_PRICE - PIRATE_COVE_STONE_MIN_PRICE + 1) + PIRATE_COVE_STONE_MIN_PRICE;
    loc_array[4]->silk_price = arc4random()%(PIRATE_COVE_SILK_MAX_PRICE - PIRATE_COVE_SILK_MIN_PRICE + 1) + PIRATE_COVE_SILK_MIN_PRICE;
    loc_array[4]->ore_price = arc4random()%(PIRATE_COVE_ORE_MAX_PRICE - PIRATE_COVE_ORE_MIN_PRICE + 1) + PIRATE_COVE_ORE_MIN_PRICE;
    loc_array[4]->gem_price = arc4random()%(PIRATE_COVE_GEM_MAX_PRICE - PIRATE_COVE_GEM_MIN_PRICE + 1) + PIRATE_COVE_GEM_MIN_PRICE;
}
