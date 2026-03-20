# Translated Text - 2ndCuatrimestrOrdenamiento.pdf

2022 R1001 - M. GONAZALEZ 1- Introduction.
- Simple ordering methods.
- Introduction to more complex methods.
- Comparisons.
 ORDERING
2022 R1001 - M. GONAZALEZ 2INTRODUCTION
Sort: rearrange a set of items 
 considering certain conditions or relationship of 
order between them.
We can sort the elements or the pointers  
that point them (for example array of 
pointers)
The best algorithms require n Log
2n 
operations to order n elements.
Two of the best algorithms are: Quicksort and 
Heapsort.
2022 R1001 - M. GONAZALEZ 3Take into account (criteria)
EFFICACY
Number of steps
Number of Comparisons (hops)
Number of element moves (and size)
SIMPLICITY
To edit it
To modify it
Also take into account other aspects such as 
size, number of processors, etc.
IT WILL ALWAYS DEPEND ON THE USE!!! IT WILL ALWAYS DEPEND ON THE USE!!!
2022 R1001 - M. GONAZALEZ 4Comments
For small N, use small algorithms 
simple implementation does not bring harm 
important.
Sort algorithms 
will complement others as being 
search.
As in other algorithms, there is a whole 
MATHEMATICAL THEORY that analyzes the 
advantages and disadvantages of each method
2022 R1001 - M. GONAZALEZ 5THEORETICAL CONCEPTS
Asymptotic upper bound (or “O Notation 
Big")
It is a function that serves as the upper bound of another function 
when the argument tends to infinity.
Landau notation O(g(x)) is usually used 
Represented as: f(x) O(g(x)) (commonly appears ∈
like f(x)=O(g(x)) but this is a mistake because it is 
a set).
2022 R1001 - M. GONAZALEZ 6Classification
According to
Place of arrangement (internal and external)
Computational complexity (comparisons)
Computational complexity (exchanges)
Memory usage (temporary support)
Recursion (recursive or non-recursive)
Stability (maintains previous relationship)
Adaptability (response according to a previous order)
Method (different variants)
2022 R1001 - M. GONAZALEZ 7Types
Internal regulation
It is carried out completely in memory 
main
External ordering
Not all the information fits in memory 
main and it is necessary to occupy memory 
secondary.
2022 R1001 - M. GONAZALEZ 8Complexity (comparisons)
The nomenclature “O GRANDE” is used
O(1): constant complexity (always has the 
same time).
O(n2
): quadratic complexity (time depends 
of the square of the number of elements).
It is also usually analyzed with three values: best 
case, worst case and average.
The number of comparisons is usually a value 
critical since they are accompanied by the 
possibility of jumping which greatly increases the 
process time.
2022 R1001 - M. GONAZALEZ 9Complexity (exchanges)
The exchange is usually accompanied with 
access to different storage media 
which adds “dead” time to the 
procedure.
2022 R1001 - M. GONAZALEZ 10Memory usage
Some algorithms only use memory to 
store the data to be sorted. This is 
O(1)
Others need temporary storage 
using additional memory for it. 
2022 R1001 - M. GONAZALEZ 11OTHER
Recursion
Whether or not they use recursive algorithms
Stability
If they maintain the pre-established order of other 
columns.
Adaptability
Whether or not its performance changes depending on how 
ordered they are initially.
Method
Every method can have variants
2022 R1001 - M. GONAZALEZ 12Simple methods of 
ordering
Initially we will see three basic methods that 
Due to their simplicity and practicality, they are 
perfectly used to organize small 
sets.
Bubble sort
Selection sort 
INSERTION sort
2022 R1001 - M. GONAZALEZ 13BUBBLE
Compare each element with the next one and the 
switches position or not as necessary 
or not to obtain the desired order.
In each pass there is at least one new 
element in its final position.
Complexity: O(n2
)
Best/Worst/Average: O(n)/O(n2
)/O(n2
)
Memory:O(1)
2022 R1001 - M. GONAZALEZ 14ALGORITHM
void bubbleorder(int data[],int elements)
{
  int top = elements, changes, i, aux;
  do {
    changes = FALSE; //#define FALSE 0
    top--;
    for(i=0; i<top; i++)
    {
      if(data[i]>data[i+1])
      {
  aux = data[i];
  data[i] = data[i+1];
  data[i+1] = aux;
  changes = TRUE; //#define TRUE 1
      }
    }
  }while(changes);
return;
}
2022 R1001 - M. GONAZALEZ 15SELECTION
Perform a searchthroughout the list of 
minimum value (or maximum) and exchanges it with the 
first element, repeat but starting from 
the next element.
In each pass there is at least one 
new value in its final position.
Complexity: O(n2
)
Best/Worst/Average: O(n2
)/O(n2
)/O(n2
)
Memory:O(1)
2022 R1001 - M. GONAZALEZ 16ALGORITHM
void selection_order(int data[],int elements)
{
  int i,j,minor,aux;
  for(i=0;i<items;i++)
  {
    minor=i;
    for(j=i+1;j<items;j++)
    {
      if(data[j]<data[minor])
    minor=j;
    }
    aux=data[i];
    data[i]=data[minor];
    data[minor]=aux;
  }
  return;
}
2022 R1001 - M. GONAZALEZ 17INSERTION
The first element is taken as a set 
ordered of an element and they are “inserted” 
 one by one the other elements in their position 
ordered relative to the current set.
The set is always ordered and is 
insert new elements.
Complexity: O(n2
)
Best/Worst/Average: O(n)/O(n2
)/O(n2
)
Memory:O(1)
2022 R1001 - M. GONAZALEZ 18ALGORITHM
void insertion_order(int data[],int elements)
{
   int i,j,minor,aux; 
   for(i=1;i<items;i++)
  {
    aux = data[i];
    for(j=i-1;(data[j]>aux)&&(j>=0);j--)
    {
      data[j+1]=data[j]; // raise element one level      
    }
    data[j+1]=aux;    // insert element
  }
  return;
}
2022 R1001 - M. GONAZALEZ 19Introduction to more methods 
advanced
We will discuss a couple of methods of 
more advanced ordering.
There is always the possibility that they will create 
new methods.
We will see:
Shell sort 
Quick sort
2022 R1001 - M. GONAZALEZ 20SHELL SORT
It is a generalization of the ordering by 
insertion, with two observations:
1) Insertion is efficient if the input is "almost 
ordered."
2) Insertion is inefficient, in general, because 
moves the values only one position at a time.
Shell sort algorithm improves insertion sort 
comparing elements separated by a space of several 
positions, allowing for "bigger steps" toward your position 
expected. These jumps become smaller and smaller in size. 
The last step is just a basic insertion sort, 
but it is already guaranteed that the vector data is almost ordered.
2022 R1001 - M. GONAZALEZ 21Features
Complexity:
 O(n2
) or O(n log2
 n) (modification by V. Pratt)
Best/Worst/Average1
:
 O(n)/O(n log2
 n)/O(n log2
 n)
Memory:
O(1)
1) It can also be n3/2
2022 R1001 - M. GONAZALEZ 22QUICK SORT
Based on the divide and conquer technique.
Steps:
Choose an element (pivot)
Relocate the other elements from the pivot according to  
order.
Repeat this process recursively in the two groups 
that were left.
2022 R1001 - M. GONAZALEZ 23Features
Complexity:
O(n log n) (worst case O(n2
)) 
Best/Worst/Average:
 O(n log n)/O(n2
)/O(n log n)
The best case is when the pivot falls in the middle and the worst when 
falls at one end.
Memory:
O(1)