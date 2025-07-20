startX, startY, cargoX, cargoY, endX, endY = map(int, input().split())

user_cargo_x_diff = cargoX - startX
user_cargo_y_diff = cargoY - startY

cargo_end_x_diff = endX - cargoX
cargo_end_y_diff = endY - cargoY

cost_to_push_right = abs(user_cargo_x_diff - 1) + abs(user_cargo_y_diff)
cost_to_push_down = abs(user_cargo_x_diff) + abs(user_cargo_y_diff + 1)
cost_to_push_left = abs(user_cargo_x_diff + 1) + abs(user_cargo_y_diff)
cost_to_push_up = abs(user_cargo_x_diff) + abs(user_cargo_y_diff - 1)

moves = 0

if (user_cargo_x_diff == 0):
    if user_cargo_y_diff > 0:
        cost_to_push_down += 2

    else:
        cost_to_push_up += 2

if (user_cargo_y_diff == 0):
    if user_cargo_x_diff > 0:
        cost_to_push_left += 2

    else:
        cost_to_push_right += 2

box_x, box_y = "", ""
if cargo_end_x_diff > 0:
    box_x = "right"

elif cargo_end_x_diff < 0:
    box_x = "left"

else:
    box_x = "none"

if cargo_end_y_diff > 0:
    box_y = "up"

elif cargo_end_y_diff < 0:
    box_y = "down"

else:
    box_y = "none"


action_1 = 0
action_2 = 0

if box_x == "right":
    action_1 = cost_to_push_right

elif box_x == "left":
    action_1 = cost_to_push_left

else:
    action_1 = float('inf')

if box_y == "up":
    action_2 = cost_to_push_up

elif box_y == "down":
    action_2 = cost_to_push_down

else:
    action_2 = float('inf')

if action_1 <= action_2:
    moves += action_1
    moves += abs(cargo_end_x_diff)
    if action_2 != float('inf'):
        moves += 2
        moves += abs(cargo_end_y_diff)

else:
    moves += action_2
    moves += abs(cargo_end_y_diff)
    if action_1 != float('inf'):
        moves += 2
        moves += abs(cargo_end_x_diff)

print(moves)