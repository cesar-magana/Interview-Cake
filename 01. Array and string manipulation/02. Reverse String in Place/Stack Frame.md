# Stack Frame

## Overview

The **call stack** is what a program uses to keep track of function calls. The call stack is made up of **stack frames**—one for each function call.

For instance, say we called a function that rolled two dice and printed the sum.

```python
  def roll_die():
    return random.randint(1, 6)

def roll_two_and_sum():
    total = 0
    total += roll_die()
    total += roll_die()
    print total

roll_two_and_sum()
```

We're still translating this code to C++. Here it is in Python 2.7:

CC#C++JavaJavaScriptObjective-CPHPPython 2.7Python 3.6RubySwift

First, our program calls rollTwoAndSum(). It goes on the call stack:

```
rollTwoAndSum()
```

That function calls rollDie(), which gets pushed on to the top of the call stack:

```
rollDie()
rollTwoAndSum()
```

Inside of rollDie(), we call random.randint(). Here's what our call stack looks like then:

```
random.randint()
rollDie()
rollTwoAndSum()
```

When random.randint() finishes, we return back to rollDie() by removing ("popping") random.randint()'s stack frame.

```
rollDie()
rollTwoAndSum()
```

Same thing when rollDie() returns:

```
rollTwoAndSum()
```

We're not done yet! rollTwoAndSum() calls rollDie() *again*:

```
rollDie()
rollTwoAndSum()
```

Which calls random.randint() again:

```
random.randint()
rollDie()
rollTwoAndSum()
```

random.randint() returns, then rollDie() returns, putting us back in rollTwoAndSum():

```
rollTwoAndSum()
```

Which calls print():

```
print()
rollTwoAndSum()
```

## What's stored in a stack frame?

What *actually* goes in a function's stack frame?

A stack frame usually stores:

- Local variables
- Arguments passed into the function
- Information about the caller's stack frame
- The *return address*—what the program should do after the function returns (i.e.: where it should "return to"). This is usually somewhere in the middle of the caller's code.

Some of the specifics vary between processor architectures. For instance, AMD64 (64-bit x86) processors pass some arguments in registers and some on the call stack. And, ARM processors (common in phones) store the return address in a special register instead of putting it on the call stack.

## The Space Cost of Stack Frames

Each function call creates its own stack frame, taking up space on the call stack. That's important because it can impact the *space complexity* of an algorithm. *Especially* when we use **recursion**.

For example, if we wanted to multiply all the numbers between 11 and n*n*, we could use this recursive approach:

```cpp
  int product1ToN(int n)
{
    // we assume n >= 1
    return (n > 1) ? (n * product1ToN(n - 1)) : 1;
}
```

CC#C++JavaJavaScriptObjective-CPHPPython 2.7Python 3.6RubySwift

What would the call stack look like when n = 10?

First, product1ToN() gets called with n = 10:

```
    product1ToN()    n = 10
```

This calls product1ToN() with n = 9.

```
    product1ToN()    n = 9
    product1ToN()    n = 10
```

Which calls product1ToN() with n = 8.

```
    product1ToN()    n = 8
    product1ToN()    n = 9
    product1ToN()    n = 10
```

And so on until we get to n = 1.

```
    product1ToN()    n = 1
    product1ToN()    n = 2
    product1ToN()    n = 3
    product1ToN()    n = 4
    product1ToN()    n = 5
    product1ToN()    n = 6
    product1ToN()    n = 7
    product1ToN()    n = 8
    product1ToN()    n = 9
    product1ToN()    n = 10
```

Look at the size of all those stack frames! The entire call stack takes up O(n)*O*(*n*) space. That's right—we have an O(n)*O*(*n*) space cost even though our function itself doesn't create any data structures!

What if we'd used an iterative approach instead of a recursive one?

```cpp
  int product1ToN(int n)
{
    // we assume n >= 1

    int result = 1;
    for (int num = 1; num <= n; ++num) {
        result *= num;
    }

    return result;
}
```

This version takes a constant amount of space. At the beginning of the loop, the call stack looks like this:

```
    product1ToN()    n = 10, result = 1, num = 1
```

As we iterate through the loop, the local variables change, but we stay in the same stack frame because we don't call any other functions.

```
    product1ToN()    n = 10, result = 2, num = 2
```



```
    product1ToN()    n = 10, result = 6, num = 3
```



```
    product1ToN()    n = 10, result = 24, num = 4
```

In general, even though the compiler or interpreter will take care of managing the call stack for you, it's important to consider the depth of the call stack when analyzing the space complexity of an algorithm.

**Be especially careful with recursive functions!** They can end up building huge call stacks.

What happens if we run out of space? It's a **stack overflow**! In C++, the program will just crash with a segfault.

If the *very last* thing a function does is call another function, then its stack frame might not be needed any more. The function *could* free up its stack frame before doing its final call, saving space.

This is called **tail call optimization** (TCO). If a recursive function is optimized with TCO, then it may not end up with a big call stack.

In general, most languages *don't* provide TCO. Scheme is one of the few languages that guarantee tail call optimization. Some Ruby, C, and Javascript implementations *may* do it. Python and Java decidedly don't.