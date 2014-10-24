//
//  DealGame.h
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 14/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#ifndef __HeyWorld__DealGame__
#define __HeyWorld__DealGame__
#include "GameObjects.h"

#include <iostream>
#include <vector>

class DealGame
{
    private:
    std::vector<Sprite> gameSprites;
    void shuffleSprites();
    void createDeck();
    void deckMonuments();
    void deckFlags();
    void deckCharacters();
    int numRondas;
    
    public:
    int typeGame;
    int difficulty;
    DealGame(int game, int diff);
    void startGame();
    void chooseGame(int g);
    void showSprite();
    bool checkSprite(int codeCountry);

};

#endif /* defined(__HeyWorld__DealGame__) */
