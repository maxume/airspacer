#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <chrono>
#include <regex>

using namespace std;

string latitudeFormat(const string& latitude)
{
    regex regLatitude("(-?)([0-9]*):([0-9]*):([0-9]*)\\s?([NS])");

    smatch m;
    regex_search(latitude,m,regLatitude);
    auto signValue = m[1].str();
    auto degValue = stoi(m[2].str());
    auto minValue = stoi(m[3].str());
    auto secValue = stoi(m[4].str());
    auto quadValue = m[5].str();

    ostringstream os;
    os << signValue << setfill('0') << setw(2) << degValue << ':' << setw(2) << minValue << ':' << setw(2) << secValue << ' ' << quadValue;

    auto newlatitude = os.str();

    return newlatitude;
}

string longitudeFormat(const string& longitude)
{
    regex regLongitude("(-?)([0-9]*):([0-9]*):([0-9]*)\\s?([EW])");

    smatch m;
    regex_search(longitude,m,regLongitude);
    auto signValue = m[1].str();
    auto degValue = stoi(m[2].str());
    auto minValue = stoi(m[3].str());
    auto secValue = stoi(m[4].str());
    auto quadValue = m[5].str();

    ostringstream os;
    os << signValue << setfill('0') << setw(3) << degValue << ':' << setw(2) << minValue << ':' << setw(2) << secValue << ' ' << quadValue << ' ';

    auto newlongitude = os.str();

    return newlongitude;
}

string convertString(const string& text, const regex& reg, string (*formater)(const string&))
{
    smatch m;
    auto sline = text;
    string newline;
    size_t it = 0;
    if (regex_search(text.begin()+it,text.end(),m,reg)) {
        auto value = m.str(0);
        auto pos = m.position(0);
        auto newvalue = formater(value);
        newline += text.substr(it,pos-it)+newvalue;
        it = pos+value.size();
    }
    newline += text.substr(it);
    return newline;
}

int main(int argc, const char* argv[])
{
    auto start = chrono::high_resolution_clock::now();

    string application = "airspacer";
    string version = "0.0.1";

    if (argc >= 3) {
        string inputFilename(argv[1]);
        string outputFilename(argv[2]);

        regex regLatitude("-?[0-9]*:[0-9]*:[0-9]*\\s?[NS]");
        regex regLongitude("-?[0-9]*:[0-9]*:[0-9]*\\s?[EW]");

        ifstream inFile(inputFilename);
        ofstream outFile(outputFilename);
        string line;
        while(getline(inFile,line)) {
            auto newline = convertString(line,regLatitude,latitudeFormat);
            newline = convertString(newline,regLongitude,longitudeFormat);
            newline = convertString(newline,regLatitude,latitudeFormat);
            newline = convertString(newline,regLongitude,longitudeFormat);
            outFile << newline << endl;
        }
        outFile.close();
    }
    else {
        cout << "Usage : airspacer <input_file> <output_file>" << endl;
    }

    auto finish = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds> (finish - start);
    cout << "Execution time : " << duration.count() << " ms" << endl;

    return EXIT_SUCCESS;
}
