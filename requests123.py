#-*- coding:utf-8 -*-
import requests
url1 = 'http://www.exanple.com/login'#��½��ַ
url2 = "http://www.example.com/main"#��Ҫ��½���ܷ��ʵĵ�ַ
data={"user":"user","password":"pass"}
headers = { "Accept":"text/html,application/xhtml+xml,application/xml;",
            "Accept-Encoding":"gzip",
            "Accept-Language":"zh-CN,zh;q=0.8",
            "Referer":"http://www.example.com/",
            "User-Agent":"Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/42.0.2311.90 Safari/537.36"
            }
res1 = requests.post(url1, data=data, headers=headers)
res2 = requests.get(url2, cookies=res1.cookies, headers=headers)

print res2.content#��ö�������Ӧ����
print res2.raw#���ԭʼ��Ӧ����,��Ҫstream=True
print res2.raw.read(50)
print type(res2.text)#���ؽ����unicode������
print res2.url
print res2.history#׷���ض���
print res2.cookies
print res2.cookies['example_cookie_name']
print res2.headers
print res2.headers['Content-Type']
print res2.headers.get('content-type')
print res2.json#���������ݱ���Ϊjson
print res2.encoding#�������ݱ���
print res2.status_code#����http״̬��
print res2.raise_for_status()#���ش���״̬��