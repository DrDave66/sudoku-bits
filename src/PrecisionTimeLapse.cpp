#include <iomanip>
#include <sstream>
using namespace std;
#include "PrecisionTimeLapse.h"  
	
PrecisionTimeLapse::PrecisionTimeLapse() {

}
void PrecisionTimeLapse::start() {
    begin = high_resolution_clock::now();
}

void PrecisionTimeLapse::stop() {
    end = high_resolution_clock::now();
}

high_resolution_clock::time_point PrecisionTimeLapse::tick() {
    return high_resolution_clock::now();
}

double PrecisionTimeLapse::elapsed() {
    time_lapse = duration_cast<std::chrono::nanoseconds> (end - begin);
    return (double)time_lapse.count();
}

string PrecisionTimeLapse::elapsedString() {
    return elapsedString(MILLISEC);
}
string PrecisionTimeLapse::elapsedString(TIME_UNIT tu) {
    string retval;          // string which will contain the result
    retval = to_string(elapsed() * tu);
    return retval;
}