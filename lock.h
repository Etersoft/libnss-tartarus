#ifndef LIBNSS_TARTARUS_LOCK_H_
#define LIBNSS_TARTARUS_LOCK_H_

#include <pthread.h>

class Lock
{
	pthread_mutex_t *mutex;
public:
	Lock (pthread_mutex_t *mutex): mutex(mutex) {
		pthread_mutex_lock (mutex);
	}
	~Lock () {
		pthread_mutex_unlock (mutex);
	}
};

#endif /*LIBNSS_TARTARUS_LOCK_H_*/
