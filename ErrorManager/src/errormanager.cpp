#include "errormanager.h"

#define QUEUE_SIZE 5

class CustomQueue {
private:
    int queue[QUEUE_SIZE];
    void enqueue(int value) {
        for (int i = QUEUE_SIZE - 1; i > 0; i--) {
            queue[i] = queue[i - 1];
        }
        queue[0] = value;
    }

public:
    CustomQueue() {
        for (int i = 0; i < QUEUE_SIZE; i++) {
            queue[i] = 0;
        }
    }

    void Throw(int errorCode) {
        enqueue(errorCode);
    }

    int Query() {
        return queue[0];
    }
};

CustomQueue customQueue;

int errormanager::Query() {
    return customQueue.Query();
}

void errormanager::Throw(int code) {
    customQueue.Throw(code);
}

