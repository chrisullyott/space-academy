using namespace std;

class Screen
{
    public:
        static void out(string text)
        {
            cout << text << "\n\n";
        }

        static void clear()
        {
            for (int n = 0; n < 80; n++) {
                printf("\n");
            }
        }
};
