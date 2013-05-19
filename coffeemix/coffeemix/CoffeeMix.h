//
//  CoffeeMix.h
//  coffeemix
//
//  Created by Le Quoc Viet on 19/5/13.
//  Copyright (c) 2013 Le Quoc Viet. All rights reserved.
//

#ifndef coffeemix_CoffeeMix_h
#define coffeemix_CoffeeMix_h

/**
 Create & use types with custom fields at compile time in 7 easy steps
 */

#include <ostream>

namespace coffeemix
{
    ////////////////////////////////////////////////////////////////
    // STEP 1 - Declare char fields' lengths
    ////////////////////////////////////////////////////////////////
    
    // Address char fields' lengths
    static const size_t ZIP_CODE_LEN        = 6;
    static const size_t STREET_LEN          = 32;
    static const size_t ROAD_LEN            = 32;
    static const size_t DISTRICT_LEN        = 32;
    
    // Contact char fields' lengths
    static const size_t MOBILE_LEN          = 16;
    static const size_t HOME_PHONE_LEN      = 32;
    static const size_t HOME_EMAIL_LEN      = 32;
    static const size_t OFFICE_PHONE_LEN    = 32;
    static const size_t OFFICE_EMAIL_LEN    = 32;
    
    ////////////////////////////////////////////////////////////////
    // STEP 2 - Declare & define bit fields
    ////////////////////////////////////////////////////////////////
    
    // Address bit fields
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
    
    // Contact bit fields
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
    
    ////////////////////////////////////////////////////////////////
    // STEP 3 - Define conditional templates for each fields & std::ostream
    ////////////////////////////////////////////////////////////////
    
    // For Unit
    template<int BitField, bool B = ((BitField & AddressBF::Unit) != 0)>
    struct MixInUnit
    {
        int Unit;
        
        void toStream(std::ostream & ostr) const
        {
            ostr << "Unit = [" << Unit << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInUnit<BitField, false>
    {
        void toStream(std::ostream & ostr) const
        {
        }
    };
    
    // For Level
    template<int BitField, bool B = ((BitField & AddressBF::Level) != 0)>
    struct MixInLevel
    {
        int Level;
        
        void toStream(std::ostream & ostr) const
        {
            ostr << "Level = [" << Level << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInLevel<BitField, false>
    {
        void toStream(std::ostream & ostr) const
        {
        }
    };
    
    // For ZipCode
    template<int BitField, bool B = ((BitField & AddressBF::ZipCode) != 0)>
    struct MixInZipCode
    {
        char ZipCode[ZIP_CODE_LEN];
        
        void toStream(std::ostream & ostr) const
        {
            ostr << "ZipCode = [" << ZipCode << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInZipCode<BitField, false>
    {
        void toStream(std::ostream & ostr) const
        {
        }
    };
    
    // For Block
    template<int BitField, bool B = ((BitField & AddressBF::Block) != 0)>
    struct MixInBlock
    {
        int Block;
        
        void toStream(std::ostream & ostr) const
        {
            ostr << "Block = [" << Block << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInBlock<BitField, false>
    {
        void toStream(std::ostream & ostr) const
        {
        }
    };
    
    // For Street
    template<int BitField, bool B = ((BitField & AddressBF::Street) != 0)>
    struct MixInStreet
    {
        char Street[STREET_LEN];
        
        void toStream(std::ostream & ostr) const
        {
            ostr << "Street = [" << Street << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInStreet<BitField, false>
    {
        void toStream(std::ostream & ostr) const
        {
        }
    };
    
    // For Road
    template<int BitField, bool B = ((BitField & AddressBF::Road) != 0)>
    struct MixInRoad
    {
        char Road[ROAD_LEN];
        
        void toStream(std::ostream & ostr) const
        {
            ostr << "Road = [" << Road << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInRoad<BitField, false>
    {
        void toStream(std::ostream & ostr) const
        {
        }
    };
    
    // For District
    template<int BitField, bool B = ((BitField & AddressBF::District) != 0)>
    struct MixInDistrict
    {
        char District[DISTRICT_LEN];
        
        void toStream(std::ostream & ostr) const
        {
            ostr << "District = [" << District << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInDistrict<BitField, false>
    {
        void toStream(std::ostream & ostr) const
        {
        }
    };
    
    // For Mobile
    template<int BitField, bool B = ((BitField & ContactBF::Mobile) != 0)>
    struct MixInMobile
    {
        char Mobile[MOBILE_LEN];
        
        void toStream(std::ostream & ostr) const
        {
            ostr << "Mobile = [" << Mobile << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInMobile<BitField, false>
    {
        void toStream(std::ostream & ostr) const
        {
        }
    };
    
    // For HomePhone
    template<int BitField, bool B = ((BitField & ContactBF::HomePhone) != 0)>
    struct MixInHomePhone
    {
        char HomePhone[HOME_PHONE_LEN];
        
        void toStream(std::ostream & ostr) const
        {
            ostr << "HomePhone = [" << HomePhone << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInHomePhone<BitField, false>
    {
        void toStream(std::ostream & ostr) const
        {
        }
    };
    
    // For HomeEmail
    template<int BitField, bool B = ((BitField & ContactBF::HomeEmail) != 0)>
    struct MixInHomeEmail
    {
        char HomeEmail[HOME_EMAIL_LEN];
        
        void toStream(std::ostream & ostr) const
        {
            ostr << "HomeEmail = [" << HomeEmail << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInHomeEmail<BitField, false>
    {
        void toStream(std::ostream & ostr) const
        {
        }
    };
    
    // For OfficePhone
    template<int BitField, bool B = ((BitField & ContactBF::OfficePhone) != 0)>
    struct MixInOfficePhone
    {
        char OfficePhone[OFFICE_PHONE_LEN];
        
        void toStream(std::ostream & ostr) const
        {
            ostr << "OfficePhone = [" << OfficePhone << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInOfficePhone<BitField, false>
    {
        void toStream(std::ostream & ostr) const
        {
        }
    };
    
    // For OfficeEmail
    template<int BitField, bool B = ((BitField & ContactBF::OfficeEmail) != 0)>
    struct MixInOfficeEmail
    {
        char OfficeEmail[OFFICE_EMAIL_LEN];
        
        void toStream(std::ostream & ostr) const
        {
            ostr << "OfficeEmail = [" << OfficeEmail << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInOfficeEmail<BitField, false>
    {
        void toStream(std::ostream & ostr) const
        {
        }
    };
    
    ////////////////////////////////////////////////////////////////
    // STEP 4 - Define aggregate template for each type
    ////////////////////////////////////////////////////////////////
    
    // Address Struct
    template<int AddressBits>
    struct AddressTypeT: MixInUnit<AddressBits>,
        MixInLevel<AddressBits>, MixInZipCode<AddressBits>,
        MixInBlock<AddressBits>, MixInStreet<AddressBits>,
        MixInRoad<AddressBits>, MixInDistrict<AddressBits>
    {
        void toStream(std::ostream & ostr) const
        {
            MixInUnit<AddressBits>::toStream(ostr);
            MixInLevel<AddressBits>::toStream(ostr);
            MixInZipCode<AddressBits>::toStream(ostr);
            MixInBlock<AddressBits>::toStream(ostr);
            MixInStreet<AddressBits>::toStream(ostr);
            MixInRoad<AddressBits>::toStream(ostr);
            MixInDistrict<AddressBits>::toStream(ostr);
        }
    };
    
    // Contact Struct
    template<int ContactBits>
    struct ContactTypeT: MixInMobile<ContactBits>,
    MixInHomePhone<ContactBits>, MixInHomeEmail<ContactBits>,
    MixInOfficePhone<ContactBits>, MixInOfficeEmail<ContactBits>
    {
        void toStream(std::ostream & ostr) const
        {
            MixInMobile<ContactBits>::toStream(ostr);
            MixInHomePhone<ContactBits>::toStream(ostr);
            MixInHomeEmail<ContactBits>::toStream(ostr);
            MixInOfficePhone<ContactBits>::toStream(ostr);
            MixInOfficeEmail<ContactBits>::toStream(ostr);
        }
    };
    
    ////////////////////////////////////////////////////////////////
    // STEP 5 - Define common output stream handler
    ////////////////////////////////////////////////////////////////
    
    template<typename TypeWithToStream>
    std::ostream & operator<<(std::ostream & ostr, const TypeWithToStream & value)
    {
        value.toStream(ostr);
        return ostr;
    }
    
    ////////////////////////////////////////////////////////////////
    // STEP 6 - Define aggregate value of chosen fields via bit fields
    ////////////////////////////////////////////////////////////////
    
    // Specify the fields we want to have for Address
    const static int AddressFields = AddressBF::Unit
        bitor AddressBF::Level
        bitor AddressBF::Block
        bitor AddressBF::ZipCode
        bitor AddressBF::District
    ;
    
    // Specify the fields we want to have for Contact
    const static int ContactFields = ContactBF::Mobile
        bitor ContactBF::HomePhone
        bitor ContactBF::OfficeEmail
    ;
    
    ////////////////////////////////////////////////////////////////
    // STEP 7 - Typedef for template specializations with chosen fields
    ////////////////////////////////////////////////////////////////
    
    // Address Struct Specialization
    typedef AddressTypeT<AddressFields> AddressType;
    
    // Contact Struct Specialization
    typedef ContactTypeT<ContactFields> ContactType;
}

#endif
