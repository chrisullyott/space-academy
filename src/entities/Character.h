using namespace std;

class Character
{
    public:
        // Constants.
        static const int MIN_HEALTH = 0;
        static const int MAX_HEALTH = 100;

        // Properties.
        string name;
        int health;

        // Constructor.
        Character()
        {
            this->name = "Player 1";
            this->health = MAX_HEALTH;
        }

        Character& setName(string name)
        {
            this->name = name;

            return *this;
        }

        string getName()
        {
            return this->name;
        }

        Character& addHealth(int points)
        {
            if ((this->health + points) > MAX_HEALTH) {
                this->health = MAX_HEALTH;
            } else {
                this->health += points;
            }

            return *this;
        }

        Character& subtractHealth(int points)
        {
            if ((this->health - points) < MIN_HEALTH) {
                this->health = MIN_HEALTH;
            } else {
                this->health -= points;
            }

            return *this;
        }

        int getHealth()
        {
            return this->health;
        }
};
