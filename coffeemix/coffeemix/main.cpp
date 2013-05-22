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

struct PersonalContacts: coffeemix::AddressType, coffeemix::ContactType
{
    
};

struct Empty1 {};
struct Empty2 {};
struct Empty3 {};
struct Empty4 {};
struct Empty5 {};
struct Empty6: Empty1, Empty2 {};
struct Empty7: Empty1, Empty2, Empty3, Empty4, Empty5 {};
struct Empty8: Empty3, Empty4, Empty5, Empty6 {};
struct Empty9: Empty5, Empty6 {};
struct Empty10: Empty1, Empty6 {};
struct Empty11: private Empty1, private Empty6 {};
struct Empty12: Empty1, Empty2, Empty6, Empty7 {};

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
    memcpy(myAddress.ZipCode, zip, strlen(zip) + 1);
    memcpy(myAddress.District, district, strlen(district) + 1);
    // And dumping to the default output stream
    std::cout << "-- sizeof(myAddress) = " << sizeof(myAddress) << std::endl;
    std::cout << myAddress << std::endl << std::endl;
    
    // Test values for ContactType fields
    const char mobile[] = "+6588776699";
    const char homePhone[] = "+6566778899";
    const char officeEmail[] = "viet@simpleit.us";
    // Assigning the fields for ContactType
    memcpy(myContacts.Mobile, mobile, strlen(mobile) + 1);
    memcpy(myContacts.HomePhone, homePhone, strlen(homePhone) + 1);
    memcpy(myContacts.OfficeEmail, officeEmail, strlen(officeEmail) + 1);
    // And dumping to the default output stream
    std::cout << "-- sizeof(myContacts) = " << sizeof(myContacts) << std::endl;
    std::cout << myContacts << std::endl;
    
    PersonalContacts personalContacts;
    std::cout << "-- sizeof(personalContacts) = " << sizeof(personalContacts) << std::endl;
    
    Empty1 oEmpty1;
    std::cout << "-- sizeof(oEmpty1) = " << sizeof(oEmpty1) << std::endl;
    Empty6 oEmpty6;
    std::cout << "-- sizeof(oEmpty6) = " << sizeof(oEmpty6) << std::endl;
    Empty7 oEmpty7;
    std::cout << "-- sizeof(oEmpty7) = " << sizeof(oEmpty7) << std::endl;
    Empty8 oEmpty8;
    std::cout << "-- sizeof(oEmpty8) = " << sizeof(oEmpty8) << std::endl;
    Empty9 oEmpty9;
    std::cout << "-- sizeof(oEmpty9) = " << sizeof(oEmpty9) << std::endl;
    Empty10 oEmpty10;
    std::cout << "-- sizeof(oEmpty10) = " << sizeof(oEmpty10) << std::endl;
    Empty11 oEmpty11;
    std::cout << "-- sizeof(oEmpty11) = " << sizeof(oEmpty11) << std::endl;
    Empty12 oEmpty12;
    std::cout << "-- sizeof(oEmpty12) = " << sizeof(oEmpty12) << std::endl;
    
    return 0;
}
