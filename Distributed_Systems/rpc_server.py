#!usr/bin/python
from SimpleXMLRPCServer import SimpleXMLRPCServer
from SimpleXMLRPCServer import SimpleXMLRPCRequestHandler

# take a specific path
class RequestHandler(SimpleXMLRPCRequestHandler):
    rpc_paths = ('/RPC2',)

# initialize the server
server = SimpleXMLRPCServer(("localhost", 8000),
                            requestHandler=RequestHandler)
server.register_introspection_functions()

#register the function to the server
server.register_function(pow, 'power')

# Register a function under a different name
def adder_function(x,y):
    return x + y
#register the function to the server
server.register_function(adder_function, 'add')

def adder_function(x,y):
    return x - y
#register the function to the server
server.register_function(adder_function, 'minus')

#make the div operator
def div_function( x, y):
return x // y
#register the function to the server
server.register_function(div_function, 'divide')

# run the main loop of the server
server.serve_forever()
