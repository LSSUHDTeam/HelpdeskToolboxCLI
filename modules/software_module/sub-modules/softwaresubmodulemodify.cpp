#include "softwaresubmodulemodify.h"

namespace hdtoolbox
{

    SoftwareSubModuleModify::SoftwareSubModuleModify() :
        ModuleBase(HDTB_SOFTWARE_MODIFY,
                   "Software SubModule - Modify",
                   "The sub-module that handles the modify function for"
                   "the Software Module")
    {
        commands.insert(
                    HDTBMapItem
                    ("java", HDTB_SOFTWARE_CMD_MODIFY_JAVA)
                    );
        commands.insert(
                    HDTBMapItem
                    ("ie", HDTB_SOFTWARE_CMD_MODIFY_IE)
                    );
    }
      HDTBReturnItem SoftwareSubModuleModify::processRequest(std::vector<std::string> args)
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

          case HDTB_SOFTWARE_CMD_MODIFY_JAVA:
              return modifyJava();
              break;

          case HDTB_SOFTWARE_CMD_MODIFY_IE:
            #ifdef _WIN32
                    if (args.size() != 3)
                    {
                        return errorHandler.generateGenericError("No version given <10/11>");
                    }
                    else
                    {
                        return modifyIE(args[2]);
                    }
            #else
                    return errorHandler.generateGenericError("OS not supported");
            #endif
          default:
              break;
          }

          return errorHandler.generateGenericError("Uncaught return");
      }

      HDTBReturnItem SoftwareSubModuleModify::modifyJava()
      {
        #ifdef _WIN32

            system("start lib\\software\\fixJava.bat");
            return HDTBReturnItem(HDTB_RETURN_GOOD, "");

        #elif __APPLE__
            system("lib/software/fixJavaMac.sh");
            return HDTBReturnItem(HDTB_RETURN_GOOD, "");
        #else
            return errorHandler.generateGenericError("OS not supported");
        #endif
      }

      HDTBReturnItem SoftwareSubModuleModify::modifyIE(std::string version)
      {
          std::cout << std::endl << "Change version to : " << version << std::endl;
          return errorHandler.generateGenericError("Not yet created");
      }

}
