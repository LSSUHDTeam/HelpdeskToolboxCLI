#include "softwaresubmoduleremove.h"

namespace hdtoolbox
{
    SoftwareSubModuleRemove::SoftwareSubModuleRemove() :
        ModuleBase(HDTB_SOFTWARE_REMOVE,
                   "Software SubModule - Remove",
                   "The sub-module that handles the remove command from"
                   "the Software Module")
    {
        commands.insert(
                    HDTBMapItem
                    ("java", HDTB_SOFTWARE_CMD_REMOVE_JAVA)
                    );

        commands.insert(
                    HDTBMapItem
                    ("kace", HDTB_SOFTWARE_CMD_REMOVE_KACE)
                    );

        commands.insert(
                    HDTBMapItem
                    ("avira", HDTB_SOFTWARE_CMD_REMOVE_AVIRA)
                    );
    }

    HDTBReturnItem SoftwareSubModuleRemove::processRequest(std::vector<std::string> args)
    {
        history.push(args);

        // Make sure commands are given, and if they are if there are enough
        if(args.size() == 1)
        {
            // Call to super class
            displayAvailableCommands();

            return errorHandler.generateGenericError("No commands given");
        }

        // Make sure command exists
        if(commands.find(args[1]) == commands.end())
        {
            // Call to super class
            displayAvailableCommands();

            return errorHandler.generateGenericError("Command not found");
        }


        //Handle command
        switch(commands[args[1]])
        {

        case HDTB_SOFTWARE_CMD_REMOVE_JAVA:
            return removeJava();
            break;

        case HDTB_SOFTWARE_CMD_REMOVE_KACE:
            return removeKACE();
            break;

        case HDTB_SOFTWARE_CMD_REMOVE_AVIRA:
            return removeAvira();
            break;

        default:
            break;
        }

        return errorHandler.generateGenericError("Uncaught return");
    }

    /*

                    Remove Java

    */

    HDTBReturnItem SoftwareSubModuleRemove::removeJava()
    {
    #ifdef _WIN32
        return HDTBReturnItem(HDTB_RETURN_BAD, "Not yet programmed");
    #elif __APPLE__
        system("lib/software/removeJavaMac.sh");
        return HDTBReturnItem(HDTB_RETURN_GOOD, "");
    #else
        return errorHandler.generateGenericError("OS not supported");
    #endif
    }

    HDTBReturnItem SoftwareSubModuleRemove::removeKACE()
    {
    #ifdef _WIN32
        std::string exec = ("start powershell.exe -ExecutionPolicy Bypass -File lib\\software\\removeKACEWin.ps1");
        system(exec.c_str());

        return HDTBReturnItem(HDTB_RETURN_GOOD, "");
    #elif __APPLE__
        return errorHandler.generateGenericError("OS not yet supported");
    #else
        return errorHandler.generateGenericError("OS not supported");
    #endif
    }

    HDTBReturnItem SoftwareSubModuleRemove::removeAvira()
    {
    #ifdef _WIN32
        return HDTBReturnItem(HDTB_RETURN_BAD, "Not yet programmed");
    #elif __APPLE__
        return errorHandler.generateGenericError("OS not yet supported");
    #else
        return errorHandler.generateGenericError("OS not supported");
    #endif
    }

}
