# rtsd_project


This project is about the resource management of a Real-Time Operating System. 

The goal of the project is to find out the response time of several performance metrics: task response time, semaphore shuffling time, deadlock breaking time and context switch time.

There are two main parts of this project: 

The FreeRTOS part, which uses the high performance counter provided by the header file windows.h to accurately measure the mentioned metrics above.


The Python part, which are just basic numpy arrays, to provide fast and accurate results from the measured response times.
