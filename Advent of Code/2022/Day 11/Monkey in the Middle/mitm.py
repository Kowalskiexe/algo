#!/usr/bin/env python

from typing import Callable


def parse_operation(text):
    text = text.split(' ')

    def f(n):
        if text[0] == 'old':
            first_arg = n
        else:
            first_arg = int(text[0])
        if text[1] == '*':
            def operation(a, b):
                return a * b
        else:
            def operation(a, b):
                return a + b
        if text[2] == 'old':
            second_arg = n
        else:
            second_arg = int(text[2])
        return operation(first_arg, second_arg)
    return f


class Monkey:
    monkey_id: int
    items = []
    test: int
    operation: Callable
    receiver_true: int
    receiver_false: int
    monkey_pool: []
    inspection_count = 0

    def __init__(self,
                 monkey_id,
                 items,
                 operation,
                 test,
                 receiver_true,
                 receiver_false,
                 monkey_pool):
        self.monkey_id = monkey_id
        self.items = items
        self.operation = parse_operation(operation)
        self.test = test
        self.receiver_true = receiver_true
        self.receiver_false = receiver_false
        self.monkey_pool = monkey_pool

    def turn(self):
        if len(self.items) == 0:
            print('  Monkey isn\'t holding any items')
            return
        self.__inspect()
        self.__throw()

    def __inspect(self):
        print('  Monkey inspect an item witha worry level of', self.items[0])
        self.items[0] = self.operation(self.items[0])
        print('    Warry level is now', self.items[0])
        self.items[0] //= 3
        print('    Monkey gets bored with item. Worry level is divided by 3 to', self.items[0])
        self.inspection_count += 1

    def find_monkey(self, target_id):
        for monkey in self.monkey_pool:
            if monkey.monkey_id == target_id:
                return monkey
        raise Exception(f'no monkey with id {target_id} in monkey_pool')

    def add_item(self, item):
        self.items.append(item)

    def __throw(self):
        if self.items[0] % self.test == 0:
            print('    Current worry level is divisible by', self.test)
            print(f'    Item with worry level {self.items[0]} is thrown to monkey {self.receiver_true}.')
            receiver = self.find_monkey(self.receiver_true)
            receiver.add_item(self.items[0])
            del self.items[0]
        else:
            print('    Current worry level is not divisible by', self.test)
            print(f'    Item with worry level {self.items[0]} is thrown to monkey {self.receiver_false}.')
            receiver = self.find_monkey(self.receiver_false)
            receiver.add_item(self.items[0])
            del self.items[0]


def main():
    monkeys = []

    input_raw = open(0).read().splitlines()
    for i, line in enumerate(input_raw[::7]):
        print('monkey', i)
        items = input_raw[i * 7 + 1].strip()
        items = items.split(' ')
        items = items[2:]
        items = [item.replace(',', '') for item in items]
        items = [int(item) for item in items]
        print('items:', items)
        operation = input_raw[i * 7 + 2].strip()
        operation = operation.split(' ')
        operation = f'{operation[3]} {operation[4]} {operation[5]}'
        print('operation:', operation)
        test = input_raw[i * 7 + 3].strip()
        test = test.split(' ')
        test = int(test[3])
        print('test:', test)
        receiver_true = input_raw[i * 7 + 4].strip()
        receiver_true = receiver_true.split(' ')
        receiver_true = int(receiver_true[5])
        print('receiver_true:', receiver_true)
        receiver_false = input_raw[i * 7 + 5].strip()
        receiver_false = receiver_false.split(' ')
        receiver_false = int(receiver_false[5])
        print('receiver_false:', receiver_false)
        print('')
        monkeys.append(Monkey(
            i,
            items,
            operation,
            test,
            receiver_true,
            receiver_false,
            monkeys,
        ))

    for i in range(1, 21):
        print('ROUND', i)
        for monkey in monkeys:
            print(f'Monkey {monkey.monkey_id}:')
            while len(monkey.items) > 0:
                monkey.turn()

    for monkey in monkeys:
        print(monkey.monkey_id, monkey.inspection_count)

    counts = [monkey.inspection_count for monkey in monkeys]
    counts.sort()

    monkey_business = counts[-1] * counts[-2]
    print(monkey_business)


if __name__ == '__main__':
    main()
