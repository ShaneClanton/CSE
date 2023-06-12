#
# astar.py
#
# This file provides a function implementing A* search for a route finding
# problem. Various search utilities from "route.py" are used in this function,
# including the classes RouteProblem, Node, and Frontier. Also, this function
# uses heuristic function objects defined in the "heuristic.py" file.
#
# YOUR COMMENTS INCLUDING CITATIONS
# Like stated in ucost.py and greedy.py comment section, I just impemented the psuedo code provided to us in the lecture slides and modified the parameters 
# for this lab.
# 
# Shane Clanton - 10/09/2022
#


from route import Node
from route import Frontier


def a_star_search(problem, h, repeat_check=False):
    """Perform A-Star search to solve the given route finding problem,
    returning a solution node in the search tree, corresponding to the goal
    location, if a solution is found. Only perform repeated state checking if
    the provided boolean argument is true."""

    # PLACE YOUR CODE HERE

    ANode = Node(problem.start, h_eval = h.h_cost(problem.start))
    
    AArr = Frontier(ANode, sort_by='f')
    visits = set()
    visits.add(ANode)
    
    if problem.is_goal(ANode.loc):
        return ANode
    while not AArr.is_empty():
        ANode = AArr.pop()
        if problem.is_goal(ANode.loc):
            return ANode
        for f in ANode.expand(problem, h):
            if repeat_check:
                if f in visits:
                    if AArr.contains(f) and f.value(sort_by = 'f') < AArr.__getitem__(f):
                        AArr.__delitem__(f)
                        AArr.add(f)
                else:
                    AArr.add(f)
                    visits.add(f)                
            else:
                AArr.add(f)
                visits.add(f)
    return None
