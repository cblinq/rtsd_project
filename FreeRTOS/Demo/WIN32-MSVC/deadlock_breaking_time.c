//#include "FreeRTOS.h"
//#include "task.h"
//#include "semphr.h"
//#include <stdio.h>
//#include <windows.h>
//
//// Declare mutexes
//SemaphoreHandle_t Mutex1 = NULL;
//SemaphoreHandle_t Mutex2 = NULL;
//
//// Task handles
//TaskHandle_t Task1Handle = NULL;
//TaskHandle_t Task2Handle = NULL;
//
//void vTask1(void* pvParameters);
//void vTask2(void* pvParameters);
//
//// Time measurement
//LARGE_INTEGER frequency;        // ticks per second
//LARGE_INTEGER start, end;       // ticks
//double interval;
//
//int main_blinky(void) {
//    // Measure frequency
//    QueryPerformanceFrequency(&frequency);
//
//    // Create mutexes
//    Mutex1 = xSemaphoreCreateMutex();
//    Mutex2 = xSemaphoreCreateMutex();
//
//    // Create tasks
//    xTaskCreate(vTask1, "Task 1", 1000, NULL, 1, &Task1Handle);
//    xTaskCreate(vTask2, "Task 2", 1000, NULL, 1, &Task2Handle);
//
//    // Start scheduler
//    vTaskStartScheduler();
//
//    return 0;
//}
//
//void vTask1(void* pvParameters) {
//    LARGE_INTEGER freq, start, end;
//    double elapsedTime;
//
//    // Get the frequency of the high-resolution performance counter
//    QueryPerformanceFrequency(&freq);
//
//    while (1) {
//        if (xSemaphoreTake(Mutex1, portMAX_DELAY)) {
//            //printf("Task 1 took Mutex 1\n");
//
//            // Simulate some load
//            unsigned long ulDummyResult = 0;
//            for (int i = 0; i < 10000; i++) {
//                ulDummyResult += i;
//            }
//
//            QueryPerformanceCounter(&start);
//
//            if (xSemaphoreTake(Mutex2, pdMS_TO_TICKS(0))) {
//                QueryPerformanceCounter(&end);
//                //printf("Task 1 took Mutex 2\n");
//                xSemaphoreGive(Mutex2);
//
//                elapsedTime = (double)(end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
//                //printf("Mutex 2 acquired in %f ms\n", elapsedTime);
//            }
//            else {
//                QueryPerformanceCounter(&end);
//                //printf("Task 1 failed to take Mutex 2 and is breaking deadlock\n");
//
//                elapsedTime = (double)(end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
//                printf("%f \n", elapsedTime);
//                printf(",");
//            }
//            xSemaphoreGive(Mutex1);
//        }
//    }
//}
//
//void vTask2(void* pvParameters) {
//    LARGE_INTEGER freq, start, end;
//    double elapsedTime;
//
//    // Get the frequency of the high-resolution performance counter
//    QueryPerformanceFrequency(&freq);
//
//    while (1) {
//        if (xSemaphoreTake(Mutex2, portMAX_DELAY)) {
//            //printf("Task 2 took Mutex 2\n");
//
//            // Simulate some load
//            unsigned long ulDummyResult = 0;
//            for (int i = 0; i < 10000; i++) {
//                ulDummyResult += i;
//            }
//
//            QueryPerformanceCounter(&start);
//
//            if (xSemaphoreTake(Mutex1, pdMS_TO_TICKS(0))) {
//                QueryPerformanceCounter(&end);
//                //printf("Task 2 took Mutex 1\n");
//                xSemaphoreGive(Mutex1);
//
//                elapsedTime = (double)(end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
//                //printf("Mutex 1 acquired in %f ms\n", elapsedTime);
//            }
//            else {
//                QueryPerformanceCounter(&end);
//                //printf("Task 2 failed to take Mutex 1 and is breaking deadlock\n");
//
//                elapsedTime = (double)(end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
//                printf("%f\n", elapsedTime);
//                printf(",");
//            }
//            xSemaphoreGive(Mutex2);
//        }
//    }
//}