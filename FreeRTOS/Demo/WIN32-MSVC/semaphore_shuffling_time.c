//#include "FreeRTOS.h"
//#include "task.h"
//#include "semphr.h"
//#include <stdio.h>
//#include <windows.h>
//
//// Function prototypes for the tasks
//static void vTask1(void* pvParameters);
//static void vTask2(void* pvParameters);
//static void vTask3(void* pvParameters);
//static void vTask4(void* pvParameters);
//static void vTask5(void* pvParameters);
//static void vTask6(void* pvParameters);
//static void vTask7(void* pvParameters);
//
//// Semaphore handle
//SemaphoreHandle_t xSemaphore = NULL;
//
//// Variables for performance measurement
//LARGE_INTEGER liFrequency;
//LARGE_INTEGER liStartTime;
//LARGE_INTEGER liEndTime;
//
//// Function to create tasks
//void createTasks(void)
//{
//    // Create a binary semaphore
//    xSemaphore = xSemaphoreCreateBinary();
//    if (xSemaphore != NULL)
//    {
//        // Create Task 1
//        if (xTaskCreate(vTask1, "vTask1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL) == pdPASS)
//        {
//            printf("Task 1 created successfully.\n");
//        }
//        else
//        {
//            printf("Failed to create Task 1.\n");
//        }
//
//        // Create Task 2
//        if (xTaskCreate(vTask2, "vTask2", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL) == pdPASS)
//        {
//            printf("Task 2 created successfully.\n");
//        }
//        else
//        {
//            printf("Failed to create Task 2.\n");
//        }
//
//        // Create Task 3
//        if (xTaskCreate(vTask3, "vTask3", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL) == pdPASS)
//        {
//            printf("Task 3 created successfully.\n");
//        }
//        else
//        {
//            printf("Failed to create Task 3.\n");
//        }
//
//        // Create Task 4
//        if (xTaskCreate(vTask4, "vTask4", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL) == pdPASS)
//        {
//            printf("Task 4 created successfully.\n");
//        }
//        else
//        {
//            printf("Failed to create Task 4.\n");
//        }
//
//        // Create Task 5
//        if (xTaskCreate(vTask5, "vTask5", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL) == pdPASS)
//        {
//            printf("Task 5 created successfully.\n");
//        }
//        else
//        {
//            printf("Failed to create Task 5.\n");
//        }
//
//        // Create Task 6
//        if (xTaskCreate(vTask6, "vTask6", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL) == pdPASS)
//        {
//            printf("Task 6 created successfully.\n");
//        }
//        else
//        {
//            printf("Failed to create Task 6.\n");
//        }
//
//        // Create Task 7
//        if (xTaskCreate(vTask7, "vTask7", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL) == pdPASS)
//        {
//            printf("Task 7 created successfully.\n");
//        }
//        else
//        {
//            printf("Failed to create Task 7.\n");
//        }
//    }
//    else
//    {
//        printf("Failed to create semaphore.\n");
//    }
//}
//
//// Task 1 function
//static void vTask1(void* pvParameters)
//{
//    double responseTimeMs;
//    QueryPerformanceFrequency(&liFrequency); // Get the frequency of the performance counter
//    printf("Task 1 running...\n");
//
//    for (;; )
//    {
//        QueryPerformanceCounter(&liStartTime); // Get the start time
//        vTaskDelay(pdMS_TO_TICKS(5)); // Delay for 5 ms
//        xSemaphoreGive(xSemaphore); // Give the semaphore
//
//        if (xSemaphoreTake(xSemaphore, portMAX_DELAY) == pdTRUE) // Take the semaphore
//        {
//            QueryPerformanceCounter(&liEndTime); // Get the end time
//            responseTimeMs = ((liEndTime.QuadPart - liStartTime.QuadPart) * 1000.0) / liFrequency.QuadPart; // Calculate the response time in milliseconds
//            printf("%.3f\n", responseTimeMs);  // Print the elapsed time
//            printf(",");
//        }
//    }
//}
//
//// Task 2 function
//static void vTask2(void* pvParameters)
//{
//    printf("Task 2 running...\n");
//
//    for (;; )
//    {
//        unsigned long ulDummyResult = 0;
//        for (int i = 0; i < 10000; i++)
//        {
//            ulDummyResult += i; // Dummy workload
//        }
//        taskYIELD(); // Yield to other tasks
//    }
//}
//
//// Task 3 function
//static void vTask3(void* pvParameters)
//{
//    printf("Task 3 running...\n");
//
//    for (;; )
//    {
//        unsigned long ulDummyResult = 0;
//        for (int i = 0; i < 10000; i++)
//        {
//            ulDummyResult += i; // Dummy workload
//        }
//        taskYIELD(); // Yield to other tasks
//    }
//}
//
//// Task 4 function
//static void vTask4(void* pvParameters)
//{
//    printf("Task 4 running...\n");
//
//    for (;; )
//    {
//        unsigned long ulDummyResult = 0;
//        for (int i = 0; i < 10000; i++)
//        {
//            ulDummyResult += i; // Dummy workload
//        }
//        taskYIELD(); // Yield to other tasks
//    }
//}
//
//// Task 5 function
//static void vTask5(void* pvParameters)
//{
//    printf("Task 5 running...\n");
//
//    for (;; )
//    {
//        unsigned long ulDummyResult = 0;
//        for (int i = 0; i < 10000; i++)
//        {
//            ulDummyResult += i; // Dummy workload
//        }
//        taskYIELD(); // Yield to other tasks
//    }
//}
//
//// Task 6 function
//static void vTask6(void* pvParameters)
//{
//    printf("Task 6 running...\n");
//
//    for (;; )
//    {
//        unsigned long ulDummyResult = 0;
//        for (int i = 0; i < 10000; i++)
//        {
//            ulDummyResult += i; // Dummy workload
//        }
//        taskYIELD(); // Yield to other tasks
//    }
//}
//
//// Task 7 function
//static void vTask7(void* pvParameters)
//{
//    printf("Task 7 running...\n");
//
//    for (;; )
//    {
//        unsigned long ulDummyResult = 0;
//        for (int i = 0; i < 10000; i++)
//        {
//            ulDummyResult += i; // Dummy workload
//        }
//        taskYIELD(); // Yield to other tasks
//    }
//}
//
//// Main function to initialize and start the tasks
//void main_blinky(void)
//{
//    printf("Initializing...\n");
//    createTasks(); // Create the tasks
//    printf("Starting scheduler...\n");
//    vTaskStartScheduler(); // Start the FreeRTOS scheduler
//}
