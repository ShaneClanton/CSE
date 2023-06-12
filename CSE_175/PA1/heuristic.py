#
# heuristic.py
#
# This script defines a utility class that can be used as an implementation
# of a frontier state (location) evaluation function for use in route-finding
# heuristic search algorithms. When a HeuristicSearch object is created,
# initialization code can be executed to prepare for the use of the heuristic
# during search. In particular, a RouteProblem object is typically provided 
# when the HeuristicFunction is created, providing information potentially
# useful for initialization. The actual heuristic cost function, simply
# called "h_cost", takes a state (location) as an argument.
#
# YOUR COMMENTS INCLUDING CITATIONS
#
# Shane Clanton - 10/25/2022
#


import route


class HeuristicFunction:
    """A heuristic function object contains the information needed to
    evaluate a state (location) in terms of its proximity to an optimal
    goal state."""
    
    def __init__(self, problem=None):
        self.problem = problem
        # PLACE ANY INITIALIZATION CODE HERE
        self.goal = problem.goal
        # initialize self.hour to zero.
        self.hour = 0
        # all_roads will look at all possible locations and map to them.
        all_roads = problem.map.locations()
        
        for streets in all_roads:
            all_location = (problem.map.get_result(streets))
            for path in all_location.values():
                # distance here calculates the distanace between two points, that being streets and path.
                distance =  problem.map.euclidean_distance(streets, path)
                # In order to calculate the distance, you need to divide the distance by the speed, which is just the road cost from start to finish.
                hour = distance / problem.map.get(streets, path)
                # In order to prevent the heuristic function from being underestimated, you need to return the highest value of hour.
                if hour > self.hour:
                    self.hour = hour
        
    def h_cost(self, loc=None):
        """An admissible heuristic function, estimating the cost from
        the specified location to the goal state of the problem."""
        # a heuristic value of zero is admissible but not informative
        value = 0.0
        if loc is None:
            return value
        else:
            # PLACE YOUR CODE FOR CALCULATING value OF loc HERE
            
            # to calcualte the value of loc you must divide the distance "dis" by self.hour
            dis = self.problem.map.euclidean_distance(loc, self.goal)
            value = dis / self.hour
            
            return value
        # admissable, initialize could be left blank or do things within h cost; depends on logic
