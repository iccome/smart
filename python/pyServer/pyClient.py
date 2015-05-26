import httplib
import urllib
import json
import pprint
conn = httplib.HTTPConnection("localhost:6666")
headers = {"Content-type":"application/x-www-form-urlencoded"} #application/x-www-form-urlencoded
params =  urllib.urlencode({"key": "value"})
conn.request("POST", "/json1", json.JSONEncoder().encode(params), headers)
response = conn.getresponse()
data = response.read()
if response.status == 200:
    print 'success'
    print data
else:
    print 'fail'
conn.close() 