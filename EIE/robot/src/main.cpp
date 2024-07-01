#include <Arduino.h>
#include <TaskScheduler.h>


Scheduler scheduler;

#define monitor_speed 115200

Task task1(1000, TASK_FOREVER, [](){
    Serial.printf("Task 1");
});

void setup() {
    // 初始化串口通信
    Serial.begin(monitor_speed);

    // 初始化任务调度器
    scheduler.init();

    // 添加任务到调度器
    scheduler.addTask(task1);

    // 启用任务（默认情况下任务是禁用的）
    task1.enable();
}

void loop() {
  // put your main code here, to run repeatedly:

  scheduler.execute();

 Serial.printf("hello world");
  delay(200);
}
