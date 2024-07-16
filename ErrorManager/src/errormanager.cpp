#include "errormanager.h"

#define QUEUE_SIZE 5 // TODO verify this.

class CustomQueue {
private:
    int queue[QUEUE_SIZE]; // TODO change this to uint8 or 16 
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

    int Query() { // TODO change return type to array or pointer
        return queue[0];
    }
};

CustomQueue customQueue; //TODO make this static

int errormanager::Query() {
    return customQueue.Query();
}

void errormanager::Throw(int code) {
    customQueue.Throw(code);
}

