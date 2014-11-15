//
//  LevelDeck.h
//  HeyWorld
//
//  Created by Maria Montserrat Lozano on 15/10/14.
//  Copyright (c) 2014 Montserrat Lozano Dieck. All rights reserved.
//

#ifndef __HeyWorld__LevelDeck__
#define __HeyWorld__LevelDeck__

#include <iostream>
#include <vector>
#include "GameObjects.h"

class LevelDeck 
{
    private:
    
    //monumentos
    
    std::vector<Flag> touristDeck;
    std::vector<Character> agentDeck;
    std::vector<Monument> guruDeck;

    public:
    //std::vector<Sprite> gameDeck;
    std::vector<Flag> getTouristDeck();
    std::vector<Character> getAgentDeck();
    std::vector<Monument> getGuruDeck();
    
    //void getLevelDeck(int gameId, int difficult);

};

#endif /* defined(__HeyWorld__LevelDeck__) */
