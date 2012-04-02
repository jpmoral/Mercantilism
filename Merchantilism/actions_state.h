//
//  player_actions.h
//  Mercantilism
//
//  Created by JP Moral on 3/31/12.
//  Copyright (c) 2012 Codeflux. All rights reserved.
//

#ifndef Mercantilism_player_actions_h
#define Mercantilism_player_actions_h

#include "player_and_locations.h"

typedef enum {
    NO,
    YES
} END_TURN, VALID_AMOUNT;

typedef enum {
    ONGOING,
    WIN,
    LOSS
} GAME_STATE;

typedef enum {
    LUMBER,
    STONE,
    SILK,
    ORE,
    GEM
} GOODS;

END_TURN enter_bank(PLAYER *);
END_TURN enter_location(PLAYER *, LOCATION *);
END_TURN take_out_loan(PLAYER *);
END_TURN withdraw_investment(PLAYER *);
END_TURN pay_bank(PLAYER *);
END_TURN invest(PLAYER *);
END_TURN buy_goods(PLAYER *, LOCATION *, GOODS);
END_TURN sell_goods(PLAYER *, LOCATION *, GOODS);
GAME_STATE get_game_state(PLAYER *);
VALID_AMOUNT is_investment_amount_valid(float, float);
VALID_AMOUNT is_loan_payment_amount_valid(float, float, float);
VALID_AMOUNT is_withdrawal_amount_valid(float, float);
VALID_AMOUNT is_purchase_valid(float, int, int, int);
void consume_newline(void);

#endif
