// Thanks Cherno
#include<iostream>
#include<vector>

// NOTE: if you know the size of your data structure before hand, better to use ARRAY instead of Vector
// Vector allocations are on HEAP. With Array, they go on stack.

// look at memory working here 
// how many allocations do we have
static int s_AllocationCount = 0;

// now we also want to focus on the numer of copies made
static int s_copyCount = 0;

// now can we think about moving as well?

static int s_moveCount = 0;
// this will overwrite the functionality that vector uses internally to allocate memory
void* operator new(size_t size)
{
    std::cout << "Allocated " << size  << "bytes\n";
    // everytime new gets called, this will get incremented
    s_AllocationCount++;

    return malloc(size); // allocate memory equal to size of vector
}

struct Data
{
    int Value = 0;

    Data() = default;
    Data(int value): Value(value) {}

    // Adding a copy constructor
    Data(const Data &other): Value(other.Value)
    {
        s_copyCount++;
        s_moveCount++;
        std::cout << "Copied Data\n";
    }

    // Adding a mpve constructor
    Data(const Data&& other): Value(other.Value)
    {
        s_moveCount++;
        std::cout << "Moved Data\n";
    }

};

// we do not nede to copy to simply print the vector
static void PrintVector(const std::vector<Data>& vector) // better to pass by reference here.
{
    size_t size = vector.size();
    std::cout << "Size is " << size << "\n";
    for(size_t i=0; i<size;i++)
    {
        std::cout << vector[i].Value << "\t";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<Data> vector;
    vector.reserve(5);
    // what if we reserve the size at the start or initialize with a fixed size initally albeit small
    for(int i =0; i< 5;i++)
    {
        // vector.push_back(Data(i)); // we creating a copy of the struct instance here & then copy into the vector
        vector.emplace_back(i); // better to use this
        // it creates this for you inside & even 0 moves
    }

    PrintVector(vector);

    std::cout << "Total Allocations: " << s_AllocationCount << "\n";
    std::cout << "Total Number of Copies made: " << s_copyCount << "\n";
    std::cout << "Total Number of Moves made: " << s_moveCount << "\n";

    std::cin.get();
}

// REASONING BEHIND ALLOCATIONS
// starts with 0 bytes when vector is instantiated.
// after first, 4 bytes.
// with 2nd element, 8 bytes.
// with 3rd element, 16 bytes.
// bsaically, memory doubles of the existing memory per allocation


// FINAL EXPECTED OUTPUT:
// Allocated 20bytes
// Size is 5
// 0       1       2       3       4
// Total Allocations: 1
// Total Number of Copies made: 0
// Total Number of Moves made: 0
