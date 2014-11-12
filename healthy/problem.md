# A healthy supply of ministers
![](../images/healthy.png)

Erna Solberg needs your help running the government, specifically with running
national health care. Being a health minister is a nightmare. You have a
seemingly infinite queue of people waiting for treatment. If someone dies
before they get treatment there will be a major outcry in the media, forcing
you to resign.

For Erna this is a major headache. Since the treatment capacity is limited,
sometimes it is inevitable that some patients die, even if the health minister
manages the patient queue perfectly. Erna must therefore have a few spare
minister candidates ready to take over at any time.

Using advanced statistical inference, Erna's advisors have been able to work
out an estimate of how people will become sick during her term. Your job is to
make a program that given this data, finds the number of minister candidates
Erna needs.

The estimate from Erna's advisors consists of two parts:
First a list of all the patients who are currently waiting in line for
treatment. Each of these patients have an estimated number of days left to live
if they don't get treatment. This means that if a patient has 3 days to live
without treatment, he must be treated in day 0, 1 or 2 of Erna's turn,
otherwise he will die.

Secondly the estimate contains a list of patients expected to enter the queue
in the future. For these patients the data states the day they are expected to
become sick (i.e. the day they enter the queue), and how long they are expected
to live if they don't get treatment from that day on. Treating a patient before
he becomes sick is obviously not possible. This means that if a patient becomes
sick on day 3 with 2 days to live, he must be treated on day 3 or 4 in order to
live.

For the sake of predictability (and not overestimating the capacity of the
norwegian health service), we will assume that only one patient can be treated
per day. If there are multiple patients waiting, the patient who has the
shortest amount of time left to live will be treated first. It takes a day for
a minister to resign and for a new one to take over, so if two or more patients
die on the same day, still only one new minister is needed. Erna's term ends
when all patients are either treated or dead.

## Input
The first line of input contains two integers _n_ and _d_, the number of
waiting patients on day _0_, and the number patients who will get sick in the
future.

Then follows a line with _n_ integers _e<sub>i</sub>_, describing the patients
alread in the waiting queue. _e<sub>i</sub>_ denotes the expected number of
days patient _i_ will live without treatment.  The patients come in no
particular order.

Then follows _d_ lines with two integers _s<sub>j</sub>_ and _e<sub>j</sub>_,
describing the patients who will enter the queue in the future. Patient _j_
becomes sick (enters the hospital queue) on day _s<sub>j</sub>_, and is
expected to live _e<sub>j</sub>_ days without treatment.

## Output
Output the number of backup-health ministers Erna will need in order to make it
through the term.

## Constraints
0 &le; _n_ &le; 10<sup>4</sup>  
0 &le; _d_ &le; 10<sup>4</sup>  
1 &le; _s<sub>i</sub>_, _e<sub>i</sub>_ &le; 10<sup>9</sup>

## Sample input
```
5 5
0 1 3 3 4
3 1
5 1
6 1
7 1
7 1
```

## Sample output
```
3
```
