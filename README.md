# Philosophers (One of the classic problems in the synchronization)


# Real Life Example of Threads

-   You are typing a paragraph on MS word. But in background one more thread running and checking your spelling mistakes. As soon as you do a typo the other thread notifies you about the typo.. And makes your life easy.

-   Online bus/anything ticket booking : here many users trying to book available ticket at same time (ex : tatkal booking ) , here application needs to handle different threads (diff users request to server ) , if tickets sold out/not available then rest users will get correct response as not available to book .

-   Lets take an example of bank ,let’s suppose we have an online banking system, where people can log in and access their account information. Whenever someone logs in to their account online, they receive a separate and unique thread so that different bank account holders can access the central system simultaneously.

# The Problem Statement

Consider five philosophers who spend their lives thinking and eating , thoses philosophers share a circular table surrounded by five chairs, each belonging to one philosopher. In the center of the table is a bowl of rice, and the table is laid with 5 single forks



When a philosopher thinks, he does not interact with her colleagues and from time to time a philosopher gets hungry so he tries to pick up the two forks that are closest to him (the forks that are between him and his left and right neighbors)


A philosopher may pick up only one fork at a time He cannot pick up a fork that is already in the hand of a neighbor , When a hungry philosopher has both his forks at the same time, he eats without releasing his forks so When he is finished eating, he puts down both of his forks and starts thinking again.

Let's use the given figure as areference to understand the problem exactly.


Arguments passed to our program: 

    ./Philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep 

# Project Goals 

Learning the basics of threading a proces and we will see how to create threads and discovering mutexes 

# What's Threads & Why we need them ? 

Threads are a mechanism that permits an application to perform multiple tasks concurrently (At the same time),

All of these threads are independently executing the same program, and they all share the same global memory, including the initialized data, uninitialized data, and heap segments

A thread has three states:

   - Running
   - Ready
   - Blocked

And we need them to make application faster by doing multiple things at the same time.


# Threads VS Processes

One of the common questions from programming interviews is, what is the difference between a Thread and a Process?

| Threads       |  Processes |
| ------------- | ------------- |
| Sharing data between threads is easy | sharing data between processes requires more work  |
| A bug in one thread can damage all of the threads in the process, since they share the same address space | processes are more isolated from one another   |
| Thread creation is faster than process less time for creation and termination | Process requires more time for creation and termination | 
| When programming with threads, we need to ensure that the functions we call are thread-safe or are called in a thread-safe manner  | Multiprocess applications don’t need to be concerned with this  |

# Pthreads Data Types 

The Pthreads Application Programming Interface defines a number of data types ; 

pthread_t => It's a the data type used to uniquely identify a thread

pthread_mutex_t => Mutex 

pthread_mutexattr_t => Mutex attributes object 

pthread_cond_t => Condition variable 

pthread_condattr_t => Condition variable attributes object 

pthread_key_t => Key for thread-specific data 

pthread_once_t => One-time initialization control context 

pthread_attr_t => Thread attributes object 

# Thread Creation 

When a program is started it has a single thread called (the initial or main thread) 

And in order to create additional new threads we're going to use; 

[Man [Pthread_create]](https://man7.org/linux/man-pages/man3/pthread_create.3.html)

    int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start)(void *), void *arg);

let's take an example :

    #include <stdio.h>
    #include <string.h>
    #include <pthread.h>
    
    void    *thread_function(void   *ptr)
    {
        char *str = (void *)ptr;
        printf("%s\n",str);
        return (void *)strlen(str);
    }
    
    int main(int ac, char *av[])
    {
        pthread_t   thread;
        void        *return_status;
    
        pthread_create(&thread, NULL, &thread_function, av[1]);
        // Error Handling
        pthread_join(thread, &return_status);
        printf("Thread returned %d\n", (int)return_status);
    }


# Thread Termination 

The pthread_join() function waits for the thread identified by thread to terminate. and obtain its return status 

[Man [Pthread_join]](https://man7.org/linux/man-pages/man3/pthread_join.3.html)

    int pthread_join(pthread_t thread, void **retval); 

By default, a thread is joinable meaning that when it terminates another thread can obtain its return status using pthread_join(). 

You can think of pthread_join as waitpid for process (مزيانة هادي) 
# Detaching a Thread 

Sometimes, we don’t care about the thread’s return status, we simply want the system to automatically clean up and remove the thread when it terminates. 

In this case, we can mark the thread as detached, 

By making a call to pthread_detach() specifying the thread’s identifier in thread. 

Once a thread has been detached, it is no longer possible to use pthread_join() to obtain its return status, and the thread can’t be made joinable again.

[Man [Pthread_detach]](https://pubs.opengroup.org/onlinepubs/009695399/functions/pthread_detach.html)

    int pthread_detach(pthread_t thread);
    
let's take an example :

    #include <stdio.h>
    #include <string.h>
    #include <pthread.h>
    
    void    *thread_body(void *arg)
    {
        arg = "Hello from Thread";
        printf("%s\n",arg);
        return (NULL);
    }
    
    int main(int ac, char *av[])
    {
        pthread_t   thread;
        int         rslt;
    
        rslt = pthread_create(&thread, NULL, thread_body, NULL);
        rslt = pthread_detach(thread);
    }

So once a thread has been detached it's no longer possible to use pthread_join to obtain its return status, pthread_detach() simply controls what happens after a thread terminates, not how or when it terminates.

 
 Gettimeofday() should only be used to get the current time 



# Mutex

A mutex is a variable of the type pthread_mutex_t
Before it can be used, a mutex must always be initialized. For a statically allocated mutex;


# Conclusion

The design of the problem was to illustrate the challenges of avoiding deadlock, a deadlockstate of a system is a state in which no progress of system can be made . Consider a proposal where each philosopher is instructed to behave as follows:

- The philosopher is instructed to hold the right fork think till the left fork is avaliable when it's grabe it

- Eat since the two forks are avaliable

- When the time to eat is reached then release the two forks

- Go to sleep within to time mentioned in the arguments

- When he wake up he start thinking and wait until the 2 forks avalibale and repeat from the beginning

While thes process if a philosopher didn’t start eat since the beginning of their last meal or the beginning of the simulation, they die,
