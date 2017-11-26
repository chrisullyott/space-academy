using namespace std;

class TamronWarship : public Ship
{
    public:
        TamronWarship(Character *pilot)
        {
            this->name = "Tamron Warship";
            this->pilot = pilot;
            this->agility = 28;
            this->resilience = 80;
            this->weapon = 30;
        }
};
