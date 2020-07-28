#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "formater.hpp"

using namespace std;

string latok = {"49:40:38 N"};
string lat1 = {"49:40:38N"};
string lat2 = {"-49:40:38N"};
string lat3 = {"49:40:8N"};
string lat4 = {"49:40:38 N"};
string longok = {"005:17:41 E"};
string long1 = {"005:17:41E"};
string long2 = {"5:17:41E"};
string long3 = {"5:17:41E"};
string long4 = {"005:17:41 E"};
string long5 = {"-5:17:41E"};

TEST_CASE( "check latitude,longitude conformation", "[airspace]" ) {
    string line;
    line = formaterString(lat1);
    CHECK( line == latok );
    line = formaterString(lat2);
    CHECK( line == "-49:40:38 N" );
    line = formaterString(lat3);
    CHECK( line == "49:40:08 N" );
    line = formaterString(lat4);
    CHECK( line == latok );
    line = formaterString(long1);
    CHECK( line == longok );
    line = formaterString(long2);
    CHECK( line == longok );
    line = formaterString(long3);
    CHECK( line == longok );
    line = formaterString(long4);
    CHECK( line == longok );
    line = formaterString(long5);
    CHECK( line == "-005:17:41 E" );
}

string line1 = {"DP 49:40:8N 5:17:41E"};
string line1ok = {"DP 49:40:08 N 005:17:41 E"};
string line2 = {"DB 50:40:36N 004:04:15E, 50:32:05N 004:06:55E"};
string line2ok = {"DB 50:40:36 N 004:04:15 E , 50:32:05 N 004:06:55 E "};

TEST_CASE( "check gps conformation", "[airspace]" ) {
    string line;
    line = formaterString(line1);
    CHECK( line == line1ok );
    line = formaterString(line2);
    CHECK( line == line2ok );
}
