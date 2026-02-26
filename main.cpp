#include <iostream>
#include <cstdlib>  // for malloc
using namespace std;

// TODO: Declare 2 initialized global variables (DATA segment)
int initializedGlobal1 = 100;
int initializedGlobal2 = 200;

// TODO: Declare 2 uninitialized global variables (BSS segment)
int uninitializedGlobal1;
int uninitializedGlobal2;

// Stack check function: receives address from caller (parent frame)
// and compares with a local variable (child frame)
void checkStack(int* parentAddr) {
    int childVar = 0;
    cout << "--- STACK SEGMENT (Cross-function comparison) ---" << endl;
    // TODO: Print parentAddr value (points to main's local var - parent frame)
    cout << "Value of parentAddr: " << parentAddr << endl;
    // TODO: Print &parentAddr (parameter's own address - child frame)
    cout << "Address of parentAddr parameter: " << &parentAddr << endl;
    // TODO: Print &childVar (local var address - child frame)
    cout << "Address of childVar local variable: " << &childVar << endl;
    // TODO: Print "Stack grows: DOWN" or "UP" based on comparison
    //       Compare: parentAddr > &childVar ? "DOWN" : "UP"
    //       (parent frame address vs child frame address)
    cout << "Stack grows: " << (parentAddr > &childVar ? "DOWN" : "UP") << endl;
    cout << endl;
}

int main() {

    // TODO: Declare a local variable (STACK - will be passed to checkStack)
    int localVar = 42;
    cout << "--- STACK SEGMENT (Cross-function comparison) ---" << endl;
    cout << "main local address (&localVar): " << &localVar << endl;
    checkStack(&localVar);
    cout << endl;

    // TODO: Allocate 2 heap variables using malloc (use larger sizes, e.g. 1024)
    //       Note: new may not allocate sequentially; malloc with larger sizes
    //       is more reliable for demonstrating heap growth direction
    void* heap1 = malloc(1024);
    void* heap2 = malloc(1024);

    cout << "=== MEMORY SEGMENT BOUNDARIES ===" << endl;
    cout << endl;

    // TODO: Print TEXT segment - 2 function addresses
    //       e.g., (void*)&main and (void*)&checkStack
    cout << "--- TEXT SEGMENT (Code) ---" << endl;
    // ...
    cout << "Address of main():       " << (void*)&main << endl;
    cout << "Address of checkStack(): " << (void*)&checkStack << endl;
    cout << endl;

    // TODO: Print DATA segment - 2 initialized global addresses + values
    cout << "--- DATA SEGMENT (Initialized Globals) ---" << endl;
    // ...
    cout << "initializedGlobal1: " << &initializedGlobal1
         << " value: " << initializedGlobal1 << endl;
    cout << "initializedGlobal2: " << &initializedGlobal2
         << " value: " << initializedGlobal2 << endl;
    cout << endl;

    // TODO: Print BSS segment - 2 uninitialized global addresses + values
    cout << "--- BSS SEGMENT (Uninitialized Globals) ---" << endl;
    // ...
    cout << "uninitializedGlobal1: " << &uninitializedGlobal1
         << " value: " << uninitializedGlobal1 << endl;
    cout << "uninitializedGlobal2: " << &uninitializedGlobal2
         << " value: " << uninitializedGlobal2 << endl;
    cout << endl;

    // STACK: call checkStack with address of your local variable
    // TODO: checkStack(&yourLocalVar);
    checkStack(&localVar);

    // TODO: Print HEAP segment - 2 heap addresses + comparison
    //       Print "Heap grows: UP" or "DOWN"
    cout << "--- HEAP SEGMENT (Dynamic Allocation) ---" << endl;
    // ...
    cout << "heap1 address: " << heap1 << endl;
    cout << "heap2 address: " << heap2 << endl;

    cout << "Heap grows: "
         << (heap2 > heap1 ? "UP" : "DOWN") << endl;
    cout << endl;

    // TODO: Print relative position summary
    cout << "=== RELATIVE POSITION SUMMARY ===" << endl;
    // ...
    cout << "Compare TEXT, DATA, BSS, HEAP, STACK addresses above." << endl;
    cout << "Typically: TEXT < DATA < BSS < HEAP < STACK" << endl;
    cout << endl;

    // TODO: Free all heap allocations
    free(heap1);
    free(heap2);

    return 0;
}

/*
 * EXPERIMENTAL RESULTS:
 * TODO: After running your program, explain what you observed:
 * - Which segment has the lowest addresses?
 * - Which has the highest?
 * - Does stack grow down? How did you verify this?
 * - Does heap grow up? How did you verify this?
 * - What is the gap between HEAP and STACK?
 */
