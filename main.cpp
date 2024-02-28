#include <iostream>
#include "alertReaderFactory.h"
#include <vector>

int main()
{

    // Not currently stored in vectors
    alertReaderFactory factory;

    std::shared_ptr <IAlertReader> myFile = factory.createAlertReader("json");
    myFile->extractNextDataElement();


    return 0;
}
