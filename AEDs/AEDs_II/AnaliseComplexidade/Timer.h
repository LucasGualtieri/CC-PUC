#include <time.h>

typedef struct Timer {
	clock_t startTime;
	clock_t endTime;
	double totalTime;
	void (*Start)(struct Timer*);
	double (*Stop)(struct Timer*);
} Timer;

void TimerStart(Timer* timer) {
	timer->startTime = clock();
}

double TimerStop(Timer* timer) {
	timer->endTime = clock();
	timer->totalTime = ((double) (timer->endTime - timer->startTime)) / CLOCKS_PER_SEC;
	// double teste = difftime(timer.elapsedTime, timer.startTime);
	// printf("Teste = %lf\n", teste);
	return timer->totalTime;
}

Timer newTimer() {
	Timer timer;
	timer.Start = TimerStart;
	timer.Stop = TimerStop;
	return timer;
}