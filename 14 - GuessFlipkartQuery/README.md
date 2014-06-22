Author: Muhammad Hussein Nasrollahpour

Date: 2014

Problem Statement:Flipkart is a popular Indian e-commerce portal. One of the most common actions performed by users of the portal, is to use the search box and query for a brand, product or product-line. The search box then returns the best matching products which it can find - along with their prices, details, descriptions, etc.

We tried out twenty different search queries (specified below), and made a list of some of the product names which were returned in response to them. You are provided with a list of N names of products from this list. Your task is to guess, which search query each of them was returned in response to.

The twenty search queries we made were:

axe deo
best-seller books
calvin klein
camcorder
camera
chemistry
chromebook
c programming
data structures algorithms
dell laptops
dslr canon
mathematics
nike-deodrant
physics
sony cybershot
spoken english
timex watch
titan watch
tommy watch
written english
Here’s a small example of the task at hand:

In response to which of these queries, was the product ‘Dell Vostro 2520 Laptop (2nd Gen PDC/ 2GB/ 320GB/ Linux…’ (most likely) returned?
Answer:dell laptops

In response to which of these queries, was the product ‘Calvin Klein One Eau de Toilette - 200 ml’ (most likely) returned?
Answer:calvin klein

Input Format

The first line contains an integer N.
This is followed by N lines each containing the name of a product.

Input Constraints

1 <= N <= 200
The product names will not exceed 200 characters in length. Sometimes, when the product name is long and descriptive, after the first 55 characters, there are likely to be a series of dots, such as the examples below. Please handle them appropriately (strip them off, or ignore them).

Laptops: AMD Mobile Platform, AMD Vision, Barebook, Cen...
Dell Vostro 2520 Laptop (2nd Gen PDC/ 2GB/ 320GB/ Linux...
Dell Inspiron 15R 5521 Laptop (3rd Gen Ci7/ 8GB/ 1TB/ W...
Output Format

The output should contain exactly N lines.
The ith line should contain the query (your best guess) which returned the ith product name in the input file. The query should strictly be from one of the twenty queries specified above, as is. Please do not add any leading or trailing spaces or any extra punctuation. Also ensure that the case remains the same.

Sample:

    Input

    60
    Data Structures and Algorithms with Object- Oriented Design Patterns in C++ 1 Edition (Paperback)
    God Moments: Stories That Inspire, Moments to Remember (Paperback)
    The Ultimate C: Concepts, Programs and Interview Questions (Paperback)
    Canon EOS 1100D SLR (Black, with Kit (EF S18-55 III))
    A Textbook of Organic Chemistry for JEE Main & Advanced and Other Engineering Entrance Examinations (Paperback)
    Test your C ++ Skills 1 Edition (Paperback)
    IIM Ahmedabad Business Books: Day to Day Economics (Paperback)
    Calvin Klein One Eau de Toilette  -  200 ml
    ..........

    Output

    data structures algorithms
    written english
    c programming
    dslr canon
    chemistry
    c programming
    best-seller books
    calvin klein
    ............
