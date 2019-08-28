# poj1068
## Description
Let S = s1 s2...s2n be a well-formed string of parentheses. S can be encoded in two different ways: 
q	By an integer sequence P = p1 p2...pn where pi is the number of left parentheses before the ith right parenthesis in S (P-sequence). 
q	By an integer sequence W = w1 w2...wn where for each right parenthesis, say a in S, we associate an integer which is the number of right parentheses counting from the matched left parenthesis of a up to a. (W-sequence). 

Following is an example of the above encodings: 

	S		(((()()())))

	P-sequence	    4 5 6666

	W-sequence	    1 1 1456


Write a program to convert P-sequence of a well-formed string to the W-sequence of the same string. 

