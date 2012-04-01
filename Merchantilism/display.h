//
//  display.h
//  Mercantilism
//
//  Created by JP Moral on 3/31/12.
//  Copyright (c) 2012 Codeflux. All rights reserved.
//

#ifndef Mercantilism_display_h
#define Mercantilism_display_h

#include "player_and_locations.h"
#include "actions_state.h"

void display_player_profile(PLAYER *);
void display_main_menu(void);
void display_help(void);
void display_destination_choice_menu(LOCATION *[], int);
void display_bank_actions_menu(void);
void display_location_actions_menu(LOCATION *);
void display_endgame_message(GAME_STATE);

#endif
