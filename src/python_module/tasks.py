# src/python_module/tasks.py

def sort_dict_by_values(d):
    """A) Sorts a dictionary by its values."""
    return dict(sorted(d.items(), key=lambda item: item[1]))

def add_key_to_dict(d, key, value):
    """B) Adds a key to the dictionary."""
    d[key] = value
    return d

def combine_dicts(*dicts):
    """C) Combines given dictionaries into a new one."""
    combined = {}
    for d in dicts:
        combined.update(d)
    return combined

def check_key_in_dict(d, key):
    """D) Checks if a key exists in the dictionary."""
    return key in d

def iterate_dict(d):
    """E) Iterates over the dictionary using a for loop."""
    for key, value in d.items():
        print(f"{key}: {value}")

def generate_square_dict(n):
    """F) Generates a dictionary of numbers from 1 to n and their squares."""
    return {x: x * x for x in range(1, n + 1)}

def generate_square_dict_up_to_15():
    """G) Generates a dictionary where keys are numbers from 1 to 15 and values are their squares."""
    return {x: x * x for x in range(1, 16)}

def create_set(elements):
    """H) Creates a set."""
    return set(elements)

def iterate_set(s):
    """I) Iterates through a set."""
    for item in s:
        print(item)

def add_value_to_set(s, value):
    """J) Adds a value to the set."""
    s.add(value)

def remove_element_from_set(s, value):
    """K) Removes an element from the set."""
    s.discard(value)

def remove_if_in_set(s, value):
    """L) Removes an element if it exists in the set."""
    if value in s:
        s.remove(value)

def intersection_of_sets(s1, s2):
    """M) Finds the intersection of two sets."""
    return s1 & s2

def sum_of_list(lst):
    """N) Sums all elements in a list."""
    return sum(lst)

def product_of_list(lst):
    """O) Multiplies all elements in a list."""
    product = 1
    for num in lst:
        product *= num
    return product

def min_max_of_list(lst):
    """P) Returns the largest and smallest values in a list."""
    return min(lst), max(lst)

def sort_tuples_by_last_element(tuples):
    """Q) Sorts a list of tuples by the last element."""
    return sorted(tuples, key=lambda x: x[-1])

def remove_duplicates(lst):
    """R) Removes duplicate elements from a list."""
    return list(set(lst))

def remove_elements_by_index(lst, indices):
    """S) Prints a list after removing elements at specified indices."""
    return [item for idx, item in enumerate(lst) if idx not in indices]

def multiply_list_values(lst):
    """T) Multiplies all values in a list."""
    product = 1
    for num in lst:
        product *= num
    return product

def factorial(n):
    """U) Calculates the factorial of a number."""
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n - 1)

def count_case(sentence):
    """V) Counts the number of uppercase and lowercase letters in a string."""
    upper_case_count = sum(1 for c in sentence if c.isupper())
    lower_case_count = sum(1 for c in sentence if c.islower())
    return upper_case_count, lower_case_count

def print_pattern(n):
    """Prints a pattern using loops."""
    for i in range(1, n + 1):
        print('* ' * i)
    for i in range(n - 1, 0, -1):
        print('* ' * i)
