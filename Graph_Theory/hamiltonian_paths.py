#!usr/bin/python
import sys


#test graph
#Explanation

# 1: [4,5]
# 1 = the vertex
# 4,5 is means tha the vertex 1 has edges going to vertex 4 and vertex 5
#connections = {1: [4, 5], 2: [5], 3: [4], 4: [1, 3, 5], 5: [1, 2, 4]} 



def find_all_paths(graph, start, end, path=[]):
#add the step that we made in order to reach our detination (end point) , to the vertex chain
    path = path + [start]
#when our last node take the same value as the node that we want to reach , it means that we found our path
    if (start == end):
        return [path]
#has_key() was removed in Python 3.x. , but with this command we check if the initial point is inside our graph (dictionary)
    if (not graph.has_key(start)):
        return []
#initialize the path
    paths = []
#take the first node 
    for node in graph[start]:
        if (node not in path):
#we used a retroactive function , and if the node is not is path already , we continue with this node and take it's directions
            newpaths = find_all_paths(graph, node, end, path)
            for newpath in newpaths:
#actually this returns one node every time until we reach our destination , when this happens the have complete the first list (first path)
                paths.append(newpath)
    return paths


#A Hamiltonian path, also called a Hamilton path, is a graph path between two vertices of a graph
# that visits each vertex exactly once. If a Hamiltonian path exists whose endpoints are adjacent, 
#then the resulting graph cycle is called a Hamiltonian cycle (or Hamiltonian cycle).
def findEveryVertexPath(connections):
	print 'the graph: ',connections,'\n'
	#run all the dictionary and every node individually
	for x in range(1,len(connections)+1):
		print '\n'
		print 'all the paths starting from the vertex: ',x,'\n'
	#for every node search all the candidate paths to every node
		for y in range(1,len(connections)+1):
			if (x==y):
	#if the start and the end point are equal it means that we are searching for a hamiltonian circuit and not a path
				for z in range(len(connections[x])):
				#do the loop for every child of this specific node
					initialPoint = x
					#the start point is not the actuall start point but it's children
					paths = find_all_paths(connections,connections[x][z],y)
					for o in range(len(paths)):
					#becaue of this i run a loop for every list (path) that i found and i add the actuall
					#start point in the begging of every list
						paths[o] = [initialPoint] + paths[o]
					print 'for vertex: ',x,' hamiltonian circuits: ',paths
				continue
			print 'from vetrex ',x,' to vertex ',y,' you can go with the following hamiltonian paths: ',find_all_paths(connections,x,y)

#if we need to read a file
def readFromaFile(inputFileName):
	#initialize the dictionary
	d = {}
	#open the file that you want to read
	with open(inputFileName) as f:
		#read every line 
		for line in f:
		#split the line based on the gaps between the number
		#take the first number which is the node as the dictionary key and all the other numbers that are the other nodes that 
		#this node is connected with through edges and take that as an array of integers to append as value of the certain
		#key of the dictionary
	       		d[int(line[0])] = map(int,line[1:len(line)-1].split())
	return d

#input file example
'''
1 4 5
2 5 
3 4
4 1 3 5
5 1 2 4
'''

#RUN THIS IN TERMINAL   ------------------------------------------> python hamiltonian_paths.py input_graph.txt <------------------------------------


def takeFileTerminal():	
	#take the first argument after the script command
	inFile = sys.argv[1]
	#take the second argument 

	#outFile = sys.argv[2]

	#return the files
	return inFile 
				

def main():
	#read the inputs from terminal
	inputFileName = takeFileTerminal()
	#determine the format of the file and take the input vertexes and edges
	dictionary = readFromaFile(inputFileName)
	#find the hamiltonian paths and circuits
	findEveryVertexPath(dictionary)

main()



