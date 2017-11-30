using namespace std;

class Character
{
    public:
        // Properties.
        string name;

        // Constructor.
        Character()
        {
            this->name = "Player 1";
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
};
