//
//  DealGame.h
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 14/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#ifndef __HeyWorld__DealGame__
#define __HeyWorld__DealGame__

#include <iostream>

class DealGame
{
    private:
    void shuffleSprites();
    void createDeck();
    
    public:
    int typeGame;
    int difficulty;
    DealGame(int game, int diff);
    void startGame();
    void chooseGame(int g);
    void showSprite();
    bool checkSprite();

};

#endif /* defined(__HeyWorld__DealGame__) */
