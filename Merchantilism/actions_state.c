//
//  player_actions.c
//  Mercantilism
//
//  Created by JP Moral on 3/31/12.
//  Copyright (c) 2012 Codeflux. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "actions_state.h"
#include "display.h"
#include "player_and_locations.h"
#include "Constants.h"

END_TURN enter_bank(PLAYER *player) {
    
    END_TURN end_turn = YES;
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
            end_turn = take_out_loan(player);
            return end_turn;
            break;
        case 'P':
            end_turn = pay_bank(player);
            return end_turn;
            break;
        case 'I':
            end_turn = invest(player);
            return end_turn;
        case 'W':
            end_turn = withdraw_investment(player);
            return end_turn;
        case 'M':
            
            return NO;
            break;
    }
    
    return NO;
}

END_TURN enter_location(PLAYER *player, LOCATION *location) {
    
    return YES;
}

END_TURN take_out_loan(PLAYER *player) {
    
    return YES;
}

END_TURN pay_bank(PLAYER *player) {
    
    return YES;
}

END_TURN invest(PLAYER *player) {
    
    return YES;
}

END_TURN buy_goods(PLAYER *player, LOCATION *loc) {
    
    return YES;
}

END_TURN sell_goods(PLAYER *player, LOCATION *loc) {
    
    return YES;
}

GAME_STATE get_game_state(PLAYER *player) {
    
    float net_balance = player->net_balance;
    if (net_balance >= WINNING_BALANCE) {
        return WIN;
    }
    
    if (net_balance < LOSING_BALANCE) {
        return LOSS;
    }
    
    return ONGOING;
}
void consume_newline(void) {
    
    while (getchar() != '\n') {
        
    }
}
