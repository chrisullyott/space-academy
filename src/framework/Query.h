using namespace std;

class Query
{
    private:
        virtual string build() = 0;
        virtual Query& ask() = 0;
        virtual bool isAnswered() = 0;
};
