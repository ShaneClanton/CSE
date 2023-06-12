#
# dfs.py
#
# This file provides a function implementing depth-first search for a
# route-finding problem. Various search utilities from "route.py" are
# used in this function, including the classes RouteProblem, Node, and
# Frontier.
# 
# YOUR COMMENTS INCLUDING CITATIONS
#
# Shane Clanton - 9/21/2022
# 


from route import Node
from route import Frontier


def DFS(problem, repeat_check=False):
    """Perform depth-first search to solve the given route finding
    problem, returning a solution node in the search tree, corresponding
    to the goal location, if a solution is found. Only perform repeated
    state checking if the provided boolean argument is true."""

    # PLACE YOUR CODE HERE
    dfsNode = Node(problem.start)
    
    dfsArr = Frontier(dfsNode, queue = False)
    visits = set()
    visits.add(dfsNode)
    
    if problem.is_goal(dfsNode.loc):
        return dfsNode
    while not dfsArr.is_empty():
        dfsNode = dfsArr.pop()
        if problem.is_goal(dfsNode.loc):
            return dfsNode     
        for x in dfsNode.expand(problem):
            if not repeat_check:
                dfsArr.add(x)   
            if x not in visits:
                visits.add(x)
                
                if repeat_check == True:
                    dfsArr.add(x)
                    
                        
    return None
