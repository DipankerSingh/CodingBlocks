one call another
that call another
this is known as stack call !
the size of array has to be constant
sometimes it works and sometimes not !
array is variable size is not always correct
when aray is passed value is changed in both
but that is not the case when any variable is
arrays cannot be returned !
binary search fast compared to linear search
array should be sorted before doing binary search
largest goes to the end in first iteration
cin>>input;
\0 is added at the end of the string to notify the end
\0 ascii value=0
string breaks after space
so we can use cin.get
but to print this we need to add manualy the null characer at the end
if we didn't add null character , then compiler won't find the end and print random characters
    multi dimensional arrays
    takiing input from user
    int input[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
        {
            cout<<"enter element in "<<i<<"th row and "<<j<<"th column"<<endl;
            cin>>input[i][j];
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
        {

            cout<<input[i][j]<<" ";
        }
        cout<<endl;
    }

while passing 2-d array you have to tell the dimension of second array

    pointers
    while passing pointers , new pointer is created
    and adress is copied
    initialising double *p=0;
    arrays can be passed like this
    void print( int *pointer,int n)
    calling print(input,n);
    print2(input-1,n-1)
    it is possible to pass part of an array to function

    time complexity
    order complexity analysis
    time as a function of input size
    selection sort vs merge sort
    big O notation
    binary search is big O of log n
    bubble insertion and selecton sort are big O of n*n
    time complexity of merge sort is nlogn

    default copy constructor copies shallow not deeply
    therefore change in one will also be seen in the other

    preoreder/PostOrder Transversal










