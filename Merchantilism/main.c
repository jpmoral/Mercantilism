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

typedef enum {
    NO,
    YES
} END_TURN;

typedef enum {
    ONGOING,
    WIN,
    LOSS
} GAME_STATE;

void game(void);
void help(void);
END_TURN enter_bank(PLAYER *);
END_TURN enter_location(PLAYER *, LOCATION *);
void consume_newline(void);

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
    
    PLAYER *player = (PLAYER *)malloc(sizeof(PLAYER));
    LOCATION *red = (LOCATION *)malloc(sizeof(PLAYER)), *azure = (LOCATION *)malloc(sizeof(PLAYER)), *emerald = (LOCATION *)malloc(sizeof(PLAYER)), *grey = (LOCATION *)malloc(sizeof(PLAYER)), *pirate = (LOCATION *)malloc(sizeof(PLAYER));
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
                
                break;
            case 'A':
                
                break;
            case 'E':
                
                break;
            case 'G':
                
                break;
            case 'P':
                
                break;
            case 'Q':
                printf("Goodbye!\n");
                return;
                break;
        }
        
        if (end_turn == YES) {
            // update game data
        }
    }
}

void help(void) {
    
    display_help();
    consume_newline();
    char c;
    c = getchar();
}

END_TURN enter_bank(PLAYER *player) {
    
    display_player_profile(player);
    display_bank_actions_menu();
    char choice = '\0';
    char *valid_choices = VALID_BANK_ACTIONS;
    
    while (!strpbrk(valid_choices, &choice)) {
        choice = getchar();
        choice = toupper(choice);
    }
    
    switch (choice) {
        case 'L':
            
            return YES;
            break;
        case 'P':
            
            return YES;
            break;
        case 'M':
            
            return NO;
            break;
    }
    
    return NO;
}

END_TURN enter_location(PLAYER *player, LOCATION *location) {
    
    return YES;
}

void consume_newline(void) {
    
    while (getchar() != '\n') {
        
    }
}