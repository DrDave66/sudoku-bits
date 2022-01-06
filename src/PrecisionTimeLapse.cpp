#include <iomanip>
#include <sstream>
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::time_point;
using std::__cxx11::to_string;

#include "PrecisionTimeLapse.h"  
	
PrecisionTimeLapse::PrecisionTimeLapse() {

}
void PrecisionTimeLapse::start() {
    begin = tick();
}

void PrecisionTimeLapse::stop() {
    end = tick();
}

high_resolution_clock::time_point PrecisionTimeLapse::tick() {
    return high_resolution_clock::now();
}

/**
 * @brief returns time, in seconds, between stop() and start()
 * 
 * @return double 
 */
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