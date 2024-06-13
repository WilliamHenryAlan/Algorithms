/*
Three friends gathered to play a few games of chess together.

In every game, two of them play against each other. 
The winner gets 2 points while the loser gets 0, and in case of a draw（以防平局）, both players get 1 point each. 
Note that the same pair of players could have played any non-negative number of times (possibly zero). 
It is also possible that no games were played at all.

You've been told that their scores after all the games were played were 𝑝1
, 𝑝2
 and 𝑝3
. Additionally, it is guaranteed that 𝑝1≤𝑝2≤𝑝3
 holds.

Find the maximum number of draws that could have happened and print it. If there isn't any way to obtain 𝑝1
, 𝑝2
 and 𝑝3
 as a result of a non-negative number of games between the three players, print −1
 instead.

Input
Each test contains multiple test cases. The first line contains the number of test cases 𝑡
 (1≤𝑡≤500
). The description of the test cases follows.

The first line of each test case contains three integers 𝑝1
, 𝑝2
 and 𝑝3
 (0≤𝑝1≤𝑝2≤𝑝3≤30
) — the scores of the three players, sorted non-decreasingly.

Output
For each testcase, print one number — the maximum possible number of draws that could've happened, or −1
 if the scores aren't consistent with any valid set of games and results.
*/