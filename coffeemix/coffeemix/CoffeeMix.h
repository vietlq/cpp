//
//  CoffeeMix.h
//  coffeemix
//
//  Created by Le Quoc Viet on 19/5/13.
//  Copyright (c) 2013 Le Quoc Viet. All rights reserved.
//

#ifndef coffeemix_CoffeeMix_h
#define coffeemix_CoffeeMix_h

namespace coffeemix
{
    template<bool B, class T = void>
    struct enable_if {};
    
    template<class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };
    
    static const size_t ZIPCODE_LEN     = 6;
    static const size_t STREET_LEN      = 32;
    static const size_t ROAD_LEN        = 32;
    static const size_t DISTRICT_LEN    = 32;
    
    enum AddressBF
    {
        Unit            = 1,
        Level           = 2,
        ZipCode         = 4,
        Block           = 8,
        Street          = 16,
        Road            = 32,
        District        = 64
        // Reserved     = 128
    };
    
    enum ContactBF
    {
        Mobile          = 1,
        HomePhone       = 2,
        HomeEmail       = 4,
        // Reserved     = 8
        OfficePhone     = 16,
        OfficeEmail     = 32
        // Reserved     = 64
        // Reserved     = 128
    };
}

#endif
