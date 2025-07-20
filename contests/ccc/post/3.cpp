#include <bits/stdc++.h>
using namespace std;
int n;
int nums[300010];
int target[300010];
vector<array<int, 3>> ops;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;

    // Take in the two streams of numbers
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> target[i];
    }

    // We start by trying to find the first (0th index)
    // target number inside the original array
    int nums_pos = 0, start_pos = 0, end_pos = 0;
    bool works = true;
    while (end_pos < n) {
        // Reset the current range to the next number
        start_pos = end_pos;

        // Extend the range of consecutive numbers
        // (all numbers between start_pos and end_pos have the same value)
        while (end_pos < n && target[end_pos] == target[end_pos + 1]) {
            end_pos++;
        }

        // Find the location of the next number that matches the target number
        // (mapping the target number to a number in the original array)
        while (nums_pos < n && nums[nums_pos] != target[end_pos]) nums_pos++;

        // If the number does not exist and the index goes out of range
        // It is impossible to create such a sequence
        if (nums_pos == n) {
            works = false;
            break;
        }

        // If the number is the same as the original array, no
        // operation is needed since the number is already in place
        if (start_pos == end_pos && start_pos == nums_pos) {
            end_pos++;
            continue;
        }
        
        // Depending on the location of the mapped number
        // determine which operation is needed
        if (nums_pos <= start_pos) {
            ops.push_back({n - nums_pos, end_pos, 'R'});
        } else if (nums_pos >= end_pos) {
            ops.push_back({nums_pos, start_pos, 'L'});
        } else {
            ops.push_back({nums_pos, start_pos, 'L'});
            ops.push_back({n - nums_pos, end_pos, 'R'});
        }
        
        // Increment to find the next number in the target array
        end_pos += 1;
    }

    // Sort the numbers
    // Right operations are sorted in ascending order
    // Left operations are sorted in decreasing order
    sort(ops.begin(), ops.end());

    if (works) {
        printf("YES\n");
        printf("%d\n", ops.size());
        
        // Print out all the operations
        for (auto [l, r, op]: ops) {
            if (op == 'L') {
                printf("%c %d %d\n", op, r, l);
                
            } else {
                printf("%c %d %d\n", op, n - l, r);

            }
        }
    } else {
        printf("NO\n");
    }
}
// TEST CASES
// 14
// 2 3 4 8 9 2 3 6 8 3 7 1 4 1
// 2 2 3 4 2 2 2 2 3 3 1 4 1 1

// 7
// 1 1 1 2 3 2 1
// 1 3 2 1 1 1 1

// 10
// 1 2 3 2 1 1 2 3 2 1
// 2 3 3 3 2 3 2 1 1 1