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
#include "Monument.h"
#include "Flag.h"
#include "Character.h"

class LevelDeck
{
    private:
    
    //monumentos
    std::vector<Monument> touristMonuments;
    std::vector<Monument> agentMonuments;
    std::vector<Monument> guruMonuments;
    //flags
    std::vector<Flag> touristFlag;
    std::vector<Flag>  agentFlag;
    std::vector<Flag>  guruFlag;
    
    //characters
    std::vector<Character> touristCharacter;
    std::vector<Character> agentCharacter;
    std::vector<Character> guruCharacter;
    
    public:
    std::vector<Sprite> getLevelDeck();

};

#endif /* defined(__HeyWorld__LevelDeck__) */
