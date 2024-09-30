#include "FreeRTOS.h"
#include "task.h"
#include <windows.h>

// Declare task handlers
TaskHandle_t TaskHandler1, TaskHandler2, TaskHandler3, TaskHandler4, TaskHandler5, TaskHandler6, TaskHandler7, TaskHandler8;

// Performance counter frequency
LARGE_INTEGER liFrequency;

// Function to measure the context switch time
void MeasureContextSwitchTime() {
    LARGE_INTEGER start, end;
    QueryPerformanceCounter(&start); // Get the start time

    // Yield to another task
    taskYIELD();

    QueryPerformanceCounter(&end); // Get the end time

    // Calculate the elapsed time in ms
    double timeTaken = (double)(end.QuadPart - start.QuadPart) * 1000.0 / (double)liFrequency.QuadPart;
    printf("%f\n", timeTaken); // Print the elapsed time
    printf(",");
}

// Task 1 function
void vTask1(void* p) {
    while (1) {
        MeasureContextSwitchTime(); // Measure the context switch time
        unsigned long ulDummyResult = 0;
        for (int i = 0; i < 10000; i++)
        {
            ulDummyResult += i; // Dummy workload
        }
    }
}

// Task 2 function
void vTask2(void* p) {
    while (1) {
        MeasureContextSwitchTime(); // Measure the context switch time
        unsigned long ulDummyResult = 0;
        for (int i = 0; i < 10000; i++)
        {
            ulDummyResult += i; // Dummy workload
        }
    }
}

// Task 3 function
void vTask3(void* p) {
    while (1) {
        MeasureContextSwitchTime(); // Measure the context switch time
        unsigned long ulDummyResult = 0;
        for (int i = 0; i < 10000; i++)
        {
            ulDummyResult += i; // Dummy workload
        }
    }
}

// Task 4 function
void vTask4(void* p) {
    while (1) {
        MeasureContextSwitchTime(); // Measure the context switch time
        unsigned long ulDummyResult = 0;
        for (int i = 0; i < 10000; i++)
        {
            ulDummyResult += i; // Dummy workload
        }
    }
}

// Task 5 function
void vTask5(void* p) {
    while (1) {
        MeasureContextSwitchTime(); // Measure the context switch time
        unsigned long ulDummyResult = 0;
        for (int i = 0; i < 10000; i++)
        {
            ulDummyResult += i; // Dummy workload
        }
    }
}

// Task 6 function
void vTask6(void* p) {
    while (1) {
        MeasureContextSwitchTime(); // Measure the context switch time
        unsigned long ulDummyResult = 0;
        for (int i = 0; i < 10000; i++)
        {
            ulDummyResult += i; // Dummy workload
        }
    }
}

// Task 7 function
void vTask7(void* p) {
    while (1) {
        MeasureContextSwitchTime(); // Measure the context switch time
        unsigned long ulDummyResult = 0;
        for (int i = 0; i < 10000; i++)
        {
            ulDummyResult += i; // Dummy workload
        }
    }
}

// Task 8 function
void vTask8(void* p) {
    while (1) {
        MeasureContextSwitchTime(); // Measure the context switch time
        unsigned long ulDummyResult = 0;
        for (int i = 0; i < 10000; i++)
        {
            ulDummyResult += i; // Dummy workload
        }
    }
}

// Main function to initialize and start the tasks
int main_blinky() {
    // Initialize the high-resolution performance counter
    QueryPerformanceFrequency(&liFrequency);

    // Create tasks
    xTaskCreate(vTask1, "Task1", 1000, NULL, 1, &TaskHandler1);
    xTaskCreate(vTask2, "Task2", 1000, NULL, 1, &TaskHandler2);
    xTaskCreate(vTask3, "Task3", 1000, NULL, 1, &TaskHandler3);
    xTaskCreate(vTask4, "Task4", 1000, NULL, 1, &TaskHandler4);
    xTaskCreate(vTask5, "Task5", 1000, NULL, 1, &TaskHandler5);
    xTaskCreate(vTask6, "Task6", 1000, NULL, 1, &TaskHandler6);
    xTaskCreate(vTask7, "Task7", 1000, NULL, 1, &TaskHandler7);
    xTaskCreate(vTask8, "Task8", 1000, NULL, 1, &TaskHandler8);

    // Start the scheduler
    vTaskStartScheduler();

    return 0;
}
