#include <ctime>

class ProcessTimer {
    std::clock_t start_time;
    bool running;

public:
    void start() {
        start_time = std::clock();
        running = true;
    }

    double result() {
        if (running) return (std::clock() - start_time) / (double) CLOCKS_PER_SEC;
        return 0.0;
    }
};
