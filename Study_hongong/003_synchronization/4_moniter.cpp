#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define NUM_ITEMS 100

typedef struct {
    int buffer[BUFFER_SIZE];          // 정수형 버퍼
    int in, out, count;
    pthread_mutex_t mutex;           // 모니터 역할의 뮤텍스
    pthread_cond_t not_full;         // 버퍼가 꽉 찼을 때 기다리는 조건 변수
    pthread_cond_t not_empty;        // 버퍼가 비었을 때 기다리는 조건 변수
} BoundedBuffer;

BoundedBuffer buffer;

void init_buffer(BoundedBuffer* b) {
    b->in = 0;
    b->out = 0;
    b->count = 0;
    pthread_mutex_init(&b->mutex, NULL);
    pthread_cond_init(&b->not_full, NULL);
    pthread_cond_init(&b->not_empty, NULL);
}

void insert(BoundedBuffer* b, int item) {
    pthread_mutex_lock(&b->mutex);

    while (b->count == BUFFER_SIZE)
        pthread_cond_wait(&b->not_full, &b->mutex);

    b->buffer[b->in] = item;
    b->in = (b->in + 1) % BUFFER_SIZE;
    b->count++;

    pthread_cond_signal(&b->not_empty);
    pthread_mutex_unlock(&b->mutex);
}

int remove_item(BoundedBuffer* b) {
    pthread_mutex_lock(&b->mutex);

    while (b->count == 0)
        pthread_cond_wait(&b->not_empty, &b->mutex);

    int item = b->buffer[b->out];
    b->out = (b->out + 1) % BUFFER_SIZE;
    b->count--;

    pthread_cond_signal(&b->not_full);
    pthread_mutex_unlock(&b->mutex);

    return item;
}

void* producer(void* arg) {
    for (int i = 1; i <= NUM_ITEMS; i++) {
        printf("Producing: %d\n", i);
        insert(&buffer, i);
        usleep(100000);  // 0.1초
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 1; i <= NUM_ITEMS; i++) {
        int item = remove_item(&buffer);
        printf("Consuming: %d\n", item);
        usleep(150000);  // 0.15초
    }
    return NULL;
}

int main() {
    pthread_t prod, cons;

    init_buffer(&buffer);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    return 0;
}