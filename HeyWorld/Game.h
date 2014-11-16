//
//  DealGame.h
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 14/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#ifndef __HeyWorld__Game__
#define __HeyWorld__Game__
#include "GameObjects.h"
#include "LevelDeck.h"
#include "User.h"
#include "Cube.h"
#include "Imageloader.h"

#include <iostream>
#include <vector>

class Game
{
    private:
    std::vector<Sprite *> gameSprites;
    void shuffleSprites();
    void createDeck();
    void initRenderImages();
    void loadTexture(Image* image, int k);
    int numRondas;
    //int typeGame;
    int difficulty;
    LevelDeck deckLevel;
    bool endGame;
    bool win;
    GLuint textures[30];
    User user;
    Cube cubo;
    
    public:
    Game();
    Game(int diff);
    //void setTypeGame(int type);
    void setDifficultyGame(int dif);
    void startGame();
    void playGame();
    void finishGame();
    void draw();
    void showSprite();
    bool checkSprite(int codeCountry);

};

#endif /* defined(__HeyWorld__DealGame__) */
