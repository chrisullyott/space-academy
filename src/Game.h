using namespace std;

class Game
{
    public:
        // Properties.
        Character *hero;
        Ship *ship;
        string planet;

        // Constructor.
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
            this->launch();
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

        void askShip()
        {
            string text = "Which ship do you choose?";
            string ships[2] = {
                "Gamma Flyer",
                "Cargo Barge"
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
            r += "Its cannons can dish out up to " + to_string(this->ship->getWeapon()) + " damage,";
            r += " if your shot lands.\n";

            if (this->ship->getResilience() > this->ship->getAgility()) {
                r += "So yeah, it's tough, but kinda slow.";
            } else {
                r += "So yeah, it's fast, but can't take much of a beating.";
            }

            Screen::out(r);

            Screen::enterToContinue();
        }

        void launch()
        {
            string r = "OK! You're headed out in your " + this->ship->getName();
            r += ". Good luck, " + this->hero->getName() + "!";

            Screen::out(r);

            sleep(3);
        }

        void doBattle()
        {
            Character *enemyPilot = new Character();
            enemyPilot->setName("R-Z4");
            TamronWarship *enemyShip = new TamronWarship(enemyPilot);

            Screen::out("RED ALERT! Enemy warship approaching!");
            sleep(2);
            Screen::out("It's " + enemyShip->getPilotName() + " piloting a Tamron Warship!");
            sleep(2);

            Battle battle(this->ship, enemyShip);
            battle.engage();
        }

        void end()
        {
            Screen::out("======== GAME OVER ========\n");
        }
};
