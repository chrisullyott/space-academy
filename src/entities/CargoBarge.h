using namespace std;

class CargoBarge : public Ship
{
    public:
        CargoBarge(Character *pilot)
        {
            this->name = "Cargo Barge";
            this->pilot = pilot;
            this->agility = 30;
            this->resilience = 60;
            this->weapon = 20;
        }
};
