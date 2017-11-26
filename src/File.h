#include <fstream>

using namespace std;

class File
{
    public:
        static string toString(string path)
        {
            ifstream file(path);

            if (!file.good()) {
                cout << "Could not find file \"" << path << "\"\n";
                return "";
            }

            string contents;
            string line;

            while(!file.eof())
            {
                getline(file, line);
                contents += (line + '\n');
            }

            return contents;
        }
};
