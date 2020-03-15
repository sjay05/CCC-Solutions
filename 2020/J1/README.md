# Problem J1

We start by getting the input of ```S, M, L``` with stdin with the following code.

```python
S = input()
M = input()
L = input()
```
Next we calculate the ```happiness score``` value using S, M, L and the formula given.

```python
happi = (1*S) + (2*M) + (3*L)
```

We check if ```happi>10``` and return the respective output.  