#coding:utf-8

from urllib import request
import paho.mqtt.client as mqtt
import itchat

# itchat.auto_login()
itchat.auto_login(enableCmdQR=2)
users = itchat.search_chatrooms(name='syl')

def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    client.subscribe("gC0sVTVWg")

def on_message(client, userdata, msg):
    print("MSG:"+msg.topic+" "+msg.payload.decode())
    itchat.send(msg.payload.decode().replace("->",""), toUserName=users[0]['UserName'])
    url = r'https://restapi.amap.com/v3/staticmap?markers=mid,0xFF0000,A:'
    url += msg.payload.decode().split(":")[1] 
    url += r'&key=983c61760e269b5e6568cf07c392637d'
    print("URL:"+url)
    request.urlretrieve(url,"map.png")
    itchat.send_image("map.png", toUserName=users[0]['UserName'])

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.username_pw_set("PMuJ4T4WR","EGu14oVZgz")
client.connect("iot.dfrobot.com.cn", 1883, 60)
client.loop_forever()
