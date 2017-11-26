using namespace std;

class Selection : public Query
{
    public:
        // Properties.
        string prompt;
        string *options;
        int size;
        int choice;

        // Constructor.
        Selection(string prompt, string *options, int size)
        {
            this->prompt = prompt;
            this->options = options;
            this->size = size;

            // Choices are zero-indexed, so -1 must be used initially.
            this->choice = -1;
        }

        Selection& ask()
        {
            int input;
            int attempt = 1;

            string text = this->build();

            while (!this->isAnswered()) {
                if (attempt > 1) {
                    cout << "\n(Psst: Choose a number.)\n";
                }

                cout << text;
                cin >> input;
                cin.clear();
                cin.ignore(100, '\n');

                this->choice = input - 1;
                attempt++;
            }

            cout << '\n';

            return *this;
        }

        int get()
        {
            return this->choice;
        }

    private:
        string build()
        {
            string output = this->prompt + '\n';

            for (int i = 0; i < this->size; i++) {
                output += this->option(i, this->options[i]) + '\n';
            }

            output += ':';

            return output;
        }

        string option(int index, string text)
        {
            string num = to_string(index + 1);

            return "(" + num + ") " + text;
        }

        bool isAnswered()
        {
            return (-1 < this->choice) && (this->choice < this->size);
        }
};
