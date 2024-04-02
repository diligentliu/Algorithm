#ifndef ALGORITHM_LC1114_H
#define ALGORITHM_LC1114_H

#include "main.h"
#include <semaphore.h>

void printFirst() {
	std::cout << "first" << std::endl;
}

void printSecond() {
	std::cout << "second" << std::endl;
}

void printThird() {
	std::cout << "third" << std::endl;
}

class LC_1114 {
	sem_t first_done, second_done;
public:
	LC_1114() {
		sem_init(&first_done, 0, 0);
		sem_init(&second_done, 0, 0);
	}

	void first(function<void()> printFirst) {
		printFirst();
		sem_post(&first_done);
	}

	void second(function<void()> printSecond) {
		sem_wait(&first_done);
		printSecond();
		sem_post(&second_done);
	}

	void third(function<void()> printThird) {
		sem_wait(&second_done);
		printThird();
	}
};

#endif //ALGORITHM_LC1114_H
