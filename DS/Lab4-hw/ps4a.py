###########################
# 6.0002 Problem Set 1a: Space Cows
# Name:
# Collaborators:
# Time:

import time

from ps4_partition import get_partitions

# ================================
# Part A: Transporting Space Cows
# ================================


# Problem 1
def load_cows(filename):
    """
    Read the contents of the given file.  Assumes the file contents contain
    data in the form of comma-separated cow name, weight pairs, and return a
    dictionary containing cow names as keys and corresponding weights as values.

    Parameters:
    filename - the name of the data file as a string

    Returns:
    a dictionary of cow name (string), weight (int) pairs
    """
    cows = {}
    f = open('ps4_cow_data.txt', 'r')
    for line in f:
        line = line.strip()
        parts = line.split(',')
        cows[parts[0]] = int(parts[1])
    f.close()
    return cows


# Problem 2
def greedy_cow_transport(cows, limit=10):
    """
    Uses a greedy heuristic to determine an allocation of cows that attempts to
    minimize the number of spaceship trips needed to transport all the cows. The
    returned allocation of cows may or may not be optimal.
    The greedy heuristic should follow the following method:

    1. As long as the current trip can fit another cow, add the largest cow that will fit
        to the trip
    2. Once the trip is full, begin a new trip to transport the remaining cows

    Does not mutate the given dictionary of cows.

    Parameters:
    cows - a dictionary of name (string), weight (int) pairs
    limit - weight limit of the spaceship (an int)

    Returns:
    A list of lists, with each inner list containing the names of cows
    transported on a particular trip and the overall list containing all the
    trips
    """
    trips = []
    sorted_cows = sorted(cows, key=cows.__getitem__, reverse=True)
    remaining = list(sorted_cows)
    while len(remaining) > 0:
        current_trip = []
        left_over = []
        total = 0
        for name in remaining:
            if total + cows[name] <= limit:
                current_trip.append(name)
                total += cows[name]
            else:
                left_over.append(name)
        trips.append(current_trip)
        remaining = left_over
    return trips


# Problem 3
def brute_force_cow_transport(cows, limit=10):
    """
    Finds the allocation of cows that minimizes the number of spaceship trips
    via brute force.  The brute force algorithm should follow the following method:

    1. Enumerate all possible ways that the cows can be divided into separate trips
        Use the given get_partitions function in ps1_partition.py to help you!
    2. Select the allocation that minimizes the number of trips without making any trip
        that does not obey the weight limitation

    Does not mutate the given dictionary of cows.

    Parameters:
    cows - a dictionary of name (string), weight (int) pairs
    limit - weight limit of the spaceship (an int)

    Returns:
    A list of lists, with each inner list containing the names of cows
    transported on a particular trip and the overall list containing all the
    trips
    """
    cow_names = list(cows.keys())
    best = None
    for partition in get_partitions(cow_names):
        valid = True
        for trip in partition:
            trip_weight = 0
            for cow in trip:
                trip_weight += cows[cow]
            if trip_weight > limit:
                valid = False
                break
        if valid:
            if best == None or len(partition) < len(best):
                best = partition
    return best
    


# Problem 4
def compare_cow_transport_algorithms():
    """
    Using the data from ps1_cow_data.txt and the specified weight limit, run your
    greedy_cow_transport and brute_force_cow_transport functions here. Use the
    default weight limits of 10 for both greedy_cow_transport and
    brute_force_cow_transport.

    Print out the number of trips returned by each method, and how long each
    method takes to run in seconds.

    Returns:
    Does not return anything.
    """
    cows = load_cows('ps4_cow_data.txt')

    start = time.time()
    greedy_result = greedy_cow_transport(cows)
    end = time.time()
    print('greedy number of trips: ', len(greedy_result))
    print('greedy time: ', f"{end-start:.5f}")

    start = time.time()
    brute_result = brute_force_cow_transport(cows)
    end = time.time()
    print('brute force number of trips: ', len(brute_result))
    print('brute time: ', f"{end-start:.5f}")

if __name__ == "__main__":
    compare_cow_transport_algorithms()
