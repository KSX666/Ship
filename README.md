# 海上船舶的动态定位与搜救设施
包括以下内容
- 服务端和客户端的代码
- 代码中使用的库
- STL模型

## 使用方式
服务端运行Server.py；
运行后需通过二维码登录网页版微信；
*群名目前是“测试群”，请在运行前更改
```
users = itchat.search_chatrooms(name='测试群')
```
*需保持程序的运行，否则可能收不到信息
*请使用支持网页版微信的微信账号*
客户端上传Client.ino
*需要注册[Easy IoT](iot.dfrobot.com.cn)的账号，并添加设备，并更改user、password、Topic*
```
#define IOT_USERNAME    "*********"
#define IOT_KEY         "**********"
#define IOT_TOPIC       "*********"
```
*需要在开阔场地使用，否则服务端不会发送任何消息*
当接通电源时会自动循环发送信息

# Dynamic positioning and rescue facilities for vessels
This repository contains:
- Code for Server and Client
- Used library
- STL model

## How to use
Run Server.py on your server
Scan QR code to login Wechat
*The chatroom is currently set to“测试群”，please make a change
```
users = itchat.search_chatrooms(name='测试群')
```
*Keep the program running, or you won't receive a message
*You need an account which is available for Wechat online*
Upload Client.ino to Arduino UNO
*You should create an account for[Easy IoT](iot.dfrobot.com.cn)，add device，and change 'user、password、Topic'*
```
#define IOT_USERNAME    "*********"
#define IOT_KEY         "**********"
#define IOT_TOPIC       "*********"
```
*You need to go outdoor for a better GPS signal, or the server won't send a message*
This will repeatedly send messages to your server
And you can receive messages on Wechat
