//#include "FreeRTOS.h"
//#include "task.h"
//#include <stdio.h>
//#include <windows.h>
//
//// Task handles
//TaskHandle_t xTaskToNotify = NULL;
//
//// Performance counter variables
//LARGE_INTEGER liFrequency, liTriggerTime, liStartTime;
//
//// Task that waits for the notification
//void vReceiverTask(void* pvParameters) {
//    uint32_t ulNotificationValue;
//    LARGE_INTEGER liCurrentTime;
//
//    while (1) {
//        // Wait indefinitely for the notification
//        if (xTaskNotifyWait(0x00, ULONG_MAX, &ulNotificationValue, portMAX_DELAY) == pdTRUE) {
//            QueryPerformanceCounter(&liCurrentTime);  // Get the time when the task starts processing
//            double responseTime = (double)(liCurrentTime.QuadPart - liStartTime.QuadPart) * 1000.0 / liFrequency.QuadPart;
//            printf("%.3f \n", responseTime);
//            printf(",");
//        }
//    }
//}
//
//// Task that triggers the notification
//void vSenderTask(void* pvParameters) {
//    while (1) {
//        vTaskDelay(pdMS_TO_TICKS(5));
//
//        QueryPerformanceCounter(&liStartTime);  // Get the time immediately before sending the notification
//        xTaskNotifyGive(xTaskToNotify);  // Send the notification
//    }
//}
//
//int main_blinky(void) {
//    QueryPerformanceFrequency(&liFrequency);  // Get the performance counter frequency
//
//    // Create tasks
//    xTaskCreate(vReceiverTask, "Receiver", 1000, NULL, 1, &xTaskToNotify);
//    xTaskCreate(vSenderTask, "Sender", 1000, NULL, 2, NULL);
//
//    // Start the scheduler
//    vTaskStartScheduler();
//
//    return 0;
//}
