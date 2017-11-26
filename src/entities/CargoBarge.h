using namespace std;

class CargoBarge : public Ship
{
    public:
        CargoBarge(Character *pilot)
        {
            this->pilot = pilot;
            this->agility = 30;
            this->resilience = 70;
            this->weapon = 20;
        }
};
