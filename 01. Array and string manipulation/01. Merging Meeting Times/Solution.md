### Gotchas

Look at this case:

```cpp
  [Meeting(1, 2), Meeting(2, 3)]
```



These meetings should probably be merged, although they don't exactly "overlap"—they just "touch." Does your function do this?

Look at this case:

```c
  [{1, 5}, {2, 3}]
```

We're still translating this code to C++. Here it is in C:



Notice that although the second meeting starts later, it ends before the first meeting ends. Does your function correctly handle the case where a later meeting is "subsumed by" an earlier meeting?

Look at this case:

```cpp
  [Meeting(1, 10), Meeting(2, 6), Meeting(3, 5), Meeting(7, 9)]
```



Here *all* of our meetings should be merged together into just Meeting(1, 10). We need keep in mind that after we've merged the first two we're not done with the result—the result of that merge *may itself need to be merged into other meetings as well*.

Make sure that your function won't "leave out" the *last* meeting.

We can do this in O(n\lg{n})*O*(*n*lg*n*) time.

### Breakdown

What if we only had two ranges? Let's take:

```cpp
  [Meeting(1, 3), Meeting(2, 4)]
```



These meetings clearly overlap, so we should merge them to give:

```cpp
  [Meeting(1, 4)]
```



But how did we know that these meetings overlap?

We could tell the meetings overlapped because the *end time* of the first one was after the *start time* of the second one! But our ideas of "first" and "second" are important here—this only works after we ensure that we treat the meeting that *starts earlier* as the "first" one.

How would we formalize this as an algorithm? **Be sure to consider these edge cases:**

1. The end time of the first meeting and the start time of the second meeting are equal. For example: [Meeting(1, 2), Meeting(2, 3)]
2. The second meeting ends before the first meeting ends. For example: [Meeting(1, 5), Meeting(2, 3)]

Here's a formal algorithm:

1. We treat the meeting with earlier start time as "first," and the other as "second."
2. If the end time of the first meeting is *equal to or greater than* the start time of the second meeting, we merge the two meetings into one time range. The resulting time range's start time is the first meeting's start, and its end time is *the later of* the two meetings' end times.
3. Else, we leave them separate.

So, we could compare *every* meeting to *every other* meeting in this way, merging them or leaving them separate.

Comparing *all pairs* of meetings would take O(n^2)*O*(*n*2) time. We can do better!

If we're going to beat O(n^2)*O*(*n*2) time, maybe we're going to get O(n)*O*(*n*) time? Is there a way to do this in one pass?

It'd be great if, for each meeting, we could just try to merge it with the *next* meeting. But that's definitely not sufficient, because the ordering of our meetings is random. There might be a non-next meeting that the current meeting could be merged with.

What if we sorted our vector of meetings by start time?

Then any meetings that could be merged would always be adjacent!

So we could sort our meetings, then walk through the sorted vector and see if each meeting can be merged with the one after it.

Sorting takes O(n\lg{n})*O*(*n*lg*n*) time in the worst case. If we can then do the merging in one pass, that's another O(n)*O*(*n*) time, for O(n\lg{n})*O*(*n*lg*n*) overall. That's not as good as O(n)*O*(*n*), but it's better than O(n^2)*O*(*n*2).

### Solution

First, we sort our input vector of meetings by start time so any meetings that might need to be merged are now next to each other.

Then we walk through our sorted meetings from left to right. At each step, either:

1. We *can* merge the current meeting with the previous one, so we do.
2. We *can't* merge the current meeting with the previous one, so we know the previous meeting can't be merged with any future meetings and we throw the current meeting into mergedMeetings.

```cpp
  bool compareMeetingsByStartTime(
    const Meeting& firstMeeting,
    const Meeting& secondMeeting)
{
    return firstMeeting.getStartTime() < secondMeeting.getStartTime();
}

vector<Meeting> mergeRanges(const vector<Meeting>& meetings)
{
    // sort by start time
    vector<Meeting> sortedMeetings(meetings);
    sort(sortedMeetings.begin(), sortedMeetings.end(), compareMeetingsByStartTime);

    // initialize mergedMeetings with the earliest meeting
    vector<Meeting> mergedMeetings;
    mergedMeetings.push_back(sortedMeetings.front());

    for (const Meeting& currentMeeting : sortedMeetings) {
        Meeting& lastMergedMeeting = mergedMeetings.back();

        if (currentMeeting.getStartTime()
                <= lastMergedMeeting.getEndTime()) {
            // if the current meeting overlaps with the last merged meeting, use the
            // later end time of the two
            lastMergedMeeting.setEndTime(max(lastMergedMeeting.getEndTime(),
                currentMeeting.getEndTime()));
        }
        else {
            // add the current meeting since it doesn't overlap
            mergedMeetings.push_back(currentMeeting);
        }
    }

    return mergedMeetings;
}
```



### Complexity

O(n\lg{n})*O*(*n*lg*n*) time and O(n)*O*(*n*) space.

Even though we only walk through our vector of meetings once to merge them, we *sort* all the meetings first, giving us a runtime of O(n\lg{n})*O*(*n*lg*n*). It's worth noting that *if* our input were sorted, we could skip the sort and do this in O(n)*O*(*n*) time!

We create a new vector of merged meeting times. In the worst case, none of the meetings overlap, giving us a vector identical to the input vector. Thus we have a worst-case space cost of O(n)*O*(*n*).

### Bonus

1. What if we *did* have an upper bound on the input values? Could we improve our runtime? Would it cost us memory?
2. Could we do this "in place" on the input vector and save some space? What are the pros and cons of doing this in place?

### What We Learned

This one arguably uses a greedy ↴ approach as well, except this time we had to *sort* the vector first.

How did we figure that out?

We started off trying to solve the problem in one pass, and we noticed that it wouldn't work. We then noticed the *reason* it wouldn't work: to see if a given meeting can be merged, we have to look at *all* the other meetings! That's because the order of the meetings is random.

*That's* what got us thinking: what if the vector *were* sorted? We saw that *then* a greedy approach would work. We had to spend O(n\lg{n})*O*(*n*lg*n*) time on sorting the vector, but it was better than our initial brute force approach, which cost us O(n^2)*O*(*n*2) time!