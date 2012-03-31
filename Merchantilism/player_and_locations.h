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
    char *name;
    int lumber_available, stone_available, silk_available, ore_available, gem_available;
    int lumber_price, stone_price, silk_price, ore_price, gem_price;
} LOCATION;

void initialize_player(PLAYER *);
void initialize_locations(LOCATION *[], int numer_of_locations);


#endif
