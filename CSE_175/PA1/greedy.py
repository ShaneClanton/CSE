#
# greedy.py
#
# This file provides a function implementing greedy best-first search for
# a route finding problem. Various search utilities from "route.py" are
# used in this function, including the classes RouteProblem, Node, and
# Frontier. Also, this function uses heuristic function objects defined
# in the "heuristic.py" file.
#
# YOUR COMMENTS INCLUDING CITATIONS
# Like stated in ucost.py comment section, I just impemented the psuedo code provided to us in the lecture slides and modified the parameters 
# for this lab.
#
# Shane Clanton - 10/09/2022
#


from route import Node
from route import Frontier


def greedy_search(problem, h, repeat_check=False):
    """Perform greedy best-first search to solve the given route finding
    problem, returning a solution node in the search tree, corresponding
    to the goal location, if a solution is found. Only perform repeated
    state checking if the provided boolean argument is true."""

    # PLACE YOUR CODE HERE
    greedNode = Node(problem.start, h_eval = h.h_cost(problem.start))
    
    greedArr = Frontier(greedNode, sort_by='h')
    visits = set()
    visits.add(greedNode)
    
    if problem.is_goal(greedNode.loc):
        return greedNode
    while not greedArr.is_empty():
        greedNode = greedArr.pop()
        if problem.is_goal(greedNode.loc):
            return greedNode
        for H in greedNode.expand(problem, h):
            if repeat_check:
                if H in visits:
                    if greedArr.contains(H) and H.value(sort_by = 'h') < greedArr.__getitem__(H):
                        greedArr.__delitem__(H)
                        greedArr.add(H)
                else:
                    greedArr.add(H)
                    visits.add(H)                
            else:
                greedArr.add(H)
                visits.add(H)
    return None
