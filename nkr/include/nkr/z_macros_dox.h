/*
    Copyright 2022 r-neal-kelly
*/

#pragma once

/**
* @defgroup macros macros
*
* @brief
*   Macros that are namespaced with a prefix and provide solutions that are otherwise difficult to achieve.
*
* @todo
*   Provide details
*
* @hideinitializer
*/

    /**
    * @defgroup macros_braces braces
    * @ingroup macros
    *
    * @brief
    *   Symbols used to delimit a macro's body.
    *
    * @details
    *   The one set is used for functional macros which return values and the other set for procedural macros which simply alter state without returning any values. These are only useful when you're defining a macro, otherwise you should not need to use them.
    *
    * @todo
    *   Give an example.
    *
    * @hideinitializer
    */

        /**
        * @class doc_nkr_nkr_M
        * @private
        *
        * @brief
        *   The opening brace for functional macros.
        */

        /**
        * @class doc_nkr_nkr_W
        * @private
        *
        * @brief
        *   The closing brace for functional macros.
        */

        /**
        * @class doc_nkr_nkr_P
        * @private
        *
        * @brief
        *   The opening brace for procedural macros.
        */

        /**
        * @class doc_nkr_nkr_b
        * @private
        *
        * @brief
        *   The closing brace for procedural macros.
        */

    /**
    * @defgroup macros_procedures procedures
    * @ingroup macros
    *
    * @brief
    *   Macros that do not return any value but can alter state within their scope.
    *
    * @hideinitializer
    */

        /**
        * @class doc_nkr_nkr_INITIALIZE_STATIC_SAFELY
        * @private
        *
        * @brief
        *   Uses an arbitrary initializer to ready static variables in a thread-safe and efficient manner.
        *
        * @param INITIALIZER_p
        *   should be a function or lambda that initializes static data.
        *
        * @par Requires
        *   ```cpp
        *   #include <mutex>
        *   #include "nkr/os.h"
        *   ```
        *
        * @todo
        *   Use the snippet command to include an example of this macro. Also this should be put in a proceduarl group
        *
        * @details
        *   In C++11 and later, static objects are intialized in a thread-safe manner through their constructors. However, not all data is subject to being defined in a class, and hence this macro acts as an on-the-fly constructor for arbitrary static data declared and defined at your discretion.
        *
        *   It uses an atomic nkr::bool_t to flag initialization so that more expensive thread-safe components are elided after execution of your initializer.
        */

    /**
    * @defgroup macros_functions functions
    * @ingroup macros
    *
    * @brief
    *   Macros that return a value and can also alter state within their scope.
    *
    * @hideinitializer
    */
