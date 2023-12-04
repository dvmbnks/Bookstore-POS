#include "UnitBookTest.h"
#include "UnitDigitalTest.h"
#include "UnitPhysicalBookTest.h"
#include "UnitUsedBookTest.h"
#include "UnitInventoryTest.h"
#include "UnitCustomerTest.h"
#include <iostream>

using namespace std;

int main() {
    UnitTestBook bookTest;
    UnitTestDigitalBook digitalBookTest;
    UnitTestPhysicalBook physicalBookTest;
    UnitTestUsedBook usedBookTest;
    UnitTestInventory inventoryTest;
    UnitTestCustomer customerTest;

    std::cout << "Running Unit Tests..." << std::endl;

    bookTest.RunTests();
    cout << "\n" << endl;
    digitalBookTest.RunTests();
    cout << "\n" << endl;
    physicalBookTest.RunTests();
    cout << "\n" << endl;

    usedBookTest.RunTests();
    cout << "\n" << endl;

    inventoryTest.RunTests();
    cout << "\n" << endl;

    customerTest.RunTests();
    cout << "\n" << endl;

    cout << "All Unit Tests Completed." << endl;

    return 0;
}
