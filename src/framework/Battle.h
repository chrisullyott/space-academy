using namespace std;

class Battle
{
    public:
        // Constants.
        static const int MAX_TURNS = 10;

        // Properties.
        Ship *hero;
        Ship *enemy;
        bool playerShootsFirst;

        // Constructor.
        Battle(Ship *hero, Ship *enemy)
        {
            this->hero = hero;
            this->enemy = enemy;
            this->playerShootsFirst = Battle::randomBool();
        }

        void engage()
        {
            int turns = MAX_TURNS;
            bool canBattle = true;
            bool heroFirst = Battle::randomBool();

            while (turns && canBattle) {
                if (heroFirst) {
                    canBattle = this->heroAttack() && this->enemyAttack();
                } else {
                    canBattle = this->enemyAttack() && this->heroAttack();
                }

                turns -= 1;
            }

            if (!canBattle) {
                if (!this->hero->getShields()) {
                    Battle::defeat();
                    return;
                }

                if (!this->enemy->getShields()) {
                    Battle::victory();
                    return;
                }
            } else {
                Battle::stalemate();
            }

            return;
        }

        bool heroAttack()
        {
            Screen::out("===========================");

            Battle::stats();

            string text = "Attack?";
            string options[2] = {
                "Yes",
                "No"
            };

            Selection s(text, options, 2);
            bool attack = !s.ask().get();

            if (attack) {
                sleep(1);
                return this->attack(this->hero, this->enemy);
            } else {
                Battle::retreat();
                return false;
            }
        }

        bool enemyAttack()
        {
            sleep(2);

            return this->attack(this->enemy, this->hero);
        }

        bool attack(Ship *player1, Ship *player2)
        {
            // Calculate hit damage.
            float effectiveness = (100 - player2->getResilience()) / 100.0;
            float placement = Battle::randomPercent(90, 100);
            int damage = player1->getWeapon() * effectiveness * placement * 4;

            // Whether the shot landed.
            bool hit = Battle::randomBoolOffset(player2->getAgility());

            // Calculate hit damage.
            if (hit) {
                player2->subtractShields(damage);
                Screen::out(player1->getPilotName() + " landed a shot on " + player2->getPilotName() + "'s ship.");

            } else {
                Screen::out(player1->getPilotName() + " fired a shot, but missed.");
            }

            return player1->getShields() && player2->getShields();
        }

        void stats()
        {
            string r = "Your shields:  " + to_string(hero->getShields()) + "\n";
            r += "Enemy shields: " + to_string(enemy->getShields());

            Screen::out(r);
        }

        void static victory()
        {
            Screen::out("You won! The academy will be stoked!");
        }

        void static defeat()
        {
            Screen::out("You were defeated! Now you'll have to hobble back to the station on impulse power :(");
        }

        void static retreat()
        {
            Screen::out("You gave up! Don't worry, I'll still sit next to you in the mess hall.");
        }

        void static stalemate()
        {
            Screen::out("The enemy retreated! I wonder if they'll be back?...");
        }

    private:
        bool randomBool()
    	{
    		srand(unsigned(time(0)));
    		return rand() % 2;
    	}

        bool randomBoolOffset(int offset)
        {
            int value = Battle::randomInt(1, 100);

            return offset < value;
        }

        int randomInt(int min, int max)
		{
			srand(unsigned(time(0)));
			return rand() % ((max + 1) - min) + min;
		}

        float randomPercent(int min, int max)
        {
        	srand(unsigned(time(0)));
        	int value = rand() % (max - min) + min;

        	return value / 100.0;
        }
};
