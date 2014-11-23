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

static bool answeredCorrect;
static int countTimer;
static std::vector<Sprite *> gameSprites;
static int numSprite;
static Cube cubo;
static User user;
static int difficulty;
static bool endGame;
static bool win;
static float rot_angle_y;
static float rot_angle_x;
static float rot_angle;
static int _num;
static char tiempo[200];


class Game
{
    private:
        void shuffleSprites();
    void createDeck();
    void initRenderImages();
    void loadTexture(Image* image, int k);

   

    void showSprite();
   
    void lostQuestion(int type); //0 contaste mal pero aun hay tiempo, 1 se acabo el tiempo y cambio a siguiente pregunta
    static void timerQuestion(int v);
    static void timerFinishGame(int v);
    
    //int typeGame;
    
    LevelDeck deckLevel;

    GLuint textures[30];
    bool checkSprite(int codeCountry);


    
    public:
    Game();
    Game(int diff);
    //void setTypeGame(int type);
    bool isGameFinished();
    void setDifficultyGame(int dif);
    void startGame();
    void initReloj();
    void playGame();
    void finishGame();
    void displayTiempo();
    void draw();
    bool mapClick(int codeCountry);

};

#endif /* defined(__HeyWorld__DealGame__) */
