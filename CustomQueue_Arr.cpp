#include <iostream>

class CustomQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    CustomQueue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~CustomQueue() {
        delete[] arr;
    }

    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Queue is full! Cannot enqueue " << item << std::endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty! Cannot dequeue." << std::endl;
            return -1;
        }
        int item = arr[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    int getSize() const {
        return size;
    }
};

int main() {
    CustomQueue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    
    queue.enqueue(60);

    std::cout << "Dequeued: " << queue.dequeue() << std::endl;
    std::cout << "Dequeued: " << queue.dequeue() << std::endl;

    queue.enqueue(60);

    while (!queue.isEmpty()) {
        std::cout << "Dequeued: " << queue.dequeue() << std::endl;
    }

    return 0;
}
