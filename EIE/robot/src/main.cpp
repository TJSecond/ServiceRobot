#include <Arduino.h>
#include <TaskScheduler.h>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm> 
#include<string.h>
#include<iostream>
#include<queue>
#include<math.h>
#include<string>
#include<map>
#include<functional>
#include<unordered_map>
#include<bitset>
#include <soc/soc.h> 
#include <soc/rtc_cntl_reg.h>
#include <soc/rtc_wdt.h> //设置看门狗用
#include <Wire.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <BluetoothSerial.h>
#include <ESP32Servo.h>

Scheduler scheduler;

#define inf 0x3f3f3f3f
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
