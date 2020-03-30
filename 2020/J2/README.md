# CCC '20 J2

We start by getting the input of ```P, N, R``` from stdin.

This means that we have ```N``` infected people. We maintain 3 variables: Count is the number of days...

```python
infected = N
people = N
count = 0
```

Since a person can only infect someone on the very next day, we have to maintain the number of people that are going to infect for that day. This will be our ```infected``` variable. After finding the number of people infected for a certain we ```+=``` to ```people``` and return output whenever ```people >= P```.

