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
 Create & use types with custom fields at compile time in 6 easy steps
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
    static const size_t HOME_PHONE_LEN      = 16;
    static const size_t HOME_EMAIL_LEN      = 32;
    static const size_t OFFICE_PHONE_LEN    = 16;
    static const size_t OFFICE_EMAIL_LEN    = 32;
    
    ////////////////////////////////////////////////////////////////
    // STEP 2 - Declare & define bit fields
    ////////////////////////////////////////////////////////////////
    
    // Address bit fields
    namespace AddressBF
    {
        enum
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
    }
    
    // Contact bit fields
    namespace ContactBF
    {
        enum
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
    
    ////////////////////////////////////////////////////////////////
    // NOTE - Use SFINAE (Substituion Failure Is Not An Error)
    ////////////////////////////////////////////////////////////////
    
    // http://stackoverflow.com/questions/257288/is-it-possible-to-write-a-c-template-to-check-for-a-functions-existence
    template<typename T, typename Signature = void(T::*)(std::ostream &) const>
    struct has_to_stream
    {
        typedef char yes[1];
        typedef char no[2];
        
        template <typename U, U>
        struct type_check;
        
        template <typename _1>
        static yes & check(type_check<Signature, &_1::toStream> *);
        
        template <typename>
        static no & check(...);
        
        static const bool value = (sizeof(yes) == sizeof(check<T>(0)));
    };
    
    template <typename T = void, bool B = false>
    struct enable_if {};
    
    template <typename T>
    struct enable_if<T, true>
    {
        typedef T type;
    };
    
    // Will be chosen when T has the method void T::toStream(std::ostream &) const
    template<typename T>
    inline
    typename enable_if<T, has_to_stream<T>::value>::type *
    to_stream(const T & obj, std::ostream & ostr)
    {
        obj.toStream(ostr);
        return 0;
    }
    
    // Will be chosen when T doesn't have the method void T::toStream(std::ostream &) const
    template<typename T>
    inline
    typename enable_if<T, !has_to_stream<T>::value>::type *
    to_stream(const T & obj, std::ostream & ostr)
    {
        return 0;
    }
    
    // http://stackoverflow.com/questions/257288/is-it-possible-to-write-a-c-template-to-check-for-a-functions-existence
    #define HAS_MEM_FUNC(func, name)                                            \
    template<typename T, typename Sign>                                         \
    struct name {                                                               \
        typedef char yes[1];                                                    \
        typedef char no [2];                                                    \
        template <typename U, U> struct type_check;                             \
        template <typename _1> static yes & chk(type_check<Sign, &_1::func> *); \
        template <typename   > static no  & chk(...);                           \
        static bool const value = (sizeof(chk<T>(0)) == sizeof(yes));           \
    }
    
    HAS_MEM_FUNC(toStream, got_to_stream);
    
    ////////////////////////////////////////////////////////////////
    // STEP 3 - Define conditional templates for each fields & std::ostream
    ////////////////////////////////////////////////////////////////
    
    // For Unit
    template<int BitField, bool B = ((BitField & AddressBF::Unit) != 0)>
    struct MixInUnit
    {
        int Unit;
        
        inline void toStream(std::ostream & ostr) const
        {
            ostr << "Unit = [" << Unit << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInUnit<BitField, false> { inline void toStream(std::ostream &) const {} };
    
    // For Level
    template<int BitField, bool B = ((BitField & AddressBF::Level) != 0)>
    struct MixInLevel
    {
        int Level;
        
        inline void toStream(std::ostream & ostr) const
        {
            ostr << "Level = [" << Level << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInLevel<BitField, false> { inline void toStream(std::ostream &) const {} };
    
    // For ZipCode
    template<int BitField, bool B = ((BitField & AddressBF::ZipCode) != 0)>
    struct MixInZipCode
    {
        char ZipCode[ZIP_CODE_LEN];
        
        inline void toStream(std::ostream & ostr) const
        {
            ostr << "ZipCode = [" << ZipCode << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInZipCode<BitField, false> { inline void toStream(std::ostream &) const {} };
    
    // For Block
    template<int BitField, bool B = ((BitField & AddressBF::Block) != 0)>
    struct MixInBlock
    {
        int Block;
        
        inline void toStream(std::ostream & ostr) const
        {
            ostr << "Block = [" << Block << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInBlock<BitField, false> { inline void toStream(std::ostream &) const {} };
    
    // For Street
    template<int BitField, bool B = ((BitField & AddressBF::Street) != 0)>
    struct MixInStreet
    {
        char Street[STREET_LEN];
        
        inline void toStream(std::ostream & ostr) const
        {
            ostr << "Street = [" << Street << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInStreet<BitField, false> { inline void toStream(std::ostream &) const {} };
    
    // For Road
    template<int BitField, bool B = ((BitField & AddressBF::Road) != 0)>
    struct MixInRoad
    {
        char Road[ROAD_LEN];
        
        inline void toStream(std::ostream & ostr) const
        {
            ostr << "Road = [" << Road << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInRoad<BitField, false> { inline void toStream(std::ostream &) const {} };
    
    // For District
    template<int BitField, bool B = ((BitField & AddressBF::District) != 0)>
    struct MixInDistrict
    {
        char District[DISTRICT_LEN];
        
        inline void toStream(std::ostream & ostr) const
        {
            ostr << "District = [" << District << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInDistrict<BitField, false> { inline void toStream(std::ostream &) const {} };
    
    // For Mobile
    template<int BitField, bool B = ((BitField & ContactBF::Mobile) != 0)>
    struct MixInMobile
    {
        char Mobile[MOBILE_LEN];
        
        inline void toStream(std::ostream & ostr) const
        {
            ostr << "Mobile = [" << Mobile << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInMobile<BitField, false> { inline void toStream(std::ostream &) const {} };
    
    // For HomePhone
    template<int BitField, bool B = ((BitField & ContactBF::HomePhone) != 0)>
    struct MixInHomePhone
    {
        char HomePhone[HOME_PHONE_LEN];
        
        inline void toStream(std::ostream & ostr) const
        {
            ostr << "HomePhone = [" << HomePhone << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInHomePhone<BitField, false> { inline void toStream(std::ostream &) const {} };
    
    // For HomeEmail
    template<int BitField, bool B = ((BitField & ContactBF::HomeEmail) != 0)>
    struct MixInHomeEmail
    {
        char HomeEmail[HOME_EMAIL_LEN];
        
        inline void toStream(std::ostream & ostr) const
        {
            ostr << "HomeEmail = [" << HomeEmail << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInHomeEmail<BitField, false> { inline void toStream(std::ostream &) const {} };
    
    // For OfficePhone
    template<int BitField, bool B = ((BitField & ContactBF::OfficePhone) != 0)>
    struct MixInOfficePhone
    {
        char OfficePhone[OFFICE_PHONE_LEN];
        
        inline void toStream(std::ostream & ostr) const
        {
            ostr << "OfficePhone = [" << OfficePhone << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInOfficePhone<BitField, false> { inline void toStream(std::ostream &) const {} };
    
    // For OfficeEmail
    template<int BitField, bool B = ((BitField & ContactBF::OfficeEmail) != 0)>
    struct MixInOfficeEmail
    {
        char OfficeEmail[OFFICE_EMAIL_LEN];
        
        inline void toStream(std::ostream & ostr) const
        {
            ostr << "OfficeEmail = [" << OfficeEmail << "]; ";
        }
    };
    
    template<int BitField>
    struct MixInOfficeEmail<BitField, false> { inline void toStream(std::ostream &) const {} };
    
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
    // NOTE - Define output stream handler for final compound types
    ////////////////////////////////////////////////////////////////
    
    template<int FieldBits>
    std::ostream & operator<<(std::ostream & ostr, const AddressTypeT<FieldBits> & value)
    {
        value.toStream(ostr);
        return ostr;
    }
    
    template<int FieldBits>
    std::ostream & operator<<(std::ostream & ostr, const ContactTypeT<FieldBits> & value)
    {
        value.toStream(ostr);
        return ostr;
    }
    
    ////////////////////////////////////////////////////////////////
    // STEP 5 - Define aggregate value of chosen fields via bit fields
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
    // STEP 6 - Typedef for template specializations with chosen fields
    ////////////////////////////////////////////////////////////////
    
    // Address Struct Specialization
    typedef AddressTypeT<AddressFields> AddressType;
    
    // Contact Struct Specialization
    typedef ContactTypeT<ContactFields> ContactType;
}

#endif
