#include "softwaresubmoduleinstall.h"

namespace hdtoolbox
{
    SoftwareSubModuleInstall::SoftwareSubModuleInstall() :
        ModuleBase(HDTB_SOFTWARE_INSTALL,
                   "Software SubModule - Install",
                   "The sub-module that handles the install command for"
                   "the Software Module")
        {
            commands.insert(
                        HDTBMapItem
                        ("java", HDTB_SOFTWARE_CMD_INSTALL_JAVA)
                        );

            commands.insert(
                        HDTBMapItem
                        ("kace", HDTB_SOFTWARE_CMD_INSTALL_KACE)
                        );

            commands.insert(
                        HDTBMapItem
                        ("avira", HDTB_SOFTWARE_CMD_INSTALL_AVIRA)
                        );
        }

    HDTBReturnItem SoftwareSubModuleInstall::processRequest(std::vector<std::string> args)
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

        case HDTB_SOFTWARE_CMD_INSTALL_JAVA:
            return installJava();
            break;

        case HDTB_SOFTWARE_CMD_INSTALL_KACE:
            return installKACE();
            break;
        case HDTB_SOFTWARE_CMD_INSTALL_AVIRA:
            return installAvira();
        default:
            break;
        }

        return errorHandler.generateGenericError("Uncaught return");
    }

    HDTBReturnItem SoftwareSubModuleInstall::installJava()
    {
        #ifdef _WIN32

            std::string exec = ("start powershell.exe -ExecutionPolicy Bypass -File lib\\software\\installJava.ps1 \n" );
            system(exec.c_str());

            system("start lib\\software\\fixJava.bat");
            return HDTBReturnItem(HDTB_RETURN_GOOD, "");
        #elif __APPLE__
            system("lib/software/installJavaMac.sh");
            return HDTBReturnItem(HDTB_RETURN_GOOD, "");
        #else
            return errorHandler.generateGenericError("OS not supported");
        #endif
    }

    HDTBReturnItem SoftwareSubModuleInstall::installKACE()
    {
        #ifdef _WIN32
            return HDTBReturnItem(HDTB_RETURN_BAD, "Not yet programmed");
        #elif __APPLE__
            return errorHandler.generateGenericError("OS not yet supported");
        #else
            return errorHandler.generateGenericError("OS not supported");
        #endif
    }

    HDTBReturnItem SoftwareSubModuleInstall::installAvira()
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
