#include "formater.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <boost/regex.hpp>

using namespace std;

string latitudeFormat(const boost::smatch& latitudeMatch)
{
    auto latitude = latitudeMatch[0].str();
    boost::regex regLatitude("(-?)([0-9]*):([0-9]*):([0-9]*)\\s?([NS])");

    boost::smatch m;
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

string longitudeFormat(const boost::smatch& longitudeMatch)
{
    auto longitude = longitudeMatch[0].str();
    boost::regex regLongitude("(-?)([0-9]*):([0-9]*):([0-9]*)\\s?([EW])");

    boost::smatch m;
    regex_search(longitude,m,regLongitude);
    auto signValue = m[1].str();
    auto degValue = stoi(m[2].str());
    auto minValue = stoi(m[3].str());
    auto secValue = stoi(m[4].str());
    auto quadValue = m[5].str();

    ostringstream os;
    os << signValue << setfill('0') << setw(3) << degValue << ':' << setw(2) << minValue << ':' << setw(2) << secValue << ' ' << quadValue;

    auto newlongitude = os.str();

    return newlongitude;
}

string formaterString(const string& line)
{
    boost::regex regLatitude("-?[0-9]*:[0-9]*:[0-9]*\\s?[NS]");
    boost::regex regLongitude("-?[0-9]*:[0-9]*:[0-9]*\\s?[EW]");

    auto newline = regex_replace(line,regLatitude,latitudeFormat);
    newline = regex_replace(newline,regLongitude,longitudeFormat);

    return newline;
}
