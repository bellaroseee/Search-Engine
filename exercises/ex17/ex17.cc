// Name: Bella Rose
// UW emai: brose714@uw.edu

/*
 * Copyright ©2020 Hal Perkins.  All rights reserved.  Permission is
 * hereby granted to students registered for University of Washington
 * CSE 333 for use solely during Spring Quarter 2020 for purposes of
 * the course.  No other use, copying, distribution, or modification
 * is permitted without prior written consent. Copyrights for
 * third-party components of this work must be honored.  Instructors
 * interested in reusing these course materials should contact the
 * author.
 */

#include <pthread.h>

#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <string>
#include <ctime>

#include "SimpleQueue.h"

using std::cout;
using std::endl;
using std::string;
using std::thread;

const int NUM_THREADS = 3;

const int NUM_PIES = 6;
static SimpleQueue queue;               // queue of pies
static unsigned int seed = time(NULL);  // initialize random sleep time
static pthread_mutex_t write_lock;      // mutex for cout

// Thread safe print that prints the given str on a line
void thread_safe_print(string str) {
  pthread_mutex_lock(&write_lock);
  // Only one thread can hold the lock at a time, making it safe to
  // use cout. If we didn't lock before using cout, the order of things
  // put into the stream could be mixed up.
  cout << str << endl;
  pthread_mutex_unlock(&write_lock);
}

// Produces NUM_PIES pies of the given type
// You should NOT modify this method at all
void producer(string pie_type) {
  for (int i = 0; i < NUM_PIES; i++) {
    queue.Enqueue(pie_type);
    thread_safe_print(pie_type + " pie ready!");
    int sleep_time = rand_r(&seed) % 500 + 1;
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
  }
}

// Eats 2 * NUM_PIES pies
// You should NOT modify this method at all
void consumer() {
  for (int i = 0; i < NUM_PIES * 2; i++) {
    bool successful = false;
    string pie_type;
    while (!successful) {
      while (queue.IsEmpty()) {
        // Sleep for a bit and then check again
        int sleep_time = rand_r(&seed) % 800 + 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
      }
      successful = queue.Dequeue(&pie_type);
    }
    thread_safe_print(pie_type + " pie eaten!");
  }
}

// WRAPPER FUNCTIONS
// wraps the producer function
void *wrapper_producer(void* arg) {
  string *pie_type = reinterpret_cast<string*> (arg);
  producer(*pie_type);
  return nullptr;
}

// wraps the consumer function
void *wrapper_consumer(void* arg) {
  consumer();
  return nullptr;
}


int main(int argc, char **argv) {
  pthread_mutex_init(&write_lock, NULL);
  // Your task: Make the two producers and the single consumer
  // all run concurrently (hint: use pthreads)

  pthread_t thds[NUM_THREADS];
  string apple = "Apple";
  string blackberry = "Blackberry";

  // call the wrapper producer at thread 0
  // replaces producer("Apple");
  if (pthread_create(&thds[0], nullptr, &wrapper_producer,  &apple) != 0) {
    std::cerr << "pthread_create failed" << std::endl;
  }

  // call the wrapper producer at thread 1
  // replaces  producer("Blackberry");
  if (pthread_create(&thds[1], nullptr, &wrapper_producer, &blackberry) != 0) {
    std::cerr << "pthread_create failed" << std::endl;
  }

  // call the wrapper consumer at thread 2
  // replaces consumer();
  if (pthread_create(&thds[2], nullptr, &wrapper_consumer, NULL) != 0) {
    std::cerr << "pthread_create failed" << std::endl;
  }

  // join the threads
  for (int i = 0; i < NUM_THREADS; i++) {
    if (pthread_join(thds[i], nullptr) != 0) {
      std::cerr << "pthread_join failed" << std::endl;
    }
  }

  pthread_mutex_destroy(&write_lock);
  return 0;
}
