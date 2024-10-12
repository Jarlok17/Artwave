# src/python_module/main.py

from python_module.tasks import *

if __name__ == "__main__":
    # A) Сортуємо словник за значеннями
    my_dict = {0: 10, 1: 20, 2: 5}
    sorted_dict = sort_dict_by_values(my_dict)
    print("Sorted Dictionary:", sorted_dict)

    # B) Додаємо ключ до словника
    updated_dict = add_key_to_dict(my_dict, 3, 30)
    print("Updated Dictionary:", updated_dict)

    # C) Об'єднуємо словники
    dic1 = {1: 10, 2: 20}
    dic2 = {3: 30, 4: 40}
    dic3 = {5: 50, 6: 60}
    combined_dict = combine_dicts(dic1, dic2, dic3)
    print("Combined Dictionary:", combined_dict)

    # D) Перевіряємо наявність ключа
    key_to_check = 2
    exists = check_key_in_dict(my_dict, key_to_check)
    print(f"Key {key_to_check} exists in dictionary:", exists)

    # E) Ітеруємо по словнику
    print("Iterating over dictionary:")
    iterate_dict(my_dict)

    # F) Генеруємо словник з квадратами до n
    n = 5
    square_dict = generate_square_dict(n)
    print(f"Square Dictionary (1 to {n}):", square_dict)

    # G) Генеруємо словник квадратів до 15
    square_dict_up_to_15 = generate_square_dict_up_to_15()
    print("Square Dictionary (1 to 15):", square_dict_up_to_15)

    # H) Створюємо set
    my_set = create_set([1, 2, 3, 4, 5])
    print("Set created:", my_set)

    # I) Ітеруємо по set
    print("Iterating over set:")
    iterate_set(my_set)

    # J) Додаємо значення до set
    add_value_to_set(my_set, 6)
    print("Set after adding 6:", my_set)

    # K) Видаляємо елемент з set
    remove_element_from_set(my_set, 2)
    print("Set after removing 2:", my_set)

    # L) Видаляємо елемент, якщо він є в set
    remove_if_in_set(my_set, 3)
    print("Set after trying to remove 3:", my_set)

    # M) Знаходимо об'єднання sets
    another_set = {4, 5, 6, 7}
    intersection = intersection_of_sets(my_set, another_set)
    print("Intersection of sets:", intersection)

    # N) Сумуємо всі елементи списку
    my_list = [1, 2, 3, 4, 5]
    total_sum = sum_of_list(my_list)
    print("Sum of list:", total_sum)

    # O) Множимо всі елементи списку
    product = product_of_list(my_list)
    print("Product of list:", product)

    # P) Виводимо найбільше та найменше значення у списку
    min_value, max_value = min_max_of_list(my_list)
    print("Min value:", min_value, "Max value:", max_value)

    # Q) Сортуємо кортежі за останнім елементом
    tuple_list = [(2, 5), (1, 2), (4, 4), (2, 3), (2, 1)]
    sorted_tuples = sort_tuples_by_last_element(tuple_list)
    print("Sorted tuples by last element:", sorted_tuples)

    # R) Видаляємо повторювані елементи
    list_with_duplicates = [1, 2, 2, 3, 4, 4, 5]
    unique_list = remove_duplicates(list_with_duplicates)
    print("List without duplicates:", unique_list)

    # S) Друкуємо список після видалення елементів за індексами
    original_list = ['Red', 'Green', 'White', 'Black', 'Pink', 'Yellow']
    indices_to_remove = [0, 4, 5]  # Віддаляємо 0, 4 та 5
    modified_list = remove_elements_by_index(original_list, indices_to_remove)
    print("List after removing specified indices:", modified_list)

    # T) Множимо всі значення в списку
    another_list = (8, 2, 3, -1, 7)
    multiplied_result = multiply_list_values(another_list)
    print("Multiplied result of list:", multiplied_result)

    # U) Розраховуємо факторіал числа
    factorial_result = factorial(5)
    print("Factorial of 5:", factorial_result)

    # V) Патерн
    print("Printing pattern:")
    print_pattern(4)

