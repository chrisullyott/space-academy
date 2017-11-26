using namespace std;

class Ship
{
    public:
        // Constants.
        static const int MIN_SHIELDS = 0;
        static const int MAX_SHIELDS = 100;

        // Properties.
        int shields;
        int agility;
        int resilience;
        int weapon;
        Character *pilot;

        // Constructor.
        Ship()
        {
            this->shields = MAX_SHIELDS;
        }

        string getPilotName()
        {
            return this->pilot->getName();
        }

        int getAgility()
        {
            return this->agility;
        }

        int getResilience()
        {
            return this->resilience;
        }

        int getShields()
        {
            return this->shields;
        }

        int getWeapon()
        {
            return this->weapon;
        }

        Ship& addShields(int points)
        {
            if ((this->shields + points) > MAX_SHIELDS) {
                this->shields = MAX_SHIELDS;
            } else {
                this->shields += points;
            }

            return *this;
        }

        Ship& subtractShields(int points)
        {
            if ((this->shields - points) < MIN_SHIELDS) {
                this->shields = MIN_SHIELDS;
            } else {
                this->shields -= points;
            }

            return *this;
        }
};
