#
# heuristic.py
#
# This Python script file provides two functions in support of minimax search
# using the expected value of game states. First, the file provides the
# function "expected_value_over_delays". This function takes as an argument
# a state of game play in which the current player has just selected an
# action. The function calculates the expected value of the state over all
# possible random results determining the amount of time before the
# Guardian changes gaze direction. This function calculates this value
# regardless of whose turn it is. The value of game states that result from
# different random outcomes is determined by calling "value". Second, the
# file provides a heuristic evaluation function for non-terminal game states.
# The heuristic value returned is between "max_payoff" (best for the
# computer player) and negative one times that value (best for the opponent).
# The heuristic function may be applied to any state of play. It uses
# features of the game state to predict the game payoff without performing
# any look-ahead search.
#
# This content is protected and may not be shared, uploaded, or distributed.
#
# This lab took much longer than intnded as it took much longer just to understand the code and how calculate the expected utility value as well as solving for the
# the heuristic function.
#
# Shane Clanton - Thu Nov  10 10:08:05 PDT 2022
#


from minimax import probability_of_time, value
from parameters import *


def expected_value_over_delays(state, ply):
    """Calculate the expected utility over all possible randomly selected
    Guardian delay times. Return this expected utility value."""
    expected = 0.0
    for i in range(2, 6):
        state.time_remaining = i
        expected += (probability_of_time(i) * value(state, ply))
    # PLACE YOUR CODE HERE
    # Note that the value of "ply" must be passed along, without
    # modification, to any function calls that calculate the value 
    # of a state.

    return expected


def heuristic_value(state):
    """Return an estimate of the expected payoff for the given state of
    game play without performing any look-ahead search. This value must
    be between the maximum payoff value and the additive inverse of the
    maximum payoff."""
    val = 0.0
    
    # PLACE YOUR CODE HERE
    if abs(state.e_loc) <= abs(state.w_loc):
        val = -max_payoff
    else:
        val = (state.e_loc + state.w_loc) * (max_payoff/(max_act_steps))
    
    if(state.current_turn == Player.east):
        val *= -1
    
    # Want to make sure that val is in between the max payoff as well as the additive inverse of the max payoff
    val = max(min(val, max_payoff), -max_payoff)
    
    return val
