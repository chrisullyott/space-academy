using namespace std;

class Question : public Query
{
    public:
        string prompt;
        string choice;

        Question(string prompt)
        {
            this->prompt = prompt;
        }

        Question& ask()
        {
            int attempt = 1;

            string text = this->build();

            while (!this->isAnswered()) {
                if (attempt > 1) {
                    cout << "\n(Try again?)\n";
                }

                cout << text;

                getline(cin, this->choice, '\n');
                cin.clear();

                attempt++;
            }

            cout << '\n';

            return *this;
        }

        string get()
        {
            return this->choice;
        }

    private:
        string build()
        {
            string output = this->prompt + '\n';

            output += ':';

            return output;
        }

        bool isAnswered()
        {
            return !this->choice.empty();
        }
};
