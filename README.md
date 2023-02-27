# C++ Concurrent Programming
Using the deferred option of std::sync allows us to delay the execution of the controller task until we receive input indicating a key has been hit. 
This eliminates the need for condition variables, mutexes, and other synchronization mechanisms in the controller task.
# Using promises and shared_futures to Calculate Factorials in Multiple Threads
This code demonstrates how to use promises and futures to calculate the factorial of a given number in multiple threads. The program defines a Fact function that takes a shared_future object as an argument and calculates the factorial of the value it receives from the future.

In the main function, two promise objects are created, and their corresponding futures are shared using shared_future. The program then creates a new thread using std::async and passes a reference to the first shared future object to the Fact function to calculate the factorial of the value. The value of the promise object is set to 3, and the result is printed to the console using the get() function of the future object.

The program then creates a new shared future object from the second promise object, and another thread is created using std::async. This time, the reference to the second shared future object is passed to the Fact function to calculate the factorial of the new value of 4. The result is printed to the console using the get() function of the second future object.

This code demonstrates how promises and futures can be used to coordinate the execution of multiple threads and pass data between them. It also shows how shared futures can be used to share the same data between multiple threads without requiring the creation of additional promises.
