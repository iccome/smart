from BaseHTTPServer import HTTPServer
from BaseHTTPServer import BaseHTTPRequestHandler
import json
import pprint
import cgi

json1 = {"key": "value"}
json2 = {"key1": "value1"}

class MyRequestHandler (BaseHTTPRequestHandler) :

    def do_GET(self) :

        if self.path == "/json1" :
            #send response code:
            self.send_response(200)
            #send headers:
            self.send_header("Content-type:", "text/html")
            # send a blank line to end headers:
            self.wfile.write("\n")

            #send response:
            json.dump(json1, self.wfile)

        elif self.path == "/json2" :
            #send response code:
            self.send_response(200)
            #send headers:
            self.send_header("Content-type:", "text/html")
            # send a blank line to end headers:
            self.wfile.write("\n")

            #send response:
            json.dump(json2, self.wfile)
    def do_POST(self) :

        if self.path == "/json1" :
            print '------->',self.headers
            #send response code:
            self.send_response(200)
            #send headers:
            self.send_header("Content-type:", "text/html")
            # send a blank line to end headers:
            self.wfile.write("\n")
            print 'Server connect success'
            #send response:
            json.dump(json1, self.wfile)
            ctype, pdict = cgi.parse_header(self.headers.getheader('content-type'))
            if ctype == 'multipart/form-data':
                postvars = cgi.parse_multipart(self.rfile, pdict)
            elif ctype == 'application/x-www-form-urlencoded':
                length = int(self.headers.getheader('content-length'))
                #postvars = cgi.parse_qs(self.rfile.read(length), keep_blank_values=1)
                json.dump(self.rfile.read(length))
            else:
                postvars = {}
        print postvars
server = HTTPServer(("localhost", 6666), MyRequestHandler)

server.serve_forever()

