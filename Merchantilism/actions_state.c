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
    
    float cash = player->cash;
    float debt = player->debt;
    float amountToBorrow;
    
    printf("Amount to borrow: ");
    scanf ("%f", &amountToBorrow);
    
    player->cash = cash + amountToBorrow;
    player->debt = debt + amountToBorrow;
    updatePlayerNetBalance(player);
    
    return YES;
}

END_TURN pay_bank(PLAYER *player) {
    
    float cash = player->cash;
    float debt = player->debt;
    float amountToPay;
    
    printf ("Amount to repay: ");
    scanf ("%f", &amountToPay);
    
    VALID_AMOUNT canPay = is_loan_payment_amount_valid(amountToPay, cash, debt);
    switch(canPay){
        case NO:
            system(SYSTEM_CLEAR);
            consume_newline();
            printf("Invalid amount.\nPress ENTER to continue: ");
            char c;
            c = getchar();
            return NO;
            break;
        case YES:
            break;
    }
    player->cash  = cash - amountToPay;
    player->debt = debt - amountToPay;
    updatePlayerNetBalance(player);
    return YES;
}

END_TURN invest(PLAYER *player) {
    
    float inv =  player->investment;
    float cash = player->cash;
    float amountToInvest;
    
    printf("Amount to invest: ");
    scanf("%f", &amountToInvest);
    
    VALID_AMOUNT canInvest = is_investment_amount_valid(amountToInvest, cash);
    switch(canInvest){
        case NO: 
            system(SYSTEM_CLEAR);
            consume_newline();
            printf("Not enough money.\nPress ENTER to continue: ");
            char c;
            c = getchar();
            break;
        case YES:
            break;
            
    }
    player->investment = inv + amountToInvest;
    player->cash = cash - amountToInvest;
    updatePlayerNetBalance(player);
    
    return YES;
}

END_TURN withdraw_investment(PLAYER *player) {

    float inv =  player->investment;
    float cash = player->cash;
    float amountToWithdraw;
    
    printf("Amount to withdraw: ");
    scanf("%f", &amountToWithdraw);
    
    VALID_AMOUNT canWithdraw = is_investment_amount_valid(amountToWithdraw, inv);
    switch(canWithdraw){
        case NO: 
            system(SYSTEM_CLEAR);
            consume_newline();
            printf("You don't have that much invested.\nPress ENTER to continue: ");
            char c;
            c = getchar();
            return NO;
            break;
        case YES:
            break;
            
    }
    player->investment = inv - amountToWithdraw;
    player->cash = cash + amountToWithdraw;
    updatePlayerNetBalance(player);
    
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

VALID_AMOUNT is_investment_amount_valid(float amountToInvest, float cashOnHand){
    
    if (amountToInvest <= cashOnHand) {
        return YES;
    } else { 
        return NO;
    }
}

VALID_AMOUNT is_loan_payment_amount_valid(float amountToPay, float cashOnHand, float debt){
    
    if (amountToPay <= cashOnHand && amountToPay <= debt) {
        return YES;
    } else {
        return NO;
    }
}

VALID_AMOUNT is_withdrawal_amount_valid(float amountToWithdraw, float investment) {
    
    if (amountToWithdraw <= investment) {
        return YES;
    } else { 
        return NO;
    }
}

void consume_newline(void) {
    
    while (getchar() != '\n') {
        
    }
}
