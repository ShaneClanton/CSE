#
# bfs.py
#
# This file provides a function implementing breadth-first search for a
# route-finding problem. Various search utilities from "route.py" are
# used in this function, including the classes RouteProblem, Node, and
# Frontier.
#
# YOUR COMMENTS INCLUDING CITATIONS
#
# Shane Clanton - 9/21/2022
#


from platform import node
from re import search
from sre_constants import FAILURE
from route import Node
from route import Frontier


def BFS(problem, repeat_check=False):
    """Perform breadth-first search to solve the given route finding
    problem, returning a solution node in the search tree, corresponding
    to the goal location, if a solution is found. Only perform repeated
    state checking if the provided boolean argument is true."""

    # PLACE YOUR CODE HERE
    
    bfsNode = Node(problem.start)
    
    bfsArr = Frontier(bfsNode, queue = True)
    visits = set()
    visits.add(bfsNode)
    
    if problem.is_goal(bfsNode.loc):
        return bfsNode
    while not bfsArr.is_empty():
        bfsNode = bfsArr.pop()
        if problem.is_goal(bfsNode.loc):
            return bfsNode     
        for x in bfsNode.expand(problem):
            if not repeat_check:
                bfsArr.add(x)   
            if x not in visits:
                visits.add(x)
                
                if repeat_check == True:
                    bfsArr.add(x)
                       
    return None
