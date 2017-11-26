#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <unistd.h>
#include <stdio.h>

#include "src/entities/Character.h"
#include "src/entities/Ship.h"
#include "src/entities/CargoBarge.h"
#include "src/entities/GammaFlyer.h"
#include "src/entities/TamronWarship.h"

#include "src/framework/Screen.h"
#include "src/framework/Intro.h"
#include "src/framework/Query.h"
#include "src/framework/Question.h"
#include "src/framework/Selection.h"
#include "src/framework/Battle.h"

#include "src/Game.h"

using namespace std;

int main()
{
    Game game;
    game.start();

    return 0;
}
