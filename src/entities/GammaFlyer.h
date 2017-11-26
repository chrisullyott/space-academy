using namespace std;

class GammaFlyer : public Ship
{
    public:
        GammaFlyer(Character *pilot)
        {
            this->name = "Gamma Flyer";
            this->pilot = pilot;
            this->agility = 72;
            this->resilience = 40;
            this->weapon = 24;
        }
};
