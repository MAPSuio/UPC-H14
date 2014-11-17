# The pinmaker
Simply use the difference equation to get the answer. Naïve recursion is too
slow, but a linear time solution should be accepted.

Start with finding k<sub>2</sub> from k<sub>0</sub> and k<sub>1</sub>. Then
find k<sub>3</sub> from k<sub>1</sub> and k<sub>2</sub> and so on...

There are some details that must be tended to. First of all, _k<sub>100</sub>_
can be very large, so we may run into overflows if we're just using `int`.
Luckily, we only need the last 8 digits for answer. This means that we can take
modulo 10<sup>8</sup> in all steps, without losing any information. This way we
make sure that the number never gets too large, and we avoid overflows.
