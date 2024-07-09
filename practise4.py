from collections import deque
import copy

def is_valid_move(state, from_stack, to_stack):
    if from_stack == to_stack or not state[from_stack]:
        return False  # Invalid move
    if state[from_stack][-1] == "B" and state[to_stack] and state[to_stack][-1] == "A":
        return False  # B cannot be placed above A
    if "C" in state[from_stack] and state[to_stack] and state[to_stack][-1] == "A":
        return False  # C cannot be above A
    if state[from_stack][-1] == "C" and state[to_stack] and state[to_stack][-1] == "B":
        return False  # C cannot be placed above B
    return True

def move_block(state, from_stack, to_stack):
    if not is_valid_move(state, from_stack, to_stack):
        return None  # Invalid move
    new_state = copy.deepcopy(state)
    block = new_state[from_stack].pop()  # Remove block from source stack
    new_state[to_stack].append(block)  # Add block to destination stack
    return new_state

def actions(state):
    available_actions = []
    for i in range(len(state)):
        for j in range(len(state)):
            if is_valid_move(state, i, j):
                available_actions.append((i, j))
    return available_actions

def bfs(initial_state, goal_state):
    visited = set()
    queue = deque([(initial_state, [])])

    while queue:
        state, path = queue.popleft()
        if state == goal_state:
            return path + [state]
        visited.add(tuple(map(tuple, state)))
        for action in actions(state):
            new_state = move_block(state, *action)
            if tuple(map(tuple, new_state)) not in visited:
                queue.append((new_state, path + [state]))
    return None

def main():
    initial_state = [["A"], ["B", "C"], []]
    goal_state = [[], [], ["A", "B", "C"]]
    print("Initial state:")
    for stack in initial_state:
        print(stack)
    print("Goal state:")
    for stack in goal_state:
        print(stack)
    print("Step-wise solution using Breadth-First Search:")
    result = bfs(initial_state, goal_state)
    if result:
        print("Result found:")
        for state in result:
            print(state)
    else:
        print("Solution not found.")

main()
