#
# ucost.py
#
# This file provides a function implementing uniform cost search for a
# route finding problem. Various search utilities from "route.py" are
# used in this function, including the classes RouteProblem, Node, and
# Frontier.
#
# YOUR COMMENTS INCLUDING CITATIONS
# For astar.py it was very simillar to that of BFS and DFS from Programming assignment 0, so with that in mind what I did was take the code
# that was used for there and put it here. all the while making changes to the name of my variables and changes to little bits of the code as
# as there are some parts to the code that are different.
# Some of the changes between the functions are that in this case ucsArr priority queue now sorts by g(n) cost and so now you need to implement
# that to the code as well as throughout the while loop.
# Shane Clanton - 10/09/2022
#


from route import Node
from route import Frontier


def uniform_cost_search(problem, repeat_check=False):
    """Perform uniform cost search to solve the given route finding
    problem, returning a solution node in the search tree, corresponding
    to the goal location, if a solution is found. Only perform repeated
    state checking if the provided boolean argument is true."""

    # PLACE YOUR CODE HERE

    ucsNode = Node(problem.start)
    
    ucsArr = Frontier(ucsNode, sort_by='g')
    visits = set()
    visits.add(ucsNode)
    
    if problem.is_goal(ucsNode.loc):
        return ucsNode
    while not ucsArr.is_empty():
        ucsNode = ucsArr.pop()
        if problem.is_goal(ucsNode.loc):
            return ucsNode
        for g in ucsNode.expand(problem):
            if repeat_check:
                if g in visits:
                    if ucsArr.contains(g) and g.value(sort_by = 'g') < ucsArr.__getitem__(g):
                        ucsArr.__delitem__(g)
                        ucsArr.add(g)
                else:
                    ucsArr.add(g)
                    visits.add(g)                
            else:
                ucsArr.add(g)
                visits.add(g)
    return None
