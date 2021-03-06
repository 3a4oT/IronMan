###  IronMan Task [![Build Status](https://travis-ci.org/3a4oT/IronMan.svg?branch=master)](https://travis-ci.org/3a4oT/IronMan)

IronMan is ready for battle! He starts his battle at location *0* moves in *1-unit* increments toward his final showdown at location *n−1*. Each location i has a power value, *pi*. **If pi < 0**, then there is an enemy at location **i** that he must lose **pi** power to beat; **if pi ≥ 0**, then he will restore pi power at location i. IronMan dies if his armor charge becomes < 1 at any point either during or after a fight, so he needs a proper initial charge to survive all possible fights in his battle traveling from location 0 to location n−1. Help him find the minimum charge needed to survive all fights in the battle!

Write a function. It has *1 parameter: an array of n integers, p, where each index i (0 ≤ i < n) describes the power charge lost or gained at battle location i*. **If the value at some pi < 0**, it represents the amount of charge IronMan must deplete to defeat the enemy; otherwise, it represents the amount of charge that he can restore at that location. **Your function must return an integer denoting the minimum starting charge IronMan needs to survive all fights**.

***Input Format***

The first line contains an integer, n, denoting number of locations IronMan will pass through. Each line i of the n subsequent lines (where 0 ≤ i < n) contains an integer describing the amount of charge he will gain or lose at battle location i.

*Constraints*

> **1 ≤ n ≤ 105 −100 ≤ pi ≤ 100**

Output Format
Your function must return an integer denoting the minimum amount of charge IronMan will need to survive all fights in the battle.

*Sample Input:*

The following argument is passed to your function: **p = {-5, 4, -2, 3, 1, -1, -6, -1, 0, 5}**

*Sample Output:*

> **8**

**Explanation**

If IronMan's initial *charge < 8*, then he will die somewhere in the middle of his battle. Thus, we return *8* **as the minimum charge needed** to survive the battle.
