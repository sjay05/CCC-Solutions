# Problem J3

The challenging bit of this problem is to parse the input by the comma. 

We maintain all our X'points in a array and all our Y'points in an array.

From the image:
![image](https://github.com/sjay05/CCC-Solutions/blob/master/images/Screen%20Shot%202020-03-15%20at%2010.32.02%20AM.png)

We notice that to find the top-right cordinate, we can find the largest ```X``` value and then ```+1``` to get the ```X``` value of the corner. As for the ```Y``` value, we find the largest ```Y``` value in our input, and ```+1```. This means our top right corner is ```[max(X)+1, max(Y)+1]```.

As for the bottom left corner, the coordinates are ```[min(X)-1, min(y)-1]```.



