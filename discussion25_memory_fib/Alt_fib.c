#include <stdio.h>        // inculdes standard input-output functions
#include <stdlib.h>       // inculdes functions for memeory allocation
#include <stdbool.h>      // inculdes true false definition
#include <string.h>       // inculdes functions for string manipulation
#include <time.h>         // inculdes functions for time manipulation

                          // Maximum number of Fibonacci numbers to compute
#define MAX_FIB 200

// max number of inputs that can be computed with naive fib and memoized fib
#define NAIVE_BIG_FIB 55
#define MEMO_BIG_FIB 90

// invalid value for memo table
#define INVALID -1

 

// ========================== MEMO DEFINITIONS ==========================

typedef unsigned long long memo_t[MAX_FIB];     // type of array to hold computed data values (range: 0 to 2^64-1)


// initialize the table: make all entries in the memoization table invalid, add values for 0,1
void initMemo(memo_t m) {
  int i;
  for (i=0; i<MAX_FIB; i++) {
    m[i] = INVALID;
  }

  // prime the pump
  m[0] = 0;
  m[1] = 1;

  return;
}

// ========================== TIME DEFINITIONS ==========================
// timer functions found in time.h
// time_t is time type
time_t startTime;
time_t stopTime;

// get current time in seconds from some magic date with
// t = time(NULL);
// or
// time(&t);
// where t is of type time_t
//
// get difference in secs between times (t1-t2) with
// d = difftime(t1, t2);
// where d is of type double

// ========================== NAIVE FIB  ==========================

unsigned long long fib(int n) {
  if (n < 1) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fib(n-1) + fib(n-2);
  }
}


// ========================== MEMOIZED FIB  ==========================

unsigned long long mfib(int n, memo_t m) {
  unsigned long long temp;
  
  if (n < 0) {
    // error condition
    return INVALID;
    
  } else if (m[n] != INVALID) {
    // already solved this sub problem
    return m[n];
    
  } else {
    // unsolved sub problem
    temp = mfib(n-1, m) + mfib(n-2, m);
    m[n] = temp;
    return temp;
  }

}

// ========================== MAIN PROGRAM  ==========================
int main() {
  
  // result of call to fib function
  unsigned long long result;

  //loop variable
  int i;

  // memo array to hold computed data values
  memo_t  memo;

  printf("START naive Fibonacci from 0 to %d by 5s\n\n", NAIVE_BIG_FIB-5); 

  for (i = 0; i < NAIVE_BIG_FIB; i+=5) {

    // get start time
    time(&startTime);
    // call fib
    //result = fib(i);
    // get stop time
    time(&stopTime);
  
    printf("fib of %d = %llu\n", i, result);
    printf("time taken (sec) = %lf\n\n", difftime(stopTime, startTime));
  }

  printf("\n\n\n");
  printf("START memoized Fibonacci from 0 to %d by 5s\n\n", MEMO_BIG_FIB-5); 


  for (i = 0; i < MEMO_BIG_FIB; i+=5) {

    // get start time
    time(&startTime);    // time(&variable) stores current time in variable
    // call mfib
    initMemo(memo);      // we initialize the memo table every time and then call mfib
    result = mfib(i, memo);
    // get stop time
    time(&stopTime);
  
    printf("mfib of %d = %llu\n", i, result);
    printf("time taken (sec) = %lf\n\n", difftime(stopTime, startTime));
  }

  return 0;
}