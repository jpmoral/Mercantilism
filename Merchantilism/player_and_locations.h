//
//  player_and_locations.h
//  Mercantilism
//
//  Created by JP Moral on 3/31/12.
//  Copyright (c) 2012 Codeflux. All rights reserved.
//

#ifndef Mercantilism_player_and_locations_h
#define Mercantilism_player_and_locations_h

typedef struct {
    float cash, investment, debt, net_balance;
    int lumber, stone, silk, ore, gem;
} PLAYER;

typedef struct {
    char *name, *menu_name;
    int lumber_available, stone_available, silk_available, ore_available, gem_available;
    int lumber_price, stone_price, silk_price, ore_price, gem_price;
    int lumber_min_restock, stone_min_restock, silk_min_restock, ore_min_restock, gem_min_restock;
    int lumber_max_restock, stone_max_restock, silk_max_restock, ore_max_restock, gem_max_restock;
    int lumber_min_price, stone_min_price, silk_min_price, ore_min_price, gem_min_price;
    int lumber_max_price, stone_max_price, silk_max_price, ore_max_price, gem_max_price;
} LOCATION;

void initialize_player(PLAYER *);
void initialize_locations(LOCATION *[], int numer_of_locations);
void updateGameData(PLAYER *, LOCATION *[]);
void updatePlayerNetBalance(PLAYER *);

#endif
