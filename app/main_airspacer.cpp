#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <chrono>
#include "formater.hpp"

using namespace std;

int main(int argc, const char* argv[])
{
    auto start = chrono::high_resolution_clock::now();

    string application = "airspacer";
    string version = "0.0.1";

    if (argc >= 3) {
        string inputFilename(argv[1]);
        string outputFilename(argv[2]);

        ifstream inFile(inputFilename);
        ofstream outFile(outputFilename);
        string line;
        while(getline(inFile,line)) {
            auto newline = formaterString(line);
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
