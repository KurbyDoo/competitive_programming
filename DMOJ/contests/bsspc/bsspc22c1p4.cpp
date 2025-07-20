// Month Day, Year

#include <iostream>
#include <queue>

using std::abs;
using std::cin;
using std::cout;
using std::max;
using std::queue;

int n, t, temp, curTime, count, maxPerson = 0;
bool removed = false;
queue<int> people;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        people.push(temp);
    }

    int next;
    while (true)
    {
        if (people.empty())
            break;
        next = people.front();
        people.pop();
        curTime += next;
        maxPerson = max(maxPerson, next);
        if (curTime > t && !removed) {
            curTime -= maxPerson;
            count -= 1;
            removed = true;
        }

        if (curTime > t)
            break;

        count++;
    }
    if (!removed)
        count--;
    printf("%d\n", count);
    return 0;
}