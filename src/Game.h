#include <iostream>
#include <string>
#include <unistd.h>

#include "Screen.h"
#include "Intro.h"
#include "Query.h"
#include "Question.h"
#include "Selection.h"
#include "Character.h"
#include "Ship.h"
#include "ships/CargoBarge.h"
#include "ships/GammaFlyer.h"
#include "ships/TamronWarship.h"
#include "Battle.h"

using namespace std;

class Game
{
    public:
        Character *hero;
        Ship *ship;
        string planet;

        Game()
        {
            this->hero = new Character();
        }

        void start()
        {
            Intro::graphic();
            Intro::credits();

            this->askName();
            this->askPlanet();
            this->askShip();
            this->doBattle();

            this->end();
        }

    private:
        void askName()
        {
            Question q("Welcome, recruit! Please give us your name.");
            string a = q.ask().get();
            this->hero->setName(a);

            string r = "Oh, \"" + this->hero->getName() + "\" huh?";
            r += "\nNice to meet you. Be careful out there in space, ok?";

            Screen::out(r);
        }

        void askShip()
        {
            string text = "Which ship do you choose?";
            string ships[2] = {
                "gamma flyer",
                "cargo barge"
            };

            Selection s(text, ships, 2);
            int a = s.ask().get();

            switch(a) {
                case 0:
                    this->ship = new GammaFlyer(this->hero);
                    Screen::out("Good choice! The new flyers are legit.");
                    break;
                case 1:
                    this->ship = new CargoBarge(this->hero);
                    Screen::out("Really? No one picks the cargos. Okay then...");
                    break;
            }

            string r = "Your ship has " + to_string(this->ship->getAgility()) + " agility";
            r += " and " + to_string(this->ship->getResilience()) + " hull resilience.\n";
            r += "Its cannons can dish out up to " + to_string(this->ship->getWeapon()) + " damage.\n";

            if (this->ship->getResilience() > this->ship->getAgility()) {
                r += "So yeah, it's tough, but kinda slow.";
            } else {
                r += "So yeah, it's fast, but can't take much of a beating, okay?";
            }

            Screen::out(r);

        }

        void askPlanet()
        {
            string text = "Where would you like to train?";
            string planets[2] = {
                "Neebus",
                "Omnicron 3"
            };

            Selection s(text, planets, 2);
            int a = s.ask().get();
            this->planet = planets[a];

            switch(a) {
                case 0:
                    Screen::out("Heh... the Neeb...");
                    break;
                case 1:
                    Screen::out("Nice pick, " + this->hero->getName() + '.');
                    break;
            }

            Screen::out("OK! You've arrived at " + this->planet + '.');
        }

        void doBattle()
        {
            Character *enemyPilot = new Character();
            enemyPilot->setName("R-Z4");
            TamronWarship *enemyShip = new TamronWarship(enemyPilot);

            sleep(8);
            Screen::out("Holy crap, an enemy warship is approaching!");
            sleep(2);
            Screen::out("It's " + enemyShip->getPilotName() + " piloting a Tamron Warship!");

            Battle battle(this->ship, enemyShip);
            battle.engage();
        }

        void askMarket()
        {
            cout << "You're feeling a bit peckish.\n";

            string text = "Want to make a pit stop at the market?";
            string o[2] = {
                "Yes",
                "No"
            };

            Selection s(text, o, 2);
            int a = s.ask().get();

            switch(a) {
                case 0:
                    this->askMarketItems();
                    break;
                case 1:
                    cout << "Well, your peckishness turned into full-blown hangry-itis,\n";
                    cout << "and you were unable to complete your training. Jeez!\n";
                    this->end();
                    break;
            }
        }

        void askMarketItems()
        {
            cout << "You find yourself at an asian market. What looks good?\n";

            string o[3] = {
                "Bulgogi beef",
                "Hagfish",
                "Kimchi ramen"
            };

        }

        void end()
        {
            Screen::out("======== GAME OVER ========\n");
        }
};
