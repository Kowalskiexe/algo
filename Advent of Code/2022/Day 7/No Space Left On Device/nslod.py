#!/usr/bin/env python

class Node:
    def __init__(self, name, parent):
        self.name = name
        self.parent = parent

    def set_size(self, size):
        self.size = 0
        curr = self
        while curr is not None:
            curr.size += size
            curr = curr.parent

    def set_children(self, children):
        self.children = children


input_raw = open(0).read().split('\n')
input_raw = [line.split(' ') for line in input_raw]
del input_raw[-1]

all_nodes = []

current_node = None
for i, line in enumerate(input_raw):
    if line[0] != '$':
        continue
    command = line[1]
    if command == 'cd':
        dir_name = line[2]
        if dir_name == '..':
            current_node = current_node.parent
        else:
            new_node = Node(dir_name, current_node)
            current_node = new_node
            all_nodes.append(new_node)
    if command == 'ls':
        j = i + 1
        dirs = []
        files = []
        while j < len(input_raw) and input_raw[j][0] != '$':
            if input_raw[j][0] == 'dir':
                dirs.append(input_raw[j][1])
            else:
                files.append(input_raw[j])
            j += 1
        print(current_node.name)
        print('dirs')
        print(dirs)
        print('files')
        print(files)
        total_size = sum([int(f[0]) for f in files])
        print(total_size)
        current_node.set_size(total_size)

for node in all_nodes:
    print(f'{node.name} {node.size}')

at_most_100k = [node for node in all_nodes if node.size <= 100_000]
for node in at_most_100k:
    print(node.name)
result = sum([node.size for node in at_most_100k])
print(result)
