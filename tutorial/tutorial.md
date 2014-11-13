# UiO Programming Challenge Tutorial
Input must be read from _stdin_, and ouput must be written _stdout_. An
explanation of how to do this in each language is shown below.

If you have questions don't hesitate asking one of the organizers.

### Python
In general input must be read from `sys.stdin` which acts like a normal file.

If input is a single number, we can read it like this:

```python
from sys import stdin

input = stdin.read()
n = int(input)

# do stuff with n here
```

Writing to _stdout_ is simply what happens when you use `print`.

If output is supposed to be `Hello, world!`, we can write it to _stdout_ like
this:

```python
print 'Hello, world!'
```

### Java
_stdin_ can be accessed through `System.in`. The easiest is just to use
`Scanner`.

If input is a single number, we can read it like this:

```java
import java.util.Scanner;

// ...

    Scanner in = new Scanner(System.in);
    int n = in.nextInt();

    // do stuff with n here

// ...
```

_stdout_ can be accessed through `System.out`. This is what you normally do.

If output is supposed to be `Hello, world!`, we can write it to _stdout_ like
this:

```java
System.out.println("Hello, world!");
```

### C
In C `main` must return `0` in order for the solution to be accepted. Otherwise
the system thinks an error has occured.

`scanf` reads from _stdin_.

If input is a single number, we can read it like this:

```c
#include <stdio.h>

/* ... */

int n;
scanf("%d", &n);

/* do stuff with n here */
```

`printf` writes to _stdout_. In C it is important to remember to write a
newline after the answer.

If output is supposed to be `Hello, world!`, we can write it to _stdout_ like
this (remember the newline):

```c
#include <stdio.h>

/* ... */

printf("Hello, world!\n");
```

### C++
In C++ `main` must return `0` in order for the solution to be accepted. Otherwise
the system thinks an error has occured.

`cin` reads from _stdin_.

If input is a single number, we can read it like this:

```c++
#include <iostream>

using namespace std;
// ...

int n;
cin >> n;

// do stuff with n here
```

`cout` writes to _stdout_. In C++ it is important to remember to write a
newline after the answer.

If output is supposed to be `Hello, world!`, we can write it to _stdout_ like
this (remember the `endl`):

```c
#include <iostream>

using namespace std;
// ...

cout << "Hello, world!" << endl;
```

## Example
See the [example problem text](summing.html). This is similar to the problems
you will get in the contest.

### Python
```python
from sys import stdin

# read the first line of input and convert it to a number
n = int(stdin.next())

# loop through all the remaining lines in the input
for line in stdin:
    # convert all the number strings to integers
    numbers = map(int, line.split())

    # find the sum and print the result
    print sum(numbers)
```

### Java
```java
import java.util.Scanner;

public class Summing {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();

        for (int i = 0; i < n; ++i) {
            // sum the ten integers
            int sum = 0;

            for (int j = 0; j < 10; ++j) {
                sum += in.nextInt();
            }

            // print the result
            System.out.println(sum);
        }
    }
}
```

### C
```c
#include <stdio.h>

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int sum = 0;

        for (int j = 0; j < 10; ++j) {
            int num;
            scanf("%d", &num);

            sum += num;
        }

        printf("%d\n", sum);
    }

    return 0;
}
```

### C++
```c++
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int sum = 0;

        for (int j = 0; j < 10; ++j) {
            int num;
            cin >> num;

            sum += num;
        }

        cout << sum << endl;
    }

    return 0;
}
```
