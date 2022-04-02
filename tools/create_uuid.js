/*
    Copyright 2022 r-neal-kelly
*/

`use strict`;

import {
    Execute_Child_Process,
    Print_Error,
} from "./common.js"

/* bool_t */ async function Can_Create_UUID()
{
    try {
        await Execute_Child_Process(`npm -v`);
        try {
            await Execute_Child_Process(`uuid`);

            return true;
        } catch (error) {
            try {
                await Execute_Child_Process(`npm install -g uuid`);
                try {
                    await Execute_Child_Process(`uuid`);
        
                    return true;
                } catch (error) {
                    Print_Error("Failed to execute `uuid` from PATH even after a global install. It may need to be reinstalled manually.", error);

                    return false;
                }
            } catch (error) {
                Print_Error("Failed to install a global instance of uuid. It may need to be installed manually.", error);

                return false;
            }
        }
    } catch (error) {
        Print_Error("'npm' could not be found in the PATH. It may need to be installed or added to the PATH.", error);
        
        return false;
    }
}

/* string_t */ async function Create_UUID()
{
    return "_" + (await Execute_Child_Process(`uuid`)).replace(/-/g, "_").replace(/[\n\r]/g, "");
}

/* string_t */ function UUID_Regex()
{
    return "_[0-9a-fA-F]{8}(_[0-9a-fA-F]{4}){3}_[0-9a-fA-F]{12}";
}

/* bool_t */ function Is_UUID(/* string_t */ uuid)
{
    return RegExp(`^${UUID_Regex()}$`).test(uuid);
}

export {
    Can_Create_UUID,
    Create_UUID,
    UUID_Regex,
    Is_UUID,
}
