//
//  main.cpp
//  coffeemix
//
//  Created by Le Quoc Viet on 19/5/13.
//  Copyright (c) 2013 Le Quoc Viet. All rights reserved.
//

#include <iostream>
#include "CoffeeMix.h"

using coffeemix::AddressType;
using coffeemix::ContactType;

int main(int argc, const char * argv[])
{
    std::cout << "CoffeeMix C++ Project!\n\n";
    
    AddressType myAddress;
    ContactType myContacts;
    
    // Test values for AddressType fields
    const char zip[] = "230045";
    const char district[] = "Financial District";
    // Assigning the fields for AddressType
    myAddress.Unit = 123;
    myAddress.Level = 9;
    myAddress.Block = 32;
    memcpy(myAddress.ZipCode, zip, strlen(zip));
    memcpy(myAddress.District, district, strlen(district));
    // And dumping to the default output stream
    std::cout << "-- sizeof(myAddress) = " << sizeof(myAddress) << std::endl;
    std::cout << myAddress << std::endl << std::endl;
    
    // Test values for ContactType fields
    const char mobile[] = "+6588776699";
    const char homePhone[] = "+6566778899";
    const char officeEmail[] = "viet@simpleit.us";
    // Assigning the fields for ContactType
    memcpy(myContacts.Mobile, mobile, strlen(mobile));
    memcpy(myContacts.HomePhone, homePhone, strlen(homePhone));
    memcpy(myContacts.OfficeEmail, officeEmail, strlen(officeEmail));
    // And dumping to the default output stream
    std::cout << "-- sizeof(myContacts) = " << sizeof(myContacts) << std::endl;
    std::cout << myContacts << std::endl;
    
    return 0;
}
