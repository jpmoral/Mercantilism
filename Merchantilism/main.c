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
#include <string.h>
#include "Constants.h"
#include "player_and_locations.h"
#include "display.h"
#include "actions_state.h"

void game(void);
void help(void);


int main (int argc, const char * argv[]) {
    
    char choice = '\0';
    char *valid_choices = VALID_MAIN_MENU_CHOICES;
    
    while (choice != 'Q') {
        
        choice = '\0';
        display_main_menu();
        
        while (!strpbrk(valid_choices, &choice)) {
            choice = getchar();
            choice = toupper(choice);
        }
        
        switch(choice){
            case 'P':
                game();
                break;
            case 'H':
                help();
                break;
            case 'Q':
                printf("Goodbye!\n");
                break;
        }
    }
    
    return 0;
}

void game (void) {
    
    PLAYER *player = (PLAYER *)malloc(sizeof(*player));
    LOCATION *red = (LOCATION *)malloc(sizeof(*red)), *azure = (LOCATION *)malloc(sizeof(*azure)), *emerald = (LOCATION *)malloc(sizeof(*emerald)), *grey = (LOCATION *)malloc(sizeof(*grey)), *pirate = (LOCATION *)malloc(sizeof(*pirate));
    LOCATION *loc_array[] = {red, azure, emerald, grey, pirate};
        
    initialize_player(player);
    initialize_locations(loc_array, NUMBER_OF_LOCATIONS);
    
    char choice = '\0';
    char *valid_choices = VALID_LOCATION_CHOICES;
    END_TURN end_turn;
    GAME_STATE game_state = ONGOING;
    
    while (choice != 'Q' && game_state == ONGOING) {
        
        choice = '\0';
        display_player_profile(player);
        display_destination_choice_menu(loc_array, NUMBER_OF_LOCATIONS);
    
        while (!strpbrk(valid_choices, &choice)) {
            choice = getchar();
            choice = toupper(choice);
        }
        
        switch(choice){
            case 'B':
                end_turn = enter_bank(player);
                break;
            case 'R':
                end_turn = enter_location(player, loc_array[0]);
                break;
            case 'A':
                end_turn = enter_location(player, loc_array[1]);
                break;
            case 'E':
                end_turn = enter_location(player, loc_array[2]);
                break;
            case 'G':
                end_turn = enter_location(player, loc_array[3]);
                break;
            case 'P':
                end_turn = enter_location(player, loc_array[4]);
                break;
            case 'Q':
                printf("Goodbye!\n");
                return;
                break;
        }
        
        if (end_turn == YES) {
            updateGameData(player, loc_array, NUMBER_OF_LOCATIONS);
            game_state = get_game_state(player);
        }
    }
    
    display_player_profile(player);
    display_endgame_message(game_state);
    consume_newline();
    char c;
    c = getchar();
    
    free(player);
    
    int i;
    for (i = 0; i < NUMBER_OF_LOCATIONS; i++) {
        free(loc_array[i]);
    }
}

void help(void) {
    
    display_help();
    consume_newline();
    char c;
    c = getchar();
}
