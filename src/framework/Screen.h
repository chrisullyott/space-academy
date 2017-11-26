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
            for (int n = 0; n < 10; n++) {
                printf("\n\n\n\n\n\n\n\n\n\n");
            }
        }
};
