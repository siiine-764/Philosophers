# Philosophers

Mr.Philo : 

![1200px-Vaticano_2011_88-d014202103c34387b0e825b0f74d1126](https://user-images.githubusercontent.com/80540449/233755351-90e96403-419c-41a0-8b6e-a295fe84b387.jpg)


<h1>Videos to get it: </h1>

Process vs Thread : 
https://www.youtube.com/watch?v=4rLW7zg21gI

<h1>Dining philosophers problem :</h1>
In computer science, --the dining philosophers problem-- is an example problem often used in concurrent (gleichzeitig) algorithm design to illustrate synchronization (the operation or activity of two or more things at the same time or rate.) issues and techniques for resolving them.

It was originally formulated in 1965 by Edsger Dijkstra as a student exam exercise, presented in terms (Bedingungen/chorot) of computers competing for access to tape drive peripherals. Soon after, Tony Hoare gave the problem its present form.

<h3>Problem statement</h3>

Five philosophers dine together at the same table. Each philosopher has their own place at the table. There is a fork between each plate. The dish served is a kind of spaghetti which has to be eaten with two forks. Each philosopher can only alternately think and eat. Moreover, a philosopher can only eat their spaghetti when they have both a left and right fork. Thus two forks will only be available when their two nearest neighbors are thinking, not eating. After an individual philosopher finishes eating, they will put down both forks. The problem is how to design a regimen (a concurrent algorithm) such that no philosopher will starve; i.e., each can forever continue to alternate between eating and thinking, assuming that no philosopher can know when others may want to eat or think (an issue of incomplete information).

<h3>Problems</h3>

The problem was designed to illustrate the challenges of avoiding deadlock, a system state in which no progress is possible. To see that a proper solution to this problem is not obvious (offensichtlich/bedihi), consider a proposal in which each philosopher is instructed to behave as follows:

think unless the left fork is available; when it is, pick it up;
think unless the right fork is available; when it is, pick it up;
when both forks are held, eat for a fixed amount of time;
put the left fork down;
put the right fork down;
repeat from the beginning.

However, they each will think for an undetermined amount of time and may end up holding a left fork thinking, staring at the right side of the plate, unable to eat because there is no right fork, until they starve.

Resource starvation, mutual exclusion and livelock are other types of sequence and access problem. 
<h1>My philos : </h1> 

Niccolo Machiavelli :

Socrates :

Aristotle Aristotle :

Sigmund Freud :

Ibn Khaldun :

![philo](https://user-images.githubusercontent.com/80540449/235598793-c693052b-2c36-461d-834e-2a8b8166560c.jpg)

<h1>Installation 🖥 </h1>

To test the project, go to one of the folders philo_one, philo_two or philo_three and make a make. Then, you can test the project using an executable.

usage :

    ./philo_one number_philosopher time_to_die time_to_eat time_to_sleep [number_of_time_each_philosophers_must_eat] 
arguments in square brackets are not required (number_of_time_each_philosophers_must_eat)

