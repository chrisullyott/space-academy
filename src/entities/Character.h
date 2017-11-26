using namespace std;

class Character
{
    public:
        // Constants.
        static const int MIN_HEALTH = 0;
        static const int MAX_HEALTH = 100;
        static const int PER_DIEM = 20;

        // Properties.
        string name;
        int health;
        float money;

        // Constructor.
        Character()
        {
            this->name = "Player 1";
            this->health = MAX_HEALTH;
            this->money = PER_DIEM;
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

        Character& addMoney(float value)
        {
            this->money += value;

            return *this;
        }

        Character& subtractMoney(float value)
        {
            if ((this->money - value) < 0) {
                cout << "Can't spend " << value;
                cout << ", you only have ";
                cout << this->money << ".\n";
            } else {
                this->money -= value;
            }

            return *this;
        }

        int getMoney()
        {
            return this->money;
        }
};
