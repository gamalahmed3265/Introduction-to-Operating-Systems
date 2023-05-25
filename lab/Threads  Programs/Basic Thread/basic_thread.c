#include <pthread.h>
#include <stdio.h>

void *thread_function(void *arg) {
  // Get the thread ID.
  pthread_t tid = pthread_self();

  // Get the thread's stack size.
  size_t stack_size = pthread_getstacksize(tid);

  // Print the thread ID and the stack size.
  printf("Thread %d [%lu]\n", tid, stack_size);

  return NULL;
}

int main() {
  pthread_t thread;
  pthread_attr_t attr;

  // Initialize the thread attributes.
  pthread_attr_init(&attr);

  // Set the stack size to 2MB.
  pthread_attr_setstacksize(&attr, 2 * 1024 * 1024);

  // Create the thread.
  pthread_create(&thread, &attr, thread_function, NULL);

  // Wait for the thread to terminate.
  pthread_join(thread, NULL);

  return 0;
}
