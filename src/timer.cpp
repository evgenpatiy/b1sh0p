#include <GyverTimer.h>
GTimer ledTimer(MS);

void initTimers()
{
    ledTimer.setInterval(1000);  
}

void startTimer() {
    ledTimer.start();
}

void stopTimer() {
    ledTimer.stop();
}

boolean isTimerReady() {
    return ledTimer.isReady();
}