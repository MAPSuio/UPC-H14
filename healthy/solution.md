# A healthy supply of ministers
This problem can be solved by simulation. The trick is to use an efficient data
structure in order to find the next patient to be treated. A priority queue is
well suited for this.

The problem can then be solved as follows:
Make a priority queue (heap) sorted on patient estimated-day-of-death.

- Add all of the initial patients to the queue
- Iterate each day starting at day 0
    - Add all new patients to the queue
    - Treat the next patient in the queue, note if he's already dead
    - Remove all dead patients from the queue

One optimization is to jump the day counter forwards to the next patient if the
queue is empty.
