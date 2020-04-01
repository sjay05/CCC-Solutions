# CCC '20 J3

The challenging bit of this problem is to parse the input by the comma. 

We maintain all X and Y coordinates in respective arrays. 

There are a few properties to consider in this problem:

1) The northern boundary lies just above the highest coordinate.
2) The eastern boundary lies just right of the right-most coordinate.
3) The southern boundary lies just below the lowest cooridinate.
4) The western boundary lies just left of the left-most coordinate.

Using these properties we can consturct the coordinate pair of the top-right and bottom-left corner. 

When I state `max(X)` or `max(Y)` it refers to the maximum of the X or Y values.

Top-right corner (x,y) = `(max(X)+1, max(Y)+1)`

Bottom-right corner (x,y) = `(max(X)-1, max(Y)-1)`




