//
//  main.c
//  Merchantilism
//
//  Created by JP Moral on 3/29/12.
//  Copyright (c) 2012 Codeflux. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Constants.h"
#include "player_and_locations.h"
#include "display.h"

void game(void);

int main (int argc, const char * argv[]) {
    
    char choice = '\0';
    
    display_main_menu();
    
    while (choice != 'P' && choice != 'H' && choice != 'E') {
        choice = getchar();
        choice = toupper(choice);
    }
        
    switch(choice){
        case 'P':
            game();
            break;
        case 'H':
            printf("help");
            break;
        case 'E':
            printf("Goodbye!\n");
        break;}
    
    return 0;
}

void game () {
    
    PLAYER *player = (PLAYER *)malloc(sizeof(PLAYER));
    LOCATION *red = (LOCATION *)malloc(sizeof(PLAYER)), *azure = (LOCATION *)malloc(sizeof(PLAYER)), *emerald = (LOCATION *)malloc(sizeof(PLAYER)), *grey = (LOCATION *)malloc(sizeof(PLAYER)), *pirate = (LOCATION *)malloc(sizeof(PLAYER));
    LOCATION *loc_array[] = {red, azure, emerald, grey, pirate};
    
    initialize_player(player);
    initialize_locations(loc_array, NUMBER_OF_LOCATIONS);
    display_player_profile(player);
}