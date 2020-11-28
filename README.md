# 海上船舶的动态定位与搜救设施
包括以下内容
- 服务端和客户端的代码
- 代码中使用的库
- STL模型

## 使用方式
服务端运行Server.py
运行后需通过二维码登录网页版微信
*群名目前是“测试群”，请在运行前更改
```
users = itchat.search_chatrooms(name='测试群')
```
*需保持程序的运行，否则可能收不到信息
*请使用支持网页版微信的微信账号*
客户端上传Client.ino
*需要注册[Easy IoT](iot.dfrobot.com.cn)的账号，并添加设备，并更改user、password、Topic
```
#define IOT_USERNAME    "*********"
#define IOT_KEY         "**********"
#define IOT_TOPIC       "*********"
```
*
当接通电源时自动循环发送信息

# Dynamic positioning and rescue facilities for vessels
This repository contains:
- Code for Server and Client
- Used library
- STL model
